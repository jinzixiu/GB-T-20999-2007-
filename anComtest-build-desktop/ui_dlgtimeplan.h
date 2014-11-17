/********************************************************************************
** Form generated from reading UI file 'dlgtimeplan.ui'
**
** Created: Tue Sep 2 17:31:13 2014
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGTIMEPLAN_H
#define UI_DLGTIMEPLAN_H

#include <QtCore/QVariant>
#include <QtDeclarative/QDeclarativeView>
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

class Ui_DlgTimePlan
{
public:
    QLabel *label;
    QLabel *label_4;
    QLabel *label_6;
    QLabel *label_5;
    QSpinBox *spinphasecha;
    QSpinBox *spintimelong;
    QLabel *hang;
    QSpinBox *spinplannum;
    QSpinBox *spineverytabnum;
    QSpinBox *spinxietiao;
    QLabel *label_7;
    QPushButton *butclearall;
    QLabel *label_2;
    QFrame *line;
    QPushButton *butquery;
    QLabel *label_8;
    QPushButton *butfind;
    QPushButton *butset;
    QPushButton *butclear;
    QLabel *display;
    QLabel *label_3;
    QDeclarativeView *declarativeView;

    void setupUi(QDialog *DlgTimePlan)
    {
        if (DlgTimePlan->objectName().isEmpty())
            DlgTimePlan->setObjectName(QString::fromUtf8("DlgTimePlan"));
        DlgTimePlan->resize(800, 450);
        label = new QLabel(DlgTimePlan);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(154, 40, 71, 31));
        label->setStyleSheet(QString::fromUtf8("font: 16pt \"\351\273\221\344\275\223\";"));
        label_4 = new QLabel(DlgTimePlan);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(423, 120, 91, 31));
        label_4->setStyleSheet(QString::fromUtf8("font: 16pt \"\351\273\221\344\275\223\";"));
        label_6 = new QLabel(DlgTimePlan);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(511, 223, 141, 21));
        label_6->setStyleSheet(QString::fromUtf8("font: 12pt \"\351\273\221\344\275\223\";"));
        label_5 = new QLabel(DlgTimePlan);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(139, 219, 191, 31));
        label_5->setStyleSheet(QString::fromUtf8("font: 16pt \"\351\273\221\344\275\223\";"));
        spinphasecha = new QSpinBox(DlgTimePlan);
        spinphasecha->setObjectName(QString::fromUtf8("spinphasecha"));
        spinphasecha->setGeometry(QRect(281, 140, 91, 31));
        spinphasecha->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));
        spinphasecha->setMaximum(255);
        spintimelong = new QSpinBox(DlgTimePlan);
        spintimelong->setObjectName(QString::fromUtf8("spintimelong"));
        spintimelong->setGeometry(QRect(554, 40, 91, 31));
        spintimelong->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));
        spintimelong->setMaximum(255);
        hang = new QLabel(DlgTimePlan);
        hang->setObjectName(QString::fromUtf8("hang"));
        hang->setGeometry(QRect(339, 283, 91, 31));
        hang->setStyleSheet(QString::fromUtf8("font: 16pt \"\351\273\221\344\275\223\";"));
        spinplannum = new QSpinBox(DlgTimePlan);
        spinplannum->setObjectName(QString::fromUtf8("spinplannum"));
        spinplannum->setGeometry(QRect(284, 40, 91, 31));
        spinplannum->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));
        spinplannum->setMinimum(1);
        spinplannum->setMaximum(32);
        spineverytabnum = new QSpinBox(DlgTimePlan);
        spineverytabnum->setObjectName(QString::fromUtf8("spineverytabnum"));
        spineverytabnum->setGeometry(QRect(361, 215, 91, 31));
        spineverytabnum->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));
        spineverytabnum->setMaximum(16);
        spinxietiao = new QSpinBox(DlgTimePlan);
        spinxietiao->setObjectName(QString::fromUtf8("spinxietiao"));
        spinxietiao->setGeometry(QRect(553, 120, 91, 31));
        spinxietiao->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));
        spinxietiao->setMaximum(16);
        label_7 = new QLabel(DlgTimePlan);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(415, 155, 251, 41));
        label_7->setStyleSheet(QString::fromUtf8("font: 12pt \"\351\273\221\344\275\223\";"));
        butclearall = new QPushButton(DlgTimePlan);
        butclearall->setObjectName(QString::fromUtf8("butclearall"));
        butclearall->setGeometry(QRect(539, 280, 51, 41));
        label_2 = new QLabel(DlgTimePlan);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(424, 40, 91, 31));
        label_2->setStyleSheet(QString::fromUtf8("font: 16pt \"\351\273\221\344\275\223\";"));
        line = new QFrame(DlgTimePlan);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(88, 264, 631, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        butquery = new QPushButton(DlgTimePlan);
        butquery->setObjectName(QString::fromUtf8("butquery"));
        butquery->setGeometry(QRect(459, 280, 51, 41));
        label_8 = new QLabel(DlgTimePlan);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(219, 283, 101, 31));
        label_8->setStyleSheet(QString::fromUtf8("font: 16pt \"\351\273\221\344\275\223\";"));
        butfind = new QPushButton(DlgTimePlan);
        butfind->setObjectName(QString::fromUtf8("butfind"));
        butfind->setGeometry(QRect(230, 380, 75, 23));
        butset = new QPushButton(DlgTimePlan);
        butset->setObjectName(QString::fromUtf8("butset"));
        butset->setGeometry(QRect(370, 380, 75, 23));
        butclear = new QPushButton(DlgTimePlan);
        butclear->setObjectName(QString::fromUtf8("butclear"));
        butclear->setGeometry(QRect(510, 380, 75, 23));
        display = new QLabel(DlgTimePlan);
        display->setObjectName(QString::fromUtf8("display"));
        display->setGeometry(QRect(367, 340, 81, 21));
        label_3 = new QLabel(DlgTimePlan);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(155, 140, 91, 31));
        label_3->setStyleSheet(QString::fromUtf8("font: 16pt \"\351\273\221\344\275\223\";"));
        declarativeView = new QDeclarativeView(DlgTimePlan);
        declarativeView->setObjectName(QString::fromUtf8("declarativeView"));
        declarativeView->setGeometry(QRect(140, 440, 300, 200));

        retranslateUi(DlgTimePlan);

        QMetaObject::connectSlotsByName(DlgTimePlan);
    } // setupUi

    void retranslateUi(QDialog *DlgTimePlan)
    {
        DlgTimePlan->setWindowTitle(QApplication::translate("DlgTimePlan", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("DlgTimePlan", "\346\226\271\346\241\210\345\217\267", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("DlgTimePlan", "\345\215\217\350\260\203\347\233\270\344\275\215", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("DlgTimePlan", "\342\200\2340\342\200\235\350\241\250\347\244\272\346\226\271\346\241\210\346\227\240\346\225\210", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("DlgTimePlan", "\345\257\271\345\272\224\351\230\266\346\256\265\351\205\215\346\227\266\350\241\250\345\217\267", 0, QApplication::UnicodeUTF8));
        hang->setText(QString());
        label_7->setText(QApplication::translate("DlgTimePlan", "\342\200\2340\342\200\235\350\241\250\347\244\272\346\227\240\345\215\217\350\260\203\347\233\270\344\275\215\345\267\256\350\256\276\347\275\256\346\227\240\346\225\210", 0, QApplication::UnicodeUTF8));
        butclearall->setText(QApplication::translate("DlgTimePlan", "\346\270\205\347\251\272\n"
"\345\205\250\350\241\250", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("DlgTimePlan", "\345\221\250\346\234\237\346\227\266\351\225\277", 0, QApplication::UnicodeUTF8));
        butquery->setText(QApplication::translate("DlgTimePlan", "\346\270\205\347\251\272\n"
"\345\205\250\350\241\250", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("DlgTimePlan", "\345\267\262\350\256\276\350\241\214\345\217\267:", 0, QApplication::UnicodeUTF8));
        butfind->setText(QApplication::translate("DlgTimePlan", "\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
        butset->setText(QApplication::translate("DlgTimePlan", "\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        butclear->setText(QApplication::translate("DlgTimePlan", "\346\270\205\347\251\272\350\241\214", 0, QApplication::UnicodeUTF8));
        display->setText(QString());
        label_3->setText(QApplication::translate("DlgTimePlan", "\347\233\270\344\275\215\345\267\256", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DlgTimePlan: public Ui_DlgTimePlan {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGTIMEPLAN_H
