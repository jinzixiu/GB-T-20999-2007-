#include "dialogphaseconflict.h"
#include "ui_dialogphaseconflict.h"
#include "unit.h"
#include <QDebug>
DialogPhaseConflict::DialogPhaseConflict(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogPhaseConflict)
{
    ui->setupUi(this);
    this->com=new CPubSub();
    this->revtimer=new QTimer();
    this->timeout=new QTimer();
    connect(timeout,SIGNAL(timeout()),this,SLOT(warming()));
}

DialogPhaseConflict::~DialogPhaseConflict()
{
    delete ui;
    deleteLater();
}
void DialogPhaseConflict::setcom(CPubSub *com)
{
    this->com=com;
}
void DialogPhaseConflict::dealwith(uchar* rec,int len)
{
    uchar* s =rec;
    for(int i=0; i<len; i++)
    {
        if((*s) != 0x02)
        {
            s++;
            continue;
        }
        uchar* s2 = s;
        unsigned short hight=(*(s2+1))<<8;
        unsigned short low=*(s2+2);
        unsigned short num=hight+low;
        if(i+(num+5)>len)
            return;
        unsigned short crchight=(*(s2+(num+3)))<<8;
        unsigned short crclow=(*(s2+(num+4)));
        unsigned short crcnum=crchight+crclow;

        //char buffer[]={0x02,0x00,0x05 ,0x84 ,0x83 ,0x00 ,0x00 ,0x00};
        //unsigned short wewewew=CommVerify((uchar*)buffer,8);
        if(crcnum!=CommVerify((uchar*)s,num+3))
        {
            s++;
            qDebug()<<"chucuo!!!!!jiaoyan!!!";
            continue;
        }
        if((uchar)*(s+3)==0x84)//查询命令处理
        {
            if((uchar)(*(s+4))==0x97)
            {
                opreart((uchar*)s);
                ui->display->setText(tr("查询成功!"));
                timeout->stop();
            }
            if((uchar)(*(s+4))==0x79)
            {
                ui->hang->setText(QString::number((uchar)(*(s+6))));
                ui->display->setText(tr("查询成功!"));
                timeout->stop();
            }
        }
        if((uchar)*(s+3)==0x85)//设置成功命令
        {
            if((uchar)(*(s+4))==0x97)
            {
                ui->display->setText(tr("设置成功!"));
                timeout->stop();
            }
            if((uchar)(*(s+4))==0x79)
            {
                ui->display->setText(tr("设置成功!"));
                timeout->stop();
            }
        }
        if((uchar)*(s+3)==0x86)//设置错误命令
        {
            if((uchar)(*(s+4))==0x97)
            {
                ui->display->setText(tr("设置失败!"));
                timeout->stop();
            }
        }
        s +=(num+5);
        i += (num+4);
    }
}

