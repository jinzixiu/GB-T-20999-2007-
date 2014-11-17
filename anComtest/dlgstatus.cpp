#include "dlgstatus.h"
#include "ui_dlgstatus.h"
#include "unit.h"
#include <QDebug>
//static QList<QLabel *> QLabel_list;
//static QList<uchar> type;
//static QList<uchar> dirc;
DlgStatus::DlgStatus(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DlgStatus)
{
    ui->setupUi(this);
    this->com=new CPubSub();
    this->revtimer=new QTimer();
    this->timeout=new QTimer();
    connect(timeout,SIGNAL(timeout()),this,SLOT(warming()));
    //this->setWindowFlags(Qt::FramelessWindowHint);
    QLabel_list<<ui->bull<<ui->bull<<ui->bull<<ui->bull<<ui->bull
               <<ui->bull<<ui->bull<<ui->bull<<ui->bull
                  <<ui->bull<<ui->bull<<ui->bull<<ui->bull
                  <<ui->bull<<ui->bull<<ui->bull;    
    type<<0x00<<0x00<<0x00<<0x00<<0x00<<0x00<<0x00<<0x00<<0x00<<0x00<<0x00<<0x00<<0x00<<0x00<<0x00<<0x00;
    dirc<<0x00<<0x00<<0x00<<0x00<<0x00<<0x00<<0x00<<0x00<<0x00<<0x00<<0x00<<0x00<<0x00<<0x00<<0x00<<0x00;
    setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowMinimizeButtonHint | Qt::WindowMaximizeButtonHint);
    QTimer::singleShot(20,this,SLOT(sendd1()));
    QTimer::singleShot(300,this,SLOT(on_butinit_clicked()));
    revtimer->start(200);
    connect(revtimer,SIGNAL(timeout()),this,SLOT(rev()));
}

DlgStatus::~DlgStatus()
{
    delete ui;
    //deleteLater();
}
void DlgStatus::setcom(CPubSub *com)
{
    this->com=com;
}
void DlgStatus::dealwith(uchar* rec,int len)
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


        if(crcnum!=CommVerify((uchar*)s,num+3))
        {
            s++;
            qDebug()<<"chucuo!!!!!jiaoyan!!!";
            continue;
        }
        if((uchar)(*(s+3))==0x93)
        {
            initb1((uchar*)s);
            qDebug()<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$";
            ui->display->setText(tr("查询成功!"));
            //timeout->stop();
        }
        if((uchar)*(s+3)==0x84)//查询命令处理
        {
            if((uchar)(*(s+4))==0xb0)
            {
                initallb0((uchar*)s);
                ui->init->setText(tr("初始化控件成功!"));
            }
            if((uchar)(*(s+4))==0xb1)
            {
                initb1((uchar*)s);
                ui->display->setText(tr("查询成功!"));
                //timeout->stop();
            }
        }
        if((uchar)*(s+3)==0x85)//设置成功命令
        {
            if((uchar)(*(s+4))==0xD1)
            {
                if(ui->kaiguan->isChecked())
                    ui->kaiguan->setChecked(false);
                else
                {
                    ui->kaiguan->setChecked(true);
                }
                //timeout->stop();
            }
        }
        if((uchar)*(s+3)==0x86)//设置错误命令
        {
            if((uchar)(*(s+4))==0xcd)
            {
                ui->display->setText(tr("设置失败!"));
                timeout->stop();
            }
        }
        s +=(num+5);
        i += (num+4);
    }
}
void DlgStatus::initallb0(uchar *buffer)
{
    if(buffer[6]==0x01)
    {
        dealchannel(buffer[7],buffer[10]);
    }
    if(buffer[6]==0x02)
    {
        dealchannel(buffer[7],buffer[10]);
        dealchannel(buffer[11],buffer[14]);
    }
    if(buffer[6]==0x03)
    {
        dealchannel(buffer[7],buffer[10]);
        dealchannel(buffer[11],buffer[14]);
        dealchannel(buffer[15],buffer[18]);
    }
    if(buffer[6]==0x04)
    {
        dealchannel(buffer[7],buffer[10]);
        dealchannel(buffer[11],buffer[14]);
        dealchannel(buffer[15],buffer[18]);
        dealchannel(buffer[19],buffer[22]);
    }
    if(buffer[6]==0x05)
    {
        dealchannel(buffer[7],buffer[10]);
        dealchannel(buffer[11],buffer[14]);
        dealchannel(buffer[15],buffer[18]);
        dealchannel(buffer[19],buffer[22]);
        dealchannel(buffer[23],buffer[26]);
    }
    if(buffer[6]==0x06)
    {
        dealchannel(buffer[7],buffer[10]);
        dealchannel(buffer[11],buffer[14]);
        dealchannel(buffer[15],buffer[18]);
        dealchannel(buffer[19],buffer[22]);
        dealchannel(buffer[23],buffer[26]);
        dealchannel(buffer[27],buffer[30]);
    }
    if(buffer[6]==0x07)
    {
        dealchannel(buffer[7],buffer[10]);
        dealchannel(buffer[11],buffer[14]);
        dealchannel(buffer[15],buffer[18]);
        dealchannel(buffer[19],buffer[22]);
        dealchannel(buffer[23],buffer[26]);
        dealchannel(buffer[27],buffer[30]);
        dealchannel(buffer[31],buffer[34]);
    }
    if(buffer[6]==0x08)
    {
        dealchannel(buffer[7],buffer[10]);
        dealchannel(buffer[11],buffer[14]);
        dealchannel(buffer[15],buffer[18]);
        dealchannel(buffer[19],buffer[22]);
        dealchannel(buffer[23],buffer[26]);
        dealchannel(buffer[27],buffer[30]);
        dealchannel(buffer[31],buffer[34]);
        dealchannel(buffer[35],buffer[38]);
    }
    if(buffer[6]==0x09)
    {
        dealchannel(buffer[7],buffer[10]);
        dealchannel(buffer[11],buffer[14]);
        dealchannel(buffer[15],buffer[18]);
        dealchannel(buffer[19],buffer[22]);
        dealchannel(buffer[23],buffer[26]);
        dealchannel(buffer[27],buffer[30]);
        dealchannel(buffer[31],buffer[34]);
        dealchannel(buffer[35],buffer[38]);
        dealchannel(buffer[39],buffer[42]);
    }
    if(buffer[6]==0x0a)
    {
        dealchannel(buffer[7],buffer[10]);
        dealchannel(buffer[11],buffer[14]);
        dealchannel(buffer[15],buffer[18]);
        dealchannel(buffer[19],buffer[22]);
        dealchannel(buffer[23],buffer[26]);
        dealchannel(buffer[27],buffer[30]);
        dealchannel(buffer[31],buffer[34]);
        dealchannel(buffer[35],buffer[38]);
        dealchannel(buffer[39],buffer[42]);
        dealchannel(buffer[43],buffer[46]);
    }
    if(buffer[6]==0x0b)
    {
        dealchannel(buffer[7],buffer[10]);
        dealchannel(buffer[11],buffer[14]);
        dealchannel(buffer[15],buffer[18]);
        dealchannel(buffer[19],buffer[22]);
        dealchannel(buffer[23],buffer[26]);
        dealchannel(buffer[27],buffer[30]);
        dealchannel(buffer[31],buffer[34]);
        dealchannel(buffer[35],buffer[38]);
        dealchannel(buffer[39],buffer[42]);
        dealchannel(buffer[43],buffer[46]);
        dealchannel(buffer[47],buffer[50]);
    }
    if(buffer[6]==0x0c)
    {
        dealchannel(buffer[7],buffer[10]);
        dealchannel(buffer[11],buffer[14]);
        dealchannel(buffer[15],buffer[18]);
        dealchannel(buffer[19],buffer[22]);
        dealchannel(buffer[23],buffer[26]);
        dealchannel(buffer[27],buffer[30]);
        dealchannel(buffer[31],buffer[34]);
        dealchannel(buffer[35],buffer[38]);
        dealchannel(buffer[39],buffer[42]);
        dealchannel(buffer[43],buffer[46]);
        dealchannel(buffer[47],buffer[50]);
        dealchannel(buffer[51],buffer[54]);
    }
    if(buffer[6]==0x0d)
    {
        dealchannel(buffer[7],buffer[10]);
        dealchannel(buffer[11],buffer[14]);
        dealchannel(buffer[15],buffer[18]);
        dealchannel(buffer[19],buffer[22]);
        dealchannel(buffer[23],buffer[26]);
        dealchannel(buffer[27],buffer[30]);
        dealchannel(buffer[31],buffer[34]);
        dealchannel(buffer[35],buffer[38]);
        dealchannel(buffer[39],buffer[42]);
        dealchannel(buffer[43],buffer[46]);
        dealchannel(buffer[47],buffer[50]);
        dealchannel(buffer[51],buffer[54]);
        dealchannel(buffer[55],buffer[58]);
    }
    if(buffer[6]==0x0e)
    {
        dealchannel(buffer[7],buffer[10]);
        dealchannel(buffer[11],buffer[14]);
        dealchannel(buffer[15],buffer[18]);
        dealchannel(buffer[19],buffer[22]);
        dealchannel(buffer[23],buffer[26]);
        dealchannel(buffer[27],buffer[30]);
        dealchannel(buffer[31],buffer[34]);
        dealchannel(buffer[35],buffer[38]);
        dealchannel(buffer[39],buffer[42]);
        dealchannel(buffer[43],buffer[46]);
        dealchannel(buffer[47],buffer[50]);
        dealchannel(buffer[51],buffer[54]);
        dealchannel(buffer[55],buffer[58]);
        dealchannel(buffer[59],buffer[62]);
    }
    if(buffer[6]==0x0f)
    {
        dealchannel(buffer[7],buffer[10]);
        dealchannel(buffer[11],buffer[14]);
        dealchannel(buffer[15],buffer[18]);
        dealchannel(buffer[19],buffer[22]);
        dealchannel(buffer[23],buffer[26]);
        dealchannel(buffer[27],buffer[30]);
        dealchannel(buffer[31],buffer[34]);
        dealchannel(buffer[35],buffer[38]);
        dealchannel(buffer[39],buffer[42]);
        dealchannel(buffer[43],buffer[46]);
        dealchannel(buffer[47],buffer[50]);
        dealchannel(buffer[51],buffer[54]);
        dealchannel(buffer[55],buffer[58]);
        dealchannel(buffer[59],buffer[62]);
        dealchannel(buffer[63],buffer[66]);
    }
    if(buffer[6]==0x10)
    {
        dealchannel(buffer[7],buffer[10]);
        dealchannel(buffer[11],buffer[14]);
        dealchannel(buffer[15],buffer[18]);
        dealchannel(buffer[19],buffer[22]);
        dealchannel(buffer[23],buffer[26]);
        dealchannel(buffer[27],buffer[30]);
        dealchannel(buffer[31],buffer[34]);
        dealchannel(buffer[35],buffer[38]);
        dealchannel(buffer[39],buffer[42]);
        dealchannel(buffer[43],buffer[46]);
        dealchannel(buffer[47],buffer[50]);
        dealchannel(buffer[51],buffer[54]);
        dealchannel(buffer[55],buffer[58]);
        dealchannel(buffer[59],buffer[62]);
        dealchannel(buffer[63],buffer[66]);
        dealchannel(buffer[67],buffer[70]);
    }
//    for(int i=0;i<7;i++)
//    {
//        QLabel_list.at(3)->setText("sdfs");
//    }
}


void DlgStatus::rev()
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
            ui->textBrowser->setText(RecText);

        }
        dealwith((uchar*)RecBuf,Rlen);
    }
}

void DlgStatus::warming()
{
    ui->display->clear();
    ui->display->setText(tr("失败!请重试!"));
}


void DlgStatus::dealchannel(uchar hang,uchar parm)
{

    //QList<QLabel *> QLabel_list;
    uchar line=hang-1;
    uchar highparm=parm>>4;
    uchar lowparm=parm&0x0f;
    if((highparm==0x01)&&(lowparm==0x03))
    {QLabel_list[line]=ui->label_1_4;
        type[line]=0x03;
        dirc[line]=0x01;
    }
    if((highparm==0x01)&&(lowparm==0x05))
       { QLabel_list[line]=ui->label_1_2;
           type[line]=0x05;
           dirc[line]=0x01;
       }
    if((highparm==0x01)&&(lowparm==0x06))
       { QLabel_list[line]=ui->label_1_2;
           type[line]=0x06;
           dirc[line]=0x01;
       }
    if((highparm==0x01)&&(lowparm==0x07))
       { QLabel_list[line]=ui->label_1_1;
           type[line]=0x07;
           dirc[line]=0x01;
       }
    if((highparm==0x01)&&(lowparm==0x08))
    {QLabel_list[line]=ui->label_1_3;
        type[line]=0x08;
        dirc[line]=0x01;
    }
    if((highparm==0x01)&&(lowparm==0x09))
       { QLabel_list[line]=ui->label_1_3;
           type[line]=0x09;
           dirc[line]=0x01;
       }

        if((highparm==0x02)&&(lowparm==0x03))
        {QLabel_list[line]=ui->label_2_4;
            type[line]=0x03;
            dirc[line]=0x02;
        }
        if((highparm==0x02)&&(lowparm==0x05))
         {   QLabel_list[line]=ui->label_2_2;
             type[line]=0x05;
             dirc[line]=0x02;
         }
        if((highparm==0x02)&&(lowparm==0x06))
          {  QLabel_list[line]=ui->label_2_2;
               type[line]=0x06;
               dirc[line]=0x02;
          }
        if((highparm==0x02)&&(lowparm==0x07))
           { QLabel_list[line]=ui->label_2_1;
                type[line]=0x07;
                dirc[line]=0x02;
           }
        if((highparm==0x02)&&(lowparm==0x08))
        { QLabel_list[line]=ui->label_2_3;
             type[line]=0x08;
             dirc[line]=0x02;
        }
        if((highparm==0x02)&&(lowparm==0x09))
         {   QLabel_list[line]=ui->label_2_3;
              type[line]=0x09;
              dirc[line]=0x02;
         }

            if((highparm==0x03)&&(lowparm==0x03))
              {  QLabel_list[line]=ui->label_3_4;
                  type[line]=0x03;
                  dirc[line]=0x03;
              }
            if((highparm==0x03)&&(lowparm==0x05))
               { QLabel_list[line]=ui->label_3_2;
                   type[line]=0x05;
                   dirc[line]=0x03;
               }
            if((highparm==0x03)&&(lowparm==0x06))
              {  QLabel_list[line]=ui->label_3_2;
                  type[line]=0x06;
                  dirc[line]=0x03;
              }
            if((highparm==0x03)&&(lowparm==0x07))
              {  QLabel_list[line]=ui->label_3_1;
                  type[line]=0x07;
                  dirc[line]=0x03;
              }
            if((highparm==0x03)&&(lowparm==0x08))
               {  QLabel_list[line]=ui->label_3_3;
                   type[line]=0x08;
                   dirc[line]=0x03;
               }
            if((highparm==0x03)&&(lowparm==0x09))
              {  QLabel_list[line]=ui->label_3_3;
                  type[line]=0x09;
                  dirc[line]=0x03;
              }

    if((highparm==0x04)&&(lowparm==0x03))
    {QLabel_list[line]=ui->label_4_4;
        type[line]=0x03;
        dirc[line]=0x04;
    }
    if((highparm==0x04)&&(lowparm==0x05))
     {   QLabel_list[line]=ui->label_4_2;
         type[line]=0x05;
         dirc[line]=0x04;
     }
    if((highparm==0x04)&&(lowparm==0x06))
      {  QLabel_list[line]=ui->label_4_2;
          type[line]=0x06;
          dirc[line]=0x04;
      }
    if((highparm==0x04)&&(lowparm==0x07))
       { QLabel_list[line]=ui->label_4_1;
           type[line]=0x07;
           dirc[line]=0x04;
       }
    if((highparm==0x04)&&(lowparm==0x08))
    { QLabel_list[line]=ui->label_4_3;
        type[line]=0x08;
        dirc[line]=0x04;
    }
    if((highparm==0x04)&&(lowparm==0x09))
     {   QLabel_list[line]=ui->label_4_3;
         type[line]=0x09;
         dirc[line]=0x04;
     }

//        if((highparm==0x05)&&(lowparm==0x03))
//        if((highparm==0x05)&&(lowparm==0x05))
//        if((highparm==0x05)&&(lowparm==0x06))
//        if((highparm==0x05)&&(lowparm==0x07))
//        if((highparm==0x05)&&(lowparm==0x08))
//        if((highparm==0x05)&&(lowparm==0x09))

//    if((highparm==0x06)&&(lowparm==0x03))
//    if((highparm==0x06)&&(lowparm==0x05))
//    if((highparm==0x06)&&(lowparm==0x06))
//    if((highparm==0x06)&&(lowparm==0x07))
//    if((highparm==0x06)&&(lowparm==0x08))
//    if((highparm==0x06)&&(lowparm==0x09))

//        if((highparm==0x07)&&(lowparm==0x03))
//        if((highparm==0x07)&&(lowparm==0x05))
//        if((highparm==0x07)&&(lowparm==0x06))
//        if((highparm==0x07)&&(lowparm==0x07))
//        if((highparm==0x07)&&(lowparm==0x08))
//        if((highparm==0x07)&&(lowparm==0x09))

//    if((highparm==0x08)&&(lowparm==0x03))
//    if((highparm==0x08)&&(lowparm==0x05))
//    if((highparm==0x08)&&(lowparm==0x06))
//    if((highparm==0x08)&&(lowparm==0x07))
//    if((highparm==0x08)&&(lowparm==0x08))
//    if((highparm==0x08)&&(lowparm==0x09))


}

