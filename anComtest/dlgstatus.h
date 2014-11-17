#ifndef DLGSTATUS_H
#define DLGSTATUS_H

#include <QDialog>
#include "cpubsub.h"
#include <QTimer>
#include <QLabel>
namespace Ui {
    class DlgStatus;
}

class DlgStatus : public QDialog
{
    Q_OBJECT

public:
    explicit DlgStatus(QWidget *parent = 0);
    ~DlgStatus();
    CPubSub *com;
    QTimer *revtimer;
    QTimer *timeout;

     QList<QLabel *> QLabel_list;
     QList<uchar> type;
     QList<uchar> dirc;
    void setcom(CPubSub *com);
    void dealwith(uchar* rec,int len);
    void initallb0(uchar *buffer);
    void dealchannel(uchar line,uchar parm);
    void initb1(uchar *buffer);
private slots:
    void on_butinit_clicked();
    void rev();
    void warming();
    void sendallb0();
    void sendd1();
    void setd1();
    void sendb1();
    void on_pushButton_clicked();
    void on_butquit_clicked();

    void on_butfind_clicked();

private:
    Ui::DlgStatus *ui;
};

#endif // DLGSTATUS_H
