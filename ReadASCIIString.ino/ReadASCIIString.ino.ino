#include <StandardCplusplus.h>
#include <system_configuration.h>
#include <unwind-cxx.h>
#include <utility.h>
#include <string>
#include "protocol.h"
#include "Actions.h"
#include "Scenarier.h"
#include "ScenarierList.h"
#include "vector"
#define F_CPU 16000000
#include <avr\io.h>
#include<avr\delay.h>
using namespace std;

// Function prototypes
void initHardware();
void burstOn();
void burstOff();



vector<char> b;
const uint8_t ZeroCrossIn = 19; //ændret til PIN 19 fra 0, da vi kører INT2 
const int LED4 = 10;
const int LED5 = 11;
const int LED6 = 12;
string inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete
protocol p1;
//int timerInterruptCounter = 0;


void setup() {
  initHardware();
  // initialize serial:
  Serial.begin(9600);
  pinMode(LED4, OUTPUT);
}

void loop()
{
  //if any zeroX, the INT2- interrupt routine will run

   
  if (stringComplete) {
    p1.readToVector(inputString);
   
        inputString = "";
    stringComplete = false;
  }
  
}


void serialEvent() 
{
      stringComplete = true;
}

// INT2 routine, burst 120kHz for 1ms, then goes to loop.
ISR(INT2_vect)    //INT2 PIN 19
{
  sei();    //Global-int enable
  burstOn();
  delay(1);
  burstOff();
}





