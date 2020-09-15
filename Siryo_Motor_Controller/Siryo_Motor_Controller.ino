/*
   Siryo motor controller
*/

#include <ros.h>
#include <L298N.h>
#include <PID_v1.h>
#include <std_msgs/String.h>
#include <geometry_msgs/Vector3Stamped.h>
#include <geometry_msgs/Twist.h>
#include <ros/time.h>

#define PIN_ENCOD_A_L  2               //A channel for encoder of left motor                    
#define PIN_ENCOD_B_L 4               //B channel for encoder of left motor

#define PIN_ENCOD_A_R 3              //A channel for encoder of right motor         
#define PIN_ENCOD_B_R 5              //B channel for encoder of right motor

#define ENAR 11
#define INR1 10
#define INR2 9
#define INL1 8
#define INL2 7
#define ENBL 6
#define LOOPTIME           100                //Looptime in millisecond


const byte noCommLoopMax = 5;                //number of main loops the robot will execute without communication before stopping
unsigned int noCommLoops = 0;                 //main loop without communication counter


unsigned long lastMilli = 0;

//--- Robot-specific constants ---
const double radius = 0.0325;                 //Wheel radius, in m
const double wheelbase = 0.194;               //Wheelbase, in m
const double encoder_cpr = 20;                //Encoder ticks or counts per rotation
const double speed_to_pwm_ratio = 0.0036;    //Ratio to convert speed (in m/s) to PWM value. It was obtained by plotting the wheel speed in relation to the PWM motor command (the value is the slope of the linear function).
const double min_speed_cmd = 0.414;          //(min_speed_cmd/speed_to_pwm_ratio) is the minimum command value needed for the motor to start moving. This value was obtained by plotting the wheel speed in relation to the PWM motor command (the value is the constant of the linear function).


double speed_req = 0;                         //Desired linear speed for the robot, in m/s
double angular_speed_req = 0;                 //Desired angular speed for the robot, in rad/s
double speed_req_left = 0;                    //Desired speed for left wheel in m/s
double speed_act_left = 0;                    //Actual speed for left wheel in m/s
double speed_cmd_left = 0;                    //Command speed for left wheel in m/s

double speed_req_right = 0;                   //Desired speed for right wheel in m/s
double speed_act_right = 0;                   //Actual speed for right wheel in m/s
double speed_cmd_right = 0;                   //Command speed for right wheel in m/s

const double max_speed = 0.9;                //Max speed in m/s

int PWM_leftMotor = 0;                     //PWM command for left motor
int PWM_rightMotor = 0;                    //PWM command for right motor

// PID Parameters
const double PID_left_param[] = { 0.3, 0.1, 0 }; //Respectively Kp, Ki and Kd for left motor PID
const double PID_right_param[] = { 0.3, 0.1, 0 }; //Respectively Kp, Ki and Kd for right motor PID

volatile float pos_left = 0;       //Left motor encoder position
volatile float pos_right = 0;      //Right motor encoder position

PID PID_leftMotor(&speed_act_left, &speed_cmd_left, &speed_req_left, PID_left_param[0], PID_left_param[1], PID_left_param[2], DIRECT);          //Setting up the PID for left motor
PID PID_rightMotor(&speed_act_right, &speed_cmd_right, &speed_req_right, PID_right_param[0], PID_right_param[1], PID_right_param[2], DIRECT);   //Setting up the PID for right motor

L298N rightMotor(ENAR, INR1, INR2);
L298N leftMotor(ENBL, INL1, INL2);

ros::NodeHandle  nh;

//function that will be called when receiving command from host
void setRequestedSpeed (const geometry_msgs::Twist& cmd_vel) {
  noCommLoops = 0;                                                  //Reset the counter for number of main loops without communication

  speed_req = cmd_vel.linear.x;                                     //Extract the commanded linear speed from the message

  angular_speed_req = cmd_vel.angular.z;                            //Extract the commanded angular speed from the message

  speed_req_left = speed_req - angular_speed_req * (wheelbase / 2); //Calculate the required speed for the left motor to comply with commanded linear and angular speeds
  speed_req_right = speed_req + angular_speed_req * (wheelbase / 2); //Calculate the required speed for the right motor to comply with commanded linear and angular speeds
}

ros::Subscriber<geometry_msgs::Twist> cmd_vel("cmd_vel", setRequestedSpeed);   //create a subscriber to ROS topic for velocity commands (will execute "handle_cmd" function when receiving data)
geometry_msgs::Vector3Stamped speed_msg;                                //create a "speed_msg" ROS message
ros::Publisher speed_pub("speed", &speed_msg);                          //create a publisher to ROS topic "speed" using the "speed_msg" type


std_msgs::String str_msg;
ros::Publisher chatter("chatter", &str_msg);


void setup()
{
  nh.initNode();                        //init ROS node
  nh.getHardware()->setBaud(57600);         //set baud for ROS serial communication
  nh.subscribe(cmd_vel);                    //suscribe to ROS topic for velocity commands
  nh.advertise(speed_pub);    
  nh.advertise(chatter);


  //setting PID parameters
  PID_leftMotor.SetSampleTime(95);
  PID_rightMotor.SetSampleTime(95);
  PID_leftMotor.SetOutputLimits(-max_speed, max_speed);
  PID_rightMotor.SetOutputLimits(-max_speed, max_speed);
  PID_leftMotor.SetMode(AUTOMATIC);
  PID_rightMotor.SetMode(AUTOMATIC);


  // Define the rotary encoder for left motor
  pinMode(PIN_ENCOD_A_L, INPUT);
  pinMode(PIN_ENCOD_B_L, INPUT);
  digitalWrite(PIN_ENCOD_A_L, HIGH);                // turn on pullup resistor
  digitalWrite(PIN_ENCOD_B_L, HIGH);
  attachInterrupt(0, encoderLeftMotor, RISING);

  // Define the rotary encoder for right motor
  pinMode(PIN_ENCOD_A_R, INPUT);
  pinMode(PIN_ENCOD_B_R, INPUT);
  digitalWrite(PIN_ENCOD_A_R, HIGH);                // turn on pullup resistor
  digitalWrite(PIN_ENCOD_B_R, HIGH);
  attachInterrupt(1, encoderRightMotor, RISING);

  //LED for Ros status
  pinMode(LED_BUILTIN,OUTPUT);
}

