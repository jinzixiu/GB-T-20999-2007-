#ifndef DIALOGCHANNELTAB_H
#define DIALOGCHANNELTAB_H

#include <QDialog>
#include "cpubsub.h"
#include <QTimer>
namespace Ui {
    class DialogChanneltab;
}

class DialogChanneltab : public QDialog
{
    Q_OBJECT

public:
    explicit DialogChanneltab(QWidget *parent = 0);
    ~DialogChanneltab();
    CPubSub *com;
    QTimer *revtimer;
    QTimer *timeout;
    void setcom(CPubSub *com);
    void dealwith(uchar* rec,int len);
    void initb0(uchar *buffer);

private slots:
    void rev();
    void warming();
    void sendb0();
    void setb0();
    void on_butfind_clicked();
    void on_butok_clicked();
    void on_butcleaer_clicked();
    void on_butquery_clicked();
    void on_butclearall_clicked();
private:
    Ui::DialogChanneltab *ui;
};

#endif // DIALOGCHANNELTAB_H
