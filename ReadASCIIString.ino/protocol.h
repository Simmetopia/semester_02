#pragma once
#include <cstdlib>
#include <vector>
#include <string>

class protocol
{
public:
	protocol();
	~protocol();
	void readToVector(char *x, int size);
	void readToVector(std::vector<char>);
 	void readToVector(std::string a);
	void printSavedVector() const;
	int  antalElementer();
	void makeRawTime(int& size);	
	void printTimes(std::vector<int> a) const;
	std::vector<int> times(int & size);
	void pushBack(char a);
	char charIntConverter(int a);
	std::vector<char> getSaveVector();
	
  int protocolLogic();
  void resetSaveVector(std::vector<char>);

  //Christians logic filer
  std::vector<int> ConvertToBinary();
  int alarmTid(int);

  std::string bitConverter();

	

private:
	std::vector<char> SaveVector;
	std::vector<int> RawtimeVec;
	int alarm1=0,alarm2=0,alarm3=0;
};

