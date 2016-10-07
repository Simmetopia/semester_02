/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionHelp;
    QWidget *centralWidget;
    QPushButton *alarm1;
    QPushButton *alarm2;
    QPushButton *alarm3;
    QLabel *label;
    QPushButton *reset;
    QMenuBar *menuBar;
    QMenu *menuHelp;
    QMenu *menuFile;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(400, 300);
        MainWindow->setStyleSheet(QLatin1String("QMainWindow{\n"
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
        actionHelp = new QAction(MainWindow);
        actionHelp->setObjectName(QStringLiteral("actionHelp"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        alarm1 = new QPushButton(centralWidget);
        alarm1->setObjectName(QStringLiteral("alarm1"));
        alarm1->setGeometry(QRect(20, 170, 71, 31));
        alarm2 = new QPushButton(centralWidget);
        alarm2->setObjectName(QStringLiteral("alarm2"));
        alarm2->setGeometry(QRect(100, 170, 71, 31));
        alarm3 = new QPushButton(centralWidget);
        alarm3->setObjectName(QStringLiteral("alarm3"));
        alarm3->setGeometry(QRect(180, 170, 71, 31));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 70, 201, 31));
        label->setStyleSheet(QLatin1String("color: fff;\n"
"font-size: 250%;\n"
" font-weight: bold;\n"
" "));
        reset = new QPushButton(centralWidget);
        reset->setObjectName(QStringLiteral("reset"));
        reset->setGeometry(QRect(260, 170, 71, 31));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 35));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuHelp->addAction(actionHelp);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionHelp->setText(QApplication::translate("MainWindow", "About", 0));
        alarm1->setText(QApplication::translate("MainWindow", "Set alarm 1", 0));
        alarm2->setText(QApplication::translate("MainWindow", "Set alarm 2", 0));
        alarm3->setText(QApplication::translate("MainWindow", "Set alarm 3", 0));
        label->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:600; color:#dedede;\">Alle Alarmer deaktiveret</span></p></body></html>", 0));
        reset->setText(QApplication::translate("MainWindow", "Reset", 0));
        menuHelp->setTitle(QApplication::translate("MainWindow", "About", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
