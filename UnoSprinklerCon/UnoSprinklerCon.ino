/*
   Simple Test program for OSBee Shield
   This demo opens and closes each valve
   for 10 seconds, one after another

   http://bee.opensprinkler.com

   License: Creative Commons CC-SA 3.0

   Written by : Ray Wang (Rayshobby LLC)
   info@rayshobby.net

*/

#include <OSBee.h>

#define DELAY_TIME  3000
int incomingByte;
const int ledPin = 13;

//#include <Serial.h>
//#include <Bridge.h>


OSBee osb;

void setup() {

  Serial.begin(9600);
  while (!Serial) {
    ; // wait for Serial port to connect.
  }

  Serial.println("Done");
  pinMode(ledPin, OUTPUT);
  // these are optional parameters
  osb.setVoltage(12.0);
  //osb.setPulseLength(100);
  osb.setDutyCycle(20);

  // must call the begin() function for proper initialization
  osb.begin();
  Serial.println("You're connected to the Serial!!!!");

}

void loop() {
  Serial.println("Hit 'A' to turn on sprinkler and 'Z' to turn off sprinkler 1");
  if (Serial.available() > 0) {
    // read the oldest byte in the serial buffer:
    incomingByte = Serial.read();
    delay(100);
     if (incomingByte == 'A') {
          digitalWrite(ledPin, HIGH);
          Serial.println("A Open");
         osb.open('A');
    }
    if (incomingByte == 'Z') {
          osb.close('A');
          digitalWrite(ledPin, LOW);
          Serial.println("A Closed");
      }  
  }
   delay(100);
  }