void DlgStatus::initb1(uchar *buffer)
{
    unsigned char parm1=*(buffer+7);
    unsigned char parm2=*(buffer+8);
    unsigned char parm3=*(buffer+9);
    unsigned char parm4=*(buffer+10);

    unsigned char parm5=*(buffer+11);
    unsigned char parm6=*(buffer+12);
    unsigned char parm7=*(buffer+13);
    unsigned char parm8=*(buffer+14);
    //===============================================

    if(parm1==0x01)
{


        {
            if(((parm2&0x01)==0x01)&&(type[0]==0x03)&&(dirc[0]==0x01))
            {
              QLabel_list[0]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
            }
            if(((parm2&0x01)==0x01)&&(type[0]==0x03)&&(dirc[0]==0x02))
            {
              QLabel_list[0]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
            }
            if(((parm2&0x01)==0x01)&&(type[0]==0x03)&&(dirc[0]==0x03))
            {
              QLabel_list[0]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
            }
            if(((parm2&0x01)==0x01)&&(type[0]==0x03)&&(dirc[0]==0x04))
            {
              QLabel_list[0]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
            }
            if(((parm2&0x01)==0x01)&&(type[0]==0x05)&&(dirc[0]==0x01))
            {
              QLabel_list[0]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
            }
            if(((parm2&0x01)==0x01)&&(type[0]==0x05)&&(dirc[0]==0x02))
            {
              QLabel_list[0]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
            }
            if(((parm2&0x01)==0x01)&&(type[0]==0x05)&&(dirc[0]==0x03))
            {
              QLabel_list[0]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
            }
            if(((parm2&0x01)==0x01)&&(type[0]==0x05)&&(dirc[0]==0x04))
            {
              QLabel_list[0]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
            }
            if(((parm2&0x01)==0x01)&&(type[0]==0x06)&&(dirc[0]==0x01))
            {
              QLabel_list[0]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R3.png);"));
            }
            if(((parm2&0x01)==0x01)&&(type[0]==0x06)&&(dirc[0]==0x02))
            {
              QLabel_list[0]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R1.png);"));
            }
            if(((parm2&0x01)==0x01)&&(type[0]==0x06)&&(dirc[0]==0x03))
            {
              QLabel_list[0]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R4.png);"));
            }
            if(((parm2&0x01)==0x01)&&(type[0]==0x06)&&(dirc[0]==0x04))
            {
              QLabel_list[0]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R2.png);"));
            }
            if(((parm2&0x01)==0x01)&&(type[0]==0x07)&&(dirc[0]==0x01))
            {
              QLabel_list[0]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R2.png);"));
            }
            if(((parm2&0x01)==0x01)&&(type[0]==0x07)&&(dirc[0]==0x02))
            {
              QLabel_list[0]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R3.png);"));
            }
            if(((parm2&0x01)==0x01)&&(type[0]==0x07)&&(dirc[0]==0x03))
            {
              QLabel_list[0]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R1.png);"));
            }
            if(((parm2&0x01)==0x01)&&(type[0]==0x07)&&(dirc[0]==0x04))
            {
              QLabel_list[0]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R4.png);"));
            }
            if(((parm2&0x01)==0x01)&&(type[0]==0x08)&&(dirc[0]==0x01))
            {
              QLabel_list[0]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R1.png);"));
            }
            if(((parm2&0x01)==0x01)&&(type[0]==0x08)&&(dirc[0]==0x02))
            {
              QLabel_list[0]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R4.png);"));
            }
            if(((parm2&0x01)==0x01)&&(type[0]==0x08)&&(dirc[0]==0x03))
            {
              QLabel_list[0]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R2.png);"));
            }
            if(((parm2&0x01)==0x01)&&(type[0]==0x08)&&(dirc[0]==0x04))
            {
              QLabel_list[0]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R3.png);"));
            }
            if(((parm2&0x01)==0x01)&&(type[0]==0x09)&&(dirc[0]==0x01))
            {
              QLabel_list[0]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/RR.png);"));
            }
            if(((parm2&0x01)==0x01)&&(type[0]==0x09)&&(dirc[0]==0x02))
            {
              QLabel_list[0]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/RR.png);"));
            }
            if(((parm2&0x01)==0x01)&&(type[0]==0x09)&&(dirc[0]==0x03))
            {
              QLabel_list[0]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/RR.png);"));
            }
            if(((parm2&0x01)==0x01)&&(type[0]==0x09)&&(dirc[0]==0x04))
            {
              QLabel_list[0]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/RR.png);"));
            }


            if(((parm2&0x02)==0x02)&&(type[1]==0x03)&&(dirc[1]==0x01))
            {
              QLabel_list[1]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
            }
            if(((parm2&0x02)==0x02)&&(type[1]==0x03)&&(dirc[1]==0x02))
            {
              QLabel_list[1]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
            }
            if(((parm2&0x02)==0x02)&&(type[1]==0x03)&&(dirc[1]==0x03))
            {
              QLabel_list[1]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
            }
            if(((parm2&0x02)==0x02)&&(type[1]==0x03)&&(dirc[1]==0x04))
            {
              QLabel_list[1]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
            }
            if(((parm2&0x02)==0x02)&&(type[1]==0x05)&&(dirc[1]==0x01))
            {
              QLabel_list[1]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
            }
            if(((parm2&0x02)==0x02)&&(type[1]==0x05)&&(dirc[1]==0x02))
            {
              QLabel_list[1]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
            }
            if(((parm2&0x02)==0x02)&&(type[1]==0x05)&&(dirc[1]==0x03))
            {
              QLabel_list[1]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
            }
            if(((parm2&0x02)==0x02)&&(type[1]==0x05)&&(dirc[1]==0x04))
            {
              QLabel_list[1]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
            }
            if(((parm2&0x02)==0x02)&&(type[1]==0x06)&&(dirc[1]==0x01))
            {
              QLabel_list[1]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R3.png);"));
            }
            if(((parm2&0x02)==0x02)&&(type[1]==0x06)&&(dirc[1]==0x02))
            {
              QLabel_list[1]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R1.png);"));
            }
            if(((parm2&0x02)==0x02)&&(type[1]==0x06)&&(dirc[1]==0x03))
            {
              QLabel_list[1]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R4.png);"));
            }
            if(((parm2&0x02)==0x02)&&(type[1]==0x06)&&(dirc[1]==0x04))
            {
              QLabel_list[1]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R2.png);"));
            }
            if(((parm2&0x02)==0x02)&&(type[1]==0x07)&&(dirc[1]==0x01))
            {
              QLabel_list[1]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R2.png);"));
            }
            if(((parm2&0x02)==0x02)&&(type[1]==0x07)&&(dirc[1]==0x02))
            {
              QLabel_list[1]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R3.png);"));
            }
            if(((parm2&0x02)==0x02)&&(type[1]==0x07)&&(dirc[1]==0x03))
            {
              QLabel_list[1]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R1.png);"));
            }
            if(((parm2&0x02)==0x02)&&(type[1]==0x07)&&(dirc[1]==0x04))
            {
              QLabel_list[1]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R4.png);"));
            }
            if(((parm2&0x02)==0x02)&&(type[1]==0x08)&&(dirc[1]==0x01))
            {
              QLabel_list[1]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R1.png);"));
            }
            if(((parm2&0x02)==0x02)&&(type[1]==0x08)&&(dirc[1]==0x02))
            {
              QLabel_list[1]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R4.png);"));
            }
            if(((parm2&0x02)==0x02)&&(type[1]==0x08)&&(dirc[1]==0x03))
            {
              QLabel_list[1]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R2.png);"));
            }
            if(((parm2&0x02)==0x02)&&(type[1]==0x08)&&(dirc[1]==0x04))
            {
              QLabel_list[1]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R3.png);"));
            }
            if(((parm2&0x02)==0x02)&&(type[1]==0x09)&&(dirc[1]==0x01))
            {
              QLabel_list[1]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/RR.png);"));
            }
            if(((parm2&0x02)==0x02)&&(type[1]==0x09)&&(dirc[1]==0x02))
            {
              QLabel_list[1]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/RR.png);"));
            }
            if(((parm2&0x02)==0x02)&&(type[1]==0x09)&&(dirc[1]==0x03))
            {
              QLabel_list[1]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/RR.png);"));
            }
            if(((parm2&0x02)==0x02)&&(type[1]==0x09)&&(dirc[1]==0x04))
            {
              QLabel_list[1]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/RR.png);"));
            }

            if(((parm2&0x04)==0x04)&&(type[2]==0x03)&&(dirc[2]==0x01))
            {
              QLabel_list[2]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
            }
            if(((parm2&0x04)==0x04)&&(type[2]==0x03)&&(dirc[2]==0x02))
            {
              QLabel_list[2]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
            }
            if(((parm2&0x04)==0x04)&&(type[2]==0x03)&&(dirc[2]==0x03))
            {
              QLabel_list[2]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
            }
            if(((parm2&0x04)==0x04)&&(type[2]==0x03)&&(dirc[2]==0x04))
            {
              QLabel_list[2]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
            }
            if(((parm2&0x04)==0x04)&&(type[2]==0x05)&&(dirc[2]==0x01))
            {
              QLabel_list[2]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
            }
            if(((parm2&0x04)==0x04)&&(type[2]==0x05)&&(dirc[2]==0x02))
            {
              QLabel_list[2]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
            }
            if(((parm2&0x04)==0x04)&&(type[2]==0x05)&&(dirc[2]==0x03))
            {
              QLabel_list[2]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
            }
            if(((parm2&0x04)==0x04)&&(type[2]==0x05)&&(dirc[2]==0x04))
            {
              QLabel_list[2]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
            }
            if(((parm2&0x04)==0x04)&&(type[2]==0x06)&&(dirc[2]==0x01))
            {
              QLabel_list[2]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R3.png);"));
            }
            if(((parm2&0x04)==0x04)&&(type[2]==0x06)&&(dirc[2]==0x02))
            {
              QLabel_list[2]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R1.png);"));
            }
            if(((parm2&0x04)==0x04)&&(type[2]==0x06)&&(dirc[2]==0x03))
            {
              QLabel_list[2]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R4.png);"));
            }
            if(((parm2&0x04)==0x04)&&(type[2]==0x06)&&(dirc[2]==0x04))
            {
              QLabel_list[2]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R2.png);"));
            }
            if(((parm2&0x04)==0x04)&&(type[2]==0x07)&&(dirc[2]==0x01))
            {
              QLabel_list[2]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R2.png);"));
            }
            if(((parm2&0x04)==0x04)&&(type[2]==0x07)&&(dirc[2]==0x02))
            {
              QLabel_list[2]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R3.png);"));
            }
            if(((parm2&0x04)==0x04)&&(type[2]==0x07)&&(dirc[2]==0x03))
            {
              QLabel_list[2]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R1.png);"));
            }
            if(((parm2&0x04)==0x04)&&(type[2]==0x07)&&(dirc[2]==0x04))
            {
              QLabel_list[2]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R4.png);"));
            }
            if(((parm2&0x04)==0x04)&&(type[2]==0x08)&&(dirc[2]==0x01))
            {
              QLabel_list[2]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R1.png);"));
            }
            if(((parm2&0x04)==0x04)&&(type[2]==0x08)&&(dirc[2]==0x02))
            {
              QLabel_list[2]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R4.png);"));
            }
            if(((parm2&0x04)==0x04)&&(type[2]==0x08)&&(dirc[2]==0x03))
            {
              QLabel_list[2]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R2.png);"));
            }
            if(((parm2&0x04)==0x04)&&(type[2]==0x08)&&(dirc[2]==0x04))
            {
              QLabel_list[2]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R3.png);"));
            }
            if(((parm2&0x04)==0x04)&&(type[2]==0x09)&&(dirc[2]==0x01))
            {
              QLabel_list[2]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/RR.png);"));
            }
            if(((parm2&0x04)==0x04)&&(type[2]==0x09)&&(dirc[2]==0x02))
            {
              QLabel_list[2]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/RR.png);"));
            }
            if(((parm2&0x04)==0x04)&&(type[2]==0x09)&&(dirc[2]==0x03))
            {
              QLabel_list[2]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/RR.png);"));
            }
            if(((parm2&0x04)==0x04)&&(type[2]==0x09)&&(dirc[2]==0x04))
            {
              QLabel_list[2]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/RR.png);"));
            }

            if(((parm2&0x08)==0x08)&&(type[3]==0x03)&&(dirc[3]==0x01))
            {
              QLabel_list[3]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
            }
            if(((parm2&0x08)==0x08)&&(type[3]==0x03)&&(dirc[3]==0x02))
            {
              QLabel_list[3]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
            }
            if(((parm2&0x08)==0x08)&&(type[3]==0x03)&&(dirc[3]==0x03))
            {
              QLabel_list[3]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
            }
            if(((parm2&0x08)==0x08)&&(type[3]==0x03)&&(dirc[3]==0x04))
            {
              QLabel_list[3]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
            }
            if(((parm2&0x08)==0x08)&&(type[3]==0x05)&&(dirc[3]==0x01))
            {
              QLabel_list[3]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
            }
            if(((parm2&0x08)==0x08)&&(type[3]==0x05)&&(dirc[3]==0x02))
            {
              QLabel_list[3]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
            }
            if(((parm2&0x08)==0x08)&&(type[3]==0x05)&&(dirc[3]==0x03))
            {
              QLabel_list[3]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
            }
            if(((parm2&0x08)==0x08)&&(type[3]==0x05)&&(dirc[3]==0x04))
            {
              QLabel_list[3]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
            }
            if(((parm2&0x08)==0x08)&&(type[3]==0x06)&&(dirc[3]==0x01))
            {
              QLabel_list[3]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R3.png);"));
            }
            if(((parm2&0x08)==0x08)&&(type[3]==0x06)&&(dirc[3]==0x02))
            {
              QLabel_list[3]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R1.png);"));
            }
            if(((parm2&0x08)==0x08)&&(type[3]==0x06)&&(dirc[3]==0x03))
            {
              QLabel_list[3]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R4.png);"));
            }
            if(((parm2&0x08)==0x08)&&(type[3]==0x06)&&(dirc[3]==0x04))
            {
              QLabel_list[3]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R2.png);"));
            }
            if(((parm2&0x08)==0x08)&&(type[3]==0x07)&&(dirc[3]==0x01))
            {
              QLabel_list[3]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R2.png);"));
            }
            if(((parm2&0x08)==0x08)&&(type[3]==0x07)&&(dirc[3]==0x02))
            {
              QLabel_list[3]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R3.png);"));
            }
            if(((parm2&0x08)==0x08)&&(type[3]==0x07)&&(dirc[3]==0x03))
            {
              QLabel_list[3]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R1.png);"));
            }
            if(((parm2&0x08)==0x08)&&(type[3]==0x07)&&(dirc[3]==0x04))
            {
              QLabel_list[3]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R4.png);"));
            }
            if(((parm2&0x08)==0x08)&&(type[3]==0x08)&&(dirc[3]==0x01))
            {
              QLabel_list[3]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R1.png);"));
            }
            if(((parm2&0x08)==0x08)&&(type[3]==0x08)&&(dirc[3]==0x02))
            {
              QLabel_list[3]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R4.png);"));
            }
            if(((parm2&0x08)==0x08)&&(type[3]==0x08)&&(dirc[3]==0x03))
            {
              QLabel_list[3]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R2.png);"));
            }
            if(((parm2&0x08)==0x08)&&(type[3]==0x08)&&(dirc[3]==0x04))
            {
              QLabel_list[3]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R3.png);"));
            }
            if(((parm2&0x08)==0x08)&&(type[3]==0x09)&&(dirc[3]==0x01))
            {
              QLabel_list[3]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/RR.png);"));
            }
            if(((parm2&0x08)==0x08)&&(type[3]==0x09)&&(dirc[3]==0x02))
            {
              QLabel_list[3]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/RR.png);"));
            }
            if(((parm2&0x08)==0x08)&&(type[3]==0x09)&&(dirc[3]==0x03))
            {
              QLabel_list[3]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/RR.png);"));
            }
            if(((parm2&0x08)==0x08)&&(type[3]==0x09)&&(dirc[3]==0x04))
            {
              QLabel_list[3]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/RR.png);"));
            }


            if(((parm2&0x10)==0x10)&&(type[4]==0x03)&&(dirc[4]==0x01))
            {
              QLabel_list[4]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
            }
            if(((parm2&0x10)==0x10)&&(type[4]==0x03)&&(dirc[4]==0x02))
            {
              QLabel_list[4]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
            }
            if(((parm2&0x10)==0x10)&&(type[4]==0x03)&&(dirc[4]==0x03))
            {
              QLabel_list[4]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
            }
            if(((parm2&0x10)==0x10)&&(type[4]==0x03)&&(dirc[4]==0x04))
            {
              QLabel_list[4]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
            }
            if(((parm2&0x10)==0x10)&&(type[4]==0x05)&&(dirc[4]==0x01))
            {
              QLabel_list[4]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
            }
            if(((parm2&0x10)==0x10)&&(type[4]==0x05)&&(dirc[4]==0x02))
            {
              QLabel_list[4]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
            }
            if(((parm2&0x10)==0x10)&&(type[4]==0x05)&&(dirc[4]==0x03))
            {
              QLabel_list[4]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
            }
            if(((parm2&0x10)==0x10)&&(type[4]==0x05)&&(dirc[4]==0x04))
            {
              QLabel_list[4]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
            }
            if(((parm2&0x10)==0x10)&&(type[4]==0x06)&&(dirc[4]==0x01))
            {
              QLabel_list[4]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R3.png);"));
            }
            if(((parm2&0x10)==0x10)&&(type[4]==0x06)&&(dirc[4]==0x02))
            {
              QLabel_list[4]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R1.png);"));
            }
            if(((parm2&0x10)==0x10)&&(type[4]==0x06)&&(dirc[4]==0x03))
            {
              QLabel_list[4]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R4.png);"));
            }
            if(((parm2&0x10)==0x10)&&(type[4]==0x06)&&(dirc[4]==0x04))
            {
              QLabel_list[4]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R2.png);"));
            }
            if(((parm2&0x10)==0x10)&&(type[4]==0x07)&&(dirc[4]==0x01))
            {
              QLabel_list[4]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R2.png);"));
            }
            if(((parm2&0x10)==0x10)&&(type[4]==0x07)&&(dirc[4]==0x02))
            {
              QLabel_list[4]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R3.png);"));
            }
            if(((parm2&0x10)==0x10)&&(type[4]==0x07)&&(dirc[4]==0x03))
            {
              QLabel_list[4]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R1.png);"));
            }
            if(((parm2&0x10)==0x10)&&(type[4]==0x07)&&(dirc[4]==0x04))
            {
              QLabel_list[4]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R4.png);"));
            }
            if(((parm2&0x10)==0x10)&&(type[4]==0x08)&&(dirc[4]==0x01))
            {
              QLabel_list[4]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R1.png);"));
            }
            if(((parm2&0x10)==0x10)&&(type[4]==0x08)&&(dirc[4]==0x02))
            {
              QLabel_list[4]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R4.png);"));
            }
            if(((parm2&0x10)==0x10)&&(type[4]==0x08)&&(dirc[4]==0x03))
            {
              QLabel_list[4]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R2.png);"));
            }
            if(((parm2&0x10)==0x10)&&(type[4]==0x08)&&(dirc[4]==0x04))
            {
              QLabel_list[4]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R3.png);"));
            }
            if(((parm2&0x10)==0x10)&&(type[4]==0x09)&&(dirc[4]==0x01))
            {
              QLabel_list[4]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/RR.png);"));
            }
            if(((parm2&0x10)==0x10)&&(type[4]==0x09)&&(dirc[4]==0x02))
            {
              QLabel_list[4]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/RR.png);"));
            }
            if(((parm2&0x10)==0x10)&&(type[4]==0x09)&&(dirc[4]==0x03))
            {
              QLabel_list[4]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/RR.png);"));
            }
            if(((parm2&0x10)==0x10)&&(type[4]==0x09)&&(dirc[4]==0x04))
            {
              QLabel_list[4]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/RR.png);"));
            }

            if(((parm2&0x20)==0x20)&&(type[5]==0x03)&&(dirc[5]==0x01))
            {
              QLabel_list[5]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
            }
            if(((parm2&0x20)==0x20)&&(type[5]==0x03)&&(dirc[5]==0x02))
            {
              QLabel_list[5]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
            }
            if(((parm2&0x20)==0x20)&&(type[5]==0x03)&&(dirc[5]==0x03))
            {
              QLabel_list[5]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
            }
            if(((parm2&0x20)==0x20)&&(type[5]==0x03)&&(dirc[5]==0x04))
            {
              QLabel_list[5]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
            }
            if(((parm2&0x20)==0x20)&&(type[5]==0x05)&&(dirc[5]==0x01))
            {
              QLabel_list[5]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
            }
            if(((parm2&0x20)==0x20)&&(type[5]==0x05)&&(dirc[5]==0x02))
            {
              QLabel_list[5]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
            }
            if(((parm2&0x20)==0x20)&&(type[5]==0x05)&&(dirc[5]==0x03))
            {
              QLabel_list[5]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
            }
            if(((parm2&0x20)==0x20)&&(type[5]==0x05)&&(dirc[5]==0x04))
            {
              QLabel_list[5]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
            }
            if(((parm2&0x20)==0x20)&&(type[5]==0x06)&&(dirc[5]==0x01))
            {
              QLabel_list[5]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R3.png);"));
            }
            if(((parm2&0x20)==0x20)&&(type[5]==0x06)&&(dirc[5]==0x02))
            {
              QLabel_list[5]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R1.png);"));
            }
            if(((parm2&0x20)==0x20)&&(type[5]==0x06)&&(dirc[5]==0x03))
            {
              QLabel_list[5]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R4.png);"));
            }
            if(((parm2&0x20)==0x20)&&(type[5]==0x06)&&(dirc[5]==0x04))
            {
              QLabel_list[5]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R2.png);"));
            }
            if(((parm2&0x20)==0x20)&&(type[5]==0x07)&&(dirc[5]==0x01))
            {
              QLabel_list[5]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R2.png);"));
            }
            if(((parm2&0x20)==0x20)&&(type[5]==0x07)&&(dirc[5]==0x02))
            {
              QLabel_list[5]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R3.png);"));
            }
            if(((parm2&0x20)==0x20)&&(type[5]==0x07)&&(dirc[5]==0x03))
            {
              QLabel_list[5]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R1.png);"));
            }
            if(((parm2&0x20)==0x20)&&(type[5]==0x07)&&(dirc[5]==0x04))
            {
              QLabel_list[5]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R4.png);"));
            }
            if(((parm2&0x20)==0x20)&&(type[5]==0x08)&&(dirc[5]==0x01))
            {
              QLabel_list[5]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R1.png);"));
            }
            if(((parm2&0x20)==0x20)&&(type[5]==0x08)&&(dirc[5]==0x02))
            {
              QLabel_list[5]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R4.png);"));
            }
            if(((parm2&0x20)==0x20)&&(type[5]==0x08)&&(dirc[5]==0x03))
            {
              QLabel_list[5]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R2.png);"));
            }
            if(((parm2&0x20)==0x20)&&(type[5]==0x08)&&(dirc[5]==0x04))
            {
              QLabel_list[5]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R3.png);"));
            }
            if(((parm2&0x20)==0x20)&&(type[5]==0x09)&&(dirc[5]==0x01))
            {
              QLabel_list[5]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/RR.png);"));
            }
            if(((parm2&0x20)==0x20)&&(type[5]==0x09)&&(dirc[5]==0x02))
            {
              QLabel_list[5]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/RR.png);"));
            }
            if(((parm2&0x20)==0x20)&&(type[5]==0x09)&&(dirc[5]==0x03))
            {
              QLabel_list[5]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/RR.png);"));
            }
            if(((parm2&0x20)==0x20)&&(type[5]==0x09)&&(dirc[5]==0x04))
            {
              QLabel_list[5]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/RR.png);"));
            }


            if(((parm2&0x40)==0x40)&&(type[6]==0x03)&&(dirc[6]==0x01))
            {
              QLabel_list[6]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
            }
            if(((parm2&0x40)==0x40)&&(type[6]==0x03)&&(dirc[6]==0x02))
            {
              QLabel_list[6]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
            }
            if(((parm2&0x40)==0x40)&&(type[6]==0x03)&&(dirc[6]==0x03))
            {
              QLabel_list[6]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
            }
            if(((parm2&0x40)==0x40)&&(type[6]==0x03)&&(dirc[6]==0x04))
            {
              QLabel_list[6]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
            }
            if(((parm2&0x40)==0x40)&&(type[6]==0x05)&&(dirc[6]==0x01))
            {
              QLabel_list[6]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
            }
            if(((parm2&0x40)==0x40)&&(type[6]==0x05)&&(dirc[6]==0x02))
            {
              QLabel_list[6]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
            }
            if(((parm2&0x40)==0x40)&&(type[6]==0x05)&&(dirc[6]==0x03))
            {
              QLabel_list[6]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
            }
            if(((parm2&0x40)==0x40)&&(type[6]==0x05)&&(dirc[6]==0x04))
            {
              QLabel_list[6]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
            }
            if(((parm2&0x40)==0x40)&&(type[6]==0x06)&&(dirc[6]==0x01))
            {
              QLabel_list[6]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R3.png);"));
            }
            if(((parm2&0x40)==0x40)&&(type[6]==0x06)&&(dirc[6]==0x02))
            {
              QLabel_list[6]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R1.png);"));
            }
            if(((parm2&0x40)==0x40)&&(type[6]==0x06)&&(dirc[6]==0x03))
            {
              QLabel_list[6]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R4.png);"));
            }
            if(((parm2&0x40)==0x40)&&(type[6]==0x06)&&(dirc[6]==0x04))
            {
              QLabel_list[6]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R2.png);"));
            }
            if(((parm2&0x40)==0x40)&&(type[6]==0x07)&&(dirc[6]==0x01))
            {
              QLabel_list[6]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R2.png);"));
            }
            if(((parm2&0x40)==0x40)&&(type[6]==0x07)&&(dirc[6]==0x02))
            {
              QLabel_list[6]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R3.png);"));
            }
            if(((parm2&0x40)==0x40)&&(type[6]==0x07)&&(dirc[6]==0x03))
            {
              QLabel_list[6]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R1.png);"));
            }
            if(((parm2&0x40)==0x40)&&(type[6]==0x07)&&(dirc[6]==0x04))
            {
              QLabel_list[6]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R4.png);"));
            }
            if(((parm2&0x40)==0x40)&&(type[6]==0x08)&&(dirc[6]==0x01))
            {
              QLabel_list[6]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R1.png);"));
            }
            if(((parm2&0x40)==0x40)&&(type[6]==0x08)&&(dirc[6]==0x02))
            {
              QLabel_list[6]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R4.png);"));
            }
            if(((parm2&0x40)==0x40)&&(type[6]==0x08)&&(dirc[6]==0x03))
            {
              QLabel_list[6]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R2.png);"));
            }
            if(((parm2&0x40)==0x40)&&(type[6]==0x08)&&(dirc[6]==0x04))
            {
              QLabel_list[6]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R3.png);"));
            }
            if(((parm2&0x40)==0x40)&&(type[6]==0x09)&&(dirc[6]==0x01))
            {
              QLabel_list[6]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/RR.png);"));
            }
            if(((parm2&0x40)==0x40)&&(type[6]==0x09)&&(dirc[6]==0x02))
            {
              QLabel_list[6]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/RR.png);"));
            }
            if(((parm2&0x40)==0x40)&&(type[6]==0x09)&&(dirc[6]==0x03))
            {
              QLabel_list[6]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/RR.png);"));
            }
            if(((parm2&0x40)==0x40)&&(type[6]==0x09)&&(dirc[6]==0x04))
            {
              QLabel_list[6]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/RR.png);"));
            }


            if(((parm2&0x80)==0x80)&&(type[7]==0x03)&&(dirc[7]==0x01))
            {
              QLabel_list[7]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
            }
            if(((parm2&0x80)==0x80)&&(type[7]==0x03)&&(dirc[7]==0x02))
            {
              QLabel_list[7]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
            }
            if(((parm2&0x80)==0x80)&&(type[7]==0x03)&&(dirc[7]==0x03))
            {
              QLabel_list[7]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
            }
            if(((parm2&0x80)==0x80)&&(type[7]==0x03)&&(dirc[7]==0x04))
            {
              QLabel_list[7]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
            }
            if(((parm2&0x80)==0x80)&&(type[7]==0x05)&&(dirc[7]==0x01))
            {
              QLabel_list[7]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
            }
            if(((parm2&0x80)==0x80)&&(type[7]==0x05)&&(dirc[7]==0x02))
            {
              QLabel_list[7]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
            }
            if(((parm2&0x80)==0x80)&&(type[7]==0x05)&&(dirc[7]==0x03))
            {
              QLabel_list[7]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
            }
            if(((parm2&0x80)==0x80)&&(type[7]==0x05)&&(dirc[7]==0x04))
            {
              QLabel_list[7]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
            }
            if(((parm2&0x80)==0x80)&&(type[7]==0x06)&&(dirc[7]==0x01))
            {
              QLabel_list[7]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R3.png);"));
            }
            if(((parm2&0x80)==0x80)&&(type[7]==0x06)&&(dirc[7]==0x02))
            {
              QLabel_list[7]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R1.png);"));
            }
            if(((parm2&0x80)==0x80)&&(type[7]==0x06)&&(dirc[7]==0x03))
            {
              QLabel_list[7]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R4.png);"));
            }
            if(((parm2&0x80)==0x80)&&(type[7]==0x06)&&(dirc[7]==0x04))
            {
              QLabel_list[7]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R2.png);"));
            }
            if(((parm2&0x80)==0x80)&&(type[7]==0x07)&&(dirc[7]==0x01))
            {
              QLabel_list[7]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R2.png);"));
            }
            if(((parm2&0x80)==0x80)&&(type[7]==0x07)&&(dirc[7]==0x02))
            {
              QLabel_list[7]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R3.png);"));
            }
            if(((parm2&0x80)==0x80)&&(type[7]==0x07)&&(dirc[7]==0x03))
            {
              QLabel_list[7]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R1.png);"));
            }
            if(((parm2&0x80)==0x80)&&(type[7]==0x07)&&(dirc[7]==0x04))
            {
              QLabel_list[7]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R4.png);"));
            }
            if(((parm2&0x80)==0x80)&&(type[7]==0x08)&&(dirc[7]==0x01))
            {
              QLabel_list[7]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R1.png);"));
            }
            if(((parm2&0x80)==0x80)&&(type[7]==0x08)&&(dirc[7]==0x02))
            {
              QLabel_list[7]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R4.png);"));
            }
            if(((parm2&0x80)==0x80)&&(type[7]==0x08)&&(dirc[7]==0x03))
            {
              QLabel_list[7]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R2.png);"));
            }
            if(((parm2&0x80)==0x80)&&(type[7]==0x08)&&(dirc[7]==0x04))
            {
              QLabel_list[7]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R3.png);"));
            }
            if(((parm2&0x80)==0x80)&&(type[7]==0x09)&&(dirc[7]==0x01))
            {
              QLabel_list[7]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/RR.png);"));
            }
            if(((parm2&0x80)==0x80)&&(type[7]==0x09)&&(dirc[7]==0x02))
            {
              QLabel_list[7]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/RR.png);"));
            }
            if(((parm2&0x80)==0x80)&&(type[7]==0x09)&&(dirc[7]==0x03))
            {
              QLabel_list[7]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/RR.png);"));
            }
            if(((parm2&0x80)==0x80)&&(type[7]==0x09)&&(dirc[7]==0x04))
            {
              QLabel_list[7]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/RR.png);"));
            }

        }



        {
            if(((parm3&0x01)==0x01)&&(type[0]==0x03)&&(dirc[0]==0x01))
            {
              QLabel_list[0]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm3&0x01)==0x01)&&(type[0]==0x03)&&(dirc[0]==0x02))
            {
              QLabel_list[0]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm3&0x01)==0x01)&&(type[0]==0x03)&&(dirc[0]==0x03))
            {
              QLabel_list[0]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm3&0x01)==0x01)&&(type[0]==0x03)&&(dirc[0]==0x04))
            {
              QLabel_list[0]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm3&0x01)==0x01)&&(type[0]==0x05)&&(dirc[0]==0x01))
            {
              QLabel_list[0]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm3&0x01)==0x01)&&(type[0]==0x05)&&(dirc[0]==0x02))
            {
              QLabel_list[0]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm3&0x01)==0x01)&&(type[0]==0x05)&&(dirc[0]==0x03))
            {
              QLabel_list[0]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm3&0x01)==0x01)&&(type[0]==0x05)&&(dirc[0]==0x04))
            {
              QLabel_list[0]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm3&0x01)==0x01)&&(type[0]==0x06)&&(dirc[0]==0x01))
            {
              QLabel_list[0]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y3.png);"));
            }
            if(((parm3&0x01)==0x01)&&(type[0]==0x06)&&(dirc[0]==0x02))
            {
              QLabel_list[0]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y1.png);"));
            }
            if(((parm3&0x01)==0x01)&&(type[0]==0x06)&&(dirc[0]==0x03))
            {
              QLabel_list[0]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y4.png);"));
            }
            if(((parm3&0x01)==0x01)&&(type[0]==0x06)&&(dirc[0]==0x04))
            {
              QLabel_list[0]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y2.png);"));
            }
            if(((parm3&0x01)==0x01)&&(type[0]==0x07)&&(dirc[0]==0x01))
            {
              QLabel_list[0]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y2.png);"));
            }
            if(((parm3&0x01)==0x01)&&(type[0]==0x07)&&(dirc[0]==0x02))
            {
              QLabel_list[0]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y3.png);"));
            }
            if(((parm3&0x01)==0x01)&&(type[0]==0x07)&&(dirc[0]==0x03))
            {
              QLabel_list[0]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y1.png);"));
            }
            if(((parm3&0x01)==0x01)&&(type[0]==0x07)&&(dirc[0]==0x04))
            {
              QLabel_list[0]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y4.png);"));
            }
            if(((parm3&0x01)==0x01)&&(type[0]==0x08)&&(dirc[0]==0x01))
            {
              QLabel_list[0]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y1.png);"));
            }
            if(((parm3&0x01)==0x01)&&(type[0]==0x08)&&(dirc[0]==0x02))
            {
              QLabel_list[0]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y4.png);"));
            }
            if(((parm3&0x01)==0x01)&&(type[0]==0x08)&&(dirc[0]==0x03))
            {
              QLabel_list[0]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y2.png);"));
            }
            if(((parm3&0x01)==0x01)&&(type[0]==0x08)&&(dirc[0]==0x04))
            {
              QLabel_list[0]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y3.png);"));
            }
            if(((parm3&0x01)==0x01)&&(type[0]==0x09)&&(dirc[0]==0x01))
            {
              QLabel_list[0]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/YY.png);"));
            }
            if(((parm3&0x01)==0x01)&&(type[0]==0x09)&&(dirc[0]==0x02))
            {
              QLabel_list[0]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/YY.png);"));
            }
            if(((parm3&0x01)==0x01)&&(type[0]==0x09)&&(dirc[0]==0x03))
            {
              QLabel_list[0]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/YY.png);"));
            }
            if(((parm3&0x01)==0x01)&&(type[0]==0x09)&&(dirc[0]==0x04))
            {
              QLabel_list[0]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/YY.png);"));
            }


            if(((parm3&0x02)==0x02)&&(type[1]==0x03)&&(dirc[1]==0x01))
            {
              QLabel_list[1]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm3&0x02)==0x02)&&(type[1]==0x03)&&(dirc[1]==0x02))
            {
              QLabel_list[1]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm3&0x02)==0x02)&&(type[1]==0x03)&&(dirc[1]==0x03))
            {
              QLabel_list[1]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm3&0x02)==0x02)&&(type[1]==0x03)&&(dirc[1]==0x04))
            {
              QLabel_list[1]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm3&0x02)==0x02)&&(type[1]==0x05)&&(dirc[1]==0x01))
            {
              QLabel_list[1]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm3&0x02)==0x02)&&(type[1]==0x05)&&(dirc[1]==0x02))
            {
              QLabel_list[1]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm3&0x02)==0x02)&&(type[1]==0x05)&&(dirc[1]==0x03))
            {
              QLabel_list[1]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm3&0x02)==0x02)&&(type[1]==0x05)&&(dirc[1]==0x04))
            {
              QLabel_list[1]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm3&0x02)==0x02)&&(type[1]==0x06)&&(dirc[1]==0x01))
            {
              QLabel_list[1]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y3.png);"));
            }
            if(((parm3&0x02)==0x02)&&(type[1]==0x06)&&(dirc[1]==0x02))
            {
              QLabel_list[1]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y1.png);"));
            }
            if(((parm3&0x02)==0x02)&&(type[1]==0x06)&&(dirc[1]==0x03))
            {
              QLabel_list[1]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y4.png);"));
            }
            if(((parm3&0x02)==0x02)&&(type[1]==0x06)&&(dirc[1]==0x04))
            {
              QLabel_list[1]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y2.png);"));
            }
            if(((parm3&0x02)==0x02)&&(type[1]==0x07)&&(dirc[1]==0x01))
            {
              QLabel_list[1]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y2.png);"));
            }
            if(((parm3&0x02)==0x02)&&(type[1]==0x07)&&(dirc[1]==0x02))
            {
              QLabel_list[1]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y3.png);"));
            }
            if(((parm3&0x02)==0x02)&&(type[1]==0x07)&&(dirc[1]==0x03))
            {
              QLabel_list[1]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y1.png);"));
            }
            if(((parm3&0x02)==0x02)&&(type[1]==0x07)&&(dirc[1]==0x04))
            {
              QLabel_list[1]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y4.png);"));
            }
            if(((parm3&0x02)==0x02)&&(type[1]==0x08)&&(dirc[1]==0x01))
            {
              QLabel_list[1]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y1.png);"));
            }
            if(((parm3&0x02)==0x02)&&(type[1]==0x08)&&(dirc[1]==0x02))
            {
              QLabel_list[1]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y4.png);"));
            }
            if(((parm3&0x02)==0x02)&&(type[1]==0x08)&&(dirc[1]==0x03))
            {
              QLabel_list[1]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y2.png);"));
            }
            if(((parm3&0x02)==0x02)&&(type[1]==0x08)&&(dirc[1]==0x04))
            {
              QLabel_list[1]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y3.png);"));
            }
            if(((parm3&0x02)==0x02)&&(type[1]==0x09)&&(dirc[1]==0x01))
            {
              QLabel_list[1]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/YY.png);"));
            }
            if(((parm3&0x02)==0x02)&&(type[1]==0x09)&&(dirc[1]==0x02))
            {
              QLabel_list[1]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/YY.png);"));
            }
            if(((parm3&0x02)==0x02)&&(type[1]==0x09)&&(dirc[1]==0x03))
            {
              QLabel_list[1]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/YY.png);"));
            }
            if(((parm3&0x02)==0x02)&&(type[1]==0x09)&&(dirc[1]==0x04))
            {
              QLabel_list[1]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/YY.png);"));
            }

            if(((parm3&0x04)==0x04)&&(type[2]==0x03)&&(dirc[2]==0x01))
            {
              QLabel_list[2]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm3&0x04)==0x04)&&(type[2]==0x03)&&(dirc[2]==0x02))
            {
              QLabel_list[2]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm3&0x04)==0x04)&&(type[2]==0x03)&&(dirc[2]==0x03))
            {
              QLabel_list[2]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm3&0x04)==0x04)&&(type[2]==0x03)&&(dirc[2]==0x04))
            {
              QLabel_list[2]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm3&0x04)==0x04)&&(type[2]==0x05)&&(dirc[2]==0x01))
            {
              QLabel_list[2]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm3&0x04)==0x04)&&(type[2]==0x05)&&(dirc[2]==0x02))
            {
              QLabel_list[2]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm3&0x04)==0x04)&&(type[2]==0x05)&&(dirc[2]==0x03))
            {
              QLabel_list[2]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm3&0x04)==0x04)&&(type[2]==0x05)&&(dirc[2]==0x04))
            {
              QLabel_list[2]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm3&0x04)==0x04)&&(type[2]==0x06)&&(dirc[2]==0x01))
            {
              QLabel_list[2]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y3.png);"));
            }
            if(((parm3&0x04)==0x04)&&(type[2]==0x06)&&(dirc[2]==0x02))
            {
              QLabel_list[2]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y1.png);"));
            }
            if(((parm3&0x04)==0x04)&&(type[2]==0x06)&&(dirc[2]==0x03))
            {
              QLabel_list[2]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y4.png);"));
            }
            if(((parm3&0x04)==0x04)&&(type[2]==0x06)&&(dirc[2]==0x04))
            {
              QLabel_list[2]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y2.png);"));
            }
            if(((parm3&0x04)==0x04)&&(type[2]==0x07)&&(dirc[2]==0x01))
            {
              QLabel_list[2]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y2.png);"));
            }
            if(((parm3&0x04)==0x04)&&(type[2]==0x07)&&(dirc[2]==0x02))
            {
              QLabel_list[2]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y3.png);"));
            }
            if(((parm3&0x04)==0x04)&&(type[2]==0x07)&&(dirc[2]==0x03))
            {
              QLabel_list[2]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y1.png);"));
            }
            if(((parm3&0x04)==0x04)&&(type[2]==0x07)&&(dirc[2]==0x04))
            {
              QLabel_list[2]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y4.png);"));
            }
            if(((parm3&0x04)==0x04)&&(type[2]==0x08)&&(dirc[2]==0x01))
            {
              QLabel_list[2]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y1.png);"));
            }
            if(((parm3&0x04)==0x04)&&(type[2]==0x08)&&(dirc[2]==0x02))
            {
              QLabel_list[2]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y4.png);"));
            }
            if(((parm3&0x04)==0x04)&&(type[2]==0x08)&&(dirc[2]==0x03))
            {
              QLabel_list[2]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y2.png);"));
            }
            if(((parm3&0x04)==0x04)&&(type[2]==0x08)&&(dirc[2]==0x04))
            {
              QLabel_list[2]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y3.png);"));
            }
            if(((parm3&0x04)==0x04)&&(type[2]==0x09)&&(dirc[2]==0x01))
            {
              QLabel_list[2]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/YY.png);"));
            }
            if(((parm3&0x04)==0x04)&&(type[2]==0x09)&&(dirc[2]==0x02))
            {
              QLabel_list[2]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/YY.png);"));
            }
            if(((parm3&0x04)==0x04)&&(type[2]==0x09)&&(dirc[2]==0x03))
            {
              QLabel_list[2]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/YY.png);"));
            }
            if(((parm3&0x04)==0x04)&&(type[2]==0x09)&&(dirc[2]==0x04))
            {
              QLabel_list[2]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/YY.png);"));
            }

            if(((parm3&0x08)==0x08)&&(type[3]==0x03)&&(dirc[3]==0x01))
            {
              QLabel_list[3]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm3&0x08)==0x08)&&(type[3]==0x03)&&(dirc[3]==0x02))
            {
              QLabel_list[3]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm3&0x08)==0x08)&&(type[3]==0x03)&&(dirc[3]==0x03))
            {
              QLabel_list[3]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm3&0x08)==0x08)&&(type[3]==0x03)&&(dirc[3]==0x04))
            {
              QLabel_list[3]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm3&0x08)==0x08)&&(type[3]==0x05)&&(dirc[3]==0x01))
            {
              QLabel_list[3]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm3&0x08)==0x08)&&(type[3]==0x05)&&(dirc[3]==0x02))
            {
              QLabel_list[3]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm3&0x08)==0x08)&&(type[3]==0x05)&&(dirc[3]==0x03))
            {
              QLabel_list[3]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm3&0x08)==0x08)&&(type[3]==0x05)&&(dirc[3]==0x04))
            {
              QLabel_list[3]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm3&0x08)==0x08)&&(type[3]==0x06)&&(dirc[3]==0x01))
            {
              QLabel_list[3]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y3.png);"));
            }
            if(((parm3&0x08)==0x08)&&(type[3]==0x06)&&(dirc[3]==0x02))
            {
              QLabel_list[3]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y1.png);"));
            }
            if(((parm3&0x08)==0x08)&&(type[3]==0x06)&&(dirc[3]==0x03))
            {
              QLabel_list[3]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y4.png);"));
            }
            if(((parm3&0x08)==0x08)&&(type[3]==0x06)&&(dirc[3]==0x04))
            {
              QLabel_list[3]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y2.png);"));
            }
            if(((parm3&0x08)==0x08)&&(type[3]==0x07)&&(dirc[3]==0x01))
            {
              QLabel_list[3]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y2.png);"));
            }
            if(((parm3&0x08)==0x08)&&(type[3]==0x07)&&(dirc[3]==0x02))
            {
              QLabel_list[3]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y3.png);"));
            }
            if(((parm3&0x08)==0x08)&&(type[3]==0x07)&&(dirc[3]==0x03))
            {
              QLabel_list[3]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y1.png);"));
            }
            if(((parm3&0x08)==0x08)&&(type[3]==0x07)&&(dirc[3]==0x04))
            {
              QLabel_list[3]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y4.png);"));
            }
            if(((parm3&0x08)==0x08)&&(type[3]==0x08)&&(dirc[3]==0x01))
            {
              QLabel_list[3]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y1.png);"));
            }
            if(((parm3&0x08)==0x08)&&(type[3]==0x08)&&(dirc[3]==0x02))
            {
              QLabel_list[3]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y4.png);"));
            }
            if(((parm3&0x08)==0x08)&&(type[3]==0x08)&&(dirc[3]==0x03))
            {
              QLabel_list[3]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y2.png);"));
            }
            if(((parm3&0x08)==0x08)&&(type[3]==0x08)&&(dirc[3]==0x04))
            {
              QLabel_list[3]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y3.png);"));
            }
            if(((parm3&0x08)==0x08)&&(type[3]==0x09)&&(dirc[3]==0x01))
            {
              QLabel_list[3]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/YY.png);"));
            }
            if(((parm3&0x08)==0x08)&&(type[3]==0x09)&&(dirc[3]==0x02))
            {
              QLabel_list[3]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/YY.png);"));
            }
            if(((parm3&0x08)==0x08)&&(type[3]==0x09)&&(dirc[3]==0x03))
            {
              QLabel_list[3]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/YY.png);"));
            }
            if(((parm3&0x08)==0x08)&&(type[3]==0x09)&&(dirc[3]==0x04))
            {
              QLabel_list[3]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/YY.png);"));
            }


            if(((parm3&0x10)==0x10)&&(type[4]==0x03)&&(dirc[4]==0x01))
            {
              QLabel_list[4]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm3&0x10)==0x10)&&(type[4]==0x03)&&(dirc[4]==0x02))
            {
              QLabel_list[4]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm3&0x10)==0x10)&&(type[4]==0x03)&&(dirc[4]==0x03))
            {
              QLabel_list[4]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm3&0x10)==0x10)&&(type[4]==0x03)&&(dirc[4]==0x04))
            {
              QLabel_list[4]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm3&0x10)==0x10)&&(type[4]==0x05)&&(dirc[4]==0x01))
            {
              QLabel_list[4]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm3&0x10)==0x10)&&(type[4]==0x05)&&(dirc[4]==0x02))
            {
              QLabel_list[4]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm3&0x10)==0x10)&&(type[4]==0x05)&&(dirc[4]==0x03))
            {
              QLabel_list[4]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm3&0x10)==0x10)&&(type[4]==0x05)&&(dirc[4]==0x04))
            {
              QLabel_list[4]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm3&0x10)==0x10)&&(type[4]==0x06)&&(dirc[4]==0x01))
            {
              QLabel_list[4]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y3.png);"));
            }
            if(((parm3&0x10)==0x10)&&(type[4]==0x06)&&(dirc[4]==0x02))
            {
              QLabel_list[4]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y1.png);"));
            }
            if(((parm3&0x10)==0x10)&&(type[4]==0x06)&&(dirc[4]==0x03))
            {
              QLabel_list[4]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y4.png);"));
            }
            if(((parm3&0x10)==0x10)&&(type[4]==0x06)&&(dirc[4]==0x04))
            {
              QLabel_list[4]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y2.png);"));
            }
            if(((parm3&0x10)==0x10)&&(type[4]==0x07)&&(dirc[4]==0x01))
            {
              QLabel_list[4]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y2.png);"));
            }
            if(((parm3&0x10)==0x10)&&(type[4]==0x07)&&(dirc[4]==0x02))
            {
              QLabel_list[4]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y3.png);"));
            }
            if(((parm3&0x10)==0x10)&&(type[4]==0x07)&&(dirc[4]==0x03))
            {
              QLabel_list[4]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y1.png);"));
            }
            if(((parm3&0x10)==0x10)&&(type[4]==0x07)&&(dirc[4]==0x04))
            {
              QLabel_list[4]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y4.png);"));
            }
            if(((parm3&0x10)==0x10)&&(type[4]==0x08)&&(dirc[4]==0x01))
            {
              QLabel_list[4]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y1.png);"));
            }
            if(((parm3&0x10)==0x10)&&(type[4]==0x08)&&(dirc[4]==0x02))
            {
              QLabel_list[4]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y4.png);"));
            }
            if(((parm3&0x10)==0x10)&&(type[4]==0x08)&&(dirc[4]==0x03))
            {
              QLabel_list[4]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y2.png);"));
            }
            if(((parm3&0x10)==0x10)&&(type[4]==0x08)&&(dirc[4]==0x04))
            {
              QLabel_list[4]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y3.png);"));
            }
            if(((parm3&0x10)==0x10)&&(type[4]==0x09)&&(dirc[4]==0x01))
            {
              QLabel_list[4]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/YY.png);"));
            }
            if(((parm3&0x10)==0x10)&&(type[4]==0x09)&&(dirc[4]==0x02))
            {
              QLabel_list[4]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/YY.png);"));
            }
            if(((parm3&0x10)==0x10)&&(type[4]==0x09)&&(dirc[4]==0x03))
            {
              QLabel_list[4]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/YY.png);"));
            }
            if(((parm3&0x10)==0x10)&&(type[4]==0x09)&&(dirc[4]==0x04))
            {
              QLabel_list[4]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/YY.png);"));
            }

            if(((parm3&0x20)==0x20)&&(type[5]==0x03)&&(dirc[5]==0x01))
            {
              QLabel_list[5]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm3&0x20)==0x20)&&(type[5]==0x03)&&(dirc[5]==0x02))
            {
              QLabel_list[5]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm3&0x20)==0x20)&&(type[5]==0x03)&&(dirc[5]==0x03))
            {
              QLabel_list[5]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm3&0x20)==0x20)&&(type[5]==0x03)&&(dirc[5]==0x04))
            {
              QLabel_list[5]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm3&0x20)==0x20)&&(type[5]==0x05)&&(dirc[5]==0x01))
            {
              QLabel_list[5]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm3&0x20)==0x20)&&(type[5]==0x05)&&(dirc[5]==0x02))
            {
              QLabel_list[5]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm3&0x20)==0x20)&&(type[5]==0x05)&&(dirc[5]==0x03))
            {
              QLabel_list[5]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm3&0x20)==0x20)&&(type[5]==0x05)&&(dirc[5]==0x04))
            {
              QLabel_list[5]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm3&0x20)==0x20)&&(type[5]==0x06)&&(dirc[5]==0x01))
            {
              QLabel_list[5]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y3.png);"));
            }
            if(((parm3&0x20)==0x20)&&(type[5]==0x06)&&(dirc[5]==0x02))
            {
              QLabel_list[5]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y1.png);"));
            }
            if(((parm3&0x20)==0x20)&&(type[5]==0x06)&&(dirc[5]==0x03))
            {
              QLabel_list[5]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y4.png);"));
            }
            if(((parm3&0x20)==0x20)&&(type[5]==0x06)&&(dirc[5]==0x04))
            {
              QLabel_list[5]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y2.png);"));
            }
            if(((parm3&0x20)==0x20)&&(type[5]==0x07)&&(dirc[5]==0x01))
            {
              QLabel_list[5]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y2.png);"));
            }
            if(((parm3&0x20)==0x20)&&(type[5]==0x07)&&(dirc[5]==0x02))
            {
              QLabel_list[5]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y3.png);"));
            }
            if(((parm3&0x20)==0x20)&&(type[5]==0x07)&&(dirc[5]==0x03))
            {
              QLabel_list[5]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y1.png);"));
            }
            if(((parm3&0x20)==0x20)&&(type[5]==0x07)&&(dirc[5]==0x04))
            {
              QLabel_list[5]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y4.png);"));
            }
            if(((parm3&0x20)==0x20)&&(type[5]==0x08)&&(dirc[5]==0x01))
            {
              QLabel_list[5]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y1.png);"));
            }
            if(((parm3&0x20)==0x20)&&(type[5]==0x08)&&(dirc[5]==0x02))
            {
              QLabel_list[5]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y4.png);"));
            }
            if(((parm3&0x20)==0x20)&&(type[5]==0x08)&&(dirc[5]==0x03))
            {
              QLabel_list[5]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y2.png);"));
            }
            if(((parm3&0x20)==0x20)&&(type[5]==0x08)&&(dirc[5]==0x04))
            {
              QLabel_list[5]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y3.png);"));
            }
            if(((parm3&0x20)==0x20)&&(type[5]==0x09)&&(dirc[5]==0x01))
            {
              QLabel_list[5]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/YY.png);"));
            }
            if(((parm3&0x20)==0x20)&&(type[5]==0x09)&&(dirc[5]==0x02))
            {
              QLabel_list[5]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/YY.png);"));
            }
            if(((parm3&0x20)==0x20)&&(type[5]==0x09)&&(dirc[5]==0x03))
            {
              QLabel_list[5]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/YY.png);"));
            }
            if(((parm3&0x20)==0x20)&&(type[5]==0x09)&&(dirc[5]==0x04))
            {
              QLabel_list[5]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/YY.png);"));
            }


            if(((parm3&0x40)==0x40)&&(type[6]==0x03)&&(dirc[6]==0x01))
            {
              QLabel_list[6]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm3&0x40)==0x40)&&(type[6]==0x03)&&(dirc[6]==0x02))
            {
              QLabel_list[6]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm3&0x40)==0x40)&&(type[6]==0x03)&&(dirc[6]==0x03))
            {
              QLabel_list[6]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm3&0x40)==0x40)&&(type[6]==0x03)&&(dirc[6]==0x04))
            {
              QLabel_list[6]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm3&0x40)==0x40)&&(type[6]==0x05)&&(dirc[6]==0x01))
            {
              QLabel_list[6]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm3&0x40)==0x40)&&(type[6]==0x05)&&(dirc[6]==0x02))
            {
              QLabel_list[6]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm3&0x40)==0x40)&&(type[6]==0x05)&&(dirc[6]==0x03))
            {
              QLabel_list[6]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm3&0x40)==0x40)&&(type[6]==0x05)&&(dirc[6]==0x04))
            {
              QLabel_list[6]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm3&0x40)==0x40)&&(type[6]==0x06)&&(dirc[6]==0x01))
            {
              QLabel_list[6]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y3.png);"));
            }
            if(((parm3&0x40)==0x40)&&(type[6]==0x06)&&(dirc[6]==0x02))
            {
              QLabel_list[6]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y1.png);"));
            }
            if(((parm3&0x40)==0x40)&&(type[6]==0x06)&&(dirc[6]==0x03))
            {
              QLabel_list[6]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y4.png);"));
            }
            if(((parm3&0x40)==0x40)&&(type[6]==0x06)&&(dirc[6]==0x04))
            {
              QLabel_list[6]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y2.png);"));
            }
            if(((parm3&0x40)==0x40)&&(type[6]==0x07)&&(dirc[6]==0x01))
            {
              QLabel_list[6]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y2.png);"));
            }
            if(((parm3&0x40)==0x40)&&(type[6]==0x07)&&(dirc[6]==0x02))
            {
              QLabel_list[6]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y3.png);"));
            }
            if(((parm3&0x40)==0x40)&&(type[6]==0x07)&&(dirc[6]==0x03))
            {
              QLabel_list[6]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y1.png);"));
            }
            if(((parm3&0x40)==0x40)&&(type[6]==0x07)&&(dirc[6]==0x04))
            {
              QLabel_list[6]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y4.png);"));
            }
            if(((parm3&0x40)==0x40)&&(type[6]==0x08)&&(dirc[6]==0x01))
            {
              QLabel_list[6]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y1.png);"));
            }
            if(((parm3&0x40)==0x40)&&(type[6]==0x08)&&(dirc[6]==0x02))
            {
              QLabel_list[6]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y4.png);"));
            }
            if(((parm3&0x40)==0x40)&&(type[6]==0x08)&&(dirc[6]==0x03))
            {
              QLabel_list[6]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y2.png);"));
            }
            if(((parm3&0x40)==0x40)&&(type[6]==0x08)&&(dirc[6]==0x04))
            {
              QLabel_list[6]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y3.png);"));
            }
            if(((parm3&0x40)==0x40)&&(type[6]==0x09)&&(dirc[6]==0x01))
            {
              QLabel_list[6]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/YY.png);"));
            }
            if(((parm3&0x40)==0x40)&&(type[6]==0x09)&&(dirc[6]==0x02))
            {
              QLabel_list[6]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/YY.png);"));
            }
            if(((parm3&0x40)==0x40)&&(type[6]==0x09)&&(dirc[6]==0x03))
            {
              QLabel_list[6]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/YY.png);"));
            }
            if(((parm3&0x40)==0x40)&&(type[6]==0x09)&&(dirc[6]==0x04))
            {
              QLabel_list[6]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/YY.png);"));
            }


            if(((parm3&0x80)==0x80)&&(type[7]==0x03)&&(dirc[7]==0x01))
            {
              QLabel_list[7]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm3&0x80)==0x80)&&(type[7]==0x03)&&(dirc[7]==0x02))
            {
              QLabel_list[7]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm3&0x80)==0x80)&&(type[7]==0x03)&&(dirc[7]==0x03))
            {
              QLabel_list[7]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm3&0x80)==0x80)&&(type[7]==0x03)&&(dirc[7]==0x04))
            {
              QLabel_list[7]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm3&0x80)==0x80)&&(type[7]==0x05)&&(dirc[7]==0x01))
            {
              QLabel_list[7]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm3&0x80)==0x80)&&(type[7]==0x05)&&(dirc[7]==0x02))
            {
              QLabel_list[7]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm3&0x80)==0x80)&&(type[7]==0x05)&&(dirc[7]==0x03))
            {
              QLabel_list[7]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm3&0x80)==0x80)&&(type[7]==0x05)&&(dirc[7]==0x04))
            {
              QLabel_list[7]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm3&0x80)==0x80)&&(type[7]==0x06)&&(dirc[7]==0x01))
            {
              QLabel_list[7]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y3.png);"));
            }
            if(((parm3&0x80)==0x80)&&(type[7]==0x06)&&(dirc[7]==0x02))
            {
              QLabel_list[7]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y1.png);"));
            }
            if(((parm3&0x80)==0x80)&&(type[7]==0x06)&&(dirc[7]==0x03))
            {
              QLabel_list[7]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y4.png);"));
            }
            if(((parm3&0x80)==0x80)&&(type[7]==0x06)&&(dirc[7]==0x04))
            {
              QLabel_list[7]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y2.png);"));
            }
            if(((parm3&0x80)==0x80)&&(type[7]==0x07)&&(dirc[7]==0x01))
            {
              QLabel_list[7]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y2.png);"));
            }
            if(((parm3&0x80)==0x80)&&(type[7]==0x07)&&(dirc[7]==0x02))
            {
              QLabel_list[7]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y3.png);"));
            }
            if(((parm3&0x80)==0x80)&&(type[7]==0x07)&&(dirc[7]==0x03))
            {
              QLabel_list[7]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y1.png);"));
            }
            if(((parm3&0x80)==0x80)&&(type[7]==0x07)&&(dirc[7]==0x04))
            {
              QLabel_list[7]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y4.png);"));
            }
            if(((parm3&0x80)==0x80)&&(type[7]==0x08)&&(dirc[7]==0x01))
            {
              QLabel_list[7]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y1.png);"));
            }
            if(((parm3&0x80)==0x80)&&(type[7]==0x08)&&(dirc[7]==0x02))
            {
              QLabel_list[7]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y4.png);"));
            }
            if(((parm3&0x80)==0x80)&&(type[7]==0x08)&&(dirc[7]==0x03))
            {
              QLabel_list[7]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y2.png);"));
            }
            if(((parm3&0x80)==0x80)&&(type[7]==0x08)&&(dirc[7]==0x04))
            {
              QLabel_list[7]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y3.png);"));
            }
            if(((parm3&0x80)==0x80)&&(type[7]==0x09)&&(dirc[7]==0x01))
            {
              QLabel_list[7]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/YY.png);"));
            }
            if(((parm3&0x80)==0x80)&&(type[7]==0x09)&&(dirc[7]==0x02))
            {
              QLabel_list[7]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/YY.png);"));
            }
            if(((parm3&0x80)==0x80)&&(type[7]==0x09)&&(dirc[7]==0x03))
            {
              QLabel_list[7]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/YY.png);"));
            }
            if(((parm3&0x80)==0x80)&&(type[7]==0x09)&&(dirc[7]==0x04))
            {
              QLabel_list[7]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/YY.png);"));
            }

        }




    {
        if(((parm4&0x01)==0x01)&&(type[0]==0x03)&&(dirc[0]==0x01))
        {
          QLabel_list[0]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
        }
        if(((parm4&0x01)==0x01)&&(type[0]==0x03)&&(dirc[0]==0x02))
        {
          QLabel_list[0]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
        }
        if(((parm4&0x01)==0x01)&&(type[0]==0x03)&&(dirc[0]==0x03))
        {
          QLabel_list[0]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
        }
        if(((parm4&0x01)==0x01)&&(type[0]==0x03)&&(dirc[0]==0x04))
        {
          QLabel_list[0]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
        }
        if(((parm4&0x01)==0x01)&&(type[0]==0x05)&&(dirc[0]==0x01))
        {
          QLabel_list[0]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
        }
        if(((parm4&0x01)==0x01)&&(type[0]==0x05)&&(dirc[0]==0x02))
        {
          QLabel_list[0]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
        }
        if(((parm4&0x01)==0x01)&&(type[0]==0x05)&&(dirc[0]==0x03))
        {
          QLabel_list[0]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
        }
        if(((parm4&0x01)==0x01)&&(type[0]==0x05)&&(dirc[0]==0x04))
        {
          QLabel_list[0]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
        }
        if(((parm4&0x01)==0x01)&&(type[0]==0x06)&&(dirc[0]==0x01))
        {
          QLabel_list[0]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G3.png);"));
        }
        if(((parm4&0x01)==0x01)&&(type[0]==0x06)&&(dirc[0]==0x02))
        {
          QLabel_list[0]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G1.png);"));
        }
        if(((parm4&0x01)==0x01)&&(type[0]==0x06)&&(dirc[0]==0x03))
        {
          QLabel_list[0]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G4.png);"));
        }
        if(((parm4&0x01)==0x01)&&(type[0]==0x06)&&(dirc[0]==0x04))
        {
          QLabel_list[0]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G2.png);"));
        }
        if(((parm4&0x01)==0x01)&&(type[0]==0x07)&&(dirc[0]==0x01))
        {
          QLabel_list[0]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G2.png);"));
        }
        if(((parm4&0x01)==0x01)&&(type[0]==0x07)&&(dirc[0]==0x02))
        {
          QLabel_list[0]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G3.png);"));
        }
        if(((parm4&0x01)==0x01)&&(type[0]==0x07)&&(dirc[0]==0x03))
        {
          QLabel_list[0]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G1.png);"));
        }
        if(((parm4&0x01)==0x01)&&(type[0]==0x07)&&(dirc[0]==0x04))
        {
          QLabel_list[0]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G4.png);"));
        }
        if(((parm4&0x01)==0x01)&&(type[0]==0x08)&&(dirc[0]==0x01))
        {
          QLabel_list[0]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G1.png);"));
        }
        if(((parm4&0x01)==0x01)&&(type[0]==0x08)&&(dirc[0]==0x02))
        {
          QLabel_list[0]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G4.png);"));
        }
        if(((parm4&0x01)==0x01)&&(type[0]==0x08)&&(dirc[0]==0x03))
        {
          QLabel_list[0]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G2.png);"));
        }
        if(((parm4&0x01)==0x01)&&(type[0]==0x08)&&(dirc[0]==0x04))
        {
          QLabel_list[0]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G3.png);"));
        }
        if(((parm4&0x01)==0x01)&&(type[0]==0x09)&&(dirc[0]==0x01))
        {
          QLabel_list[0]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/GG.png);"));
        }
        if(((parm4&0x01)==0x01)&&(type[0]==0x09)&&(dirc[0]==0x02))
        {
          QLabel_list[0]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/GG.png);"));
        }
        if(((parm4&0x01)==0x01)&&(type[0]==0x09)&&(dirc[0]==0x03))
        {
          QLabel_list[0]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/GG.png);"));
        }
        if(((parm4&0x01)==0x01)&&(type[0]==0x09)&&(dirc[0]==0x04))
        {
          QLabel_list[0]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/GG.png);"));
        }


        if(((parm4&0x02)==0x02)&&(type[1]==0x03)&&(dirc[1]==0x01))
        {
          QLabel_list[1]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
        }
        if(((parm4&0x02)==0x02)&&(type[1]==0x03)&&(dirc[1]==0x02))
        {
          QLabel_list[1]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
        }
        if(((parm4&0x02)==0x02)&&(type[1]==0x03)&&(dirc[1]==0x03))
        {
          QLabel_list[1]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
        }
        if(((parm4&0x02)==0x02)&&(type[1]==0x03)&&(dirc[1]==0x04))
        {
          QLabel_list[1]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
        }
        if(((parm4&0x02)==0x02)&&(type[1]==0x05)&&(dirc[1]==0x01))
        {
          QLabel_list[1]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
        }
        if(((parm4&0x02)==0x02)&&(type[1]==0x05)&&(dirc[1]==0x02))
        {
          QLabel_list[1]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
        }
        if(((parm4&0x02)==0x02)&&(type[1]==0x05)&&(dirc[1]==0x03))
        {
          QLabel_list[1]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
        }
        if(((parm4&0x02)==0x02)&&(type[1]==0x05)&&(dirc[1]==0x04))
        {
          QLabel_list[1]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
        }
        if(((parm4&0x02)==0x02)&&(type[1]==0x06)&&(dirc[1]==0x01))
        {
          QLabel_list[1]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G3.png);"));
        }
        if(((parm4&0x02)==0x02)&&(type[1]==0x06)&&(dirc[1]==0x02))
        {
          QLabel_list[1]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G1.png);"));
        }
        if(((parm4&0x02)==0x02)&&(type[1]==0x06)&&(dirc[1]==0x03))
        {
          QLabel_list[1]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G4.png);"));
        }
        if(((parm4&0x02)==0x02)&&(type[1]==0x06)&&(dirc[1]==0x04))
        {
          QLabel_list[1]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G2.png);"));
        }
        if(((parm4&0x02)==0x02)&&(type[1]==0x07)&&(dirc[1]==0x01))
        {
          QLabel_list[1]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G2.png);"));
        }
        if(((parm4&0x02)==0x02)&&(type[1]==0x07)&&(dirc[1]==0x02))
        {
          QLabel_list[1]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G3.png);"));
        }
        if(((parm4&0x02)==0x02)&&(type[1]==0x07)&&(dirc[1]==0x03))
        {
          QLabel_list[1]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G1.png);"));
        }
        if(((parm4&0x02)==0x02)&&(type[1]==0x07)&&(dirc[1]==0x04))
        {
          QLabel_list[1]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G4.png);"));
        }
        if(((parm4&0x02)==0x02)&&(type[1]==0x08)&&(dirc[1]==0x01))
        {
          QLabel_list[1]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G1.png);"));
        }
        if(((parm4&0x02)==0x02)&&(type[1]==0x08)&&(dirc[1]==0x02))
        {
          QLabel_list[1]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G4.png);"));
        }
        if(((parm4&0x02)==0x02)&&(type[1]==0x08)&&(dirc[1]==0x03))
        {
          QLabel_list[1]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G2.png);"));
        }
        if(((parm4&0x02)==0x02)&&(type[1]==0x08)&&(dirc[1]==0x04))
        {
          QLabel_list[1]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G3.png);"));
        }
        if(((parm4&0x02)==0x02)&&(type[1]==0x09)&&(dirc[1]==0x01))
        {
          QLabel_list[1]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/GG.png);"));
        }
        if(((parm4&0x02)==0x02)&&(type[1]==0x09)&&(dirc[1]==0x02))
        {
          QLabel_list[1]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/GG.png);"));
        }
        if(((parm4&0x02)==0x02)&&(type[1]==0x09)&&(dirc[1]==0x03))
        {
          QLabel_list[1]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/GG.png);"));
        }
        if(((parm4&0x02)==0x02)&&(type[1]==0x09)&&(dirc[1]==0x04))
        {
          QLabel_list[1]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/GG.png);"));
        }

        if(((parm4&0x04)==0x04)&&(type[2]==0x03)&&(dirc[2]==0x01))
        {
          QLabel_list[2]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
        }
        if(((parm4&0x04)==0x04)&&(type[2]==0x03)&&(dirc[2]==0x02))
        {
          QLabel_list[2]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
        }
        if(((parm4&0x04)==0x04)&&(type[2]==0x03)&&(dirc[2]==0x03))
        {
          QLabel_list[2]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
        }
        if(((parm4&0x04)==0x04)&&(type[2]==0x03)&&(dirc[2]==0x04))
        {
          QLabel_list[2]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
        }
        if(((parm4&0x04)==0x04)&&(type[2]==0x05)&&(dirc[2]==0x01))
        {
          QLabel_list[2]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
        }
        if(((parm4&0x04)==0x04)&&(type[2]==0x05)&&(dirc[2]==0x02))
        {
          QLabel_list[2]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
        }
        if(((parm4&0x04)==0x04)&&(type[2]==0x05)&&(dirc[2]==0x03))
        {
          QLabel_list[2]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
        }
        if(((parm4&0x04)==0x04)&&(type[2]==0x05)&&(dirc[2]==0x04))
        {
          QLabel_list[2]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
        }
        if(((parm4&0x04)==0x04)&&(type[2]==0x06)&&(dirc[2]==0x01))
        {
          QLabel_list[2]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G3.png);"));
        }
        if(((parm4&0x04)==0x04)&&(type[2]==0x06)&&(dirc[2]==0x02))
        {
          QLabel_list[2]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G1.png);"));
        }
        if(((parm4&0x04)==0x04)&&(type[2]==0x06)&&(dirc[2]==0x03))
        {
          QLabel_list[2]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G4.png);"));
        }
        if(((parm4&0x04)==0x04)&&(type[2]==0x06)&&(dirc[2]==0x04))
        {
          QLabel_list[2]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G2.png);"));
        }
        if(((parm4&0x04)==0x04)&&(type[2]==0x07)&&(dirc[2]==0x01))
        {
          QLabel_list[2]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G2.png);"));
        }
        if(((parm4&0x04)==0x04)&&(type[2]==0x07)&&(dirc[2]==0x02))
        {
          QLabel_list[2]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G3.png);"));
        }
        if(((parm4&0x04)==0x04)&&(type[2]==0x07)&&(dirc[2]==0x03))
        {
          QLabel_list[2]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G1.png);"));
        }
        if(((parm4&0x04)==0x04)&&(type[2]==0x07)&&(dirc[2]==0x04))
        {
          QLabel_list[2]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G4.png);"));
        }
        if(((parm4&0x04)==0x04)&&(type[2]==0x08)&&(dirc[2]==0x01))
        {
          QLabel_list[2]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G1.png);"));
        }
        if(((parm4&0x04)==0x04)&&(type[2]==0x08)&&(dirc[2]==0x02))
        {
          QLabel_list[2]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G4.png);"));
        }
        if(((parm4&0x04)==0x04)&&(type[2]==0x08)&&(dirc[2]==0x03))
        {
          QLabel_list[2]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G2.png);"));
        }
        if(((parm4&0x04)==0x04)&&(type[2]==0x08)&&(dirc[2]==0x04))
        {
          QLabel_list[2]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G3.png);"));
        }
        if(((parm4&0x04)==0x04)&&(type[2]==0x09)&&(dirc[2]==0x01))
        {
          QLabel_list[2]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/GG.png);"));
        }
        if(((parm4&0x04)==0x04)&&(type[2]==0x09)&&(dirc[2]==0x02))
        {
          QLabel_list[2]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/GG.png);"));
        }
        if(((parm4&0x04)==0x04)&&(type[2]==0x09)&&(dirc[2]==0x03))
        {
          QLabel_list[2]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/GG.png);"));
        }
        if(((parm4&0x04)==0x04)&&(type[2]==0x09)&&(dirc[2]==0x04))
        {
          QLabel_list[2]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/GG.png);"));
        }

        if(((parm4&0x08)==0x08)&&(type[3]==0x03)&&(dirc[3]==0x01))
        {
          QLabel_list[3]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
        }
        if(((parm4&0x08)==0x08)&&(type[3]==0x03)&&(dirc[3]==0x02))
        {
          QLabel_list[3]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
        }
        if(((parm4&0x08)==0x08)&&(type[3]==0x03)&&(dirc[3]==0x03))
        {
          QLabel_list[3]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
        }
        if(((parm4&0x08)==0x08)&&(type[3]==0x03)&&(dirc[3]==0x04))
        {
          QLabel_list[3]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
        }
        if(((parm4&0x08)==0x08)&&(type[3]==0x05)&&(dirc[3]==0x01))
        {
          QLabel_list[3]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
        }
        if(((parm4&0x08)==0x08)&&(type[3]==0x05)&&(dirc[3]==0x02))
        {
          QLabel_list[3]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
        }
        if(((parm4&0x08)==0x08)&&(type[3]==0x05)&&(dirc[3]==0x03))
        {
          QLabel_list[3]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
        }
        if(((parm4&0x08)==0x08)&&(type[3]==0x05)&&(dirc[3]==0x04))
        {
          QLabel_list[3]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
        }
        if(((parm4&0x08)==0x08)&&(type[3]==0x06)&&(dirc[3]==0x01))
        {
          QLabel_list[3]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G3.png);"));
        }
        if(((parm4&0x08)==0x08)&&(type[3]==0x06)&&(dirc[3]==0x02))
        {
          QLabel_list[3]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G1.png);"));
        }
        if(((parm4&0x08)==0x08)&&(type[3]==0x06)&&(dirc[3]==0x03))
        {
          QLabel_list[3]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G4.png);"));
        }
        if(((parm4&0x08)==0x08)&&(type[3]==0x06)&&(dirc[3]==0x04))
        {
          QLabel_list[3]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G2.png);"));
        }
        if(((parm4&0x08)==0x08)&&(type[3]==0x07)&&(dirc[3]==0x01))
        {
          QLabel_list[3]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G2.png);"));
        }
        if(((parm4&0x08)==0x08)&&(type[3]==0x07)&&(dirc[3]==0x02))
        {
          QLabel_list[3]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G3.png);"));
        }
        if(((parm4&0x08)==0x08)&&(type[3]==0x07)&&(dirc[3]==0x03))
        {
          QLabel_list[3]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G1.png);"));
        }
        if(((parm4&0x08)==0x08)&&(type[3]==0x07)&&(dirc[3]==0x04))
        {
          QLabel_list[3]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G4.png);"));
        }
        if(((parm4&0x08)==0x08)&&(type[3]==0x08)&&(dirc[3]==0x01))
        {
          QLabel_list[3]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G1.png);"));
        }
        if(((parm4&0x08)==0x08)&&(type[3]==0x08)&&(dirc[3]==0x02))
        {
          QLabel_list[3]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G4.png);"));
        }
        if(((parm4&0x08)==0x08)&&(type[3]==0x08)&&(dirc[3]==0x03))
        {
          QLabel_list[3]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G2.png);"));
        }
        if(((parm4&0x08)==0x08)&&(type[3]==0x08)&&(dirc[3]==0x04))
        {
          QLabel_list[3]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G3.png);"));
        }
        if(((parm4&0x08)==0x08)&&(type[3]==0x09)&&(dirc[3]==0x01))
        {
          QLabel_list[3]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/GG.png);"));
        }
        if(((parm4&0x08)==0x08)&&(type[3]==0x09)&&(dirc[3]==0x02))
        {
          QLabel_list[3]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/GG.png);"));
        }
        if(((parm4&0x08)==0x08)&&(type[3]==0x09)&&(dirc[3]==0x03))
        {
          QLabel_list[3]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/GG.png);"));
        }
        if(((parm4&0x08)==0x08)&&(type[3]==0x09)&&(dirc[3]==0x04))
        {
          QLabel_list[3]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/GG.png);"));
        }


        if(((parm4&0x10)==0x10)&&(type[4]==0x03)&&(dirc[4]==0x01))
        {
          QLabel_list[4]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
        }
        if(((parm4&0x10)==0x10)&&(type[4]==0x03)&&(dirc[4]==0x02))
        {
          QLabel_list[4]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
        }
        if(((parm4&0x10)==0x10)&&(type[4]==0x03)&&(dirc[4]==0x03))
        {
          QLabel_list[4]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
        }
        if(((parm4&0x10)==0x10)&&(type[4]==0x03)&&(dirc[4]==0x04))
        {
          QLabel_list[4]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
        }
        if(((parm4&0x10)==0x10)&&(type[4]==0x05)&&(dirc[4]==0x01))
        {
          QLabel_list[4]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
        }
        if(((parm4&0x10)==0x10)&&(type[4]==0x05)&&(dirc[4]==0x02))
        {
          QLabel_list[4]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
        }
        if(((parm4&0x10)==0x10)&&(type[4]==0x05)&&(dirc[4]==0x03))
        {
          QLabel_list[4]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
        }
        if(((parm4&0x10)==0x10)&&(type[4]==0x05)&&(dirc[4]==0x04))
        {
          QLabel_list[4]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
        }
        if(((parm4&0x10)==0x10)&&(type[4]==0x06)&&(dirc[4]==0x01))
        {
          QLabel_list[4]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G3.png);"));
        }
        if(((parm4&0x10)==0x10)&&(type[4]==0x06)&&(dirc[4]==0x02))
        {
          QLabel_list[4]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G1.png);"));
        }
        if(((parm4&0x10)==0x10)&&(type[4]==0x06)&&(dirc[4]==0x03))
        {
          QLabel_list[4]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G4.png);"));
        }
        if(((parm4&0x10)==0x10)&&(type[4]==0x06)&&(dirc[4]==0x04))
        {
          QLabel_list[4]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G2.png);"));
        }
        if(((parm4&0x10)==0x10)&&(type[4]==0x07)&&(dirc[4]==0x01))
        {
          QLabel_list[4]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G2.png);"));
        }
        if(((parm4&0x10)==0x10)&&(type[4]==0x07)&&(dirc[4]==0x02))
        {
          QLabel_list[4]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G3.png);"));
        }
        if(((parm4&0x10)==0x10)&&(type[4]==0x07)&&(dirc[4]==0x03))
        {
          QLabel_list[4]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G1.png);"));
        }
        if(((parm4&0x10)==0x10)&&(type[4]==0x07)&&(dirc[4]==0x04))
        {
          QLabel_list[4]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G4.png);"));
        }
        if(((parm4&0x10)==0x10)&&(type[4]==0x08)&&(dirc[4]==0x01))
        {
          QLabel_list[4]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G1.png);"));
        }
        if(((parm4&0x10)==0x10)&&(type[4]==0x08)&&(dirc[4]==0x02))
        {
          QLabel_list[4]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G4.png);"));
        }
        if(((parm4&0x10)==0x10)&&(type[4]==0x08)&&(dirc[4]==0x03))
        {
          QLabel_list[4]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G2.png);"));
        }
        if(((parm4&0x10)==0x10)&&(type[4]==0x08)&&(dirc[4]==0x04))
        {
          QLabel_list[4]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G3.png);"));
        }
        if(((parm4&0x10)==0x10)&&(type[4]==0x09)&&(dirc[4]==0x01))
        {
          QLabel_list[4]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/GG.png);"));
        }
        if(((parm4&0x10)==0x10)&&(type[4]==0x09)&&(dirc[4]==0x02))
        {
          QLabel_list[4]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/GG.png);"));
        }
        if(((parm4&0x10)==0x10)&&(type[4]==0x09)&&(dirc[4]==0x03))
        {
          QLabel_list[4]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/GG.png);"));
        }
        if(((parm4&0x10)==0x10)&&(type[4]==0x09)&&(dirc[4]==0x04))
        {
          QLabel_list[4]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/GG.png);"));
        }

        if(((parm4&0x20)==0x20)&&(type[5]==0x03)&&(dirc[5]==0x01))
        {
          QLabel_list[5]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
        }
        if(((parm4&0x20)==0x20)&&(type[5]==0x03)&&(dirc[5]==0x02))
        {
          QLabel_list[5]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
        }
        if(((parm4&0x20)==0x20)&&(type[5]==0x03)&&(dirc[5]==0x03))
        {
          QLabel_list[5]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
        }
        if(((parm4&0x20)==0x20)&&(type[5]==0x03)&&(dirc[5]==0x04))
        {
          QLabel_list[5]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
        }
        if(((parm4&0x20)==0x20)&&(type[5]==0x05)&&(dirc[5]==0x01))
        {
          QLabel_list[5]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
        }
        if(((parm4&0x20)==0x20)&&(type[5]==0x05)&&(dirc[5]==0x02))
        {
          QLabel_list[5]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
        }
        if(((parm4&0x20)==0x20)&&(type[5]==0x05)&&(dirc[5]==0x03))
        {
          QLabel_list[5]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
        }
        if(((parm4&0x20)==0x20)&&(type[5]==0x05)&&(dirc[5]==0x04))
        {
          QLabel_list[5]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
        }
        if(((parm4&0x20)==0x20)&&(type[5]==0x06)&&(dirc[5]==0x01))
        {
          QLabel_list[5]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G3.png);"));
        }
        if(((parm4&0x20)==0x20)&&(type[5]==0x06)&&(dirc[5]==0x02))
        {
          QLabel_list[5]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G1.png);"));
        }
        if(((parm4&0x20)==0x20)&&(type[5]==0x06)&&(dirc[5]==0x03))
        {
          QLabel_list[5]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G4.png);"));
        }
        if(((parm4&0x20)==0x20)&&(type[5]==0x06)&&(dirc[5]==0x04))
        {
          QLabel_list[5]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G2.png);"));
        }
        if(((parm4&0x20)==0x20)&&(type[5]==0x07)&&(dirc[5]==0x01))
        {
          QLabel_list[5]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G2.png);"));
        }
        if(((parm4&0x20)==0x20)&&(type[5]==0x07)&&(dirc[5]==0x02))
        {
          QLabel_list[5]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G3.png);"));
        }
        if(((parm4&0x20)==0x20)&&(type[5]==0x07)&&(dirc[5]==0x03))
        {
          QLabel_list[5]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G1.png);"));
        }
        if(((parm4&0x20)==0x20)&&(type[5]==0x07)&&(dirc[5]==0x04))
        {
          QLabel_list[5]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G4.png);"));
        }
        if(((parm4&0x20)==0x20)&&(type[5]==0x08)&&(dirc[5]==0x01))
        {
          QLabel_list[5]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G1.png);"));
        }
        if(((parm4&0x20)==0x20)&&(type[5]==0x08)&&(dirc[5]==0x02))
        {
          QLabel_list[5]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G4.png);"));
        }
        if(((parm4&0x20)==0x20)&&(type[5]==0x08)&&(dirc[5]==0x03))
        {
          QLabel_list[5]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G2.png);"));
        }
        if(((parm4&0x20)==0x20)&&(type[5]==0x08)&&(dirc[5]==0x04))
        {
          QLabel_list[5]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G3.png);"));
        }
        if(((parm4&0x20)==0x20)&&(type[5]==0x09)&&(dirc[5]==0x01))
        {
          QLabel_list[5]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/GG.png);"));
        }
        if(((parm4&0x20)==0x20)&&(type[5]==0x09)&&(dirc[5]==0x02))
        {
          QLabel_list[5]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/GG.png);"));
        }
        if(((parm4&0x20)==0x20)&&(type[5]==0x09)&&(dirc[5]==0x03))
        {
          QLabel_list[5]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/GG.png);"));
        }
        if(((parm4&0x20)==0x20)&&(type[5]==0x09)&&(dirc[5]==0x04))
        {
          QLabel_list[5]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/GG.png);"));
        }


        if(((parm4&0x40)==0x40)&&(type[6]==0x03)&&(dirc[6]==0x01))
        {
          QLabel_list[6]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
        }
        if(((parm4&0x40)==0x40)&&(type[6]==0x03)&&(dirc[6]==0x02))
        {
          QLabel_list[6]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
        }
        if(((parm4&0x40)==0x40)&&(type[6]==0x03)&&(dirc[6]==0x03))
        {
          QLabel_list[6]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
        }
        if(((parm4&0x40)==0x40)&&(type[6]==0x03)&&(dirc[6]==0x04))
        {
          QLabel_list[6]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
        }
        if(((parm4&0x40)==0x40)&&(type[6]==0x05)&&(dirc[6]==0x01))
        {
          QLabel_list[6]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
        }
        if(((parm4&0x40)==0x40)&&(type[6]==0x05)&&(dirc[6]==0x02))
        {
          QLabel_list[6]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
        }
        if(((parm4&0x40)==0x40)&&(type[6]==0x05)&&(dirc[6]==0x03))
        {
          QLabel_list[6]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
        }
        if(((parm4&0x40)==0x40)&&(type[6]==0x05)&&(dirc[6]==0x04))
        {
          QLabel_list[6]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
        }
        if(((parm4&0x40)==0x40)&&(type[6]==0x06)&&(dirc[6]==0x01))
        {
          QLabel_list[6]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G3.png);"));
        }
        if(((parm4&0x40)==0x40)&&(type[6]==0x06)&&(dirc[6]==0x02))
        {
          QLabel_list[6]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G1.png);"));
        }
        if(((parm4&0x40)==0x40)&&(type[6]==0x06)&&(dirc[6]==0x03))
        {
          QLabel_list[6]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G4.png);"));
        }
        if(((parm4&0x40)==0x40)&&(type[6]==0x06)&&(dirc[6]==0x04))
        {
          QLabel_list[6]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G2.png);"));
        }
        if(((parm4&0x40)==0x40)&&(type[6]==0x07)&&(dirc[6]==0x01))
        {
          QLabel_list[6]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G2.png);"));
        }
        if(((parm4&0x40)==0x40)&&(type[6]==0x07)&&(dirc[6]==0x02))
        {
          QLabel_list[6]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G3.png);"));
        }
        if(((parm4&0x40)==0x40)&&(type[6]==0x07)&&(dirc[6]==0x03))
        {
          QLabel_list[6]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G1.png);"));
        }
        if(((parm4&0x40)==0x40)&&(type[6]==0x07)&&(dirc[6]==0x04))
        {
          QLabel_list[6]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G4.png);"));
        }
        if(((parm4&0x40)==0x40)&&(type[6]==0x08)&&(dirc[6]==0x01))
        {
          QLabel_list[6]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G1.png);"));
        }
        if(((parm4&0x40)==0x40)&&(type[6]==0x08)&&(dirc[6]==0x02))
        {
          QLabel_list[6]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G4.png);"));
        }
        if(((parm4&0x40)==0x40)&&(type[6]==0x08)&&(dirc[6]==0x03))
        {
          QLabel_list[6]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G2.png);"));
        }
        if(((parm4&0x40)==0x40)&&(type[6]==0x08)&&(dirc[6]==0x04))
        {
          QLabel_list[6]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G3.png);"));
        }
        if(((parm4&0x40)==0x40)&&(type[6]==0x09)&&(dirc[6]==0x01))
        {
          QLabel_list[6]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/GG.png);"));
        }
        if(((parm4&0x40)==0x40)&&(type[6]==0x09)&&(dirc[6]==0x02))
        {
          QLabel_list[6]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/GG.png);"));
        }
        if(((parm4&0x40)==0x40)&&(type[6]==0x09)&&(dirc[6]==0x03))
        {
          QLabel_list[6]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/GG.png);"));
        }
        if(((parm4&0x40)==0x40)&&(type[6]==0x09)&&(dirc[6]==0x04))
        {
          QLabel_list[6]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/GG.png);"));
        }


        if(((parm4&0x80)==0x80)&&(type[7]==0x03)&&(dirc[7]==0x01))
        {
          QLabel_list[7]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
        }
        if(((parm4&0x80)==0x80)&&(type[7]==0x03)&&(dirc[7]==0x02))
        {
          QLabel_list[7]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
        }
        if(((parm4&0x80)==0x80)&&(type[7]==0x03)&&(dirc[7]==0x03))
        {
          QLabel_list[7]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
        }
        if(((parm4&0x80)==0x80)&&(type[7]==0x03)&&(dirc[7]==0x04))
        {
          QLabel_list[7]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
        }
        if(((parm4&0x80)==0x80)&&(type[7]==0x05)&&(dirc[7]==0x01))
        {
          QLabel_list[7]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
        }
        if(((parm4&0x80)==0x80)&&(type[7]==0x05)&&(dirc[7]==0x02))
        {
          QLabel_list[7]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
        }
        if(((parm4&0x80)==0x80)&&(type[7]==0x05)&&(dirc[7]==0x03))
        {
          QLabel_list[7]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
        }
        if(((parm4&0x80)==0x80)&&(type[7]==0x05)&&(dirc[7]==0x04))
        {
          QLabel_list[7]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
        }
        if(((parm4&0x80)==0x80)&&(type[7]==0x06)&&(dirc[7]==0x01))
        {
          QLabel_list[7]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G3.png);"));
        }
        if(((parm4&0x80)==0x80)&&(type[7]==0x06)&&(dirc[7]==0x02))
        {
          QLabel_list[7]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G1.png);"));
        }
        if(((parm4&0x80)==0x80)&&(type[7]==0x06)&&(dirc[7]==0x03))
        {
          QLabel_list[7]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G4.png);"));
        }
        if(((parm4&0x80)==0x80)&&(type[7]==0x06)&&(dirc[7]==0x04))
        {
          QLabel_list[7]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G2.png);"));
        }
        if(((parm4&0x80)==0x80)&&(type[7]==0x07)&&(dirc[7]==0x01))
        {
          QLabel_list[7]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G2.png);"));
        }
        if(((parm4&0x80)==0x80)&&(type[7]==0x07)&&(dirc[7]==0x02))
        {
          QLabel_list[7]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G3.png);"));
        }
        if(((parm4&0x80)==0x80)&&(type[7]==0x07)&&(dirc[7]==0x03))
        {
          QLabel_list[7]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G1.png);"));
        }
        if(((parm4&0x80)==0x80)&&(type[7]==0x07)&&(dirc[7]==0x04))
        {
          QLabel_list[7]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G4.png);"));
        }
        if(((parm4&0x80)==0x80)&&(type[7]==0x08)&&(dirc[7]==0x01))
        {
          QLabel_list[7]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G1.png);"));
        }
        if(((parm4&0x80)==0x80)&&(type[7]==0x08)&&(dirc[7]==0x02))
        {
          QLabel_list[7]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G4.png);"));
        }
        if(((parm4&0x80)==0x80)&&(type[7]==0x08)&&(dirc[7]==0x03))
        {
          QLabel_list[7]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G2.png);"));
        }
        if(((parm4&0x80)==0x80)&&(type[7]==0x08)&&(dirc[7]==0x04))
        {
          QLabel_list[7]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G3.png);"));
        }
        if(((parm4&0x80)==0x80)&&(type[7]==0x09)&&(dirc[7]==0x01))
        {
          QLabel_list[7]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/GG.png);"));
        }
        if(((parm4&0x80)==0x80)&&(type[7]==0x09)&&(dirc[7]==0x02))
        {
          QLabel_list[7]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/GG.png);"));
        }
        if(((parm4&0x80)==0x80)&&(type[7]==0x09)&&(dirc[7]==0x03))
        {
          QLabel_list[7]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/GG.png);"));
        }
        if(((parm4&0x80)==0x80)&&(type[7]==0x09)&&(dirc[7]==0x04))
        {
          QLabel_list[7]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/GG.png);"));
        }

    }




