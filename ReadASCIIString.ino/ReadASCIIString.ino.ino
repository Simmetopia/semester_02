#include <StandardCplusplus.h>
#include <system_configuration.h>
#include <unwind-cxx.h>
#include <utility.h>
#include <string>
#include <bitset>
#include <deque>
#include "protocol.h"
#include "vector"
#define F_CPU 16000000
#include <avr\io.h>
#include<avr\delay.h>
using namespace std;
void ConvertToBinary(int n);
// Function prototypes
void initHardware();
void burstOn();
int dataOut = 0;
vector<char> b;
const uint8_t ZeroCrossIn = 19; //INT2/RXD1
const int BurstPin = 11;        //Burst Pin/OC1A
const int LED4 = 10;
const int LED5 = 11;
const int LED6 = 12;
std::deque<int> fuckDigBui;
int readyToSend = 0;
string inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete
protocol p1;
int senderstuffs = -1;
int tempSize = 0;

void setup() {
  initHardware();
  // initialize serial:
  Serial.begin(9600);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);
  pinMode(44, OUTPUT);
  pinMode(42, OUTPUT);
  // reserve 200 bytes for the inputString:
  inputString.reserve(200);
}

void loop()
{

  if (stringComplete)
  {
    p1.readToVector(inputString);
    inputString = "";
    stringComplete = false;
    readyToSend = 1;
    
   // ConvertToBinary(p1.alarmTid(1));
  }

  
  if(digitalRead(ZeroCrossIn) == HIGH && readyToSend == 1){
  sendStartBit();
  }

  if(digitalRead(ZeroCrossIn) == HIGH && readyToSend == 2){
    if(tempSize == 0){
    ConvertToBinary(p1.alarmTid(1));
    p1.clearSavedVector();
    }
    if(tempSize < 14){
    for(int i = tempSize; i< 14; i++){
      fuckDigBui.push_front(0);
       tempSize++;
    }// end for
//    Serial.print(tempSize);
//    Serial.print(" ");
    } // end if
   
    if(fuckDigBui[dataOut] == 0){
      delay(3);
//      Serial.print(0);
//      Serial.print(" ");
    }
    if(fuckDigBui[dataOut] == 1){
      burstOn();
//      Serial.print(1);
//      Serial.print(" ");
    }
    dataOut++;
//    Serial.print(dataOut);
//    Serial.print(" ");
    if(dataOut >= 14){
      dataOut = 0;
      readyToSend = 0;
      tempSize=0;
      fuckDigBui.clear();
      
    }
  }


  //    int antalEnheder = p1.antalElementer();
  //
  //    std::vector<int> Enheder;
  //    for (int i = 0; i < antalEnheder; i++) {
  //
  //      for (int i = 0; i < p1.getSaveVector().size(); i++) {
  //        if (p1.getSaveVector()[i] == 'N') {
  //          Enheder.push_back( (int)p1.getSaveVector()[i + 1] );
  //        } // end if
  //      } // end inner for lopp
  //    } // end outer for
  //    for (int i = 0; i < antalEnheder; i++) {

  //    }


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

void initHardware()
{
  pinMode(ZeroCrossIn, INPUT);
  //------- FAST PWM SETUP --------//
  pinMode(BurstPin, OUTPUT);                    // PIN 11 OUTPUT BURST
  TCCR1A = 0; //default
  TCCR1B = 0; //default
  TCCR1A = (1 << WGM11);                                // fast PWM 14
  TCCR1B = (1 << WGM12) | (1 << WGM13) | (1 << CS10);                       // fast PWM 14 - PS: 1 = 120301 Hz
  ICR1 = 132 / 2;                                   // TOP 132/2.
  OCR1A = 66 / 2 ;                                   // 50% DUTY-CYCLE
}

void burst_ISR()               // run interrupt routine and detach interrupt after 1 ms.
{

  detachInterrupt(digitalPinToInterrupt(ZeroCrossIn));
}


void burstOn()                  //enable burst in 1 ms.
{
  //attachInterrupt(digitalPinToInterrupt(ZeroCrossIn), burst_ISR, RISING);
  TCCR1A |= (1 << COM1A0);            // OCR1A on - resten er det samme. Enable burst timer 1 120kHz.
  delay(1);
  TCCR1A &= (0 << COM1A0);  
  delay(2);// OCR1A off - resten er det samme. disable burst timer 1 120kHz
}

void sendStartBit(){
  
  
  if(senderstuffs < 3){
    burstOn();
    senderstuffs ++;
  }
  if(senderstuffs == 3){
    delay(11);
    senderstuffs = 0;
    readyToSend = 2;
  }
}


void ConvertToBinary(int n) /*recusiv følge*/
{ 
  if (n / 2 != 0) {
    ConvertToBinary(n / 2);
  }
tempSize++;
fuckDigBui.push_back(n%2);
//Serial.print(n%2);
//Serial.print(" ");
}

