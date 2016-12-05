#include "opretscenarie.h"
#include "ui_opretscenarie.h"
#include "opretscenarie.h"
#include "protocol.h"
#include "aktion.h"
#include "scenarier.h"
#include "scenarielist.h"
#include "additem.h"
#include <Qstring>
#include <string>
#include <QMessageBox>
#include <QLabel>
#include <QDebug>
#include <vector>
using namespace std;


OpretScenarie::OpretScenarie(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OpretScenarie)
{
    ui->setupUi(this);
    temp_vector.push_back('!');

}

OpretScenarie::~OpretScenarie()
{
    delete ui;
}

void OpretScenarie::on_pushButton_clicked()
{
        AddItem ad1;
        ad1.setModal(true);
        ad1.exec();

              int hour,minut,hour1,hour2, minut1, minut2;
              ad1.getTid(hour,minut);
              int hour3= hour;
              int minut3 = minut;
              ui->timer->setNum(hour3) ;
              ui->minutter->setNum(minut3);



                hour1 = hour % 10;
                hour /= 10;
                hour2 = hour % 10;
                hour /= 10;
                minut1 = minut % 10;
                minut /= 10;
                minut2 = minut % 10;
                minut /= 10;
                temp_vector.push_back('N');
                temp_vector.push_back('H');
                temp_vector.push_back(hour2+'0');
                temp_vector.push_back(hour1+'0');
                temp_vector.push_back('M');
                temp_vector.push_back(minut2+'0');
                temp_vector.push_back(minut1+'0');


}
void OpretScenarie::on_buttonBox_accepted()
{
    temp_navn = ui->ScenStreng->text();
}

vector<char> OpretScenarie::getTempVec(){
    return temp_vector;
}
QString OpretScenarie::getNavn(){
    return temp_navn;
}
