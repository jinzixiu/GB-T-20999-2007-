#include "unit.h"
#include <QString>
#define	CRC_PRESET   0xFFFF
#define CRC_POLYNOM  0x8408
void isComOpen(QWidget *parm,bool flag)
{
    if(!flag)
    {
        QString str1;
        str1 = str1.fromLocal8Bit("错误！");
        QString str2;
        str2 = str2.fromLocal8Bit("串口没有打开，请检查连接或者重启程序");
        QMessageBox::information(parm, str1,str2,QMessageBox::Ok,NULL);
    }
}
unsigned short CommVerify(unsigned char* checksource,unsigned short length)
{
    unsigned short verifynum = CRC_PRESET; // CRC_PRESET= 0xffff
    unsigned short verifyi, verifyj;
    for(verifyi = 0; verifyi < length; verifyi++)
    {
        verifynum ^= *checksource;
        for(verifyj=0;verifyj<8;verifyj++)
        {
            if(verifynum&0x0001)
                verifynum=(verifynum>>1)^CRC_POLYNOM;//CRC_POLYNOM=8408H
            else
                verifynum=(verifynum>>1);
        }
        checksource++;
    }
    return verifynum;
    //return 43690;
}
void message(QWidget *who,const char *title,const char *neirong)
{
    QString str1;
    str1 = str1.fromLocal8Bit(title);
    QString str2;
    str2 = str2.fromLocal8Bit(neirong);
    QMessageBox::information(who, str1,str2,QMessageBox::Ok,NULL);
}
void messagelab(QLabel *who,const char *title)
{
    QString str1;
    str1 = str1.fromLocal8Bit(title);
    who->setText(str1);
}