void loop()
{
  nh.spinOnce();

  if ((millis() - lastMilli) >= LOOPTIME)
  { // enter timed loop
    lastMilli = millis();
     
      if (nh.connected()){
        digitalWrite(LED_BUILTIN,HIGH);
      } else{
        digitalWrite(LED_BUILTIN,LOW);
      }
    
    //compute actual speed for left wheel
    if (abs(pos_left) < 5) {                //Avoid taking in account small disturbances
      speed_act_left = 0;
    }
    else {
      speed_act_left = ((pos_left / encoder_cpr) * 2 * PI) * (1000 / LOOPTIME) * radius; // calculate speed of left wheel
    }
    
    //compute actual speed for right wheel
    if (abs(pos_right) < 5) {               //Avoid taking in account small disturbances
      speed_act_right = 0;
    }
    else {
      speed_act_right = ((pos_right / encoder_cpr) * 2 * PI) * (1000 / LOOPTIME) * radius; // calculate speed of right wheel
    }

    pos_left = 0;
    pos_right = 0;

    speed_cmd_left = constrain(speed_cmd_left, -max_speed, max_speed);
    PID_leftMotor.Compute();
    // compute PWM value for left motor. Check constant definition comments for more information.
    PWM_leftMotor = constrain(((speed_req_left + sgn(speed_req_left) * min_speed_cmd) / speed_to_pwm_ratio) + (speed_cmd_left / speed_to_pwm_ratio), -255, 255); //

    if (noCommLoops >= noCommLoopMax) {      //Stopping if too much time without command
      leftMotor.setSpeed(0);
      leftMotor.run(L298N::STOP);
    }
    else if (speed_req_left == 0) {                //Stopping
      leftMotor.setSpeed(0);
      leftMotor.run(L298N::STOP);
    }
    else if (PWM_leftMotor > 0) {                  //Going forward
      leftMotor.setSpeed(abs(PWM_leftMotor));
      leftMotor.run(L298N::BACKWARD);
    }
    else {                                         //Going backward
      leftMotor.setSpeed(abs(PWM_leftMotor));
      leftMotor.run(L298N::FORWARD);
    }
    
    speed_cmd_right = constrain(speed_cmd_right, -max_speed, max_speed);
    PID_rightMotor.Compute();
    // compute PWM value for right motor. Check constant definition comments for more information.
    PWM_rightMotor = constrain(((speed_req_right + sgn(speed_req_right) * min_speed_cmd) / speed_to_pwm_ratio) + (speed_cmd_right / speed_to_pwm_ratio), -255, 255); //

    if (noCommLoops >= noCommLoopMax) {                   //Stopping if too much time without command
      rightMotor.setSpeed(0);
      rightMotor.run(L298N::STOP);
    }
    else if (speed_req_right == 0) {                      //Stopping
      rightMotor.setSpeed(0);
      rightMotor.run(L298N::STOP);
    }
    else if (PWM_rightMotor > 0) {                        //Going forward
      rightMotor.setSpeed(abs(PWM_rightMotor));
      rightMotor.run(L298N::FORWARD);
    }
    else {                                                //Going backward
      rightMotor.setSpeed(abs(PWM_rightMotor));
      rightMotor.run(L298N::BACKWARD);
    }

    if ((millis() - lastMilli) >= LOOPTIME) {     //write an error if execution time of the loop in longer than the specified looptime
      str_msg.data = "XL";
      chatter.publish( &str_msg );
    }

    noCommLoops++;
    if (noCommLoops == 65535) {
      noCommLoops = noCommLoopMax;
    }

    publishSpeed(LOOPTIME);   //Publish odometry on ROS topic
  }
}


//Publish function for odometry, uses a vector type message to send the data (message type is not meant for that but that's easier than creating a specific message type)
void publishSpeed(double time) {
  speed_msg.header.stamp = nh.now();      //timestamp for odometry data
  speed_msg.vector.x = speed_act_left;    //left wheel speed (in m/s)
  speed_msg.vector.y = speed_act_right;   //right wheel speed (in m/s)
  speed_msg.vector.z = time / 1000;       //looptime, should be the same as specified in LOOPTIME (in s)
  speed_pub.publish(&speed_msg);
  nh.spinOnce();
  nh.loginfo("Pub");
}


//Left motor encoder counter (Right direction: clockwise)
void encoderLeftMotor() {
  if (digitalRead(PIN_ENCOD_A_L) == digitalRead(PIN_ENCOD_B_L)) {
    pos_left++;
  } else {
    pos_left--;
  }
}

//Right motor encoder counter (Right direction: counter-clockwise)
void encoderRightMotor() {
  if (digitalRead(PIN_ENCOD_A_R) == digitalRead(PIN_ENCOD_B_R)) {
    pos_right--;
  } else {
    pos_right++;
  }
}

template <typename T> int sgn(T val) {
  return (T(0) < val) - (val < T(0));
}
