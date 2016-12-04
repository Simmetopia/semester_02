#include "QDebug"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "opretscenarie.h"
#include "additem.h"
#include <iostream>
#include <conio.h>
#include "protocol.h"
#include "aktion.h"
#include "scenarier.h"
#include "scenarielist.h"
#include <QtSerialPort/QSerialPort>
#include <QMessageBox>
QSerialPort *serial;
ScenarierList scenlist;
using namespace std;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    serial = new QSerialPort(this);
    serial->setPortName("COM3");
    serial->open(QIODevice::ReadWrite);
    serial->setBaudRate(QSerialPort::Baud9600);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);


connect(serial, SIGNAL(error(QSerialPort::SerialPortError)), this, SLOT(SerialError(QSerialPort::SerialPortError)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    OpretScenarie op1;
    op1.setModal(true);
    op1.exec();
    qDebug() << op1.getTempVec();
    scenlist.addScenarie(op1.getTempVec(),"negerpak");

}

void MainWindow::on_pushButton_2_clicked()
{

        char test[200] = {};
        int scenToSend = ui->spinBox->value();
        qDebug() << "Størrelsen på vector er" << scenlist.AntalElementer();
        scenlist.tilCharArray(test,1);
        qDebug() << test;
        serial->write(test);

}


