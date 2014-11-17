#include "dlgtimeplan.h"
#include "ui_dlgtimeplan.h"
#include "unit.h"
#include <QDebug>
DlgTimePlan::DlgTimePlan(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DlgTimePlan)
{
    ui->setupUi(this);
    this->com=new CPubSub();
    this->revtimer=new QTimer();
    this->timeout=new QTimer();
    connect(timeout,SIGNAL(timeout()),this,SLOT(warming()));
}

DlgTimePlan::~DlgTimePlan()
{
    delete ui;
    deleteLater();
}

//void DlgTimePlan::setcom(CPubSub *com)
//{
//    this->com=com;
//}
//void DlgTimePlan::dealwith(uchar* rec,int len)
//{
//    uchar* s =rec;
//    for(int i=0; i<len; i++)
//    {
//        if((*s) != 0x02)
//        {
//            s++;
//            continue;
//        }
//        uchar* s2 = s;
//        unsigned short hight=(*(s2+1))<<8;
//        unsigned short low=*(s2+2);
//        unsigned short num=hight+low;
//        if(i+(num+5)>len)
//            return;

//        unsigned short crchight=(*(s2+(num+3)))<<8;
//        unsigned short crclow=(*(s2+(num+4)));
//        unsigned short crcnum=crchight+crclow;

//        char buffer[]={0x02,0x00,0x05 ,0x84 ,0x83 ,0x00 ,0x00 ,0x00};
//        unsigned short wewewew=CommVerify((uchar*)buffer,8);
//        if(crcnum!=CommVerify((uchar*)s,num+3))
//        {
//            s++;
//            qDebug()<<"chucuo!!!!!jiaoyan!!!";
//            continue;
//        }
//        if((uchar)*(s+3)==0x84)//查询命令处理
//        {
//            if((uchar)(*(s+4))==0xc0)
//            {
//                initc0((uchar*)s);
//                ui->display->setText(tr("查询成功!"));
//                timeout->stop();
//            }
//            qDebug()<<"###########";
//            if((uchar)(*(s+4))==0x79)
//            {
//                ui->hang->setText(QString::number(*(s+6),10));
//                ui->display->setText(tr("查询成功!"));
//                timeout->stop();
//            }
//        }
//        if((uchar)*(s+3)==0x85)//设置成功命令
//        {
//            if((uchar)(*(s+4))==0xc0)
//            {
//                ui->display->setText(tr("设置成功!"));
//                timeout->stop();
//            }
//            if((uchar)(*(s+4))==0x79)
//            {
//                ui->display->setText(tr("设置成功!"));
//                timeout->stop();
//            }
//        }
//        if((uchar)*(s+3)==0x86)//设置错误命令
//        s +=(num+5);
//        i += (num+4);
//    }
//}
//void DlgTimePlan::initc0(uchar *buffer)
//{
//    unsigned char parm1=*(buffer+7);
//    unsigned char parm2=*(buffer+8);
//    unsigned char parm3=*(buffer+9);
//    unsigned char parm4=*(buffer+10);
//    unsigned char parm5=*(buffer+11);
//    ui->spinplannum->setValue(parm1);
//    if((parm2==0xff)&(parm3==0xff)&(parm4==0xff)&(parm5==0xff))
//    {
//        ui->spintimelong->clear();
//        ui->spinphasecha->clear();
//        ui->spinxietiao->clear();
//        ui->spineverytabnum->clear();
//    }else{
//        ui->spintimelong->setValue(parm2);
//        ui->spinphasecha->setValue(parm3);
//        ui->spinxietiao->setValue(parm4);
//        ui->spineverytabnum->setValue(parm5);
//    }
//}
//void DlgTimePlan::rev()
//{
//    char RecBuf[4096];
//    memset(RecBuf,NULL,4096);
//    QString RecText;
//    int Rlen;
//    if(com->isopen())
//    {
//            Rlen=com->GetDataLen();
//            if(Rlen>0)
//            {
//                com->ReadCom(RecBuf,Rlen);
//                for(int i=0;i<Rlen;i++)
//                {

//                        RecText.append(QString::number((uchar)RecBuf[i],16));
//                        RecText.append("|");
//                }
//            }
//            dealwith((uchar*)RecBuf,Rlen);
//    }
//}
//void DlgTimePlan::warming()
//{
//    ui->display->clear();
//    ui->display->setText(tr("失败!请重试!"));
//}
//void DlgTimePlan::sendc0()
//{
//    unsigned char value=(unsigned char)ui->spinplannum->value();
//    char buffer[60];
//    buffer[0]=0x02;
//    buffer[1]=0x00;
//    buffer[2]=0x04;
//    buffer[3]=0x80;
//    buffer[4]=0xc0;
//    buffer[5]=0x40;
//    buffer[6]=value;
//    int len=7;
//    unsigned short rssum=CommVerify((unsigned char *)buffer,len);
//    buffer[len]=rssum/256;
//    buffer[len+1]=rssum%256;
//    com->WriteCom(buffer,len+2);
//}
//void DlgTimePlan::setc0()
//{
//    char buffer[50];
//    buffer[0]=0x02;
//    buffer[1]=0x00;
//    buffer[2]=0x09;
//    buffer[3]=0x81;
//    buffer[4]=0xc0;
//    buffer[5]=0x40;
//    buffer[6]=(unsigned char)(ui->spinplannum->value());
//    buffer[7]=(unsigned char)(ui->spinplannum->value());
//    buffer[8]=(unsigned char)(ui->spintimelong->value());
//    buffer[9]=(unsigned char)(ui->spinphasecha->value());
//    buffer[10]=(unsigned char)(ui->spinxietiao->value());;
//    buffer[11]=(unsigned char)(ui->spineverytabnum->value());;
//    int len=12;
//    unsigned short rssum = CommVerify((unsigned char *)buffer,len);
//    buffer[len]=rssum/256;
//    buffer[len+1]=rssum%256;
//    com->WriteCom(buffer,len+2);
//}

//void DlgTimePlan::on_butfind_clicked()
//{
//    ui->display->clear();
//    ui->spineverytabnum->clear();
//    ui->spinphasecha->clear();
//    ui->spintimelong->clear();
//    ui->spinxietiao->clear();
//    QTimer::singleShot(1,this,SLOT(sendc0()));
//    revtimer->start(20);
//    connect(revtimer,SIGNAL(timeout()),this,SLOT(rev()));
//}

//void DlgTimePlan::on_butset_clicked()
//{

//}

//void DlgTimePlan::on_butclear_clicked()
//{

//}

//void DlgTimePlan::on_butquery_clicked()
//{

//}

//void DlgTimePlan::on_butclearall_clicked()
//{

//}