void DialogPhaseConflict::initPhaseClash(unsigned char pparm,unsigned char pvalue1,unsigned char pvalue2)
{
    unsigned char parm=pparm;
    unsigned char value1=pvalue2;
    unsigned char value2=pvalue1;
    if((parm!=0xff)&&((value1!=0xff)||(value2!=0xff)))
    {
       if(parm==0x01)
       {

               if((value1&0x01)==0x01)
                   ui->c1_1->setChecked(true);
               if((value1&0x02)==0x02)
                   ui->c1_2->setChecked(true);
               if((value1&0x04)==0x04)
                   ui->c1_3->setChecked(true);
               if((value1&0x08)==0x08)
                   ui->c1_4->setChecked(true);
               if((value1&0x10)==0x10)
                   ui->c1_5->setChecked(true);
               if((value1&0x20)==0x20)
                   ui->c1_6->setChecked(true);
               if((value1&0x40)==0x40)
                   ui->c1_7->setChecked(true);
               if((value1&0x80)==0x80)
                   ui->c1_8->setChecked(true);

               if((value2&0x01)==0x01)
                   ui->c1_9->setChecked(true);
               if((value2&0x02)==0x02)
                   ui->c1_10->setChecked(true);
               if((value2&0x04)==0x04)
                   ui->c1_11->setChecked(true);
               if((value2&0x08)==0x08)
                   ui->c1_12->setChecked(true);
               if((value2&0x10)==0x10)
                   ui->c1_13->setChecked(true);
               if((value2&0x20)==0x20)
                   ui->c1_14->setChecked(true);
               if((value2&0x40)==0x40)
                   ui->c1_15->setChecked(true);
               if((value2&0x80)==0x80)
                   ui->c1_16->setChecked(true);

       }
       if(parm==0x02)
       {

           if((value1&0x01)==0x01)
               ui->c2_1->setChecked(true);
           if((value1&0x02)==0x02)
               ui->c2_2->setChecked(true);
           if((value1&0x04)==0x04)
               ui->c2_3->setChecked(true);
           if((value1&0x08)==0x08)
               ui->c2_4->setChecked(true);
           if((value1&0x10)==0x10)
               ui->c2_5->setChecked(true);
           if((value1&0x20)==0x20)
               ui->c2_6->setChecked(true);
           if((value1&0x40)==0x40)
               ui->c2_7->setChecked(true);
           if((value1&0x80)==0x80)
               ui->c2_8->setChecked(true);

               if((value2&0x01)==0x01)
                   ui->c2_9->setChecked(true);
               if((value2&0x02)==0x02)
                   ui->c2_10->setChecked(true);
               if((value2&0x04)==0x04)
                   ui->c2_11->setChecked(true);
               if((value2&0x08)==0x08)
                   ui->c2_12->setChecked(true);
               if((value2&0x10)==0x10)
                   ui->c2_13->setChecked(true);
               if((value2&0x20)==0x20)
                   ui->c2_14->setChecked(true);
               if((value2&0x40)==0x40)
                   ui->c2_15->setChecked(true);
               if((value2&0x80)==0x80)
                   ui->c2_16->setChecked(true);

       }
       if(parm==0x03)
       {

               if((value1&0x01)==0x01)
                   ui->c3_1->setChecked(true);
               if((value1&0x02)==0x02)
                   ui->c3_2->setChecked(true);
               if((value1&0x04)==0x04)
                   ui->c3_3->setChecked(true);
               if((value1&0x08)==0x08)
                   ui->c3_4->setChecked(true);
               if((value1&0x10)==0x10)
                   ui->c3_5->setChecked(true);
               if((value1&0x20)==0x20)
                   ui->c3_6->setChecked(true);
               if((value1&0x40)==0x40)
                   ui->c3_7->setChecked(true);
               if((value1&0x80)==0x80)
                   ui->c3_8->setChecked(true);

               if((value2&0x01)==0x01)
                   ui->c3_9->setChecked(true);
               if((value2&0x02)==0x02)
                   ui->c3_10->setChecked(true);
               if((value2&0x04)==0x04)
                   ui->c3_11->setChecked(true);
               if((value2&0x08)==0x08)
                   ui->c3_12->setChecked(true);
               if((value2&0x10)==0x10)
                   ui->c3_13->setChecked(true);
               if((value2&0x20)==0x20)
                   ui->c3_14->setChecked(true);
               if((value2&0x40)==0x40)
                   ui->c3_15->setChecked(true);
               if((value2&0x80)==0x80)
                   ui->c3_16->setChecked(true);

       }
       if(parm==0x04)
       {
               if((value1&0x01)==0x01)
                   ui->c4_1->setChecked(true);
               if((value1&0x02)==0x02)
                   ui->c4_2->setChecked(true);
               if((value1&0x04)==0x04)
                   ui->c4_3->setChecked(true);
               if((value1&0x08)==0x08)
                   ui->c4_4->setChecked(true);
               if((value1&0x10)==0x10)
                   ui->c4_5->setChecked(true);
               if((value1&0x20)==0x20)
                   ui->c4_6->setChecked(true);
               if((value1&0x40)==0x40)
                   ui->c4_7->setChecked(true);
               if((value1&0x80)==0x80)
                   ui->c4_8->setChecked(true);

               if((value2&0x01)==0x01)
                   ui->c4_9->setChecked(true);
               if((value2&0x02)==0x02)
                   ui->c4_10->setChecked(true);
               if((value2&0x04)==0x04)
                   ui->c4_11->setChecked(true);
               if((value2&0x08)==0x08)
                   ui->c4_12->setChecked(true);
               if((value2&0x10)==0x10)
                   ui->c4_13->setChecked(true);
               if((value2&0x20)==0x20)
                   ui->c4_14->setChecked(true);
               if((value2&0x40)==0x40)
                   ui->c4_15->setChecked(true);
               if((value2&0x80)==0x80)
                   ui->c4_16->setChecked(true);

       }
       if(parm==0x05)
       {

               if((value1&0x01)==0x01)
                   ui->c5_1->setChecked(true);
               if((value1&0x02)==0x02)
                   ui->c5_2->setChecked(true);
               if((value1&0x04)==0x04)
                   ui->c5_3->setChecked(true);
               if((value1&0x08)==0x08)
                   ui->c5_4->setChecked(true);
               if((value1&0x10)==0x10)
                   ui->c5_5->setChecked(true);
               if((value1&0x20)==0x20)
                   ui->c5_6->setChecked(true);
               if((value1&0x40)==0x40)
                   ui->c5_7->setChecked(true);
               if((value1&0x80)==0x80)
                   ui->c5_8->setChecked(true);

               if((value2&0x01)==0x01)
                   ui->c5_9->setChecked(true);
               if((value2&0x02)==0x02)
                   ui->c5_10->setChecked(true);
               if((value2&0x04)==0x04)
                   ui->c5_11->setChecked(true);
               if((value2&0x08)==0x08)
                   ui->c5_12->setChecked(true);
               if((value2&0x10)==0x10)
                   ui->c5_13->setChecked(true);
               if((value2&0x20)==0x20)
                   ui->c5_14->setChecked(true);
               if((value2&0x40)==0x40)
                   ui->c5_15->setChecked(true);
               if((value2&0x80)==0x80)
                   ui->c5_16->setChecked(true);

       }
       if(parm==0x06)
       {

               if((value1&0x01)==0x01)
                   ui->c6_1->setChecked(true);
               if((value1&0x02)==0x02)
                   ui->c6_2->setChecked(true);
               if((value1&0x04)==0x04)
                   ui->c6_3->setChecked(true);
               if((value1&0x08)==0x08)
                   ui->c6_4->setChecked(true);
               if((value1&0x10)==0x10)
                   ui->c6_5->setChecked(true);
               if((value1&0x20)==0x20)
                   ui->c6_6->setChecked(true);
               if((value1&0x40)==0x40)
                   ui->c6_7->setChecked(true);
               if((value1&0x80)==0x80)
                   ui->c6_8->setChecked(true);

               if((value2&0x01)==0x01)
                   ui->c6_9->setChecked(true);
               if((value2&0x02)==0x02)
                   ui->c6_10->setChecked(true);
               if((value2&0x04)==0x04)
                   ui->c6_11->setChecked(true);
               if((value2&0x08)==0x08)
                   ui->c6_12->setChecked(true);
               if((value2&0x10)==0x10)
                   ui->c6_13->setChecked(true);
               if((value2&0x20)==0x20)
                   ui->c6_14->setChecked(true);
               if((value2&0x40)==0x40)
                   ui->c6_15->setChecked(true);
               if((value2&0x80)==0x80)
                   ui->c6_16->setChecked(true);

       }
       if(parm==0x07)
       {

               if((value1&0x01)==0x01)
                   ui->c7_1->setChecked(true);
               if((value1&0x02)==0x02)
                   ui->c7_2->setChecked(true);
               if((value1&0x04)==0x04)
                   ui->c7_3->setChecked(true);
               if((value1&0x08)==0x08)
                   ui->c7_4->setChecked(true);
               if((value1&0x10)==0x10)
                   ui->c7_5->setChecked(true);
               if((value1&0x20)==0x20)
                   ui->c7_6->setChecked(true);
               if((value1&0x40)==0x40)
                   ui->c7_7->setChecked(true);
               if((value1&0x80)==0x80)
                   ui->c7_8->setChecked(true);

               if((value2&0x01)==0x01)
                   ui->c7_9->setChecked(true);
               if((value2&0x02)==0x02)
                   ui->c7_10->setChecked(true);
               if((value2&0x04)==0x04)
                   ui->c7_11->setChecked(true);
               if((value2&0x08)==0x08)
                   ui->c7_12->setChecked(true);
               if((value2&0x10)==0x10)
                   ui->c7_13->setChecked(true);
               if((value2&0x20)==0x20)
                   ui->c7_14->setChecked(true);
               if((value2&0x40)==0x40)
                   ui->c7_15->setChecked(true);
               if((value2&0x80)==0x80)
                   ui->c7_16->setChecked(true);

       }
       if(parm==0x08)
       {

               if((value1&0x01)==0x01)
                   ui->c8_1->setChecked(true);
               if((value1&0x02)==0x02)
                   ui->c8_2->setChecked(true);
               if((value1&0x04)==0x04)
                   ui->c8_3->setChecked(true);
               if((value1&0x08)==0x08)
                   ui->c8_4->setChecked(true);
               if((value1&0x10)==0x10)
                   ui->c8_5->setChecked(true);
               if((value1&0x20)==0x20)
                   ui->c8_6->setChecked(true);
               if((value1&0x40)==0x40)
                   ui->c8_7->setChecked(true);
               if((value1&0x80)==0x80)
                   ui->c8_8->setChecked(true);

               if((value2&0x01)==0x01)
                   ui->c8_9->setChecked(true);
               if((value2&0x02)==0x02)
                   ui->c8_10->setChecked(true);
               if((value2&0x04)==0x04)
                   ui->c8_11->setChecked(true);
               if((value2&0x08)==0x08)
                   ui->c8_12->setChecked(true);
               if((value2&0x10)==0x10)
                   ui->c8_13->setChecked(true);
               if((value2&0x20)==0x20)
                   ui->c8_14->setChecked(true);
               if((value2&0x40)==0x40)
                   ui->c8_15->setChecked(true);
               if((value2&0x80)==0x80)
                   ui->c8_16->setChecked(true);

       }
       if(parm==0x09)
       {

               if((value1&0x01)==0x01)
                   ui->c9_1->setChecked(true);
               if((value1&0x02)==0x02)
                   ui->c9_2->setChecked(true);
               if((value1&0x04)==0x04)
                   ui->c9_3->setChecked(true);
               if((value1&0x08)==0x08)
                   ui->c9_4->setChecked(true);
               if((value1&0x10)==0x10)
                   ui->c9_5->setChecked(true);
               if((value1&0x20)==0x20)
                   ui->c9_6->setChecked(true);
               if((value1&0x40)==0x40)
                   ui->c9_7->setChecked(true);
               if((value1&0x80)==0x80)
                   ui->c9_8->setChecked(true);

               if((value2&0x01)==0x01)
                   ui->c9_9->setChecked(true);
               if((value2&0x02)==0x02)
                   ui->c9_10->setChecked(true);
               if((value2&0x04)==0x04)
                   ui->c9_11->setChecked(true);
               if((value2&0x08)==0x08)
                   ui->c9_12->setChecked(true);
               if((value2&0x10)==0x10)
                   ui->c9_13->setChecked(true);
               if((value2&0x20)==0x20)
                   ui->c9_14->setChecked(true);
               if((value2&0x40)==0x40)
                   ui->c9_15->setChecked(true);
               if((value2&0x80)==0x80)
                   ui->c9_16->setChecked(true);


       }
       if(parm==0x0a)
       {

           if((value1&0x01)==0x01)
               ui->c10_1->setChecked(true);
           if((value1&0x02)==0x02)
               ui->c10_2->setChecked(true);
           if((value1&0x04)==0x04)
               ui->c10_3->setChecked(true);
           if((value1&0x08)==0x08)
               ui->c10_4->setChecked(true);
           if((value1&0x10)==0x10)
               ui->c10_5->setChecked(true);
           if((value1&0x20)==0x20)
               ui->c10_6->setChecked(true);
           if((value1&0x40)==0x40)
               ui->c10_7->setChecked(true);
           if((value1&0x80)==0x80)
               ui->c10_8->setChecked(true);

           if((value2&0x01)==0x01)
               ui->c10_9->setChecked(true);
           if((value2&0x02)==0x02)
               ui->c10_10->setChecked(true);
           if((value2&0x04)==0x04)
               ui->c10_11->setChecked(true);
           if((value2&0x08)==0x08)
               ui->c10_12->setChecked(true);
           if((value2&0x10)==0x10)
               ui->c10_13->setChecked(true);
           if((value2&0x20)==0x20)
               ui->c10_14->setChecked(true);
           if((value2&0x40)==0x40)
               ui->c10_15->setChecked(true);
           if((value2&0x80)==0x80)
               ui->c10_16->setChecked(true);

       }
       if(parm==0x0b)
       {

           if((value1&0x01)==0x01)
               ui->c11_1->setChecked(true);
           if((value1&0x02)==0x02)
               ui->c11_2->setChecked(true);
           if((value1&0x04)==0x04)
               ui->c11_3->setChecked(true);
           if((value1&0x08)==0x08)
               ui->c11_4->setChecked(true);
           if((value1&0x10)==0x10)
               ui->c11_5->setChecked(true);
           if((value1&0x20)==0x20)
               ui->c11_6->setChecked(true);
           if((value1&0x40)==0x40)
               ui->c11_7->setChecked(true);
           if((value1&0x80)==0x80)
               ui->c11_8->setChecked(true);

           if((value2&0x01)==0x01)
               ui->c11_9->setChecked(true);
           if((value2&0x02)==0x02)
               ui->c11_10->setChecked(true);
           if((value2&0x04)==0x04)
               ui->c11_11->setChecked(true);
           if((value2&0x08)==0x08)
               ui->c11_12->setChecked(true);
           if((value2&0x10)==0x10)
               ui->c11_13->setChecked(true);
           if((value2&0x20)==0x20)
               ui->c11_14->setChecked(true);
           if((value2&0x40)==0x40)
               ui->c11_15->setChecked(true);
           if((value2&0x80)==0x80)
               ui->c11_16->setChecked(true);

       }
       if(parm==0x0c)
       {

               if((value1&0x01)==0x01)
                   ui->c12_1->setChecked(true);
               if((value1&0x02)==0x02)
                   ui->c12_2->setChecked(true);
               if((value1&0x04)==0x04)
                   ui->c12_3->setChecked(true);
               if((value1&0x08)==0x08)
                   ui->c12_4->setChecked(true);
               if((value1&0x10)==0x10)
                   ui->c12_5->setChecked(true);
               if((value1&0x20)==0x20)
                   ui->c12_6->setChecked(true);
               if((value1&0x40)==0x40)
                   ui->c12_7->setChecked(true);
               if((value1&0x80)==0x80)
                   ui->c12_8->setChecked(true);

               if((value2&0x01)==0x01)
                   ui->c12_9->setChecked(true);
               if((value2&0x02)==0x02)
                   ui->c12_10->setChecked(true);
               if((value2&0x04)==0x04)
                   ui->c12_11->setChecked(true);
               if((value2&0x08)==0x08)
                   ui->c12_12->setChecked(true);
               if((value2&0x10)==0x10)
                   ui->c12_13->setChecked(true);
               if((value2&0x20)==0x20)
                   ui->c12_14->setChecked(true);
               if((value2&0x40)==0x40)
                   ui->c12_15->setChecked(true);
               if((value2&0x80)==0x80)
                   ui->c12_16->setChecked(true);

       }
       if(parm==0x0d)
       {

               if((value1&0x01)==0x01)
                   ui->c13_1->setChecked(true);
               if((value1&0x02)==0x02)
                   ui->c13_2->setChecked(true);
               if((value1&0x04)==0x04)
                   ui->c13_3->setChecked(true);
               if((value1&0x08)==0x08)
                   ui->c13_4->setChecked(true);
               if((value1&0x10)==0x10)
                   ui->c13_5->setChecked(true);
               if((value1&0x20)==0x20)
                   ui->c13_6->setChecked(true);
               if((value1&0x40)==0x40)
                   ui->c13_7->setChecked(true);
               if((value1&0x80)==0x80)
                   ui->c13_8->setChecked(true);

               if((value2&0x01)==0x01)
                   ui->c13_9->setChecked(true);
               if((value2&0x02)==0x02)
                   ui->c13_10->setChecked(true);
               if((value2&0x04)==0x04)
                   ui->c13_11->setChecked(true);
               if((value2&0x08)==0x08)
                   ui->c13_12->setChecked(true);
               if((value2&0x10)==0x10)
                   ui->c13_13->setChecked(true);
               if((value2&0x20)==0x20)
                   ui->c13_14->setChecked(true);
               if((value2&0x40)==0x40)
                   ui->c13_15->setChecked(true);
               if((value2&0x80)==0x80)
                   ui->c13_16->setChecked(true);

       }
       if(parm==0x0e)
       {

           if((value1&0x01)==0x01)
               ui->c14_1->setChecked(true);
           if((value1&0x02)==0x02)
               ui->c14_2->setChecked(true);
           if((value1&0x04)==0x04)
               ui->c14_3->setChecked(true);
           if((value1&0x08)==0x08)
               ui->c14_4->setChecked(true);
           if((value1&0x10)==0x10)
               ui->c14_5->setChecked(true);
           if((value1&0x20)==0x20)
               ui->c14_6->setChecked(true);
           if((value1&0x40)==0x40)
               ui->c14_7->setChecked(true);
           if((value1&0x80)==0x80)
               ui->c14_8->setChecked(true);

           if((value2&0x01)==0x01)
               ui->c14_9->setChecked(true);
           if((value2&0x02)==0x02)
               ui->c14_10->setChecked(true);
           if((value2&0x04)==0x04)
               ui->c14_11->setChecked(true);
           if((value2&0x08)==0x08)
               ui->c14_12->setChecked(true);
           if((value2&0x10)==0x10)
               ui->c14_13->setChecked(true);
           if((value2&0x20)==0x20)
               ui->c14_14->setChecked(true);
           if((value2&0x40)==0x40)
               ui->c14_15->setChecked(true);
           if((value2&0x80)==0x80)
               ui->c14_16->setChecked(true);

       }
       if(parm==0x0f)
       {

           if((value1&0x01)==0x01)
               ui->c15_1->setChecked(true);
           if((value1&0x02)==0x02)
               ui->c15_2->setChecked(true);
           if((value1&0x04)==0x04)
               ui->c15_3->setChecked(true);
           if((value1&0x08)==0x08)
               ui->c15_4->setChecked(true);
           if((value1&0x10)==0x10)
               ui->c15_5->setChecked(true);
           if((value1&0x20)==0x20)
               ui->c15_6->setChecked(true);
           if((value1&0x40)==0x40)
               ui->c15_7->setChecked(true);
           if((value1&0x80)==0x80)
               ui->c15_8->setChecked(true);

           if((value2&0x01)==0x01)
               ui->c15_9->setChecked(true);
           if((value2&0x02)==0x02)
               ui->c15_10->setChecked(true);
           if((value2&0x04)==0x04)
               ui->c15_11->setChecked(true);
           if((value2&0x08)==0x08)
               ui->c15_12->setChecked(true);
           if((value2&0x10)==0x10)
               ui->c15_13->setChecked(true);
           if((value2&0x20)==0x20)
               ui->c15_14->setChecked(true);
           if((value2&0x40)==0x40)
               ui->c15_15->setChecked(true);
           if((value2&0x80)==0x80)
               ui->c15_16->setChecked(true);

       }
       if(parm==0x10)
       {

           if((value1&0x01)==0x01)
               ui->c16_1->setChecked(true);
           if((value1&0x02)==0x02)
               ui->c16_2->setChecked(true);
           if((value1&0x04)==0x04)
               ui->c16_3->setChecked(true);
           if((value1&0x08)==0x08)
               ui->c16_4->setChecked(true);
           if((value1&0x10)==0x10)
               ui->c16_5->setChecked(true);
           if((value1&0x20)==0x20)
               ui->c16_6->setChecked(true);
           if((value1&0x40)==0x40)
               ui->c16_7->setChecked(true);
           if((value1&0x80)==0x80)
               ui->c16_8->setChecked(true);

               if((value2&0x01)==0x01)
                   ui->c16_9->setChecked(true);
               if((value2&0x02)==0x02)
                   ui->c16_10->setChecked(true);
               if((value2&0x04)==0x04)
                   ui->c16_11->setChecked(true);
               if((value2&0x08)==0x08)
                   ui->c16_12->setChecked(true);
               if((value2&0x10)==0x10)
                   ui->c16_13->setChecked(true);
               if((value2&0x20)==0x20)
                   ui->c16_14->setChecked(true);
               if((value2&0x40)==0x40)
                   ui->c16_15->setChecked(true);
               if((value2&0x80)==0x80)
                   ui->c16_16->setChecked(true);

       }
    }
}

