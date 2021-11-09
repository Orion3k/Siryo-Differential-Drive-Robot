cmake_minimum_required(VERSION 2.8.3)
project(siryo)

find_package(catkin REQUIRED COMPONENTS 
  nav_msgs
  roscpp
  rospy
  sensor_msgs
  std_msgs
  geometry_msgs
  tf  )

catkin_package()

include_directories(include ${catkin_INCLUDE_DIRS})

add_executable(EncodersOdometry src/EncodersOdometry.cpp)
target_link_libraries(EncodersOdometry ${catkin_LIBRARIES})
