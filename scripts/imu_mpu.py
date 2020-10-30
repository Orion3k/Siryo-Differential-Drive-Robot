#!/usr/bin/env python
import rospy
from mpu6050 import mpu6050
from sensor_msgs.msg import Imu
from geometry_msgs.msg import Vector3

sensor = mpu6050(0x68)

def get_data():
	#sensor.set_accel_range(accel_range=sensor.ACCEL_RANGE_2G)
	#sensor.set_gyro_range(gyro_range=sensor.GYRO_RANGE_250DEG)

	acc_mean = [0.7250001757202134, 0.12694057202148465, 9.722326217529298]
	acc_var = [0.0026197816704015024, 0.002954857995298211, 0.0035961123983046226]
	gyr_mean = [-3.224709923664119, 0.8887633587786263, -3.266458015267172]
	gyr_var = [0.00582360882127977, 0.006331332020558544, 0.005843476432787353]

	i = Imu()
	i.header.stamp = rospy.Time.now()
	i.header.frame_id = 'imu_base'
	l_acel_dic = sensor.get_accel_data(g=False)
	l_acel = Vector3()
	l_acel.x = l_acel_dic['x'] - acc_mean[0]
	l_acel.y = l_acel_dic['y'] - acc_mean[1]
	l_acel.z = l_acel_dic['z'] - acc_mean[2] + 9.81
	i.linear_acceleration = l_acel
	a_vel_dic = sensor.get_gyro_data()
	a_vel = Vector3()
	a_vel.x = a_vel_dic['x'] - gyr_mean[0]
	a_vel.y = a_vel_dic['y'] - gyr_mean[1]
	a_vel.z = a_vel_dic['z'] - gyr_mean[2]
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
