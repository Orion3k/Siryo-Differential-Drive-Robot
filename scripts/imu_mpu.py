#!/usr/bin/env python
import rospy
from mpu6050 import mpu6050
from sensor_msgs.msg import Imu
from geometry_msgs.msg import Vector3

sensor = mpu6050(0x68)

def get_data():
	i = Imu()
	i.header.stamp = rospy.Time.now()
	i.header.frame_id = 'imu_base'
	l_acel_dic = sensor.get_accel_data(g=False)
	l_acel = Vector3()
	l_acel.x = l_acel_dic['x']
	l_acel.y = l_acel_dic['y']
	l_acel.z = l_acel_dic['z']
	i.linear_acceleration = l_acel
	a_vel_dic = sensor.get_gyro_data()
	a_vel = Vector3()
	a_vel.x = a_vel_dic['x']
	a_vel.y = a_vel_dic['y']
	a_vel.z = a_vel_dic['z']
	i.angular_velocity = a_vel
	return i

def pub_imu_data():
	rospy.init_node('imu_mpu',anonymous=True)
	imu_pub = rospy.Publisher('imu_odom',Imu, queue_size = 1)
	rate = rospy.Rate(10)
	while not rospy.is_shutdown():
		msg = get_data()
		imu_pub.publish(msg)
		rate.sleep()


if __name__ == '__main__':
	try:
		pub_imu_data()
	except rospy.ROSInterruptException:
		pass