void DialogPhaseConflict::opreart(unsigned char *buffer)
{
    if(0x01==*(buffer+7))
    initPhaseClash(*(buffer+7),*(buffer+8),*(buffer+9));
    if(0x02==*(buffer+10))
    initPhaseClash(*(buffer+10),*(buffer+11),*(buffer+12));
    if(0x03==*(buffer+13))
    initPhaseClash(*(buffer+13),*(buffer+14),*(buffer+15));
    if(0x04==*(buffer+16))
    initPhaseClash(*(buffer+16),*(buffer+17),*(buffer+18));
    if(0x05==*(buffer+19))
    initPhaseClash(*(buffer+19),*(buffer+20),*(buffer+21));
    if(0x06==*(buffer+22))
    initPhaseClash(*(buffer+22),*(buffer+23),*(buffer+24));
    if(0x07==*(buffer+25))
    initPhaseClash(*(buffer+25),*(buffer+26),*(buffer+27));
    if(0x08==*(buffer+28))
    initPhaseClash(*(buffer+28),*(buffer+29),*(buffer+30));
    if(0x09==*(buffer+31))
    initPhaseClash(*(buffer+31),*(buffer+32),*(buffer+33));
    if(0x0a==*(buffer+34))
    initPhaseClash(*(buffer+34),*(buffer+35),*(buffer+36));
    if(0x0b==*(buffer+37))
    initPhaseClash(*(buffer+37),*(buffer+38),*(buffer+39));
    if(0x0c==*(buffer+40))
    initPhaseClash(*(buffer+40),*(buffer+41),*(buffer+42));
    if(0x0d==*(buffer+43))
    initPhaseClash(*(buffer+43),*(buffer+44),*(buffer+45));
    if(0x0e==*(buffer+46))
    initPhaseClash(*(buffer+46),*(buffer+47),*(buffer+48));
    if(0x0f==*(buffer+49))
    initPhaseClash(*(buffer+49),*(buffer+50),*(buffer+51));
    if(0x10==*(buffer+52))
    initPhaseClash(*(buffer+52),*(buffer+53),*(buffer+54));
}

void DialogPhaseConflict::rev()
{
    qDebug()<<"~~~~~~~~~~~~~~~~~~";
    char RecBuf[4096];
    memset(RecBuf,NULL,4096);
    QString RecText;
    int Rlen;
    if(com->isopen())
    {
        Rlen=com->GetDataLen();
        if(Rlen>0)
        {
            com->ReadCom(RecBuf,Rlen);
            for(int i=0;i<Rlen;i++)
            {

                    RecText.append(QString::number((uchar)RecBuf[i],16));
                    RecText.append("|");
            }
        }
        dealwith((uchar*)RecBuf,Rlen);
    }
}

void DialogPhaseConflict::warming()
{
    ui->display->clear();
    ui->display->setText(tr("失败!请重试!"));
}

void DialogPhaseConflict::sendPhaseClash()
{
    char buffer[60];
    buffer[0]=0x02;
    buffer[1]=0x00;
    buffer[2]=0x03;
    buffer[3]=0x80;
    buffer[4]=0x97;
    buffer[5]=0x00;
    int len=6;
    unsigned short rssum=CommVerify((unsigned char *)buffer,len);
    buffer[len]=rssum/256;
    buffer[len+1]=rssum%256;
    this->com->WriteCom(buffer,len+2);
}

