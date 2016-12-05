#pragma once
#include "aktion.h"
#include <vector>
#include <string>

class Scenarier
{
public:
    Scenarier();
    ~Scenarier();
    void addAction(int& hour, int & minut);
    void antalAktioner(char p) const;
    size_t antalAktioner() const;
    std::vector<char> getScenarieStreng();
    void setScenarieStreng(std::vector<char> a);
    int getSize();
    void setNavn(std::string );
    std::string getNavn();
private:
    std::string navnPaaAktion;
    std::vector<Actions> aktioner;
    std::vector<char> scenariestreng;
};

