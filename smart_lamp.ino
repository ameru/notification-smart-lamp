// initialize constants
const int OUTPUT_PIN = 13; // output connected to digital pin 13
int NEW_MAIL = LOW; // check for new mail
int VALUE; // value read from the serial port


void setup()
{
    pinMode(OUTPUT_PIN, OUTPUT); // sets the digital pin as output
    Serial.begin(9600);
    Serial.flush(); // wait for outgoing serial data transmission to complete
}


void loop()
{
    // Read from serial port
    if (Serial.available()) // gets number of bytes available for reading from serial port
    {
        VALUE = Serial.read();
        Serial.println(VALUE);
        if (VALUE == 'M') NEW_MAIL = HIGH; // sets variable mail to true if data is "M" (mail)
        else if (VALUE == 'N') NEW_MAIL = LOW; // sets variable mail to false if data is "N" (no mail)
    }

    // Set the status of the output pin
    digitalWrite(OUTPUT_PIN, NEW_MAIL);
}
