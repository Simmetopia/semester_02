#include "Scenarier.h"
#include "aktion.h"
#include <iostream>
#include <QDebug>
#include <QString>

Scenarier::Scenarier()
{

}


Scenarier::~Scenarier()
{
}

void Scenarier::addAction(int& hour, int & minut)
{
    Actions ny_actions(hour, minut);
    aktioner.push_back(ny_actions);
    qDebug() << "Succes til scenarie";
}

void Scenarier::antalAktioner(char p) const
{
    std::cout << "Der er " << aktioner.size() << std::endl;
}

size_t Scenarier::antalAktioner() const
{
    return aktioner.size();
}

std::vector<char> Scenarier::getScenarieStreng()
{
    size_t i = scenariestreng.size();
    if (scenariestreng[i-1] == '\n')
    {
        return scenariestreng;
    }
    else
    {
        qDebug() << "EOF appended";
        scenariestreng.push_back('\n');
        return scenariestreng;
    }
}

void Scenarier::setScenarieStreng(std::vector<char> a)
{
    scenariestreng = a;
}

void Scenarier::setNavn(QString navn)
{
    navnPaaAktion = navn;
}

QString Scenarier::getNavn()
{
    return navnPaaAktion;
}
