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

void Scenarier::addAction(int& hour, int & minut) // denne kaldes i scenarie når der skal tilføjes en aktion til et scenarie objekt
{
    Actions ny_actions(hour, minut);

    aktioner.push_back(ny_actions);

    //qDebug() << "Succes til scenarie";    qDebug bliver brugt til at hjælpe med at isolere fejl
}

size_t Scenarier::antalAktioner() const
{
    return aktioner.size();
}

std::vector<char> Scenarier::getScenarieStreng() // Denne retunere en scenarie streng som kan bruges til at sende den serielt til X:10
{
    size_t i = scenariestreng.size(); // da vores arduino læser til \n var det nødvendigt at sikre den var på vectoren

    if (scenariestreng[i-1] == '\n')    // hvis den er der, så retuner bare strengen
    {
        return scenariestreng;
    }
    else                                // ellers push_back den, også retuner den.
    {
        qDebug() << "EOF appended";     // bruges til at se hvilke tilfælde det er nødvendigt med denne sikkerhed
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
