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

volatile int lock1 = 0;
volatile int lock2 = 0;
int DikCount = 0;

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
  for (int i = 0; i < 14; i++) {
    pinMode(33 + i, OUTPUT);
  }
}



void loop()
{
  //  digitalWrite(redLed, LOW);
  //  digitalWrite(greenLed, HIGH);

  switch (digitalRead(ZEROCROSS))
  {
    case HIGH:
      if (lock1 == 0) {
        
        
        
        if (dataIn() == 0) {
          Serial.print(dataIn());
          lock2 = 1;
          lock1 = 1;
          
        }
      
      if (lock2 == 1) {       // Kun opfyldt hvis dataIn = 1, smider 1 tallet in i buffervec
        if (DikCount < 14) {
          
          int tryhard = dataIn();   // dataIn() er 1
          bufferVec.push_back( tryhard ); // dvs. den her kun bliver fyldt med et.
          lock2 = 1; 
          DikCount++;
        }
      }
      /*
      else                                // læser 0'er ind i buffervec når der ikke er 1 i dataIn().
      {
        int tryhardest = dataIn();        // dataIn() er 0 her
        bufferVec.push_back( tryhardest);
        DikCount++;                       
      }
      */
      if (DikCount == 13) {
        l1.readToVectorModtager(bufferVec);
       // showOutPut = 1;
        DikCount = 0;
      }
      }
      lock1=1;
      break;

    case LOW:
      
      if (lock1 == 1)
      {
        lock1 = 0;
      }
      break;
  }

  if (showOutPut == 1)
  {
    for (int z = 0; z < 14; z++) {
      Serial.print(l1.getVector()[z]);
      Serial.print(" ");
      if (l1.getVector()[z] == 1) {

        digitalWrite(33 + z, HIGH);
      }
    }
    showOutPut = 0;
    delay(30000);
    for (int p = 0; p < 14; p++) {
      digitalWrite(33 + p, LOW);
    }

    lock2 = 0;

  }
}




//    digitalWrite(greenLed, LOW);
//    digitalWrite(yellowLed, HIGH);
//  switch (digitalRead(ZEROCROSS))
//  {
//    case HIGH:
//      if (lock1 == 0)
//      {
//        if (lock2 == 0) {
//          tempBuff.push_back(dataIn());
//          count ++;
//        }
//        if (std::equal(tempBuff.begin(), tempBuff.end(), constBuff.begin() ) && DikCount <14) {
//          int tryhard = dataIn();
//          bufferVec.push_back( tryhard );
//          lock2 = 1;
//          DikCount++;
//        }
//        if(DikCount == 13){
//          l1.readToVectorModtager(bufferVec);
//          showOutPut = 1;
//        }
//        if (count >= 3) {
//          count = 0;
//          tempBuff.clear();
//        }
//        lock1 = 1;
//      }
//        break;
//
//    case LOW:
//      if (lock1 == 1)
//      {
//        lock1 = 0;
//      }
//        break;
//
//  }


/*-- LOCK --- */
/*
  int lock1, lock2 = 0;

  if (lock1 == 0)
  {
    if (digitalRead(ZEROCROSS) == HIGH)
    {
      lock1 = 1;
      lock2 = 1;  // låser locks


    }
    if(digitalRead(ZEROCROSS) == LOW)
    {
      lock1 = 0; // låser lock1 op
    }
    if(lock2 == 1)
    {
      int tryhard = dataIn();
      bufferVec.push_back( tryhard );
      lock2 = 0;
    }
*/
/////////////////////////

/*
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
*/




int dataIn() {

  if (digitalRead(d_in) == HIGH)
  {
    return 0;
  }
  else {
    return 1;
  }
}








