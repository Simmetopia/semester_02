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
    protocol pr1;
    pr1.readToVector(a, sizeOfArray);
    Scenarier nyt_scenarier;
    for (auto i = 0; i < pr1.antalElementer(sizeOfArray) * 2 ;)
    {
        auto hour = pr1.times(sizeOfArray)[i];
        auto minut = pr1.times(sizeOfArray)[i+1];
        i = i + 2;
        nyt_scenarier.addAction(hour, minut);
    }
    nyt_scenarier.setScenarieStreng(pr1.getSaveVector());
    scenarielist.push_back(nyt_scenarier);


}
void ScenarierList::addScenarie(std::string a, std::string b)
{
    int sizeOfArray = a.size();
    protocol pr1;
    pr1.readToVector(a);
    Scenarier nyt_scenarier;
    for (auto i = 0; i < pr1.antalElementer(sizeOfArray) * 2 ;)
    {
        auto hour = pr1.times(sizeOfArray)[i];
        auto minut = pr1.times(sizeOfArray)[i+1];
        i = i + 2;
        nyt_scenarier.addAction(hour, minut);
    }
    nyt_scenarier.setScenarieStreng(pr1.getSaveVector());
    nyt_scenarier.setNavn(QString::fromStdString(b));
    scenarielist.push_back(nyt_scenarier);


}

void ScenarierList::addScenarie(std::vector<char> a, QString b)
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
        qDebug() << "Aktion tilføjet";
    }
    nyt_scenarier.setScenarieStreng(pr1.getSaveVector());
    scenarielist.push_back(nyt_scenarier);
    qDebug() << "Succes" ;
    qDebug() << "Størrelse på vectoer er nu" << AntalElementer();


}

int ScenarierList::AntalElementer() const
{
    return scenarielist.size();
}

void ScenarierList::AntalaktionerIScenarie(int nummer, char p) const
{
    scenarielist[nummer - 1].antalAktioner(p);

}
size_t ScenarierList::getSize()
{
    return scenarielist.size();
}




std::vector<char> ScenarierList::etScenarie(int i)
{
    return scenarielist[i - 1].getScenarieStreng();
}


void ScenarierList::tilCharArray(char * a, int b)
{
    qDebug() << "størrelse på et scenarie" << etScenarie(b).size();

    for (auto i = 0; i < etScenarie(b).size(); i++)
    {
        a[i] = etScenarie(b)[i];
    }
}

Scenarier ScenarierList::getScenarie(int i)
{
    return scenarielist[i - 1];
}

void ScenarierList::sletScenarie(int nr){
    scenarielist.erase(scenarielist.begin()+nr-1);

}



