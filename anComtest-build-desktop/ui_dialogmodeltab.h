/********************************************************************************
** Form generated from reading UI file 'dialogmodeltab.ui'
**
** Created: Thu Sep 4 15:22:00 2014
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGMODELTAB_H
#define UI_DIALOGMODELTAB_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_DialogModelTab
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *jiedian;
    QLabel *zhizaoshang;
    QLabel *xinghao;
    QLabel *banben;
    QLabel *leixing;
    QPushButton *butfind;
    QPushButton *butfind2;
    QPushButton *butfind3;
    QPushButton *butfind4;
    QLabel *display;

    void setupUi(QDialog *DialogModelTab)
    {
        if (DialogModelTab->objectName().isEmpty())
            DialogModelTab->setObjectName(QString::fromUtf8("DialogModelTab"));
        DialogModelTab->resize(800, 450);
        label = new QLabel(DialogModelTab);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(80, 93, 120, 19));
        label->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));
        label_2 = new QLabel(DialogModelTab);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(80, 140, 100, 19));
        label_2->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));
        label_3 = new QLabel(DialogModelTab);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(80, 187, 80, 19));
        label_3->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));
        label_4 = new QLabel(DialogModelTab);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(80, 235, 80, 19));
        label_4->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));
        label_5 = new QLabel(DialogModelTab);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(80, 282, 80, 19));
        label_5->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));
        jiedian = new QLabel(DialogModelTab);
        jiedian->setObjectName(QString::fromUtf8("jiedian"));
        jiedian->setGeometry(QRect(260, 87, 461, 31));
        jiedian->setStyleSheet(QString::fromUtf8("QLabel{     border-width: 1px;     border-style: solid;     border-color: rgb(255, 170, 0);}"));
        zhizaoshang = new QLabel(DialogModelTab);
        zhizaoshang->setObjectName(QString::fromUtf8("zhizaoshang"));
        zhizaoshang->setGeometry(QRect(260, 134, 461, 31));
        zhizaoshang->setStyleSheet(QString::fromUtf8("QLabel{     border-width: 1px;     border-style: solid;     border-color: rgb(255, 170, 0);}"));
        xinghao = new QLabel(DialogModelTab);
        xinghao->setObjectName(QString::fromUtf8("xinghao"));
        xinghao->setGeometry(QRect(260, 181, 461, 31));
        xinghao->setStyleSheet(QString::fromUtf8("QLabel{     border-width: 1px;     border-style: solid;     border-color: rgb(255, 170, 0);}"));
        banben = new QLabel(DialogModelTab);
        banben->setObjectName(QString::fromUtf8("banben"));
        banben->setGeometry(QRect(260, 230, 461, 31));
        banben->setStyleSheet(QString::fromUtf8("QLabel{     border-width: 1px;     border-style: solid;     border-color: rgb(255, 170, 0);}"));
        leixing = new QLabel(DialogModelTab);
        leixing->setObjectName(QString::fromUtf8("leixing"));
        leixing->setGeometry(QRect(260, 275, 461, 31));
        leixing->setStyleSheet(QString::fromUtf8("QLabel{     border-width: 1px;     border-style: solid;     border-color: rgb(255, 170, 0);}"));
        butfind = new QPushButton(DialogModelTab);
        butfind->setObjectName(QString::fromUtf8("butfind"));
        butfind->setGeometry(QRect(170, 360, 91, 31));
        butfind2 = new QPushButton(DialogModelTab);
        butfind2->setObjectName(QString::fromUtf8("butfind2"));
        butfind2->setGeometry(QRect(290, 360, 91, 31));
        butfind3 = new QPushButton(DialogModelTab);
        butfind3->setObjectName(QString::fromUtf8("butfind3"));
        butfind3->setGeometry(QRect(410, 360, 91, 31));
        butfind4 = new QPushButton(DialogModelTab);
        butfind4->setObjectName(QString::fromUtf8("butfind4"));
        butfind4->setGeometry(QRect(530, 360, 91, 31));
        display = new QLabel(DialogModelTab);
        display->setObjectName(QString::fromUtf8("display"));
        display->setGeometry(QRect(360, 320, 81, 31));

        retranslateUi(DialogModelTab);

        QMetaObject::connectSlotsByName(DialogModelTab);
    } // setupUi

    void retranslateUi(QDialog *DialogModelTab)
    {
        DialogModelTab->setWindowTitle(QApplication::translate("DialogModelTab", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("DialogModelTab", "\346\250\241\345\235\227\350\256\276\345\244\207\347\273\223\347\202\271", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("DialogModelTab", "\346\250\241\345\235\227\345\210\266\351\200\240\345\225\206", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("DialogModelTab", "\346\250\241\345\235\227\345\236\213\345\217\267", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("DialogModelTab", "\346\250\241\345\235\227\347\211\210\346\234\254", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("DialogModelTab", "\346\250\241\345\235\227\347\261\273\345\236\213", 0, QApplication::UnicodeUTF8));
        jiedian->setText(QString());
        zhizaoshang->setText(QString());
        xinghao->setText(QString());
        banben->setText(QString());
        leixing->setText(QString());
        butfind->setText(QApplication::translate("DialogModelTab", "\346\237\245\347\234\213\346\250\241\345\235\227\350\241\250\350\241\2141", 0, QApplication::UnicodeUTF8));
        butfind2->setText(QApplication::translate("DialogModelTab", "\346\237\245\347\234\213\346\250\241\345\235\227\350\241\250\350\241\2142", 0, QApplication::UnicodeUTF8));
        butfind3->setText(QApplication::translate("DialogModelTab", "\346\237\245\347\234\213\346\250\241\345\235\227\350\241\250\350\241\2143", 0, QApplication::UnicodeUTF8));
        butfind4->setText(QApplication::translate("DialogModelTab", "\346\237\245\347\234\213\346\250\241\345\235\227\350\241\250\350\241\2144", 0, QApplication::UnicodeUTF8));
        display->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class DialogModelTab: public Ui_DialogModelTab {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGMODELTAB_H
