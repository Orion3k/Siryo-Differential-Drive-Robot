/*
 * Siryo motor controller
 */

#include <ros.h>
#include <std_msgs/String.h>
#include <L298N.h>
#include <PID_v1.h>

#define PIN_ENCOD_A_L  2               //A channel for encoder of left motor                    
#define PIN_ENCOD_B_L 4               //B channel for encoder of left motor

#define PIN_ENCOD_A_R 3              //A channel for encoder of right motor         
#define PIN_ENCOD_B_R 5              //B channel for encoder of right motor

#define ENA 11
#define ENB 10
#define INR1 9
#define INR2 8
#define INL1 6
#define INL2 7

unsigned long lastMilli = 0;

//--- Robot-specific constants ---
const double radius = 0.0325;                   //Wheel radius, in m
const double wheelbase = 0.194;               //Wheelbase, in m
const double encoder_cpr = 990;               //Encoder ticks or counts per rotation
const double speed_to_pwm_ratio = 0; //0.00235;    //Ratio to convert speed (in m/s) to PWM value. It was obtained by plotting the wheel speed in relation to the PWM motor command (the value is the slope of the linear function).
const double min_speed_cmd = 0; //0.0882;          //(min_speed_cmd/speed_to_pwm_ratio) is the minimum command value needed for the motor to start moving. This value was obtained by plotting the wheel speed in relation to the PWM motor command (the value is the constant of the linear function).


double speed_req = 0;                         //Desired linear speed for the robot, in m/s
double angular_speed_req = 0;                 //Desired angular speed for the robot, in rad/s

double speed_req_left = 0;                    //Desired speed for left wheel in m/s
double speed_act_left = 0;                    //Actual speed for left wheel in m/s
double speed_cmd_left = 0;                    //Command speed for left wheel in m/s 

double speed_req_right = 0;                   //Desired speed for right wheel in m/s
double speed_act_right = 0;                   //Actual speed for right wheel in m/s
double speed_cmd_right = 0;                   //Command speed for right wheel in m/s 
                        
const double max_speed = 0; //0.4;                 //Max speed in m/s

int PWM_leftMotor = 0;                     //PWM command for left motor
int PWM_rightMotor = 0;                    //PWM command for right motor 
                                                      
// PID Parameters
const double PID_left_param[] = { 0, 0, 0.1 }; //Respectively Kp, Ki and Kd for left motor PID
const double PID_right_param[] = { 0, 0, 0.1 }; //Respectively Kp, Ki and Kd for right motor PID

volatile float pos_left = 0;       //Left motor encoder position
volatile float pos_right = 0;      //Right motor encoder position

PID PID_leftMotor(&speed_act_left, &speed_cmd_left, &speed_req_left, PID_left_param[0], PID_left_param[1], PID_left_param[2], DIRECT);          //Setting up the PID for left motor
PID PID_rightMotor(&speed_act_right, &speed_cmd_right, &speed_req_right, PID_right_param[0], PID_right_param[1], PID_right_param[2], DIRECT);   //Setting up the PID for right motor

L298N right_motor(ENA,INR1,INR2);
L298N left_motor(ENB,INL1,INL2);


ros::NodeHandle  nh;

std_msgs::String str_msg;
ros::Publisher chatter("chatter", &str_msg);

void setup()
{
  nh.initNode();
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
}

void loop()
{
  str_msg.data = "Hello World!";
  chatter.publish( &str_msg );
  nh.spinOnce();
  delay(1000);
}




//Left motor encoder counter
void encoderLeftMotor() {
  if (digitalRead(PIN_ENCOD_A_L) == digitalRead(PIN_ENCOD_B_L)) pos_left++;
  else pos_left--;
}

//Right motor encoder counter
void encoderRightMotor() {
  if (digitalRead(PIN_ENCOD_A_R) == digitalRead(PIN_ENCOD_B_R)) pos_right--;
  else pos_right++;
}
