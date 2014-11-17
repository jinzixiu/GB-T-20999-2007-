#ifndef DIALOGCARTEST_H
#define DIALOGCARTEST_H

#include <QDialog>
#include "cpubsub.h"
#include <QTimer>
namespace Ui {
    class DialogCarTest;
}

class DialogCarTest : public QDialog
{
    Q_OBJECT

public:
    explicit DialogCarTest(QWidget *parent = 0);
    ~DialogCarTest();
    CPubSub *com;
    QTimer *revtimer;
    QTimer *timeout;
    void setcom(CPubSub *com);
    void dealwith(uchar* rec,int len);
    void init9f(uchar *buffer);

private slots:
    void rev();
    void warming();
    void send9f();
    void set9f();
    void on_butfind_clicked();

    void on_butok_clicked();

    void on_butok_2_clicked();

    void on_butquery_clicked();

    void on_butclearall_clicked();

private:
    Ui::DialogCarTest *ui;
};

#endif // DIALOGCARTEST_H
