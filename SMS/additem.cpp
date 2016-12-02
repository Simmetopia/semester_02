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
}

AddItem::~AddItem()
{
    delete ui;
}

void AddItem::on_buttonBox_accepted()
{
  timer_=ui->spinBox->value();
  minutter_ = ui ->spinBox_2->value();
}

void AddItem::getTid(int& timer, int& minutter){

    timer = timer_;
    minutter = minutter_;
}
