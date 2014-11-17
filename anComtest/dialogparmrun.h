#ifndef DIALOGPARMRUN_H
#define DIALOGPARMRUN_H

#include <QDialog>
#include "cpubsub.h"
#include <QTimer>
namespace Ui {
    class DialogParmRun;
}

class DialogParmRun : public QDialog
{
    Q_OBJECT

public:
    explicit DialogParmRun(QWidget *parent = 0);
    ~DialogParmRun();
    CPubSub *com;
    QTimer *revtimer;
    QTimer *timeout;
    void setcom(CPubSub *com);
    void dealwith(uchar* rec,int len);
    void initc2(uchar *buffer);
private slots:
    void rev();
    void warming();
    void sendc2();
    void setc2();
    void on_butfind_clicked();

    void on_butok_clicked();

private:
    Ui::DialogParmRun *ui;
};

#endif // DIALOGPARMRUN_H
