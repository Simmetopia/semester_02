#include "Scenarier.h"
#include "Actions.h"
#include <iostream>


Scenarier::Scenarier()
{
	
}


Scenarier::~Scenarier()
{
}

void Scenarier::addAction(int& hour, int & minut)
{
	Actions ny_actions(hour, minut);
	aktioner.push_back(ny_actions);
}

void Scenarier::antalAktioner(char p) const
{
	std::cout << "Der er " << aktioner.size() << std::endl;
}

int Scenarier::antalAktioner() const
{
	return aktioner.size();
}

std::vector<char> Scenarier::getScenarieStreng()
{
	return scenariestreng;
}

void Scenarier::setScenarieStreng(std::vector<char> a)
{
	scenariestreng = a;
}


