#ifndef OPRETSCENARIE_H
#define OPRETSCENARIE_H
#include "opretscenarie.h"
#include "ui_opretscenarie.h"
#include "mainwindow.h"

namespace Ui {
class OpretScenarie;
}

class OpretScenarie : public QDialog
{
    Q_OBJECT

public:
    explicit OpretScenarie(QWidget *parent = 0);
    ~OpretScenarie();
    std::vector<char> getTempVec();
    QString getNavn();

private slots:
    void on_pushButton_clicked();

    void on_buttonBox_accepted();


private:
    Ui::OpretScenarie *ui;
    int alarmCounter = 0;
    std::vector<char> temp_vector;
    QString temp_navn;
};

#endif // OPRETSCENARIE_H


