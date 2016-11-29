#include "ScenarierList.h"
#include "Scenarier.h"
#include "protocol.h"
#include <iostream>
#include <vector>


ScenarierList::ScenarierList()
{
}


ScenarierList::~ScenarierList()
{
}

void ScenarierList::addScenarie(char* a)
{
	int sizeOfArray = strlen(a) + 1;
	protocol pr1;
	pr1.readToVector(a, sizeOfArray);
	Scenarier nyt_scenarier;
	for (auto i = 0; i < pr1.antalElementer(sizeOfArray) * 2 ;)
	{
		auto hour = pr1.times(sizeOfArray)[i];
		auto minut = pr1.times(sizeOfArray)[i+1];
		i = i + 2;
		nyt_scenarier.addAction(hour, minut);
	}
	scenarielist.push_back(nyt_scenarier);
	
}

void ScenarierList::AntalElementer() const
{
	std::cout << scenarielist.size() << std::endl;
}

void ScenarierList::AntalaktionerIScenarie(int nummer) const
{
	scenarielist[nummer - 1].antalAktioner();

}
