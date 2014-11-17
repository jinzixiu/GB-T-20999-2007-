/********************************************************************************
** Form generated from reading UI file 'dlgtimeinterval.ui'
**
** Created: Sat Sep 13 18:15:00 2014
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGTIMEINTERVAL_H
#define UI_DLGTIMEINTERVAL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_DlgTimeInterval
{
public:
    QSpinBox *spintimingnum;
    QLabel *label_7;
    QLabel *hang;
    QSpinBox *spintimetab;
    QSpinBox *spinstarthour;
    QLabel *label_4;
    QGroupBox *groupBox;
    QRadioButton *radionum8;
    QRadioButton *radionum13;
    QRadioButton *radionum11;
    QRadioButton *radionum12;
    QRadioButton *radionum0;
    QRadioButton *radionum3;
    QRadioButton *radionum1;
    QRadioButton *radionum6;
    QRadioButton *radionum2;
    QRadioButton *radioButton;
    QLabel *label_2;
    QFrame *line;
    QLabel *label;
    QPushButton *clearall;
    QLabel *label_6;
    QSpinBox *spineventnum;
    QLabel *label_8;
    QLabel *label_3;
    QSpinBox *spinstartminite;
    QPushButton *query;
    QFrame *line_2;
    QLabel *display;
    QPushButton *butfind;
    QPushButton *butok;
    QPushButton *butclear;

    void setupUi(QDialog *DlgTimeInterval)
    {
        if (DlgTimeInterval->objectName().isEmpty())
            DlgTimeInterval->setObjectName(QString::fromUtf8("DlgTimeInterval"));
        DlgTimeInterval->resize(800, 450);
        spintimingnum = new QSpinBox(DlgTimeInterval);
        spintimingnum->setObjectName(QString::fromUtf8("spintimingnum"));
        spintimingnum->setGeometry(QRect(200, 230, 91, 31));
        spintimingnum->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));
        spintimingnum->setMinimum(0);
        spintimingnum->setMaximum(255);
        label_7 = new QLabel(DlgTimeInterval);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(312, 237, 441, 16));
        label_7->setStyleSheet(QString::fromUtf8("font: 9pt \"Agency FB\";"));
        hang = new QLabel(DlgTimeInterval);
        hang->setObjectName(QString::fromUtf8("hang"));
        hang->setGeometry(QRect(335, 290, 71, 31));
        hang->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));
        spintimetab = new QSpinBox(DlgTimeInterval);
        spintimetab->setObjectName(QString::fromUtf8("spintimetab"));
        spintimetab->setGeometry(QRect(230, 20, 91, 31));
        spintimetab->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));
        spintimetab->setMinimum(1);
        spintimetab->setMaximum(16);
        spinstarthour = new QSpinBox(DlgTimeInterval);
        spinstarthour->setObjectName(QString::fromUtf8("spinstarthour"));
        spinstarthour->setGeometry(QRect(289, 79, 91, 31));
        spinstarthour->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));
        spinstarthour->setMaximum(23);
        label_4 = new QLabel(DlgTimeInterval);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(400, 80, 211, 31));
        label_4->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));
        groupBox = new QGroupBox(DlgTimeInterval);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(70, 120, 671, 101));
        groupBox->setStyleSheet(QString::fromUtf8("font: 12pt \"\351\273\221\344\275\223\";"));
        radionum8 = new QRadioButton(groupBox);
        radionum8->setObjectName(QString::fromUtf8("radionum8"));
        radionum8->setGeometry(QRect(100, 60, 111, 20));
        radionum13 = new QRadioButton(groupBox);
        radionum13->setObjectName(QString::fromUtf8("radionum13"));
        radionum13->setGeometry(QRect(454, 60, 114, 20));
        radionum11 = new QRadioButton(groupBox);
        radionum11->setObjectName(QString::fromUtf8("radionum11"));
        radionum11->setGeometry(QRect(216, 60, 114, 20));
        radionum12 = new QRadioButton(groupBox);
        radionum12->setObjectName(QString::fromUtf8("radionum12"));
        radionum12->setGeometry(QRect(335, 60, 114, 20));
        radionum0 = new QRadioButton(groupBox);
        radionum0->setObjectName(QString::fromUtf8("radionum0"));
        radionum0->setGeometry(QRect(100, 27, 91, 20));
        radionum3 = new QRadioButton(groupBox);
        radionum3->setObjectName(QString::fromUtf8("radionum3"));
        radionum3->setGeometry(QRect(364, 27, 79, 20));
        radionum1 = new QRadioButton(groupBox);
        radionum1->setObjectName(QString::fromUtf8("radionum1"));
        radionum1->setGeometry(QRect(196, 27, 79, 20));
        radionum6 = new QRadioButton(groupBox);
        radionum6->setObjectName(QString::fromUtf8("radionum6"));
        radionum6->setGeometry(QRect(448, 27, 79, 20));
        radionum2 = new QRadioButton(groupBox);
        radionum2->setObjectName(QString::fromUtf8("radionum2"));
        radionum2->setGeometry(QRect(280, 27, 79, 20));
        radioButton = new QRadioButton(groupBox);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(532, 27, 89, 21));
        label_2 = new QLabel(DlgTimeInterval);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(470, 20, 101, 31));
        label_2->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));
        line = new QFrame(DlgTimeInterval);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(60, 61, 681, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        label = new QLabel(DlgTimeInterval);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(130, 20, 101, 31));
        label->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));
        clearall = new QPushButton(DlgTimeInterval);
        clearall->setObjectName(QString::fromUtf8("clearall"));
        clearall->setGeometry(QRect(544, 284, 51, 41));
        label_6 = new QLabel(DlgTimeInterval);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(80, 230, 121, 31));
        label_6->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));
        spineventnum = new QSpinBox(DlgTimeInterval);
        spineventnum->setObjectName(QString::fromUtf8("spineventnum"));
        spineventnum->setGeometry(QRect(590, 20, 91, 31));
        spineventnum->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));
        spineventnum->setMinimum(1);
        spineventnum->setMaximum(48);
        label_8 = new QLabel(DlgTimeInterval);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(180, 290, 121, 31));
        label_8->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));
        label_3 = new QLabel(DlgTimeInterval);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(79, 79, 211, 31));
        label_3->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));
        spinstartminite = new QSpinBox(DlgTimeInterval);
        spinstartminite->setObjectName(QString::fromUtf8("spinstartminite"));
        spinstartminite->setGeometry(QRect(610, 79, 91, 31));
        spinstartminite->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));
        spinstartminite->setMaximum(59);
        query = new QPushButton(DlgTimeInterval);
        query->setObjectName(QString::fromUtf8("query"));
        query->setGeometry(QRect(463, 284, 51, 41));
        line_2 = new QFrame(DlgTimeInterval);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(60, 271, 681, 16));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        display = new QLabel(DlgTimeInterval);
        display->setObjectName(QString::fromUtf8("display"));
        display->setGeometry(QRect(342, 336, 131, 31));
        butfind = new QPushButton(DlgTimeInterval);
        butfind->setObjectName(QString::fromUtf8("butfind"));
        butfind->setGeometry(QRect(240, 377, 81, 31));
        butfind->setStyleSheet(QString::fromUtf8("font: 12pt \"\351\273\221\344\275\223\";"));
        butok = new QPushButton(DlgTimeInterval);
        butok->setObjectName(QString::fromUtf8("butok"));
        butok->setGeometry(QRect(370, 377, 81, 31));
        butok->setStyleSheet(QString::fromUtf8("font: 12pt \"\351\273\221\344\275\223\";"));
        butclear = new QPushButton(DlgTimeInterval);
        butclear->setObjectName(QString::fromUtf8("butclear"));
        butclear->setGeometry(QRect(500, 377, 81, 31));
        butclear->setStyleSheet(QString::fromUtf8("font: 12pt \"\351\273\221\344\275\223\";"));

        retranslateUi(DlgTimeInterval);

        QMetaObject::connectSlotsByName(DlgTimeInterval);
    } // setupUi

    void retranslateUi(QDialog *DlgTimeInterval)
    {
        DlgTimeInterval->setWindowTitle(QApplication::translate("DlgTimeInterval", "\346\227\266\346\256\265\350\241\250", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("DlgTimeInterval", "*\350\246\201\346\211\247\350\241\214\347\232\204\351\205\215\346\227\266\346\226\271\346\241\210\345\217\267\343\200\2020\350\241\250\347\244\272\346\262\241\346\234\211\345\217\257\346\211\247\350\241\214\346\226\271\345\274\217\357\274\214\345\215\263\347\224\261\344\277\241\345\217\267\346\234\272\350\207\252\344\270\273\345\206\263\345\256\232\346\216\247\345\210\266\346\226\271\345\274\217", 0, QApplication::UnicodeUTF8));
        hang->setText(QString());
        label_4->setText(QApplication::translate("DlgTimeInterval", "\345\274\200\345\247\213\346\211\247\350\241\214\346\227\266\345\210\273\347\232\204\346\225\264\345\210\206\346\225\260", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("DlgTimeInterval", "\346\216\247\345\210\266\346\226\271\345\274\217", 0, QApplication::UnicodeUTF8));
        radionum8->setText(QApplication::translate("DlgTimeInterval", "[8]\345\215\225\347\202\271\344\274\230\345\214\226", 0, QApplication::UnicodeUTF8));
        radionum13->setText(QApplication::translate("DlgTimeInterval", "[13]\345\271\262\351\242\204\347\272\277\346\216\247", 0, QApplication::UnicodeUTF8));
        radionum11->setText(QApplication::translate("DlgTimeInterval", "[11]\344\270\273\344\273\216\347\272\277\346\216\247", 0, QApplication::UnicodeUTF8));
        radionum12->setText(QApplication::translate("DlgTimeInterval", "[12]\347\263\273\347\273\237\344\274\230\345\214\226", 0, QApplication::UnicodeUTF8));
        radionum0->setText(QApplication::translate("DlgTimeInterval", "[0]\350\207\252\344\270\273\346\216\247\345\210\266", 0, QApplication::UnicodeUTF8));
        radionum3->setText(QApplication::translate("DlgTimeInterval", "[3]\345\205\250\347\272\242", 0, QApplication::UnicodeUTF8));
        radionum1->setText(QApplication::translate("DlgTimeInterval", "[1]\345\205\263\347\201\257", 0, QApplication::UnicodeUTF8));
        radionum6->setText(QApplication::translate("DlgTimeInterval", "[6]\346\204\237\345\272\224", 0, QApplication::UnicodeUTF8));
        radionum2->setText(QApplication::translate("DlgTimeInterval", "[2]\351\227\252\345\205\211", 0, QApplication::UnicodeUTF8));
        radioButton->setText(QApplication::translate("DlgTimeInterval", "\347\275\256\347\251\272", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("DlgTimeInterval", "\346\227\266\346\256\265\344\272\213\344\273\266\345\217\267", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("DlgTimeInterval", "\346\227\266\346\256\265\350\241\250\345\217\267", 0, QApplication::UnicodeUTF8));
        clearall->setText(QApplication::translate("DlgTimeInterval", "\346\270\205\347\251\272\n"
"\345\205\250\350\241\250", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("DlgTimeInterval", "\351\205\215\346\227\266\346\226\271\346\241\210\345\217\267", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("DlgTimeInterval", "\345\267\262\350\256\276\346\227\266\346\256\265\350\241\250\346\225\260", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("DlgTimeInterval", "\345\274\200\345\247\213\346\211\247\350\241\214\346\227\266\345\210\273\347\232\204\346\225\264\347\202\271\346\225\260", 0, QApplication::UnicodeUTF8));
        query->setText(QApplication::translate("DlgTimeInterval", "\346\237\245\350\257\242\n"
"\345\267\262\350\256\276", 0, QApplication::UnicodeUTF8));
        display->setText(QString());
        butfind->setText(QApplication::translate("DlgTimeInterval", "\346\237\245 \350\257\242", 0, QApplication::UnicodeUTF8));
        butok->setText(QApplication::translate("DlgTimeInterval", "\344\277\256 \346\224\271", 0, QApplication::UnicodeUTF8));
        butclear->setText(QApplication::translate("DlgTimeInterval", "\346\270\205\347\251\272\350\241\214", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DlgTimeInterval: public Ui_DlgTimeInterval {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGTIMEINTERVAL_H
