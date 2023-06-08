#!/bin/bash

export ROS_HOSTNAME=192.168.1.60
export ROS_IP=192.168.1.60
export ROS_MASTER_URI=http://192.168.1.60:11311
source /opt/ros/noetic/setup.bash
source /home/siryo/siryo_ws/devel/setup.bash

roslaunch siryo coreLauncher.launch &
