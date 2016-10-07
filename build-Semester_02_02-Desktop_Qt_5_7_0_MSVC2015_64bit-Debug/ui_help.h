/********************************************************************************
** Form generated from reading UI file 'help.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELP_H
#define UI_HELP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_Help
{
public:
    QTextBrowser *textBrowser;

    void setupUi(QDialog *Help)
    {
        if (Help->objectName().isEmpty())
            Help->setObjectName(QStringLiteral("Help"));
        Help->resize(400, 300);
        textBrowser = new QTextBrowser(Help);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(0, 0, 401, 301));

        retranslateUi(Help);

        QMetaObject::connectSlotsByName(Help);
    } // setupUi

    void retranslateUi(QDialog *Help)
    {
        Help->setWindowTitle(QApplication::translate("Help", "Dialog", 0));
        textBrowser->setHtml(QApplication::translate("Help", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"justify\" style=\" margin-top:12px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; background-color:#ffffff;\"><span style=\" font-family:'arial,helvetica,sans-serif'; font-size:8pt; color:#000000; background-color:#ffffff;\">Lorem ipsum dolor sit amet, varius non magna, arcu praesent. Eros urna at. Amet posuere. Wisi sit, wisi morbi arcu cursus morbi posuere, fames lobortis amet suscipit ut, aptent sapien pulvinar congue. Ac suscipit mus, placerat feugiat, nec morbi nonummy laoreet tellus amet. Dis nec morbi nunc, porta purus pede. Pretium nec dignissim faucibus, sagittis neque ipsum lobortis interdum, aenean turpis. "
                        "Pulvinar euismod ultrices purus ac, venenatis elit, amet proin nunc justo magna, torquent suspendisse primis, hendrerit ut tempor libero massa. Vel et wisi vestibulum nibh, tincidunt vitae. Nonummy in imperdiet aenean quis fusce ligula, quis velit nunc sit enim pellentesque dolor, eros interdum aliquet ornare suspendisse integer ligula. Ut a odio ante suspendisse in neque, mollis elit lectus nullam ut lacinia, rutrum enim, massa porttitor gravida, lectus erat rutrum. Quam bibendum amet enim pede at.</span></p>\n"
"<p align=\"justify\" style=\" margin-top:12px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; background-color:#ffffff;\"><span style=\" font-family:'arial,helvetica,sans-serif'; font-size:8pt; color:#000000; background-color:#ffffff;\">Tortor odio amet aut elit pretium, feugiat vitae magna, nisl rhoncus purus ac, id nibh quis sed, odio odio tincidunt leo wisi nulla. Id accumsan convallis erat, elit velit ante varius. Nec sollicitudin diam, suscipit viverra"
                        ", amet venenatis sodales. Consectetuer vivamus in. Mi maecenas condimentum, in consectetuer ac mauris justo tristique, iaculis sed. Eget tellus viverra aliquet elit, dictumst risus maecenas vel, mi libero phasellus class dui velit lectus.</span></p>\n"
"<p align=\"justify\" style=\" margin-top:12px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; background-color:#ffffff;\"><span style=\" font-family:'arial,helvetica,sans-serif'; font-size:8pt; color:#000000; background-color:#ffffff;\">Vitae suspendisse arcu faucibus ullamcorper sed eget, inceptos ligula donec sodales dolor integer fames. Suscipit integer sed, neque elit, lorem vitae tincidunt tellus cursus lectus, integer non turpis feugiat, leo erat lectus tempor dolor dictum dui. Et eu arcu eget mattis tempus, volutpat etiam eu habitant volutpat nisl ipsum. Ut accumsan risus turpis, orci mattis neque ipsum magna cum, varius purus nonummy turpis bibendum tincidunt consequat, lorem non. Adipiscing dolor massa sapien"
                        " lacus aliquam, purus nisl purus molestie mauris, suscipit sodales lacus architecto et risus sem, pede facilisis, mauris velit pellentesque vivamus nullam ultrices.</span></p>\n"
"<p align=\"justify\" style=\" margin-top:12px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; background-color:#ffffff;\"><span style=\" font-family:'arial,helvetica,sans-serif'; font-size:8pt; color:#000000; background-color:#ffffff;\">Tempor nisl pellentesque purus. Pellentesque dui, tincidunt dui lorem fusce, ante velit suscipit eleifend. Lacus lobortis nibh leo pellentesque, sapien pulvinar justo, purus eget wisi sit vivamus vitae. Vitae officiis. Risus massa, etiam lacinia orci volutpat sit, consequat habitant aenean vivamus, massa quam leo maecenas in. Mauris consequat lorem vestibulum bibendum urna, laoreet ipsum sapien, turpis non suscipit mollis faucibus ut aliquam. Phasellus phasellus fames ornare consequat mauris, massa sit sit amet aliquam, in ut urna quis at nascetur, massa at "
                        "lectus varius fringilla et, et elementum nunc.</span></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class Help: public Ui_Help {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELP_H
