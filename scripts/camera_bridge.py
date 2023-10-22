#!/usr/bin/env python3

import numpy as np
import cv2
import rospy
from sensor_msgs.msg import Image
from cv_bridge import CvBridge, CvBridgeError
from std_msgs.msg import Bool, String

class CameraBridge:

    def __init__(self):
        self.heigth = 120
        self.width = 200
        self.bridge = CvBridge()
        self.camera_on = True
        rospy.Subscriber("/camera/activate", Bool, self.activate_camera)
        self.img_pub = rospy.Publisher("/camera/image_raw", Image,
                              queue_size=10)
        self.video = cv2.VideoCapture(0)
        if not self.video.isOpened():
            rospy.logerr("cannot open camera ")
        fps = 10
        # Get frame rate.
        self.rate = rospy.Rate(fps)

    def activate_camera(self, msg):
        self.camera_on = msg.data

    def main_loop(self):

        while not rospy.is_shutdown() and self.video.grab():
            if self.camera_on:
                # capture image frame
                tmp, img = self.video.retrieve()
                if not tmp:
                    rospy.logerr("Could not grab frame.")
                    pass
                rsz_image = cv2.resize(img, (self.width, self.heigth)) 
                try:
                    # Publish image.
                    img_msg = self.bridge.cv2_to_imgmsg(rsz_image, "bgr8")
                    img_msg.header.stamp = rospy.Time.now()
                    img_msg.header.frame_id = "camera"
                    self.img_pub.publish(img_msg)
                except CvBridgeError as err:
                    rospy.logerr(err)
            self.rate.sleep()

        self.video.release()
        return

if __name__ == '__main__':
    # Init node
    rospy.init_node("camera_bridge", anonymous=True)
    cb = CameraBridge()
    cb.main_loop()
