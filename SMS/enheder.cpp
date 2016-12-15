#include "enheder.h"
#include "ui_enheder.h"

#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QByteArray>
#include <QDebug>
#include <iostream>
#include <fstream>

Enheder::Enheder(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Enheder)
{

    ui->setupUi(this);
    initEnhedsFileStreamFunction();

}

Enheder::~Enheder()
{
    delete ui;
}
/*
void Enheder::on_addEnhed_clicked()
{
    tilfoejEnhed te1;
    te1.setModal(true);
    te1.exec();
}
*/

void Enheder::initEnhedsFileStreamFunction()
{
    std::ifstream checkEnheder("saved_enheder.txt", std::ios::in);

    int enhedNr;
    std::string name;
    if(enheder_is_empty(checkEnheder))
    {
        qDebug() << "jeg er forbi enhdeder";
        std::ofstream predefinedEnheder("saved_enheder.txt", std::ios::out | std::ios::in);
        predefinedEnheder << "Lysalarm" << " " << 0 << std::endl;
    }

    std::ifstream inEnheder("saved_enheder.txt", std::ios::in);
    while(inEnheder >> name >> enhedNr)
    {
        addUnit(name);
        addLabel(name);
    }

}

void Enheder::savedEnheder(std::string navn)
{
}

void Enheder::on_tilfoejEnhedTilListe_clicked()
{
    temp_enhed = ui->navnEnhed->text().toStdString();
    qDebug() << QString::fromStdString(temp_enhed);
    ui->listeAfEnheder->addItem(QString::fromStdString(temp_enhed));
    ui->navnEnhed->clear();

    addUnit(getEnhed());
    qDebug() << getEnhedsVector().size();
    skrivTilFil(getEnhedsVector()[getEnhedsVector().size() - 1], getEnhedsVector().size() - 1);
}

bool Enheder::enheder_is_empty(std::ifstream & eFile)
{
    return eFile.peek() == std::ifstream::traits_type::eof();
}


std::string Enheder::getEnhed()
{
    return temp_enhed;
}

void Enheder::addLabel(std::string name_)
{
    QString q1 = QString::fromStdString(name_);
    ui->listeAfEnheder->addItem(q1);
}

void Enheder::skrivTilFil(std::string a, int b)
{
    std::ofstream outEnhedFile("saved_enheder.txt", std::ios::out | std::ios::app);
    outEnhedFile << a << " " << b << std::endl;
    qDebug() << "Skrevet enhed til fil";
}

std::vector<std::string> Enheder::getEnhedsVector()
{
    return enheds_vector;
}

void Enheder::addUnit(std::string a)
{
    enheds_vector.push_back(a);
}

void Enheder::sletEnheder()
{
    QList<QListWidgetItem *> items = ui->listeAfEnheder->selectedItems();
    foreach(QListWidgetItem * item, items)
    {
        delete ui->listeAfEnheder->takeItem(ui->listeAfEnheder->row(item));
    }
}

void Enheder::on_sletEnhed_clicked()
{
    if(ui->listeAfEnheder->currentRow() == 0)
    {
        QMessageBox msg;
        msg.setText("IDIOT!");
        msg.exec();
    }
    else
    {
        sletEnheder();
    }
    std::ifstream readEnheder("saved_enheder.txt", std::ios::in);

    std::string enhedsNavn;
    int enhedsNummer;

    std::vector<std::string> updateEnhed;
    std::vector<int> updateNummer;

    while(readEnheder >> enhedsNavn >> enhedsNummer)
    {
        updateEnhed.push_back(enhedsNavn);
        updateNummer.push_back(enhedsNummer);
    }


    if(updateEnhed.size() == 1)
    {
        std::ofstream ofs;
        ofs.open("saved_enheder.txt", std::ios::out | std::ios::trunc);
        ofs.close();
    }
    else
    {
        std::ofstream ofs;
        ofs.open("saved_enheder.txt", std::ios::out | std::ios::trunc);
        ofs.close();

        updateEnhed.erase(updateEnhed.begin()+ui->listeAfEnheder->currentRow());


        for(int i = 0; i < updateEnhed.size(); i++)
        {
            skrivTilFil(updateEnhed[i], updateNummer[i]);
        }
    }

}
