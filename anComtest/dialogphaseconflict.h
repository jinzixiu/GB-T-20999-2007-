#ifndef DIALOGPHASECONFLICT_H
#define DIALOGPHASECONFLICT_H

#include <QDialog>
#include "cpubsub.h"
#include <QTimer>
namespace Ui {
    class DialogPhaseConflict;
}

class DialogPhaseConflict : public QDialog
{
    Q_OBJECT

public:
    explicit DialogPhaseConflict(QWidget *parent = 0);
    ~DialogPhaseConflict();
    CPubSub *com;
    QTimer *revtimer;
    QTimer *timeout;
    void setcom(CPubSub *com);
    void dealwith(uchar* rec,int len);
    void initPhaseClash(unsigned char pparm,unsigned char pvalue1,unsigned char pvalue2);
    void opreart(unsigned char *buffer);
private slots:
    void rev();
    void warming();
    void sendPhaseClash();
    void setPhaseClash();
    void on_butfind_clicked();

    void on_butok_clicked();

    void on_checkBox_stateChanged(int );

    void on_butquery_clicked();

    void on_butclearall_clicked();

private:
    Ui::DialogPhaseConflict *ui;
};

#endif // DIALOGPHASECONFLICT_H
