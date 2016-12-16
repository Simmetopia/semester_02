/********************************************************************************
** Form generated from reading UI file 'enheder.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENHEDER_H
#define UI_ENHEDER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Enheder
{
public:
    QListWidget *listeAfEnheder;
    QDialogButtonBox *godkend;
    QLabel *label;
    QLineEdit *navnEnhed;
    QPushButton *tilfoejEnhedTilListe;
    QPushButton *sletEnhed;

    void setupUi(QDialog *Enheder)
    {
        if (Enheder->objectName().isEmpty())
            Enheder->setObjectName(QStringLiteral("Enheder"));
        Enheder->resize(400, 300);
        listeAfEnheder = new QListWidget(Enheder);
        listeAfEnheder->setObjectName(QStringLiteral("listeAfEnheder"));
        listeAfEnheder->setGeometry(QRect(220, 30, 141, 201));
        godkend = new QDialogButtonBox(Enheder);
        godkend->setObjectName(QStringLiteral("godkend"));
        godkend->setGeometry(QRect(210, 250, 156, 23));
        godkend->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(Enheder);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 80, 121, 20));
        navnEnhed = new QLineEdit(Enheder);
        navnEnhed->setObjectName(QStringLiteral("navnEnhed"));
        navnEnhed->setGeometry(QRect(30, 110, 141, 20));
        tilfoejEnhedTilListe = new QPushButton(Enheder);
        tilfoejEnhedTilListe->setObjectName(QStringLiteral("tilfoejEnhedTilListe"));
        tilfoejEnhedTilListe->setGeometry(QRect(50, 150, 111, 23));
        sletEnhed = new QPushButton(Enheder);
        sletEnhed->setObjectName(QStringLiteral("sletEnhed"));
        sletEnhed->setGeometry(QRect(50, 190, 111, 23));

        retranslateUi(Enheder);
        QObject::connect(godkend, SIGNAL(accepted()), Enheder, SLOT(accept()));
        QObject::connect(godkend, SIGNAL(rejected()), Enheder, SLOT(reject()));

        QMetaObject::connectSlotsByName(Enheder);
    } // setupUi

    void retranslateUi(QDialog *Enheder)
    {
        Enheder->setWindowTitle(QApplication::translate("Enheder", "Dialog", 0));
        label->setText(QApplication::translate("Enheder", "Angiv navn til enhed", 0));
        tilfoejEnhedTilListe->setText(QApplication::translate("Enheder", "Tilf\303\270j enhed til liste", 0));
        sletEnhed->setText(QApplication::translate("Enheder", "Slet Enhed", 0));
    } // retranslateUi

};

namespace Ui {
    class Enheder: public Ui_Enheder {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENHEDER_H
