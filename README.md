# Siryo-Differential-Drive-Robot
A cute differential drive Robot

GENERAL SYSTEM SETTINGS

In order to launch the core nodes on the Robot 
add in the .bashrc file the following commands.

In the .bashrc on Siryo (Raspberry pi) MASTER:

export ROS_HOSTNAME=*RASPBERRY_PI_IP*
export ROS_IP=*RASPBERRY_PI_IP*
export ROS_MASTER_URI=http://*RASPBERRY_PI_IP*:11311


In the bashrc on the Pc (teleop and visualization):

export ROS_MASTER_URI=http://*RASPBERRY_PI_IP*:11311

_____________

ROS Packages used:

- rplidar_ros
- teleop_twist_keyboard
- tf
- rosserial_python
