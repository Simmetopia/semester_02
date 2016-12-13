#include "protocol.h"
#include <vector>
#include <iostream>
#include <string>
using namespace std;


protocol::protocol()
{
}


protocol::~protocol()
{
}

void protocol::readToVector(char* x, int size)
{

	if (x[0] != '!')
	{
		/* EXIT */

	}
	else if (x[0] == '!')
	{
		

		for (auto i = 0; i < size; i++)
		{
			SaveVector.push_back(x[i]);
			
		}//end for loop
	}
}
void protocol::readToVector(string x)
{

  int i = 0;

  if (x[0] != '!')
  {
    /* EXIT */

  }
  else if (x[0] == '!')
  {
    

        
       while(x[i] != '\n')
       {
    
        
        SaveVector.push_back(x[i]);
        i++;
      
    }
  }
}
void protocol::readToVector(vector<char> a)
{

	SaveVector = a;
}

void protocol::printSavedVector() const
{
	for (vector<char>::const_iterator i = SaveVector.begin(); i != SaveVector.end(); ++i)
		cout << *i;
}

int protocol::antalElementer(int size)
{
	int antal = 0;
	for (auto i = 0; i <size ; i++)
	{
		if (SaveVector[i] == 'N')
		{
			antal++;
		}
		
	}
	return antal;
}

void protocol::makeRawTime(int& size)
{

	for (auto i = 0; i < size; i++)
	{
		if (SaveVector[i] == 'H' || SaveVector[i] == 'M')
		{
			for (auto j = i+1; j < i + 3; j++)
			{
				RawtimeVec.push_back(charIntConverter(SaveVector[j]));
			}
		}
		
	}

}



void protocol::printTimes(std::vector<int> a) const
{
	for (vector<int>::const_iterator i = a.begin(); i != a.end(); ++i)
		cout << *i;
}

vector<int> protocol::times(int &size)
{
	makeRawTime(size);
	vector<int> useable;
	for (auto i = 0; i < RawtimeVec.size();)
	{
		
			auto a = RawtimeVec[i] * 10 + RawtimeVec[i + 1];
			useable.push_back(a);
			i = i + 2;
	}
	return  useable;
}

void protocol::pushBack(char a)
{
	SaveVector.push_back(a);
}

char protocol::charIntConverter(int a)
{
	if (a == 1)
	{
		return '1';
	}
	if (a ==2)
	{
		return '2';
	}
	if (a == 3)
	{
		return '3';
	}
	if (a == 4)
	{
		return '4';
	}
	if (a == 5)
	{
		return '5';
	}
	if (a == 6)
	{
		return '6';
	}
	if (a == 7)
	{
		return '7';
	}
	if (a == 8)
	{
		return '8';
	}
	if (a == 9)
	{
		return '9';
	}
	else
	{
		return '0';
	}
}

vector<char> protocol::getSaveVector()
{
	return SaveVector;
}

int protocol::protocolLogic(){
  if(antalElementer(SaveVector.size()) == 1){

    return 1;
    
  }
  else if(antalElementer(SaveVector.size()) == 2){

    return 2;
    
  }
  else if(antalElementer(SaveVector.size()) == 3){

    return 3;
    
  }
  else{

    return 0;
  }
}
void protocol::resetSaveVector(std::vector<char> a){
  SaveVector = a;
}

void protocol::alarmTid(std::vector<char> &v, int * a)
{
int alarmTidIMs;
const int asciiConverter = 48; // bruges til at modulere vores chars til talværdier.

  for (int i = 0; i != v.size(); i++)
  {
	  if (v[i] == 'N')
	  {
		  switch (v[i + 1])
      {
        case '1':
		alarmTidIMs = (((int)v[4] % asciiConverter) * 1000) + (((int)v[5] % asciiConverter) * 100) + (((int)v[7] % asciiConverter) * 10) + (((int)v[8] % asciiConverter) * 1);  // første enhed i ms
		break;

        case '2':
        alarmTidIMs = (((int)v[((4*2)-1)] % asciiConverter)*1000) + (((int)v[((5*2)-1)] % asciiConverter)*100) + (((int)v[(7*2)-1] % asciiConverter)*10) + (((int)v[(8*2)-1] % asciiConverter) *1);  // anden enhed i ms
        break;

        case '3':
        alarmTidIMs = (((int)v[(5*3)-1] % asciiConverter)*1000) + (((int)v[(6*3)-1] % asciiConverter)*100) + (((int)v[(8*3)-1] % asciiConverter)*10) + ((int)v[(9*3)-1] % asciiConverter *1); // tredje enhed i ms
        break;

		default:
		alarmTidIMs = (((int)v[4] % asciiConverter) * 1000) + (((int)v[5] % asciiConverter) * 100) + (((int)v[7] % asciiConverter) * 10) + (((int)v[8] % asciiConverter) * 1);  // Default er tilsvarende den første
        break;
      }
    }
  }
}

std::vector<int> protocol::ConvertToBinary()
{
	
	int n = alarmTid(SaveVector);
	if (n / 2 != 0) {
    ConvertToBinary(n / 2);
    }
    printf("%d", n % 2);
}
