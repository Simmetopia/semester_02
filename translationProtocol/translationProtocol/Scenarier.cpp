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

void Scenarier::antalAktioner() const
{
	std::cout << "Der er " << aktioner.size() << std::endl;
}
