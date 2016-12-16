#ifndef OPRETSCENARIE_H
#define OPRETSCENARIE_H
#include "opretscenarie.h"
#include "ui_opretscenarie.h"
#include "opretscenarie.h"
#include "protocol.h"
#include "aktion.h"
#include "scenarier.h"
#include "scenarielist.h"
#include "additem.h"
#include <Qstring>
#include <string>
#include <QMessageBox>
#include <QLabel>
#include <QtSerialPort/QSerialPort>
#include <QDialog>
#include <vector>

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
    std::string getNavn();

    void initLoadEnhedsListe();

private slots:
    void on_pushButton_clicked();

    void on_buttonBox_accepted();



private:
    Ui::OpretScenarie *ui;
    int alarmCounter = 0;
    std::vector<char> temp_vector;
    std::string temp_navn;
};

#endif // OPRETSCENARIE_H
