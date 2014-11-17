#ifndef DLGTIMEBASE_H
#define DLGTIMEBASE_H

#include <QDialog>
#include "cpubsub.h"
#include <QTimer>
namespace Ui {
    class DlgTimeBase;
}

class DlgTimeBase : public QDialog
{
    Q_OBJECT

public:
    explicit DlgTimeBase(QWidget *parent = 0);
    ~DlgTimeBase();
    CPubSub *com;
    QTimer *revtimer;
    QTimer *timeout;
    void setcom(CPubSub *com);
    void dealwith(uchar* rec,int len);

    void init8d(uchar *buffer);
private slots:
    void rev();
    void warming();
    void send8d();
    void set8d();




    void on_butfind_clicked();

    void on_butset_clicked();

    void on_bufclear_clicked();

    void on_checkBoxifofmon_stateChanged(int );

    void on_checkBoxifofweek_stateChanged(int );

    void on_checkBoxifofday_stateChanged(int );

    void on_butquery_clicked();

    void on_butclearall_clicked();

private:
    Ui::DlgTimeBase *ui;
};

#endif // DLGTIMEBASE_H
