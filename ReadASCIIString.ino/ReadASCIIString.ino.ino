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
const uint8_t ZeroCrossIn = 19; //INT2/RXD1 
const int BurstPin = 11;        //Burst Pin/OC1A
const int LED4 = 10;
const int LED5 = 11;
const int LED6 = 12;
string inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete
protocol p1;
// zero cross/burst variable that changes
volatile int zeroState = 0;


void setup() {
  initHardware();
  // initialize serial:
  Serial.begin(9600);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);

  // reserve 200 bytes for the inputString:
  inputString.reserve(200);
}

void loop() {

  if (digitalRead(ZeroCrossIn) == 0)
  {
    burstOn();
    _delay_ms(1);
    burstOff();
    delay(200);
  }

  
  
  
  
  if (stringComplete) {
    p1.readToVector(inputString);
        inputString = "";
    stringComplete = false;
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

void initHardware(){
  pinMode(ZeroCrossIn, INPUT);
  //------- FAST PWM SETUP --------//
  pinMode(BurstPin, OUTPUT);                    // PIN 11 OUTPUT BURST 
  TCCR1A = 0; //default
  TCCR1B = 0; //default
  TCCR1A = (1 << WGM11);                                // fast PWM 14
  TCCR1B = (1 << WGM12) | (1 << WGM13) | (1<< CS10);                        // fast PWM 14 - PS: 1 = 120301 Hz
  ICR1 = 132/2;                                     // TOP 132.
  OCR1A = 66/2 ;                                     // 50% DUTY-CYCLE
  //------- attachInterrupt try --------//
  attachInterrupt(digitalPinToInterrupt(ZeroCrossIn),burst_ISR, CHANGE);
}

void burst_ISR(){
  zeroState = digitalRead(ZeroCrossIn);
  if(zeroState == 0){
    burstOn();
    delay(1);
    burstOff();
  }
  else{
    burstOff();
  }
}

//void activateInterrupt2(){
//  EICRA &= (0 << ISC20 | 0 << ISC21); //clear existing flags
//  EICRA |= (1 << ISC20);              //set wanted flags (any change intterupt)
//  EIFR  |= (1 << INTF2);              //clear flag for INT 2
//  EIMSK |= (1 << INT2);               //enable INT 2
//} 

//void deactivateInterrupt2(){
//  EIMSK &= (0 << INT2);               //disable INT2
//}

// if

void burstOn()                  //enable burst timer 1 120kHz
{
  
  TCCR1A |= (1 << COM1A0);            // OCR1A on - resten er det samme.
}
void burstOff()                 //disable burst timer 1 120kHz
{
  TCCR1A &= (0 << COM1A0);            // OCR1A off - resten er det samme.
}

