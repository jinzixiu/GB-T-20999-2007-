#ifndef DIALOGFLOWPHASE_H
#define DIALOGFLOWPHASE_H

#include <QDialog>
#include "cpubsub.h"
#include <QTimer>
namespace Ui {
    class DialogFlowPhase;
}

class DialogFlowPhase : public QDialog
{
    Q_OBJECT

public:
    explicit DialogFlowPhase(QWidget *parent = 0);
    ~DialogFlowPhase();
    CPubSub *com;
    QTimer *revtimer;
    QTimer *timeout;
    void setcom(CPubSub *com);
    void dealwith(uchar* rec,int len);
    void initc8(uchar *buffer);

private slots:
    void rev();
    void warming();
    void sendc8();
    void setc8();
    void on_butfind_clicked();

    void on_butset_clicked();

    void on_butcleaer_clicked();

    void on_butquery_clicked();

    void on_butclearall_clicked();

private:
    Ui::DialogFlowPhase *ui;
};

#endif // DIALOGFLOWPHASE_H
