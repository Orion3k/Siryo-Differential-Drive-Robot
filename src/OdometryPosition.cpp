#include "ros/ros.h"
#include "nav_msg/Odometry.h"
#include "tf/transform_broadcaster.h"

class odom_class{
    
    private:
        ros::NodeHandle nh;
        ros::Subscriber speed_sub;
        ros::Publisher odom_pub;
        tf::TransformBroadcaster tf_pub;
        ros::Time current:_time, last_time;
        
    public:
        odom_class(){
            speed_sub = nh.Subscribe("speed");
            odom_pub = nh.advertise<nav_msgs::Odometry>("Odom",1000);
            last_time = ros::Time::now();
        }

};

int main(int argc, char **argv) {
    ros::init(argc,argv,"OdometryPosition");


    ros::spin();

}
