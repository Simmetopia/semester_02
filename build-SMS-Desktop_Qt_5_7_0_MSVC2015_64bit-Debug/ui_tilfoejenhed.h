/********************************************************************************
** Form generated from reading UI file 'tilfoejenhed.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TILFOEJENHED_H
#define UI_TILFOEJENHED_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_tilfoejEnhed
{
public:
    QLabel *label;
    QLineEdit *enhedsNavn;
    QDialogButtonBox *godkendEnhed;

    void setupUi(QDialog *tilfoejEnhed)
    {
        if (tilfoejEnhed->objectName().isEmpty())
            tilfoejEnhed->setObjectName(QStringLiteral("tilfoejEnhed"));
        tilfoejEnhed->resize(345, 147);
        label = new QLabel(tilfoejEnhed);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(120, 30, 131, 16));
        enhedsNavn = new QLineEdit(tilfoejEnhed);
        enhedsNavn->setObjectName(QStringLiteral("enhedsNavn"));
        enhedsNavn->setGeometry(QRect(102, 70, 151, 20));
        godkendEnhed = new QDialogButtonBox(tilfoejEnhed);
        godkendEnhed->setObjectName(QStringLiteral("godkendEnhed"));
        godkendEnhed->setGeometry(QRect(100, 110, 156, 23));
        godkendEnhed->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(tilfoejEnhed);
        QObject::connect(godkendEnhed, SIGNAL(accepted()), tilfoejEnhed, SLOT(accept()));
        QObject::connect(godkendEnhed, SIGNAL(rejected()), tilfoejEnhed, SLOT(reject()));

        QMetaObject::connectSlotsByName(tilfoejEnhed);
    } // setupUi

    void retranslateUi(QDialog *tilfoejEnhed)
    {
        tilfoejEnhed->setWindowTitle(QApplication::translate("tilfoejEnhed", "Dialog", 0));
        label->setText(QApplication::translate("tilfoejEnhed", "Indtast navn p\303\245 enhed", 0));
    } // retranslateUi

};

namespace Ui {
    class tilfoejEnhed: public Ui_tilfoejEnhed {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TILFOEJENHED_H
