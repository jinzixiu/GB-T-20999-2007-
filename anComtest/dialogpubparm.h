#ifndef DIALOGPUBPARM_H
#define DIALOGPUBPARM_H

#include <QDialog>
#include "serialport.h"
QT_BEGIN_NAMESPACE_SERIALPORT
class SerialPort;
QT_END_NAMESPACE_SERIALPORT

QT_USE_NAMESPACE_SERIALPORT

namespace Ui {
    class DialogPubParm;
}

class DialogPubParm : public QDialog
{
    Q_OBJECT

public:
    explicit DialogPubParm(QWidget *parent = 0);
    ~DialogPubParm();
    SerialPort *com;
    void setPort(SerialPort *com);
    bool send_chose_amd(unsigned char *sendbuf,int sendlen,unsigned char *revbuf,int revlen);

private slots:
    void on_butfind_clicked();

private:
    Ui::DialogPubParm *ui;
};

#endif // DIALOGPUBPARM_H