void DialogPhaseConflict::setPhaseClash()
{
    unsigned char parm11=0x00;
    unsigned char parm12=0x00;
    unsigned char parm21=0x00;
    unsigned char parm22=0x00;
    unsigned char parm31=0x00;
    unsigned char parm32=0x00;
    unsigned char parm41=0x00;
    unsigned char parm42=0x00;
    unsigned char parm51=0x00;
    unsigned char parm52=0x00;
    unsigned char parm61=0x00;
    unsigned char parm62=0x00;
    unsigned char parm71=0x00;
    unsigned char parm72=0x00;
    unsigned char parm81=0x00;
    unsigned char parm82=0x00;
    unsigned char parm91=0x00;
    unsigned char parm92=0x00;
    unsigned char parm101=0x00;
    unsigned char parm102=0x00;
    unsigned char parm111=0x00;
    unsigned char parm112=0x00;
    unsigned char parm121=0x00;
    unsigned char parm122=0x00;
    unsigned char parm131=0x00;
    unsigned char parm132=0x00;
    unsigned char parm141=0x00;
    unsigned char parm142=0x00;
    unsigned char parm151=0x00;
    unsigned char parm152=0x00;
    unsigned char parm161=0x00;
    unsigned char parm162=0x00;

       if(ui->c1_1->isChecked())
           parm11=(parm11|0x01);
       if(ui->c1_2->isChecked())
           parm11=(parm11|0x02);
       if(ui->c1_3->isChecked())
           parm11=(parm11|0x04);
       if(ui->c1_4->isChecked())
           parm11=(parm11|0x08);
       if(ui->c1_5->isChecked())
           parm11=(parm11|0x10);
       if(ui->c1_6->isChecked())
           parm11=(parm11|0x20);
       if(ui->c1_7->isChecked())
           parm11=(parm11|0x40);
       if(ui->c1_8->isChecked())
           parm11=(parm11|0x80);
       if(ui->c1_9->isChecked())
           parm12=(parm12|0x01);
       if(ui->c1_10->isChecked())
           parm12=(parm12|0x02);
       if(ui->c1_11->isChecked())
           parm12=(parm12|0x04);
       if(ui->c1_12->isChecked())
           parm12=(parm12|0x08);
       if(ui->c1_13->isChecked())
           parm12=(parm12|0x10);
       if(ui->c1_14->isChecked())
           parm12=(parm12|0x20);
       if(ui->c1_15->isChecked())
           parm12=(parm12|0x40);
       if(ui->c1_16->isChecked())
           parm12=(parm12|0x80);

    qDebug()<<QString::number(parm11,10);
    qDebug()<<QString::number(parm12,10);

       if(ui->c2_1->isChecked())
           parm21=parm21|0x01;
       if(ui->c2_2->isChecked())
           parm21=parm21|0x02;
       if(ui->c2_3->isChecked())
           parm21=parm21|0x04;
       if(ui->c2_4->isChecked())
           parm21=parm21|0x08;
       if(ui->c2_5->isChecked())
           parm21=parm21|0x10;
       if(ui->c2_6->isChecked())
           parm21=parm21|0x20;
       if(ui->c2_7->isChecked())
           parm21=parm21|0x40;
       if(ui->c2_8->isChecked())
           parm21=parm21|0x80;

        if(ui->c2_9->isChecked())
            parm22=parm22|0x01;
        if(ui->c2_10->isChecked())
            parm22=parm22|0x02;
        if(ui->c2_11->isChecked())
            parm22=parm22|0x04;
        if(ui->c2_12->isChecked())
            parm22=parm22|0x08;
        if(ui->c2_13->isChecked())
            parm22=parm22|0x10;
        if(ui->c2_14->isChecked())
            parm22=parm22|0x20;
        if(ui->c2_15->isChecked())
            parm22=parm22|0x40;
        if(ui->c2_16->isChecked())
            parm22=parm22|0x80;



       if(ui->c3_1->isChecked())
           parm31=(parm31|0x01);
       if(ui->c3_2->isChecked())
           parm31=(parm31|0x02);
       if(ui->c3_3->isChecked())
           parm31=(parm31|0x04);
       if(ui->c3_4->isChecked())
           parm31=(parm31|0x08);
       if(ui->c3_5->isChecked())
           parm31=(parm31|0x10);
       if(ui->c3_6->isChecked())
           parm31=(parm31|0x20);
       if(ui->c3_7->isChecked())
           parm31=(parm31|0x40);
       if(ui->c3_8->isChecked())
           parm31=(parm31|0x80);

        if(ui->c3_9->isChecked())
            parm32=(parm32|0x01);
        if(ui->c3_10->isChecked())
            parm32=(parm32|0x02);
        if(ui->c3_11->isChecked())
            parm32=(parm32|0x04);
        if(ui->c3_12->isChecked())
            parm32=(parm32|0x08);
        if(ui->c3_13->isChecked())
            parm32=(parm32|0x10);
        if(ui->c3_14->isChecked())
            parm32=(parm32|0x20);
        if(ui->c3_15->isChecked())
            parm32=(parm32|0x40);
        if(ui->c3_16->isChecked())
            parm32=(parm32|0x80);

       if(ui->c4_1->isChecked())
           parm41=(parm41|0x01);
       if(ui->c4_2->isChecked())
           parm41=(parm41|0x02);
       if(ui->c4_3->isChecked())
           parm41=(parm41|0x04);
       if(ui->c4_4->isChecked())
           parm41=(parm41|0x08);
       if(ui->c4_5->isChecked())
           parm41=(parm41|0x10);
       if(ui->c4_6->isChecked())
           parm41=(parm41|0x20);
       if(ui->c4_7->isChecked())
           parm41=(parm41|0x40);
       if(ui->c4_8->isChecked())
           parm41=(parm41|0x80);
        if(ui->c4_9->isChecked())
            parm42=(parm42|0x01);
        if(ui->c4_10->isChecked())
            parm42=(parm42|0x02);
        if(ui->c4_11->isChecked())
            parm42=(parm42|0x04);
        if(ui->c4_12->isChecked())
            parm42=(parm42|0x08);
        if(ui->c4_13->isChecked())
            parm42=(parm42|0x10);
        if(ui->c4_14->isChecked())
            parm42=(parm42|0x20);
        if(ui->c4_15->isChecked())
            parm42=(parm42|0x40);
        if(ui->c4_16->isChecked())
            parm42=(parm42|0x80);

           if(ui->c5_1->isChecked())
               parm51=(parm51|0x01);
           if(ui->c5_2->isChecked())
               parm51=(parm51|0x02);
           if(ui->c5_3->isChecked())
               parm51=(parm51|0x04);
           if(ui->c5_4->isChecked())
               parm51=(parm51|0x08);
           if(ui->c5_5->isChecked())
               parm51=(parm51|0x10);
           if(ui->c5_6->isChecked())
               parm51=(parm51|0x20);
           if(ui->c5_7->isChecked())
               parm51=(parm51|0x40);
           if(ui->c5_8->isChecked())
               parm51=(parm51|0x80);

            if(ui->c5_9->isChecked())
                parm52=(parm52|0x01);
            if(ui->c5_10->isChecked())
                parm52=(parm52|0x02);
            if(ui->c5_11->isChecked())
                parm52=(parm52|0x04);
            if(ui->c5_12->isChecked())
                parm52=(parm52|0x08);
            if(ui->c5_13->isChecked())
                parm52=(parm52|0x10);
            if(ui->c5_14->isChecked())
                parm52=(parm52|0x20);
            if(ui->c5_15->isChecked())
                parm52=(parm52|0x40);
            if(ui->c5_16->isChecked())
                parm52=(parm52|0x80);

           if(ui->c6_1->isChecked())
               parm61=(parm61|0x01);
           if(ui->c6_2->isChecked())
               parm61=(parm61|0x02);
           if(ui->c6_3->isChecked())
               parm61=(parm61|0x04);
           if(ui->c6_4->isChecked())
               parm61=(parm61|0x08);
           if(ui->c6_5->isChecked())
               parm61=(parm61|0x10);
           if(ui->c6_6->isChecked())
               parm61=(parm61|0x20);
           if(ui->c6_7->isChecked())
               parm61=(parm61|0x40);
           if(ui->c6_8->isChecked())
               parm61=(parm61|0x80);

            if(ui->c6_9->isChecked())
                parm62=(parm62|0x01);
            if(ui->c6_10->isChecked())
                parm62=(parm62|0x02);
            if(ui->c6_11->isChecked())
                parm62=(parm62|0x04);
            if(ui->c6_12->isChecked())
                parm62=(parm62|0x08);
            if(ui->c6_13->isChecked())
                parm62=(parm62|0x10);
            if(ui->c6_14->isChecked())
                parm62=(parm62|0x20);
            if(ui->c6_15->isChecked())
                parm62=(parm62|0x40);
            if(ui->c6_16->isChecked())
                parm62=(parm62|0x80);

           if(ui->c7_1->isChecked())
               parm71=(parm71|0x01);
           if(ui->c7_2->isChecked())
               parm71=(parm71|0x02);
           if(ui->c7_3->isChecked())
               parm71=(parm71|0x04);
           if(ui->c7_4->isChecked())
               parm71=(parm71|0x08);
           if(ui->c7_5->isChecked())
               parm71=(parm71|0x10);
           if(ui->c7_6->isChecked())
               parm71=(parm71|0x20);
           if(ui->c7_7->isChecked())
               parm71=(parm71|0x40);
           if(ui->c7_8->isChecked())
               parm71=(parm71|0x80);

            if(ui->c7_9->isChecked())
                parm72=(parm72|0x01);
            if(ui->c7_10->isChecked())
                parm72=(parm72|0x02);
            if(ui->c7_11->isChecked())
                parm72=(parm72|0x04);
            if(ui->c7_12->isChecked())
                parm72=(parm72|0x08);
            if(ui->c7_13->isChecked())
                parm72=(parm72|0x10);
            if(ui->c7_14->isChecked())
                parm72=(parm72|0x20);
            if(ui->c7_15->isChecked())
                parm72=(parm72|0x40);
            if(ui->c7_16->isChecked())
                parm72=(parm72|0x80);

           if(ui->c8_1->isChecked())
               parm81=(parm81|0x01);
           if(ui->c8_2->isChecked())
               parm81=(parm81|0x02);
           if(ui->c8_3->isChecked())
               parm81=(parm81|0x04);
           if(ui->c8_4->isChecked())
               parm81=(parm81|0x08);
           if(ui->c8_5->isChecked())
               parm81=(parm81|0x10);
           if(ui->c8_6->isChecked())
               parm81=(parm81|0x20);
           if(ui->c8_7->isChecked())
               parm81=(parm81|0x40);
           if(ui->c8_8->isChecked())
               parm81=(parm81|0x80);

            if(ui->c8_9->isChecked())
                parm82=(parm82|0x01);
            if(ui->c8_10->isChecked())
                parm82=(parm82|0x02);
            if(ui->c8_11->isChecked())
                parm82=(parm82|0x04);
            if(ui->c8_12->isChecked())
                parm82=(parm82|0x08);
            if(ui->c8_13->isChecked())
                parm82=(parm82|0x10);
            if(ui->c8_14->isChecked())
                parm82=(parm82|0x20);
            if(ui->c8_15->isChecked())
                parm82=(parm82|0x40);
            if(ui->c8_16->isChecked())
                parm82=(parm82|0x80);

           if(ui->c9_1->isChecked())
               parm91=(parm91|0x01);
           if(ui->c9_2->isChecked())
               parm91=(parm91|0x02);
           if(ui->c9_3->isChecked())
               parm91=(parm91|0x04);
           if(ui->c9_4->isChecked())
               parm91=(parm91|0x08);
           if(ui->c9_5->isChecked())
               parm91=(parm91|0x10);
           if(ui->c9_6->isChecked())
               parm91=(parm91|0x20);
           if(ui->c9_7->isChecked())
               parm91=(parm91|0x40);
           if(ui->c9_8->isChecked())
               parm91=(parm91|0x80);

            if(ui->c9_9->isChecked())
                parm92=(parm92|0x01);
            if(ui->c9_10->isChecked())
                parm92=(parm92|0x02);
            if(ui->c9_11->isChecked())
                parm92=(parm92|0x04);
            if(ui->c9_12->isChecked())
                parm92=(parm92|0x08);
            if(ui->c9_13->isChecked())
                parm92=(parm92|0x10);
            if(ui->c9_14->isChecked())
                parm92=(parm92|0x20);
            if(ui->c9_15->isChecked())
                parm92=(parm92|0x40);
            if(ui->c9_16->isChecked())
                parm92=(parm92|0x80);

           if(ui->c10_1->isChecked())
               parm101=(parm101|0x01);
           if(ui->c10_2->isChecked())
               parm101=(parm101|0x02);
           if(ui->c10_3->isChecked())
               parm101=(parm101|0x04);
           if(ui->c10_4->isChecked())
               parm101=(parm101|0x08);
           if(ui->c10_5->isChecked())
               parm101=(parm101|0x10);
           if(ui->c10_6->isChecked())
               parm101=(parm101|0x20);
           if(ui->c10_7->isChecked())
               parm101=(parm101|0x40);
           if(ui->c10_8->isChecked())
               parm101=(parm101|0x80);

            if(ui->c10_9->isChecked())
                parm102=(parm102|0x01);
            if(ui->c10_10->isChecked())
                parm102=(parm102|0x02);
            if(ui->c10_11->isChecked())
                parm102=(parm102|0x04);
            if(ui->c10_12->isChecked())
                parm102=(parm102|0x08);
            if(ui->c10_13->isChecked())
                parm102=(parm102|0x10);
            if(ui->c10_14->isChecked())
                parm102=(parm102|0x20);
            if(ui->c10_15->isChecked())
                parm102=(parm102|0x40);
            if(ui->c10_16->isChecked())
                parm102=(parm102|0x80);

           if(ui->c11_1->isChecked())
               parm111=(parm111|0x01);
           if(ui->c11_2->isChecked())
               parm111=(parm111|0x02);
           if(ui->c11_3->isChecked())
               parm111=(parm111|0x04);
           if(ui->c11_4->isChecked())
               parm111=(parm111|0x08);
           if(ui->c11_5->isChecked())
               parm111=(parm111|0x10);
           if(ui->c11_6->isChecked())
               parm111=(parm111|0x20);
           if(ui->c11_7->isChecked())
               parm111=(parm111|0x40);
           if(ui->c11_8->isChecked())
               parm111=(parm111|0x80);

            if(ui->c11_9->isChecked())
                parm112=(parm112|0x01);
            if(ui->c11_10->isChecked())
                parm112=(parm112|0x02);
            if(ui->c11_11->isChecked())
                parm112=(parm112|0x04);
            if(ui->c11_12->isChecked())
                parm112=(parm112|0x08);
            if(ui->c11_13->isChecked())
                parm112=(parm112|0x10);
            if(ui->c11_14->isChecked())
                parm112=(parm112|0x20);
            if(ui->c11_15->isChecked())
                parm112=(parm112|0x40);
            if(ui->c11_16->isChecked())
                parm112=(parm112|0x80);

           if(ui->c12_1->isChecked())
               parm121=(parm121|0x01);
           if(ui->c12_2->isChecked())
               parm121=(parm121|0x02);
           if(ui->c12_3->isChecked())
               parm121=(parm121|0x04);
           if(ui->c12_4->isChecked())
               parm121=(parm121|0x08);
           if(ui->c12_5->isChecked())
               parm121=(parm121|0x10);
           if(ui->c12_6->isChecked())
               parm121=(parm121|0x20);
           if(ui->c12_7->isChecked())
               parm121=(parm121|0x40);
           if(ui->c12_8->isChecked())
               parm121=(parm121|0x80);

            if(ui->c12_9->isChecked())
                parm122=(parm122|0x01);
            if(ui->c12_10->isChecked())
                parm122=(parm122|0x02);
            if(ui->c12_11->isChecked())
                parm122=(parm122|0x04);
            if(ui->c12_12->isChecked())
                parm122=(parm122|0x08);
            if(ui->c12_13->isChecked())
                parm122=(parm122|0x10);
            if(ui->c12_14->isChecked())
                parm122=(parm122|0x20);
            if(ui->c12_15->isChecked())
                parm122=(parm122|0x40);
            if(ui->c12_16->isChecked())
                parm122=(parm122|0x80);

           if(ui->c13_1->isChecked())
               parm131=(parm131|0x01);
           if(ui->c13_2->isChecked())
               parm131=(parm131|0x02);
           if(ui->c13_3->isChecked())
               parm131=(parm131|0x04);
           if(ui->c13_4->isChecked())
               parm131=(parm131|0x08);
           if(ui->c13_5->isChecked())
               parm131=(parm131|0x10);
           if(ui->c13_6->isChecked())
               parm131=(parm131|0x20);
           if(ui->c13_7->isChecked())
               parm131=(parm131|0x40);
           if(ui->c13_8->isChecked())
               parm131=(parm131|0x80);

            if(ui->c13_9->isChecked())
                parm132=(parm132|0x01);
            if(ui->c13_10->isChecked())
                parm132=(parm132|0x02);
            if(ui->c13_11->isChecked())
                parm132=(parm132|0x04);
            if(ui->c13_12->isChecked())
                parm132=(parm132|0x08);
            if(ui->c13_13->isChecked())
                parm132=(parm132|0x10);
            if(ui->c13_14->isChecked())
                parm132=(parm132|0x20);
            if(ui->c13_15->isChecked())
                parm132=(parm132|0x40);
            if(ui->c13_16->isChecked())
                parm132=(parm132|0x80);

           if(ui->c14_1->isChecked())
               parm141=(parm141|0x01);
           if(ui->c14_2->isChecked())
               parm141=(parm141|0x02);
           if(ui->c14_3->isChecked())
               parm141=(parm141|0x04);
           if(ui->c14_4->isChecked())
               parm141=(parm141|0x08);
           if(ui->c14_5->isChecked())
               parm141=(parm141|0x10);
           if(ui->c14_6->isChecked())
               parm141=(parm141|0x20);
           if(ui->c14_7->isChecked())
               parm141=(parm141|0x40);
           if(ui->c14_8->isChecked())
               parm141=(parm141|0x80);

            if(ui->c14_9->isChecked())
                parm142=(parm142|0x01);
            if(ui->c14_10->isChecked())
                parm142=(parm142|0x02);
            if(ui->c14_11->isChecked())
                parm142=(parm142|0x04);
            if(ui->c14_12->isChecked())
                parm142=(parm142|0x08);
            if(ui->c14_13->isChecked())
                parm142=(parm142|0x10);
            if(ui->c14_14->isChecked())
                parm142=(parm142|0x20);
            if(ui->c14_15->isChecked())
                parm142=(parm142|0x40);
            if(ui->c14_16->isChecked())
                parm142=(parm142|0x80);

           if(ui->c15_1->isChecked())
               parm151=(parm151|0x01);
           if(ui->c15_2->isChecked())
               parm151=(parm151|0x02);
           if(ui->c15_3->isChecked())
               parm151=(parm151|0x04);
           if(ui->c15_4->isChecked())
               parm151=(parm151|0x08);
           if(ui->c15_5->isChecked())
               parm151=(parm151|0x10);
           if(ui->c15_6->isChecked())
               parm151=(parm151|0x20);
           if(ui->c15_7->isChecked())
               parm151=(parm151|0x40);
           if(ui->c15_8->isChecked())
               parm151=(parm151|0x80);

            if(ui->c15_9->isChecked())
                parm152=(parm152|0x01);
            if(ui->c15_10->isChecked())
                parm152=(parm152|0x02);
            if(ui->c15_11->isChecked())
                parm152=(parm152|0x04);
            if(ui->c15_12->isChecked())
                parm152=(parm152|0x08);
            if(ui->c15_13->isChecked())
                parm152=(parm152|0x10);
            if(ui->c15_14->isChecked())
                parm152=(parm152|0x20);
            if(ui->c15_15->isChecked())
                parm152=(parm152|0x40);
            if(ui->c15_16->isChecked())
                parm152=(parm152|0x80);

           if(ui->c16_1->isChecked())
               parm161=(parm161|0x01);
           if(ui->c16_2->isChecked())
               parm161=(parm161|0x02);
           if(ui->c16_3->isChecked())
               parm161=(parm161|0x04);
           if(ui->c16_4->isChecked())
               parm161=(parm161|0x08);
           if(ui->c16_5->isChecked())
               parm161=(parm161|0x10);
           if(ui->c16_6->isChecked())
               parm161=(parm161|0x20);
           if(ui->c16_7->isChecked())
               parm161=(parm161|0x40);
           if(ui->c16_8->isChecked())
               parm161=(parm161|0x80);


            if(ui->c16_9->isChecked())
                parm162=(parm162|0x01);
            if(ui->c16_10->isChecked())
                parm162=(parm162|0x02);
            if(ui->c16_11->isChecked())
                parm162=(parm162|0x04);
            if(ui->c16_12->isChecked())
                parm162=(parm162|0x08);
            if(ui->c16_13->isChecked())
                parm162=(parm162|0x10);
            if(ui->c16_14->isChecked())
                parm162=(parm162|0x20);
            if(ui->c16_15->isChecked())
                parm162=(parm162|0x40);
            if(ui->c16_16->isChecked())
                parm162=(parm162|0x80);

    char buffer[600];
    int len;
    buffer[0]=0x02;
    buffer[1]=0x00;
    buffer[2]=0x34;
    buffer[3]=0x81;
    buffer[4]=0x97;
    buffer[5]=0x00;
    buffer[6]=0x10;

    buffer[7]=0x01;
    buffer[8]=parm12;
    buffer[9]=parm11;

    buffer[10]=0x02;
    buffer[11]=parm22;
    buffer[12]=parm21;

    buffer[13]=0x03;
    buffer[14]=parm32;
    buffer[15]=parm31;

    buffer[16]=0x04;
    buffer[17]=parm42;
    buffer[18]=parm41;

    buffer[19]=0x05;
    buffer[20]=parm52;
    buffer[21]=parm51;

    buffer[22]=0x06;
    buffer[23]=parm62;
    buffer[24]=parm61;

    buffer[25]=0x07;
    buffer[26]=parm72;
    buffer[27]=parm71;

    buffer[28]=0x08;
    buffer[29]=parm82;
    buffer[30]=parm81;

    buffer[31]=0x09;
    buffer[32]=parm92;
    buffer[33]=parm91;

    buffer[34]=0x0a;
    buffer[35]=parm102;
    buffer[36]=parm101;

    buffer[37]=0x0b;
    buffer[38]=parm112;
    buffer[39]=parm111;

    buffer[40]=0x0c;
    buffer[41]=parm122;
    buffer[42]=parm121;

    buffer[43]=0x0d;
    buffer[44]=parm132;
    buffer[45]=parm131;

    buffer[46]=0x0e;
    buffer[47]=parm142;
    buffer[48]=parm141;

    buffer[49]=0x0f;
    buffer[50]=parm152;
    buffer[51]=parm151;

    buffer[52]=0x10;
    buffer[53]=parm162;
    buffer[54]=parm161;

    len=55;
    unsigned short rssum=CommVerify((unsigned char *)buffer,len);
    buffer[len]=rssum/256;
    buffer[len+1]=rssum%256;
//    int i=0;
//    for(i;i<len;i++)
//        qDebug()<<"buffer"+QString::number(i,10)+":"+QString::number(buffer[i],16);
    com->WriteCom(buffer,len+2);
}

