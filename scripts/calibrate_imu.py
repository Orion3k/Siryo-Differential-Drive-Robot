#!/usr/bin/env python
import rospy
from sensor_msgs.msg import Imu
from geometry_msgs.msg import Vector3

class Calibration:

	def __init__(self):
		self.n_samples = 1000
		self.acc_x = []
		self.acc_y = []
		self.acc_z = []
		self.gyr_x = []
		self.gyr_y = []
		self.gyr_z = []
		self.count = 0
		self.sub_imu_data()

	def callback(self,data):
		self.count += 1
		#rospy.loginfo("Callback called")
		if self.count < self.n_samples:
			self.acc_x.append(data.linear_acceleration.x)
			self.acc_y.append(data.linear_acceleration.y)
			self.acc_z.append(data.linear_acceleration.z)
			self.gyr_x.append(data.angular_velocity.x)
			self.gyr_y.append(data.angular_velocity.y)
			self.gyr_z.append(data.angular_velocity.z)
		else:
			self.compute_mean_var()

	def compute_mean_var(self):
		acc_mean = [0.,0.,0.]
		for x in self.acc_x:
			acc_mean[0] += x
		for y in self.acc_y:
			acc_mean[1] += y
		for z in self.acc_z:
			acc_mean[2] += z

		gyr_mean = [0.,0.,0.]
		for x in self.gyr_x:
			gyr_mean[0] += x
		for y in self.gyr_y:
			gyr_mean[1] += y
		for z in self.gyr_z:
			gyr_mean[2] += z

		acc_mean[0] = acc_mean[0]/self.n_samples
		acc_mean[1] = acc_mean[1]/self.n_samples
		acc_mean[2] = acc_mean[2]/self.n_samples

		gyr_mean[0] = gyr_mean[0]/self.n_samples
		gyr_mean[1] = gyr_mean[1]/self.n_samples
		gyr_mean[2] = gyr_mean[2]/self.n_samples

		acc_var = [0.,0.,0.]
		for x in self.acc_x:
			acc_var[0] += (x - acc_mean[0])**2
		for y in self.acc_y:
			acc_var[1] += (y - acc_mean[1])**2
		for z in self.acc_z:
			acc_var[2] += (z - acc_mean[2])**2

		gyr_var = [0.,0.,0.]
		for x in self.gyr_x:
			gyr_var[0] += (x - gyr_mean[0])**2
		for y in self.gyr_y:
			gyr_var[1] += (y - gyr_mean[1])**2
		for z in self.gyr_z:
			gyr_var[2] += (z - gyr_mean[2])**2

		acc_var[0] = acc_var[0]/(self.n_samples-1)
		acc_var[1] = acc_var[1]/(self.n_samples-1)
		acc_var[2] = acc_var[2]/(self.n_samples-1)
		gyr_var[0] = gyr_var[0]/(self.n_samples-1)
		gyr_var[1] = gyr_var[1]/(self.n_samples-1)
		gyr_var[2] = gyr_var[2]/(self.n_samples-1)

		print("acc mean: ",acc_mean, "acc var: ",acc_var)
		print("gyro mean : ", gyr_mean, "gyro var: ", gyr_var)

	def sub_imu_data(self):
		rospy.init_node('calibrate_imu',anonymous=True)
		imu_sub = rospy.Subscriber('imu_odom',Imu,self.callback)
		rospy.spin()

if __name__ == '__main__':
	try:
		calib = Calibration()
	except rospy.ROSInterruptException:
		pass
