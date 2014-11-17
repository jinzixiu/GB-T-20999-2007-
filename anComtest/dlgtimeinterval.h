#ifndef DLGTIMEINTERVAL_H
#define DLGTIMEINTERVAL_H

#include <QDialog>
#include "cpubsub.h"
#include <QTimer>
namespace Ui {
    class DlgTimeInterval;
}

class DlgTimeInterval : public QDialog
{
    Q_OBJECT

public:
    explicit DlgTimeInterval(QWidget *parent = 0);
    ~DlgTimeInterval();
    CPubSub *com;
    QTimer *revtimer;
    QTimer *timeout;
    void setcom(CPubSub *com);
    void dealwith(uchar* rec,int len);

    void init8e(uchar *buffer);
private slots:
    void rev();
    void warming();
    void send8e();
    void set8e();

    void on_butfind_clicked();

    void on_butok_clicked();

    void on_butclear_clicked();

    void on_query_clicked();

    void on_clearall_clicked();

private:
    Ui::DlgTimeInterval *ui;
};

#endif // DLGTIMEINTERVAL_H
