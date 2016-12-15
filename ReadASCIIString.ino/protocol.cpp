#include <StandardCplusplus.h>
#include <system_configuration.h>
#include <unwind-cxx.h>
#include <utility.h>

#include "protocol.h"
#include <bitset>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

protocol::protocol() {}

protocol::~protocol() {}

void protocol::readToVector(char *x, int size) {

  if (x[0] != '!') {
    /* EXIT */

  } else if (x[0] == '!') {

    for (auto i = 0; i < size; i++) {
      SaveVector.push_back(x[i]);

    } // end for loop
  }
}
void protocol::readToVector(string x) {

  int i = 0;

  if (x[0] != '!') {
    /* EXIT */

  } else if (x[0] == '!') {

    while (x[i] != '\n') {

      SaveVector.push_back(x[i]);
      i++;
    }
  }
  //	for (int i = 0; i <= antalElementer; ++i)
  //	{
  //		alarm1 = SaveVector[3];
  //		if (antalElementer == 2)
  //		{
  //			alarm2 = SaveVector[11];
  //		}
  //		if (antalElementer == 3)
  //		{
  //			alarm3 == SaveVector[19];
  //		}
  //	}
}
void protocol::readToVector(vector<char> a) { SaveVector = a; }

void protocol::printSavedVector() const {
  for (vector<char>::const_iterator i = SaveVector.begin();
       i != SaveVector.end(); ++i)
    cout << *i;
}

int protocol::antalElementer() {
  int antal = 0;
  for (auto i = SaveVector.begin(); i != SaveVector.end();) {
    if (SaveVector[i] == 'N') {
      antal++;
    }
    i++;
  }
  return antal;
}

void protocol::makeRawTime(int &size) {

  for (auto i = 0; i < size; i++) {
    if (SaveVector[i] == 'H' || SaveVector[i] == 'M') {
      for (auto j = i + 1; j < i + 3; j++) {
        RawtimeVec.push_back(charIntConverter(SaveVector[j]));
      }
    }
  }
}

void protocol::printTimes(std::vector<int> a) const {
  for (vector<int>::const_iterator i = a.begin(); i != a.end(); ++i)
    cout << *i;
}

vector<int> protocol::times(int &size) {
  makeRawTime(size);
  vector<int> useable;
  for (auto i = 0; i < RawtimeVec.size();) {

    auto a = RawtimeVec[i] * 10 + RawtimeVec[i + 1];
    useable.push_back(a);
    i = i + 2;
  }
  return useable;
}

void protocol::pushBack(char a) { SaveVector.push_back(a); }

char protocol::charIntConverter(int a) {
  if (a == 1) {
    return '1';
  }
  if (a == 2) {
    return '2';
  }
  if (a == 3) {
    return '3';
  }
  if (a == 4) {
    return '4';
  }
  if (a == 5) {
    return '5';
  }
  if (a == 6) {
    return '6';
  }
  if (a == 7) {
    return '7';
  }
  if (a == 8) {
    return '8';
  }
  if (a == 9) {
    return '9';
  } else {
    return '0';
  }
}

vector<char> protocol::getSaveVector() { return SaveVector; }

void protocol::resetSaveVector(std::vector<char> a) { SaveVector = a; }

int protocol::alarmTid(int a) {
  int alarmTidIMs;
  const int asciiConverter =
      48; // bruges til at modulere vores chars til talværdier.

  alarmTidIMs =
      (((int)SaveVector[4] % asciiConverter) * 1000) +
      (((int)SaveVector[5] % asciiConverter) * 100) +
      (((int)SaveVector[7] % asciiConverter) * 10) +
      (((int)SaveVector[8] % asciiConverter) * 1); // første enhed i ms

  return alarmTidIMs;
}
