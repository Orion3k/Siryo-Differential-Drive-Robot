#!/usr/bin/env python3
import rospy
from mpu6050 import mpu6050
from sensor_msgs.msg import Imu
from geometry_msgs.msg import Vector3

sensor = mpu6050(0x68)
filter_thres = 0.1

i = Imu()
i.header.frame_id = 'imu'

def get_data():
	#sensor.set_accel_range(accel_range=sensor.ACCEL_RANGE_2G)
	#sensor.set_gyro_range(gyro_range=sensor.GYRO_RANGE_250DEG)
	try:
		acc_mean = [rospy.get_param("/acc_mean_x", 0.2148), 
			rospy.get_param("/acc_mean_y", 0.1520), 
			rospy.get_param("/acc_mean_z", -0.4913)]
		acc_var = [0.0014298346317537685, 0.003488776651191735, 0.004005896867499097]
		gyr_mean = [rospy.get_param("/gyro_mean_x", 3.13919847328244),
			rospy.get_param("/gyro_mean_y", -0.3588244274809159), 
			rospy.get_param("/gyro_mean_z", 3.118717557251906)]
		gyr_mean = [3.13919847328244, -0.3588244274809159, 3.118717557251906]
		gyr_var = [0.00645090062771555, 0.006565394554497192, 0.005613595184040882]
	except Exception as e:
		print(e)

	i.header.stamp = rospy.Time.now()
	i.orientation.z = 1
	l_acel_dic = sensor.get_accel_data(g=False)
	a_vel_dic = sensor.get_gyro_data()

	i.linear_acceleration.x = l_acel_dic['x'] + acc_mean[0] if abs(l_acel_dic['x'] + acc_mean[0]) > filter_thres else 0.0
	i.linear_acceleration.y = l_acel_dic['y'] + acc_mean[1] if abs(l_acel_dic['y'] + acc_mean[2]) > filter_thres else 0.0
	i.linear_acceleration.z = l_acel_dic['z'] + acc_mean[2] if abs(l_acel_dic['z'] + acc_mean[2]) > filter_thres else 0.0
	i.linear_acceleration_covariance = [acc_var[0], 0., 0.,
										0., acc_var[1], 0.,
					   					0., 0., acc_var[2]]

	i.angular_velocity.x = a_vel_dic['x'] + gyr_mean[0] if abs(a_vel_dic['x'] + gyr_mean[0]) > filter_thres else 0.0
	i.angular_velocity.y = a_vel_dic['y'] + gyr_mean[1] if abs(a_vel_dic['y'] + gyr_mean[1]) > filter_thres else 0.0
	i.angular_velocity.z = a_vel_dic['z'] + gyr_mean[2] if abs(a_vel_dic['z'] + gyr_mean[2]) > filter_thres else 0.0
	i.angular_velocity_covariance = [gyr_var[0], 0., 0.,
									0., gyr_var[1], 0.,
									0., 0., gyr_var[2]]
	i.orientation_covariance = [-1., -1., -1.,
								-1., -1., -1.,
								-1., -1., -1.]
	return i

def pub_imu_data():
	rospy.init_node('imu_mpu',anonymous=True)
	imu_pub = rospy.Publisher('/imu_data',Imu, queue_size = 1)
	rate = rospy.Rate(20)
	while not rospy.is_shutdown():
		msg = get_data()
		imu_pub.publish(msg)
		rate.sleep()


if __name__ == '__main__':
	try:
		pub_imu_data()
	except rospy.ROSInterruptException:
		pass

