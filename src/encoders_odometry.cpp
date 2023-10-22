#include "ros/ros.h"
#include "nav_msgs/Odometry.h"
#include "tf/transform_broadcaster.h"
#include "geometry_msgs/Vector3Stamped.h"
#include "math.h"

#define M_2PI 2 * M_PI

class Odom_class{
    private:
        ros::NodeHandle nh;
        ros::Subscriber speed_sub;
        ros::Publisher odom_pub;
        tf::TransformBroadcaster tf_pub;
        tf::Quaternion quat_tf;
        geometry_msgs::TransformStamped tf_trans;
        ros::Time current_time, last_time;
        geometry_msgs::Quaternion odom_quat;
        double dt, x ,y, z, vxy, omega, vx, vy, robot_wheelbase, dth, theta, speed_r, speed_l;
        bool publishTF = true;

    public:
        Odom_class(){
            //ros::AsyncSpinner spinner(4);
            //spinner.start();
            ROS_INFO("%s","Odom Class started \n");

            speed_sub = nh.subscribe("/wheels_speed", 1, &Odom_class::encodersCallback, this);
            odom_pub = nh.advertise<nav_msgs::Odometry>("/wheel_encoders/odom",100);
            robot_wheelbase = 0.194;
            nh.getParam("/robot_base_L",robot_wheelbase);
            nh.getParam("/publish_tf",publishTF);

            last_time = ros::Time::now();
            theta = 0;
            x = 0;
            y = 0;
            z = 0;
            omega = 0;
            vxy = 0;
            vx = 0;
            vy = 0;
            dth = 0;
            speed_l = 0.0;
            speed_r = 0.0;

            // Init TF
            tf_trans.header.stamp = ros::Time::now();
            tf_trans.header.frame_id = "odom";
            tf_trans.child_frame_id = "base_link";
            tf_trans.transform.translation.x = 0;
            tf_trans.transform.translation.y = 0;
            tf_trans.transform.translation.z = 0;
            tf_trans.transform.rotation = tf::createQuaternionMsgFromYaw(0);
            tf_pub.sendTransform(tf_trans);

        }


    void encodersCallback(const geometry_msgs::Vector3Stamped::ConstPtr& msg) {
        current_time = ros::Time::now();
        speed_l = msg->vector.x;
        speed_r = msg->vector.y;
        dt = msg->vector.z;
        ROS_INFO("Speed right wheel : %f", speed_r);
        ROS_INFO("Speed left wheel : %f", speed_l);

    }

    void loop(float rate){
        ros::Rate r(rate);

        while(nh.ok()) {
            ros::spinOnce();
            double v_diff = (speed_r - speed_l);

            omega = abs(v_diff) < 0.05 ? 0.0 : v_diff/robot_wheelbase;
            vxy = (speed_r + speed_l) / 2.0;

            double dxy = vxy * dt;
            dth = omega * dt;
            if (omega > 0) {
                ROS_INFO("omega: %f", omega);
                ROS_INFO("delta th: %f", dth);
            }

            theta = theta + dth;
            vx = vxy;
            vy = 0.0;
            double dx = cos(dth) * dxy;
            double dy = sin(dth) * dxy;
            x = x + (cos(theta) * dx - sin(theta) * dy);
            y = y + (sin(theta) * dx + cos(theta) * dy);
            z = 0.0;

            if(theta >= M_2PI) theta -= M_2PI;
            if(theta <= -M_2PI) theta += M_2PI;

            nav_msgs::Odometry odom_msg;
            odom_msg.header.stamp = current_time;
            odom_msg.header.frame_id = "odom";
            odom_msg.child_frame_id = "base_link";
            odom_quat = tf::createQuaternionMsgFromYaw(theta);
            //set pose
            odom_msg.pose.pose.position.x = x;
            odom_msg.pose.pose.position.y = y;
            odom_msg.pose.pose.position.z = z;
            odom_msg.pose.pose.orientation = odom_quat;
            //set velocity
            odom_msg.twist.twist.linear.x = vx;
            odom_msg.twist.twist.linear.y = vy;
            odom_msg.twist.twist.angular.z = omega;

            odom_msg.pose.covariance[0] = 1e-3;
            odom_msg.pose.covariance[7] = 1e-3;
            odom_msg.pose.covariance[8] = 0.0;
            odom_msg.pose.covariance[14] = 1e6;
            odom_msg.pose.covariance[21] = 1e6;
            odom_msg.pose.covariance[28] = 1e6;
            odom_msg.pose.covariance[35] = 1e3;
            odom_msg.twist.covariance[0] = 1e-3;
            odom_msg.twist.covariance[7] = 1e-3;
            odom_msg.twist.covariance[8] = 0.0;
            odom_msg.twist.covariance[14] = 1e6;
            odom_msg.twist.covariance[21] = 1e6;
            odom_msg.twist.covariance[28] = 1e6;
            odom_msg.twist.covariance[35] = 1e3;

            odom_pub.publish(odom_msg);

            if (publishTF) {
                //tf
                tf_trans.header.stamp = current_time;
                tf_trans.header.frame_id = "odom";
                tf_trans.child_frame_id = "base_link";
            
                tf_trans.transform.translation.x = x;
                tf_trans.transform.translation.y = y;
                tf_trans.transform.translation.z = z;
                tf_trans.transform.rotation = odom_quat;
            
                //send the transform
                tf_pub.sendTransform(tf_trans);
            }
        
            r.sleep();
        }
    }

};

int main(int argc, char **argv){
    ros::init(argc,argv,"EncodersOdometry");
    Odom_class my_odom_class;
    my_odom_class.loop(20);
    return 0;
}
