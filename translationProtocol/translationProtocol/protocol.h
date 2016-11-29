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
	int antalElementer(int& size);
	void makeRawTime(int& size);
	int charToInt(char a);
	void printTimes(std::vector<int> a) const;
	std::vector<int> times(int & size);
	

private:
	std::vector<char> SaveVector;
	std::vector<int> RawtimeVec;
};

