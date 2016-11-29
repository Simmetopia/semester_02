#pragma once
#include "Actions.h"
#include <vector>

class Scenarier
{
public:
	Scenarier(int& antalscenarier);
	Scenarier();
	~Scenarier();
	void addAction(Actions&);
	void antalAktioner() const;
private:
	std::vector<Actions> aktioner;
};

