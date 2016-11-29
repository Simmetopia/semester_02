#pragma once
#include "Actions.h"
#include <vector>

class Scenarier
{
public:
	Scenarier();
	~Scenarier();
	void addAction(int& hour, int & minut);
	void antalAktioner() const;
private:
	std::vector<Actions> aktioner;
};

