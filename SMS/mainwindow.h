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
#include "additem.h"
#include <Qstring>
#include <string>
#include <QMessageBox>
#include <QLabel>
#include <QtSerialPort/QSerialPort>

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

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
