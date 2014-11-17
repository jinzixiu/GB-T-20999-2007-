#include "dialogchanneltab.h"
#include "ui_dialogchanneltab.h"
#include "unit.h"
#include <QDebug>
DialogChanneltab::DialogChanneltab(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogChanneltab)
{
    ui->setupUi(this);
    this->com=new CPubSub();
    this->revtimer=new QTimer();
    this->timeout=new QTimer();
    connect(timeout,SIGNAL(timeout()),this,SLOT(warming()));
}

DialogChanneltab::~DialogChanneltab()
{
    delete ui;
    deleteLater();
}
void DialogChanneltab::setcom(CPubSub *com)
{
    this->com=com;
}

void DialogChanneltab::rev()
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
void DialogChanneltab::dealwith(uchar* rec,int len)
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
            if((uchar)(*(s+4))==0xb0)
            {
                initb0((uchar*)s);
                ui->display->setText(tr("查询成功!"));
                timeout->stop();
            }
            qDebug()<<"###########";
            if((uchar)(*(s+4))==0x79)
            {
                ui->hang->setText(QString::number(*(s+6),10));
                ui->display->setText(tr("查询成功!"));
                timeout->stop();
            }
        }
        if((uchar)*(s+3)==0x85)//设置成功命令
        {
            if((uchar)(*(s+4))==0xb0)
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
            if((uchar)(*(s+4))==0xb0)
            {
                ui->display->setText(tr("设置失败!"));
                timeout->stop();
            }
            if((uchar)(*(s+4))==0x79)
            {
                ui->display->setText(tr("清空失败!"));
                timeout->stop();
            }
        }
        s +=(num+5);
        i += (num+4);
    }
}
void DialogChanneltab::sendb0()
{
    char index=ui->spinChannelNum->value();
    char buffer[60];
    buffer[0]=0x02;
    buffer[1]=0x00;
    buffer[2]=0x04;
    buffer[3]=0x80;
    buffer[4]=0xb0;
    buffer[5]=0x40;
    buffer[6]=index;
    int len=7;
    unsigned short rssum=CommVerify((unsigned char *)buffer,len);
    buffer[len]=rssum/256;
    buffer[len+1]=rssum%256;
    this->com->WriteCom(buffer,len+2);
}
void DialogChanneltab::initb0(uchar *buffer)
{
    unsigned char parm1=(unsigned char)buffer[7];
    unsigned char parm2=(unsigned char)buffer[8];
    unsigned char parm3=(unsigned char)buffer[9];
    unsigned char parm4=(unsigned char)buffer[10];
    ui->spinChannelNum->setValue(parm1);
    if(parm2!=0xff)
    {
      ui->ChannelSignSour->setText(QString::number(parm2,10));
    }
    else
    {
      ui->ChannelSignSour->clear();
    }
    if(parm3!=0xff)
     {
            if((parm3&0x02)==0x02)
            {
               ui->checkBox->setChecked(true);
            }
            if((parm3&0x04)==0x04)
            {
               ui->checkBox_2->setChecked(true);
            }
            if((parm3&0x08)==0x08)
            {
              ui->checkBox_3->setChecked(true);
            }
     }
    else
    {
         ui->checkBox->setChecked(false);
         ui->checkBox_2->setChecked(false);
         ui->checkBox_3->setChecked(false);
    }
    if(parm4!=0xff)
    {
        uchar highparm=parm4>>4;
        uchar lowparm=parm4&0x0f;
        if(highparm==0x01)
            ui->dir1->setChecked(true);
        if(highparm==0x02)
            ui->dir2->setChecked(true);
        if(highparm==0x03)
            ui->dir3->setChecked(true);
        if(highparm==0x04)
            ui->dir4->setChecked(true);
        if(highparm==0x05)
            ui->dir5->setChecked(true);
        if(highparm==0x06)
            ui->dir6->setChecked(true);
        if(highparm==0x07)
            ui->dir7->setChecked(true);
        if(highparm==0x08)
            ui->dir8->setChecked(true);

        if(lowparm==0x01)
            ui->flash1->setChecked(true);
        if(lowparm==0x03)
            ui->flash3->setChecked(true);
        if(lowparm==0x04)
            ui->flash4->setChecked(true);
        if(lowparm==0x05)
            ui->flash5->setChecked(true);
        if(lowparm==0x06)
            ui->flash6->setChecked(true);
        if(lowparm==0x07)
            ui->flash7->setChecked(true);
        if(lowparm==0x08)
            ui->flash8->setChecked(true);
        if(lowparm==0x09)
            ui->flash9->setChecked(true);
    }
}
void DialogChanneltab::setb0()
{
    unsigned char parm1=(unsigned char)(ui->spinChannelNum->value());
    unsigned char parm2=(unsigned char)(ui->ChannelSignSour->text().toInt());
    unsigned char parm3=0x00;
    if(ui->checkBox->isChecked()|ui->checkBox_2->isChecked()|ui->checkBox_3->isChecked())
    {
        if(ui->checkBox->isChecked())
            parm3=parm3|0x02;
        if(ui->checkBox_2->isChecked())
            parm3=parm3|0x04;
        if(ui->checkBox_3->isChecked())
            parm3=parm3|0x08;
    }
    else
    {
        parm3=0xff;
    }
    char parm4=0x00;
    {
        uchar highparm;
        uchar lowparm;
        if(ui->dir1->isChecked())
            highparm=0x01;
        if(ui->dir2->isChecked())
            highparm=0x02;
        if(ui->dir3->isChecked())
            highparm=0x03;
        if(ui->dir4->isChecked())
            highparm=0x04;
        if(ui->dir5->isChecked())
            highparm=0x05;
        if(ui->dir6->isChecked())
            highparm=0x06;
        if(ui->dir7->isChecked())
            highparm=0x07;
        if(ui->dir8->isChecked())
            highparm=0x08;

        if(ui->NULL1->isChecked())
            highparm=0x0F;

        if(ui->flash1->isChecked())
            lowparm=0x01;
        if(ui->flash3->isChecked())
            lowparm=0x03;
        if(ui->flash4->isChecked())
            lowparm=0x04;
        if(ui->flash5->isChecked())
            lowparm=0x05;
        if(ui->flash6->isChecked())
            lowparm=0x06;
        if(ui->flash7->isChecked())
            lowparm=0x07;
        if(ui->flash8->isChecked())
            lowparm=0x08;
        if(ui->flash9->isChecked())
            lowparm=0x09;

        if(ui->NULL2->isChecked())
            lowparm=0x0F;
        highparm=highparm<<4;
        parm4=highparm+lowparm;
    }
    char buffer[60];
    buffer[0]=0x02;
    buffer[1]=0x00;
    buffer[2]=0x08;
    buffer[3]=0x81;
    buffer[4]=0xb0;
    buffer[5]=0x40;
    buffer[6]=parm1;
    buffer[7]=parm1;
    buffer[8]=parm2;
    buffer[9]=parm3;
    buffer[10]=parm4;
    int len=11;
    unsigned short rssum=CommVerify((unsigned char *)buffer,len);
    buffer[len]=rssum/256;
    buffer[len+1]=rssum%256;
    com->WriteCom(buffer,len+2);
}

