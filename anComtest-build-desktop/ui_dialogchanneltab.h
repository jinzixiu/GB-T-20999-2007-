/********************************************************************************
** Form generated from reading UI file 'dialogchanneltab.ui'
**
** Created: Sat Sep 13 18:15:00 2014
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGCHANNELTAB_H
#define UI_DIALOGCHANNELTAB_H

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
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_DialogChanneltab
{
public:
    QSpinBox *spinChannelNum;
    QLabel *label_5;
    QLabel *label_6;
    QPushButton *butquery;
    QLineEdit *ChannelSignSour;
    QCheckBox *checkBox;
    QPushButton *butclearall;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_2;
    QLabel *label_4;
    QLabel *label_8;
    QLabel *hang;
    QFrame *line;
    QFrame *line_2;
    QPushButton *butfind;
    QPushButton *butok;
    QPushButton *butcleaer;
    QLabel *display;
    QGroupBox *groupBox;
    QRadioButton *NULL1;
    QRadioButton *dir1;
    QRadioButton *dir2;
    QRadioButton *dir3;
    QRadioButton *dir4;
    QRadioButton *dir7;
    QRadioButton *dir6;
    QRadioButton *dir8;
    QRadioButton *dir5;
    QGroupBox *groupBox_2;
    QRadioButton *flash1;
    QRadioButton *flash3;
    QRadioButton *flash4;
    QRadioButton *flash5;
    QRadioButton *flash6;
    QRadioButton *flash7;
    QRadioButton *flash8;
    QRadioButton *flash9;
    QRadioButton *NULL2;

    void setupUi(QDialog *DialogChanneltab)
    {
        if (DialogChanneltab->objectName().isEmpty())
            DialogChanneltab->setObjectName(QString::fromUtf8("DialogChanneltab"));
        DialogChanneltab->resize(800, 450);
        spinChannelNum = new QSpinBox(DialogChanneltab);
        spinChannelNum->setObjectName(QString::fromUtf8("spinChannelNum"));
        spinChannelNum->setGeometry(QRect(252, 45, 101, 31));
        spinChannelNum->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));
        spinChannelNum->setMinimum(1);
        spinChannelNum->setMaximum(16);
        label_5 = new QLabel(DialogChanneltab);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(404, 50, 111, 20));
        label_5->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";\n"
""));
        label_6 = new QLabel(DialogChanneltab);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(219, 110, 141, 31));
        label_6->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));
        butquery = new QPushButton(DialogChanneltab);
        butquery->setObjectName(QString::fromUtf8("butquery"));
        butquery->setGeometry(QRect(486, 323, 41, 41));
        ChannelSignSour = new QLineEdit(DialogChanneltab);
        ChannelSignSour->setObjectName(QString::fromUtf8("ChannelSignSour"));
        ChannelSignSour->setGeometry(QRect(517, 45, 111, 31));
        ChannelSignSour->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));
        checkBox = new QCheckBox(DialogChanneltab);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(449, 110, 291, 30));
        checkBox->setStyleSheet(QString::fromUtf8("font: 12pt \"\351\273\221\344\275\223\";"));
        butclearall = new QPushButton(DialogChanneltab);
        butclearall->setObjectName(QString::fromUtf8("butclearall"));
        butclearall->setGeometry(QRect(546, 323, 41, 41));
        checkBox_3 = new QCheckBox(DialogChanneltab);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));
        checkBox_3->setGeometry(QRect(450, 180, 211, 30));
        checkBox_3->setStyleSheet(QString::fromUtf8("font: 12pt \"\351\273\221\344\275\223\";"));
        checkBox_2 = new QCheckBox(DialogChanneltab);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setGeometry(QRect(449, 145, 231, 30));
        checkBox_2->setStyleSheet(QString::fromUtf8("font: 12pt \"\351\273\221\344\275\223\";"));
        label_4 = new QLabel(DialogChanneltab);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(121, 52, 121, 20));
        label_4->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));
        label_8 = new QLabel(DialogChanneltab);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(230, 336, 91, 20));
        label_8->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));
        hang = new QLabel(DialogChanneltab);
        hang->setObjectName(QString::fromUtf8("hang"));
        hang->setGeometry(QRect(370, 330, 61, 31));
        hang->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));
        line = new QFrame(DialogChanneltab);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(31, 304, 741, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(DialogChanneltab);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(37, 25, 731, 20));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        butfind = new QPushButton(DialogChanneltab);
        butfind->setObjectName(QString::fromUtf8("butfind"));
        butfind->setGeometry(QRect(220, 370, 71, 31));
        butok = new QPushButton(DialogChanneltab);
        butok->setObjectName(QString::fromUtf8("butok"));
        butok->setGeometry(QRect(380, 370, 71, 31));
        butcleaer = new QPushButton(DialogChanneltab);
        butcleaer->setObjectName(QString::fromUtf8("butcleaer"));
        butcleaer->setGeometry(QRect(540, 370, 71, 31));
        display = new QLabel(DialogChanneltab);
        display->setObjectName(QString::fromUtf8("display"));
        display->setGeometry(QRect(370, 400, 91, 31));
        groupBox = new QGroupBox(DialogChanneltab);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(400, 230, 351, 61));
        groupBox->setStyleSheet(QString::fromUtf8("font: 12pt \"\351\273\221\344\275\223\";"));
        NULL1 = new QRadioButton(groupBox);
        NULL1->setObjectName(QString::fromUtf8("NULL1"));
        NULL1->setGeometry(QRect(300, 24, 61, 20));
        dir1 = new QRadioButton(groupBox);
        dir1->setObjectName(QString::fromUtf8("dir1"));
        dir1->setGeometry(QRect(20, 24, 39, 20));
        dir2 = new QRadioButton(groupBox);
        dir2->setObjectName(QString::fromUtf8("dir2"));
        dir2->setGeometry(QRect(92, 24, 39, 20));
        dir3 = new QRadioButton(groupBox);
        dir3->setObjectName(QString::fromUtf8("dir3"));
        dir3->setGeometry(QRect(163, 24, 39, 20));
        dir4 = new QRadioButton(groupBox);
        dir4->setObjectName(QString::fromUtf8("dir4"));
        dir4->setGeometry(QRect(235, 24, 39, 20));
        dir7 = new QRadioButton(groupBox);
        dir7->setObjectName(QString::fromUtf8("dir7"));
        dir7->setEnabled(false);
        dir7->setGeometry(QRect(163, 100, 55, 20));
        dir6 = new QRadioButton(groupBox);
        dir6->setObjectName(QString::fromUtf8("dir6"));
        dir6->setEnabled(false);
        dir6->setGeometry(QRect(92, 100, 55, 20));
        dir8 = new QRadioButton(groupBox);
        dir8->setObjectName(QString::fromUtf8("dir8"));
        dir8->setEnabled(false);
        dir8->setGeometry(QRect(235, 100, 55, 20));
        dir5 = new QRadioButton(groupBox);
        dir5->setObjectName(QString::fromUtf8("dir5"));
        dir5->setEnabled(false);
        dir5->setGeometry(QRect(20, 99, 55, 20));
        groupBox_2 = new QGroupBox(DialogChanneltab);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(50, 160, 311, 131));
        groupBox_2->setStyleSheet(QString::fromUtf8("font: 12pt \"\351\273\221\344\275\223\";"));
        flash1 = new QRadioButton(groupBox_2);
        flash1->setObjectName(QString::fromUtf8("flash1"));
        flash1->setEnabled(false);
        flash1->setGeometry(QRect(20, 25, 89, 16));
        flash3 = new QRadioButton(groupBox_2);
        flash3->setObjectName(QString::fromUtf8("flash3"));
        flash3->setGeometry(QRect(123, 25, 89, 16));
        flash4 = new QRadioButton(groupBox_2);
        flash4->setObjectName(QString::fromUtf8("flash4"));
        flash4->setEnabled(false);
        flash4->setGeometry(QRect(226, 25, 89, 16));
        flash5 = new QRadioButton(groupBox_2);
        flash5->setObjectName(QString::fromUtf8("flash5"));
        flash5->setGeometry(QRect(35, 49, 89, 16));
        flash6 = new QRadioButton(groupBox_2);
        flash6->setObjectName(QString::fromUtf8("flash6"));
        flash6->setGeometry(QRect(178, 48, 111, 16));
        flash7 = new QRadioButton(groupBox_2);
        flash7->setObjectName(QString::fromUtf8("flash7"));
        flash7->setGeometry(QRect(35, 71, 101, 16));
        flash8 = new QRadioButton(groupBox_2);
        flash8->setObjectName(QString::fromUtf8("flash8"));
        flash8->setGeometry(QRect(178, 71, 101, 16));
        flash9 = new QRadioButton(groupBox_2);
        flash9->setObjectName(QString::fromUtf8("flash9"));
        flash9->setGeometry(QRect(35, 95, 111, 16));
        NULL2 = new QRadioButton(groupBox_2);
        NULL2->setObjectName(QString::fromUtf8("NULL2"));
        NULL2->setGeometry(QRect(178, 93, 89, 21));

        retranslateUi(DialogChanneltab);

        QMetaObject::connectSlotsByName(DialogChanneltab);
    } // setupUi

    void retranslateUi(QDialog *DialogChanneltab)
    {
        DialogChanneltab->setWindowTitle(QApplication::translate("DialogChanneltab", "\351\200\232\351\201\223\350\241\250", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("DialogChanneltab", "\351\200\232\351\201\223\344\277\241\345\217\267\346\272\220", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("DialogChanneltab", "Flash\351\200\232\351\201\223\347\212\266\346\200\201", 0, QApplication::UnicodeUTF8));
        butquery->setText(QApplication::translate("DialogChanneltab", "\346\237\245\350\257\242\n"
"\345\267\262\350\256\276", 0, QApplication::UnicodeUTF8));
        checkBox->setText(QApplication::translate("DialogChanneltab", "\351\200\211\344\270\255\345\220\216\345\215\212\347\247\222\344\272\256\347\201\257/\344\270\215\351\200\211\344\270\255\345\211\215\345\215\212\347\247\222\344\272\256\347\201\257", 0, QApplication::UnicodeUTF8));
        butclearall->setText(QApplication::translate("DialogChanneltab", "\346\270\205\347\251\272\n"
"\345\205\250\350\241\250", 0, QApplication::UnicodeUTF8));
        checkBox_3->setText(QApplication::translate("DialogChanneltab", "\351\200\211\344\270\255\351\273\204\351\227\252/\344\270\215\351\200\211\344\270\255\351\273\204\347\201\257\345\205\263\347\201\257", 0, QApplication::UnicodeUTF8));
        checkBox_2->setText(QApplication::translate("DialogChanneltab", "\351\200\211\344\270\255\347\272\242\351\227\252/\344\270\215\351\200\211\344\270\255\347\272\242\347\201\257\345\205\263\347\201\257", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("DialogChanneltab", "\351\200\232\351\201\223\345\217\267(1-16)", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("DialogChanneltab", "\345\267\262\350\256\276\350\241\214\346\225\260", 0, QApplication::UnicodeUTF8));
        hang->setText(QString());
        butfind->setText(QApplication::translate("DialogChanneltab", "\346\237\245 \350\257\242", 0, QApplication::UnicodeUTF8));
        butok->setText(QApplication::translate("DialogChanneltab", "\344\277\256 \346\224\271", 0, QApplication::UnicodeUTF8));
        butcleaer->setText(QApplication::translate("DialogChanneltab", "\346\270\205\347\251\272\350\241\214", 0, QApplication::UnicodeUTF8));
        display->setText(QString());
        groupBox->setTitle(QApplication::translate("DialogChanneltab", "\346\226\271\345\220\221", 0, QApplication::UnicodeUTF8));
        NULL1->setText(QApplication::translate("DialogChanneltab", "\347\251\272", 0, QApplication::UnicodeUTF8));
        dir1->setText(QApplication::translate("DialogChanneltab", "\344\270\234", 0, QApplication::UnicodeUTF8));
        dir2->setText(QApplication::translate("DialogChanneltab", "\345\215\227", 0, QApplication::UnicodeUTF8));
        dir3->setText(QApplication::translate("DialogChanneltab", "\350\245\277", 0, QApplication::UnicodeUTF8));
        dir4->setText(QApplication::translate("DialogChanneltab", "\345\214\227", 0, QApplication::UnicodeUTF8));
        dir7->setText(QApplication::translate("DialogChanneltab", "\350\245\277\345\214\227", 0, QApplication::UnicodeUTF8));
        dir6->setText(QApplication::translate("DialogChanneltab", "\350\245\277\345\215\227", 0, QApplication::UnicodeUTF8));
        dir8->setText(QApplication::translate("DialogChanneltab", "\350\245\277\345\215\227", 0, QApplication::UnicodeUTF8));
        dir5->setText(QApplication::translate("DialogChanneltab", "\344\270\234\345\215\227", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("DialogChanneltab", "\347\201\257\347\247\215", 0, QApplication::UnicodeUTF8));
        flash1->setText(QApplication::translate("DialogChanneltab", "\345\205\266\344\273\226\347\201\257", 0, QApplication::UnicodeUTF8));
        flash3->setText(QApplication::translate("DialogChanneltab", "\350\241\214\344\272\272\347\201\257", 0, QApplication::UnicodeUTF8));
        flash4->setText(QApplication::translate("DialogChanneltab", "\350\267\237\351\232\217\347\201\257", 0, QApplication::UnicodeUTF8));
        flash5->setText(QApplication::translate("DialogChanneltab", "\345\234\206\346\234\272\345\212\250\347\201\257", 0, QApplication::UnicodeUTF8));
        flash6->setText(QApplication::translate("DialogChanneltab", "\347\233\264\350\241\214\346\234\272\345\212\250\347\201\257", 0, QApplication::UnicodeUTF8));
        flash7->setText(QApplication::translate("DialogChanneltab", "\345\267\246\350\275\254\346\234\272\345\212\250\347\201\257", 0, QApplication::UnicodeUTF8));
        flash8->setText(QApplication::translate("DialogChanneltab", "\345\217\263\350\275\254\346\234\272\345\212\250\347\201\257", 0, QApplication::UnicodeUTF8));
        flash9->setText(QApplication::translate("DialogChanneltab", "\346\216\211\345\244\264\346\234\272\345\212\250\347\201\257", 0, QApplication::UnicodeUTF8));
        NULL2->setText(QApplication::translate("DialogChanneltab", "\347\251\272", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DialogChanneltab: public Ui_DialogChanneltab {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGCHANNELTAB_H
