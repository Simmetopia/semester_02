#ifndef ADDITEM_H
#define ADDITEM_H

#include <QDialog>

namespace Ui {
class AddItem;
}

class AddItem : public QDialog
{
    Q_OBJECT

public:
    explicit AddItem(QWidget *parent = 0);
    ~AddItem();
    void getTid(int&,int&);

private slots:
    void on_buttonBox_accepted();

private:
    Ui::AddItem *ui;
    int timer_,minutter_;
};

#endif // ADDITEM_H
