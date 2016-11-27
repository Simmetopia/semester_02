#include <StandardCplusplus.h>
#include <system_configuration.h>
#include <unwind-cxx.h>
#include <utility.h>

#include "protocol.h"
#include "vector"
const int LED4 = 10;
const int LED5 = 11;
const int LED6 = 12;
String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete
protocol p1;
void setup() {
  // initialize serial:
  Serial.begin(9600);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);

  // reserve 200 bytes for the inputString:
  inputString.reserve(200);
}

void loop() {
  // print the string when a newline arrives:
  if (stringComplete) {
    Serial.println(inputString);
    switch ( p1.protocolLogic() ) {
      case 1:
        digitalWrite(LED4, HIGH);
        break;
      case 2:
        digitalWrite(LED5, HIGH);
        break;
      case 3:
        digitalWrite(LED6, HIGH);
        break;
      default:
        digitalWrite(LED4, HIGH);
        digitalWrite(LED5, HIGH);
        digitalWrite(LED6, HIGH);
        break;
    }
    delay(1000);
    // clear the string:
    inputString = "";
    stringComplete = false;
    digitalWrite(LED4, LOW);
  }
}

/*
  SerialEvent occurs whenever a new data comes in the
  hardware serial RX.  This routine is run between each
  time loop() runs, so using delay inside loop can delay
  response.  Multiple bytes of data may be available.
*/
void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:
    if (inChar == '\n') {
      stringComplete = true;
    }
  }
}
