#pragma once
#include <cstdlib>
#include <vector>
#include "Scenarier.h"
#include <string>

class protocol
{
public:
    protocol();
    ~protocol();
    void readToVector(char *x, int size);
    void readToVector(std::vector<char>);
    void printSavedVector() const;
    int antalElementer(int& size);
    void makeRawTime(int& size);
    void printTimes(std::vector<int> a) const;
    std::vector<int> times(int & size);
    void pushBack(char a);
    char* toString(Scenarier scen);
    char charIntConverter(int a);
    std::vector<char> getSaveVector();
    void readToVector(std::string a);



private:
    std::vector<char> SaveVector;
    std::vector<int> RawtimeVec;
};
