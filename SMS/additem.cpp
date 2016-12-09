#include "additem.h"
#include "ui_additem.h"
#include "protocol.h"
#include "aktion.h"
#include "scenarier.h"
#include "scenarielist.h"

AddItem::AddItem(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddItem)
{
    ui->setupUi(this);
    ui->horizontalSlider->setRange(0,24);
    ui->horizontalSlider_2->setRange(0,60);
}

AddItem::~AddItem()
{
    delete ui;
}

void AddItem::on_buttonBox_accepted()
{
  timer_= (int)ui->lcdNumber->value();
  minutter_ = (int) ui->lcdNumber_2->value();
}

void AddItem::getTid(int& timer, int& minutter){

    timer = timer_;
    minutter = minutter_;
}
