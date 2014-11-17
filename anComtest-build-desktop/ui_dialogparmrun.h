/********************************************************************************
** Form generated from reading UI file 'dialogparmrun.ui'
**
** Created: Sat Sep 13 18:15:00 2014
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGPARMRUN_H
#define UI_DIALOGPARMRUN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_DialogParmRun
{
public:
    QLabel *display;
    QGroupBox *groupBox_3;
    QRadioButton *radiorun;
    QRadioButton *radionorun;
    QRadioButton *radionull;
    QPushButton *butfind;
    QPushButton *butok;

    void setupUi(QDialog *DialogParmRun)
    {
        if (DialogParmRun->objectName().isEmpty())
            DialogParmRun->setObjectName(QString::fromUtf8("DialogParmRun"));
        DialogParmRun->resize(800, 450);
        display = new QLabel(DialogParmRun);
        display->setObjectName(QString::fromUtf8("display"));
        display->setGeometry(QRect(350, 330, 101, 21));
        groupBox_3 = new QGroupBox(DialogParmRun);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(141, 93, 531, 191));
        groupBox_3->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));
        radiorun = new QRadioButton(groupBox_3);
        radiorun->setObjectName(QString::fromUtf8("radiorun"));
        radiorun->setGeometry(QRect(70, 88, 81, 21));
        radionorun = new QRadioButton(groupBox_3);
        radionorun->setObjectName(QString::fromUtf8("radionorun"));
        radionorun->setGeometry(QRect(220, 87, 81, 21));
        radionull = new QRadioButton(groupBox_3);
        radionull->setObjectName(QString::fromUtf8("radionull"));
        radionull->setGeometry(QRect(390, 87, 61, 21));
        butfind = new QPushButton(DialogParmRun);
        butfind->setObjectName(QString::fromUtf8("butfind"));
        butfind->setGeometry(QRect(250, 363, 81, 31));
        butfind->setStyleSheet(QString::fromUtf8("font: 12pt \"\351\273\221\344\275\223\";"));
        butok = new QPushButton(DialogParmRun);
        butok->setObjectName(QString::fromUtf8("butok"));
        butok->setGeometry(QRect(480, 363, 71, 31));
        butok->setStyleSheet(QString::fromUtf8("font: 12pt \"\351\273\221\344\275\223\";"));

        retranslateUi(DialogParmRun);

        QMetaObject::connectSlotsByName(DialogParmRun);
    } // setupUi

    void retranslateUi(QDialog *DialogParmRun)
    {
        DialogParmRun->setWindowTitle(QApplication::translate("DialogParmRun", "\345\217\202\346\225\260\350\277\220\350\241\214\345\274\200\345\205\263", 0, QApplication::UnicodeUTF8));
        display->setText(QString());
        groupBox_3->setTitle(QApplication::translate("DialogParmRun", "\345\217\202\346\225\260\350\277\220\350\241\214\345\274\200\345\205\263", 0, QApplication::UnicodeUTF8));
        radiorun->setText(QApplication::translate("DialogParmRun", "\350\277\220\350\241\214", 0, QApplication::UnicodeUTF8));
        radionorun->setText(QApplication::translate("DialogParmRun", "\344\270\215\350\277\220\350\241\214", 0, QApplication::UnicodeUTF8));
        radionull->setText(QApplication::translate("DialogParmRun", "\346\234\252\350\256\276", 0, QApplication::UnicodeUTF8));
        butfind->setText(QApplication::translate("DialogParmRun", "\346\237\245 \350\257\242", 0, QApplication::UnicodeUTF8));
        butok->setText(QApplication::translate("DialogParmRun", "\344\277\256 \346\224\271", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DialogParmRun: public Ui_DialogParmRun {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGPARMRUN_H
