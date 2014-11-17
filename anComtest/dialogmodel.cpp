#include "dialogmodel.h"
#include "ui_dialogmodel.h"
#include "unit.h"
#include <QDebug>
DialogModel::DialogModel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogModel)
{
    ui->setupUi(this);
    this->com =new CPubSub();
    this->revtimer=new QTimer();
    this->timeout=new QTimer();
    connect(timeout,SIGNAL(timeout()),this,SLOT(warming()));
    connect(revtimer,SIGNAL(timeout()),this,SLOT(rev()));
}

DialogModel::~DialogModel()
{
    delete ui;
    deleteLater();
}


void DialogModel::setcom(CPubSub *com)
{
    this->com=com;
}
void DialogModel::dealwith(uchar* rec,int len)
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
           if((uchar)(*(s+4))==0x85)
           {
               init85((uchar*)s);
               ui->display->setText(tr("查询成功!"));
               timeout->stop();
           }
       }
       s +=(num+5);
       i += (num+4);
    }
}
void DialogModel::init85(uchar *buffer)
{
    char jiedian[40];
    char zhizaoshang[40];
    char xinghao[40];
    char banben[20];
    int i=0;
    for(i;i<40;i++)
    {
        jiedian[i]=((char)(*(buffer+(8+i))));
    }
    i=0;
    for(i;i<40;i++)
    {
        zhizaoshang[i]=((char)(*(buffer+(48+i))));
    }
    i=0;
    for(i;i<40;i++)
    {
        xinghao[i]=((char)(*(buffer+(88+i))));
    }
    i=0;
    for(i;i<20;i++)
    {
        banben[i]=((char)(*(buffer+(128+i))));
    }
    QString str1;
    QString str2;
    QString str3;
    QString str4;

    ui->jiedian->setText(str1.fromLocal8Bit(jiedian));
    ui->zhizaoshang->setText(str2.fromLocal8Bit(zhizaoshang));
    ui->xinghao->setText(str3.fromLocal8Bit(xinghao));
    ui->banben->setText(str4.fromLocal8Bit(banben));

}

void DialogModel::rev()
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
void DialogModel::warming()
{
    ui->display->clear();
    ui->display->setText(tr("失败!请重试!"));
}

void DialogModel::send85()
{
    char buffer[60];
    buffer[0]=0x02;
    buffer[1]=0x00;
    buffer[2]=0x04;
    buffer[3]=0x80;
    buffer[4]=0x85;
    buffer[5]=0x40;
    buffer[6]=0x01;
    int len=7;
    unsigned short rssum=CommVerify((unsigned char *)buffer,len);
    buffer[len]=rssum/256;
    buffer[len+1]=rssum%256;
    this->com->WriteCom(buffer,len+2);
}

void DialogModel::on_butfind1_clicked()
{
    ui->display->clear();
    ui->display->setText(tr("查询中......"));
    char buffer[60];
    buffer[0]=0x02;
    buffer[1]=0x00;
    buffer[2]=0x04;
    buffer[3]=0x80;
    buffer[4]=0x85;
    buffer[5]=0x40;
    buffer[6]=0x01;
    int len=7;
    unsigned short rssum=CommVerify((unsigned char *)buffer,len);
    buffer[len]=rssum/256;
    buffer[len+1]=rssum%256;
    this->com->WriteCom(buffer,len+2);
//////////////////////////////////////////////////
    revtimer->start(100);
    timeout->start(3000);
}
void DialogModel::on_butfind1_2_clicked()
{
    ui->display->clear();
    ui->display->setText(tr("查询中......"));
    char buffer[60];
    buffer[0]=0x02;
    buffer[1]=0x00;
    buffer[2]=0x04;
    buffer[3]=0x80;
    buffer[4]=0x85;
    buffer[5]=0x40;
    buffer[6]=0x02;
    int len=7;
    unsigned short rssum=CommVerify((unsigned char *)buffer,len);
    buffer[len]=rssum/256;
    buffer[len+1]=rssum%256;
    this->com->WriteCom(buffer,len+2);
//////////////////////////////////////////////////
    revtimer->start(100);
    timeout->start(3000);
}
void DialogModel::on_butfind1_3_clicked()
{
    ui->display->clear();
    ui->display->setText(tr("查询中......"));
    char buffer[60];
    buffer[0]=0x02;
    buffer[1]=0x00;
    buffer[2]=0x04;
    buffer[3]=0x80;
    buffer[4]=0x85;
    buffer[5]=0x40;
    buffer[6]=0x03;
    int len=7;
    unsigned short rssum=CommVerify((unsigned char *)buffer,len);
    buffer[len]=rssum/256;
    buffer[len+1]=rssum%256;
    this->com->WriteCom(buffer,len+2);
    //////////////////////////////////////////////////
    revtimer->start(100);
    timeout->start(3000);
}
void DialogModel::on_butfind1_4_clicked()
{
    ui->display->clear();
    ui->display->setText(tr("查询中......"));
    char buffer[60];
    buffer[0]=0x02;
    buffer[1]=0x00;
    buffer[2]=0x04;
    buffer[3]=0x80;
    buffer[4]=0x85;
    buffer[5]=0x40;
    buffer[6]=0x04;
    int len=7;
    unsigned short rssum=CommVerify((unsigned char *)buffer,len);
    buffer[len]=rssum/256;
    buffer[len+1]=rssum%256;
    this->com->WriteCom(buffer,len+2);
//////////////////////////////////////////////////
    revtimer->start(100);
    timeout->start(3000);
}
