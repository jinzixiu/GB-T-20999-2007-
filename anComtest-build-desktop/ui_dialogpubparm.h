/********************************************************************************
** Form generated from reading UI file 'dialogpubparm.ui'
**
** Created: Fri Aug 29 14:50:06 2014
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGPUBPARM_H
#define UI_DIALOGPUBPARM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_DialogPubParm
{
public:
    QPushButton *butfind;

    void setupUi(QDialog *DialogPubParm)
    {
        if (DialogPubParm->objectName().isEmpty())
            DialogPubParm->setObjectName(QString::fromUtf8("DialogPubParm"));
        DialogPubParm->resize(719, 469);
        butfind = new QPushButton(DialogPubParm);
        butfind->setObjectName(QString::fromUtf8("butfind"));
        butfind->setGeometry(QRect(150, 390, 75, 23));

        retranslateUi(DialogPubParm);

        QMetaObject::connectSlotsByName(DialogPubParm);
    } // setupUi

    void retranslateUi(QDialog *DialogPubParm)
    {
        DialogPubParm->setWindowTitle(QApplication::translate("DialogPubParm", "Dialog", 0, QApplication::UnicodeUTF8));
        butfind->setText(QApplication::translate("DialogPubParm", "PushButton", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DialogPubParm: public Ui_DialogPubParm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGPUBPARM_H
