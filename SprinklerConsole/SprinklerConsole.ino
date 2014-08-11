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

#include <Console.h>
#include <Bridge.h>


OSBee osb;

void setup() {

  Bridge.begin();
  Console.begin();
  Console.println("Sprinkler Control");
  Console.print("Initializing the bridge...");
  while (!Console) {
    ; // wait for Console port to connect.
  }

  Console.println("Done");
  pinMode(ledPin, OUTPUT);
  // these are optional parameters
  osb.setVoltage(12.0);
  //osb.setPulseLength(100);
  osb.setDutyCycle(20);

  // must call the begin() function for proper initialization
  osb.begin();
  Console.println("You're connected to the Console!!!!");

}

void loop() {
  Console.println("Hit 'A' to turn on sprinkler and 'Z' to turn off sprinkler 1");
  if (Console.available() > 0) {
    // read the oldest byte in the serial buffer:
    incomingByte = Console.read();
    delay(100);
     if (incomingByte == 'A') {
          digitalWrite(ledPin, HIGH);
          Console.println("A Open");
         osb.open('A');
    }
    if (incomingByte == 'Z') {
          osb.close('A');
          digitalWrite(ledPin, LOW);
          Console.println("A Closed");
      }  
  }
   delay(100);
  }
