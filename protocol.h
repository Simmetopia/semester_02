#pragma once
#include <cstdlib>
#include <vector>

class protocol
{
public:
	protocol();
	~protocol();
	void readToVector(char *x, int size);
	void printSavedVector() const;
	void testScenario() const;

private:
	std::vector<char> SaveVector;
};

