#import evdev
from evdev import InputDevice, categorize, ecodes

#serial prep
import serial
port = "/dev/ttyACM0"
ser = serial.Serial(port,9600)
ser.flushInput()

#creates object 'gamepad' to store the data
gamepad = InputDevice('/dev/input/event0')

#button+analog codes
abtn = 304
bbtn = 305
xbtn = 307
ybtn = 308
#up = -1, down = 1
dvert = 17
#left = -1, right = 1
dhori = 16
xboxbtn = 316
leftstartbtn = 314
rightstartbtn = 315
leftbump = 310
rightbump = 311
leftjoypush = 317
rightjoypush = 318

#needs more testing
#leftjoyvert = 04
#leftjoyhori = 03
#rightjoyvert = 01
#rightjoyhori = 00

#min = 0, max = 1024
lefttrig = 02
righttrig = 05

#prints info at start
print(gamepad)
#evdev takes care of polling controller in loop
for event in gamepad.read_loop():
   print(event)
   if event.type == ecodes.EV_KEY:
	if event.value == 1:
	    if event.code == abtn:
		print("A")
		ser.write('A')
	    if event.code == bbtn:
		print("B")
		ser.write('B')
	    if event.code == xbtn:
		print("X")
		ser.write('X')
	    if event.code == ybtn:
		print("Y")
		ser.write('Y')
