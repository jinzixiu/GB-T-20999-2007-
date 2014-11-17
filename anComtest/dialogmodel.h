#ifndef DIALOGMODEL_H
#define DIALOGMODEL_H

#include <QDialog>
#include "cpubsub.h"
#include <QTimer>
namespace Ui {
    class DialogModel;
}

class DialogModel : public QDialog
{
    Q_OBJECT

public:
    explicit DialogModel(QWidget *parent = 0);
    ~DialogModel();
    CPubSub *com;
    QTimer *revtimer;
    QTimer *timeout;
    void setcom(CPubSub *com);
    void dealwith(uchar* rec,int len);
    void init85(uchar *buffer);

private slots:
    void rev();
    void warming();
    void send85();
    void on_butfind1_clicked();

    void on_butfind1_2_clicked();

    void on_butfind1_3_clicked();

    void on_butfind1_4_clicked();

private:
    Ui::DialogModel *ui;
};

#endif // DIALOGMODEL_H
