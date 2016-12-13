#include <StandardCplusplus.h>
#include <system_configuration.h>
#include <unwind-cxx.h>
#include <utility.h>
#include <vector>
#include "logik.h"
#include "CircularBuffer-int.h"
#define ZEROCROSS 2
#define d_in 3
#define redLed 32
#define yellowLed 33
#define greenLed 31

std::vector<int> bufferVec;
void dataIn();
void writeToVector(unsigned char);
logik l1;

CircularBuffer startBuf(4);



void setup() 
{
  pinMode(redLed, OUTPUT);
  pinMode(yellowLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(ZEROCROSS, INPUT);
  pinMode(d_in, INPUT);
}



void loop() 
{
  Serial.begin(9600);
  digitalWrite(redLed, LOW);
  digitalWrite(greenLed, HIGH);

if(digitalRead(ZEROCROSS) == 1)
{
   startBuf.insert( digitalRead(d_in) )
} 


//  unsigned char next_step = 0;

//  if(digitalRead(ZEROCROSS) == 1 && digitalRead(d_in) == 1)
//  {
//    dataIn();
//    digitalWrite(redLed, HIGH);
//  }
  
//  if(next_step != 0)
//  {
//    l1.readVec(bufferVec);
//    writeToVector(5);
//  }
}



void writeToVector(unsigned char i) 
{
  if(i==0)
  {
    bufferVec.push_back(0);
    Serial.print(0);
  }
  else if(i==1)
  {
    bufferVec.push_back(1);
    Serial.print(1);
  }
  else
  {
    bufferVec.erase(bufferVec.begin(), bufferVec.end() );
  }
}

void dataIn()
{
    digitalWrite(greenLed, LOW);
    unsigned int count = 0;
    if(count < 7 )
    {
      digitalWrite(yellowLed, HIGH);
      if(digitalRead(ZEROCROSS) == HIGH && digitalRead(d_in) == HIGH)
      {
        writeToVector(1);
        count++;
        delay(3);
      }
      if(digitalRead(ZEROCROSS) == HIGH && digitalRead(d_in) == LOW)
      {
        writeToVector(0);
        count++;
        delay(3);
      }
    } //end while
    digitalWrite(yellowLed, LOW);
}