void DialogPhaseConflict::on_butfind_clicked()
{

    {

    ui->c1_1->setChecked(false);
    ui->c1_2->setChecked(false);
    ui->c1_3->setChecked(false);
    ui->c1_4->setChecked(false);
    ui->c1_5->setChecked(false);
    ui->c1_6->setChecked(false);
    ui->c1_7->setChecked(false);
    ui->c1_8->setChecked(false);
    ui->c1_9->setChecked(false);
    ui->c1_10->setChecked(false);
    ui->c1_11->setChecked(false);
    ui->c1_12->setChecked(false);
    ui->c1_13->setChecked(false);
    ui->c1_14->setChecked(false);
    ui->c1_15->setChecked(false);
    ui->c1_16->setChecked(false);

    //////////////////////////////////
    ui->c2_1->setChecked(false);
    ui->c2_2->setChecked(false);
    ui->c2_3->setChecked(false);
    ui->c2_4->setChecked(false);
    ui->c2_5->setChecked(false);
    ui->c2_6->setChecked(false);
    ui->c2_7->setChecked(false);
    ui->c2_8->setChecked(false);
    ui->c2_9->setChecked(false);
    ui->c2_10->setChecked(false);
    ui->c2_11->setChecked(false);
    ui->c2_12->setChecked(false);
    ui->c2_13->setChecked(false);
    ui->c2_14->setChecked(false);
    ui->c2_15->setChecked(false);
    ui->c2_16->setChecked(false);
    /////////////////////////////////////
    ui->c3_1->setChecked(false);
    ui->c3_2->setChecked(false);
    ui->c3_3->setChecked(false);
    ui->c3_4->setChecked(false);
    ui->c3_5->setChecked(false);
    ui->c3_6->setChecked(false);
    ui->c3_7->setChecked(false);
    ui->c3_8->setChecked(false);
    ui->c3_9->setChecked(false);
    ui->c3_10->setChecked(false);
    ui->c3_11->setChecked(false);
    ui->c3_12->setChecked(false);
    ui->c3_13->setChecked(false);
    ui->c3_14->setChecked(false);
    ui->c3_15->setChecked(false);
    ui->c3_16->setChecked(false);
    ////////////////////////////////////////
    ui->c4_1->setChecked(false);
    ui->c4_2->setChecked(false);
    ui->c4_3->setChecked(false);
    ui->c4_4->setChecked(false);
    ui->c4_5->setChecked(false);
    ui->c4_6->setChecked(false);
    ui->c4_7->setChecked(false);
    ui->c4_8->setChecked(false);
    ui->c4_9->setChecked(false);
    ui->c4_10->setChecked(false);
    ui->c4_11->setChecked(false);
    ui->c4_12->setChecked(false);
    ui->c4_13->setChecked(false);
    ui->c4_14->setChecked(false);
    ui->c4_15->setChecked(false);
    ui->c4_16->setChecked(false);

    ////////////////////////////////////////
    ui->c5_1->setChecked(false);
    ui->c5_2->setChecked(false);
    ui->c5_3->setChecked(false);
    ui->c5_4->setChecked(false);
    ui->c5_5->setChecked(false);
    ui->c5_6->setChecked(false);
    ui->c5_7->setChecked(false);
    ui->c5_8->setChecked(false);
    ui->c5_9->setChecked(false);
    ui->c5_10->setChecked(false);
    ui->c5_11->setChecked(false);
    ui->c5_12->setChecked(false);
    ui->c5_13->setChecked(false);
    ui->c5_14->setChecked(false);
    ui->c5_15->setChecked(false);
    ui->c5_16->setChecked(false);

    /////////////////////////////////////////
    ui->c6_1->setChecked(false);
    ui->c6_2->setChecked(false);
    ui->c6_3->setChecked(false);
    ui->c6_4->setChecked(false);
    ui->c6_5->setChecked(false);
    ui->c6_6->setChecked(false);
    ui->c6_7->setChecked(false);
    ui->c6_8->setChecked(false);
    ui->c6_9->setChecked(false);
    ui->c6_10->setChecked(false);
    ui->c6_11->setChecked(false);
    ui->c6_12->setChecked(false);
    ui->c6_13->setChecked(false);
    ui->c6_14->setChecked(false);
    ui->c6_15->setChecked(false);
    ui->c6_16->setChecked(false);
    ///////////////////////////////////////////
    ui->c7_1->setChecked(false);
    ui->c7_2->setChecked(false);
    ui->c7_3->setChecked(false);
    ui->c7_4->setChecked(false);
    ui->c7_5->setChecked(false);
    ui->c7_6->setChecked(false);
    ui->c7_7->setChecked(false);
    ui->c7_8->setChecked(false);
    ui->c7_9->setChecked(false);
    ui->c7_10->setChecked(false);
    ui->c7_11->setChecked(false);
    ui->c7_12->setChecked(false);
    ui->c7_13->setChecked(false);
    ui->c7_14->setChecked(false);
    ui->c7_15->setChecked(false);
    ui->c7_16->setChecked(false);
    ///////////////////////////////////////
    ui->c8_1->setChecked(false);
    ui->c8_2->setChecked(false);
    ui->c8_3->setChecked(false);
    ui->c8_4->setChecked(false);
    ui->c8_5->setChecked(false);
    ui->c8_6->setChecked(false);
    ui->c8_7->setChecked(false);
    ui->c8_8->setChecked(false);
    ui->c8_9->setChecked(false);
    ui->c8_10->setChecked(false);
    ui->c8_11->setChecked(false);
    ui->c8_12->setChecked(false);
    ui->c8_13->setChecked(false);
    ui->c8_14->setChecked(false);
    ui->c8_15->setChecked(false);
    ui->c8_16->setChecked(false);
    ///////////////////////////////////////
    ui->c9_1->setChecked(false);
    ui->c9_2->setChecked(false);
    ui->c9_3->setChecked(false);
    ui->c9_4->setChecked(false);
    ui->c9_5->setChecked(false);
    ui->c9_6->setChecked(false);
    ui->c9_7->setChecked(false);
    ui->c9_8->setChecked(false);
    ui->c9_9->setChecked(false);
    ui->c9_10->setChecked(false);
    ui->c9_11->setChecked(false);
    ui->c9_12->setChecked(false);
    ui->c9_13->setChecked(false);
    ui->c9_14->setChecked(false);
    ui->c9_15->setChecked(false);
    ui->c9_16->setChecked(false);
    ////////////////////////////////////////////
    ui->c10_1->setChecked(false);
    ui->c10_2->setChecked(false);
    ui->c10_3->setChecked(false);
    ui->c10_4->setChecked(false);
    ui->c10_5->setChecked(false);
    ui->c10_6->setChecked(false);
    ui->c10_7->setChecked(false);
    ui->c10_8->setChecked(false);
    ui->c10_9->setChecked(false);
    ui->c10_10->setChecked(false);
    ui->c10_11->setChecked(false);
    ui->c10_12->setChecked(false);
    ui->c10_13->setChecked(false);
    ui->c10_14->setChecked(false);
    ui->c10_15->setChecked(false);
    ui->c10_16->setChecked(false);
    ////////////////////////////////////////////
    ui->c11_1->setChecked(false);
    ui->c11_2->setChecked(false);
    ui->c11_3->setChecked(false);
    ui->c11_4->setChecked(false);
    ui->c11_5->setChecked(false);
    ui->c11_6->setChecked(false);
    ui->c11_7->setChecked(false);
    ui->c11_8->setChecked(false);
    ui->c11_9->setChecked(false);
    ui->c11_10->setChecked(false);
    ui->c11_11->setChecked(false);
    ui->c11_12->setChecked(false);
    ui->c11_13->setChecked(false);
    ui->c11_14->setChecked(false);
    ui->c11_15->setChecked(false);
    ui->c11_16->setChecked(false);
    //////////////////////////////////////
    ui->c12_1->setChecked(false);
    ui->c12_2->setChecked(false);
    ui->c12_3->setChecked(false);
    ui->c12_4->setChecked(false);
    ui->c12_5->setChecked(false);
    ui->c12_6->setChecked(false);
    ui->c12_7->setChecked(false);
    ui->c12_8->setChecked(false);
    ui->c12_9->setChecked(false);
    ui->c12_10->setChecked(false);
    ui->c12_11->setChecked(false);
    ui->c12_12->setChecked(false);
    ui->c12_13->setChecked(false);
    ui->c12_14->setChecked(false);
    ui->c12_15->setChecked(false);
    ui->c12_16->setChecked(false);
    ///////////////////////////////////////
    ui->c13_1->setChecked(false);
    ui->c13_2->setChecked(false);
    ui->c13_3->setChecked(false);
    ui->c13_4->setChecked(false);
    ui->c13_5->setChecked(false);
    ui->c13_6->setChecked(false);
    ui->c13_7->setChecked(false);
    ui->c13_8->setChecked(false);
    ui->c13_9->setChecked(false);
    ui->c13_10->setChecked(false);
    ui->c13_11->setChecked(false);
    ui->c13_12->setChecked(false);
    ui->c13_13->setChecked(false);
    ui->c13_14->setChecked(false);
    ui->c13_15->setChecked(false);
    ui->c13_16->setChecked(false);
    //////////////////////////////////////
    ui->c14_1->setChecked(false);
    ui->c14_2->setChecked(false);
    ui->c14_3->setChecked(false);
    ui->c14_4->setChecked(false);
    ui->c14_5->setChecked(false);
    ui->c14_6->setChecked(false);
    ui->c14_7->setChecked(false);
    ui->c14_8->setChecked(false);
    ui->c14_9->setChecked(false);
    ui->c14_10->setChecked(false);
    ui->c14_11->setChecked(false);
    ui->c14_12->setChecked(false);
    ui->c14_13->setChecked(false);
    ui->c14_14->setChecked(false);
    ui->c14_15->setChecked(false);
    ui->c14_16->setChecked(false);
    //////////////////////////////////////////
    ui->c15_1->setChecked(false);
    ui->c15_2->setChecked(false);
    ui->c15_3->setChecked(false);
    ui->c15_4->setChecked(false);
    ui->c15_5->setChecked(false);
    ui->c15_6->setChecked(false);
    ui->c15_7->setChecked(false);
    ui->c15_8->setChecked(false);
    ui->c15_9->setChecked(false);
    ui->c15_10->setChecked(false);
    ui->c15_11->setChecked(false);
    ui->c15_12->setChecked(false);
    ui->c15_13->setChecked(false);
    ui->c15_14->setChecked(false);
    ui->c15_15->setChecked(false);
    ui->c15_16->setChecked(false);
    ///////////////////////////////
    ui->c16_1->setChecked(false);
    ui->c16_2->setChecked(false);
    ui->c16_3->setChecked(false);
    ui->c16_4->setChecked(false);
    ui->c16_5->setChecked(false);
    ui->c16_6->setChecked(false);
    ui->c16_7->setChecked(false);
    ui->c16_8->setChecked(false);
    ui->c16_9->setChecked(false);
    ui->c16_10->setChecked(false);
    ui->c16_11->setChecked(false);
    ui->c16_12->setChecked(false);
    ui->c16_13->setChecked(false);
    ui->c16_14->setChecked(false);
    ui->c16_15->setChecked(false);
    ui->c16_16->setChecked(false);
    //////////////////////////////////////////
    }

    ui->display->clear();
    ui->display->setText(tr("查询中......"));

    QTimer::singleShot(1,this,SLOT(sendPhaseClash()));
    revtimer->start(500);
    connect(revtimer,SIGNAL(timeout()),this,SLOT(rev()));
    timeout->start(3000);
}

