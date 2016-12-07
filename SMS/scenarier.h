#pragma once
#include "aktion.h"
#include <vector>
#include <string>
#include <QString>

class Scenarier
{
public:
    Scenarier();
    ~Scenarier();
    void addAction(int& hour, int & minut);
    size_t antalAktioner() const;
    std::vector<char> getScenarieStreng();
    void setScenarieStreng(std::vector<char> a);
    int getSize();
    void setNavn(QString );
    QString getNavn();
private:
    QString navnPaaAktion;
    std::vector<Actions> aktioner;
    std::vector<char> scenariestreng;
};

