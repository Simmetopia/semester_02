#ifndef TILFOEJENHED_H
#define TILFOEJENHED_H

#include <QDialog>

namespace Ui {
class tilfoejEnhed;
}

class tilfoejEnhed : public QDialog
{
    Q_OBJECT

public:
    explicit tilfoejEnhed(QWidget *parent = 0);
    ~tilfoejEnhed();
    std::string getEnhed();

private slots:
    void on_godkendEnhed_accepted();

private:
    Ui::tilfoejEnhed *ui;
    std::string temp_Enhed;
};

#endif // TILFOEJENHED_H
