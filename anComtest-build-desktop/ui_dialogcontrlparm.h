/********************************************************************************
** Form generated from reading UI file 'dialogcontrlparm.ui'
**
** Created: Sat Sep 13 18:15:00 2014
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGCONTRLPARM_H
#define UI_DIALOGCONTRLPARM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_DialogContrlParm
{
public:
    QSpinBox *spinphasedif;
    QLabel *label;
    QSpinBox *spinstate;
    QGroupBox *groupBox_6;
    QGroupBox *groupBox_5;
    QLabel *label_14;
    QLabel *label_15;
    QCheckBox *checkBox4_1;
    QCheckBox *checkBox4_2;
    QCheckBox *checkBox4_3;
    QCheckBox *checkBox4_4;
    QCheckBox *checkBox4_6;
    QCheckBox *checkBox4_5;
    QCheckBox *checkBox4_7;
    QCheckBox *checkBox4_8;
    QGroupBox *groupBox_4;
    QLabel *label_12;
    QLabel *label_13;
    QCheckBox *checkBox3_1;
    QCheckBox *checkBox3_2;
    QCheckBox *checkBox3_3;
    QCheckBox *checkBox3_4;
    QCheckBox *checkBox3_6;
    QCheckBox *checkBox3_5;
    QCheckBox *checkBox3_7;
    QCheckBox *checkBox3_8;
    QGroupBox *groupBox_3;
    QLabel *label_10;
    QLabel *label_11;
    QCheckBox *checkBox2_1;
    QCheckBox *checkBox2_2;
    QCheckBox *checkBox2_3;
    QCheckBox *checkBox2_4;
    QCheckBox *checkBox2_6;
    QCheckBox *checkBox2_5;
    QCheckBox *checkBox2_7;
    QCheckBox *checkBox2_8;
    QGroupBox *groupBox_2;
    QLabel *label_3;
    QLabel *label_9;
    QCheckBox *checkBox1_1;
    QCheckBox *checkBox1_2;
    QCheckBox *checkBox1_3;
    QCheckBox *checkBox1_4;
    QCheckBox *checkBox1_6;
    QCheckBox *checkBox1_5;
    QCheckBox *checkBox1_7;
    QCheckBox *checkBox1_8;
    QCheckBox *checkBox;
    QSpinBox *spininstruction;
    QLabel *label_4;
    QLabel *label_7;
    QSpinBox *spinmodel;
    QLabel *label_2;
    QLabel *label_5;
    QSpinBox *spinManual;
    QSpinBox *spincycletime;
    QLabel *label_8;
    QLabel *label_6;
    QGroupBox *groupBox;
    QRadioButton *radioclose;
    QRadioButton *radioflash;
    QRadioButton *radioallred;
    QRadioButton *radiofeel;
    QRadioButton *radiosinglebetter;
    QRadioButton *radiomasterlinecontrl;
    QRadioButton *radiosystembetter;
    QRadioButton *radiointerventionlinecontrl;
    QRadioButton *radionull;
    QLabel *display;
    QPushButton *butfind;
    QPushButton *butok;
    QComboBox *comboBoxplan;

    void setupUi(QDialog *DialogContrlParm)
    {
        if (DialogContrlParm->objectName().isEmpty())
            DialogContrlParm->setObjectName(QString::fromUtf8("DialogContrlParm"));
        DialogContrlParm->resize(800, 450);
        spinphasedif = new QSpinBox(DialogContrlParm);
        spinphasedif->setObjectName(QString::fromUtf8("spinphasedif"));
        spinphasedif->setGeometry(QRect(568, 134, 120, 30));
        spinphasedif->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));
        spinphasedif->setMaximum(255);
        label = new QLabel(DialogContrlParm);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(100, 13, 120, 30));
        label->setStyleSheet(QString::fromUtf8("font: 13pt \"\351\273\221\344\275\223\";\n"
"color:red;\357\277\275"));
        spinstate = new QSpinBox(DialogContrlParm);
        spinstate->setObjectName(QString::fromUtf8("spinstate"));
        spinstate->setGeometry(QRect(200, 178, 70, 30));
        spinstate->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));
        spinstate->setMaximum(16);
        groupBox_6 = new QGroupBox(DialogContrlParm);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        groupBox_6->setGeometry(QRect(48, 209, 711, 171));
        groupBox_6->setStyleSheet(QString::fromUtf8(""));
        groupBox_5 = new QGroupBox(groupBox_6);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setGeometry(QRect(536, 19, 161, 111));
        label_14 = new QLabel(groupBox_5);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(4, 20, 54, 12));
        label_15 = new QLabel(groupBox_5);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(4, 60, 54, 12));
        checkBox4_1 = new QCheckBox(groupBox_5);
        checkBox4_1->setObjectName(QString::fromUtf8("checkBox4_1"));
        checkBox4_1->setGeometry(QRect(43, 20, 71, 16));
        checkBox4_2 = new QCheckBox(groupBox_5);
        checkBox4_2->setObjectName(QString::fromUtf8("checkBox4_2"));
        checkBox4_2->setGeometry(QRect(93, 20, 71, 16));
        checkBox4_3 = new QCheckBox(groupBox_5);
        checkBox4_3->setObjectName(QString::fromUtf8("checkBox4_3"));
        checkBox4_3->setGeometry(QRect(43, 40, 71, 16));
        checkBox4_4 = new QCheckBox(groupBox_5);
        checkBox4_4->setObjectName(QString::fromUtf8("checkBox4_4"));
        checkBox4_4->setGeometry(QRect(93, 40, 71, 16));
        checkBox4_6 = new QCheckBox(groupBox_5);
        checkBox4_6->setObjectName(QString::fromUtf8("checkBox4_6"));
        checkBox4_6->setGeometry(QRect(93, 60, 71, 16));
        checkBox4_5 = new QCheckBox(groupBox_5);
        checkBox4_5->setObjectName(QString::fromUtf8("checkBox4_5"));
        checkBox4_5->setGeometry(QRect(43, 60, 71, 16));
        checkBox4_7 = new QCheckBox(groupBox_5);
        checkBox4_7->setObjectName(QString::fromUtf8("checkBox4_7"));
        checkBox4_7->setGeometry(QRect(43, 80, 71, 16));
        checkBox4_8 = new QCheckBox(groupBox_5);
        checkBox4_8->setObjectName(QString::fromUtf8("checkBox4_8"));
        checkBox4_8->setGeometry(QRect(93, 80, 71, 16));
        groupBox_4 = new QGroupBox(groupBox_6);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(363, 20, 161, 111));
        label_12 = new QLabel(groupBox_4);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(4, 20, 54, 12));
        label_13 = new QLabel(groupBox_4);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(4, 60, 54, 12));
        checkBox3_1 = new QCheckBox(groupBox_4);
        checkBox3_1->setObjectName(QString::fromUtf8("checkBox3_1"));
        checkBox3_1->setGeometry(QRect(43, 20, 71, 16));
        checkBox3_2 = new QCheckBox(groupBox_4);
        checkBox3_2->setObjectName(QString::fromUtf8("checkBox3_2"));
        checkBox3_2->setGeometry(QRect(93, 20, 71, 16));
        checkBox3_3 = new QCheckBox(groupBox_4);
        checkBox3_3->setObjectName(QString::fromUtf8("checkBox3_3"));
        checkBox3_3->setGeometry(QRect(43, 40, 71, 16));
        checkBox3_4 = new QCheckBox(groupBox_4);
        checkBox3_4->setObjectName(QString::fromUtf8("checkBox3_4"));
        checkBox3_4->setGeometry(QRect(93, 40, 71, 16));
        checkBox3_6 = new QCheckBox(groupBox_4);
        checkBox3_6->setObjectName(QString::fromUtf8("checkBox3_6"));
        checkBox3_6->setGeometry(QRect(93, 60, 71, 16));
        checkBox3_5 = new QCheckBox(groupBox_4);
        checkBox3_5->setObjectName(QString::fromUtf8("checkBox3_5"));
        checkBox3_5->setGeometry(QRect(43, 60, 71, 16));
        checkBox3_7 = new QCheckBox(groupBox_4);
        checkBox3_7->setObjectName(QString::fromUtf8("checkBox3_7"));
        checkBox3_7->setGeometry(QRect(43, 80, 71, 16));
        checkBox3_8 = new QCheckBox(groupBox_4);
        checkBox3_8->setObjectName(QString::fromUtf8("checkBox3_8"));
        checkBox3_8->setGeometry(QRect(93, 80, 71, 16));
        groupBox_3 = new QGroupBox(groupBox_6);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(189, 20, 161, 111));
        label_10 = new QLabel(groupBox_3);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(4, 20, 54, 12));
        label_11 = new QLabel(groupBox_3);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(4, 60, 54, 12));
        checkBox2_1 = new QCheckBox(groupBox_3);
        checkBox2_1->setObjectName(QString::fromUtf8("checkBox2_1"));
        checkBox2_1->setGeometry(QRect(43, 20, 71, 16));
        checkBox2_2 = new QCheckBox(groupBox_3);
        checkBox2_2->setObjectName(QString::fromUtf8("checkBox2_2"));
        checkBox2_2->setGeometry(QRect(93, 20, 71, 16));
        checkBox2_3 = new QCheckBox(groupBox_3);
        checkBox2_3->setObjectName(QString::fromUtf8("checkBox2_3"));
        checkBox2_3->setGeometry(QRect(43, 40, 71, 16));
        checkBox2_4 = new QCheckBox(groupBox_3);
        checkBox2_4->setObjectName(QString::fromUtf8("checkBox2_4"));
        checkBox2_4->setGeometry(QRect(93, 40, 71, 16));
        checkBox2_6 = new QCheckBox(groupBox_3);
        checkBox2_6->setObjectName(QString::fromUtf8("checkBox2_6"));
        checkBox2_6->setGeometry(QRect(93, 60, 71, 16));
        checkBox2_5 = new QCheckBox(groupBox_3);
        checkBox2_5->setObjectName(QString::fromUtf8("checkBox2_5"));
        checkBox2_5->setGeometry(QRect(43, 60, 71, 16));
        checkBox2_7 = new QCheckBox(groupBox_3);
        checkBox2_7->setObjectName(QString::fromUtf8("checkBox2_7"));
        checkBox2_7->setGeometry(QRect(43, 80, 71, 16));
        checkBox2_8 = new QCheckBox(groupBox_3);
        checkBox2_8->setObjectName(QString::fromUtf8("checkBox2_8"));
        checkBox2_8->setGeometry(QRect(93, 80, 71, 16));
        groupBox_2 = new QGroupBox(groupBox_6);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(15, 20, 161, 111));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(4, 20, 54, 12));
        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(4, 60, 54, 12));
        checkBox1_1 = new QCheckBox(groupBox_2);
        checkBox1_1->setObjectName(QString::fromUtf8("checkBox1_1"));
        checkBox1_1->setGeometry(QRect(43, 20, 71, 16));
        checkBox1_2 = new QCheckBox(groupBox_2);
        checkBox1_2->setObjectName(QString::fromUtf8("checkBox1_2"));
        checkBox1_2->setGeometry(QRect(93, 20, 71, 16));
        checkBox1_3 = new QCheckBox(groupBox_2);
        checkBox1_3->setObjectName(QString::fromUtf8("checkBox1_3"));
        checkBox1_3->setGeometry(QRect(43, 40, 71, 16));
        checkBox1_4 = new QCheckBox(groupBox_2);
        checkBox1_4->setObjectName(QString::fromUtf8("checkBox1_4"));
        checkBox1_4->setGeometry(QRect(93, 40, 71, 16));
        checkBox1_6 = new QCheckBox(groupBox_2);
        checkBox1_6->setObjectName(QString::fromUtf8("checkBox1_6"));
        checkBox1_6->setGeometry(QRect(93, 60, 71, 16));
        checkBox1_5 = new QCheckBox(groupBox_2);
        checkBox1_5->setObjectName(QString::fromUtf8("checkBox1_5"));
        checkBox1_5->setGeometry(QRect(43, 60, 71, 16));
        checkBox1_7 = new QCheckBox(groupBox_2);
        checkBox1_7->setObjectName(QString::fromUtf8("checkBox1_7"));
        checkBox1_7->setGeometry(QRect(43, 80, 71, 16));
        checkBox1_8 = new QCheckBox(groupBox_2);
        checkBox1_8->setObjectName(QString::fromUtf8("checkBox1_8"));
        checkBox1_8->setGeometry(QRect(93, 80, 71, 16));
        checkBox = new QCheckBox(groupBox_6);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(340, 140, 61, 16));
        spininstruction = new QSpinBox(DialogContrlParm);
        spininstruction->setObjectName(QString::fromUtf8("spininstruction"));
        spininstruction->setGeometry(QRect(420, 179, 70, 30));
        spininstruction->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));
        spininstruction->setMaximum(16);
        label_4 = new QLabel(DialogContrlParm);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(438, 134, 120, 30));
        label_4->setStyleSheet(QString::fromUtf8("font: 13pt \"\351\273\221\344\275\223\";\n"
"color:red;\357\277\275"));
        label_7 = new QLabel(DialogContrlParm);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(320, 178, 100, 30));
        label_7->setStyleSheet(QString::fromUtf8("font: 13pt \"\351\273\221\344\275\223\";\n"
"color:red;\357\277\275"));
        spinmodel = new QSpinBox(DialogContrlParm);
        spinmodel->setObjectName(QString::fromUtf8("spinmodel"));
        spinmodel->setGeometry(QRect(650, 179, 70, 30));
        spinmodel->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));
        spinmodel->setMaximum(13);
        label_2 = new QLabel(DialogContrlParm);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(430, 13, 120, 30));
        label_2->setStyleSheet(QString::fromUtf8("font: 13pt \"\351\273\221\344\275\223\";\n"
"color:red;\357\277\275"));
        label_5 = new QLabel(DialogContrlParm);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(98, 134, 121, 30));
        label_5->setStyleSheet(QString::fromUtf8("font: 13pt \"\351\273\221\344\275\223\";\n"
"color:red;\357\277\275"));
        spinManual = new QSpinBox(DialogContrlParm);
        spinManual->setObjectName(QString::fromUtf8("spinManual"));
        spinManual->setGeometry(QRect(251, 13, 120, 30));
        spinManual->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));
        spinManual->setMaximum(255);
        spincycletime = new QSpinBox(DialogContrlParm);
        spincycletime->setObjectName(QString::fromUtf8("spincycletime"));
        spincycletime->setGeometry(QRect(228, 134, 120, 30));
        spincycletime->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));
        spincycletime->setMaximum(255);
        label_8 = new QLabel(DialogContrlParm);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(550, 178, 100, 30));
        label_8->setStyleSheet(QString::fromUtf8("font: 13pt \"\351\273\221\344\275\223\";\n"
"color:red;\357\277\275"));
        label_6 = new QLabel(DialogContrlParm);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(100, 178, 100, 30));
        label_6->setStyleSheet(QString::fromUtf8("font: 13pt \"\351\273\221\344\275\223\";\n"
"color:red;\357\277\275"));
        groupBox = new QGroupBox(DialogContrlParm);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(90, 40, 631, 81));
        groupBox->setStyleSheet(QString::fromUtf8("font: 11pt \"\351\273\221\344\275\223\";\n"
"color:red;\357\277\275"));
        radioclose = new QRadioButton(groupBox);
        radioclose->setObjectName(QString::fromUtf8("radioclose"));
        radioclose->setGeometry(QRect(60, 20, 71, 21));
        radioflash = new QRadioButton(groupBox);
        radioflash->setObjectName(QString::fromUtf8("radioflash"));
        radioflash->setGeometry(QRect(170, 20, 71, 21));
        radioallred = new QRadioButton(groupBox);
        radioallred->setObjectName(QString::fromUtf8("radioallred"));
        radioallred->setGeometry(QRect(290, 20, 71, 21));
        radiofeel = new QRadioButton(groupBox);
        radiofeel->setObjectName(QString::fromUtf8("radiofeel"));
        radiofeel->setGeometry(QRect(400, 20, 71, 21));
        radiosinglebetter = new QRadioButton(groupBox);
        radiosinglebetter->setObjectName(QString::fromUtf8("radiosinglebetter"));
        radiosinglebetter->setGeometry(QRect(60, 47, 110, 20));
        radiomasterlinecontrl = new QRadioButton(groupBox);
        radiomasterlinecontrl->setObjectName(QString::fromUtf8("radiomasterlinecontrl"));
        radiomasterlinecontrl->setGeometry(QRect(200, 47, 110, 20));
        radiosystembetter = new QRadioButton(groupBox);
        radiosystembetter->setObjectName(QString::fromUtf8("radiosystembetter"));
        radiosystembetter->setGeometry(QRect(330, 47, 110, 20));
        radiointerventionlinecontrl = new QRadioButton(groupBox);
        radiointerventionlinecontrl->setObjectName(QString::fromUtf8("radiointerventionlinecontrl"));
        radiointerventionlinecontrl->setGeometry(QRect(470, 47, 110, 20));
        radionull = new QRadioButton(groupBox);
        radionull->setObjectName(QString::fromUtf8("radionull"));
        radionull->setGeometry(QRect(510, 20, 71, 21));
        display = new QLabel(DialogContrlParm);
        display->setObjectName(QString::fromUtf8("display"));
        display->setGeometry(QRect(351, 378, 121, 31));
        butfind = new QPushButton(DialogContrlParm);
        butfind->setObjectName(QString::fromUtf8("butfind"));
        butfind->setGeometry(QRect(290, 410, 75, 23));
        butok = new QPushButton(DialogContrlParm);
        butok->setObjectName(QString::fromUtf8("butok"));
        butok->setGeometry(QRect(460, 410, 75, 23));
        comboBoxplan = new QComboBox(DialogContrlParm);
        comboBoxplan->setObjectName(QString::fromUtf8("comboBoxplan"));
        comboBoxplan->setGeometry(QRect(570, 12, 111, 31));

        retranslateUi(DialogContrlParm);

        QMetaObject::connectSlotsByName(DialogContrlParm);
    } // setupUi

    void retranslateUi(QDialog *DialogContrlParm)
    {
        DialogContrlParm->setWindowTitle(QApplication::translate("DialogContrlParm", "\346\216\247\345\210\266\346\226\271\346\241\210\350\241\250", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("DialogContrlParm", "\346\211\213\345\212\250\346\216\247\345\210\266\346\226\271\346\241\210", 0, QApplication::UnicodeUTF8));
        groupBox_6->setTitle(QApplication::translate("DialogContrlParm", "\345\200\222\350\256\241\347\211\214\345\261\236\346\200\247", 0, QApplication::UnicodeUTF8));
        groupBox_5->setTitle(QApplication::translate("DialogContrlParm", "\351\251\261\345\212\250\346\235\2774", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("DialogContrlParm", "\345\200\222\344\270\200", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("DialogContrlParm", "\345\200\222\344\272\214", 0, QApplication::UnicodeUTF8));
        checkBox4_1->setText(QApplication::translate("DialogContrlParm", "\351\200\232\351\201\2231", 0, QApplication::UnicodeUTF8));
        checkBox4_2->setText(QApplication::translate("DialogContrlParm", "\351\200\232\351\201\2232", 0, QApplication::UnicodeUTF8));
        checkBox4_3->setText(QApplication::translate("DialogContrlParm", "\351\200\232\351\201\2233", 0, QApplication::UnicodeUTF8));
        checkBox4_4->setText(QApplication::translate("DialogContrlParm", "\351\200\232\351\201\2234", 0, QApplication::UnicodeUTF8));
        checkBox4_6->setText(QApplication::translate("DialogContrlParm", "\351\200\232\351\201\2232", 0, QApplication::UnicodeUTF8));
        checkBox4_5->setText(QApplication::translate("DialogContrlParm", "\351\200\232\351\201\2231", 0, QApplication::UnicodeUTF8));
        checkBox4_7->setText(QApplication::translate("DialogContrlParm", "\351\200\232\351\201\2233", 0, QApplication::UnicodeUTF8));
        checkBox4_8->setText(QApplication::translate("DialogContrlParm", "\351\200\232\351\201\2234", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("DialogContrlParm", "\351\251\261\345\212\250\346\235\2773", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("DialogContrlParm", "\345\200\222\344\270\200", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("DialogContrlParm", "\345\200\222\344\272\214", 0, QApplication::UnicodeUTF8));
        checkBox3_1->setText(QApplication::translate("DialogContrlParm", "\351\200\232\351\201\2231", 0, QApplication::UnicodeUTF8));
        checkBox3_2->setText(QApplication::translate("DialogContrlParm", "\351\200\232\351\201\2232", 0, QApplication::UnicodeUTF8));
        checkBox3_3->setText(QApplication::translate("DialogContrlParm", "\351\200\232\351\201\2233", 0, QApplication::UnicodeUTF8));
        checkBox3_4->setText(QApplication::translate("DialogContrlParm", "\351\200\232\351\201\2234", 0, QApplication::UnicodeUTF8));
        checkBox3_6->setText(QApplication::translate("DialogContrlParm", "\351\200\232\351\201\2232", 0, QApplication::UnicodeUTF8));
        checkBox3_5->setText(QApplication::translate("DialogContrlParm", "\351\200\232\351\201\2231", 0, QApplication::UnicodeUTF8));
        checkBox3_7->setText(QApplication::translate("DialogContrlParm", "\351\200\232\351\201\2233", 0, QApplication::UnicodeUTF8));
        checkBox3_8->setText(QApplication::translate("DialogContrlParm", "\351\200\232\351\201\2234", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("DialogContrlParm", "\351\251\261\345\212\250\346\235\2772", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("DialogContrlParm", "\345\200\222\344\270\200", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("DialogContrlParm", "\345\200\222\344\272\214", 0, QApplication::UnicodeUTF8));
        checkBox2_1->setText(QApplication::translate("DialogContrlParm", "\351\200\232\351\201\2231", 0, QApplication::UnicodeUTF8));
        checkBox2_2->setText(QApplication::translate("DialogContrlParm", "\351\200\232\351\201\2232", 0, QApplication::UnicodeUTF8));
        checkBox2_3->setText(QApplication::translate("DialogContrlParm", "\351\200\232\351\201\2233", 0, QApplication::UnicodeUTF8));
        checkBox2_4->setText(QApplication::translate("DialogContrlParm", "\351\200\232\351\201\2234", 0, QApplication::UnicodeUTF8));
        checkBox2_6->setText(QApplication::translate("DialogContrlParm", "\351\200\232\351\201\2232", 0, QApplication::UnicodeUTF8));
        checkBox2_5->setText(QApplication::translate("DialogContrlParm", "\351\200\232\351\201\2231", 0, QApplication::UnicodeUTF8));
        checkBox2_7->setText(QApplication::translate("DialogContrlParm", "\351\200\232\351\201\2233", 0, QApplication::UnicodeUTF8));
        checkBox2_8->setText(QApplication::translate("DialogContrlParm", "\351\200\232\351\201\2234", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("DialogContrlParm", "\351\251\261\345\212\250\346\235\2771", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("DialogContrlParm", "\345\200\222\344\270\200", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("DialogContrlParm", "\345\200\222\344\272\214", 0, QApplication::UnicodeUTF8));
        checkBox1_1->setText(QApplication::translate("DialogContrlParm", "\351\200\232\351\201\2231", 0, QApplication::UnicodeUTF8));
        checkBox1_2->setText(QApplication::translate("DialogContrlParm", "\351\200\232\351\201\2232", 0, QApplication::UnicodeUTF8));
        checkBox1_3->setText(QApplication::translate("DialogContrlParm", "\351\200\232\351\201\2233", 0, QApplication::UnicodeUTF8));
        checkBox1_4->setText(QApplication::translate("DialogContrlParm", "\351\200\232\351\201\2234", 0, QApplication::UnicodeUTF8));
        checkBox1_6->setText(QApplication::translate("DialogContrlParm", "\351\200\232\351\201\2232", 0, QApplication::UnicodeUTF8));
        checkBox1_5->setText(QApplication::translate("DialogContrlParm", "\351\200\232\351\201\2231", 0, QApplication::UnicodeUTF8));
        checkBox1_7->setText(QApplication::translate("DialogContrlParm", "\351\200\232\351\201\2233", 0, QApplication::UnicodeUTF8));
        checkBox1_8->setText(QApplication::translate("DialogContrlParm", "\351\200\232\351\201\2234", 0, QApplication::UnicodeUTF8));
        checkBox->setText(QApplication::translate("DialogContrlParm", "\345\205\250\351\200\211", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("DialogContrlParm", "\345\215\217\350\260\203\347\233\270\344\275\215\345\267\256", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("DialogContrlParm", "\346\255\245\350\277\233\346\214\207\344\273\244", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("DialogContrlParm", "\347\263\273\347\273\237\346\216\247\345\210\266\346\226\271\346\241\210", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("DialogContrlParm", "\345\205\254\345\205\261\345\221\250\346\234\237\346\227\266\351\225\277", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("DialogContrlParm", "\351\231\215\347\272\247\346\250\241\345\274\217", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("DialogContrlParm", "\351\230\266\346\256\265\347\212\266\346\200\201", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("DialogContrlParm", "\346\216\247\345\210\266\346\226\271\345\274\217", 0, QApplication::UnicodeUTF8));
        radioclose->setText(QApplication::translate("DialogContrlParm", "\345\205\263\347\201\257", 0, QApplication::UnicodeUTF8));
        radioflash->setText(QApplication::translate("DialogContrlParm", "\351\227\252\345\205\211", 0, QApplication::UnicodeUTF8));
        radioallred->setText(QApplication::translate("DialogContrlParm", "\345\205\250\347\272\242", 0, QApplication::UnicodeUTF8));
        radiofeel->setText(QApplication::translate("DialogContrlParm", "\346\204\237\345\272\224", 0, QApplication::UnicodeUTF8));
        radiosinglebetter->setText(QApplication::translate("DialogContrlParm", "\345\215\225\347\202\271\344\274\230\345\214\226", 0, QApplication::UnicodeUTF8));
        radiomasterlinecontrl->setText(QApplication::translate("DialogContrlParm", "\344\270\273\344\273\216\347\272\277\346\216\247", 0, QApplication::UnicodeUTF8));
        radiosystembetter->setText(QApplication::translate("DialogContrlParm", "\347\263\273\347\273\237\344\274\230\345\214\226", 0, QApplication::UnicodeUTF8));
        radiointerventionlinecontrl->setText(QApplication::translate("DialogContrlParm", "\345\271\262\351\242\204\347\272\277\346\216\247", 0, QApplication::UnicodeUTF8));
        radionull->setText(QApplication::translate("DialogContrlParm", "\347\251\272", 0, QApplication::UnicodeUTF8));
        display->setText(QString());
        butfind->setText(QApplication::translate("DialogContrlParm", "\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
        butok->setText(QApplication::translate("DialogContrlParm", "\344\277\256\346\224\271", 0, QApplication::UnicodeUTF8));
        comboBoxplan->clear();
        comboBoxplan->insertItems(0, QStringList()
         << QApplication::translate("DialogContrlParm", "\350\207\252\344\270\273\346\216\247\345\210\266", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DialogContrlParm", "\351\205\215\346\227\266\346\226\271\346\241\2101", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DialogContrlParm", "\351\205\215\346\227\266\346\226\271\346\241\2102", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DialogContrlParm", "\351\205\215\346\227\266\346\226\271\346\241\2103", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DialogContrlParm", "\351\205\215\346\227\266\346\226\271\346\241\2104", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DialogContrlParm", "\351\205\215\346\227\266\346\226\271\346\241\2105", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DialogContrlParm", "\351\205\215\346\227\266\346\226\271\346\241\2106", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DialogContrlParm", "\351\205\215\346\227\266\346\226\271\346\241\2107", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DialogContrlParm", "\351\205\215\346\227\266\346\226\271\346\241\2108", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DialogContrlParm", "\351\205\215\346\227\266\346\226\271\346\241\2109", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DialogContrlParm", "\351\205\215\346\227\266\346\226\271\346\241\21010", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DialogContrlParm", "\351\205\215\346\227\266\346\226\271\346\241\21011", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DialogContrlParm", "\351\205\215\346\227\266\346\226\271\346\241\21012", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DialogContrlParm", "\351\205\215\346\227\266\346\226\271\346\241\21013", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DialogContrlParm", "\351\205\215\346\227\266\346\226\271\346\241\21014", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DialogContrlParm", "\351\205\215\346\227\266\346\226\271\346\241\21015", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DialogContrlParm", "\351\205\215\346\227\266\346\226\271\346\241\21016", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DialogContrlParm", "\351\205\215\346\227\266\346\226\271\346\241\21017", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DialogContrlParm", "\351\205\215\346\227\266\346\226\271\346\241\21018", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DialogContrlParm", "\351\205\215\346\227\266\346\226\271\346\241\21019", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DialogContrlParm", "\351\205\215\346\227\266\346\226\271\346\241\21020", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DialogContrlParm", "\351\205\215\346\227\266\346\226\271\346\241\21021", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DialogContrlParm", "\351\205\215\346\227\266\346\226\271\346\241\21022", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DialogContrlParm", "\351\205\215\346\227\266\346\226\271\346\241\21023", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DialogContrlParm", "\351\205\215\346\227\266\346\226\271\346\241\21024", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DialogContrlParm", "\351\205\215\346\227\266\346\226\271\346\241\21025", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DialogContrlParm", "\351\205\215\346\227\266\346\226\271\346\241\21026", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DialogContrlParm", "\351\205\215\346\227\266\346\226\271\346\241\21027", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DialogContrlParm", "\351\205\215\346\227\266\346\226\271\346\241\21028", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DialogContrlParm", "\351\205\215\346\227\266\346\226\271\346\241\21029", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DialogContrlParm", "\351\205\215\346\227\266\346\226\271\346\241\21030", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DialogContrlParm", "\351\205\215\346\227\266\346\226\271\346\241\21031", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DialogContrlParm", "\351\205\215\346\227\266\346\226\271\346\241\21032", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DialogContrlParm", "\345\205\250\347\272\242", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DialogContrlParm", "\351\227\252\345\205\211", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DialogContrlParm", "\345\205\263\347\201\257", 0, QApplication::UnicodeUTF8)
        );
    } // retranslateUi

};

namespace Ui {
    class DialogContrlParm: public Ui_DialogContrlParm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGCONTRLPARM_H
