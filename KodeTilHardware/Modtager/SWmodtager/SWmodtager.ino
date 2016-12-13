#include <StandardCplusplus.h>
#include <system_configuration.h>
#include <unwind-cxx.h>
#include <utility.h>
#include <vector>
#include "logik.h"
#define ZEROCROSS 2
#define d_in 3
#define redLed 32
#define yellowLed 33
#define greenLed 31


void dataIn();
void writeToVector(unsigned char);
logik l1;
int  count = 0;
const std::vector<int> constBuff = {1, 1, 1, 0};
std::vector<int> tempBuff;
std::vector<int> bufferVec;




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


  if(ZEROCROSS == 1)
  {
    digitalWrite(greenLed, LOW);
    digitalWrite(yellowLed, HIGH);
  
    
    switch (count) 
    {
      case 0:
        tempBuff.push_back(digitalRead(d_in)) ;
        break; 

      case 1:  
        tempBuff.push_back(digitalRead(d_in))
        break;

      case 2:
        tempBuff.push_back(digitalRead(d_in))
        break;

      case 3:
        tempBuff.push_back(digitalRead(d_in))
        break;

      default:
        // do something
        break;
    }
    count ++;

    if( tempBuff == constBuff )
    { 
      int count2_=0;
        while(count2_ < 14)
        {
          if(digitalRead(ZEROCROSS) == 1)
          {
            bufferVec.push_back(digitalRead(d_in) )
          } // end inner if

          digitalWrite(redLed,HIGH);
        } // end while
        l1.readToVectorModtager(bufferVec);
        bufferVec.erase(bufferVec.data(),bufferVec.size());
        digitalWrite(redLed,LOW);

     } // end main if

  if(count > 4)
  {
      count = 0;

  }


  
}




