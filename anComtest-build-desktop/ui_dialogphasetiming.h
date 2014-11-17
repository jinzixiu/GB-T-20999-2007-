/********************************************************************************
** Form generated from reading UI file 'dialogphasetiming.ui'
**
** Created: Thu Sep 11 14:36:24 2014
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGPHASETIMING_H
#define UI_DIALOGPHASETIMING_H

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
#include <QtGui/QSpinBox>
#include <QtGui/QSplitter>

QT_BEGIN_NAMESPACE

class Ui_DialogPhaseTiming
{
public:
    QSplitter *splitter;
    QLabel *label_5;
    QSpinBox *spinblue;
    QLabel *label_6;
    QSpinBox *spinyellow;
    QLabel *label_7;
    QSpinBox *spinred;
    QPushButton *butquery;
    QFrame *line;
    QGroupBox *groupBox;
    QSplitter *splitter_4;
    QSplitter *splitter_2;
    QCheckBox *phase1;
    QCheckBox *phase2;
    QCheckBox *phase3;
    QCheckBox *phase4;
    QCheckBox *phase5;
    QCheckBox *phase6;
    QCheckBox *phase7;
    QCheckBox *phase8;
    QSplitter *splitter_3;
    QCheckBox *phase9;
    QCheckBox *phase10;
    QCheckBox *phase11;
    QCheckBox *phase12;
    QCheckBox *phase13;
    QCheckBox *phase14;
    QCheckBox *phase15;
    QCheckBox *phase16;
    QCheckBox *checkisparm;
    QSpinBox *spinnum;
    QLabel *label_3;
    QLabel *label_2;
    QSpinBox *spinBoxplannum;
    QLabel *hang;
    QLabel *label_8;
    QLabel *label;
    QPushButton *butclearall;
    QFrame *line_2;
    QPushButton *butfind;
    QPushButton *butok;
    QLabel *display;
    QPushButton *butclear;

    void setupUi(QDialog *DialogPhaseTiming)
    {
        if (DialogPhaseTiming->objectName().isEmpty())
            DialogPhaseTiming->setObjectName(QString::fromUtf8("DialogPhaseTiming"));
        DialogPhaseTiming->resize(800, 450);
        splitter = new QSplitter(DialogPhaseTiming);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setGeometry(QRect(87, 186, 651, 51));
        splitter->setOrientation(Qt::Horizontal);
        label_5 = new QLabel(splitter);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));
        splitter->addWidget(label_5);
        spinblue = new QSpinBox(splitter);
        spinblue->setObjectName(QString::fromUtf8("spinblue"));
        spinblue->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));
        spinblue->setMaximum(255);
        splitter->addWidget(spinblue);
        label_6 = new QLabel(splitter);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));
        splitter->addWidget(label_6);
        spinyellow = new QSpinBox(splitter);
        spinyellow->setObjectName(QString::fromUtf8("spinyellow"));
        spinyellow->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));
        spinyellow->setMaximum(16);
        splitter->addWidget(spinyellow);
        label_7 = new QLabel(splitter);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));
        splitter->addWidget(label_7);
        spinred = new QSpinBox(splitter);
        spinred->setObjectName(QString::fromUtf8("spinred"));
        spinred->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));
        spinred->setMaximum(16);
        splitter->addWidget(spinred);
        butquery = new QPushButton(DialogPhaseTiming);
        butquery->setObjectName(QString::fromUtf8("butquery"));
        butquery->setGeometry(QRect(434, 290, 41, 41));
        line = new QFrame(DialogPhaseTiming);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(28, 60, 741, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        groupBox = new QGroupBox(DialogPhaseTiming);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(70, 80, 671, 101));
        groupBox->setStyleSheet(QString::fromUtf8("font: 12pt \"\351\273\221\344\275\223\";"));
        splitter_4 = new QSplitter(groupBox);
        splitter_4->setObjectName(QString::fromUtf8("splitter_4"));
        splitter_4->setGeometry(QRect(20, 20, 631, 71));
        splitter_4->setOrientation(Qt::Vertical);
        splitter_2 = new QSplitter(splitter_4);
        splitter_2->setObjectName(QString::fromUtf8("splitter_2"));
        splitter_2->setOrientation(Qt::Horizontal);
        phase1 = new QCheckBox(splitter_2);
        phase1->setObjectName(QString::fromUtf8("phase1"));
        splitter_2->addWidget(phase1);
        phase2 = new QCheckBox(splitter_2);
        phase2->setObjectName(QString::fromUtf8("phase2"));
        splitter_2->addWidget(phase2);
        phase3 = new QCheckBox(splitter_2);
        phase3->setObjectName(QString::fromUtf8("phase3"));
        splitter_2->addWidget(phase3);
        phase4 = new QCheckBox(splitter_2);
        phase4->setObjectName(QString::fromUtf8("phase4"));
        splitter_2->addWidget(phase4);
        phase5 = new QCheckBox(splitter_2);
        phase5->setObjectName(QString::fromUtf8("phase5"));
        splitter_2->addWidget(phase5);
        phase6 = new QCheckBox(splitter_2);
        phase6->setObjectName(QString::fromUtf8("phase6"));
        splitter_2->addWidget(phase6);
        phase7 = new QCheckBox(splitter_2);
        phase7->setObjectName(QString::fromUtf8("phase7"));
        splitter_2->addWidget(phase7);
        phase8 = new QCheckBox(splitter_2);
        phase8->setObjectName(QString::fromUtf8("phase8"));
        splitter_2->addWidget(phase8);
        splitter_4->addWidget(splitter_2);
        splitter_3 = new QSplitter(splitter_4);
        splitter_3->setObjectName(QString::fromUtf8("splitter_3"));
        splitter_3->setOrientation(Qt::Horizontal);
        phase9 = new QCheckBox(splitter_3);
        phase9->setObjectName(QString::fromUtf8("phase9"));
        splitter_3->addWidget(phase9);
        phase10 = new QCheckBox(splitter_3);
        phase10->setObjectName(QString::fromUtf8("phase10"));
        splitter_3->addWidget(phase10);
        phase11 = new QCheckBox(splitter_3);
        phase11->setObjectName(QString::fromUtf8("phase11"));
        splitter_3->addWidget(phase11);
        phase12 = new QCheckBox(splitter_3);
        phase12->setObjectName(QString::fromUtf8("phase12"));
        splitter_3->addWidget(phase12);
        phase13 = new QCheckBox(splitter_3);
        phase13->setObjectName(QString::fromUtf8("phase13"));
        splitter_3->addWidget(phase13);
        phase14 = new QCheckBox(splitter_3);
        phase14->setObjectName(QString::fromUtf8("phase14"));
        splitter_3->addWidget(phase14);
        phase15 = new QCheckBox(splitter_3);
        phase15->setObjectName(QString::fromUtf8("phase15"));
        splitter_3->addWidget(phase15);
        phase16 = new QCheckBox(splitter_3);
        phase16->setObjectName(QString::fromUtf8("phase16"));
        splitter_3->addWidget(phase16);
        splitter_4->addWidget(splitter_3);
        checkisparm = new QCheckBox(DialogPhaseTiming);
        checkisparm->setObjectName(QString::fromUtf8("checkisparm"));
        checkisparm->setGeometry(QRect(447, 246, 171, 21));
        checkisparm->setStyleSheet(QString::fromUtf8("font: 12pt \"\351\273\221\344\275\223\";"));
        spinnum = new QSpinBox(DialogPhaseTiming);
        spinnum->setObjectName(QString::fromUtf8("spinnum"));
        spinnum->setGeometry(QRect(604, 30, 81, 31));
        spinnum->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));
        spinnum->setMinimum(1);
        spinnum->setMaximum(16);
        label_3 = new QLabel(DialogPhaseTiming);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(255, 296, 91, 31));
        label_3->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));
        label_2 = new QLabel(DialogPhaseTiming);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(480, 29, 61, 31));
        label_2->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));
        spinBoxplannum = new QSpinBox(DialogPhaseTiming);
        spinBoxplannum->setObjectName(QString::fromUtf8("spinBoxplannum"));
        spinBoxplannum->setGeometry(QRect(276, 30, 81, 31));
        spinBoxplannum->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));
        spinBoxplannum->setMinimum(1);
        spinBoxplannum->setMaximum(16);
        hang = new QLabel(DialogPhaseTiming);
        hang->setObjectName(QString::fromUtf8("hang"));
        hang->setGeometry(QRect(351, 299, 61, 21));
        hang->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));
        label_8 = new QLabel(DialogPhaseTiming);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(220, 240, 151, 31));
        label_8->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));
        label = new QLabel(DialogPhaseTiming);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(73, 29, 151, 31));
        label->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));
        butclearall = new QPushButton(DialogPhaseTiming);
        butclearall->setObjectName(QString::fromUtf8("butclearall"));
        butclearall->setGeometry(QRect(500, 290, 41, 41));
        line_2 = new QFrame(DialogPhaseTiming);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(30, 273, 741, 16));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        butfind = new QPushButton(DialogPhaseTiming);
        butfind->setObjectName(QString::fromUtf8("butfind"));
        butfind->setGeometry(QRect(280, 390, 75, 23));
        butok = new QPushButton(DialogPhaseTiming);
        butok->setObjectName(QString::fromUtf8("butok"));
        butok->setGeometry(QRect(380, 390, 75, 23));
        display = new QLabel(DialogPhaseTiming);
        display->setObjectName(QString::fromUtf8("display"));
        display->setGeometry(QRect(380, 350, 91, 31));
        butclear = new QPushButton(DialogPhaseTiming);
        butclear->setObjectName(QString::fromUtf8("butclear"));
        butclear->setGeometry(QRect(480, 390, 75, 23));

        retranslateUi(DialogPhaseTiming);

        QMetaObject::connectSlotsByName(DialogPhaseTiming);
    } // setupUi

    void retranslateUi(QDialog *DialogPhaseTiming)
    {
        DialogPhaseTiming->setWindowTitle(QApplication::translate("DialogPhaseTiming", "\351\230\266\346\256\265\351\205\215\346\227\266", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("DialogPhaseTiming", "\351\230\266\346\256\265\347\273\277\347\201\257\346\227\266\351\227\264", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("DialogPhaseTiming", "\351\230\266\346\256\265\351\273\204\347\201\257\346\227\266\351\227\264", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("DialogPhaseTiming", "\351\230\266\346\256\265\347\272\242\347\201\257\346\227\266\351\227\264", 0, QApplication::UnicodeUTF8));
        butquery->setText(QApplication::translate("DialogPhaseTiming", "\346\237\245\350\257\242\n"
"\345\267\262\350\256\276", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("DialogPhaseTiming", "\346\224\276\350\241\214\347\233\270\344\275\215", 0, QApplication::UnicodeUTF8));
        phase1->setText(QApplication::translate("DialogPhaseTiming", "\347\233\270\344\275\2151", 0, QApplication::UnicodeUTF8));
        phase2->setText(QApplication::translate("DialogPhaseTiming", "\347\233\270\344\275\2152", 0, QApplication::UnicodeUTF8));
        phase3->setText(QApplication::translate("DialogPhaseTiming", "\347\233\270\344\275\2153", 0, QApplication::UnicodeUTF8));
        phase4->setText(QApplication::translate("DialogPhaseTiming", "\347\233\270\344\275\2154", 0, QApplication::UnicodeUTF8));
        phase5->setText(QApplication::translate("DialogPhaseTiming", "\347\233\270\344\275\2155", 0, QApplication::UnicodeUTF8));
        phase6->setText(QApplication::translate("DialogPhaseTiming", "\347\233\270\344\275\2156", 0, QApplication::UnicodeUTF8));
        phase7->setText(QApplication::translate("DialogPhaseTiming", "\347\233\270\344\275\2157", 0, QApplication::UnicodeUTF8));
        phase8->setText(QApplication::translate("DialogPhaseTiming", "\347\233\270\344\275\2158", 0, QApplication::UnicodeUTF8));
        phase9->setText(QApplication::translate("DialogPhaseTiming", "\347\233\270\344\275\2159", 0, QApplication::UnicodeUTF8));
        phase10->setText(QApplication::translate("DialogPhaseTiming", "\347\233\270\344\275\21510", 0, QApplication::UnicodeUTF8));
        phase11->setText(QApplication::translate("DialogPhaseTiming", "\347\233\270\344\275\21511", 0, QApplication::UnicodeUTF8));
        phase12->setText(QApplication::translate("DialogPhaseTiming", "\347\233\270\344\275\21512", 0, QApplication::UnicodeUTF8));
        phase13->setText(QApplication::translate("DialogPhaseTiming", "\347\233\270\344\275\21513", 0, QApplication::UnicodeUTF8));
        phase14->setText(QApplication::translate("DialogPhaseTiming", "\347\233\270\344\275\21514", 0, QApplication::UnicodeUTF8));
        phase15->setText(QApplication::translate("DialogPhaseTiming", "\347\233\270\344\275\21515", 0, QApplication::UnicodeUTF8));
        phase16->setText(QApplication::translate("DialogPhaseTiming", "\347\233\270\344\275\21516", 0, QApplication::UnicodeUTF8));
        checkisparm->setText(QApplication::translate("DialogPhaseTiming", "\346\230\257\345\220\246\344\274\230\351\200\211\345\205\254\345\205\261\345\221\250\346\234\237", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("DialogPhaseTiming", "\345\267\262\350\256\276\350\241\214\345\217\267", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("DialogPhaseTiming", "\351\230\266\346\256\265\345\217\267", 0, QApplication::UnicodeUTF8));
        hang->setText(QString());
        label_8->setText(QApplication::translate("DialogPhaseTiming", "\351\230\266\346\256\265\351\200\211\351\241\271\345\217\202\346\225\260", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("DialogPhaseTiming", "\351\230\266\346\256\265\351\205\215\346\227\266\346\226\271\346\241\210\345\217\267", 0, QApplication::UnicodeUTF8));
        butclearall->setText(QApplication::translate("DialogPhaseTiming", "\346\270\205\351\231\244\n"
"\345\205\250\350\241\250", 0, QApplication::UnicodeUTF8));
        butfind->setText(QApplication::translate("DialogPhaseTiming", "\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
        butok->setText(QApplication::translate("DialogPhaseTiming", "\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        display->setText(QString());
        butclear->setText(QApplication::translate("DialogPhaseTiming", "\346\270\205\347\251\272\350\241\214", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DialogPhaseTiming: public Ui_DialogPhaseTiming {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGPHASETIMING_H
