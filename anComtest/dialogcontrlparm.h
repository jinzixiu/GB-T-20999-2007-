#ifndef DIALOGCONTRLPARM_H
#define DIALOGCONTRLPARM_H

#include <QDialog>
#include "cpubsub.h"
#include <QTimer>
namespace Ui {
    class DialogContrlParm;
}

class DialogContrlParm : public QDialog
{
    Q_OBJECT

public:
    explicit DialogContrlParm(QWidget *parent = 0);
    ~DialogContrlParm();
    CPubSub *com;
    QTimer *revtimer;
    QTimer *timeout;
    void setcom(CPubSub *com);
    void dealwith(uchar* rec,int len);

    void initb5(uchar *buffer);
    void initb6(uchar *buffer);
    void initb7(uchar *buffer);
    void initb8(uchar *buffer);
    void initb9(uchar *buffer);
    void initba(uchar *buffer);
    void initbb(uchar *buffer);
    void initbd(uchar *buffer);
    void initcd(uchar *buffer);
private slots:
    void rev();
    void warming();
    void sendb5();
    void sendb6();
    void sendb7();
    void sendb8();
    void sendb9();
    void sendba();
    void sendbb();
    void sendbd();
    void sendcd();
    void setCountDown();
    void sendquerymsg(char parm);
    void on_butfind_clicked();

    void on_butok_clicked();

    void on_checkBox_stateChanged(int );

private:
    Ui::DialogContrlParm *ui;
};

#endif // DIALOGCONTRLPARM_H
