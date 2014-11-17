#ifndef DIALOGUNITPARM_H
#define DIALOGUNITPARM_H

#include <QDialog>
#include "cpubsub.h"
#include <QTimer>
namespace Ui {
    class DialogUnitParm;
}

class DialogUnitParm : public QDialog
{
    Q_OBJECT

public:
    explicit DialogUnitParm(QWidget *parent = 0);
    ~DialogUnitParm();
    CPubSub *com;
    QTimer *revtimer;
    QTimer *timeout;
    void setcom(CPubSub *com);
    void dealwith(uchar* rec,int len);

    void inita3(uchar* buffer);
    void inita4(uchar* buffer);
    void inita5(uchar* buffer);
    void inita6(uchar* buffer);
    void inita8(uchar* buffer);
    void inita7(uchar* buffer);
    void initab(uchar* buffer);
    void initaa(uchar* buffer);
    void inita9(uchar* buffer);
private slots:
    void rev();
    void warming();

    void senda3();
    void senda4();
    void senda5();
    void senda6();
    void senda8();
    void senda7();
    void sendab();
    void sendaa();
    void senda9();

    void seta3();
    void seta4();
    void seta5();
    void seta6();
    void setaa();
    void setab();

    void on_butfind_clicked();

    void on_butok_clicked();

private:
    Ui::DialogUnitParm *ui;
};

#endif // DIALOGUNITPARM_H
