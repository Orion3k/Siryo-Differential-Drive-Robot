#!/usr/bin/env python
import rospy
from sensor_msgs.msg import Imu
from geometry_msgs.msg import Vector3

n_samples = 10000
acc_x = []
acc_y = []
acc_z = []
gyr_x = []
gyr_y = []
gyr_z = []
count = 0

def callback(data):
	count += 1
	if count < n_samples:
		acc_x.append(data.linear_acceleration.x)
		acc_y.append(data.linear_acceleration.y)
		acc_z.append(data.linear_acceleration.z)
		gyr_x.append(data.angular_velocity.x)
		gyr_y.append(data.angular_velocity.y)
		gyr_z.append(data.angular_velocity.z)
	else:
		compute_mean_var()

def compute_mean_var():
	acc_mean = [0.,0.,0.]
	for x in acc_x:
		acc_mean[0] += x
	for y in acc_y:
		acc_mean[1] += y
	for z in acc_z:
		acc_mean[2] += z

	gyr_mean = [0.,0.,0.]
	for x in gyr_x:
		gyr_mean[0] += x
	for y in gyr_y:
		gyr_mean[1] += y
	for z in gyr_z:
		gyr_mean[2] += z

	acc_mean[0] = acc_mean[0]/n_samples
	acc_mean[1] = acc_mean[1]/n_samples
	acc_mean[2] = acc_mean[2]/n_samples

	gyr_mean[0] = gyr_mean[0]/n_samples
	gyr_mean[1] = gyr_mean[1]/n_samples
	gyr_mean[2] = gyr_mean[2]/n_samples

	acc_var = [0.,0.,0.]
	for x in acc_x:
		acc_var[0] += (x - acc_mean[0])**2
	for y in acc_y:
		acc_var[1] += (y - acc_mean[1])**2
	for z in acc_z:
		acc_var[2] += (z - acc_mean[2])**2

	gyr_var = [0.,0.,0.]
	for x in gyr_x:
		gyr_var[0] += (x - gyr_mean[0])**2
	for y in gyr_y:
		gyr_var[1] += (y - gyr_mean[1])**2
	for z in gyr_z:
		gyr_var[2] += (z - gyr_mean[2])**2

	acc_var[0] = acc_var[0]/(n_samples-1)
	acc_var[1] = acc_var[1]/(n_samples-1)
	acc_var[2] = acc_var[2]/(n_samples-1)
	gyr_var[0] = gyr_var[0]/(n_samples-1)
	gyr_var[1] = gyr_var[1]/(n_samples-1)
	gyr_var[2] = gyr_var[2]/(n_samples-1)

	print("acc mean: ",acc_mean, "acc var: ",acc_var)
	print("gyro mean : ", gyr_var, "gyro var: ", gyr_var)

def sub_imu_data():
	rospy.init_node('calibrate_imu',anonymous=True)
	count = 0
	imu_sub = rospy.Subscriber('imu_odom',Imu,callback)
	rospy.spin()

if __name__ == '__main__':
	try:
		sub_imu_data()
	except rospy.ROSInterruptException:
		pass
