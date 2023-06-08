#!/usr/bin/env python

import picamera

camera = picamera.PiCamera()

camera.capture('test.jpg')
camera.close
