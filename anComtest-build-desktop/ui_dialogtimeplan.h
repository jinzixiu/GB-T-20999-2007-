/********************************************************************************
** Form generated from reading UI file 'dialogtimeplan.ui'
**
** Created: Sat Sep 13 18:15:00 2014
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGTIMEPLAN_H
#define UI_DIALOGTIMEPLAN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_DialogTimePlan
{
public:
    QFrame *line;
    QLabel *display;
    QPushButton *butquery;
    QPushButton *butset;
    QLabel *label_8;
    QSpinBox *spinplannum;
    QSpinBox *spintimelong;
    QLabel *hang;
    QLabel *label_5;
    QLabel *label_3;
    QLabel *label_2;
    QLabel *label_4;
    QSpinBox *spineverytabnum;
    QLabel *label;
    QPushButton *butclearall;
    QSpinBox *spinxietiao;
    QSpinBox *spinphasecha;
    QLabel *label_6;
    QPushButton *butclear;
    QLabel *label_7;
    QPushButton *butsend;

    void setupUi(QDialog *DialogTimePlan)
    {
        if (DialogTimePlan->objectName().isEmpty())
            DialogTimePlan->setObjectName(QString::fromUtf8("DialogTimePlan"));
        DialogTimePlan->resize(800, 450);
        line = new QFrame(DialogTimePlan);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(94, 266, 631, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        display = new QLabel(DialogTimePlan);
        display->setObjectName(QString::fromUtf8("display"));
        display->setGeometry(QRect(373, 340, 81, 21));
        butquery = new QPushButton(DialogTimePlan);
        butquery->setObjectName(QString::fromUtf8("butquery"));
        butquery->setGeometry(QRect(465, 286, 51, 41));
        butset = new QPushButton(DialogTimePlan);
        butset->setObjectName(QString::fromUtf8("butset"));
        butset->setGeometry(QRect(376, 380, 81, 31));
        butset->setStyleSheet(QString::fromUtf8("font: 12pt \"\351\273\221\344\275\223\";"));
        label_8 = new QLabel(DialogTimePlan);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(225, 289, 101, 31));
        label_8->setStyleSheet(QString::fromUtf8("font: 16pt \"\351\273\221\344\275\223\";"));
        spinplannum = new QSpinBox(DialogTimePlan);
        spinplannum->setObjectName(QString::fromUtf8("spinplannum"));
        spinplannum->setGeometry(QRect(250, 50, 91, 31));
        spinplannum->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));
        spinplannum->setMinimum(1);
        spinplannum->setMaximum(32);
        spintimelong = new QSpinBox(DialogTimePlan);
        spintimelong->setObjectName(QString::fromUtf8("spintimelong"));
        spintimelong->setGeometry(QRect(589, 50, 91, 31));
        spintimelong->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));
        spintimelong->setMaximum(255);
        hang = new QLabel(DialogTimePlan);
        hang->setObjectName(QString::fromUtf8("hang"));
        hang->setGeometry(QRect(345, 289, 91, 31));
        hang->setStyleSheet(QString::fromUtf8("font: 16pt \"\351\273\221\344\275\223\";"));
        label_5 = new QLabel(DialogTimePlan);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(128, 220, 191, 31));
        label_5->setStyleSheet(QString::fromUtf8("font: 16pt \"\351\273\221\344\275\223\";"));
        label_3 = new QLabel(DialogTimePlan);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(124, 145, 91, 31));
        label_3->setStyleSheet(QString::fromUtf8("font: 16pt \"\351\273\221\344\275\223\";"));
        label_2 = new QLabel(DialogTimePlan);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(459, 50, 91, 31));
        label_2->setStyleSheet(QString::fromUtf8("font: 16pt \"\351\273\221\344\275\223\";"));
        label_4 = new QLabel(DialogTimePlan);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(458, 125, 91, 31));
        label_4->setStyleSheet(QString::fromUtf8("font: 16pt \"\351\273\221\344\275\223\";"));
        spineverytabnum = new QSpinBox(DialogTimePlan);
        spineverytabnum->setObjectName(QString::fromUtf8("spineverytabnum"));
        spineverytabnum->setGeometry(QRect(350, 221, 91, 31));
        spineverytabnum->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));
        spineverytabnum->setMaximum(16);
        label = new QLabel(DialogTimePlan);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(123, 50, 71, 31));
        label->setStyleSheet(QString::fromUtf8("font: 16pt \"\351\273\221\344\275\223\";"));
        butclearall = new QPushButton(DialogTimePlan);
        butclearall->setObjectName(QString::fromUtf8("butclearall"));
        butclearall->setGeometry(QRect(545, 286, 51, 41));
        spinxietiao = new QSpinBox(DialogTimePlan);
        spinxietiao->setObjectName(QString::fromUtf8("spinxietiao"));
        spinxietiao->setGeometry(QRect(588, 125, 91, 31));
        spinxietiao->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));
        spinxietiao->setMaximum(16);
        spinphasecha = new QSpinBox(DialogTimePlan);
        spinphasecha->setObjectName(QString::fromUtf8("spinphasecha"));
        spinphasecha->setGeometry(QRect(250, 145, 91, 31));
        spinphasecha->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));
        spinphasecha->setMaximum(255);
        label_6 = new QLabel(DialogTimePlan);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(529, 225, 141, 21));
        label_6->setStyleSheet(QString::fromUtf8("font: 12pt \"\351\273\221\344\275\223\";"));
        butclear = new QPushButton(DialogTimePlan);
        butclear->setObjectName(QString::fromUtf8("butclear"));
        butclear->setGeometry(QRect(516, 380, 81, 31));
        butclear->setStyleSheet(QString::fromUtf8("font: 12pt \"\351\273\221\344\275\223\";"));
        label_7 = new QLabel(DialogTimePlan);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(450, 160, 251, 41));
        label_7->setStyleSheet(QString::fromUtf8("font: 12pt \"\351\273\221\344\275\223\";"));
        butsend = new QPushButton(DialogTimePlan);
        butsend->setObjectName(QString::fromUtf8("butsend"));
        butsend->setGeometry(QRect(230, 380, 81, 31));
        butsend->setStyleSheet(QString::fromUtf8("font: 12pt \"\351\273\221\344\275\223\";"));

        retranslateUi(DialogTimePlan);

        QMetaObject::connectSlotsByName(DialogTimePlan);
    } // setupUi

    void retranslateUi(QDialog *DialogTimePlan)
    {
        DialogTimePlan->setWindowTitle(QApplication::translate("DialogTimePlan", "\351\205\215\346\227\266\346\226\271\346\241\210", 0, QApplication::UnicodeUTF8));
        display->setText(QString());
        butquery->setText(QApplication::translate("DialogTimePlan", "\346\237\245\350\257\242\n"
"\345\267\262\350\256\276", 0, QApplication::UnicodeUTF8));
        butset->setText(QApplication::translate("DialogTimePlan", "\350\256\276 \347\275\256", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("DialogTimePlan", "\345\267\262\350\256\276\350\241\214\345\217\267:", 0, QApplication::UnicodeUTF8));
        hang->setText(QString());
        label_5->setText(QApplication::translate("DialogTimePlan", "\345\257\271\345\272\224\351\230\266\346\256\265\351\205\215\346\227\266\350\241\250\345\217\267", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("DialogTimePlan", "\347\233\270\344\275\215\345\267\256", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("DialogTimePlan", "\345\221\250\346\234\237\346\227\266\351\225\277", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("DialogTimePlan", "\345\215\217\350\260\203\347\233\270\344\275\215", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("DialogTimePlan", "\346\226\271\346\241\210\345\217\267", 0, QApplication::UnicodeUTF8));
        butclearall->setText(QApplication::translate("DialogTimePlan", "\346\270\205\347\251\272\n"
"\345\205\250\350\241\250", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("DialogTimePlan", "\342\200\2340\342\200\235\350\241\250\347\244\272\346\226\271\346\241\210\346\227\240\346\225\210", 0, QApplication::UnicodeUTF8));
        butclear->setText(QApplication::translate("DialogTimePlan", "\346\270\205\347\251\272\350\241\214", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("DialogTimePlan", "\342\200\2340\342\200\235\350\241\250\347\244\272\346\227\240\345\215\217\350\260\203\347\233\270\344\275\215\345\267\256\350\256\276\347\275\256\346\227\240\346\225\210", 0, QApplication::UnicodeUTF8));
        butsend->setText(QApplication::translate("DialogTimePlan", "\346\237\245 \350\257\242", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DialogTimePlan: public Ui_DialogTimePlan {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGTIMEPLAN_H
