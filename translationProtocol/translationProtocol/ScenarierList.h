#pragma once
#include "Scenarier.h"
#include <vector>
class ScenarierList
{
public:
	ScenarierList();
	~ScenarierList();
	void addScenarie(char* a);
	void AntalElementer() const;
	void AntalaktionerIScenarie(int ) const;
private:
	std::vector<Scenarier> scenarielist;
};

