#include "opretscenarie.h"
#include "ui_opretscenarie.h"

OpretScenarie::OpretScenarie(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OpretScenarie)
{
    ui->setupUi(this);
}

OpretScenarie::~OpretScenarie()
{
    delete ui;
}

void OpretScenarie::on_spinBox_valueChanged(int arg1)
{
    timer_ = arg1;
}

void OpretScenarie::on_spinBox_2_valueChanged(int arg1)
{
    sekunder_ = arg1;
}

void OpretScenarie::on_spinBox_3_valueChanged(int arg1)
{
    minutter_ = arg1;
}

void OpretScenarie::on_buttonBox_accepted()
{

}