void DialogChanneltab::warming()
{
    ui->display->clear();
    ui->display->setText(tr("失败!请重试!"));
}

void DialogChanneltab::on_butfind_clicked()
{
    ui->display->setText(tr("查询中......"));
    ui->checkBox->setChecked(false);
    ui->checkBox_2->setChecked(false);
    ui->checkBox_3->setChecked(false);
    ui->NULL1->setChecked(true);
    ui->NULL2->setChecked(true);
    QTimer::singleShot(1,this,SLOT(sendb0()));
    revtimer->start(200);
    connect(revtimer,SIGNAL(timeout()),this,SLOT(rev()));
    timeout->start(5000);
}

void DialogChanneltab::on_butok_clicked()
{
    ui->display->clear();
    QTimer::singleShot(1,this,SLOT(setb0()));
    timeout->start(1000);
}

void DialogChanneltab::on_butcleaer_clicked()
{
    ui->display->clear();
    unsigned char parm1=(unsigned char)(ui->spinChannelNum->value());
    char buffer[60];
    buffer[0]=0x02;
    buffer[1]=0x00;
    buffer[2]=0x08;
    buffer[3]=0x81;
    buffer[4]=0xb0;
    buffer[5]=0x40;
    buffer[6]=parm1;
    buffer[7]=parm1;
    buffer[8]=0xff;
    buffer[9]=0xff;
    buffer[10]=0xff;
    int len=11;
    unsigned short rssum=CommVerify((unsigned char *)buffer,len);
    buffer[len]=rssum/256;
    buffer[len+1]=rssum%256;
    com->WriteCom(buffer,len+2);
    timeout->start(1000);
}

void DialogChanneltab::on_butquery_clicked()
{
    char buffer[60];
    buffer[0]=0x02;
    buffer[1]=0x00;
    buffer[2]=0x04;
    buffer[3]=0x80;
    buffer[4]=0x79;
    buffer[5]=0x00;
    buffer[6]=0xb0;
    int len=7;
    unsigned short rssum=CommVerify((unsigned char *)buffer,len);
    buffer[len]=rssum/256;
    buffer[len+1]=rssum%256;
    this->com->WriteCom(buffer,len+2);
    revtimer->start(20);
    connect(revtimer,SIGNAL(timeout()),this,SLOT(rev()));
    timeout->start(1000);
}

void DialogChanneltab::on_butclearall_clicked()
{
    char buffer[60];
    buffer[0]=0x02;
    buffer[1]=0x00;
    buffer[2]=0x04;
    buffer[3]=0x81;
    buffer[4]=0x79;
    buffer[5]=0x00;
    buffer[6]=0xb0;
    int len=7;
    unsigned short rssum=CommVerify((unsigned char *)buffer,len);
    buffer[len]=rssum/256;
    buffer[len+1]=rssum%256;
    this->com->WriteCom(buffer,len+2);
}
