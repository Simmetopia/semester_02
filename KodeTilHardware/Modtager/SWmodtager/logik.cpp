#include "logik.h"
#include <vector>

logik::logik(){
  }

logik::~logik(){ }


void logik::readToVectorModtager(std::vector<int> a)
{
	tidsBin = a;
}

int logik::binaryConverter()
{
	int x = 1;
	int tal = 0;
	for (int i = tidsBin.size(); i > 0 ; --i)
	{		
		tal =+ tidsBin[i] * x;
    x=x*2;
	}

	return tal-1;
}


