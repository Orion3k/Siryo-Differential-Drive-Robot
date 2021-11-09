#!/usr/bin/env python
import rospy
from mpu6050 import mpu6050
from sensor_msgs.msg import Imu
from geometry_msgs.msg import Vector3

sensor = mpu6050(0x68)

def get_data():
	#sensor.set_accel_range(accel_range=sensor.ACCEL_RANGE_2G)
	#sensor.set_gyro_range(gyro_range=sensor.GYRO_RANGE_250DEG)

	acc_mean = [0.6995122561825856, 0.13567193821975915, 9.721960112000165]
	acc_var = [0.0014298346317537685, 0.003488776651191735, 0.004005896867499097]
	gyr_mean = [-3.201630522419838, 0.8785332246412229, -3.2426313427938864] 
	gyr_var = [0.00645090062771555, 0.006565394554497192, 0.005613595184040882] 

	i = Imu()
	i.header.stamp = rospy.Time.now()
	i.header.frame_id = 'imu_base'
	l_acel_dic = sensor.get_accel_data(g=False)
	l_acel = Vector3()
	l_acel.x = l_acel_dic['x'] - acc_mean[0]
	l_acel.y = l_acel_dic['y'] - acc_mean[1]
	l_acel.z = l_acel_dic['z'] - acc_mean[2]
	i.linear_acceleration = l_acel
	i.linear_acceleration_covariance = [acc_var[0], 0., 0.,
										0., acc_var[1], 0.,
					   					0., 0., acc_var[2]]
	a_vel_dic = sensor.get_gyro_data()
	a_vel = Vector3()
	a_vel.x = a_vel_dic['x'] - gyr_mean[0]
	a_vel.y = a_vel_dic['y'] - gyr_mean[1]
	a_vel.z = a_vel_dic['z'] - gyr_mean[2]
	i.angular_velocity = a_vel
	i.angular_velocity_covariance = [gyr_var[0], 0., 0.,
									0., gyr_var[1], 0.,
									0., 0., gyr_var[2]]
	i.orientation_covariance = [-1., -1., -1.,
								-1., -1., -1.,
								-1., -1., -1.]
	return i

def pub_imu_data():
	rospy.init_node('imu_mpu',anonymous=True)
	imu_pub = rospy.Publisher('/imu/data',Imu, queue_size = 1)
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

