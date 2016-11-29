#pragma once
#include "Scenarier.h"
#include <vector>
class ScenarierList
{
public:
	ScenarierList();
	~ScenarierList();
	void addScenarie(char* a);
	void addScenarie(std::vector<char> a);
	void AntalElementer() const;
	void AntalaktionerIScenarie(int , char ) const;
	void opretScenarie();
	char* tilCharArray(std::vector<char> a);
	std::vector<char> etScenarie(int);
private:
	std::vector<Scenarier> scenarielist;
};

