#include <StandardCplusplus.h>
#include <system_configuration.h>
#include <unwind-cxx.h>
#include <utility.h>

#include "senderLogik.h"

#define switchDonger  38 // switch 0
#define sendTid  13      // LED7

//////////////////////////////////////
/* Vector med vores char koden */ 
char a[] = "!N1H12M30";

std::vector<char> testVec(a, a + strlen(a));
////////////////////////////////////////
void setup()
{
    pinMode(switchDonger, INPUT);
    pinMode(sendTid, OUTPUT);
}

void loop()
{
  if (digitalRead(switchDonger) == LOW)
  {
    digitalWrite(sendTid, HIGH);
    delay(alarmTid(testVec));       // sender til tiden 1230 ms svarende til 1.23 sekunder
    digitalWrite(sendTid, LOW);
  }
}



