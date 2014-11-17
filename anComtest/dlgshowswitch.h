#ifndef DLGSHOWSWITCH_H
#define DLGSHOWSWITCH_H

#include <QDialog>
#include "cpubsub.h"
#include <QTimer>
namespace Ui {
    class DlgShowSwitch;
}

class DlgShowSwitch : public QDialog
{
    Q_OBJECT

public:
    explicit DlgShowSwitch(QWidget *parent = 0);
    ~DlgShowSwitch();
    CPubSub *com;
    QTimer *revtimer;
    QTimer *timeout;
    void setcom(CPubSub *com);
    void dealwith(uchar* rec,int len);
    void initcc(unsigned char *);
    void initcb(unsigned char *);
private slots:
    void rev();
    void warming();

    void sendcc() ;
    void sendcb();
    void setcc();
    void setcb();
    void on_butfind_clicked();

    void on_butok_clicked();

    void on_checkr_stateChanged(int );

    void on_checky_stateChanged(int );

    void on_checkg_stateChanged(int );

private:
    Ui::DlgShowSwitch *ui;
};

#endif // DLGSHOWSWITCH_H