{
/*
      if((parm2&0x02)==0x02)
       QLabel_list[1]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
      if((parm2&0x04)==0x04)
       QLabel_list[2]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
      if((parm2&0x08)==0x08)
       QLabel_list[3]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
      if((parm2&0x10)==0x10)
       QLabel_list[4]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
      if((parm2&0x20)==0x20)
       QLabel_list[5]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
      if((parm2&0x40)==0x40)
       QLabel_list[6]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
      if((parm2&0x80)==0x80)
       QLabel_list[7]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
      /////////////////////////////////////red   hou 8////////////////////////////////////////////////////////
      //============================================================================================
      if((parm3&0x01)==0x01)
       QLabel_list[0]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
      if((parm3&0x02)==0x02)
       QLabel_list[1]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
      if((parm3&0x04)==0x04)
       QLabel_list[2]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
      if((parm3&0x08)==0x08)
       QLabel_list[3]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
      if((parm3&0x10)==0x10)
       QLabel_list[4]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
      if((parm3&0x20)==0x20)
       QLabel_list[5]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
      if((parm3&0x40)==0x40)
       QLabel_list[6]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
      if((parm3&0x80)==0x80)
       QLabel_list[7]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));

      //===========================================================================================
      if((parm4&0x01)==0x01)
       QLabel_list[0]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
      if((parm4&0x02)==0x02)
       QLabel_list[1]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
      if((parm4&0x04)==0x04)
       QLabel_list[2]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
      if((parm4&0x08)==0x08)
       QLabel_list[3]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
      if((parm4&0x10)==0x10)
       QLabel_list[4]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
      if((parm4&0x20)==0x20)
       QLabel_list[5]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
      if((parm4&0x40)==0x40)
       QLabel_list[6]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
      if((parm4&0x80)==0x80)
       QLabel_list[7]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));

    //=========================================================================================
    //============================================================================================
    //=====*/}
    }
    if(parm5==0x02)
    {



        {
                   if(((parm6&0x01)==0x01)&&(type[8]==0x03)&&(dirc[8]==0x01))
                   {
                     QLabel_list[8]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
                   }
                   if(((parm6&0x01)==0x01)&&(type[8]==0x03)&&(dirc[8]==0x02))
                   {
                     QLabel_list[8]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
                   }
                   if(((parm6&0x01)==0x01)&&(type[8]==0x03)&&(dirc[8]==0x03))
                   {
                     QLabel_list[8]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
                   }
                   if(((parm6&0x01)==0x01)&&(type[8]==0x03)&&(dirc[8]==0x04))
                   {
                     QLabel_list[8]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
                   }
                   if(((parm6&0x01)==0x01)&&(type[8]==0x05)&&(dirc[8]==0x01))
                   {
                     QLabel_list[8]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
                   }
                   if(((parm6&0x01)==0x01)&&(type[8]==0x05)&&(dirc[8]==0x02))
                   {
                     QLabel_list[8]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
                   }
                   if(((parm6&0x01)==0x01)&&(type[8]==0x05)&&(dirc[8]==0x03))
                   {
                     QLabel_list[8]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
                   }
                   if(((parm6&0x01)==0x01)&&(type[8]==0x05)&&(dirc[8]==0x04))
                   {
                     QLabel_list[8]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
                   }
                   if(((parm6&0x01)==0x01)&&(type[8]==0x06)&&(dirc[8]==0x01))
                   {
                     QLabel_list[8]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R3.png);"));
                   }
                   if(((parm6&0x01)==0x01)&&(type[8]==0x06)&&(dirc[8]==0x02))
                   {
                     QLabel_list[8]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R1.png);"));
                   }
                   if(((parm6&0x01)==0x01)&&(type[8]==0x06)&&(dirc[8]==0x03))
                   {
                     QLabel_list[8]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R4.png);"));
                   }
                   if(((parm6&0x01)==0x01)&&(type[8]==0x06)&&(dirc[8]==0x04))
                   {
                     QLabel_list[8]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R2.png);"));
                   }
                   if(((parm6&0x01)==0x01)&&(type[8]==0x07)&&(dirc[8]==0x01))
                   {
                     QLabel_list[8]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R2.png);"));
                   }
                   if(((parm6&0x01)==0x01)&&(type[8]==0x07)&&(dirc[8]==0x02))
                   {
                     QLabel_list[8]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R3.png);"));
                   }
                   if(((parm6&0x01)==0x01)&&(type[8]==0x07)&&(dirc[8]==0x03))
                   {
                     QLabel_list[8]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R1.png);"));
                   }
                   if(((parm6&0x01)==0x01)&&(type[8]==0x07)&&(dirc[8]==0x04))
                   {
                     QLabel_list[8]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R4.png);"));
                   }
                   if(((parm6&0x01)==0x01)&&(type[8]==0x08)&&(dirc[8]==0x01))
                   {
                     QLabel_list[8]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R1.png);"));
                   }
                   if(((parm6&0x01)==0x01)&&(type[8]==0x08)&&(dirc[8]==0x02))
                   {
                     QLabel_list[8]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R4.png);"));
                   }
                   if(((parm6&0x01)==0x01)&&(type[8]==0x08)&&(dirc[8]==0x03))
                   {
                     QLabel_list[8]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R2.png);"));
                   }
                   if(((parm6&0x01)==0x01)&&(type[8]==0x08)&&(dirc[8]==0x04))
                   {
                     QLabel_list[8]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R3.png);"));
                   }
                   if(((parm6&0x01)==0x01)&&(type[8]==0x09)&&(dirc[8]==0x01))
                   {
                     QLabel_list[8]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/RR.png);"));
                   }
                   if(((parm6&0x01)==0x01)&&(type[8]==0x09)&&(dirc[8]==0x02))
                   {
                     QLabel_list[8]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/RR.png);"));
                   }
                   if(((parm6&0x01)==0x01)&&(type[8]==0x09)&&(dirc[8]==0x03))
                   {
                     QLabel_list[8]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/RR.png);"));
                   }
                   if(((parm6&0x01)==0x01)&&(type[8]==0x09)&&(dirc[8]==0x04))
                   {
                     QLabel_list[8]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/RR.png);"));
                   }


                   if(((parm6&0x02)==0x02)&&(type[9]==0x03)&&(dirc[9]==0x01))
                   {
                     QLabel_list[9]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
                   }
                   if(((parm6&0x02)==0x02)&&(type[9]==0x03)&&(dirc[9]==0x02))
                   {
                     QLabel_list[9]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
                   }
                   if(((parm6&0x02)==0x02)&&(type[9]==0x03)&&(dirc[9]==0x03))
                   {
                     QLabel_list[9]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
                   }
                   if(((parm6&0x02)==0x02)&&(type[9]==0x03)&&(dirc[9]==0x04))
                   {
                     QLabel_list[9]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
                   }
                   if(((parm6&0x02)==0x02)&&(type[9]==0x05)&&(dirc[9]==0x01))
                   {
                     QLabel_list[9]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
                   }
                   if(((parm6&0x02)==0x02)&&(type[9]==0x05)&&(dirc[9]==0x02))
                   {
                     QLabel_list[9]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
                   }
                   if(((parm6&0x02)==0x02)&&(type[9]==0x05)&&(dirc[9]==0x03))
                   {
                     QLabel_list[9]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
                   }
                   if(((parm6&0x02)==0x02)&&(type[9]==0x05)&&(dirc[9]==0x04))
                   {
                     QLabel_list[9]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
                   }
                   if(((parm6&0x02)==0x02)&&(type[9]==0x06)&&(dirc[9]==0x01))
                   {
                     QLabel_list[9]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R3.png);"));
                   }
                   if(((parm6&0x02)==0x02)&&(type[9]==0x06)&&(dirc[9]==0x02))
                   {
                     QLabel_list[9]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R1.png);"));
                   }
                   if(((parm6&0x02)==0x02)&&(type[9]==0x06)&&(dirc[9]==0x03))
                   {
                     QLabel_list[9]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R4.png);"));
                   }
                   if(((parm6&0x02)==0x02)&&(type[9]==0x06)&&(dirc[9]==0x04))
                   {
                     QLabel_list[9]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R2.png);"));
                   }
                   if(((parm6&0x02)==0x02)&&(type[9]==0x07)&&(dirc[9]==0x01))
                   {
                     QLabel_list[9]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R2.png);"));
                   }
                   if(((parm6&0x02)==0x02)&&(type[9]==0x07)&&(dirc[9]==0x02))
                   {
                     QLabel_list[9]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R3.png);"));
                   }
                   if(((parm6&0x02)==0x02)&&(type[9]==0x07)&&(dirc[9]==0x03))
                   {
                     QLabel_list[9]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R1.png);"));
                   }
                   if(((parm6&0x02)==0x02)&&(type[9]==0x07)&&(dirc[9]==0x04))
                   {
                     QLabel_list[9]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R4.png);"));
                   }
                   if(((parm6&0x02)==0x02)&&(type[9]==0x08)&&(dirc[9]==0x01))
                   {
                     QLabel_list[9]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R1.png);"));
                   }
                   if(((parm6&0x02)==0x02)&&(type[9]==0x08)&&(dirc[9]==0x02))
                   {
                     QLabel_list[9]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R4.png);"));
                   }
                   if(((parm6&0x02)==0x02)&&(type[9]==0x08)&&(dirc[9]==0x03))
                   {
                     QLabel_list[9]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R2.png);"));
                   }
                   if(((parm6&0x02)==0x02)&&(type[9]==0x08)&&(dirc[9]==0x04))
                   {
                     QLabel_list[9]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R3.png);"));
                   }
                   if(((parm6&0x02)==0x02)&&(type[9]==0x09)&&(dirc[9]==0x01))
                   {
                     QLabel_list[9]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/RR.png);"));
                   }
                   if(((parm6&0x02)==0x02)&&(type[9]==0x09)&&(dirc[9]==0x02))
                   {
                     QLabel_list[9]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/RR.png);"));
                   }
                   if(((parm6&0x02)==0x02)&&(type[9]==0x09)&&(dirc[9]==0x03))
                   {
                     QLabel_list[9]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/RR.png);"));
                   }
                   if(((parm6&0x02)==0x02)&&(type[9]==0x09)&&(dirc[9]==0x04))
                   {
                     QLabel_list[9]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/RR.png);"));
                   }

                   if(((parm6&0x04)==0x04)&&(type[10]==0x03)&&(dirc[10]==0x01))
                   {
                     QLabel_list[10]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
                   }
                   if(((parm6&0x04)==0x04)&&(type[10]==0x03)&&(dirc[10]==0x02))
                   {
                     QLabel_list[10]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
                   }
                   if(((parm6&0x04)==0x04)&&(type[10]==0x03)&&(dirc[10]==0x03))
                   {
                     QLabel_list[10]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
                   }
                   if(((parm6&0x04)==0x04)&&(type[10]==0x03)&&(dirc[10]==0x04))
                   {
                     QLabel_list[10]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
                   }
                   if(((parm6&0x04)==0x04)&&(type[10]==0x05)&&(dirc[10]==0x01))
                   {
                     QLabel_list[10]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
                   }
                   if(((parm6&0x04)==0x04)&&(type[10]==0x05)&&(dirc[10]==0x02))
                   {
                     QLabel_list[10]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
                   }
                   if(((parm6&0x04)==0x04)&&(type[10]==0x05)&&(dirc[10]==0x03))
                   {
                     QLabel_list[10]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
                   }
                   if(((parm6&0x04)==0x04)&&(type[10]==0x05)&&(dirc[10]==0x04))
                   {
                     QLabel_list[10]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
                   }
                   if(((parm6&0x04)==0x04)&&(type[10]==0x06)&&(dirc[10]==0x01))
                   {
                     QLabel_list[10]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R3.png);"));
                   }
                   if(((parm6&0x04)==0x04)&&(type[10]==0x06)&&(dirc[10]==0x02))
                   {
                     QLabel_list[10]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R1.png);"));
                   }
                   if(((parm6&0x04)==0x04)&&(type[10]==0x06)&&(dirc[10]==0x03))
                   {
                     QLabel_list[10]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R4.png);"));
                   }
                   if(((parm6&0x04)==0x04)&&(type[10]==0x06)&&(dirc[10]==0x04))
                   {
                     QLabel_list[10]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R2.png);"));
                   }
                   if(((parm6&0x04)==0x04)&&(type[10]==0x07)&&(dirc[10]==0x01))
                   {
                     QLabel_list[10]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R2.png);"));
                   }
                   if(((parm6&0x04)==0x04)&&(type[10]==0x07)&&(dirc[10]==0x02))
                   {
                     QLabel_list[10]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R3.png);"));
                   }
                   if(((parm6&0x04)==0x04)&&(type[10]==0x07)&&(dirc[10]==0x03))
                   {
                     QLabel_list[10]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R1.png);"));
                   }
                   if(((parm6&0x04)==0x04)&&(type[10]==0x07)&&(dirc[10]==0x04))
                   {
                     QLabel_list[10]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R4.png);"));
                   }
                   if(((parm6&0x04)==0x04)&&(type[10]==0x08)&&(dirc[10]==0x01))
                   {
                     QLabel_list[10]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R1.png);"));
                   }
                   if(((parm6&0x04)==0x04)&&(type[10]==0x08)&&(dirc[10]==0x02))
                   {
                     QLabel_list[10]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R4.png);"));
                   }
                   if(((parm6&0x04)==0x04)&&(type[10]==0x08)&&(dirc[10]==0x03))
                   {
                     QLabel_list[10]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R2.png);"));
                   }
                   if(((parm6&0x04)==0x04)&&(type[10]==0x08)&&(dirc[10]==0x04))
                   {
                     QLabel_list[10]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R3.png);"));
                   }
                   if(((parm6&0x04)==0x04)&&(type[10]==0x09)&&(dirc[10]==0x01))
                   {
                     QLabel_list[10]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/RR.png);"));
                   }
                   if(((parm6&0x04)==0x04)&&(type[10]==0x09)&&(dirc[10]==0x02))
                   {
                     QLabel_list[10]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/RR.png);"));
                   }
                   if(((parm6&0x04)==0x04)&&(type[10]==0x09)&&(dirc[10]==0x03))
                   {
                     QLabel_list[10]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/RR.png);"));
                   }
                   if(((parm6&0x04)==0x04)&&(type[10]==0x09)&&(dirc[10]==0x04))
                   {
                     QLabel_list[10]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/RR.png);"));
                   }

                   if(((parm6&0x08)==0x08)&&(type[11]==0x03)&&(dirc[11]==0x01))
                   {
                     QLabel_list[11]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
                   }
                   if(((parm6&0x08)==0x08)&&(type[11]==0x03)&&(dirc[11]==0x02))
                   {
                     QLabel_list[11]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
                   }
                   if(((parm6&0x08)==0x08)&&(type[11]==0x03)&&(dirc[11]==0x03))
                   {
                     QLabel_list[11]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
                   }
                   if(((parm6&0x08)==0x08)&&(type[11]==0x03)&&(dirc[11]==0x04))
                   {
                     QLabel_list[11]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
                   }
                   if(((parm6&0x08)==0x08)&&(type[11]==0x05)&&(dirc[11]==0x01))
                   {
                     QLabel_list[11]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
                   }
                   if(((parm6&0x08)==0x08)&&(type[11]==0x05)&&(dirc[11]==0x02))
                   {
                     QLabel_list[11]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
                   }
                   if(((parm6&0x08)==0x08)&&(type[11]==0x05)&&(dirc[11]==0x03))
                   {
                     QLabel_list[11]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
                   }
                   if(((parm6&0x08)==0x08)&&(type[11]==0x05)&&(dirc[11]==0x04))
                   {
                     QLabel_list[11]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
                   }
                   if(((parm6&0x08)==0x08)&&(type[11]==0x06)&&(dirc[11]==0x01))
                   {
                     QLabel_list[11]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R3.png);"));
                   }
                   if(((parm6&0x08)==0x08)&&(type[11]==0x06)&&(dirc[11]==0x02))
                   {
                     QLabel_list[11]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R1.png);"));
                   }
                   if(((parm6&0x08)==0x08)&&(type[11]==0x06)&&(dirc[11]==0x03))
                   {
                     QLabel_list[11]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R4.png);"));
                   }
                   if(((parm6&0x08)==0x08)&&(type[11]==0x06)&&(dirc[11]==0x04))
                   {
                     QLabel_list[11]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R2.png);"));
                   }
                   if(((parm6&0x08)==0x08)&&(type[11]==0x07)&&(dirc[11]==0x01))
                   {
                     QLabel_list[11]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R2.png);"));
                   }
                   if(((parm6&0x08)==0x08)&&(type[11]==0x07)&&(dirc[11]==0x02))
                   {
                     QLabel_list[11]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R3.png);"));
                   }
                   if(((parm6&0x08)==0x08)&&(type[11]==0x07)&&(dirc[11]==0x03))
                   {
                     QLabel_list[11]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R1.png);"));
                   }
                   if(((parm6&0x08)==0x08)&&(type[11]==0x07)&&(dirc[11]==0x04))
                   {
                     QLabel_list[11]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R4.png);"));
                   }
                   if(((parm6&0x08)==0x08)&&(type[11]==0x08)&&(dirc[11]==0x01))
                   {
                     QLabel_list[11]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R1.png);"));
                   }
                   if(((parm6&0x08)==0x08)&&(type[11]==0x08)&&(dirc[11]==0x02))
                   {
                     QLabel_list[11]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R4.png);"));
                   }
                   if(((parm6&0x08)==0x08)&&(type[11]==0x08)&&(dirc[11]==0x03))
                   {
                     QLabel_list[11]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R2.png);"));
                   }
                   if(((parm6&0x08)==0x08)&&(type[11]==0x08)&&(dirc[11]==0x04))
                   {
                     QLabel_list[11]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R3.png);"));
                   }
                   if(((parm6&0x08)==0x08)&&(type[11]==0x09)&&(dirc[11]==0x01))
                   {
                     QLabel_list[11]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/RR.png);"));
                   }
                   if(((parm6&0x08)==0x08)&&(type[11]==0x09)&&(dirc[11]==0x02))
                   {
                     QLabel_list[11]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/RR.png);"));
                   }
                   if(((parm6&0x08)==0x08)&&(type[11]==0x09)&&(dirc[11]==0x03))
                   {
                     QLabel_list[11]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/RR.png);"));
                   }
                   if(((parm6&0x08)==0x08)&&(type[11]==0x09)&&(dirc[11]==0x04))
                   {
                     QLabel_list[11]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/RR.png);"));
                   }


                   if(((parm6&0x10)==0x10)&&(type[12]==0x03)&&(dirc[12]==0x01))
                   {
                     QLabel_list[12]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
                   }
                   if(((parm6&0x10)==0x10)&&(type[12]==0x03)&&(dirc[12]==0x02))
                   {
                     QLabel_list[12]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
                   }
                   if(((parm6&0x10)==0x10)&&(type[12]==0x03)&&(dirc[12]==0x03))
                   {
                     QLabel_list[12]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
                   }
                   if(((parm6&0x10)==0x10)&&(type[12]==0x03)&&(dirc[12]==0x04))
                   {
                     QLabel_list[12]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
                   }
                   if(((parm6&0x10)==0x10)&&(type[12]==0x05)&&(dirc[12]==0x01))
                   {
                     QLabel_list[12]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
                   }
                   if(((parm6&0x10)==0x10)&&(type[12]==0x05)&&(dirc[12]==0x02))
                   {
                     QLabel_list[12]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
                   }
                   if(((parm6&0x10)==0x10)&&(type[12]==0x05)&&(dirc[12]==0x03))
                   {
                     QLabel_list[12]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
                   }
                   if(((parm6&0x10)==0x10)&&(type[12]==0x05)&&(dirc[12]==0x04))
                   {
                     QLabel_list[12]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
                   }
                   if(((parm6&0x10)==0x10)&&(type[12]==0x06)&&(dirc[12]==0x01))
                   {
                     QLabel_list[12]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R3.png);"));
                   }
                   if(((parm6&0x10)==0x10)&&(type[12]==0x06)&&(dirc[12]==0x02))
                   {
                     QLabel_list[12]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R1.png);"));
                   }
                   if(((parm6&0x10)==0x10)&&(type[12]==0x06)&&(dirc[12]==0x03))
                   {
                     QLabel_list[12]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R4.png);"));
                   }
                   if(((parm6&0x10)==0x10)&&(type[12]==0x06)&&(dirc[12]==0x04))
                   {
                     QLabel_list[12]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R2.png);"));
                   }
                   if(((parm6&0x10)==0x10)&&(type[12]==0x07)&&(dirc[12]==0x01))
                   {
                     QLabel_list[12]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R2.png);"));
                   }
                   if(((parm6&0x10)==0x10)&&(type[12]==0x07)&&(dirc[12]==0x02))
                   {
                     QLabel_list[12]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R3.png);"));
                   }
                   if(((parm6&0x10)==0x10)&&(type[12]==0x07)&&(dirc[12]==0x03))
                   {
                     QLabel_list[12]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R1.png);"));
                   }
                   if(((parm6&0x10)==0x10)&&(type[12]==0x07)&&(dirc[12]==0x04))
                   {
                     QLabel_list[12]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R4.png);"));
                   }
                   if(((parm6&0x10)==0x10)&&(type[12]==0x08)&&(dirc[12]==0x01))
                   {
                     QLabel_list[12]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R1.png);"));
                   }
                   if(((parm6&0x10)==0x10)&&(type[12]==0x08)&&(dirc[12]==0x02))
                   {
                     QLabel_list[12]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R4.png);"));
                   }
                   if(((parm6&0x10)==0x10)&&(type[12]==0x08)&&(dirc[12]==0x03))
                   {
                     QLabel_list[12]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R2.png);"));
                   }
                   if(((parm6&0x10)==0x10)&&(type[12]==0x08)&&(dirc[12]==0x04))
                   {
                     QLabel_list[12]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R3.png);"));
                   }
                   if(((parm6&0x10)==0x10)&&(type[12]==0x09)&&(dirc[12]==0x01))
                   {
                     QLabel_list[12]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/RR.png);"));
                   }
                   if(((parm6&0x10)==0x10)&&(type[12]==0x09)&&(dirc[12]==0x02))
                   {
                     QLabel_list[12]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/RR.png);"));
                   }
                   if(((parm6&0x10)==0x10)&&(type[12]==0x09)&&(dirc[12]==0x03))
                   {
                     QLabel_list[12]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/RR.png);"));
                   }
                   if(((parm6&0x10)==0x10)&&(type[12]==0x09)&&(dirc[12]==0x04))
                   {
                     QLabel_list[12]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/RR.png);"));
                   }

                   if(((parm6&0x20)==0x20)&&(type[13]==0x03)&&(dirc[13]==0x01))
                   {
                     QLabel_list[13]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
                   }
                   if(((parm6&0x20)==0x20)&&(type[13]==0x03)&&(dirc[13]==0x02))
                   {
                     QLabel_list[13]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
                   }
                   if(((parm6&0x20)==0x20)&&(type[13]==0x03)&&(dirc[13]==0x03))
                   {
                     QLabel_list[13]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
                   }
                   if(((parm6&0x20)==0x20)&&(type[13]==0x03)&&(dirc[13]==0x04))
                   {
                     QLabel_list[13]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
                   }
                   if(((parm6&0x20)==0x20)&&(type[13]==0x05)&&(dirc[13]==0x01))
                   {
                     QLabel_list[13]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
                   }
                   if(((parm6&0x20)==0x20)&&(type[13]==0x05)&&(dirc[13]==0x02))
                   {
                     QLabel_list[13]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
                   }
                   if(((parm6&0x20)==0x20)&&(type[13]==0x05)&&(dirc[13]==0x03))
                   {
                     QLabel_list[13]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
                   }
                   if(((parm6&0x20)==0x20)&&(type[13]==0x05)&&(dirc[13]==0x04))
                   {
                     QLabel_list[13]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
                   }
                   if(((parm6&0x20)==0x20)&&(type[13]==0x06)&&(dirc[13]==0x01))
                   {
                     QLabel_list[13]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R3.png);"));
                   }
                   if(((parm6&0x20)==0x20)&&(type[13]==0x06)&&(dirc[13]==0x02))
                   {
                     QLabel_list[13]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R1.png);"));
                   }
                   if(((parm6&0x20)==0x20)&&(type[13]==0x06)&&(dirc[13]==0x03))
                   {
                     QLabel_list[13]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R4.png);"));
                   }
                   if(((parm6&0x20)==0x20)&&(type[13]==0x06)&&(dirc[13]==0x04))
                   {
                     QLabel_list[13]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R2.png);"));
                   }
                   if(((parm6&0x20)==0x20)&&(type[13]==0x07)&&(dirc[13]==0x01))
                   {
                     QLabel_list[13]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R2.png);"));
                   }
                   if(((parm6&0x20)==0x20)&&(type[13]==0x07)&&(dirc[13]==0x02))
                   {
                     QLabel_list[13]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R3.png);"));
                   }
                   if(((parm6&0x20)==0x20)&&(type[13]==0x07)&&(dirc[13]==0x03))
                   {
                     QLabel_list[13]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R1.png);"));
                   }
                   if(((parm6&0x20)==0x20)&&(type[13]==0x07)&&(dirc[13]==0x04))
                   {
                     QLabel_list[13]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R4.png);"));
                   }
                   if(((parm6&0x20)==0x20)&&(type[13]==0x08)&&(dirc[13]==0x01))
                   {
                     QLabel_list[13]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R1.png);"));
                   }
                   if(((parm6&0x20)==0x20)&&(type[13]==0x08)&&(dirc[13]==0x02))
                   {
                     QLabel_list[13]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R4.png);"));
                   }
                   if(((parm6&0x20)==0x20)&&(type[13]==0x08)&&(dirc[13]==0x03))
                   {
                     QLabel_list[13]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R2.png);"));
                   }
                   if(((parm6&0x20)==0x20)&&(type[13]==0x08)&&(dirc[13]==0x04))
                   {
                     QLabel_list[13]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R3.png);"));
                   }
                   if(((parm6&0x20)==0x20)&&(type[13]==0x09)&&(dirc[13]==0x01))
                   {
                     QLabel_list[13]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/RR.png);"));
                   }
                   if(((parm6&0x20)==0x20)&&(type[13]==0x09)&&(dirc[13]==0x02))
                   {
                     QLabel_list[13]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/RR.png);"));
                   }
                   if(((parm6&0x20)==0x20)&&(type[13]==0x09)&&(dirc[13]==0x03))
                   {
                     QLabel_list[13]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/RR.png);"));
                   }
                   if(((parm6&0x20)==0x20)&&(type[13]==0x09)&&(dirc[13]==0x04))
                   {
                     QLabel_list[13]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/RR.png);"));
                   }


                   if(((parm6&0x40)==0x40)&&(type[14]==0x03)&&(dirc[14]==0x01))
                   {
                     QLabel_list[14]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
                   }
                   if(((parm6&0x40)==0x40)&&(type[14]==0x03)&&(dirc[14]==0x02))
                   {
                     QLabel_list[14]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
                   }
                   if(((parm6&0x40)==0x40)&&(type[14]==0x03)&&(dirc[14]==0x03))
                   {
                     QLabel_list[14]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
                   }
                   if(((parm6&0x40)==0x40)&&(type[14]==0x03)&&(dirc[14]==0x04))
                   {
                     QLabel_list[14]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
                   }
                   if(((parm6&0x40)==0x40)&&(type[14]==0x05)&&(dirc[14]==0x01))
                   {
                     QLabel_list[14]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
                   }
                   if(((parm6&0x40)==0x40)&&(type[14]==0x05)&&(dirc[14]==0x02))
                   {
                     QLabel_list[14]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
                   }
                   if(((parm6&0x40)==0x40)&&(type[14]==0x05)&&(dirc[14]==0x03))
                   {
                     QLabel_list[14]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
                   }
                   if(((parm6&0x40)==0x40)&&(type[14]==0x05)&&(dirc[14]==0x04))
                   {
                     QLabel_list[14]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
                   }
                   if(((parm6&0x40)==0x40)&&(type[14]==0x06)&&(dirc[14]==0x01))
                   {
                     QLabel_list[14]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R3.png);"));
                   }
                   if(((parm6&0x40)==0x40)&&(type[14]==0x06)&&(dirc[14]==0x02))
                   {
                     QLabel_list[14]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R1.png);"));
                   }
                   if(((parm6&0x40)==0x40)&&(type[14]==0x06)&&(dirc[14]==0x03))
                   {
                     QLabel_list[14]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R4.png);"));
                   }
                   if(((parm6&0x40)==0x40)&&(type[14]==0x06)&&(dirc[14]==0x04))
                   {
                     QLabel_list[14]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R2.png);"));
                   }
                   if(((parm6&0x40)==0x40)&&(type[14]==0x07)&&(dirc[14]==0x01))
                   {
                     QLabel_list[14]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R2.png);"));
                   }
                   if(((parm6&0x40)==0x40)&&(type[14]==0x07)&&(dirc[14]==0x02))
                   {
                     QLabel_list[14]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R3.png);"));
                   }
                   if(((parm6&0x40)==0x40)&&(type[14]==0x07)&&(dirc[14]==0x03))
                   {
                     QLabel_list[14]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R1.png);"));
                   }
                   if(((parm6&0x40)==0x40)&&(type[14]==0x07)&&(dirc[14]==0x04))
                   {
                     QLabel_list[14]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R4.png);"));
                   }
                   if(((parm6&0x40)==0x40)&&(type[14]==0x08)&&(dirc[14]==0x01))
                   {
                     QLabel_list[14]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R1.png);"));
                   }
                   if(((parm6&0x40)==0x40)&&(type[14]==0x08)&&(dirc[14]==0x02))
                   {
                     QLabel_list[14]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R4.png);"));
                   }
                   if(((parm6&0x40)==0x40)&&(type[14]==0x08)&&(dirc[14]==0x03))
                   {
                     QLabel_list[14]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R2.png);"));
                   }
                   if(((parm6&0x40)==0x40)&&(type[14]==0x08)&&(dirc[14]==0x04))
                   {
                     QLabel_list[14]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R3.png);"));
                   }
                   if(((parm6&0x40)==0x40)&&(type[14]==0x09)&&(dirc[14]==0x01))
                   {
                     QLabel_list[14]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/RR.png);"));
                   }
                   if(((parm6&0x40)==0x40)&&(type[14]==0x09)&&(dirc[14]==0x02))
                   {
                     QLabel_list[14]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/RR.png);"));
                   }
                   if(((parm6&0x40)==0x40)&&(type[14]==0x09)&&(dirc[14]==0x03))
                   {
                     QLabel_list[14]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/RR.png);"));
                   }
                   if(((parm6&0x40)==0x40)&&(type[14]==0x09)&&(dirc[14]==0x04))
                   {
                     QLabel_list[14]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/RR.png);"));
                   }


                   if(((parm6&0x80)==0x80)&&(type[15]==0x03)&&(dirc[15]==0x01))
                   {
                     QLabel_list[15]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
                   }
                   if(((parm6&0x80)==0x80)&&(type[15]==0x03)&&(dirc[15]==0x02))
                   {
                     QLabel_list[15]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
                   }
                   if(((parm6&0x80)==0x80)&&(type[15]==0x03)&&(dirc[15]==0x03))
                   {
                     QLabel_list[15]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
                   }
                   if(((parm6&0x80)==0x80)&&(type[15]==0x03)&&(dirc[15]==0x04))
                   {
                     QLabel_list[15]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
                   }
                   if(((parm6&0x80)==0x80)&&(type[15]==0x05)&&(dirc[15]==0x01))
                   {
                     QLabel_list[15]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
                   }
                   if(((parm6&0x80)==0x80)&&(type[15]==0x05)&&(dirc[15]==0x02))
                   {
                     QLabel_list[15]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
                   }
                   if(((parm6&0x80)==0x80)&&(type[15]==0x05)&&(dirc[15]==0x03))
                   {
                     QLabel_list[15]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
                   }
                   if(((parm6&0x80)==0x80)&&(type[15]==0x05)&&(dirc[15]==0x04))
                   {
                     QLabel_list[15]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
                   }
                   if(((parm6&0x80)==0x80)&&(type[15]==0x06)&&(dirc[15]==0x01))
                   {
                     QLabel_list[15]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R3.png);"));
                   }
                   if(((parm6&0x80)==0x80)&&(type[15]==0x06)&&(dirc[15]==0x02))
                   {
                     QLabel_list[15]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R1.png);"));
                   }
                   if(((parm6&0x80)==0x80)&&(type[15]==0x06)&&(dirc[15]==0x03))
                   {
                     QLabel_list[15]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R4.png);"));
                   }
                   if(((parm6&0x80)==0x80)&&(type[15]==0x06)&&(dirc[15]==0x04))
                   {
                     QLabel_list[15]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R2.png);"));
                   }
                   if(((parm6&0x80)==0x80)&&(type[15]==0x07)&&(dirc[15]==0x01))
                   {
                     QLabel_list[15]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R2.png);"));
                   }
                   if(((parm6&0x80)==0x80)&&(type[15]==0x07)&&(dirc[15]==0x02))
                   {
                     QLabel_list[15]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R3.png);"));
                   }
                   if(((parm6&0x80)==0x80)&&(type[15]==0x07)&&(dirc[15]==0x03))
                   {
                     QLabel_list[15]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R1.png);"));
                   }
                   if(((parm6&0x80)==0x80)&&(type[15]==0x07)&&(dirc[15]==0x04))
                   {
                     QLabel_list[15]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R4.png);"));
                   }
                   if(((parm6&0x80)==0x80)&&(type[15]==0x08)&&(dirc[15]==0x01))
                   {
                     QLabel_list[15]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R1.png);"));
                   }
                   if(((parm6&0x80)==0x80)&&(type[15]==0x08)&&(dirc[15]==0x02))
                   {
                     QLabel_list[15]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R4.png);"));
                   }
                   if(((parm6&0x80)==0x80)&&(type[15]==0x08)&&(dirc[15]==0x03))
                   {
                     QLabel_list[15]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R2.png);"));
                   }
                   if(((parm6&0x80)==0x80)&&(type[15]==0x08)&&(dirc[15]==0x04))
                   {
                     QLabel_list[15]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R3.png);"));
                   }
                   if(((parm6&0x80)==0x80)&&(type[15]==0x09)&&(dirc[15]==0x01))
                   {
                     QLabel_list[15]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/RR.png);"));
                   }
                   if(((parm6&0x80)==0x80)&&(type[15]==0x09)&&(dirc[15]==0x02))
                   {
                     QLabel_list[15]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/RR.png);"));
                   }
                   if(((parm6&0x80)==0x80)&&(type[15]==0x09)&&(dirc[15]==0x03))
                   {
                     QLabel_list[15]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/RR.png);"));
                   }
                   if(((parm6&0x80)==0x80)&&(type[15]==0x09)&&(dirc[15]==0x04))
                   {
                     QLabel_list[15]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/RR.png);"));
                   }

               }



        {
            if(((parm7&0x01)==0x01)&&(type[8]==0x03)&&(dirc[8]==0x01))
            {
              QLabel_list[8]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm7&0x01)==0x01)&&(type[8]==0x03)&&(dirc[8]==0x02))
            {
              QLabel_list[8]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm7&0x01)==0x01)&&(type[8]==0x03)&&(dirc[8]==0x03))
            {
              QLabel_list[8]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm7&0x01)==0x01)&&(type[8]==0x03)&&(dirc[8]==0x04))
            {
              QLabel_list[8]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm7&0x01)==0x01)&&(type[8]==0x05)&&(dirc[8]==0x01))
            {
              QLabel_list[8]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm7&0x01)==0x01)&&(type[8]==0x05)&&(dirc[8]==0x02))
            {
              QLabel_list[8]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm7&0x01)==0x01)&&(type[8]==0x05)&&(dirc[8]==0x03))
            {
              QLabel_list[8]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm7&0x01)==0x01)&&(type[8]==0x05)&&(dirc[8]==0x04))
            {
              QLabel_list[8]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm7&0x01)==0x01)&&(type[8]==0x06)&&(dirc[8]==0x01))
            {
              QLabel_list[8]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y3.png);"));
            }
            if(((parm7&0x01)==0x01)&&(type[8]==0x06)&&(dirc[8]==0x02))
            {
              QLabel_list[8]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y1.png);"));
            }
            if(((parm7&0x01)==0x01)&&(type[8]==0x06)&&(dirc[8]==0x03))
            {
              QLabel_list[8]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y4.png);"));
            }
            if(((parm7&0x01)==0x01)&&(type[8]==0x06)&&(dirc[8]==0x04))
            {
              QLabel_list[8]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y2.png);"));
            }
            if(((parm7&0x01)==0x01)&&(type[8]==0x07)&&(dirc[8]==0x01))
            {
              QLabel_list[8]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y2.png);"));
            }
            if(((parm7&0x01)==0x01)&&(type[8]==0x07)&&(dirc[8]==0x02))
            {
              QLabel_list[8]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y3.png);"));
            }
            if(((parm7&0x01)==0x01)&&(type[8]==0x07)&&(dirc[8]==0x03))
            {
              QLabel_list[8]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y1.png);"));
            }
            if(((parm7&0x01)==0x01)&&(type[8]==0x07)&&(dirc[8]==0x04))
            {
              QLabel_list[8]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y4.png);"));
            }
            if(((parm7&0x01)==0x01)&&(type[8]==0x08)&&(dirc[8]==0x01))
            {
              QLabel_list[8]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y1.png);"));
            }
            if(((parm7&0x01)==0x01)&&(type[8]==0x08)&&(dirc[8]==0x02))
            {
              QLabel_list[8]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y4.png);"));
            }
            if(((parm7&0x01)==0x01)&&(type[8]==0x08)&&(dirc[8]==0x03))
            {
              QLabel_list[8]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y2.png);"));
            }
            if(((parm7&0x01)==0x01)&&(type[8]==0x08)&&(dirc[8]==0x04))
            {
              QLabel_list[8]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y3.png);"));
            }
            if(((parm7&0x01)==0x01)&&(type[8]==0x09)&&(dirc[8]==0x01))
            {
              QLabel_list[8]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/YY.png);"));
            }
            if(((parm7&0x01)==0x01)&&(type[8]==0x09)&&(dirc[8]==0x02))
            {
              QLabel_list[8]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/YY.png);"));
            }
            if(((parm7&0x01)==0x01)&&(type[8]==0x09)&&(dirc[8]==0x03))
            {
              QLabel_list[8]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/YY.png);"));
            }
            if(((parm7&0x01)==0x01)&&(type[8]==0x09)&&(dirc[8]==0x04))
            {
              QLabel_list[8]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/YY.png);"));
            }


            if(((parm7&0x02)==0x02)&&(type[9]==0x03)&&(dirc[9]==0x01))
            {
              QLabel_list[9]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm7&0x02)==0x02)&&(type[9]==0x03)&&(dirc[9]==0x02))
            {
              QLabel_list[9]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm7&0x02)==0x02)&&(type[9]==0x03)&&(dirc[9]==0x03))
            {
              QLabel_list[9]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm7&0x02)==0x02)&&(type[9]==0x03)&&(dirc[9]==0x04))
            {
              QLabel_list[9]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm7&0x02)==0x02)&&(type[9]==0x05)&&(dirc[9]==0x01))
            {
              QLabel_list[9]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm7&0x02)==0x02)&&(type[9]==0x05)&&(dirc[9]==0x02))
            {
              QLabel_list[9]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm7&0x02)==0x02)&&(type[9]==0x05)&&(dirc[9]==0x03))
            {
              QLabel_list[9]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm7&0x02)==0x02)&&(type[9]==0x05)&&(dirc[9]==0x04))
            {
              QLabel_list[9]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm7&0x02)==0x02)&&(type[9]==0x06)&&(dirc[9]==0x01))
            {
              QLabel_list[9]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y3.png);"));
            }
            if(((parm7&0x02)==0x02)&&(type[9]==0x06)&&(dirc[9]==0x02))
            {
              QLabel_list[9]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y1.png);"));
            }
            if(((parm7&0x02)==0x02)&&(type[9]==0x06)&&(dirc[9]==0x03))
            {
              QLabel_list[9]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y4.png);"));
            }
            if(((parm7&0x02)==0x02)&&(type[9]==0x06)&&(dirc[9]==0x04))
            {
              QLabel_list[9]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y2.png);"));
            }
            if(((parm7&0x02)==0x02)&&(type[9]==0x07)&&(dirc[9]==0x01))
            {
              QLabel_list[9]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y2.png);"));
            }
            if(((parm7&0x02)==0x02)&&(type[9]==0x07)&&(dirc[9]==0x02))
            {
              QLabel_list[9]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y3.png);"));
            }
            if(((parm7&0x02)==0x02)&&(type[9]==0x07)&&(dirc[9]==0x03))
            {
              QLabel_list[9]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y1.png);"));
            }
            if(((parm7&0x02)==0x02)&&(type[9]==0x07)&&(dirc[9]==0x04))
            {
              QLabel_list[9]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y4.png);"));
            }
            if(((parm7&0x02)==0x02)&&(type[9]==0x08)&&(dirc[9]==0x01))
            {
              QLabel_list[9]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y1.png);"));
            }
            if(((parm7&0x02)==0x02)&&(type[9]==0x08)&&(dirc[9]==0x02))
            {
              QLabel_list[9]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y4.png);"));
            }
            if(((parm7&0x02)==0x02)&&(type[9]==0x08)&&(dirc[9]==0x03))
            {
              QLabel_list[9]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y2.png);"));
            }
            if(((parm7&0x02)==0x02)&&(type[9]==0x08)&&(dirc[9]==0x04))
            {
              QLabel_list[9]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y3.png);"));
            }
            if(((parm7&0x02)==0x02)&&(type[9]==0x09)&&(dirc[9]==0x01))
            {
              QLabel_list[9]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/YY.png);"));
            }
            if(((parm7&0x02)==0x02)&&(type[9]==0x09)&&(dirc[9]==0x02))
            {
              QLabel_list[9]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/YY.png);"));
            }
            if(((parm7&0x02)==0x02)&&(type[9]==0x09)&&(dirc[9]==0x03))
            {
              QLabel_list[9]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/YY.png);"));
            }
            if(((parm7&0x02)==0x02)&&(type[9]==0x09)&&(dirc[9]==0x04))
            {
              QLabel_list[9]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/YY.png);"));
            }

            if(((parm7&0x04)==0x04)&&(type[10]==0x03)&&(dirc[10]==0x01))
            {
              QLabel_list[10]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm7&0x04)==0x04)&&(type[10]==0x03)&&(dirc[10]==0x02))
            {
              QLabel_list[10]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm7&0x04)==0x04)&&(type[10]==0x03)&&(dirc[10]==0x03))
            {
              QLabel_list[10]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm7&0x04)==0x04)&&(type[10]==0x03)&&(dirc[10]==0x04))
            {
              QLabel_list[10]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm7&0x04)==0x04)&&(type[10]==0x05)&&(dirc[10]==0x01))
            {
              QLabel_list[10]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm7&0x04)==0x04)&&(type[10]==0x05)&&(dirc[10]==0x02))
            {
              QLabel_list[10]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm7&0x04)==0x04)&&(type[10]==0x05)&&(dirc[10]==0x03))
            {
              QLabel_list[10]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm7&0x04)==0x04)&&(type[10]==0x05)&&(dirc[10]==0x04))
            {
              QLabel_list[10]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm7&0x04)==0x04)&&(type[10]==0x06)&&(dirc[10]==0x01))
            {
              QLabel_list[10]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y3.png);"));
            }
            if(((parm7&0x04)==0x04)&&(type[10]==0x06)&&(dirc[10]==0x02))
            {
              QLabel_list[10]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y1.png);"));
            }
            if(((parm7&0x04)==0x04)&&(type[10]==0x06)&&(dirc[10]==0x03))
            {
              QLabel_list[10]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y4.png);"));
            }
            if(((parm7&0x04)==0x04)&&(type[10]==0x06)&&(dirc[10]==0x04))
            {
              QLabel_list[10]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y2.png);"));
            }
            if(((parm7&0x04)==0x04)&&(type[10]==0x07)&&(dirc[10]==0x01))
            {
              QLabel_list[10]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y2.png);"));
            }
            if(((parm7&0x04)==0x04)&&(type[10]==0x07)&&(dirc[10]==0x02))
            {
              QLabel_list[10]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y3.png);"));
            }
            if(((parm7&0x04)==0x04)&&(type[10]==0x07)&&(dirc[10]==0x03))
            {
              QLabel_list[10]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y1.png);"));
            }
            if(((parm7&0x04)==0x04)&&(type[10]==0x07)&&(dirc[10]==0x04))
            {
              QLabel_list[10]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y4.png);"));
            }
            if(((parm7&0x04)==0x04)&&(type[10]==0x08)&&(dirc[10]==0x01))
            {
              QLabel_list[10]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y1.png);"));
            }
            if(((parm7&0x04)==0x04)&&(type[10]==0x08)&&(dirc[10]==0x02))
            {
              QLabel_list[10]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y4.png);"));
            }
            if(((parm7&0x04)==0x04)&&(type[10]==0x08)&&(dirc[10]==0x03))
            {
              QLabel_list[10]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y2.png);"));
            }
            if(((parm7&0x04)==0x04)&&(type[10]==0x08)&&(dirc[10]==0x04))
            {
              QLabel_list[10]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y3.png);"));
            }
            if(((parm7&0x04)==0x04)&&(type[10]==0x09)&&(dirc[10]==0x01))
            {
              QLabel_list[10]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/YY.png);"));
            }
            if(((parm7&0x04)==0x04)&&(type[10]==0x09)&&(dirc[10]==0x02))
            {
              QLabel_list[10]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/YY.png);"));
            }
            if(((parm7&0x04)==0x04)&&(type[10]==0x09)&&(dirc[10]==0x03))
            {
              QLabel_list[10]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/YY.png);"));
            }
            if(((parm7&0x04)==0x04)&&(type[10]==0x09)&&(dirc[10]==0x04))
            {
              QLabel_list[10]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/YY.png);"));
            }

            if(((parm7&0x08)==0x08)&&(type[12]==0x03)&&(dirc[11]==0x01))
            {
              QLabel_list[11]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm7&0x08)==0x08)&&(type[12]==0x03)&&(dirc[11]==0x02))
            {
              QLabel_list[11]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm7&0x08)==0x08)&&(type[12]==0x03)&&(dirc[11]==0x03))
            {
              QLabel_list[11]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm7&0x08)==0x08)&&(type[12]==0x03)&&(dirc[11]==0x04))
            {
              QLabel_list[11]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm7&0x08)==0x08)&&(type[12]==0x05)&&(dirc[11]==0x01))
            {
              QLabel_list[11]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm7&0x08)==0x08)&&(type[12]==0x05)&&(dirc[11]==0x02))
            {
              QLabel_list[11]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm7&0x08)==0x08)&&(type[12]==0x05)&&(dirc[11]==0x03))
            {
              QLabel_list[11]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm7&0x08)==0x08)&&(type[12]==0x05)&&(dirc[11]==0x04))
            {
              QLabel_list[11]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm7&0x08)==0x08)&&(type[12]==0x06)&&(dirc[11]==0x01))
            {
              QLabel_list[11]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y3.png);"));
            }
            if(((parm7&0x08)==0x08)&&(type[12]==0x06)&&(dirc[11]==0x02))
            {
              QLabel_list[11]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y1.png);"));
            }
            if(((parm7&0x08)==0x08)&&(type[12]==0x06)&&(dirc[11]==0x03))
            {
              QLabel_list[11]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y4.png);"));
            }
            if(((parm7&0x08)==0x08)&&(type[12]==0x06)&&(dirc[11]==0x04))
            {
              QLabel_list[11]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y2.png);"));
            }
            if(((parm7&0x08)==0x08)&&(type[12]==0x07)&&(dirc[11]==0x01))
            {
              QLabel_list[11]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y2.png);"));
            }
            if(((parm7&0x08)==0x08)&&(type[12]==0x07)&&(dirc[11]==0x02))
            {
              QLabel_list[11]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y3.png);"));
            }
            if(((parm7&0x08)==0x08)&&(type[12]==0x07)&&(dirc[11]==0x03))
            {
              QLabel_list[11]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y1.png);"));
            }
            if(((parm7&0x08)==0x08)&&(type[12]==0x07)&&(dirc[11]==0x04))
            {
              QLabel_list[11]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y4.png);"));
            }
            if(((parm7&0x08)==0x08)&&(type[12]==0x08)&&(dirc[11]==0x01))
            {
              QLabel_list[11]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y1.png);"));
            }
            if(((parm7&0x08)==0x08)&&(type[12]==0x08)&&(dirc[11]==0x02))
            {
              QLabel_list[11]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y4.png);"));
            }
            if(((parm7&0x08)==0x08)&&(type[12]==0x08)&&(dirc[11]==0x03))
            {
              QLabel_list[11]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y2.png);"));
            }
            if(((parm7&0x08)==0x08)&&(type[12]==0x08)&&(dirc[11]==0x04))
            {
              QLabel_list[11]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y3.png);"));
            }
            if(((parm7&0x08)==0x08)&&(type[12]==0x09)&&(dirc[11]==0x01))
            {
              QLabel_list[11]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/YY.png);"));
            }
            if(((parm7&0x08)==0x08)&&(type[12]==0x09)&&(dirc[11]==0x02))
            {
              QLabel_list[11]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/YY.png);"));
            }
            if(((parm7&0x08)==0x08)&&(type[12]==0x09)&&(dirc[11]==0x03))
            {
              QLabel_list[11]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/YY.png);"));
            }
            if(((parm7&0x08)==0x08)&&(type[12]==0x09)&&(dirc[11]==0x04))
            {
              QLabel_list[11]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/YY.png);"));
            }


            if(((parm7&0x10)==0x10)&&(type[12]==0x03)&&(dirc[12]==0x01))
            {
              QLabel_list[12]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm7&0x10)==0x10)&&(type[12]==0x03)&&(dirc[12]==0x02))
            {
              QLabel_list[12]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm7&0x10)==0x10)&&(type[12]==0x03)&&(dirc[12]==0x03))
            {
              QLabel_list[12]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm7&0x10)==0x10)&&(type[12]==0x03)&&(dirc[12]==0x04))
            {
              QLabel_list[12]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm7&0x10)==0x10)&&(type[12]==0x05)&&(dirc[12]==0x01))
            {
              QLabel_list[12]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm7&0x10)==0x10)&&(type[12]==0x05)&&(dirc[12]==0x02))
            {
              QLabel_list[12]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm7&0x10)==0x10)&&(type[12]==0x05)&&(dirc[12]==0x03))
            {
              QLabel_list[12]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm7&0x10)==0x10)&&(type[12]==0x05)&&(dirc[12]==0x04))
            {
              QLabel_list[12]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm7&0x10)==0x10)&&(type[12]==0x06)&&(dirc[12]==0x01))
            {
              QLabel_list[12]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y3.png);"));
            }
            if(((parm7&0x10)==0x10)&&(type[12]==0x06)&&(dirc[12]==0x02))
            {
              QLabel_list[12]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y1.png);"));
            }
            if(((parm7&0x10)==0x10)&&(type[12]==0x06)&&(dirc[12]==0x03))
            {
              QLabel_list[12]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y4.png);"));
            }
            if(((parm7&0x10)==0x10)&&(type[12]==0x06)&&(dirc[12]==0x04))
            {
              QLabel_list[12]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y2.png);"));
            }
            if(((parm7&0x10)==0x10)&&(type[12]==0x07)&&(dirc[12]==0x01))
            {
              QLabel_list[12]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y2.png);"));
            }
            if(((parm7&0x10)==0x10)&&(type[12]==0x07)&&(dirc[12]==0x02))
            {
              QLabel_list[12]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y3.png);"));
            }
            if(((parm7&0x10)==0x10)&&(type[12]==0x07)&&(dirc[12]==0x03))
            {
              QLabel_list[12]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y1.png);"));
            }
            if(((parm7&0x10)==0x10)&&(type[12]==0x07)&&(dirc[12]==0x04))
            {
              QLabel_list[12]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y4.png);"));
            }
            if(((parm7&0x10)==0x10)&&(type[12]==0x08)&&(dirc[12]==0x01))
            {
              QLabel_list[12]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y1.png);"));
            }
            if(((parm7&0x10)==0x10)&&(type[12]==0x08)&&(dirc[12]==0x02))
            {
              QLabel_list[12]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y4.png);"));
            }
            if(((parm7&0x10)==0x10)&&(type[12]==0x08)&&(dirc[12]==0x03))
            {
              QLabel_list[12]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y2.png);"));
            }
            if(((parm7&0x10)==0x10)&&(type[12]==0x08)&&(dirc[12]==0x04))
            {
              QLabel_list[12]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y3.png);"));
            }
            if(((parm7&0x10)==0x10)&&(type[12]==0x09)&&(dirc[12]==0x01))
            {
              QLabel_list[12]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/YY.png);"));
            }
            if(((parm7&0x10)==0x10)&&(type[12]==0x09)&&(dirc[12]==0x02))
            {
              QLabel_list[12]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/YY.png);"));
            }
            if(((parm7&0x10)==0x10)&&(type[12]==0x09)&&(dirc[12]==0x03))
            {
              QLabel_list[12]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/YY.png);"));
            }
            if(((parm7&0x10)==0x10)&&(type[12]==0x09)&&(dirc[12]==0x04))
            {
              QLabel_list[12]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/YY.png);"));
            }

            if(((parm7&0x20)==0x20)&&(type[13]==0x03)&&(dirc[13]==0x01))
            {
              QLabel_list[13]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm7&0x20)==0x20)&&(type[13]==0x03)&&(dirc[13]==0x02))
            {
              QLabel_list[13]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm7&0x20)==0x20)&&(type[13]==0x03)&&(dirc[13]==0x03))
            {
              QLabel_list[13]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm7&0x20)==0x20)&&(type[13]==0x03)&&(dirc[13]==0x04))
            {
              QLabel_list[13]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm7&0x20)==0x20)&&(type[13]==0x05)&&(dirc[13]==0x01))
            {
              QLabel_list[13]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm7&0x20)==0x20)&&(type[13]==0x05)&&(dirc[13]==0x02))
            {
              QLabel_list[13]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm7&0x20)==0x20)&&(type[13]==0x05)&&(dirc[13]==0x03))
            {
              QLabel_list[13]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm7&0x20)==0x20)&&(type[13]==0x05)&&(dirc[13]==0x04))
            {
              QLabel_list[13]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm7&0x20)==0x20)&&(type[13]==0x06)&&(dirc[13]==0x01))
            {
              QLabel_list[13]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y3.png);"));
            }
            if(((parm7&0x20)==0x20)&&(type[13]==0x06)&&(dirc[13]==0x02))
            {
              QLabel_list[13]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y1.png);"));
            }
            if(((parm7&0x20)==0x20)&&(type[13]==0x06)&&(dirc[13]==0x03))
            {
              QLabel_list[13]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y4.png);"));
            }
            if(((parm7&0x20)==0x20)&&(type[13]==0x06)&&(dirc[13]==0x04))
            {
              QLabel_list[13]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y2.png);"));
            }
            if(((parm7&0x20)==0x20)&&(type[13]==0x07)&&(dirc[13]==0x01))
            {
              QLabel_list[13]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y2.png);"));
            }
            if(((parm7&0x20)==0x20)&&(type[13]==0x07)&&(dirc[13]==0x02))
            {
              QLabel_list[13]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y3.png);"));
            }
            if(((parm7&0x20)==0x20)&&(type[13]==0x07)&&(dirc[13]==0x03))
            {
              QLabel_list[13]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y1.png);"));
            }
            if(((parm7&0x20)==0x20)&&(type[13]==0x07)&&(dirc[13]==0x04))
            {
              QLabel_list[13]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y4.png);"));
            }
            if(((parm7&0x20)==0x20)&&(type[13]==0x08)&&(dirc[13]==0x01))
            {
              QLabel_list[13]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y1.png);"));
            }
            if(((parm7&0x20)==0x20)&&(type[13]==0x08)&&(dirc[13]==0x02))
            {
              QLabel_list[13]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y4.png);"));
            }
            if(((parm7&0x20)==0x20)&&(type[13]==0x08)&&(dirc[13]==0x03))
            {
              QLabel_list[13]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y2.png);"));
            }
            if(((parm7&0x20)==0x20)&&(type[13]==0x08)&&(dirc[13]==0x04))
            {
              QLabel_list[13]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y3.png);"));
            }
            if(((parm7&0x20)==0x20)&&(type[13]==0x09)&&(dirc[13]==0x01))
            {
              QLabel_list[13]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/YY.png);"));
            }
            if(((parm7&0x20)==0x20)&&(type[13]==0x09)&&(dirc[13]==0x02))
            {
              QLabel_list[13]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/YY.png);"));
            }
            if(((parm7&0x20)==0x20)&&(type[13]==0x09)&&(dirc[13]==0x03))
            {
              QLabel_list[13]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/YY.png);"));
            }
            if(((parm7&0x20)==0x20)&&(type[13]==0x09)&&(dirc[13]==0x04))
            {
              QLabel_list[13]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/YY.png);"));
            }


            if(((parm7&0x40)==0x40)&&(type[14]==0x03)&&(dirc[14]==0x01))
            {
              QLabel_list[14]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm7&0x40)==0x40)&&(type[14]==0x03)&&(dirc[14]==0x02))
            {
              QLabel_list[14]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm7&0x40)==0x40)&&(type[14]==0x03)&&(dirc[14]==0x03))
            {
              QLabel_list[14]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm7&0x40)==0x40)&&(type[14]==0x03)&&(dirc[14]==0x04))
            {
              QLabel_list[14]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm7&0x40)==0x40)&&(type[14]==0x05)&&(dirc[14]==0x01))
            {
              QLabel_list[14]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm7&0x40)==0x40)&&(type[14]==0x05)&&(dirc[14]==0x02))
            {
              QLabel_list[14]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm7&0x40)==0x40)&&(type[14]==0x05)&&(dirc[14]==0x03))
            {
              QLabel_list[14]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm7&0x40)==0x40)&&(type[14]==0x05)&&(dirc[14]==0x04))
            {
              QLabel_list[14]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm7&0x40)==0x40)&&(type[14]==0x06)&&(dirc[14]==0x01))
            {
              QLabel_list[14]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y3.png);"));
            }
            if(((parm7&0x40)==0x40)&&(type[14]==0x06)&&(dirc[14]==0x02))
            {
              QLabel_list[14]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y1.png);"));
            }
            if(((parm7&0x40)==0x40)&&(type[14]==0x06)&&(dirc[14]==0x03))
            {
              QLabel_list[14]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y4.png);"));
            }
            if(((parm7&0x40)==0x40)&&(type[14]==0x06)&&(dirc[14]==0x04))
            {
              QLabel_list[14]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y2.png);"));
            }
            if(((parm7&0x40)==0x40)&&(type[14]==0x07)&&(dirc[14]==0x01))
            {
              QLabel_list[14]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y2.png);"));
            }
            if(((parm7&0x40)==0x40)&&(type[14]==0x07)&&(dirc[14]==0x02))
            {
              QLabel_list[14]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y3.png);"));
            }
            if(((parm7&0x40)==0x40)&&(type[14]==0x07)&&(dirc[14]==0x03))
            {
              QLabel_list[14]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y1.png);"));
            }
            if(((parm7&0x40)==0x40)&&(type[14]==0x07)&&(dirc[14]==0x04))
            {
              QLabel_list[14]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y4.png);"));
            }
            if(((parm7&0x40)==0x40)&&(type[14]==0x08)&&(dirc[14]==0x01))
            {
              QLabel_list[14]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y1.png);"));
            }
            if(((parm7&0x40)==0x40)&&(type[14]==0x08)&&(dirc[14]==0x02))
            {
              QLabel_list[14]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y4.png);"));
            }
            if(((parm7&0x40)==0x40)&&(type[14]==0x08)&&(dirc[14]==0x03))
            {
              QLabel_list[14]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y2.png);"));
            }
            if(((parm7&0x40)==0x40)&&(type[14]==0x08)&&(dirc[14]==0x04))
            {
              QLabel_list[14]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y3.png);"));
            }
            if(((parm7&0x40)==0x40)&&(type[14]==0x09)&&(dirc[14]==0x01))
            {
              QLabel_list[14]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/YY.png);"));
            }
            if(((parm7&0x40)==0x40)&&(type[14]==0x09)&&(dirc[14]==0x02))
            {
              QLabel_list[14]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/YY.png);"));
            }
            if(((parm7&0x40)==0x40)&&(type[14]==0x09)&&(dirc[14]==0x03))
            {
              QLabel_list[14]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/YY.png);"));
            }
            if(((parm7&0x40)==0x40)&&(type[14]==0x09)&&(dirc[14]==0x04))
            {
              QLabel_list[14]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/YY.png);"));
            }


            if(((parm7&0x80)==0x80)&&(type[15]==0x03)&&(dirc[15]==0x01))
            {
              QLabel_list[15]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm7&0x80)==0x80)&&(type[15]==0x03)&&(dirc[15]==0x02))
            {
              QLabel_list[15]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm7&0x80)==0x80)&&(type[15]==0x03)&&(dirc[15]==0x03))
            {
              QLabel_list[15]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm7&0x80)==0x80)&&(type[15]==0x03)&&(dirc[15]==0x04))
            {
              QLabel_list[15]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm7&0x80)==0x80)&&(type[15]==0x05)&&(dirc[15]==0x01))
            {
              QLabel_list[15]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm7&0x80)==0x80)&&(type[15]==0x05)&&(dirc[15]==0x02))
            {
              QLabel_list[15]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm7&0x80)==0x80)&&(type[15]==0x05)&&(dirc[15]==0x03))
            {
              QLabel_list[15]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm7&0x80)==0x80)&&(type[15]==0x05)&&(dirc[15]==0x04))
            {
              QLabel_list[15]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
            }
            if(((parm7&0x80)==0x80)&&(type[15]==0x06)&&(dirc[15]==0x01))
            {
              QLabel_list[15]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y3.png);"));
            }
            if(((parm7&0x80)==0x80)&&(type[15]==0x06)&&(dirc[15]==0x02))
            {
              QLabel_list[15]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y1.png);"));
            }
            if(((parm7&0x80)==0x80)&&(type[15]==0x06)&&(dirc[15]==0x03))
            {
              QLabel_list[15]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y4.png);"));
            }
            if(((parm7&0x80)==0x80)&&(type[15]==0x06)&&(dirc[15]==0x04))
            {
              QLabel_list[15]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y2.png);"));
            }
            if(((parm7&0x80)==0x80)&&(type[15]==0x07)&&(dirc[15]==0x01))
            {
              QLabel_list[15]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y2.png);"));
            }
            if(((parm7&0x80)==0x80)&&(type[15]==0x07)&&(dirc[15]==0x02))
            {
              QLabel_list[15]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y3.png);"));
            }
            if(((parm7&0x80)==0x80)&&(type[15]==0x07)&&(dirc[15]==0x03))
            {
              QLabel_list[15]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y1.png);"));
            }
            if(((parm7&0x80)==0x80)&&(type[15]==0x07)&&(dirc[15]==0x04))
            {
              QLabel_list[15]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y4.png);"));
            }
            if(((parm7&0x80)==0x80)&&(type[15]==0x08)&&(dirc[15]==0x01))
            {
              QLabel_list[15]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y1.png);"));
            }
            if(((parm7&0x80)==0x80)&&(type[15]==0x08)&&(dirc[15]==0x02))
            {
              QLabel_list[15]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y4.png);"));
            }
            if(((parm7&0x80)==0x80)&&(type[15]==0x08)&&(dirc[15]==0x03))
            {
              QLabel_list[15]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y2.png);"));
            }
            if(((parm7&0x80)==0x80)&&(type[15]==0x08)&&(dirc[15]==0x04))
            {
              QLabel_list[15]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y3.png);"));
            }
            if(((parm7&0x80)==0x80)&&(type[15]==0x09)&&(dirc[15]==0x01))
            {
              QLabel_list[15]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/YY.png);"));
            }
            if(((parm7&0x80)==0x80)&&(type[15]==0x09)&&(dirc[15]==0x02))
            {
              QLabel_list[15]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/YY.png);"));
            }
            if(((parm7&0x80)==0x80)&&(type[15]==0x09)&&(dirc[15]==0x03))
            {
              QLabel_list[15]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/YY.png);"));
            }
            if(((parm7&0x80)==0x80)&&(type[15]==0x09)&&(dirc[15]==0x04))
            {
              QLabel_list[15]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/YY.png);"));
            }

        }



        {
            if(((parm8&0x01)==0x01)&&(type[8]==0x03)&&(dirc[8]==0x01))
            {
              QLabel_list[8]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
            }
            if(((parm8&0x01)==0x01)&&(type[8]==0x03)&&(dirc[8]==0x02))
            {
              QLabel_list[8]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
            }
            if(((parm8&0x01)==0x01)&&(type[8]==0x03)&&(dirc[8]==0x03))
            {
              QLabel_list[8]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
            }
            if(((parm8&0x01)==0x01)&&(type[8]==0x03)&&(dirc[8]==0x04))
            {
              QLabel_list[8]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
            }
            if(((parm8&0x01)==0x01)&&(type[8]==0x05)&&(dirc[8]==0x01))
            {
              QLabel_list[8]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
            }
            if(((parm8&0x01)==0x01)&&(type[8]==0x05)&&(dirc[8]==0x02))
            {
              QLabel_list[8]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
            }
            if(((parm8&0x01)==0x01)&&(type[8]==0x05)&&(dirc[8]==0x03))
            {
              QLabel_list[8]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
            }
            if(((parm8&0x01)==0x01)&&(type[8]==0x05)&&(dirc[8]==0x04))
            {
              QLabel_list[8]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
            }
            if(((parm8&0x01)==0x01)&&(type[8]==0x06)&&(dirc[8]==0x01))
            {
              QLabel_list[8]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G3.png);"));
            }
            if(((parm8&0x01)==0x01)&&(type[8]==0x06)&&(dirc[8]==0x02))
            {
              QLabel_list[8]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G1.png);"));
            }
            if(((parm8&0x01)==0x01)&&(type[8]==0x06)&&(dirc[8]==0x03))
            {
              QLabel_list[8]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G4.png);"));
            }
            if(((parm8&0x01)==0x01)&&(type[8]==0x06)&&(dirc[8]==0x04))
            {
              QLabel_list[8]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G2.png);"));
            }
            if(((parm8&0x01)==0x01)&&(type[8]==0x07)&&(dirc[8]==0x01))
            {
              QLabel_list[8]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G2.png);"));
            }
            if(((parm8&0x01)==0x01)&&(type[8]==0x07)&&(dirc[8]==0x02))
            {
              QLabel_list[8]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G3.png);"));
            }
            if(((parm8&0x01)==0x01)&&(type[8]==0x07)&&(dirc[8]==0x03))
            {
              QLabel_list[8]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G1.png);"));
            }
            if(((parm8&0x01)==0x01)&&(type[8]==0x07)&&(dirc[8]==0x04))
            {
              QLabel_list[8]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G4.png);"));
            }
            if(((parm8&0x01)==0x01)&&(type[8]==0x08)&&(dirc[8]==0x01))
            {
              QLabel_list[8]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G1.png);"));
            }
            if(((parm8&0x01)==0x01)&&(type[8]==0x08)&&(dirc[8]==0x02))
            {
              QLabel_list[8]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G4.png);"));
            }
            if(((parm8&0x01)==0x01)&&(type[8]==0x08)&&(dirc[8]==0x03))
            {
              QLabel_list[8]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G2.png);"));
            }
            if(((parm8&0x01)==0x01)&&(type[8]==0x08)&&(dirc[8]==0x04))
            {
              QLabel_list[8]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G3.png);"));
            }
            if(((parm8&0x01)==0x01)&&(type[8]==0x09)&&(dirc[8]==0x01))
            {
              QLabel_list[8]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/GG.png);"));
            }
            if(((parm8&0x01)==0x01)&&(type[8]==0x09)&&(dirc[8]==0x02))
            {
              QLabel_list[8]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/GG.png);"));
            }
            if(((parm8&0x01)==0x01)&&(type[8]==0x09)&&(dirc[8]==0x03))
            {
              QLabel_list[8]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/GG.png);"));
            }
            if(((parm8&0x01)==0x01)&&(type[8]==0x09)&&(dirc[8]==0x04))
            {
              QLabel_list[8]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/GG.png);"));
            }


            if(((parm8&0x02)==0x02)&&(type[9]==0x03)&&(dirc[9]==0x01))
            {
              QLabel_list[9]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
            }
            if(((parm8&0x02)==0x02)&&(type[9]==0x03)&&(dirc[9]==0x02))
            {
              QLabel_list[9]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
            }
            if(((parm8&0x02)==0x02)&&(type[9]==0x03)&&(dirc[9]==0x03))
            {
              QLabel_list[9]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
            }
            if(((parm8&0x02)==0x02)&&(type[9]==0x03)&&(dirc[9]==0x04))
            {
              QLabel_list[9]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
            }
            if(((parm8&0x02)==0x02)&&(type[9]==0x05)&&(dirc[9]==0x01))
            {
              QLabel_list[9]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
            }
            if(((parm8&0x02)==0x02)&&(type[9]==0x05)&&(dirc[9]==0x02))
            {
              QLabel_list[9]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
            }
            if(((parm8&0x02)==0x02)&&(type[9]==0x05)&&(dirc[9]==0x03))
            {
              QLabel_list[9]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
            }
            if(((parm8&0x02)==0x02)&&(type[9]==0x05)&&(dirc[9]==0x04))
            {
              QLabel_list[9]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
            }
            if(((parm8&0x02)==0x02)&&(type[9]==0x06)&&(dirc[9]==0x01))
            {
              QLabel_list[9]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G3.png);"));
            }
            if(((parm8&0x02)==0x02)&&(type[9]==0x06)&&(dirc[9]==0x02))
            {
              QLabel_list[9]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G1.png);"));
            }
            if(((parm8&0x02)==0x02)&&(type[9]==0x06)&&(dirc[9]==0x03))
            {
              QLabel_list[9]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G4.png);"));
            }
            if(((parm8&0x02)==0x02)&&(type[9]==0x06)&&(dirc[9]==0x04))
            {
              QLabel_list[9]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G2.png);"));
            }
            if(((parm8&0x02)==0x02)&&(type[9]==0x07)&&(dirc[9]==0x01))
            {
              QLabel_list[9]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G2.png);"));
            }
            if(((parm8&0x02)==0x02)&&(type[9]==0x07)&&(dirc[9]==0x02))
            {
              QLabel_list[9]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G3.png);"));
            }
            if(((parm8&0x02)==0x02)&&(type[9]==0x07)&&(dirc[9]==0x03))
            {
              QLabel_list[9]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G1.png);"));
            }
            if(((parm8&0x02)==0x02)&&(type[9]==0x07)&&(dirc[9]==0x04))
            {
              QLabel_list[9]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G4.png);"));
            }
            if(((parm8&0x02)==0x02)&&(type[9]==0x08)&&(dirc[9]==0x01))
            {
              QLabel_list[9]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G1.png);"));
            }
            if(((parm8&0x02)==0x02)&&(type[9]==0x08)&&(dirc[9]==0x02))
            {
              QLabel_list[9]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G4.png);"));
            }
            if(((parm8&0x02)==0x02)&&(type[9]==0x08)&&(dirc[9]==0x03))
            {
              QLabel_list[9]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G2.png);"));
            }
            if(((parm8&0x02)==0x02)&&(type[9]==0x08)&&(dirc[9]==0x04))
            {
              QLabel_list[9]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G3.png);"));
            }
            if(((parm8&0x02)==0x02)&&(type[9]==0x09)&&(dirc[9]==0x01))
            {
              QLabel_list[9]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/GG.png);"));
            }
            if(((parm8&0x02)==0x02)&&(type[9]==0x09)&&(dirc[9]==0x02))
            {
              QLabel_list[9]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/GG.png);"));
            }
            if(((parm8&0x02)==0x02)&&(type[9]==0x09)&&(dirc[9]==0x03))
            {
              QLabel_list[9]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/GG.png);"));
            }
            if(((parm8&0x02)==0x02)&&(type[9]==0x09)&&(dirc[9]==0x04))
            {
              QLabel_list[9]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/GG.png);"));
            }

            if(((parm8&0x04)==0x04)&&(type[10]==0x03)&&(dirc[10]==0x01))
            {
              QLabel_list[10]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
            }
            if(((parm8&0x04)==0x04)&&(type[10]==0x03)&&(dirc[10]==0x02))
            {
              QLabel_list[10]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
            }
            if(((parm8&0x04)==0x04)&&(type[10]==0x03)&&(dirc[10]==0x03))
            {
              QLabel_list[10]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
            }
            if(((parm8&0x04)==0x04)&&(type[10]==0x03)&&(dirc[10]==0x04))
            {
              QLabel_list[10]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
            }
            if(((parm8&0x04)==0x04)&&(type[10]==0x05)&&(dirc[10]==0x01))
            {
              QLabel_list[10]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
            }
            if(((parm8&0x04)==0x04)&&(type[10]==0x05)&&(dirc[10]==0x02))
            {
              QLabel_list[10]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
            }
            if(((parm8&0x04)==0x04)&&(type[10]==0x05)&&(dirc[10]==0x03))
            {
              QLabel_list[10]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
            }
            if(((parm8&0x04)==0x04)&&(type[10]==0x05)&&(dirc[10]==0x04))
            {
              QLabel_list[10]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
            }
            if(((parm8&0x04)==0x04)&&(type[10]==0x06)&&(dirc[10]==0x01))
            {
              QLabel_list[10]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G3.png);"));
            }
            if(((parm8&0x04)==0x04)&&(type[10]==0x06)&&(dirc[10]==0x02))
            {
              QLabel_list[10]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G1.png);"));
            }
            if(((parm8&0x04)==0x04)&&(type[10]==0x06)&&(dirc[10]==0x03))
            {
              QLabel_list[10]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G4.png);"));
            }
            if(((parm8&0x04)==0x04)&&(type[10]==0x06)&&(dirc[10]==0x04))
            {
              QLabel_list[10]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G2.png);"));
            }
            if(((parm8&0x04)==0x04)&&(type[10]==0x07)&&(dirc[10]==0x01))
            {
              QLabel_list[10]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G2.png);"));
            }
            if(((parm8&0x04)==0x04)&&(type[10]==0x07)&&(dirc[10]==0x02))
            {
              QLabel_list[10]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G3.png);"));
            }
            if(((parm8&0x04)==0x04)&&(type[10]==0x07)&&(dirc[10]==0x03))
            {
              QLabel_list[10]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G1.png);"));
            }
            if(((parm8&0x04)==0x04)&&(type[10]==0x07)&&(dirc[10]==0x04))
            {
              QLabel_list[10]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G4.png);"));
            }
            if(((parm8&0x04)==0x04)&&(type[10]==0x08)&&(dirc[10]==0x01))
            {
              QLabel_list[10]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G1.png);"));
            }
            if(((parm8&0x04)==0x04)&&(type[10]==0x08)&&(dirc[10]==0x02))
            {
              QLabel_list[10]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G4.png);"));
            }
            if(((parm8&0x04)==0x04)&&(type[10]==0x08)&&(dirc[10]==0x03))
            {
              QLabel_list[10]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G2.png);"));
            }
            if(((parm8&0x04)==0x04)&&(type[10]==0x08)&&(dirc[10]==0x04))
            {
              QLabel_list[10]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G3.png);"));
            }
            if(((parm8&0x04)==0x04)&&(type[10]==0x09)&&(dirc[10]==0x01))
            {
              QLabel_list[10]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/GG.png);"));
            }
            if(((parm8&0x04)==0x04)&&(type[10]==0x09)&&(dirc[10]==0x02))
            {
              QLabel_list[10]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/GG.png);"));
            }
            if(((parm8&0x04)==0x04)&&(type[10]==0x09)&&(dirc[10]==0x03))
            {
              QLabel_list[10]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/GG.png);"));
            }
            if(((parm8&0x04)==0x04)&&(type[10]==0x09)&&(dirc[10]==0x04))
            {
              QLabel_list[10]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/GG.png);"));
            }

            if(((parm8&0x08)==0x08)&&(type[11]==0x03)&&(dirc[11]==0x01))
            {
              QLabel_list[11]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
            }
            if(((parm8&0x08)==0x08)&&(type[11]==0x03)&&(dirc[11]==0x02))
            {
              QLabel_list[11]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
            }
            if(((parm8&0x08)==0x08)&&(type[11]==0x03)&&(dirc[11]==0x03))
            {
              QLabel_list[11]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
            }
            if(((parm8&0x08)==0x08)&&(type[11]==0x03)&&(dirc[11]==0x04))
            {
              QLabel_list[11]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
            }
            if(((parm8&0x08)==0x08)&&(type[11]==0x05)&&(dirc[11]==0x01))
            {
              QLabel_list[11]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
            }
            if(((parm8&0x08)==0x08)&&(type[11]==0x05)&&(dirc[11]==0x02))
            {
              QLabel_list[11]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
            }
            if(((parm8&0x08)==0x08)&&(type[11]==0x05)&&(dirc[11]==0x03))
            {
              QLabel_list[11]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
            }
            if(((parm8&0x08)==0x08)&&(type[11]==0x05)&&(dirc[11]==0x04))
            {
              QLabel_list[11]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
            }
            if(((parm8&0x08)==0x08)&&(type[11]==0x06)&&(dirc[11]==0x01))
            {
              QLabel_list[11]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G3.png);"));
            }
            if(((parm8&0x08)==0x08)&&(type[11]==0x06)&&(dirc[11]==0x02))
            {
              QLabel_list[11]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G1.png);"));
            }
            if(((parm8&0x08)==0x08)&&(type[11]==0x06)&&(dirc[11]==0x03))
            {
              QLabel_list[11]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G4.png);"));
            }
            if(((parm8&0x08)==0x08)&&(type[11]==0x06)&&(dirc[11]==0x04))
            {
              QLabel_list[11]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G2.png);"));
            }
            if(((parm8&0x08)==0x08)&&(type[11]==0x07)&&(dirc[11]==0x01))
            {
              QLabel_list[11]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G2.png);"));
            }
            if(((parm8&0x08)==0x08)&&(type[11]==0x07)&&(dirc[11]==0x02))
            {
              QLabel_list[11]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G3.png);"));
            }
            if(((parm8&0x08)==0x08)&&(type[11]==0x07)&&(dirc[11]==0x03))
            {
              QLabel_list[11]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G1.png);"));
            }
            if(((parm8&0x08)==0x08)&&(type[11]==0x07)&&(dirc[11]==0x04))
            {
              QLabel_list[11]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G4.png);"));
            }
            if(((parm8&0x08)==0x08)&&(type[11]==0x08)&&(dirc[11]==0x01))
            {
              QLabel_list[11]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G1.png);"));
            }
            if(((parm8&0x08)==0x08)&&(type[11]==0x08)&&(dirc[11]==0x02))
            {
              QLabel_list[11]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G4.png);"));
            }
            if(((parm8&0x08)==0x08)&&(type[11]==0x08)&&(dirc[11]==0x03))
            {
              QLabel_list[11]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G2.png);"));
            }
            if(((parm8&0x08)==0x08)&&(type[11]==0x08)&&(dirc[11]==0x04))
            {
              QLabel_list[11]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G3.png);"));
            }
            if(((parm8&0x08)==0x08)&&(type[11]==0x09)&&(dirc[11]==0x01))
            {
              QLabel_list[11]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/GG.png);"));
            }
            if(((parm8&0x08)==0x08)&&(type[11]==0x09)&&(dirc[11]==0x02))
            {
              QLabel_list[11]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/GG.png);"));
            }
            if(((parm8&0x08)==0x08)&&(type[11]==0x09)&&(dirc[11]==0x03))
            {
              QLabel_list[11]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/GG.png);"));
            }
            if(((parm8&0x08)==0x08)&&(type[11]==0x09)&&(dirc[11]==0x04))
            {
              QLabel_list[11]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/GG.png);"));
            }


            if(((parm8&0x10)==0x10)&&(type[12]==0x03)&&(dirc[12]==0x01))
            {
              QLabel_list[12]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
            }
            if(((parm8&0x10)==0x10)&&(type[12]==0x03)&&(dirc[12]==0x02))
            {
              QLabel_list[12]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
            }
            if(((parm8&0x10)==0x10)&&(type[12]==0x03)&&(dirc[12]==0x03))
            {
              QLabel_list[12]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
            }
            if(((parm8&0x10)==0x10)&&(type[12]==0x03)&&(dirc[12]==0x04))
            {
              QLabel_list[12]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
            }
            if(((parm8&0x10)==0x10)&&(type[12]==0x05)&&(dirc[12]==0x01))
            {
              QLabel_list[12]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
            }
            if(((parm8&0x10)==0x10)&&(type[12]==0x05)&&(dirc[12]==0x02))
            {
              QLabel_list[12]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
            }
            if(((parm8&0x10)==0x10)&&(type[12]==0x05)&&(dirc[12]==0x03))
            {
              QLabel_list[12]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
            }
            if(((parm8&0x10)==0x10)&&(type[12]==0x05)&&(dirc[12]==0x04))
            {
              QLabel_list[12]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
            }
            if(((parm8&0x10)==0x10)&&(type[12]==0x06)&&(dirc[12]==0x01))
            {
              QLabel_list[12]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G3.png);"));
            }
            if(((parm8&0x10)==0x10)&&(type[12]==0x06)&&(dirc[12]==0x02))
            {
              QLabel_list[12]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G1.png);"));
            }
            if(((parm8&0x10)==0x10)&&(type[12]==0x06)&&(dirc[12]==0x03))
            {
              QLabel_list[12]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G4.png);"));
            }
            if(((parm8&0x10)==0x10)&&(type[12]==0x06)&&(dirc[12]==0x04))
            {
              QLabel_list[12]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G2.png);"));
            }
            if(((parm8&0x10)==0x10)&&(type[12]==0x07)&&(dirc[12]==0x01))
            {
              QLabel_list[12]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G2.png);"));
            }
            if(((parm8&0x10)==0x10)&&(type[12]==0x07)&&(dirc[12]==0x02))
            {
              QLabel_list[12]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G3.png);"));
            }
            if(((parm8&0x10)==0x10)&&(type[12]==0x07)&&(dirc[12]==0x03))
            {
              QLabel_list[12]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G1.png);"));
            }
            if(((parm8&0x10)==0x10)&&(type[12]==0x07)&&(dirc[12]==0x04))
            {
              QLabel_list[12]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G4.png);"));
            }
            if(((parm8&0x10)==0x10)&&(type[12]==0x08)&&(dirc[12]==0x01))
            {
              QLabel_list[12]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G1.png);"));
            }
            if(((parm8&0x10)==0x10)&&(type[12]==0x08)&&(dirc[12]==0x02))
            {
              QLabel_list[12]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G4.png);"));
            }
            if(((parm8&0x10)==0x10)&&(type[12]==0x08)&&(dirc[12]==0x03))
            {
              QLabel_list[12]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G2.png);"));
            }
            if(((parm8&0x10)==0x10)&&(type[12]==0x08)&&(dirc[12]==0x04))
            {
              QLabel_list[12]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G3.png);"));
            }
            if(((parm8&0x10)==0x10)&&(type[12]==0x09)&&(dirc[12]==0x01))
            {
              QLabel_list[12]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/GG.png);"));
            }
            if(((parm8&0x10)==0x10)&&(type[12]==0x09)&&(dirc[12]==0x02))
            {
              QLabel_list[12]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/GG.png);"));
            }
            if(((parm8&0x10)==0x10)&&(type[12]==0x09)&&(dirc[12]==0x03))
            {
              QLabel_list[12]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/GG.png);"));
            }
            if(((parm8&0x10)==0x10)&&(type[12]==0x09)&&(dirc[12]==0x04))
            {
              QLabel_list[12]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/GG.png);"));
            }

            if(((parm8&0x20)==0x20)&&(type[13]==0x03)&&(dirc[13]==0x01))
            {
              QLabel_list[13]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
            }
            if(((parm8&0x20)==0x20)&&(type[13]==0x03)&&(dirc[13]==0x02))
            {
              QLabel_list[13]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
            }
            if(((parm8&0x20)==0x20)&&(type[13]==0x03)&&(dirc[13]==0x03))
            {
              QLabel_list[13]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
            }
            if(((parm8&0x20)==0x20)&&(type[13]==0x03)&&(dirc[13]==0x04))
            {
              QLabel_list[13]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
            }
            if(((parm8&0x20)==0x20)&&(type[13]==0x05)&&(dirc[13]==0x01))
            {
              QLabel_list[13]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
            }
            if(((parm8&0x20)==0x20)&&(type[13]==0x05)&&(dirc[13]==0x02))
            {
              QLabel_list[13]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
            }
            if(((parm8&0x20)==0x20)&&(type[13]==0x05)&&(dirc[13]==0x03))
            {
              QLabel_list[13]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
            }
            if(((parm8&0x20)==0x20)&&(type[13]==0x05)&&(dirc[13]==0x04))
            {
              QLabel_list[13]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
            }
            if(((parm8&0x20)==0x20)&&(type[13]==0x06)&&(dirc[13]==0x01))
            {
              QLabel_list[13]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G3.png);"));
            }
            if(((parm8&0x20)==0x20)&&(type[13]==0x06)&&(dirc[13]==0x02))
            {
              QLabel_list[13]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G1.png);"));
            }
            if(((parm8&0x20)==0x20)&&(type[13]==0x06)&&(dirc[13]==0x03))
            {
              QLabel_list[13]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G4.png);"));
            }
            if(((parm8&0x20)==0x20)&&(type[13]==0x06)&&(dirc[13]==0x04))
            {
              QLabel_list[13]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G2.png);"));
            }
            if(((parm8&0x20)==0x20)&&(type[13]==0x07)&&(dirc[13]==0x01))
            {
              QLabel_list[13]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G2.png);"));
            }
            if(((parm8&0x20)==0x20)&&(type[13]==0x07)&&(dirc[13]==0x02))
            {
              QLabel_list[13]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G3.png);"));
            }
            if(((parm8&0x20)==0x20)&&(type[13]==0x07)&&(dirc[13]==0x03))
            {
              QLabel_list[13]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G1.png);"));
            }
            if(((parm8&0x20)==0x20)&&(type[13]==0x07)&&(dirc[13]==0x04))
            {
              QLabel_list[13]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G4.png);"));
            }
            if(((parm8&0x20)==0x20)&&(type[13]==0x08)&&(dirc[13]==0x01))
            {
              QLabel_list[13]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G1.png);"));
            }
            if(((parm8&0x20)==0x20)&&(type[13]==0x08)&&(dirc[13]==0x02))
            {
              QLabel_list[13]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G4.png);"));
            }
            if(((parm8&0x20)==0x20)&&(type[13]==0x08)&&(dirc[13]==0x03))
            {
              QLabel_list[13]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G2.png);"));
            }
            if(((parm8&0x20)==0x20)&&(type[13]==0x08)&&(dirc[13]==0x04))
            {
              QLabel_list[13]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G3.png);"));
            }
            if(((parm8&0x20)==0x20)&&(type[13]==0x09)&&(dirc[13]==0x01))
            {
              QLabel_list[13]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/GG.png);"));
            }
            if(((parm8&0x20)==0x20)&&(type[13]==0x09)&&(dirc[13]==0x02))
            {
              QLabel_list[13]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/GG.png);"));
            }
            if(((parm8&0x20)==0x20)&&(type[13]==0x09)&&(dirc[13]==0x03))
            {
              QLabel_list[13]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/GG.png);"));
            }
            if(((parm8&0x20)==0x20)&&(type[13]==0x09)&&(dirc[13]==0x04))
            {
              QLabel_list[13]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/GG.png);"));
            }


            if(((parm8&0x40)==0x40)&&(type[14]==0x03)&&(dirc[14]==0x01))
            {
              QLabel_list[14]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
            }
            if(((parm8&0x40)==0x40)&&(type[14]==0x03)&&(dirc[14]==0x02))
            {
              QLabel_list[14]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
            }
            if(((parm8&0x40)==0x40)&&(type[14]==0x03)&&(dirc[14]==0x03))
            {
              QLabel_list[14]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
            }
            if(((parm8&0x40)==0x40)&&(type[14]==0x03)&&(dirc[14]==0x04))
            {
              QLabel_list[14]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
            }
            if(((parm8&0x40)==0x40)&&(type[14]==0x05)&&(dirc[14]==0x01))
            {
              QLabel_list[14]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
            }
            if(((parm8&0x40)==0x40)&&(type[14]==0x05)&&(dirc[14]==0x02))
            {
              QLabel_list[14]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
            }
            if(((parm8&0x40)==0x40)&&(type[14]==0x05)&&(dirc[14]==0x03))
            {
              QLabel_list[14]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
            }
            if(((parm8&0x40)==0x40)&&(type[14]==0x05)&&(dirc[14]==0x04))
            {
              QLabel_list[14]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
            }
            if(((parm8&0x40)==0x40)&&(type[14]==0x06)&&(dirc[14]==0x01))
            {
              QLabel_list[14]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G3.png);"));
            }
            if(((parm8&0x40)==0x40)&&(type[14]==0x06)&&(dirc[14]==0x02))
            {
              QLabel_list[14]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G1.png);"));
            }
            if(((parm8&0x40)==0x40)&&(type[14]==0x06)&&(dirc[14]==0x03))
            {
              QLabel_list[14]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G4.png);"));
            }
            if(((parm8&0x40)==0x40)&&(type[14]==0x06)&&(dirc[14]==0x04))
            {
              QLabel_list[14]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G2.png);"));
            }
            if(((parm8&0x40)==0x40)&&(type[14]==0x07)&&(dirc[14]==0x01))
            {
              QLabel_list[14]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G2.png);"));
            }
            if(((parm8&0x40)==0x40)&&(type[14]==0x07)&&(dirc[14]==0x02))
            {
              QLabel_list[14]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G3.png);"));
            }
            if(((parm8&0x40)==0x40)&&(type[14]==0x07)&&(dirc[14]==0x03))
            {
              QLabel_list[14]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G1.png);"));
            }
            if(((parm8&0x40)==0x40)&&(type[14]==0x07)&&(dirc[14]==0x04))
            {
              QLabel_list[14]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G4.png);"));
            }
            if(((parm8&0x40)==0x40)&&(type[14]==0x08)&&(dirc[14]==0x01))
            {
              QLabel_list[14]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G1.png);"));
            }
            if(((parm8&0x40)==0x40)&&(type[14]==0x08)&&(dirc[14]==0x02))
            {
              QLabel_list[14]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G4.png);"));
            }
            if(((parm8&0x40)==0x40)&&(type[14]==0x08)&&(dirc[14]==0x03))
            {
              QLabel_list[14]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G2.png);"));
            }
            if(((parm8&0x40)==0x40)&&(type[14]==0x08)&&(dirc[14]==0x04))
            {
              QLabel_list[14]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G3.png);"));
            }
            if(((parm8&0x40)==0x40)&&(type[14]==0x09)&&(dirc[14]==0x01))
            {
              QLabel_list[14]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/GG.png);"));
            }
            if(((parm8&0x40)==0x40)&&(type[14]==0x09)&&(dirc[14]==0x02))
            {
              QLabel_list[14]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/GG.png);"));
            }
            if(((parm8&0x40)==0x40)&&(type[14]==0x09)&&(dirc[14]==0x03))
            {
              QLabel_list[14]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/GG.png);"));
            }
            if(((parm8&0x40)==0x40)&&(type[14]==0x09)&&(dirc[14]==0x04))
            {
              QLabel_list[14]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/GG.png);"));
            }


            if(((parm8&0x80)==0x80)&&(type[15]==0x03)&&(dirc[15]==0x01))
            {
              QLabel_list[15]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
            }
            if(((parm8&0x80)==0x80)&&(type[15]==0x03)&&(dirc[15]==0x02))
            {
              QLabel_list[15]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
            }
            if(((parm8&0x80)==0x80)&&(type[15]==0x03)&&(dirc[15]==0x03))
            {
              QLabel_list[15]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
            }
            if(((parm8&0x80)==0x80)&&(type[15]==0x03)&&(dirc[15]==0x04))
            {
              QLabel_list[15]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
            }
            if(((parm8&0x80)==0x80)&&(type[15]==0x05)&&(dirc[15]==0x01))
            {
              QLabel_list[15]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
            }
            if(((parm8&0x80)==0x80)&&(type[15]==0x05)&&(dirc[15]==0x02))
            {
              QLabel_list[15]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
            }
            if(((parm8&0x80)==0x80)&&(type[15]==0x05)&&(dirc[15]==0x03))
            {
              QLabel_list[15]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
            }
            if(((parm8&0x80)==0x80)&&(type[15]==0x05)&&(dirc[15]==0x04))
            {
              QLabel_list[15]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
            }
            if(((parm8&0x80)==0x80)&&(type[15]==0x06)&&(dirc[15]==0x01))
            {
              QLabel_list[15]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G3.png);"));
            }
            if(((parm8&0x80)==0x80)&&(type[15]==0x06)&&(dirc[15]==0x02))
            {
              QLabel_list[15]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G1.png);"));
            }
            if(((parm8&0x80)==0x80)&&(type[15]==0x06)&&(dirc[15]==0x03))
            {
              QLabel_list[15]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G4.png);"));
            }
            if(((parm8&0x80)==0x80)&&(type[15]==0x06)&&(dirc[15]==0x04))
            {
              QLabel_list[15]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G2.png);"));
            }
            if(((parm8&0x80)==0x80)&&(type[15]==0x07)&&(dirc[15]==0x01))
            {
              QLabel_list[15]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G2.png);"));
            }
            if(((parm8&0x80)==0x80)&&(type[15]==0x07)&&(dirc[15]==0x02))
            {
              QLabel_list[15]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G3.png);"));
            }
            if(((parm8&0x80)==0x80)&&(type[15]==0x07)&&(dirc[15]==0x03))
            {
              QLabel_list[15]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G1.png);"));
            }
            if(((parm8&0x80)==0x80)&&(type[15]==0x07)&&(dirc[15]==0x04))
            {
              QLabel_list[15]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G4.png);"));
            }
            if(((parm8&0x80)==0x80)&&(type[15]==0x08)&&(dirc[15]==0x01))
            {
              QLabel_list[15]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G1.png);"));
            }
            if(((parm8&0x80)==0x80)&&(type[15]==0x08)&&(dirc[15]==0x02))
            {
              QLabel_list[15]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G4.png);"));
            }
            if(((parm8&0x80)==0x80)&&(type[15]==0x08)&&(dirc[15]==0x03))
            {
              QLabel_list[15]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G2.png);"));
            }
            if(((parm8&0x80)==0x80)&&(type[15]==0x08)&&(dirc[15]==0x04))
            {
              QLabel_list[15]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G3.png);"));
            }
            if(((parm8&0x80)==0x80)&&(type[15]==0x09)&&(dirc[15]==0x01))
            {
              QLabel_list[15]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/GG.png);"));
            }
            if(((parm8&0x80)==0x80)&&(type[15]==0x09)&&(dirc[15]==0x02))
            {
              QLabel_list[15]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/GG.png);"));
            }
            if(((parm8&0x80)==0x80)&&(type[15]==0x09)&&(dirc[15]==0x03))
            {
              QLabel_list[15]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/GG.png);"));
            }
            if(((parm8&0x80)==0x80)&&(type[15]==0x09)&&(dirc[15]==0x04))
            {
              QLabel_list[15]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/GG.png);"));
            }

        }

        {
//      if((parm6&0x01)==0x01)
//       QLabel_list[8]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
//      if((parm6&0x02)==0x02)
//       QLabel_list[9]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
//      if((parm6&0x04)==0x04)
//       QLabel_list[10]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
//      if((parm6&0x08)==0x08)
//        QLabel_list[11]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
//      if((parm6&0x10)==0x10)
//        QLabel_list[12]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
//      if((parm6&0x20)==0x20)
//       QLabel_list[13]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
//      if((parm6&0x40)==0x40)
//       QLabel_list[14]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
//      if((parm6&0x80)==0x80)
//       QLabel_list[15]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/R.png);"));
//      /////////////////////////////////////////////////////////////////////////////////////////////
//      if((parm7&0x01)==0x01)
//       QLabel_list[8]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
//      if((parm7&0x02)==0x02)
//       QLabel_list[9]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
//      if((parm7&0x04)==0x04)
//       QLabel_list[10]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
//      if((parm7&0x08)==0x08)
//        QLabel_list[11]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
//      if((parm7&0x10)==0x10)
//       QLabel_list[12]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
//      if((parm7&0x20)==0x20)
//      QLabel_list[13]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
//      if((parm7&0x40)==0x40)
//       QLabel_list[14]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
//      if((parm7&0x80)==0x80)
//       QLabel_list[15]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/Y.png);"));
//      //////////////////////////////////////////////////////////////////////////////////////////
//      if((parm8&0x01)==0x01)
//       QLabel_list[8]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
//      if((parm8&0x02)==0x02)
//       QLabel_list[9]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
//      if((parm8&0x04)==0x04)
//       QLabel_list[10]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
//      if((parm8&0x08)==0x08)
//       QLabel_list[11]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
//      if((parm8&0x10)==0x10)
//       QLabel_list[12]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
//      if((parm8&0x20)==0x20)
//       QLabel_list[13]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
//      if((parm8&0x40)==0x40)
//       QLabel_list[14]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
//      if((parm8&0x80)==0x80)
//       QLabel_list[15]->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/G.png);"));
        }
    }

}
void DlgStatus::sendallb0()
{
        char buffer[60];
        buffer[0]=0x02;
        buffer[1]=0x00;
        buffer[2]=0x04;
        buffer[3]=0x80;
        buffer[4]=0xb0;
        buffer[5]=0x00;
        buffer[6]=0x00;
        int len=7;
        unsigned short rssum = CommVerify((unsigned char *)buffer,len);
        buffer[len]=rssum/256;
        buffer[len+1]=rssum%256;
        int i=0;
        for(i;i<3;i++)
        {
                if(com->WriteCom(buffer,len+2))
                {
                        break;
                }

        }
    }