void DialogPhaseConflict::on_butok_clicked()
{
    QTimer::singleShot(1,this,SLOT(setPhaseClash()));
}

void DialogPhaseConflict::on_checkBox_stateChanged(int )
{
    if(ui->checkBox->isChecked())
    {
        {
//        ui->c1_1->setChecked(true);
        ui->c1_2->setChecked(true);
        ui->c1_3->setChecked(true);
        ui->c1_4->setChecked(true);
        ui->c1_5->setChecked(true);
        ui->c1_6->setChecked(true);
        ui->c1_7->setChecked(true);
        ui->c1_8->setChecked(true);
        ui->c1_9->setChecked(true);
        ui->c1_10->setChecked(true);
        ui->c1_11->setChecked(true);
        ui->c1_12->setChecked(true);
        ui->c1_13->setChecked(true);
        ui->c1_14->setChecked(true);
        ui->c1_15->setChecked(true);
        ui->c1_16->setChecked(true);

        //////////////////////////////////
//        ui->c2_1->setChecked(true);
//        ui->c2_2->setChecked(true);
        ui->c2_3->setChecked(true);
        ui->c2_4->setChecked(true);
        ui->c2_5->setChecked(true);
        ui->c2_6->setChecked(true);
        ui->c2_7->setChecked(true);
        ui->c2_8->setChecked(true);
        ui->c2_9->setChecked(true);
        ui->c2_10->setChecked(true);
        ui->c2_11->setChecked(true);
        ui->c2_12->setChecked(true);
        ui->c2_13->setChecked(true);
        ui->c2_14->setChecked(true);
        ui->c2_15->setChecked(true);
        ui->c2_16->setChecked(true);
        /////////////////////////////////////
//        ui->c3_1->setChecked(true);
//        ui->c3_2->setChecked(true);
//        ui->c3_3->setChecked(true);
        ui->c3_4->setChecked(true);
        ui->c3_5->setChecked(true);
        ui->c3_6->setChecked(true);
        ui->c3_7->setChecked(true);
        ui->c3_8->setChecked(true);
        ui->c3_9->setChecked(true);
        ui->c3_10->setChecked(true);
        ui->c3_11->setChecked(true);
        ui->c3_12->setChecked(true);
        ui->c3_13->setChecked(true);
        ui->c3_14->setChecked(true);
        ui->c3_15->setChecked(true);
        ui->c3_16->setChecked(true);
        ////////////////////////////////////////
//        ui->c4_1->setChecked(true);
//        ui->c4_2->setChecked(true);
//        ui->c4_3->setChecked(true);
//        ui->c4_4->setChecked(true);
        ui->c4_5->setChecked(true);
        ui->c4_6->setChecked(true);
        ui->c4_7->setChecked(true);
        ui->c4_8->setChecked(true);
        ui->c4_9->setChecked(true);
        ui->c4_10->setChecked(true);
        ui->c4_11->setChecked(true);
        ui->c4_12->setChecked(true);
        ui->c4_13->setChecked(true);
        ui->c4_14->setChecked(true);
        ui->c4_15->setChecked(true);
        ui->c4_16->setChecked(true);

        ////////////////////////////////////////
//        ui->c5_1->setChecked(true);
//        ui->c5_2->setChecked(true);
//        ui->c5_3->setChecked(true);
//        ui->c5_4->setChecked(true);
//        ui->c5_5->setChecked(true);
        ui->c5_6->setChecked(true);
        ui->c5_7->setChecked(true);
        ui->c5_8->setChecked(true);
        ui->c5_9->setChecked(true);
        ui->c5_10->setChecked(true);
        ui->c5_11->setChecked(true);
        ui->c5_12->setChecked(true);
        ui->c5_13->setChecked(true);
        ui->c5_14->setChecked(true);
        ui->c5_15->setChecked(true);
        ui->c5_16->setChecked(true);

        /////////////////////////////////////////
//        ui->c6_1->setChecked(true);
//        ui->c6_2->setChecked(true);
//        ui->c6_3->setChecked(true);
//        ui->c6_4->setChecked(true);
//        ui->c6_5->setChecked(true);
//        ui->c6_6->setChecked(true);
        ui->c6_7->setChecked(true);
        ui->c6_8->setChecked(true);
        ui->c6_9->setChecked(true);
        ui->c6_10->setChecked(true);
        ui->c6_11->setChecked(true);
        ui->c6_12->setChecked(true);
        ui->c6_13->setChecked(true);
        ui->c6_14->setChecked(true);
        ui->c6_15->setChecked(true);
        ui->c6_16->setChecked(true);
        ///////////////////////////////////////////
//        ui->c7_1->setChecked(true);
//        ui->c7_2->setChecked(true);
//        ui->c7_3->setChecked(true);
//        ui->c7_4->setChecked(true);
//        ui->c7_5->setChecked(true);
//        ui->c7_6->setChecked(true);
//        ui->c7_7->setChecked(true);
        ui->c7_8->setChecked(true);
        ui->c7_9->setChecked(true);
        ui->c7_10->setChecked(true);
        ui->c7_11->setChecked(true);
        ui->c7_12->setChecked(true);
        ui->c7_13->setChecked(true);
        ui->c7_14->setChecked(true);
        ui->c7_15->setChecked(true);
        ui->c7_16->setChecked(true);
        ///////////////////////////////////////
//        ui->c8_1->setChecked(true);
//        ui->c8_2->setChecked(true);
//        ui->c8_3->setChecked(true);
//        ui->c8_4->setChecked(true);
//        ui->c8_5->setChecked(true);
//        ui->c8_6->setChecked(true);
//        ui->c8_7->setChecked(true);
////        ui->c8_8->setChecked(true);
        ui->c8_9->setChecked(true);
        ui->c8_10->setChecked(true);
        ui->c8_11->setChecked(true);
        ui->c8_12->setChecked(true);
        ui->c8_13->setChecked(true);
        ui->c8_14->setChecked(true);
        ui->c8_15->setChecked(true);
        ui->c8_16->setChecked(true);
        ///////////////////////////////////////
//        ui->c9_1->setChecked(true);
//        ui->c9_2->setChecked(true);
//        ui->c9_3->setChecked(true);
//        ui->c9_4->setChecked(true);
//        ui->c9_5->setChecked(true);
//        ui->c9_6->setChecked(true);
//        ui->c9_7->setChecked(true);
//        ui->c9_8->setChecked(true);
//        ui->c9_9->setChecked(true);
        ui->c9_10->setChecked(true);
        ui->c9_11->setChecked(true);
        ui->c9_12->setChecked(true);
        ui->c9_13->setChecked(true);
        ui->c9_14->setChecked(true);
        ui->c9_15->setChecked(true);
        ui->c9_16->setChecked(true);
        ////////////////////////////////////////////
//        ui->c10_1->setChecked(true);
//        ui->c10_2->setChecked(true);
//        ui->c10_3->setChecked(true);
//        ui->c10_4->setChecked(true);
//        ui->c10_5->setChecked(true);
//        ui->c10_6->setChecked(true);
//        ui->c10_7->setChecked(true);
//        ui->c10_8->setChecked(true);
//        ui->c10_9->setChecked(true);
//        ui->c10_10->setChecked(true);
        ui->c10_11->setChecked(true);
        ui->c10_12->setChecked(true);
        ui->c10_13->setChecked(true);
        ui->c10_14->setChecked(true);
        ui->c10_15->setChecked(true);
        ui->c10_16->setChecked(true);
        ////////////////////////////////////////////
//        ui->c11_1->setChecked(true);
//        ui->c11_2->setChecked(true);
//        ui->c11_3->setChecked(true);
//        ui->c11_4->setChecked(true);
//        ui->c11_5->setChecked(true);
//        ui->c11_6->setChecked(true);
//        ui->c11_7->setChecked(true);
//        ui->c11_8->setChecked(true);
//        ui->c11_9->setChecked(true);
//        ui->c11_10->setChecked(true);
//        ui->c11_11->setChecked(true);
        ui->c11_12->setChecked(true);
        ui->c11_13->setChecked(true);
        ui->c11_14->setChecked(true);
        ui->c11_15->setChecked(true);
        ui->c11_16->setChecked(true);
        //////////////////////////////////////
//        ui->c12_1->setChecked(true);
//        ui->c12_2->setChecked(true);
//        ui->c12_3->setChecked(true);
//        ui->c12_4->setChecked(true);
//        ui->c12_5->setChecked(true);
//        ui->c12_6->setChecked(true);
//        ui->c12_7->setChecked(true);
//        ui->c12_8->setChecked(true);
//        ui->c12_9->setChecked(true);
//        ui->c12_10->setChecked(true);
//        ui->c12_11->setChecked(true);
//        ui->c12_12->setChecked(true);
        ui->c12_13->setChecked(true);
        ui->c12_14->setChecked(true);
        ui->c12_15->setChecked(true);
        ui->c12_16->setChecked(true);
        ///////////////////////////////////////
//        ui->c13_1->setChecked(true);
//        ui->c13_2->setChecked(true);
//        ui->c13_3->setChecked(true);
//        ui->c13_4->setChecked(true);
//        ui->c13_5->setChecked(true);
//        ui->c13_6->setChecked(true);
//        ui->c13_7->setChecked(true);
//        ui->c13_8->setChecked(true);
//        ui->c13_9->setChecked(true);
//        ui->c13_10->setChecked(true);
//        ui->c13_11->setChecked(true);
//        ui->c13_12->setChecked(true);
//        ui->c13_13->setChecked(true);
        ui->c13_14->setChecked(true);
        ui->c13_15->setChecked(true);
        ui->c13_16->setChecked(true);
        //////////////////////////////////////
//        ui->c14_1->setChecked(true);
//        ui->c14_2->setChecked(true);
//        ui->c14_3->setChecked(true);
//        ui->c14_4->setChecked(true);
//        ui->c14_5->setChecked(true);
//        ui->c14_6->setChecked(true);
//        ui->c14_7->setChecked(true);
//        ui->c14_8->setChecked(true);
//        ui->c14_9->setChecked(true);
//        ui->c14_10->setChecked(true);
//        ui->c14_11->setChecked(true);
//        ui->c14_12->setChecked(true);
//        ui->c14_13->setChecked(true);
//        ui->c14_14->setChecked(true);
        ui->c14_15->setChecked(true);
        ui->c14_16->setChecked(true);
        //////////////////////////////////////////
//        ui->c15_1->setChecked(true);
//        ui->c15_2->setChecked(true);
//        ui->c15_3->setChecked(true);
//        ui->c15_4->setChecked(true);
//        ui->c15_5->setChecked(true);
//        ui->c15_6->setChecked(true);
//        ui->c15_7->setChecked(true);
//        ui->c15_8->setChecked(true);
//        ui->c15_9->setChecked(true);
//        ui->c15_10->setChecked(true);
//        ui->c15_11->setChecked(true);
//        ui->c15_12->setChecked(true);
//        ui->c15_13->setChecked(true);
//        ui->c15_14->setChecked(true);
//        ui->c15_15->setChecked(true);
        ui->c15_16->setChecked(true);
        ///////////////////////////////
//        ui->c16_1->setChecked(true);
//        ui->c16_2->setChecked(true);
//        ui->c16_3->setChecked(true);
//        ui->c16_4->setChecked(true);
//        ui->c16_5->setChecked(true);
//        ui->c16_6->setChecked(true);
//        ui->c16_7->setChecked(true);
//        ui->c16_8->setChecked(true);
//        ui->c16_9->setChecked(true);
//        ui->c16_10->setChecked(true);
//        ui->c16_11->setChecked(true);
//        ui->c16_12->setChecked(true);
//        ui->c16_13->setChecked(true);
//        ui->c16_14->setChecked(true);
//        ui->c16_15->setChecked(true);
//        ui->c16_16->setChecked(true);
       }
    }
    else
    {
        {
//        ui->c1_1->setChecked(false);
        ui->c1_2->setChecked(false);
        ui->c1_3->setChecked(false);
        ui->c1_4->setChecked(false);
        ui->c1_5->setChecked(false);
        ui->c1_6->setChecked(false);
        ui->c1_7->setChecked(false);
        ui->c1_8->setChecked(false);
        ui->c1_9->setChecked(false);
        ui->c1_10->setChecked(false);
        ui->c1_11->setChecked(false);
        ui->c1_12->setChecked(false);
        ui->c1_13->setChecked(false);
        ui->c1_14->setChecked(false);
        ui->c1_15->setChecked(false);
        ui->c1_16->setChecked(false);

        //////////////////////////////////
//        ui->c2_1->setChecked(false);
//        ui->c2_2->setChecked(false);
        ui->c2_3->setChecked(false);
        ui->c2_4->setChecked(false);
        ui->c2_5->setChecked(false);
        ui->c2_6->setChecked(false);
        ui->c2_7->setChecked(false);
        ui->c2_8->setChecked(false);
        ui->c2_9->setChecked(false);
        ui->c2_10->setChecked(false);
        ui->c2_11->setChecked(false);
        ui->c2_12->setChecked(false);
        ui->c2_13->setChecked(false);
        ui->c2_14->setChecked(false);
        ui->c2_15->setChecked(false);
        ui->c2_16->setChecked(false);
        /////////////////////////////////////
//        ui->c3_1->setChecked(false);
//        ui->c3_2->setChecked(false);
//        ui->c3_3->setChecked(false);
        ui->c3_4->setChecked(false);
        ui->c3_5->setChecked(false);
        ui->c3_6->setChecked(false);
        ui->c3_7->setChecked(false);
        ui->c3_8->setChecked(false);
        ui->c3_9->setChecked(false);
        ui->c3_10->setChecked(false);
        ui->c3_11->setChecked(false);
        ui->c3_12->setChecked(false);
        ui->c3_13->setChecked(false);
        ui->c3_14->setChecked(false);
        ui->c3_15->setChecked(false);
        ui->c3_16->setChecked(false);
        ////////////////////////////////////////
//        ui->c4_1->setChecked(false);
//        ui->c4_2->setChecked(false);
//        ui->c4_3->setChecked(false);
//        ui->c4_4->setChecked(false);
        ui->c4_5->setChecked(false);
        ui->c4_6->setChecked(false);
        ui->c4_7->setChecked(false);
        ui->c4_8->setChecked(false);
        ui->c4_9->setChecked(false);
        ui->c4_10->setChecked(false);
        ui->c4_11->setChecked(false);
        ui->c4_12->setChecked(false);
        ui->c4_13->setChecked(false);
        ui->c4_14->setChecked(false);
        ui->c4_15->setChecked(false);
        ui->c4_16->setChecked(false);

        ////////////////////////////////////////
//        ui->c5_1->setChecked(false);
//        ui->c5_2->setChecked(false);
//        ui->c5_3->setChecked(false);
//        ui->c5_4->setChecked(false);
//        ui->c5_5->setChecked(false);
        ui->c5_6->setChecked(false);
        ui->c5_7->setChecked(false);
        ui->c5_8->setChecked(false);
        ui->c5_9->setChecked(false);
        ui->c5_10->setChecked(false);
        ui->c5_11->setChecked(false);
        ui->c5_12->setChecked(false);
        ui->c5_13->setChecked(false);
        ui->c5_14->setChecked(false);
        ui->c5_15->setChecked(false);
        ui->c5_16->setChecked(false);

        /////////////////////////////////////////
//        ui->c6_1->setChecked(false);
//        ui->c6_2->setChecked(false);
//        ui->c6_3->setChecked(false);
//        ui->c6_4->setChecked(false);
//        ui->c6_5->setChecked(false);
//        ui->c6_6->setChecked(false);
        ui->c6_7->setChecked(false);
        ui->c6_8->setChecked(false);
        ui->c6_9->setChecked(false);
        ui->c6_10->setChecked(false);
        ui->c6_11->setChecked(false);
        ui->c6_12->setChecked(false);
        ui->c6_13->setChecked(false);
        ui->c6_14->setChecked(false);
        ui->c6_15->setChecked(false);
        ui->c6_16->setChecked(false);
        ///////////////////////////////////////////
//        ui->c7_1->setChecked(false);
//        ui->c7_2->setChecked(false);
//        ui->c7_3->setChecked(false);
//        ui->c7_4->setChecked(false);
//        ui->c7_5->setChecked(false);
//        ui->c7_6->setChecked(false);
//        ui->c7_7->setChecked(false);
        ui->c7_8->setChecked(false);
        ui->c7_9->setChecked(false);
        ui->c7_10->setChecked(false);
        ui->c7_11->setChecked(false);
        ui->c7_12->setChecked(false);
        ui->c7_13->setChecked(false);
        ui->c7_14->setChecked(false);
        ui->c7_15->setChecked(false);
        ui->c7_16->setChecked(false);
        ///////////////////////////////////////
//        ui->c8_1->setChecked(false);
//        ui->c8_2->setChecked(false);
//        ui->c8_3->setChecked(false);
//        ui->c8_4->setChecked(false);
//        ui->c8_5->setChecked(false);
//        ui->c8_6->setChecked(false);
//        ui->c8_7->setChecked(false);
//        ui->c8_8->setChecked(false);
        ui->c8_9->setChecked(false);
        ui->c8_10->setChecked(false);
        ui->c8_11->setChecked(false);
        ui->c8_12->setChecked(false);
        ui->c8_13->setChecked(false);
        ui->c8_14->setChecked(false);
        ui->c8_15->setChecked(false);
        ui->c8_16->setChecked(false);
        ///////////////////////////////////////
//        ui->c9_1->setChecked(false);
//        ui->c9_2->setChecked(false);
//        ui->c9_3->setChecked(false);
//        ui->c9_4->setChecked(false);
//        ui->c9_5->setChecked(false);
//        ui->c9_6->setChecked(false);
//        ui->c9_7->setChecked(false);
//        ui->c9_8->setChecked(false);
//        ui->c9_9->setChecked(false);
        ui->c9_10->setChecked(false);
        ui->c9_11->setChecked(false);
        ui->c9_12->setChecked(false);
        ui->c9_13->setChecked(false);
        ui->c9_14->setChecked(false);
        ui->c9_15->setChecked(false);
        ui->c9_16->setChecked(false);
        ////////////////////////////////////////////
//        ui->c10_1->setChecked(false);
//        ui->c10_2->setChecked(false);
//        ui->c10_3->setChecked(false);
//        ui->c10_4->setChecked(false);
//        ui->c10_5->setChecked(false);
//        ui->c10_6->setChecked(false);
//        ui->c10_7->setChecked(false);
//        ui->c10_8->setChecked(false);
//        ui->c10_9->setChecked(false);
//        ui->c10_10->setChecked(false);
        ui->c10_11->setChecked(false);
        ui->c10_12->setChecked(false);
        ui->c10_13->setChecked(false);
        ui->c10_14->setChecked(false);
        ui->c10_15->setChecked(false);
        ui->c10_16->setChecked(false);
        ////////////////////////////////////////////
//        ui->c11_1->setChecked(false);
//        ui->c11_2->setChecked(false);
//        ui->c11_3->setChecked(false);
//        ui->c11_4->setChecked(false);
//        ui->c11_5->setChecked(false);
//        ui->c11_6->setChecked(false);
//        ui->c11_7->setChecked(false);
//        ui->c11_8->setChecked(false);
//        ui->c11_9->setChecked(false);
//        ui->c11_10->setChecked(false);
//        ui->c11_11->setChecked(false);
        ui->c11_12->setChecked(false);
        ui->c11_13->setChecked(false);
        ui->c11_14->setChecked(false);
        ui->c11_15->setChecked(false);
        ui->c11_16->setChecked(false);
        //////////////////////////////////////
//        ui->c12_1->setChecked(false);
//        ui->c12_2->setChecked(false);
//        ui->c12_3->setChecked(false);
//        ui->c12_4->setChecked(false);
//        ui->c12_5->setChecked(false);
//        ui->c12_6->setChecked(false);
//        ui->c12_7->setChecked(false);
//        ui->c12_8->setChecked(false);
//        ui->c12_9->setChecked(false);
//        ui->c12_10->setChecked(false);
//        ui->c12_11->setChecked(false);
//        ui->c12_12->setChecked(false);
        ui->c12_13->setChecked(false);
        ui->c12_14->setChecked(false);
        ui->c12_15->setChecked(false);
        ui->c12_16->setChecked(false);
        ///////////////////////////////////////
//        ui->c13_1->setChecked(false);
//        ui->c13_2->setChecked(false);
//        ui->c13_3->setChecked(false);
//        ui->c13_4->setChecked(false);
//        ui->c13_5->setChecked(false);
//        ui->c13_6->setChecked(false);
//        ui->c13_7->setChecked(false);
//        ui->c13_8->setChecked(false);
//        ui->c13_9->setChecked(false);
//        ui->c13_10->setChecked(false);
//        ui->c13_11->setChecked(false);
//        ui->c13_12->setChecked(false);
//        ui->c13_13->setChecked(false);
        ui->c13_14->setChecked(false);
        ui->c13_15->setChecked(false);
        ui->c13_16->setChecked(false);
        //////////////////////////////////////
//        ui->c14_1->setChecked(false);
//        ui->c14_2->setChecked(false);
//        ui->c14_3->setChecked(false);
//        ui->c14_4->setChecked(false);
//        ui->c14_5->setChecked(false);
//        ui->c14_6->setChecked(false);
//        ui->c14_7->setChecked(false);
//        ui->c14_8->setChecked(false);
//        ui->c14_9->setChecked(false);
//        ui->c14_10->setChecked(false);
//        ui->c14_11->setChecked(false);
//        ui->c14_12->setChecked(false);
//        ui->c14_13->setChecked(false);
//        ui->c14_14->setChecked(false);
        ui->c14_15->setChecked(false);
        ui->c14_16->setChecked(false);
        //////////////////////////////////////////
//        ui->c15_1->setChecked(false);
//        ui->c15_2->setChecked(false);
//        ui->c15_3->setChecked(false);
//        ui->c15_4->setChecked(false);
//        ui->c15_5->setChecked(false);
//        ui->c15_6->setChecked(false);
//        ui->c15_7->setChecked(false);
//        ui->c15_8->setChecked(false);
//        ui->c15_9->setChecked(false);
//        ui->c15_10->setChecked(false);
//        ui->c15_11->setChecked(false);
//        ui->c15_12->setChecked(false);
//        ui->c15_13->setChecked(false);
//        ui->c15_14->setChecked(false);
//        ui->c15_15->setChecked(false);
        ui->c15_16->setChecked(false);
        ///////////////////////////////
//        ui->c16_1->setChecked(false);
//        ui->c16_2->setChecked(false);
//        ui->c16_3->setChecked(false);
//        ui->c16_4->setChecked(false);
//        ui->c16_5->setChecked(false);
//        ui->c16_6->setChecked(false);
//        ui->c16_7->setChecked(false);
//        ui->c16_8->setChecked(false);
//        ui->c16_9->setChecked(false);
//        ui->c16_10->setChecked(false);
//        ui->c16_11->setChecked(false);
//        ui->c16_12->setChecked(false);
//        ui->c16_13->setChecked(false);
//        ui->c16_14->setChecked(false);
//        ui->c16_15->setChecked(false);
//        ui->c16_16->setChecked(false);
       }
    }
}

