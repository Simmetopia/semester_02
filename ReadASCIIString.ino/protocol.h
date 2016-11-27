#pragma once
#include <vector>

class protocol
{
public:
	protocol();
	~protocol();
	void readToVector(char *x, int size);
	void printSavedVector() const;
	void testScenario() const;
  int protocolLogic() ;

private:
	std::vector<char> SaveVector;
};