void DlgStatus::sendd1()
{
    char buffer[60];
    buffer[0]=0x02;
    buffer[1]=0x00;
    buffer[2]=0x04;
    buffer[3]=0x81;
    buffer[4]=0xd1;
    buffer[5]=0x00;
    buffer[6]=0xaa;
    int len=7;
    unsigned short rssum=CommVerify((unsigned char *)buffer,len);
    buffer[len]=rssum/256;
    buffer[len+1]=rssum%256;
    this->com->WriteCom(buffer,len+2);
}


void DlgStatus::setd1()
{
    char buffer[60];
    buffer[0]=0x02;
    buffer[1]=0x00;
    buffer[2]=0x04;
    buffer[3]=0x81;
    buffer[4]=0xd1;
    buffer[5]=0x00;
    buffer[6]=0x00;
    int len=7;
    unsigned short rssum=CommVerify((unsigned char *)buffer,len);
    buffer[len]=rssum/256;
    buffer[len+1]=rssum%256;
    this->com->WriteCom(buffer,len+2);
}


void DlgStatus::sendb1()
{
    char buffer[60];
    buffer[0]=0x02;
    buffer[1]=0x00;
    buffer[2]=0x04;
    buffer[3]=0x80;
    buffer[4]=0xb1;
    buffer[5]=0x00;
    buffer[6]=0x00;
    int len=7;
    unsigned short rssum=CommVerify((unsigned char *)buffer,len);
    buffer[len]=rssum/256;
    buffer[len+1]=rssum%256;
    this->com->WriteCom(buffer,len+2);
}

