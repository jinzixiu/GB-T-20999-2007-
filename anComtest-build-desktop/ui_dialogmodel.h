/********************************************************************************
** Form generated from reading UI file 'dialogmodel.ui'
**
** Created: Sat Sep 13 18:15:00 2014
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGMODEL_H
#define UI_DIALOGMODEL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_DialogModel
{
public:
    QPushButton *butfind1;
    QLabel *display;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *butfind1_2;
    QPushButton *butfind1_3;
    QPushButton *butfind1_4;
    QLabel *jiedian;
    QLabel *zhizaoshang;
    QLabel *xinghao;
    QLabel *banben;

    void setupUi(QDialog *DialogModel)
    {
        if (DialogModel->objectName().isEmpty())
            DialogModel->setObjectName(QString::fromUtf8("DialogModel"));
        DialogModel->setWindowModality(Qt::NonModal);
        DialogModel->resize(800, 450);
        butfind1 = new QPushButton(DialogModel);
        butfind1->setObjectName(QString::fromUtf8("butfind1"));
        butfind1->setGeometry(QRect(160, 330, 101, 31));
        butfind1->setStyleSheet(QString::fromUtf8("font: 12pt \"\351\273\221\344\275\223\";"));
        display = new QLabel(DialogModel);
        display->setObjectName(QString::fromUtf8("display"));
        display->setGeometry(QRect(360, 299, 101, 21));
        label = new QLabel(DialogModel);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(70, 57, 121, 31));
        label->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));
        label_2 = new QLabel(DialogModel);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(70, 113, 121, 21));
        label_2->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));
        label_3 = new QLabel(DialogModel);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(70, 163, 121, 31));
        label_3->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));
        label_4 = new QLabel(DialogModel);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(70, 222, 121, 31));
        label_4->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));
        butfind1_2 = new QPushButton(DialogModel);
        butfind1_2->setObjectName(QString::fromUtf8("butfind1_2"));
        butfind1_2->setGeometry(QRect(288, 330, 101, 31));
        butfind1_2->setStyleSheet(QString::fromUtf8("font: 12pt \"\351\273\221\344\275\223\";"));
        butfind1_3 = new QPushButton(DialogModel);
        butfind1_3->setObjectName(QString::fromUtf8("butfind1_3"));
        butfind1_3->setGeometry(QRect(414, 330, 101, 31));
        butfind1_3->setStyleSheet(QString::fromUtf8("font: 12pt \"\351\273\221\344\275\223\";"));
        butfind1_4 = new QPushButton(DialogModel);
        butfind1_4->setObjectName(QString::fromUtf8("butfind1_4"));
        butfind1_4->setGeometry(QRect(540, 330, 101, 31));
        butfind1_4->setStyleSheet(QString::fromUtf8("font: 12pt \"\351\273\221\344\275\223\";"));
        jiedian = new QLabel(DialogModel);
        jiedian->setObjectName(QString::fromUtf8("jiedian"));
        jiedian->setGeometry(QRect(230, 58, 481, 31));
        jiedian->setStyleSheet(QString::fromUtf8("QLabel{     border-width: 1px;     border-style: solid;     border-color: rgb(255, 170, 0);}"));
        zhizaoshang = new QLabel(DialogModel);
        zhizaoshang->setObjectName(QString::fromUtf8("zhizaoshang"));
        zhizaoshang->setGeometry(QRect(230, 108, 481, 31));
        zhizaoshang->setStyleSheet(QString::fromUtf8("QLabel{     border-width: 1px;     border-style: solid;     border-color: rgb(255, 170, 0);}"));
        xinghao = new QLabel(DialogModel);
        xinghao->setObjectName(QString::fromUtf8("xinghao"));
        xinghao->setGeometry(QRect(230, 162, 481, 31));
        xinghao->setStyleSheet(QString::fromUtf8("QLabel{     border-width: 1px;     border-style: solid;     border-color: rgb(255, 170, 0);}"));
        banben = new QLabel(DialogModel);
        banben->setObjectName(QString::fromUtf8("banben"));
        banben->setGeometry(QRect(230, 220, 481, 31));
        banben->setStyleSheet(QString::fromUtf8("QLabel{     border-width: 1px;     border-style: solid;     border-color: rgb(255, 170, 0);}"));

        retranslateUi(DialogModel);

        QMetaObject::connectSlotsByName(DialogModel);
    } // setupUi

    void retranslateUi(QDialog *DialogModel)
    {
        DialogModel->setWindowTitle(QApplication::translate("DialogModel", "\346\250\241\345\235\227\350\241\250", 0, QApplication::UnicodeUTF8));
        butfind1->setText(QApplication::translate("DialogModel", "\346\237\245\350\257\242\344\270\273\346\216\247\346\234\272", 0, QApplication::UnicodeUTF8));
        display->setText(QString());
        label->setText(QApplication::translate("DialogModel", "\346\250\241\345\235\227\350\256\276\345\244\207\347\273\223\347\202\271", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("DialogModel", "\346\250\241\345\235\227\345\210\266\351\200\240\345\225\206", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("DialogModel", "\346\250\241\345\235\227\345\236\213\345\217\267", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("DialogModel", "\346\250\241\345\235\227\347\211\210\346\234\254", 0, QApplication::UnicodeUTF8));
        butfind1_2->setText(QApplication::translate("DialogModel", "\346\237\245\350\257\242\351\251\261\345\212\250\346\235\277", 0, QApplication::UnicodeUTF8));
        butfind1_3->setText(QApplication::translate("DialogModel", "\346\237\245\350\257\242\351\207\207\351\233\206\346\235\277", 0, QApplication::UnicodeUTF8));
        butfind1_4->setText(QApplication::translate("DialogModel", "\346\237\245\350\257\242\346\243\200\346\265\213\346\235\277", 0, QApplication::UnicodeUTF8));
        jiedian->setText(QString());
        zhizaoshang->setText(QString());
        xinghao->setText(QString());
        banben->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class DialogModel: public Ui_DialogModel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGMODEL_H
