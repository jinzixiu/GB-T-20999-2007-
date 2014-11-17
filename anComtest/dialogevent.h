#ifndef DIALOGEVENT_H
#define DIALOGEVENT_H

#include <QDialog>
#include "cpubsub.h"
#include <QTimer>
namespace Ui {
    class DialogEvent;
}

class DialogEvent : public QDialog
{
    Q_OBJECT

public:
    explicit DialogEvent(QWidget *parent = 0);
    ~DialogEvent();
    CPubSub *com;
    QTimer *revtimer;
    QTimer *timeout;

    void setcom(CPubSub *com);
    void dealwith(uchar* rec,int len);
    void init91(uchar *buffer);
private slots:
    void rev();
    void warming();
    void sendd2();
    void set91();
    void on_butfind_clicked();

    void on_butclear_clicked();

    void on_butsave_clicked();

private:
    Ui::DialogEvent *ui;
};



#endif // DIALOGEVENT_H
