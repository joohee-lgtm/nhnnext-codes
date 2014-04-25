#/Users/kimjoohwee/develop/next_codes/141_hci-aduino/loud


from xbee import XBee
import serial
import time

SerialPort = serial.Serial('/dev/tty.usbserial-A702LD1T',9600);
print SerialPort

MAXSOUND = 50;

while True:
	try:
		print "======================="
		print "max sound = 50"
		value = SerialPort.readline()
		if int(value) > MAXSOUND:
			print "CALM DOWN MAN~"
		else:
			print "PLAY! PLAY!"
		
		print "Your Volum : " + value
	except:
		print ("norequest")
		break

SerialPort.close()
