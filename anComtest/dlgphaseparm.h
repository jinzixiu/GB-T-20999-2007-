#ifndef DLGPHASEPARM_H
#define DLGPHASEPARM_H

#include <QDialog>
#include <QDialog>
#include "cpubsub.h"
#include <QTimer>
namespace Ui {
    class DlgPhaseParm;
}

class DlgPhaseParm : public QDialog
{
    Q_OBJECT

public:
    explicit DlgPhaseParm(QWidget *parent = 0);
    ~DlgPhaseParm();
    CPubSub *com;
    QTimer *revtimer;
    QTimer *timeout;
    void setcom(CPubSub *com);
    void dealwith(uchar* rec,int len);

    void init95(uchar *buffer);
private slots:
    void rev();
    void warming();
    void send95();
    void set95();
    void on_butfind_clicked();

    void on_butok_clicked();

    void on_butclear_clicked();

    void on_butquery_clicked();

    void on_butclearall_clicked();

private:
    Ui::DlgPhaseParm *ui;
};

#endif // DLGPHASEPARM_H
