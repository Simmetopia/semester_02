#include "protocol.h"
#include <vector>
#include <iostream>
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

void protocol::printSavedVector() const
{
	for (vector<char>::const_iterator i = SaveVector.begin(); i != SaveVector.end(); ++i)
		cout << *i << ' ';
}

void protocol::testScenario() const
{
	if(SaveVector[1] == 'I')
	{
		cout << "Der oprettes et scenarie!" << endl;

	} else
	{
		cout << "Fejl i kode!!" << endl;
	}
}
