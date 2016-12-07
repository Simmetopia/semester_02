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
#include <QFile>
#include <QTextStream>

QSerialPort *serial;
ScenarierList scenlist;
using namespace std;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    initSerial();
    fileStreamFunktion();




connect(serial, SIGNAL(error(QSerialPort::SerialPortError)), this, SLOT(SerialError(QSerialPort::SerialPortError)));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::fileStreamFunktion(){

    QFile file("scenarier.txt");
    if(file.open(QIODevice::ReadWrite|QIODevice::Append) ){
        if(file.pos()==0){

            char a[] = "!NH13M30NH13M20\n" ;
            scenlist.addScenarie(a);
            QString q1 = "HardCoded Scenarie";
            ui->listWidget->addItem(q1);
            QTextStream stream(&file);
            stream << a;

        }else
        {
            QTextStream stream(&file);
            while(!file.atEnd() )
            {
                qDebug() << "jeg er någet hertil";
               QString temp_= file.readLine();
               char * b;
               QByteArray ba;
               ba=temp_.toLatin1();
               b = ba.data();

                QString q1 = "HardCoded Scenarie";
                scenlist.addScenarie(b);

                ui->listWidget->addItem(q1);
            }
        }

    }


}



void MainWindow::on_pushButton_clicked()
{
    OpretScenarie op1;
    op1.setModal(true);
    op1.exec();
    qDebug() << op1.getTempVec();
    scenlist.addScenarie(op1.getTempVec(),op1.getNavn());
    qDebug() << op1.getNavn();
    AddLabel(scenlist.AntalElementer());

}

void MainWindow::on_pushButton_2_clicked()
{


        size_t scenToSend = ui->spinBox->value();
        char test[200] = {};
        scenlist.tilCharArray(test,scenToSend);
        qDebug() << test;
        serial->write(test,scenlist.etScenarie(scenToSend).size());
        serial->write("\n");


}

void MainWindow::AddLabel(size_t i)
{
   QString q1 = scenlist.getScenarie(i).getNavn();
    ui->listWidget->addItem(q1);
}

void MainWindow::on_sletAlarmKnap_clicked()
{
    scenlist.sletScenarie(ui->spinBox_2->value());
    QListWidgetItem* item = ui->listWidget->takeItem(ui->spinBox_2->value()-1);
    delete item;
}
void MainWindow::initSerial(){

    serial = new QSerialPort(this);
    serial->setPortName("COM5");
    serial->open(QIODevice::ReadWrite);
    serial->setBaudRate(QSerialPort::Baud9600);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);
}
