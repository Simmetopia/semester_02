#pragma once
#include <vector>

class logik
{
  public:
  logik();  
  ~logik();
  void readToVectorModtager(std::vector<int>);
  int binaryConverter();
  
  private:
  	std::vector<int> tidsBin;
};

