#include "tilfoejenhed.h"
#include "ui_tilfoejenhed.h"
tilfoejEnhed::tilfoejEnhed(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::tilfoejEnhed)
{
    ui->setupUi(this);
}

tilfoejEnhed::~tilfoejEnhed()
{
    delete ui;
}

void tilfoejEnhed::on_godkendEnhed_accepted()
{
    temp_Enhed = ui->enhedsNavn->text().toStdString();
}

std::string tilfoejEnhed::getEnhed()
{
    return temp_Enhed;
}
