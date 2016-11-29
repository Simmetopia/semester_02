#include "Scenarier.h"
#include "Actions.h"
#include <iostream>


Scenarier::Scenarier()
{
	std::cout << "Ikke valgt hvor mange handler du ønsker der skal ske, prøv igen" << std::endl;
}


Scenarier::Scenarier(int& aktioner)
{
	for (size_t i = 0; i < aktioner; i++)
	{	
		int hour, minut;
		std::cout << "Vælg først timer, så minutter, hver afsluttet af enter til scenarie:" << i << std::endl;
		std::cin >> hour;
		std::cin >> minut;
		Actions nyAktion(hour, minut);
		addAction(nyAktion);
	}
}

Scenarier::~Scenarier()
{
}

void Scenarier::addAction(Actions& aktion)
{
	aktioner.push_back(aktion);
}

void Scenarier::antalAktioner() const
{
	std::cout << "Der er " << aktioner.size() << std::endl;
}
