#include "QDebug"
#include <fstream>
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
#include <QByteArray>

QSerialPort *serial;
ScenarierList scenlist;
using namespace std;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    initSerial();
    initFileStreamFunktion();
    ui->spinBox->setMinimum(1);
    ui->spinBox_2->setMinimum(1);
    ui->spinBox->setMaximum(scenlist.getSize());
    ui->spinBox_2->setMaximum(scenlist.getSize());
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::initFileStreamFunktion(){


   ifstream checkAlarm( "saved_data_alarmet.txt", ios::in );
   int nummerListe = 1;
   string name,streng;

    if(is_empty(checkAlarm) ) // tjekker om filen er tom eller ikke
    {
        qDebug() << "jeg er forbi her ";
        ofstream outAlarmFile( "saved_data_alarmet.txt", ios::out | ios::in);
        outAlarmFile << "!NH07M00NH07M30" << " " << "Predefineret_Scenarie" << endl; // lægger vores prediferenet scenarie ind hvis den ér tom
    }

        ifstream InAlarmFile("saved_data_alarmet.txt");
        while(InAlarmFile >> streng >> name  )
        {
            savedData(streng,name,nummerListe);
            nummerListe++;
        } // end while



}//end init file

void MainWindow::savedData(string streng,string& navn ,int nrListe){

    scenlist.addScenarie(streng,navn);
    scenlist.getScenarie(nrListe).setNavn(QString::fromStdString(navn));
    AddLabel(nrListe);
}



bool MainWindow::is_empty(ifstream& pFile)
{
    return pFile.peek() == std::ifstream::traits_type::eof();
}


void MainWindow::on_pushButton_clicked()
{
    OpretScenarie op1;
    op1.setModal(true);
    op1.exec();
    qDebug() << op1.getTempVec();
    scenlist.addScenarie(op1.getTempVec(),QString::fromStdString(op1.getNavn()));
    AddLabel(scenlist.AntalElementer());
    skrivTilFil(std::string(op1.getTempVec().data(),op1.getTempVec().size()),op1.getNavn());
    ui->spinBox->setMaximum(scenlist.getSize());
    ui->spinBox_2->setMaximum(scenlist.getSize());


}
void MainWindow::skrivTilFil(string a, string b){

    ofstream outAlarmFile("saved_data_alarmet.txt",ios::out|ios::app);

    outAlarmFile << a << " " << b << endl;
    qDebug() << "baam så der skrevt mere til filen";
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
    ifstream readData("saved_data_alarmet.txt" , ios::in);
    vector<string> a;
    vector<string> b;
    int c = 0;
    string streng,name;
    while(readData >> streng >> name  )
    {
        a.push_back(streng); b.push_back(name);
        c++;
    } // end while

    qDebug() << ui->spinBox_2->value()-1;

    if(a.size() == 1){
        ofstream ofs;
        ofs.open("saved_data_alarmet.txt", ios::out|ios::trunc);
        ofs.close();
    }
    else
    {
        ofstream ofs;
        ofs.open("saved_data_alarmet.txt", ios::out|ios::trunc);
        ofs.close();

        a.erase(a.begin()+ui->spinBox_2->value()-1);
        b.erase(b.begin()+ui->spinBox_2->value()-1);
        qDebug() << "Størrelse på c er:" <<c ;
        for(int i = 0; i < c-1 ;i++)
        {
            qDebug() << " Jeg kan sagtens skrive til filen" << i << "gange";
            skrivTilFil(a[i],b[i]);
        }
    }
    ui->spinBox->setMaximum(scenlist.getSize());
    ui->spinBox_2->setMaximum(scenlist.getSize());



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
