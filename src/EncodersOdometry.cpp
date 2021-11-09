#include "ros/ros.h"
#include "nav_msgs/Odometry.h"
#include "tf/transform_broadcaster.h"
#include "geometry_msgs/Vector3Stamped.h"
#include "math.h"


class Odom_class{
    private:
        ros::NodeHandle nh;
        ros::Subscriber speed_sub;
        ros::Publisher odom_pub;
        tf::TransformBroadcaster tf_pub;
        tf::Quaternion q;
        tf::Transform transform;
        ros::Time current_time, last_time;
        geometry_msgs::Quaternion odom_quat;
        double dt, x ,y, z, vl, va, vx, vy, L, R, dtheta, theta;

    public:
        Odom_class(){

            speed_sub = nh.subscribe("/wheels_speed",1,&Odom_class::encodersCallback,this);
            odom_pub = nh.advertise<nav_msgs::Odometry>("/wheel_encoders/odom",1000);
            last_time = ros::Time::now();
            nh.getParam("/robot_base_L",L);
            theta = 0;
            R = 0;
            x = 0;
            y = 0;
            z = 0;
            va = 0;
            vl = 0;
            vx = 0;
            vy = 0;
            dtheta = 0;
	        ROS_INFO("%s","Inner class constructor entered\n");
        }


    void encodersCallback(const geometry_msgs::Vector3Stamped::ConstPtr& msg){

        //odometry
        dt = msg->vector.z;
        va = (msg->vector.y - msg->vector.x)/L;
        R = (L* (msg->vector.y + msg->vector.x) )/(2 * (msg->vector.y - msg->vector.x) );
        vl = (msg->vector.y + msg->vector.x) / 2;

        dtheta = va * dt;
        theta = theta + dtheta;
        vx = vl * cos(theta);
        vy = vl * sin(theta);
        x = x + vx * dt;
        y = y + vy * dt;

        nav_msgs::Odometry odom;
        odom.header.stamp = current_time;
        odom.header.frame_id = "robot_odom_base";
        odom.child_frame_id = "robot_link";
        odom_quat = tf::createQuaternionMsgFromYaw(theta);
        //set pose
        odom.pose.pose.position.x = x;
        odom.pose.pose.position.y = y;
        odom.pose.pose.position.z = z;
        odom.pose.pose.orientation = odom_quat;
        //set velocity
        odom.twist.twist.linear.x = vx;
        odom.twist.twist.linear.y = vy;
        odom.twist.twist.angular.z = va;

        odom_pub.publish(odom);

        //tf
        transform.setOrigin(tf::Vector3(x,y,z));
        q.setRPY(0,0,theta);
        transform.setRotation(q);
        tf_pub.sendTransform(tf::StampedTransform(transform, ros::Time::now(), "map", "robot_odom_base"));
 }

};

int main(int argc, char **argv){

    ros::init(argc,argv,"EncodersOdometry");
    Odom_class my_odom_class;
    ros::spin();
    return 0;
}
