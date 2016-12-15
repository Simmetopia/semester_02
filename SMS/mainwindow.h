#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "opretscenarie.h"
#include "ui_opretscenarie.h"
#include "opretscenarie.h"
#include "protocol.h"
#include "aktion.h"
#include "scenarier.h"
#include "scenarielist.h"
#include "enheder.h"
#include "additem.h"
#include <Qstring>
#include <string>
#include <QMessageBox>
#include <QLabel>
#include <QtSerialPort/QSerialPort>
#include <fstream>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:


    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void AddLabel(size_t);

    void skrivTilFil(std::string a, std::string b);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_sletAlarmKnap_clicked();

    void on_enhedsHaandtering_clicked();

    void initSerial();

    void initFileStreamFunktion();

    bool is_empty(std::ifstream& pfile);

    void savedData(std::string streng, std::string& navn ,int nrListe);

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
