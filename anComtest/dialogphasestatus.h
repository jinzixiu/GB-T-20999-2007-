#ifndef DIALOGPHASESTATUS_H
#define DIALOGPHASESTATUS_H

#include <QDialog>
#include "cpubsub.h"
#include <QTimer>
namespace Ui {
    class DialogPhaseStatus;
}

class DialogPhaseStatus : public QDialog
{
    Q_OBJECT

public:
    explicit DialogPhaseStatus(QWidget *parent = 0);
    ~DialogPhaseStatus();
    CPubSub *com;
    QTimer *revtimer;
    QTimer *timeout;
    void setcom(CPubSub *com);
    void dealwith(uchar* rec,int len);
    void initb1(uchar *buffer);
    void init96iii(uchar *buffer);
    void init92(uchar *buffer);
    void inita0(uchar *buffer);
private slots:
    void rev();
    void warming();
    void sendb1();
    void setb96();
    void sendd1();
    void setbd1();
    void on_butfind_clicked();
    void on_butquit_clicked();

private:
    Ui::DialogPhaseStatus *ui;
};

#endif // DIALOGPHASESTATUS_H
