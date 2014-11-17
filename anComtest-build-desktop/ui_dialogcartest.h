/********************************************************************************
** Form generated from reading UI file 'dialogcartest.ui'
**
** Created: Sat Sep 13 18:15:00 2014
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGCARTEST_H
#define UI_DIALOGCARTEST_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_DialogCarTest
{
public:
    QLabel *label;
    QGroupBox *groupBox;
    QRadioButton *radioout;
    QRadioButton *radioin;
    QRadioButton *radionull;
    QSpinBox *spinBox;
    QGroupBox *groupBox_3;
    QCheckBox *bao;
    QCheckBox *bao_2;
    QCheckBox *bao_3;
    QCheckBox *bao_4;
    QCheckBox *bao_5;
    QCheckBox *bao_6;
    QCheckBox *bao_7;
    QCheckBox *bao_8;
    QCheckBox *bao_9;
    QCheckBox *bao_10;
    QCheckBox *bao_11;
    QCheckBox *bao_12;
    QCheckBox *bao_13;
    QCheckBox *bao_14;
    QCheckBox *bao_15;
    QCheckBox *bao_16;
    QLabel *display;
    QPushButton *butfind;
    QPushButton *butok;
    QPushButton *butquery;
    QLabel *label_8;
    QPushButton *butclearall;
    QLabel *hang;
    QPushButton *butok_2;

    void setupUi(QDialog *DialogCarTest)
    {
        if (DialogCarTest->objectName().isEmpty())
            DialogCarTest->setObjectName(QString::fromUtf8("DialogCarTest"));
        DialogCarTest->resize(800, 450);
        label = new QLabel(DialogCarTest);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(160, 30, 151, 31));
        label->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));
        groupBox = new QGroupBox(DialogCarTest);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(200, 84, 371, 71));
        groupBox->setStyleSheet(QString::fromUtf8("font: 12pt \"\351\273\221\344\275\223\";"));
        radioout = new QRadioButton(groupBox);
        radioout->setObjectName(QString::fromUtf8("radioout"));
        radioout->setGeometry(QRect(43, 30, 55, 20));
        radioin = new QRadioButton(groupBox);
        radioin->setObjectName(QString::fromUtf8("radioin"));
        radioin->setGeometry(QRect(273, 30, 55, 20));
        radionull = new QRadioButton(groupBox);
        radionull->setObjectName(QString::fromUtf8("radionull"));
        radionull->setGeometry(QRect(161, 32, 89, 16));
        spinBox = new QSpinBox(DialogCarTest);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(490, 30, 111, 31));
        spinBox->setMinimum(1);
        spinBox->setMaximum(56);
        groupBox_3 = new QGroupBox(DialogCarTest);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(80, 170, 651, 101));
        groupBox_3->setStyleSheet(QString::fromUtf8("font: 12pt \"\351\273\221\344\275\223\";"));
        bao = new QCheckBox(groupBox_3);
        bao->setObjectName(QString::fromUtf8("bao"));
        bao->setGeometry(QRect(20, 27, 63, 20));
        bao_2 = new QCheckBox(groupBox_3);
        bao_2->setObjectName(QString::fromUtf8("bao_2"));
        bao_2->setGeometry(QRect(90, 27, 63, 20));
        bao_3 = new QCheckBox(groupBox_3);
        bao_3->setObjectName(QString::fromUtf8("bao_3"));
        bao_3->setGeometry(QRect(170, 27, 63, 20));
        bao_4 = new QCheckBox(groupBox_3);
        bao_4->setObjectName(QString::fromUtf8("bao_4"));
        bao_4->setGeometry(QRect(250, 27, 63, 20));
        bao_5 = new QCheckBox(groupBox_3);
        bao_5->setObjectName(QString::fromUtf8("bao_5"));
        bao_5->setGeometry(QRect(330, 27, 63, 20));
        bao_6 = new QCheckBox(groupBox_3);
        bao_6->setObjectName(QString::fromUtf8("bao_6"));
        bao_6->setGeometry(QRect(410, 27, 63, 20));
        bao_7 = new QCheckBox(groupBox_3);
        bao_7->setObjectName(QString::fromUtf8("bao_7"));
        bao_7->setGeometry(QRect(490, 27, 63, 20));
        bao_8 = new QCheckBox(groupBox_3);
        bao_8->setObjectName(QString::fromUtf8("bao_8"));
        bao_8->setGeometry(QRect(570, 27, 63, 20));
        bao_9 = new QCheckBox(groupBox_3);
        bao_9->setObjectName(QString::fromUtf8("bao_9"));
        bao_9->setGeometry(QRect(20, 64, 63, 20));
        bao_10 = new QCheckBox(groupBox_3);
        bao_10->setObjectName(QString::fromUtf8("bao_10"));
        bao_10->setGeometry(QRect(90, 64, 71, 20));
        bao_11 = new QCheckBox(groupBox_3);
        bao_11->setObjectName(QString::fromUtf8("bao_11"));
        bao_11->setGeometry(QRect(170, 64, 71, 20));
        bao_12 = new QCheckBox(groupBox_3);
        bao_12->setObjectName(QString::fromUtf8("bao_12"));
        bao_12->setGeometry(QRect(249, 64, 71, 20));
        bao_13 = new QCheckBox(groupBox_3);
        bao_13->setObjectName(QString::fromUtf8("bao_13"));
        bao_13->setGeometry(QRect(330, 64, 71, 20));
        bao_14 = new QCheckBox(groupBox_3);
        bao_14->setObjectName(QString::fromUtf8("bao_14"));
        bao_14->setGeometry(QRect(410, 64, 71, 20));
        bao_15 = new QCheckBox(groupBox_3);
        bao_15->setObjectName(QString::fromUtf8("bao_15"));
        bao_15->setGeometry(QRect(490, 64, 71, 20));
        bao_16 = new QCheckBox(groupBox_3);
        bao_16->setObjectName(QString::fromUtf8("bao_16"));
        bao_16->setGeometry(QRect(570, 64, 81, 20));
        display = new QLabel(DialogCarTest);
        display->setObjectName(QString::fromUtf8("display"));
        display->setGeometry(QRect(340, 340, 131, 31));
        butfind = new QPushButton(DialogCarTest);
        butfind->setObjectName(QString::fromUtf8("butfind"));
        butfind->setGeometry(QRect(230, 380, 81, 31));
        butok = new QPushButton(DialogCarTest);
        butok->setObjectName(QString::fromUtf8("butok"));
        butok->setGeometry(QRect(360, 380, 81, 31));
        butquery = new QPushButton(DialogCarTest);
        butquery->setObjectName(QString::fromUtf8("butquery"));
        butquery->setGeometry(QRect(440, 283, 41, 41));
        label_8 = new QLabel(DialogCarTest);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(260, 296, 91, 20));
        label_8->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));
        butclearall = new QPushButton(DialogCarTest);
        butclearall->setObjectName(QString::fromUtf8("butclearall"));
        butclearall->setGeometry(QRect(500, 283, 41, 41));
        hang = new QLabel(DialogCarTest);
        hang->setObjectName(QString::fromUtf8("hang"));
        hang->setGeometry(QRect(360, 290, 61, 31));
        hang->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));
        butok_2 = new QPushButton(DialogCarTest);
        butok_2->setObjectName(QString::fromUtf8("butok_2"));
        butok_2->setGeometry(QRect(490, 380, 81, 31));

        retranslateUi(DialogCarTest);

        QMetaObject::connectSlotsByName(DialogCarTest);
    } // setupUi

    void retranslateUi(QDialog *DialogCarTest)
    {
        DialogCarTest->setWindowTitle(QApplication::translate("DialogCarTest", "\350\275\246\346\243\200\350\241\250", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("DialogCarTest", "\350\275\246\350\276\206\346\243\200\346\265\213\350\241\250\350\241\214\345\217\267", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("DialogCarTest", "\345\207\272\345\205\245\345\217\243", 0, QApplication::UnicodeUTF8));
        radioout->setText(QApplication::translate("DialogCarTest", "\345\207\272\345\217\243", 0, QApplication::UnicodeUTF8));
        radioin->setText(QApplication::translate("DialogCarTest", "\345\205\245\345\217\243", 0, QApplication::UnicodeUTF8));
        radionull->setText(QApplication::translate("DialogCarTest", "\347\251\272", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("DialogCarTest", "\347\233\270\344\275\215", 0, QApplication::UnicodeUTF8));
        bao->setText(QApplication::translate("DialogCarTest", "\347\233\270\344\275\2151 ", 0, QApplication::UnicodeUTF8));
        bao_2->setText(QApplication::translate("DialogCarTest", "\347\233\270\344\275\2152", 0, QApplication::UnicodeUTF8));
        bao_3->setText(QApplication::translate("DialogCarTest", "\347\233\270\344\275\2153", 0, QApplication::UnicodeUTF8));
        bao_4->setText(QApplication::translate("DialogCarTest", "\347\233\270\344\275\2154", 0, QApplication::UnicodeUTF8));
        bao_5->setText(QApplication::translate("DialogCarTest", "\347\233\270\344\275\2155", 0, QApplication::UnicodeUTF8));
        bao_6->setText(QApplication::translate("DialogCarTest", "\347\233\270\344\275\2156", 0, QApplication::UnicodeUTF8));
        bao_7->setText(QApplication::translate("DialogCarTest", "\347\233\270\344\275\2157", 0, QApplication::UnicodeUTF8));
        bao_8->setText(QApplication::translate("DialogCarTest", "\347\233\270\344\275\2158", 0, QApplication::UnicodeUTF8));
        bao_9->setText(QApplication::translate("DialogCarTest", "\347\233\270\344\275\2159", 0, QApplication::UnicodeUTF8));
        bao_10->setText(QApplication::translate("DialogCarTest", "\347\233\270\344\275\21510", 0, QApplication::UnicodeUTF8));
        bao_11->setText(QApplication::translate("DialogCarTest", "\347\233\270\344\275\21511", 0, QApplication::UnicodeUTF8));
        bao_12->setText(QApplication::translate("DialogCarTest", "\347\233\270\344\275\21512", 0, QApplication::UnicodeUTF8));
        bao_13->setText(QApplication::translate("DialogCarTest", "\347\233\270\344\275\21513", 0, QApplication::UnicodeUTF8));
        bao_14->setText(QApplication::translate("DialogCarTest", "\347\233\270\344\275\21514", 0, QApplication::UnicodeUTF8));
        bao_15->setText(QApplication::translate("DialogCarTest", "\347\233\270\344\275\21515", 0, QApplication::UnicodeUTF8));
        bao_16->setText(QApplication::translate("DialogCarTest", "\347\233\270\344\275\21516", 0, QApplication::UnicodeUTF8));
        display->setText(QString());
        butfind->setText(QApplication::translate("DialogCarTest", "\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
        butok->setText(QApplication::translate("DialogCarTest", "\344\277\256\346\224\271", 0, QApplication::UnicodeUTF8));
        butquery->setText(QApplication::translate("DialogCarTest", "\346\237\245\350\257\242\n"
"\345\267\262\350\256\276", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("DialogCarTest", "\345\267\262\350\256\276\350\241\214\346\225\260", 0, QApplication::UnicodeUTF8));
        butclearall->setText(QApplication::translate("DialogCarTest", "\346\270\205\347\251\272\n"
"\345\205\250\350\241\250", 0, QApplication::UnicodeUTF8));
        hang->setText(QString());
        butok_2->setText(QApplication::translate("DialogCarTest", "\346\270\205\347\251\272\350\241\214", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DialogCarTest: public Ui_DialogCarTest {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGCARTEST_H
