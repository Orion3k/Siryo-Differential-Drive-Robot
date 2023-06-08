# Import libraries
import RPi.GPIO as GPIO
import time
import sys

# Set GPIO numbering mode
GPIO.setmode(GPIO.BOARD)

# Set pin 11 as an output, and set servo1 as pin 11 as PWM
GPIO.setup(11,GPIO.OUT)
servo1 = GPIO.PWM(11,50) # Note 11 is pin, 50 = 50Hz pulse

input = float(sys.argv[1])
position = input if input <= 8.5 or input >= 2 else 4
servo1.start(0)

servo1.ChangeDutyCycle(position)

time.sleep(1)

servo1.stop()
GPIO.cleanup()
print ("Goodbye")
