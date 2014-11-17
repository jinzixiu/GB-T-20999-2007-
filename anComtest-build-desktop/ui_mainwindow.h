/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sat Sep 13 17:30:43 2014
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *showtimeinterval;
    QPushButton *pushButton;
    QPushButton *showtimebase;
    QPushButton *showchanneltab;
    QPushButton *showtimingplan;
    QPushButton *showphaseparm;
    QPushButton *opencom;
    QPushButton *showPubParm;
    QLabel *label;
    QPushButton *showContrlParm;
    QLabel *label_2;
    QPushButton *showphasestatus;
    QPushButton *showUnitParm;
    QComboBox *comboBox;
    QPushButton *showphaseconfli;
    QPushButton *showswitch;
    QPushButton *closecom;
    QPushButton *showphasetiming;
    QComboBox *comboBox_2;
    QLabel *label_3;
    QPushButton *showParmRun;
    QPushButton *showmodeltab;
    QPushButton *showcartest;
    QPushButton *showflowphase;
    QPushButton *showevent;
    QPushButton *status;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 443);
        MainWindow->setDocumentMode(false);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        showtimeinterval = new QPushButton(centralWidget);
        showtimeinterval->setObjectName(QString::fromUtf8("showtimeinterval"));
        showtimeinterval->setGeometry(QRect(270, 90, 100, 40));
        showtimeinterval->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(690, 360, 71, 61));
        pushButton->setStyleSheet(QString::fromUtf8(""));
        showtimebase = new QPushButton(centralWidget);
        showtimebase->setObjectName(QString::fromUtf8("showtimebase"));
        showtimebase->setGeometry(QRect(129, 90, 100, 40));
        showtimebase->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));
        showchanneltab = new QPushButton(centralWidget);
        showchanneltab->setObjectName(QString::fromUtf8("showchanneltab"));
        showchanneltab->setGeometry(QRect(130, 150, 100, 40));
        showchanneltab->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));
        showtimingplan = new QPushButton(centralWidget);
        showtimingplan->setObjectName(QString::fromUtf8("showtimingplan"));
        showtimingplan->setGeometry(QRect(410, 90, 100, 40));
        showtimingplan->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));
        showphaseparm = new QPushButton(centralWidget);
        showphaseparm->setObjectName(QString::fromUtf8("showphaseparm"));
        showphaseparm->setGeometry(QRect(270, 150, 100, 40));
        showphaseparm->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));
        opencom = new QPushButton(centralWidget);
        opencom->setObjectName(QString::fromUtf8("opencom"));
        opencom->setGeometry(QRect(290, 350, 71, 61));
        opencom->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));
        showPubParm = new QPushButton(centralWidget);
        showPubParm->setObjectName(QString::fromUtf8("showPubParm"));
        showPubParm->setGeometry(QRect(101, 210, 101, 40));
        showPubParm->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(67, 335, 61, 21));
        label->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));
        showContrlParm = new QPushButton(centralWidget);
        showContrlParm->setObjectName(QString::fromUtf8("showContrlParm"));
        showContrlParm->setGeometry(QRect(221, 210, 100, 40));
        showContrlParm->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(106, 8, 571, 61));
        label_2->setStyleSheet(QString::fromUtf8("font: 36pt \"\344\273\277\345\256\213\";"));
        label_2->setTextFormat(Qt::AutoText);
        label_2->setAlignment(Qt::AlignCenter);
        showphasestatus = new QPushButton(centralWidget);
        showphasestatus->setObjectName(QString::fromUtf8("showphasestatus"));
        showphasestatus->setEnabled(true);
        showphasestatus->setGeometry(QRect(580, 210, 100, 40));
        showphasestatus->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));
        showUnitParm = new QPushButton(centralWidget);
        showUnitParm->setObjectName(QString::fromUtf8("showUnitParm"));
        showUnitParm->setGeometry(QRect(341, 210, 100, 40));
        showUnitParm->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));
        comboBox = new QComboBox(centralWidget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(146, 330, 81, 31));
        showphaseconfli = new QPushButton(centralWidget);
        showphaseconfli->setObjectName(QString::fromUtf8("showphaseconfli"));
        showphaseconfli->setEnabled(true);
        showphaseconfli->setGeometry(QRect(410, 150, 100, 40));
        showphaseconfli->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));
        showswitch = new QPushButton(centralWidget);
        showswitch->setObjectName(QString::fromUtf8("showswitch"));
        showswitch->setGeometry(QRect(461, 210, 100, 40));
        showswitch->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));
        closecom = new QPushButton(centralWidget);
        closecom->setObjectName(QString::fromUtf8("closecom"));
        closecom->setGeometry(QRect(410, 350, 71, 61));
        closecom->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));
        showphasetiming = new QPushButton(centralWidget);
        showphasetiming->setObjectName(QString::fromUtf8("showphasetiming"));
        showphasetiming->setGeometry(QRect(550, 90, 100, 40));
        showphasetiming->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));
        comboBox_2 = new QComboBox(centralWidget);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setGeometry(QRect(146, 377, 81, 31));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(67, 382, 61, 21));
        label_3->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));
        showParmRun = new QPushButton(centralWidget);
        showParmRun->setObjectName(QString::fromUtf8("showParmRun"));
        showParmRun->setGeometry(QRect(101, 270, 101, 40));
        showParmRun->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));
        showmodeltab = new QPushButton(centralWidget);
        showmodeltab->setObjectName(QString::fromUtf8("showmodeltab"));
        showmodeltab->setGeometry(QRect(221, 270, 101, 40));
        showmodeltab->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));
        showcartest = new QPushButton(centralWidget);
        showcartest->setObjectName(QString::fromUtf8("showcartest"));
        showcartest->setGeometry(QRect(461, 270, 101, 40));
        showcartest->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));
        showflowphase = new QPushButton(centralWidget);
        showflowphase->setObjectName(QString::fromUtf8("showflowphase"));
        showflowphase->setGeometry(QRect(341, 270, 101, 40));
        showflowphase->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));
        showevent = new QPushButton(centralWidget);
        showevent->setObjectName(QString::fromUtf8("showevent"));
        showevent->setGeometry(QRect(581, 270, 101, 40));
        showevent->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));
        status = new QPushButton(centralWidget);
        status->setObjectName(QString::fromUtf8("status"));
        status->setGeometry(QRect(550, 150, 101, 41));
        status->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "[GB/T 20999-2007]\344\277\241\345\217\267\346\216\247\345\210\266\347\273\210\347\253\257(\346\231\213\345\237\216\350\267\257\344\270\260\347\247\221\346\212\200\345\205\254\345\217\270)", 0, QApplication::UnicodeUTF8));
        showtimeinterval->setText(QApplication::translate("MainWindow", "\346\227\266 \346\256\265 \350\241\250", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272", 0, QApplication::UnicodeUTF8));
        showtimebase->setText(QApplication::translate("MainWindow", "\346\227\266\345\237\272\350\260\203\345\272\246", 0, QApplication::UnicodeUTF8));
        showchanneltab->setText(QApplication::translate("MainWindow", "\351\200\232 \351\201\223 \350\241\250", 0, QApplication::UnicodeUTF8));
        showtimingplan->setText(QApplication::translate("MainWindow", "\351\205\215\346\227\266\346\226\271\346\241\210", 0, QApplication::UnicodeUTF8));
        showphaseparm->setText(QApplication::translate("MainWindow", "\347\233\270\344\275\215\345\217\202\346\225\260", 0, QApplication::UnicodeUTF8));
        opencom->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200\n"
"\344\270\262\345\217\243", 0, QApplication::UnicodeUTF8));
        showPubParm->setText(QApplication::translate("MainWindow", "\345\205\254\345\205\261\345\217\202\346\225\260", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "COM\345\217\243", 0, QApplication::UnicodeUTF8));
        showContrlParm->setText(QApplication::translate("MainWindow", "\346\216\247\345\210\266\345\217\202\346\225\260", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        label_2->setWhatsThis(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'\344\273\277\345\256\213'; font-size:36pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"></p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        label_2->setText(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'\344\273\277\345\256\213'; font-size:36pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">\344\277\241 \345\217\267 \347\201\257 \346\216\247 \345\210\266 \347\273\210 \347\253\257</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        showphasestatus->setText(QApplication::translate("MainWindow", "\347\233\270\344\275\215\347\212\266\346\200\201", 0, QApplication::UnicodeUTF8));
        showUnitParm->setText(QApplication::translate("MainWindow", "\345\215\225\345\205\203\345\217\202\346\225\260", 0, QApplication::UnicodeUTF8));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "COM1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "COM2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "COM3", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "COM4", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "COM5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "COM6", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "COM7", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "COM8", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "COM9", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "COM10", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "COM11", 0, QApplication::UnicodeUTF8)
        );
        showphaseconfli->setText(QApplication::translate("MainWindow", "\347\233\270\344\275\215\345\206\262\347\252\201", 0, QApplication::UnicodeUTF8));
        showswitch->setText(QApplication::translate("MainWindow", "\351\203\250\345\210\206\345\274\200\345\205\263", 0, QApplication::UnicodeUTF8));
        closecom->setText(QApplication::translate("MainWindow", "\345\205\263\351\227\255\n"
"\344\270\262\345\217\243", 0, QApplication::UnicodeUTF8));
        showphasetiming->setText(QApplication::translate("MainWindow", "\351\230\266\346\256\265\351\205\215\346\227\266", 0, QApplication::UnicodeUTF8));
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "1200", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "2400", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "4800", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "9600", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "19200", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "38400", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "57600", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "115200", 0, QApplication::UnicodeUTF8)
        );
        label_3->setText(QApplication::translate("MainWindow", "\346\257\224\347\211\271\347\216\207", 0, QApplication::UnicodeUTF8));
        showParmRun->setText(QApplication::translate("MainWindow", "\346\211\247\350\241\214\345\274\200\345\205\263", 0, QApplication::UnicodeUTF8));
        showmodeltab->setText(QApplication::translate("MainWindow", "\346\250\241 \345\235\227 \350\241\250", 0, QApplication::UnicodeUTF8));
        showcartest->setText(QApplication::translate("MainWindow", "\350\275\246 \346\243\200 \350\241\250", 0, QApplication::UnicodeUTF8));
        showflowphase->setText(QApplication::translate("MainWindow", "\350\267\237\351\232\217\347\233\270\344\275\215", 0, QApplication::UnicodeUTF8));
        showevent->setText(QApplication::translate("MainWindow", "\344\272\213 \344\273\266 \350\241\250", 0, QApplication::UnicodeUTF8));
        status->setText(QApplication::translate("MainWindow", "\347\201\257\347\273\204\347\212\266\346\200\201", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
