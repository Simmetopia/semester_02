#ifndef ENHEDER_H
#define ENHEDER_H

#include <QDialog>
#include <vector>

namespace Ui {
class Enheder;
}

class Enheder : public QDialog
{
    Q_OBJECT

public:
    explicit Enheder(QWidget *parent = 0);
    ~Enheder();
    std::string getEnhed();
    void listEnhed();
    //void skrivTilFil(std::string a, int b);
    void initEnhedsFileStreamFunction();
    bool enheder_is_empty(std::ifstream& eFile);
    void savedEnheder(std::string);
    void addLabel(std::string);
    std::vector<std::string> getEnhedsVector();

    void skrivTilFil(std::string, int);

    void addUnit(std::string);

    void sletEnheder();


private slots:
    void on_tilfoejEnhedTilListe_clicked();

    void on_sletEnhed_clicked();



private:
    Ui::Enheder *ui;
    std::string temp_enhed;
    std::vector<std::string> enheds_vector;
};

#endif // ENHEDER_H
