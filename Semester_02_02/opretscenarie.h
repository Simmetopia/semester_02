#ifndef OPRETSCENARIE_H
#define OPRETSCENARIE_H

#include <QDialog>
#include <QString>

namespace Ui {
class OpretScenarie;
}

class OpretScenarie : public QDialog
{
    Q_OBJECT

public:
    explicit OpretScenarie(QWidget *parent = 0);
    ~OpretScenarie();

private slots:

    void on_spinBox_valueChanged(int arg1);

    void on_spinBox_2_valueChanged(int arg1);

    void on_spinBox_3_valueChanged(int arg1);

    void on_buttonBox_accepted();

private:
    Ui::OpretScenarie *ui;
    int timer_,minutter_,sekunder_;
};

#endif // OPRETSCENARIE_H