void DialogPhaseConflict::on_butquery_clicked()
{
    char buffer[60];
    buffer[0]=0x02;
    buffer[1]=0x00;
    buffer[2]=0x04;
    buffer[3]=0x80;
    buffer[4]=0x79;
    buffer[5]=0x00;
    buffer[6]=0x97;
    int len=7;
    unsigned short rssum=CommVerify((unsigned char *)buffer,len);
    buffer[len]=rssum/256;
    buffer[len+1]=rssum%256;
    this->com->WriteCom(buffer,len+2);
    revtimer->start(20);
    connect(revtimer,SIGNAL(timeout()),this,SLOT(rev()));
    timeout->start(1000);
}

void DialogPhaseConflict::on_butclearall_clicked()
{
    char buffer[60];
    buffer[0]=0x02;
    buffer[1]=0x00;
    buffer[2]=0x04;
    buffer[3]=0x81;
    buffer[4]=0x79;
    buffer[5]=0x00;
    buffer[6]=0x97;
    int len=7;
    unsigned short rssum=CommVerify((unsigned char *)buffer,len);
    buffer[len]=rssum/256;
    buffer[len+1]=rssum%256;
    this->com->WriteCom(buffer,len+2);
    revtimer->start(20);
    connect(revtimer,SIGNAL(timeout()),this,SLOT(rev()));
    timeout->start(1000);
}
