import serial, sys, feedparser

#Settings - Change these to match your account details
USERNAME="username@gmail.com"
PASSWORD="yourpassword"
PROTO="https://"
SERVER="mail.google.com"
PATH="/gmail/feed/atom"

SERIALPORT = "/dev/tty.usbserial-FTDK0P3M" # Change this to your serial port!

# Set up serial port
try:
    ser = serial.Serial(SERIALPORT, 9600)
except serial.SerialException:
    sys.exit()

newmails = int(feedparser.parse(
    PROTO + USERNAME + ":" + PASSWORD + "@" + SERVER + PATH
)["feed"]["fullcount"])

# Output data to serial port
if newmails > 0: ser.write('M')
else: ser.write('N')

# Close serial port
ser.close()
