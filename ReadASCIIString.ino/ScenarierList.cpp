#include "ScenarierList.h"
#include "Scenarier.h"
#include "protocol.h"
#include <vector>
#include <string>


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
void ScenarierList::addScenarie(std::string a)
{
  int sizeOfArray = a.size();
  protocol pr1;
  pr1.readToVector(a);
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


void ScenarierList::AntalaktionerIScenarie(int nummer, char p) const
{
	scenarielist[nummer - 1].antalAktioner(p);

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

