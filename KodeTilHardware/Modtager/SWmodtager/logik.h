#pragma once
#include <vector>

class logik
{
  public:
  logik();  
  ~logik();
  void readToVectorModtager(std::vector<int> a);
  
  private:
  	std::vector<int> tidsBin;
};

