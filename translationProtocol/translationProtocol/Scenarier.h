#pragma once
#include "Actions.h"
#include <vector>

class Scenarier
{
public:
	Scenarier();
	~Scenarier();
	void addAction(int& hour, int & minut);
	void antalAktioner(char p) const;
	int antalAktioner() const;
	std::vector<char> getScenarieStreng();
	void setScenarieStreng(std::vector<char> a);
	int getSize();
private:
	std::vector<Actions> aktioner;
	std::vector<char> scenariestreng;
};

