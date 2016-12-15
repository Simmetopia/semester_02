#include "enhedsnavn.h"
#include "ui_enhedsnavn.h"

enhedsNavn::enhedsNavn(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::enhedsNavn)
{
    ui->setupUi(this);
}

enhedsNavn::~enhedsNavn()
{
    delete ui;
}
