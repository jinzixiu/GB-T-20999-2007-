/********************************************************************************
** Form generated from reading UI file 'dlgphaseparm.ui'
**
** Created: Sat Sep 13 18:15:00 2014
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGPHASEPARM_H
#define UI_DLGPHASEPARM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_DlgPhaseParm
{
public:
    QLabel *label_5;
    QSpinBox *spinNumber;
    QSpinBox *spinGreenTime;
    QLabel *label_6;
    QCheckBox *check1;
    QSpinBox *spinCrossmsec;
    QSpinBox *spinClearTime;
    QGroupBox *groupBox;
    QRadioButton *radioFixed;
    QRadioButton *radioWait;
    QRadioButton *radioPlay;
    QRadioButton *radioKey;
    QRadioButton *radiokongong;
    QLabel *label_10;
    QCheckBox *check4;
    QLabel *label_7;
    QFrame *line;
    QLabel *label;
    QSpinBox *spinGreenLaterTime;
    QSpinBox *spinMaxTime;
    QLabel *label_8;
    QLabel *label_2;
    QCheckBox *check2;
    QGroupBox *groupBox_2;
    QRadioButton *radiodong;
    QRadioButton *radiobei;
    QRadioButton *radioxi;
    QRadioButton *radionan;
    QRadioButton *radionull;
    QLabel *label_11;
    QLabel *label_3;
    QSpinBox *spinGreenFlash;
    QPushButton *butquery;
    QSpinBox *spinMaxTime2;
    QLabel *label_9;
    QGroupBox *groupBox_3;
    QRadioButton *radioyuandeng;
    QRadioButton *radioyouzhuan;
    QRadioButton *radiozhixingdeng;
    QRadioButton *radiozuozhuan;
    QRadioButton *radiodiaotou;
    QRadioButton *radiokong;
    QSpinBox *spinMinGreenTime;
    QLabel *label_4;
    QCheckBox *check0;
    QLabel *hang;
    QCheckBox *check3;
    QPushButton *butclearall;
    QPushButton *butfind;
    QPushButton *butok;
    QPushButton *butclear;
    QLabel *display;

    void setupUi(QDialog *DlgPhaseParm)
    {
        if (DlgPhaseParm->objectName().isEmpty())
            DlgPhaseParm->setObjectName(QString::fromUtf8("DlgPhaseParm"));
        DlgPhaseParm->resize(800, 450);
        label_5 = new QLabel(DlgPhaseParm);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(27, 202, 170, 38));
        label_5->setStyleSheet(QString::fromUtf8("font: 11pt \"\351\273\221\344\275\223\";"));
        label_5->setAlignment(Qt::AlignCenter);
        spinNumber = new QSpinBox(DlgPhaseParm);
        spinNumber->setObjectName(QString::fromUtf8("spinNumber"));
        spinNumber->setGeometry(QRect(206, 31, 71, 35));
        spinNumber->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));
        spinNumber->setMinimum(1);
        spinNumber->setMaximum(16);
        spinGreenTime = new QSpinBox(DlgPhaseParm);
        spinGreenTime->setObjectName(QString::fromUtf8("spinGreenTime"));
        spinGreenTime->setGeometry(QRect(207, 334, 71, 35));
        spinGreenTime->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));
        spinGreenTime->setMaximum(256);
        label_6 = new QLabel(DlgPhaseParm);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(27, 245, 170, 39));
        label_6->setStyleSheet(QString::fromUtf8("font: 11pt \"\351\273\221\344\275\223\";"));
        label_6->setAlignment(Qt::AlignCenter);
        check1 = new QCheckBox(DlgPhaseParm);
        check1->setObjectName(QString::fromUtf8("check1"));
        check1->setEnabled(false);
        check1->setGeometry(QRect(486, 257, 191, 28));
        check1->setStyleSheet(QString::fromUtf8("font: 11pt \"\351\273\221\344\275\223\";"));
        spinCrossmsec = new QSpinBox(DlgPhaseParm);
        spinCrossmsec->setObjectName(QString::fromUtf8("spinCrossmsec"));
        spinCrossmsec->setGeometry(QRect(207, 74, 71, 35));
        spinCrossmsec->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));
        spinCrossmsec->setMaximum(256);
        spinClearTime = new QSpinBox(DlgPhaseParm);
        spinClearTime->setObjectName(QString::fromUtf8("spinClearTime"));
        spinClearTime->setGeometry(QRect(207, 114, 71, 35));
        spinClearTime->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));
        spinClearTime->setMaximum(256);
        groupBox = new QGroupBox(DlgPhaseParm);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(330, 110, 131, 201));
        groupBox->setStyleSheet(QString::fromUtf8("font: 11pt \"\351\273\221\344\275\223\";"));
        radioFixed = new QRadioButton(groupBox);
        radioFixed->setObjectName(QString::fromUtf8("radioFixed"));
        radioFixed->setGeometry(QRect(22, 25, 87, 19));
        radioWait = new QRadioButton(groupBox);
        radioWait->setObjectName(QString::fromUtf8("radioWait"));
        radioWait->setGeometry(QRect(22, 132, 87, 19));
        radioPlay = new QRadioButton(groupBox);
        radioPlay->setObjectName(QString::fromUtf8("radioPlay"));
        radioPlay->setGeometry(QRect(22, 61, 87, 19));
        radioKey = new QRadioButton(groupBox);
        radioKey->setObjectName(QString::fromUtf8("radioKey"));
        radioKey->setGeometry(QRect(22, 97, 87, 19));
        radiokongong = new QRadioButton(groupBox);
        radiokongong->setObjectName(QString::fromUtf8("radiokongong"));
        radiokongong->setGeometry(QRect(22, 167, 39, 19));
        label_10 = new QLabel(DlgPhaseParm);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(390, 27, 71, 31));
        label_10->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));
        check4 = new QCheckBox(DlgPhaseParm);
        check4->setObjectName(QString::fromUtf8("check4"));
        check4->setEnabled(false);
        check4->setGeometry(QRect(486, 157, 293, 28));
        check4->setStyleSheet(QString::fromUtf8("font: 11pt \"\351\273\221\344\275\223\";"));
        label_7 = new QLabel(DlgPhaseParm);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(27, 289, 170, 38));
        label_7->setStyleSheet(QString::fromUtf8("font: 11pt \"\351\273\221\344\275\223\";"));
        label_7->setAlignment(Qt::AlignCenter);
        line = new QFrame(DlgPhaseParm);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(293, 18, 20, 411));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        label = new QLabel(DlgPhaseParm);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(27, 29, 170, 38));
        label->setStyleSheet(QString::fromUtf8("font: 11pt \"\351\273\221\344\275\223\";"));
        label->setAlignment(Qt::AlignCenter);
        spinGreenLaterTime = new QSpinBox(DlgPhaseParm);
        spinGreenLaterTime->setObjectName(QString::fromUtf8("spinGreenLaterTime"));
        spinGreenLaterTime->setGeometry(QRect(207, 199, 71, 35));
        spinGreenLaterTime->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));
        spinGreenLaterTime->setMaximum(256);
        spinMaxTime = new QSpinBox(DlgPhaseParm);
        spinMaxTime->setObjectName(QString::fromUtf8("spinMaxTime"));
        spinMaxTime->setGeometry(QRect(207, 246, 71, 35));
        spinMaxTime->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));
        spinMaxTime->setMaximum(256);
        label_8 = new QLabel(DlgPhaseParm);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(27, 332, 170, 38));
        label_8->setStyleSheet(QString::fromUtf8("font: 11pt \"\351\273\221\344\275\223\";"));
        label_8->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(DlgPhaseParm);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(27, 72, 170, 39));
        label_2->setStyleSheet(QString::fromUtf8("font: 11pt \"\351\273\221\344\275\223\";"));
        label_2->setAlignment(Qt::AlignCenter);
        check2 = new QCheckBox(DlgPhaseParm);
        check2->setObjectName(QString::fromUtf8("check2"));
        check2->setEnabled(false);
        check2->setGeometry(QRect(486, 223, 251, 29));
        check2->setStyleSheet(QString::fromUtf8("font: 11pt \"\351\273\221\344\275\223\";"));
        groupBox_2 = new QGroupBox(DlgPhaseParm);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(412, 399, 16, 16));
        groupBox_2->setStyleSheet(QString::fromUtf8("font: 11pt \"\351\273\221\344\275\223\";"));
        radiodong = new QRadioButton(groupBox_2);
        radiodong->setObjectName(QString::fromUtf8("radiodong"));
        radiodong->setGeometry(QRect(32, 19, 41, 21));
        radiobei = new QRadioButton(groupBox_2);
        radiobei->setObjectName(QString::fromUtf8("radiobei"));
        radiobei->setGeometry(QRect(80, 60, 41, 20));
        radioxi = new QRadioButton(groupBox_2);
        radioxi->setObjectName(QString::fromUtf8("radioxi"));
        radioxi->setGeometry(QRect(91, 19, 41, 21));
        radionan = new QRadioButton(groupBox_2);
        radionan->setObjectName(QString::fromUtf8("radionan"));
        radionan->setGeometry(QRect(20, 60, 41, 21));
        radionull = new QRadioButton(groupBox_2);
        radionull->setObjectName(QString::fromUtf8("radionull"));
        radionull->setGeometry(QRect(20, 100, 41, 21));
        label_11 = new QLabel(DlgPhaseParm);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(486, 107, 151, 31));
        label_11->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));
        label_3 = new QLabel(DlgPhaseParm);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(27, 116, 170, 38));
        label_3->setStyleSheet(QString::fromUtf8("font: 11pt \"\351\273\221\344\275\223\";"));
        label_3->setAlignment(Qt::AlignCenter);
        spinGreenFlash = new QSpinBox(DlgPhaseParm);
        spinGreenFlash->setObjectName(QString::fromUtf8("spinGreenFlash"));
        spinGreenFlash->setGeometry(QRect(207, 378, 71, 35));
        spinGreenFlash->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));
        spinGreenFlash->setMaximum(256);
        butquery = new QPushButton(DlgPhaseParm);
        butquery->setObjectName(QString::fromUtf8("butquery"));
        butquery->setGeometry(QRect(590, 22, 41, 41));
        spinMaxTime2 = new QSpinBox(DlgPhaseParm);
        spinMaxTime2->setObjectName(QString::fromUtf8("spinMaxTime2"));
        spinMaxTime2->setGeometry(QRect(207, 290, 71, 35));
        spinMaxTime2->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));
        spinMaxTime2->setMaximum(256);
        label_9 = new QLabel(DlgPhaseParm);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(37, 380, 131, 31));
        label_9->setStyleSheet(QString::fromUtf8("font: 11pt \"\351\273\221\344\275\223\";"));
        label_9->setAlignment(Qt::AlignCenter);
        groupBox_3 = new QGroupBox(DlgPhaseParm);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(452, 399, 16, 16));
        groupBox_3->setStyleSheet(QString::fromUtf8("font: 11pt \"\351\273\221\344\275\223\";"));
        radioyuandeng = new QRadioButton(groupBox_3);
        radioyuandeng->setObjectName(QString::fromUtf8("radioyuandeng"));
        radioyuandeng->setGeometry(QRect(22, 19, 71, 21));
        radioyouzhuan = new QRadioButton(groupBox_3);
        radioyouzhuan->setObjectName(QString::fromUtf8("radioyouzhuan"));
        radioyouzhuan->setGeometry(QRect(100, 52, 91, 20));
        radiozhixingdeng = new QRadioButton(groupBox_3);
        radiozhixingdeng->setObjectName(QString::fromUtf8("radiozhixingdeng"));
        radiozhixingdeng->setGeometry(QRect(112, 18, 71, 21));
        radiozuozhuan = new QRadioButton(groupBox_3);
        radiozuozhuan->setObjectName(QString::fromUtf8("radiozuozhuan"));
        radiozuozhuan->setGeometry(QRect(10, 50, 91, 21));
        radiodiaotou = new QRadioButton(groupBox_3);
        radiodiaotou->setObjectName(QString::fromUtf8("radiodiaotou"));
        radiodiaotou->setGeometry(QRect(10, 83, 91, 20));
        radiokong = new QRadioButton(groupBox_3);
        radiokong->setObjectName(QString::fromUtf8("radiokong"));
        radiokong->setGeometry(QRect(101, 83, 91, 20));
        spinMinGreenTime = new QSpinBox(DlgPhaseParm);
        spinMinGreenTime->setObjectName(QString::fromUtf8("spinMinGreenTime"));
        spinMinGreenTime->setGeometry(QRect(207, 156, 71, 35));
        spinMinGreenTime->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));
        spinMinGreenTime->setMaximum(256);
        label_4 = new QLabel(DlgPhaseParm);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(27, 159, 170, 38));
        label_4->setStyleSheet(QString::fromUtf8("font: 11pt \"\351\273\221\344\275\223\";"));
        label_4->setAlignment(Qt::AlignCenter);
        check0 = new QCheckBox(DlgPhaseParm);
        check0->setObjectName(QString::fromUtf8("check0"));
        check0->setEnabled(false);
        check0->setGeometry(QRect(486, 290, 71, 28));
        check0->setStyleSheet(QString::fromUtf8("font: 11pt \"\351\273\221\344\275\223\";"));
        hang = new QLabel(DlgPhaseParm);
        hang->setObjectName(QString::fromUtf8("hang"));
        hang->setGeometry(QRect(481, 27, 71, 31));
        hang->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));
        check3 = new QCheckBox(DlgPhaseParm);
        check3->setObjectName(QString::fromUtf8("check3"));
        check3->setEnabled(false);
        check3->setGeometry(QRect(486, 190, 201, 28));
        check3->setStyleSheet(QString::fromUtf8("font: 11pt \"\351\273\221\344\275\223\";"));
        butclearall = new QPushButton(DlgPhaseParm);
        butclearall->setObjectName(QString::fromUtf8("butclearall"));
        butclearall->setGeometry(QRect(640, 22, 41, 41));
        butfind = new QPushButton(DlgPhaseParm);
        butfind->setObjectName(QString::fromUtf8("butfind"));
        butfind->setGeometry(QRect(412, 391, 71, 31));
        butfind->setStyleSheet(QString::fromUtf8("font: 12pt \"\351\273\221\344\275\223\";"));
        butok = new QPushButton(DlgPhaseParm);
        butok->setObjectName(QString::fromUtf8("butok"));
        butok->setGeometry(QRect(522, 391, 71, 31));
        butok->setStyleSheet(QString::fromUtf8("font: 12pt \"\351\273\221\344\275\223\";"));
        butclear = new QPushButton(DlgPhaseParm);
        butclear->setObjectName(QString::fromUtf8("butclear"));
        butclear->setGeometry(QRect(631, 391, 71, 31));
        butclear->setStyleSheet(QString::fromUtf8("font: 12pt \"\351\273\221\344\275\223\";"));
        display = new QLabel(DlgPhaseParm);
        display->setObjectName(QString::fromUtf8("display"));
        display->setGeometry(QRect(490, 349, 111, 21));
        groupBox_3->raise();
        label_5->raise();
        spinNumber->raise();
        spinGreenTime->raise();
        label_6->raise();
        check1->raise();
        spinCrossmsec->raise();
        spinClearTime->raise();
        groupBox->raise();
        label_10->raise();
        check4->raise();
        label_7->raise();
        line->raise();
        label->raise();
        spinGreenLaterTime->raise();
        spinMaxTime->raise();
        label_8->raise();
        label_2->raise();
        check2->raise();
        groupBox_2->raise();
        label_11->raise();
        label_3->raise();
        spinGreenFlash->raise();
        butquery->raise();
        spinMaxTime2->raise();
        label_9->raise();
        spinMinGreenTime->raise();
        label_4->raise();
        check0->raise();
        hang->raise();
        check3->raise();
        butclearall->raise();
        butfind->raise();
        butok->raise();
        butclear->raise();
        display->raise();

        retranslateUi(DlgPhaseParm);

        QMetaObject::connectSlotsByName(DlgPhaseParm);
    } // setupUi

    void retranslateUi(QDialog *DlgPhaseParm)
    {
        DlgPhaseParm->setWindowTitle(QApplication::translate("DlgPhaseParm", "\347\233\270\344\275\215\345\217\202\346\225\260\350\241\250", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("DlgPhaseParm", "\345\215\225\344\275\215\347\273\277\347\201\257\345\273\266\346\227\266\346\227\266\351\227\264", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("DlgPhaseParm", "\346\234\200\345\244\247\347\273\277\347\201\257\346\227\266\351\227\2641", 0, QApplication::UnicodeUTF8));
        check1->setText(QApplication::translate("DlgPhaseParm", "\350\267\257\346\256\265\344\270\255\347\232\204\350\241\214\344\272\272\350\277\207\350\241\227\347\233\270\344\275\215", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("DlgPhaseParm", "\347\233\270\344\275\215\347\261\273\345\236\213", 0, QApplication::UnicodeUTF8));
        radioFixed->setText(QApplication::translate("DlgPhaseParm", "\345\233\272\345\256\232\347\233\270\344\275\215", 0, QApplication::UnicodeUTF8));
        radioWait->setText(QApplication::translate("DlgPhaseParm", "\345\276\205\345\256\232\347\233\270\344\275\215", 0, QApplication::UnicodeUTF8));
        radioPlay->setText(QApplication::translate("DlgPhaseParm", "\345\274\271\346\200\247\347\233\270\344\275\215", 0, QApplication::UnicodeUTF8));
        radioKey->setText(QApplication::translate("DlgPhaseParm", "\345\205\263\351\224\256\347\233\270\344\275\215", 0, QApplication::UnicodeUTF8));
        radiokongong->setText(QApplication::translate("DlgPhaseParm", "\346\227\240", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("DlgPhaseParm", "\345\267\262\350\256\276\350\241\214\357\274\232", 0, QApplication::UnicodeUTF8));
        check4->setText(QApplication::translate("DlgPhaseParm", "\350\267\237\351\232\217\345\220\214\351\230\266\346\256\265\344\270\255\345\220\214\346\227\266\346\224\276\350\241\214\347\232\204\347\233\270\344\275\215\344\270\200\350\265\267\346\224\276\350\241\214", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("DlgPhaseParm", "\346\234\200\345\244\247\347\273\277\347\201\257\346\227\266\351\227\2642", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("DlgPhaseParm", "\347\233\270   \344\275\215   \345\217\267", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("DlgPhaseParm", "\345\274\271\346\200\247\347\233\270\344\275\215\345\233\272\345\256\232\347\273\277\347\201\257\346\227\266\351\227\264", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("DlgPhaseParm", "\350\241\214\344\272\272\350\277\207\350\241\227\347\273\277\347\201\257\347\232\204\347\247\222\346\225\260", 0, QApplication::UnicodeUTF8));
        check2->setText(QApplication::translate("DlgPhaseParm", "\345\220\214\351\230\266\346\256\265\347\233\270\344\275\215\345\207\272\347\216\260\346\227\266\357\274\214\346\234\254\347\233\270\344\275\215\345\207\272\347\216\260", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("DlgPhaseParm", "\346\226\271\345\220\221", 0, QApplication::UnicodeUTF8));
        radiodong->setText(QApplication::translate("DlgPhaseParm", "\344\270\234", 0, QApplication::UnicodeUTF8));
        radiobei->setText(QApplication::translate("DlgPhaseParm", "\345\214\227", 0, QApplication::UnicodeUTF8));
        radioxi->setText(QApplication::translate("DlgPhaseParm", "\350\245\277", 0, QApplication::UnicodeUTF8));
        radionan->setText(QApplication::translate("DlgPhaseParm", "\345\215\227", 0, QApplication::UnicodeUTF8));
        radionull->setText(QApplication::translate("DlgPhaseParm", "\346\227\240", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("DlgPhaseParm", "\347\233\270\344\275\215\351\200\211\351\241\271\345\212\237\350\203\275\357\274\232", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("DlgPhaseParm", "\350\241\214\344\272\272\346\270\205\347\251\272\346\227\266\351\227\264", 0, QApplication::UnicodeUTF8));
        butquery->setText(QApplication::translate("DlgPhaseParm", "\346\237\245\350\257\242\n"
"\345\267\262\350\256\276", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("DlgPhaseParm", "\347\273\277 \351\227\252 \346\227\266 \351\227\264", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("DlgPhaseParm", "\347\233\270\344\275\215\347\261\273\345\236\213", 0, QApplication::UnicodeUTF8));
        radioyuandeng->setText(QApplication::translate("DlgPhaseParm", "\345\234\206\347\201\257", 0, QApplication::UnicodeUTF8));
        radioyouzhuan->setText(QApplication::translate("DlgPhaseParm", "\345\217\263\350\275\254", 0, QApplication::UnicodeUTF8));
        radiozhixingdeng->setText(QApplication::translate("DlgPhaseParm", "\347\233\264\350\241\214\347\201\257", 0, QApplication::UnicodeUTF8));
        radiozuozhuan->setText(QApplication::translate("DlgPhaseParm", "\345\267\246\350\275\254", 0, QApplication::UnicodeUTF8));
        radiodiaotou->setText(QApplication::translate("DlgPhaseParm", "\346\216\211\345\244\264", 0, QApplication::UnicodeUTF8));
        radiokong->setText(QApplication::translate("DlgPhaseParm", "\347\251\272", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("DlgPhaseParm", "\346\234\200\345\260\217\347\273\277\347\201\257\346\227\266\351\227\264", 0, QApplication::UnicodeUTF8));
        check0->setText(QApplication::translate("DlgPhaseParm", "\345\220\257\347\224\250", 0, QApplication::UnicodeUTF8));
        hang->setText(QString());
        check3->setText(QApplication::translate("DlgPhaseParm", "\350\241\214\344\272\272\350\267\237\351\232\217\346\234\272\345\212\250\350\275\246\344\270\200\350\265\267\346\224\276\350\241\214", 0, QApplication::UnicodeUTF8));
        butclearall->setText(QApplication::translate("DlgPhaseParm", "\346\270\205\347\251\272\n"
"\345\205\250\350\241\250", 0, QApplication::UnicodeUTF8));
        butfind->setText(QApplication::translate("DlgPhaseParm", "\346\237\245 \350\257\242", 0, QApplication::UnicodeUTF8));
        butok->setText(QApplication::translate("DlgPhaseParm", "\344\277\256 \346\224\271", 0, QApplication::UnicodeUTF8));
        butclear->setText(QApplication::translate("DlgPhaseParm", "\346\270\205\347\251\272\350\241\214", 0, QApplication::UnicodeUTF8));
        display->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class DlgPhaseParm: public Ui_DlgPhaseParm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGPHASEPARM_H
