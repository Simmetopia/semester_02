#include "ScenarierList.h"
#include "Scenarier.h"
#include <iostream>


ScenarierList::ScenarierList()
{
}


ScenarierList::~ScenarierList()
{
}

void ScenarierList::addScenarie()
{
	int antalaktioner;
	std::cout << "hvor mange hændelser ønsker du koplet til dette scenarie?" << std::endl;
	std::cin >> antalaktioner;
	Scenarier nytScenarie(antalaktioner);
	scenarielist.push_back(nytScenarie);
}

void ScenarierList::AntalElementer() const
{
	std::cout << scenarielist.size() << std::endl;
}

void ScenarierList::AntalaktionerIScenarie(int &nummer) const
{
	scenarielist[nummer-1].antalAktioner();

}
