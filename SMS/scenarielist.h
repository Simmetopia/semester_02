<<<<<<< HEAD
#pragma once
#include "Scenarier.h"
#include <vector>
class ScenarierList
{
public:
    ScenarierList();
    ~ScenarierList();
    void addScenarie(char* a);
   void addScenarie(std::vector<char> a, QString b);
    int AntalElementer() const;
    void AntalaktionerIScenarie(int , char ) const;
    void opretScenarie();
    Scenarier getScenarie(int);
    void tilCharArray(char* a,int b);
    std::vector<char> etScenarie(int);
    size_t getSize();
    void sletScenarie(int);
    void addScenarie(std::string a,std::string);
private:
    std::vector<Scenarier> scenarielist;
};

=======
#pragma once
#include "Scenarier.h"
#include <vector>
class ScenarierList
{
public:
    ScenarierList();
    ~ScenarierList();
    void addScenarie(char* a);
   void addScenarie(std::vector<char> a, QString b);
    int AntalElementer() const;
    void AntalaktionerIScenarie(int , char ) const;
    void opretScenarie();
    Scenarier getScenarie(int);
    void tilCharArray(char* a,int b);
    std::vector<char> etScenarie(int);
    size_t getSize();
    void sletScenarie(int);
    void addScenarie(std::string a,std::string);
private:
    std::vector<Scenarier> scenarielist;
};

>>>>>>> master
