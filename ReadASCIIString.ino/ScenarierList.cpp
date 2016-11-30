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
	int sizeOfArray = strlen(a);
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
	nyt_scenarier.setScenarieStreng(pr1.getSaveVector());
	scenarielist.push_back(nyt_scenarier);
	
	
}

void ScenarierList::addScenarie(std::vector<char> a)
{
	int sizeOfArray = a.size();
	protocol pr1;
	pr1.readToVector(a);
	Scenarier nyt_scenarier;
	for (auto i = 0; i < pr1.antalElementer(sizeOfArray) * 2;)
	{
		auto hour = pr1.times(sizeOfArray)[i];
		auto minut = pr1.times(sizeOfArray)[i + 1];
		i = i + 2;
		nyt_scenarier.addAction(hour, minut);
	}
	nyt_scenarier.setScenarieStreng(pr1.getSaveVector());
	scenarielist.push_back(nyt_scenarier);

}

void ScenarierList::AntalElementer() const
{
	std::cout << scenarielist.size() << std::endl;
}

void ScenarierList::AntalaktionerIScenarie(int nummer, char p) const
{
	scenarielist[nummer - 1].antalAktioner(p);

}

void ScenarierList::opretScenarie()
{
	std::vector<char> temp_vector;
	int antalKnytninger;
	temp_vector.push_back('!');
	std::cout << "hvor mange elementer ønsker du at knytte til alarmen?" << std::endl;
	std::cin >> antalKnytninger;
	
	for (auto i = 0; i < antalKnytninger; i++)
	{
		
		int hour,minut,hour1,hour2, minut1, minut2;
		std::cout << "Først timer på alarm element nr:" << i + 1 << std::endl;
		std::cin >> hour;		
		std::cout << "Så minutter på alarm element nr:" << i + 1 << std::endl;
		std::cin >> minut;
		if (hour > 0 && hour < 24 && minut > 0 && minut < 60)
		{
			hour1 = hour % 10;
			hour /= 10;
			hour2 = hour % 10;
			hour /= 10;
			minut1 = minut % 10;
			minut /= 10;
			minut2 = minut % 10;
			minut /= 10;
			temp_vector.push_back('N');
			temp_vector.push_back('H');
			temp_vector.push_back(hour2);
			temp_vector.push_back(hour1);
			temp_vector.push_back('M');
			temp_vector.push_back(minut2);
			temp_vector.push_back(minut1);
		}
		else
		{
			std::cout << "ikke godkendt format af tid" << std::endl;
			i--;
		}
		
	}
	temp_vector.push_back(' ');
	addScenarie(temp_vector);

}



std::vector<char> ScenarierList::etScenarie(int i)
{
	return scenarielist[i - 1].getScenarieStreng();
}


void ScenarierList::tilCharArray(char * a, int b)
{
	for (auto i = 0; i < etScenarie(b).size(); i++)
	{
		a[i] = etScenarie(b)[i];
	}
}

