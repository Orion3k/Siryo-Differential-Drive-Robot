#!/usr/bin/env python
import rospy
from mpu6050 import mpu6050
from sensor_msgs.msg import Imu
from geometry_msgs.msg import Quaternion, Vector3, PoseStamped

sensor = mpu6050(0x68)

def get_data():
	i = Imu()
	i.header.stamp = rospy.Time.now()
	i.header.frame_id = 'imu_base'
	l_acel = sensor.get_accel_data(g=False)
	i.linear_acceleration.x = l_acel['x']
	i.linear_acceleration.y = l_acel['y']
	i.linear_acceleration.z = l_acel['z']
	a_vel = sensor.get_gyro_data()
	i.angular_velocity.x = a_vel['x']
	i.angular_velocity.y = a_vel['y']
	i.angular_velocity.z = a_vel['z']
	return i

def pub_imu_data():
	rospy.init_node('imu_mpu',anonymous=True)
	imu_pub = rospy.Publisher('imu_odom',String, queue_size = 1)
	rate = rospy.Rate(10)
	while not rsospy.is_shutdown():
		msg = get_data()
		imu_pub.publish(i)
		rate.sleep()


if __name__ == '__main__':
	try:
		pub_imu_data()
	except rospy.ROSInterruptException:
		pass
