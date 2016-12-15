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

void Enheder::on_tilfoejEnhedTilListe_clicked()
{
    temp_enhed = ui->navnEnhed->text().toStdString();

    skrivTilFil(temp_enhed, 1);
    ui->listeAfEnheder->addItem(QString::fromStdString(temp_enhed));
    ui->navnEnhed->clear();
}

std::string Enheder::getEnhed()
{
    return temp_enhed;
}

void Enheder::skrivTilFil(std::string a, int b)
{
    std::ofstream outEnhedFile("saved_enheder.txt", std::ios::out | std::ios::app);
    outEnhedFile << a << " " << b << std::endl;
    qDebug() << "Skrevet enhed til fil";
}

bool Enheder::enheder_is_empty(std::ifstream & eFile)
{
    return eFile.peek() == std::ifstream::traits_type::eof();
}

std::vector<char> Enheder::getEnhedsVector()
{
    return enheds_vector;
}



