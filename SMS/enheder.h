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
    void skrivTilFil(std::string a, int b);
    std::vector<char> getEnhedsVector();


private slots:
    void on_tilfoejEnhedTilListe_clicked();
    bool enheder_is_empty(std::ifstream& eFile);



private:
    Ui::Enheder *ui;
    std::string temp_enhed;
    std::vector<char> enheds_vector;
};

#endif // ENHEDER_H