void DlgStatus::on_butinit_clicked()
{
//    QList<QLabel *> QLabel_list;
//    QLabel_list <<ui->label<<ui->label_2;
//    for(int i=0;i<2;i++)
//    {

//    }
    //ui->display->setText(tr("设计!!!"));//clear();
    QLabel_list<<ui->bull<<ui->bull<<ui->bull<<ui->bull<<ui->bull
               <<ui->bull<<ui->bull<<ui->bull<<ui->bull
                  <<ui->bull<<ui->bull<<ui->bull<<ui->bull
                  <<ui->bull<<ui->bull<<ui->bull;
    type<<0x00<<0x00<<0x00<<0x00<<0x00<<0x00<<0x00<<0x00<<0x00<<0x00<<0x00<<0x00<<0x00<<0x00<<0x00<<0x00;
    dirc<<0x00<<0x00<<0x00<<0x00<<0x00<<0x00<<0x00<<0x00<<0x00<<0x00<<0x00<<0x00<<0x00<<0x00<<0x00<<0x00;
    QTimer::singleShot(1,this,SLOT(sendallb0()));
    revtimer->start(300);
    connect(revtimer,SIGNAL(timeout()),this,SLOT(rev()));
}

void DlgStatus::on_pushButton_clicked()
{

}

void DlgStatus::on_butquit_clicked()
{
    QTimer::singleShot(1,this,SLOT(setd1()));
    revtimer->start(20);
    QTimer::singleShot(2000,this,SLOT(close()));
}

void DlgStatus::on_butfind_clicked()
{
    ui->display->setText(tr("查询中......"));
    QTimer::singleShot(1,this,SLOT(sendb1()));
    revtimer->start(100);
    connect(revtimer,SIGNAL(timeout()),this,SLOT(rev()));
}


