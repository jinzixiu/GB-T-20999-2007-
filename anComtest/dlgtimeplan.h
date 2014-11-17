#ifndef DLGTIMEPLAN_H
#define DLGTIMEPLAN_H

#include <QDialog>
#include "cpubsub.h"
#include <QTimer>
namespace Ui {
    class DlgTimePlan;
}

class DlgTimePlan : public QDialog
{
    Q_OBJECT

public:
    explicit DlgTimePlan(QWidget *parent = 0);
    ~DlgTimePlan();
    CPubSub *com;
    QTimer *revtimer;
    QTimer *timeout;
//    void setcom(CPubSub *com);
//    void dealwith(uchar* rec,int len);
//    void initc0(uchar *buffer);

//private slots:
//    void rev();
//    void warming();
//    void sendc0();
//    void setc0();

//    void on_butfind_clicked();

//    void on_butset_clicked();

//    void on_butclear_clicked();

//    void on_butquery_clicked();

//    void on_butclearall_clicked();

private:
    Ui::DlgTimePlan *ui;
};

#endif // DLGTIMEPLAN_H
