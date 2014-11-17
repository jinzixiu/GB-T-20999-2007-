#ifndef DIALOGTIMEPLAN_H
#define DIALOGTIMEPLAN_H

#include <QDialog>
#include "cpubsub.h"
#include <QTimer>
namespace Ui {
    class DialogTimePlan;
}

class DialogTimePlan : public QDialog
{
    Q_OBJECT

public:
    explicit DialogTimePlan(QWidget *parent = 0);
    ~DialogTimePlan();
    CPubSub *com;
    QTimer *revtimer;
    QTimer *timeout;
    void setcom(CPubSub *com);
    void dealwith(uchar* rec,int len);
    void initc0(uchar *buffer);
private slots:
    void rev();
    void warming();
    void sendc0();
    void setc0();

    void on_butset_clicked();

    void on_butclear_clicked();

    void on_butquery_clicked();

    void on_butclearall_clicked();

    void on_butsend_clicked();

private:
    Ui::DialogTimePlan *ui;
};

#endif // DIALOGTIMEPLAN_H
