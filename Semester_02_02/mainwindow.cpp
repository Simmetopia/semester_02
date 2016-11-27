#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "help.h"
#include "opretscenarie.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    alarmCount = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionHelp_triggered()
{
    Help h1;
    h1.setModal(true);
    h1.exec();
}


void MainWindow::on_alarm1_clicked()
{
    if(alarmCount == 0){
        ui->label->setText("Alarm 1 aktiveret");
        alarmCount = 1;
    }
}

void MainWindow::on_pushButton_clicked()
{
    OpretScenarie os;
    os.setModal(true);
    os.exec();
}
