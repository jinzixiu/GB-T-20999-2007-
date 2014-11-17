#include "dialogcartest.h"
#include "ui_dialogcartest.h"
#include "unit.h"
#include <QDebug>
DialogCarTest::DialogCarTest(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogCarTest)
{
    ui->setupUi(this);
    this->com=new CPubSub();
    this->revtimer=new QTimer();
    this->timeout=new QTimer();
    connect(timeout,SIGNAL(timeout()),this,SLOT(warming()));
}

DialogCarTest::~DialogCarTest()
{
    delete ui;
    deleteLater();
}
void DialogCarTest::setcom(CPubSub *com)
{
    this->com=com;
}
void DialogCarTest::dealwith(uchar* rec,int len)
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
            if((uchar)(*(s+4))==0x9f)
            {
                init9f((uchar*)s);
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
            if((uchar)(*(s+4))==0x9f)
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
            if((uchar)(*(s+4))==0x9f)
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
void DialogCarTest::init9f(uchar *buffer)
{
    uchar parm1=buffer[8];
    uchar parm2=buffer[10];
    uchar parm3=buffer[9];
    if(parm1!=0xff)
    {
        ui->radionull->setChecked(true);
        if(parm1==0x01)
            ui->radioout->setChecked(true);
        if(parm1==0x00)
            ui->radioin->setChecked(true);
    }else
    {
        ui->radionull->setChecked(true);
    }

    if((parm2&0x01)==0x01)
        ui->bao->setChecked(true);
    if((parm2&0x02)==0x02)
        ui->bao_2->setChecked(true);
    if((parm2&0x04)==0x04)
        ui->bao_3->setChecked(true);
    if((parm2&0x08)==0x08)
        ui->bao_4->setChecked(true);
    if((parm2&0x10)==0x10)
        ui->bao_5->setChecked(true);
    if((parm2&0x20)==0x20)
        ui->bao_6->setChecked(true);
    if((parm2&0x40)==0x40)
        ui->bao_7->setChecked(true);
    if((parm2&0x80)==0x80)
        ui->bao_8->setChecked(true);


    if((parm3&0x01)==0x01)
        ui->bao_9->setChecked(true);
    if((parm3&0x02)==0x02)
        ui->bao_10->setChecked(true);
    if((parm3&0x04)==0x04)
        ui->bao_11->setChecked(true);
    if((parm3&0x08)==0x08)
        ui->bao_12->setChecked(true);
    if((parm3&0x10)==0x10)
        ui->bao_13->setChecked(true);
    if((parm3&0x20)==0x20)
        ui->bao_14->setChecked(true);
    if((parm3&0x40)==0x40)
        ui->bao_15->setChecked(true);
    if((parm3&0x80)==0x80)
        ui->bao_16->setChecked(true);

}
void DialogCarTest::rev()
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
void DialogCarTest::warming()
{
    ui->display->clear();
    ui->display->setText(tr("失败!请重试!"));
}
void DialogCarTest::send9f()
{
    char index=ui->spinBox->value();
    char buffer[60];
    buffer[0]=0x02;
    buffer[1]=0x00;
    buffer[2]=0x04;
    buffer[3]=0x80;
    buffer[4]=0x9f;
    buffer[5]=0x40;
    buffer[6]=index;
    int len=7;
    unsigned short rssum=CommVerify((unsigned char *)buffer,len);
    buffer[len]=rssum/256;
    buffer[len+1]=rssum%256;
    this->com->WriteCom(buffer,len+2);
}
void DialogCarTest::set9f()
{
    uchar parm1=0x00;
    uchar parm2=0x00;
    uchar parm3=0x00;
    if(ui->radioin->isChecked())
        parm1=0x00;
    if(ui->radioout->isChecked())
        parm1=0x01;
    if(ui->radionull->isChecked())
        parm1=0xff;

    if(ui->bao->isChecked())
        parm2=(parm2|0x01);
    if(ui->bao_2->isChecked())
        parm2=(parm2|0x02);
    if(ui->bao_3->isChecked())
        parm2=(parm2|0x04);
    if(ui->bao_4->isChecked())
        parm2=(parm2|0x08);
    if(ui->bao_5->isChecked())
        parm2=(parm2|0x10);
    if(ui->bao_6->isChecked())
        parm2=(parm2|0x20);
    if(ui->bao_7->isChecked())
        parm2=(parm2|0x40);
    if(ui->bao_8->isChecked())
        parm2=(parm2|0x80);


    if(ui->bao_9->isChecked())
        parm3=(parm3|0x01);
    if(ui->bao_10->isChecked())
        parm3=(parm3|0x02);
    if(ui->bao_11->isChecked())
        parm3=(parm3|0x04);
    if(ui->bao_12->isChecked())
        parm3=(parm3|0x08);
    if(ui->bao_13->isChecked())
        parm3=(parm3|0x10);
    if(ui->bao_14->isChecked())
        parm3=(parm3|0x20);
    if(ui->bao_15->isChecked())
        parm3=(parm3|0x40);
    if(ui->bao_16->isChecked())
        parm3=(parm3|0x80);

    uchar value=ui->spinBox->value();
    char buffer[60];
    buffer[0]=0x02;
    buffer[1]=0x00;
    buffer[2]=0x09;
    buffer[3]=0x81;
    buffer[4]=0x9f;
    buffer[5]=0x40;
    buffer[6]=value;
    buffer[7]=value;
    buffer[8]=parm1;
    buffer[9]=parm3;
    buffer[10]=parm2;
    buffer[11]=0xff;
    int len=12;
    unsigned short rssum=CommVerify((unsigned char *)buffer,len);
    buffer[len]=rssum/256;
    buffer[len+1]=rssum%256;
    this->com->WriteCom(buffer,len+2);
}

void DialogCarTest::on_butfind_clicked()
{
    ui->display->clear();
    ui->display->setText(tr("查询中......"));
    ui->radionull->setChecked(true);
    ui->bao->setChecked(false);
    ui->bao_2->setChecked(false);
    ui->bao_3->setChecked(false);
    ui->bao_4->setChecked(false);
    ui->bao_5->setChecked(false);
    ui->bao_6->setChecked(false);
    ui->bao_7->setChecked(false);
    ui->bao_8->setChecked(false);
    ui->bao_9->setChecked(false);
    ui->bao_10->setChecked(false);
    ui->bao_11->setChecked(false);
    ui->bao_12->setChecked(false);
    ui->bao_13->setChecked(false);
    ui->bao_14->setChecked(false);
    ui->bao_15->setChecked(false);
    ui->bao_16->setChecked(false);
    QTimer::singleShot(1,this,SLOT(send9f()));
    revtimer->start(80);
    connect(revtimer,SIGNAL(timeout()),this,SLOT(rev()));
    timeout->start(3000);
}

void DialogCarTest::on_butok_clicked()
{
    ui->display->setText(tr("设置中......"));
    QTimer::singleShot(1,this,SLOT(set9f()));
    revtimer->start(100);
    connect(revtimer,SIGNAL(timeout()),this,SLOT(rev()));
    timeout->start(3000);
}

void DialogCarTest::on_butok_2_clicked()
{
    ui->display->clear();
    uchar value=ui->spinBox->value();
    char buffer[60];
    buffer[0]=0x02;
    buffer[1]=0x00;
    buffer[2]=0x09;
    buffer[3]=0x81;
    buffer[4]=0x9f;
    buffer[5]=0x40;
    buffer[6]=value;
    buffer[7]=value;
    buffer[8]=0xff;
    buffer[9]=0xff;
    buffer[10]=0xff;
    buffer[11]=0xff;
    int len=12;
    unsigned short rssum=CommVerify((unsigned char *)buffer,len);
    buffer[len]=rssum/256;
    buffer[len+1]=rssum%256;
    this->com->WriteCom(buffer,len+2);
    revtimer->start(100);
    connect(revtimer,SIGNAL(timeout()),this,SLOT(rev()));
    timeout->start(3000);
}

void DialogCarTest::on_butquery_clicked()
{
    char buffer[60];
    buffer[0]=0x02;
    buffer[1]=0x00;
    buffer[2]=0x04;
    buffer[3]=0x80;
    buffer[4]=0x79;
    buffer[5]=0x00;
    buffer[6]=0x9f;
    int len=7;
    unsigned short rssum=CommVerify((unsigned char *)buffer,len);
    buffer[len]=rssum/256;
    buffer[len+1]=rssum%256;
    this->com->WriteCom(buffer,len+2);
    revtimer->start(20);
    connect(revtimer,SIGNAL(timeout()),this,SLOT(rev()));
    timeout->start(1000);
}

void DialogCarTest::on_butclearall_clicked()
{
    char buffer[60];
    buffer[0]=0x02;
    buffer[1]=0x00;
    buffer[2]=0x04;
    buffer[3]=0x81;
    buffer[4]=0x79;
    buffer[5]=0x00;
    buffer[6]=0x9f;
    int len=7;
    unsigned short rssum=CommVerify((unsigned char *)buffer,len);
    buffer[len]=rssum/256;
    buffer[len+1]=rssum%256;
    this->com->WriteCom(buffer,len+2);
    revtimer->start(20);
    connect(revtimer,SIGNAL(timeout()),this,SLOT(rev()));
    timeout->start(1000);
}
