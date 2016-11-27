#include "protocol.h"
#include <vector>
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

}
int protocol::protocolLogic()
{
  return 3;
}


void protocol::testScenario() const
{

}
