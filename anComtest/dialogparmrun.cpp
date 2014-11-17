#include "dialogparmrun.h"
#include "ui_dialogparmrun.h"
#include "unit.h"
#include <QDebug>
DialogParmRun::DialogParmRun(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogParmRun)
{
    ui->setupUi(this);
    this->com=new CPubSub();
    this->revtimer=new QTimer();
    this->timeout=new QTimer();
    connect(timeout,SIGNAL(timeout()),this,SLOT(warming()));
    ui->radionull->setChecked(true);
}

DialogParmRun::~DialogParmRun()
{
    delete ui;
    deleteLater();
}
void DialogParmRun::setcom(CPubSub *com)
{
    this->com=com;
}
void DialogParmRun::dealwith(uchar* rec,int len)
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
            if((uchar)(*(s+4))==0xc2)
            {
                initc2((uchar*)s);
                ui->display->setText(tr("查询成功!"));
                timeout->stop();
            }
        }
        if((uchar)*(s+3)==0x85)//设置成功命令
        {
            if((uchar)(*(s+4))==0xc2)
            {
                ui->display->setText(tr("设置成功!"));
                timeout->stop();
            }
        }
        if((uchar)*(s+3)==0x86)//设置错误命令
        {
            if((uchar)(*(s+4))==0xc2)
            {
                ui->display->setText(tr("设置失败!"));
                timeout->stop();
            }
        }
        s +=(num+5);
        i += (num+4);
    }
}
void DialogParmRun::initc2(uchar *buffer)
{
    unsigned char parm1=(unsigned char)buffer[6];
    if(parm1=0xff)
        ui->radionull->setChecked(true);
    if(parm1=0xaa)
        ui->radionorun->setChecked(true);

    if(parm1=0x00)
        ui->radiorun->setChecked(true);

}
void DialogParmRun::rev()
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
void DialogParmRun::warming()
{
    ui->display->clear();
    ui->display->setText(tr("失败!请重试!"));
}
void DialogParmRun::sendc2()
{
    char buffer[60];
    buffer[0]=0x02;
    buffer[1]=0x00;
    buffer[2]=0x03;
    buffer[3]=0x80;
    buffer[4]=0xc2;
    buffer[5]=0x00;
    int len=6;
    unsigned short rssum=CommVerify((unsigned char *)buffer,len);
    buffer[len]=rssum/256;
    buffer[len+1]=rssum%256;
    this->com->WriteCom(buffer,len+2);
}
void DialogParmRun::setc2()
{
    unsigned char parm1=0xff;
    if(ui->radiorun->isChecked())
        parm1=0xaa;
    if(ui->radionorun->isChecked())
        parm1=0x00;
    if(ui->radionull->isChecked())
        parm1=0x00;

    char buffer[60];
    buffer[0]=0x02;
    buffer[1]=0x00;
    buffer[2]=0x04;
    buffer[3]=0x81;
    buffer[4]=0xc2;
    buffer[5]=0x00;
    buffer[6]=parm1;
    int len=7;
    unsigned short rssum=CommVerify((unsigned char *)buffer,len);
    buffer[len]=rssum/256;
    buffer[len+1]=rssum%256;
    com->WriteCom(buffer,len+2);
}

void DialogParmRun::on_butfind_clicked()
{
    ui->display->setText(tr("查询中......"));
    ui->radionull->setChecked(true);
    QTimer::singleShot(1,this,SLOT(sendc2()));
    revtimer->start(200);
    connect(revtimer,SIGNAL(timeout()),this,SLOT(rev()));
    timeout->start(3000);
}

void DialogParmRun::on_butok_clicked()
{
    ui->display->setText(tr("设置中......"));
    QTimer::singleShot(1,this,SLOT(setc2()));
    revtimer->start(50);
    connect(revtimer,SIGNAL(timeout()),this,SLOT(rev()));
    timeout->start(3000);
}
