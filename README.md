# Arduino Email Notifier Smart Lamp
The LED lights up everytime you get incoming mail in your Gmail, and the number on the display increments for every new email. You'll have to manually reset the program to reset the number count.

![IMG_3444](https://user-images.githubusercontent.com/44534814/120252014-1fa81b80-c238-11eb-956c-a649194310cb.jpg)

### Hardware
- LED (go further: use an RGB LED and set different senders as different colors in your inbox by setting up rules)
- 7 segment display
- 9 resistors
- several jumper wires
- Arduino UNO
- USB cable connected to laptop

** Disclaimer: I am a Mac user, formatting and file saving directions may be different for Windows users


Here's the Tinkercad setup:

![email_smart_lamp](https://user-images.githubusercontent.com/44534814/120252048-40707100-c238-11eb-887f-137dd36058d5.png)

### Software
This project requires two bits of software: one running on the Arduino to receive serial data and toggle the output accordingly, and one running on the computer to check for new emails and send data out over the serial port.
1. Upload the .ino file in this repo to your Arduino program and connect your output device to pin 13.
2. Next, make the necessary changes to the .py script. If the serial port opens successfully, the script has to talk to Google's servers to determine if you have any new email waiting for you. It does this by authenticating with your Gmail username and password, and then requesting the Atom feed for your inbox. Make sure you have the pySerial library installed! This script needs to be run regularly so that when you get a new email, your notifier will light up promptly.
3. Save the .plist file in ~/Library/LaunchAgents (create this folder if it doesn't exist). Don't forget to change the second ProgramArguments string to the location of your Python script.
4. You may need to alter the /usr/bin/python string in this plist file to point to the location of the Python interpreter on your machine, for example /usr/local/bin/python2.5. 
5. To load this .plist file into launchd, type <launchctl load ~/Library/LaunchAgents/users.amy.check-gmail.plist> in the terminal.

