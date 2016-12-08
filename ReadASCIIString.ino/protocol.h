#pragma once
#include <cstdlib>
#include <vector>
#include <string>
#include "Scenarier.h"

class protocol
{
public:
	protocol();
	~protocol();
	void readToVector(char *x, int size);
	void readToVector(std::vector<char>);
 void readToVector(std::string a);
	void printSavedVector() const;
	int antalElementer(int size);
	void makeRawTime(int& size);	
	void printTimes(std::vector<int> a) const;
	std::vector<int> times(int & size);
	void pushBack(char a);
	char* toString(Scenarier scen);
	char charIntConverter(int a);
	std::vector<char> getSaveVector();
  int protocolLogic();
  void resetSaveVector(std::vector<char>);

	

private:
	std::vector<char> SaveVector;
	std::vector<int> RawtimeVec;
};

