#ifndef DIALOGPHASETIMING_H
#define DIALOGPHASETIMING_H

#include <QDialog>
#include "cpubsub.h"
#include <QTimer>
namespace Ui {
    class DialogPhaseTiming;
}

class DialogPhaseTiming : public QDialog
{
    Q_OBJECT

public:
    explicit DialogPhaseTiming(QWidget *parent = 0);
    ~DialogPhaseTiming();
    CPubSub *com;
    QTimer *revtimer;
    QTimer *timeout;
    void setcom(CPubSub *com);
    void dealwith(uchar* rec,int len);
    void initPhaseTiming(unsigned char *);

private slots:
    void rev();
    void warming();
    void sendPhaseTiming();
    void setPhaseTiming();
    void on_butfind_clicked();

    void on_butok_clicked();

    void on_butquery_clicked();

    void on_butclearall_clicked();

    void on_butclear_clicked();

private:
    Ui::DialogPhaseTiming *ui;
};

#endif // DIALOGPHASETIMING_H
