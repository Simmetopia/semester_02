/********************************************************************************
** Form generated from reading UI file 'opretscenarie.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPRETSCENARIE_H
#define UI_OPRETSCENARIE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OpretScenarie
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton;
    QListWidget *EnhedsList;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *ScenStreng;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QLabel *timer;
    QLabel *label_3;
    QLabel *minutter;

    void setupUi(QDialog *OpretScenarie)
    {
        if (OpretScenarie->objectName().isEmpty())
            OpretScenarie->setObjectName(QStringLiteral("OpretScenarie"));
        OpretScenarie->resize(400, 300);
        OpretScenarie->setStyleSheet(QLatin1String("QMainWindow{\n"
"\n"
"background-color:#1d1d1d\n"
"\n"
"}\n"
"QMenuBar{\n"
"background-color: #1d1d1d;\n"
"padding:5px;\n"
"font: 12pt \"MS Shell Dlg 2\";\n"
"color:#fff;\n"
"\n"
"}\n"
"\n"
"QMenu{\n"
"color: #fff;\n"
"padding: 0px;\n"
"background-color:#1d1d1d;\n"
"}\n"
"\n"
"QMenu::item:selected{\n"
"color: black;\n"
"background-color:white;\n"
"}\n"
"\n"
"QStatusBar{\n"
"background-color:#7e3878;\n"
"color:#fff;\n"
"}\n"
"\n"
"QPushButton{\n"
"border-style:solid;\n"
"background-color:#3d3d3d;\n"
"color:#fff;\n"
"border-radius:7px;\n"
"\n"
"}\n"
"\n"
"QLabel{\n"
"color: fff;\n"
"	font-weight: bold;\n"
"font-size: 12 pt;\n"
"}"));
        buttonBox = new QDialogButtonBox(OpretScenarie);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        layoutWidget = new QWidget(OpretScenarie);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(11, 12, 307, 166));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_3->addWidget(pushButton);

        EnhedsList = new QListWidget(layoutWidget);
        EnhedsList->setObjectName(QStringLiteral("EnhedsList"));

        horizontalLayout_3->addWidget(EnhedsList);


        verticalLayout_2->addLayout(horizontalLayout_3);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        ScenStreng = new QLineEdit(layoutWidget);
        ScenStreng->setObjectName(QStringLiteral("ScenStreng"));

        horizontalLayout_2->addWidget(ScenStreng);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(71, 0));

        horizontalLayout->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        timer = new QLabel(layoutWidget);
        timer->setObjectName(QStringLiteral("timer"));

        horizontalLayout->addWidget(timer);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout->addWidget(label_3);

        minutter = new QLabel(layoutWidget);
        minutter->setObjectName(QStringLiteral("minutter"));

        horizontalLayout->addWidget(minutter);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(OpretScenarie);
        QObject::connect(buttonBox, SIGNAL(accepted()), OpretScenarie, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), OpretScenarie, SLOT(reject()));

        QMetaObject::connectSlotsByName(OpretScenarie);
    } // setupUi

    void retranslateUi(QDialog *OpretScenarie)
    {
        OpretScenarie->setWindowTitle(QApplication::translate("OpretScenarie", "Dialog", 0));
        pushButton->setText(QApplication::translate("OpretScenarie", "Tilf\303\270j tid til element:", 0));
        label_2->setText(QApplication::translate("OpretScenarie", "Alarm Navn:", 0));
        label->setText(QApplication::translate("OpretScenarie", "Alarm sat til:", 0));
        timer->setText(QApplication::translate("OpretScenarie", "0", 0));
        label_3->setText(QApplication::translate("OpretScenarie", ":", 0));
        minutter->setText(QApplication::translate("OpretScenarie", "0", 0));
    } // retranslateUi

};

namespace Ui {
    class OpretScenarie: public Ui_OpretScenarie {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPRETSCENARIE_H
