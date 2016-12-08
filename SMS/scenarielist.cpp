#include "scenarielist.h"
#include "scenarier.h"
#include "protocol.h"
#include <iostream>
#include <vector>
#include <QDebug>


ScenarierList::ScenarierList()
{
}


ScenarierList::~ScenarierList()
{
}

void ScenarierList::addScenarie(char* a)
{
    int sizeOfArray = strlen(a);

    protocol pr1;                           // opretter et protocol objekt
    pr1.readToVector(a, sizeOfArray);

    Scenarier nyt_scenarier;                // opretter et Scenarie objekt

    for (auto i = 0; i < pr1.antalElementer(sizeOfArray) * 2 ;) // denne læser minutter og sekunder ind og tilføjer en aktion til scenariet.
    {
        auto hour = pr1.times(sizeOfArray)[i];
        auto minut = pr1.times(sizeOfArray)[i+1];
        i = i + 2;
        nyt_scenarier.addAction(hour, minut);
    } // end for

    nyt_scenarier.setScenarieStreng(pr1.getSaveVector());   // her gemmer vi en streng som en vector i selve scenariet til senere brug

    scenarielist.push_back(nyt_scenarier);  // denne ligger så scenariet i slutningen på vores vector<Scenarier> så vi har adgang til alt information gennem denne klasse


}

void ScenarierList::addScenarie(std::vector<char> a, QString b) // denne har samme funktionalitet som ovenstående, denne tager bare en vektor i stedet for et char array
{
    int sizeOfArray = a.size();
    protocol pr1;

    pr1.readToVector(a);
    Scenarier nyt_scenarier;

    nyt_scenarier.setNavn(b);

    for (auto i = 0; i < pr1.antalElementer(sizeOfArray) * 2;)
    {
        auto hour = pr1.times(sizeOfArray)[i];
        auto minut = pr1.times(sizeOfArray)[i + 1];

        i = i + 2;
        nyt_scenarier.addAction(hour, minut);
    }
    nyt_scenarier.setScenarieStreng(pr1.getSaveVector());

    scenarielist.push_back(nyt_scenarier);

}

int ScenarierList::AntalElementer() const
{
    return scenarielist.size();
}


std::vector<char> ScenarierList::etScenarie(int i) // denne funktion retunere den scenarie streng som skal sendes til vores X:10
{
    return scenarielist[i - 1].getScenarieStreng();
}


void ScenarierList::tilCharArray(char * a, int b)   // denne tager en vector og gemmer den i et char array som så kan sendes serielt
{
    qDebug() << "størrelse på et scenarie" << etScenarie(b).size();

    for (auto i = 0; i < etScenarie(b).size(); i++)
    {
        a[i] = etScenarie(b)[i];
    }
}

Scenarier ScenarierList::getScenarie(int i) // retunere det i'te Scenarie fra listen
{
    return scenarielist[i-1];
}

void ScenarierList::sletScenarie(int nr){
    scenarielist.erase(scenarielist.begin()+nr-1);

}
