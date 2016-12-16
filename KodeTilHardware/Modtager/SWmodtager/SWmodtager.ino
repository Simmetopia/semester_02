#include <StandardCplusplus.h>
#include <system_configuration.h>
#include <unwind-cxx.h>
#include <utility.h>
#include <vector>
#include <list>
#include "logik.h"
#define ZEROCROSS 2
#define d_in 3
//#define redLed 32
//#define yellowLed 33
//#define greenLed 31


int dataIn();
void writeToVector(unsigned char);
logik l1;
int  count = 0;
int showOutPut = 0;
const std::vector<int> constBuff = {1, 1, 1};
std::vector<int> tempBuff;
std::vector<int> bufferVec;




void setup() 
{
  Serial.begin(9600);
//  pinMode(redLed, OUTPUT);
//  pinMode(yellowLed, OUTPUT);
//  pinMode(greenLed, OUTPUT);
  pinMode(ZEROCROSS, INPUT);
  pinMode(d_in, INPUT);
  for(int i =0;i<14;i++){
    pinMode(33+i,OUTPUT);
  }
}



void loop() 
{
//  digitalWrite(redLed, LOW);
//  digitalWrite(greenLed, HIGH);
  

  if(digitalRead(ZEROCROSS) == HIGH)
  {
//    digitalWrite(greenLed, LOW);
//    digitalWrite(yellowLed, HIGH);
    switch (count) 
    {
      case 0:
        tempBuff.push_back(dataIn()) ;
        delay(2);
  
        break; 

      case 1:  
        tempBuff.push_back(dataIn());
        delay(2);
        break;

      case 2:
        tempBuff.push_back(dataIn());
        delay(2);
        break;

      case 3:
        tempBuff.push_back(dataIn());
        delay(1);
        break;

      default:
        // do something
        break;
    }
    count ++;

    if( std::equal(tempBuff.begin(), tempBuff.end(), constBuff.begin()) )
    { 
      int count2_=0;
        while(count2_ < 14)
        {

          if(digitalRead(ZEROCROSS) == HIGH)
          {
             delay(1);
            int tryhard = dataIn();
            bufferVec.push_back( tryhard );
            count2_++;
            delay(4);
            
          } // end inner if
            
//          digitalWrite(redLed,HIGH);
          
        } // end while
        l1.readToVectorModtager(bufferVec);
        Serial.print("\n");
//        Serial.println(l1.binaryConverter() );
        bufferVec.clear();
//        digitalWrite(redLed,LOW);
        showOutPut = 1;
        tempBuff.clear();

     } // end main if
if(showOutPut == 1)
{
  for(int z=0; z<14; z++){
            Serial.print(l1.getVector()[z]);
            Serial.print(" ");
      if(l1.getVector()[z] == 1){

          digitalWrite(33+z, HIGH);
      }
  }
  delay(30000);
  for(int p=0; p<14; p++){
      digitalWrite(33+p, LOW);
  }
  showOutPut = 0;
  
}
  if(count > 3)
  {
      count = 0;
      tempBuff.clear();
//      digitalWrite(yellowLed, LOW);


  }
  }
}

int dataIn(){

if(digitalRead(d_in) == HIGH)
{
  return 0;
}
else {
return 1;
}
}


  





