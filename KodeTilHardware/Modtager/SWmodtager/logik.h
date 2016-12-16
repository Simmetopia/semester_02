#pragma once
#include <vector>

class logik
{
  public:
  logik();  
  ~logik();
  void readToVectorModtager(std::vector<int>);
  int binaryConverter();
  void clearVec();
  std::vector<int> getVector();
  
  private:
  	std::vector<int> tidsBin;
};

