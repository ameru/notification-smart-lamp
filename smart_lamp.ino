#include "SevSeg.h"
SevSeg myDisplay;

// initialize constants
const int OUTPUT_PIN = 13; // output connected to digital pin 13
int NEW_MAIL = LOW; // check for new mail
int VALUE; // value read from the serial port


void setup()
{
    pinMode(OUTPUT_PIN, OUTPUT); // sets the digital pin as output
    Serial.begin(9600);
    Serial.flush(); // wait for outgoing serial data transmission to complete
  
    // set to 1 for single digit display
    byte numDigits = 1;
  
    // defines common pins while using multi-digit display
    // left empty as we have a single digit display
    byte digitPins[] = {};
  
    // defines arduino pin connections in order: A, B, C, D, E, F, G, DP
    byte segmentPins[] = {3, 2, 8, 7, 6, 4, 5, 9};
    bool resistorsOnSegments = true;
  
    // initialize sevseg object
    sevseg.begin(COMMON_ANODE, numDigits, digitPins, segmentPins, resistorsOnSegments);
    sevseg.begin(COMMON_CATHODE, numDigits, digitPins, segmentPins, resistorsOnSegments);
  
    sevseg.setBrightness(90);
}


void loop()
{
    // read from serial port
    if (Serial.available()) // gets number of bytes available for reading from serial port
    {
        VALUE = Serial.read();
        Serial.println(VALUE);
        if (VALUE == 'M') NEW_MAIL = HIGH; // sets variable mail to true if data is "M" (mail)
        {
        // display numbers on 7 segment
        for(int i = 0; i < 10; i++) // increments number by 1 each time new mail
        {
             sevseg.setNumber(i); 
             sevseg.refreshDisplay();
             delay(1000);
        }
        else if (VALUE == 'N') NEW_MAIL = LOW; // sets variable mail to false if data is "N" (no mail)
    }
    // set the status of the output pin
    digitalWrite(OUTPUT_PIN, NEW_MAIL);
    }
}
