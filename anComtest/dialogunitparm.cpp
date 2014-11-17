#include "dialogunitparm.h"
#include "ui_dialogunitparm.h"
#include "unit.h"
#include <QDebug>
static bool finda3=false;
static bool finda4=false;
static bool finda5=false;
static bool finda6=false;
static bool finda8=false;
static bool finda7=false;
static bool findab=false;
static bool findaa=false;
static bool finda9=false;

static bool succa3=false;
static bool succa4=false;
static bool succaa=false;
static bool succab=false;
DialogUnitParm::DialogUnitParm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogUnitParm)
{
    ui->setupUi(this);
    this->com=new CPubSub();
    this->revtimer=new QTimer();
    this->timeout=new QTimer();
    connect(timeout,SIGNAL(timeout()),this,SLOT(warming()));
}

DialogUnitParm::~DialogUnitParm()
{
    delete ui;
    deleteLater();
}
void DialogUnitParm::setcom(CPubSub *com)
{
    this->com=com;
}
void DialogUnitParm::dealwith(uchar* rec,int len)
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
            if((uchar)(*(s+4))==0xa3)
            {
                inita3((uchar*)s);
                //ui->display->setText(tr("查询成功!"));
                finda3=true;
                QTimer::singleShot(1,this,SLOT(senda4()));
            }
            if((uchar)(*(s+4))==0xa4)
            {
                inita4((uchar*)s);
                //ui->display->setText(tr("查询成功!"));
                finda4=true;
                QTimer::singleShot(1,this,SLOT(senda5()));
            }
            if((uchar)(*(s+4))==0xa5)
            {
                inita5((uchar*)s);
                //ui->display->setText(tr("查询成功!"));
                finda5=true;
                QTimer::singleShot(1,this,SLOT(senda6()));
            }
            if((uchar)(*(s+4))==0xa6)
            {
                inita6((uchar*)s);
                //ui->display->setText(tr("查询成功!"));
                finda6=true;
                QTimer::singleShot(1,this,SLOT(senda7()));
            }
            if((uchar)(*(s+4))==0xa7)
            {
                inita7((uchar*)s);
                //ui->display->setText(tr("查询成功!"));
                finda7=true;
                QTimer::singleShot(1,this,SLOT(senda8()));
            }
            if((uchar)(*(s+4))==0xa8)
            {
                inita8((uchar*)s);
                //ui->display->setText(tr("查询成功!"));
                finda8=true;
                QTimer::singleShot(1,this,SLOT(senda9()));
            }
            if((uchar)(*(s+4))==0xa9)
            {
                inita9((uchar*)s);
                //ui->display->setText(tr("查询成功!"));
                finda9=true;
                QTimer::singleShot(1,this,SLOT(sendaa()));
            }
            if((uchar)(*(s+4))==0xaa)
            {
                initaa((uchar*)s);
                //ui->display->setText(tr("查询成功!"));
                findaa=true;
                QTimer::singleShot(1,this,SLOT(sendab()));
            }
            if((uchar)(*(s+4))==0xab)
            {
                initab((uchar*)s);
                //ui->display->setText(tr("查询成功!"));
                findab=true;
            }
            if(finda3&finda4&finda5&finda6&finda7&finda8&finda9&findaa&findab)
            {
                ui->display->setText(tr("查询成功!"));
                timeout->stop();
            }
        }
        if((uchar)*(s+3)==0x85)//设置成功命令
        {
            if((uchar)(*(s+4))==0xa3)
            {
                succa3=true;
                QTimer::singleShot(1,this,SLOT(seta4()));
            }
            if((uchar)(*(s+4))==0xa4)
            {
                succa4=true;
                QTimer::singleShot(1,this,SLOT(setaa()));
            }
            if((uchar)(*(s+4))==0xaa)
            {
                succaa=true;
                QTimer::singleShot(1,this,SLOT(setab()));
            }
            if((uchar)(*(s+4))==0xab)
            {
                succab=true;
            }
            if(succa3&succa4&succaa&succab)
            {
                ui->display->setText(tr("设置成功!"));
                timeout->stop();
            }
        }
        if((uchar)*(s+3)==0x86)//设置错误命令
        {
            if((uchar)(*(s+4))==0xa3)
            {
                ui->display->setText(tr("闪光控制时间设置失败!"));
            }
            if((uchar)(*(s+4))==0xa4)
            {
                ui->display->setText(tr("全红控制时间设置失败!"));
            }
            if((uchar)(*(s+4))==0xaa)
            {
                ui->display->setText(tr("远程控制设置失败!"));
            }
            if((uchar)(*(s+4))==0xab)
            {
               ui->display->setText(tr("闪光控制时间设置失败!"));
            }
        }
        s +=(num+5);
        i += (num+4);
    }
}
void DialogUnitParm::rev()
{
    qDebug()<<"~~~~~~~~~~~~~~~~~~";
    char RecBuf[4096];
    memset(RecBuf,NULL,4096);
    QString RecText;
    int Rlen;
    if(com->isopen())
    {
        Rlen=com->GetDataLen();
        if((Rlen>0))//&((Rlen==9)|(Rlen==8))
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
void DialogUnitParm::warming()
{
    ui->display->clear();
    ui->display->setText(tr("失败!请重试!"));
}
void DialogUnitParm::inita3(uchar* buffer)
{
    unsigned char parm1=*(buffer+6);
            ui->spinFlashContrl->setValue((int)parm1);
}
void DialogUnitParm::inita4(uchar* buffer)
{
    unsigned char parm=*(buffer+6);
    ui->spinAllRedContrl->setValue((int)parm);
}
void DialogUnitParm::inita5(uchar* buffer)
{
    unsigned char parm=*(buffer+6);
    switch (parm){
    case 1:
        ui->signcontrlstate->setCurrentIndex(0);
        break;
    case 2:
        ui->signcontrlstate->setCurrentIndex(1);
        break;
    case 3:
        ui->signcontrlstate->setCurrentIndex(2);
        break;
    case 4:
        ui->signcontrlstate->setCurrentIndex(3);
        break;
    case 5:
        ui->signcontrlstate->setCurrentIndex(4);
        break;
    case 6:
        ui->signcontrlstate->setCurrentIndex(5);
        break;
     default:
        ui->signcontrlstate->setCurrentIndex(6);
    }
}
void DialogUnitParm::inita6(uchar* buffer)
{
    unsigned char parm=*(buffer+6);
    switch (parm){
    case 1:
        ui->flashcontrlstate->setCurrentIndex(0);
        break;
    case 2:
        ui->flashcontrlstate->setCurrentIndex(1);
        break;
    case 3:
        ui->flashcontrlstate->setCurrentIndex(2);
        break;
    case 4:
        ui->flashcontrlstate->setCurrentIndex(3);
        break;
    case 5:
        ui->flashcontrlstate->setCurrentIndex(4);
        break;
    case 6:
        ui->flashcontrlstate->setCurrentIndex(5);
        break;
    case 7:
        ui->flashcontrlstate->setCurrentIndex(6);
        break;
    default:
       ui->flashcontrlstate->setCurrentIndex(7);
    }
}
void DialogUnitParm::inita8(uchar* buffer)
{
    unsigned char parm=*(buffer+6);
    qDebug()<<"parm:"+QString::number(parm,16);
    QString strinform;
    QString str;
    if((parm&(0x10))==0x10)
    {
       str=str.fromLocal8Bit("MMU引起的闪光，并且长于Start-Up闪光时间");
       strinform.append(str);
       str="";

    }
    else if((parm&(0x20))==0x20)
    {
       str=str.fromLocal8Bit("本地闪光控制！");
       strinform.append(str);
       str="";
    }
    else if((parm&(0x40))==0x40)
    {
       str=str.fromLocal8Bit("本地单点控制！");
       strinform.append(str);
       str="";
    }
    else if((parm&(0x80))==0x80)
    {
       str=str.fromLocal8Bit("正处于协调控制状态！");
       strinform.append(&str);
       str="";
    }
    else if(((parm&(0x01))==0x01)|((parm&(0x02))==0x02)|((parm&(0x04))==0x04)|((parm&(0x08))==0x08))
    {
       str="reserved";
       strinform.append(str);
       //qDebug()<<"=====:"+QString::number(parm&&(0x20),16);
       str="";
    }
    else
    {
    strinform.append("null");
    }
    ui->Editsign1->setText(strinform);
}
void DialogUnitParm::inita7(uchar* buffer)
{
    unsigned char parm=*(buffer+6);
    qDebug()<<"parm:"+QString::number(parm,16);
    QString strinform;
    QString str;
    if((parm&(0x20))==0x20)
       {
          str=str.fromLocal8Bit("即将停止运行，停机计时器开始计时！！");
          strinform.append(str);
          str="";
          qDebug()<<"=====:"+QString::number(parm&&(0x20),16);
       }
    else if((parm&(0x02))==0x02)
      {
          str=str.fromLocal8Bit("电池不足！");
          strinform.append(str);
          str="";
      }
    else if((parm&(0x01))==0x01)
      {
          str=str.fromLocal8Bit("重启！");
          strinform.append(str);
          str="";
      }
    else if(((parm&(0x08))==0x08)|((parm&(0x10))==0x10)|((parm&(0x80))==0x80)|((parm&(0x40))==0x40))
      {
          str="reserved";
          strinform.append(str);
          str="";
      }
    else
    {
       strinform.append("null");
    }
    ui->Editsign2->setText(strinform);
}
void DialogUnitParm::initab(uchar* buffer)
{
    unsigned char parm=*(buffer+6);
    if((parm&0x01)==0x01)
    {
       ui->radioButton2->setChecked(true);
    }
    if((parm&0x02)==0x02)
    {
       ui->radioButton1->setChecked(true);
    }
    if((parm&0x04)==0x04)
    {
       ui->radioButton5->setChecked(true);
    }
}
void DialogUnitParm::initaa(uchar* buffer)
{
    unsigned char parm=*(buffer+6);
    if((parm&0x01)==0x01)
    {
      ui->checkBox3->setChecked(true);
    }
    if((parm&0x40)==0x40)
    {
       ui->checkBox2->setChecked(true);
    }
    if((parm&0x80)==0x80)
    {
       ui->checkBox1->setChecked(true);
    }
}
void DialogUnitParm::inita9(uchar* buffer)
{
    unsigned char parm=*(buffer+6);
    QString strinform;
    QString str;
    if(((parm&(0x01))==0x01)|((parm&(0x08))==0x08)|((parm&(0x04))==0x04))
    {
     str="Reserved";
     strinform.append(str);
     str="";
    }
    else if((parm&(0x02))==0x02)
    {
     str="T&F flash--local Flash or MMU Flash";
     strinform.append(str);
     str="";
    }
    else if((parm&(0x08))==0x08)
    {
     str=str.fromLocal8Bit("强制本地不控制-不允许信号机响应系统协调指令");
     strinform.append(str);
     str="";
    }
    else if((parm&(0x20))==0x20)
    {
     str=str.fromLocal8Bit("检测器故障-when any detectorAlarm fault occurs");
     strinform.append(str);
     str="";
    }
    else if((parm&(0x40))==0x40)
    {
     str=str.fromLocal8Bit("非紧急报警-任何报警发生时");
     strinform.append(str);
     str="";
    }
    else if((parm&(0x80))==0x80)
    {
     str=str.fromLocal8Bit("紧急报警-即将停止运行");
     strinform.append(str);
     str="";
    }
    else
    {
    strinform.append("null");
    }
    ui->Editsignlist->setText(strinform);
}
void DialogUnitParm::senda3()
{
    char buffer[60];
    buffer[0]=0x02;
    buffer[1]=0x00;
    buffer[2]=0x03;
    buffer[3]=0x80;
    buffer[4]=0xa3;
    buffer[5]=0x00;
    int len=6;
    unsigned short rssum=CommVerify((unsigned char *)buffer,len);
    buffer[len]=rssum/256;
    buffer[len+1]=rssum%256;
    this->com->WriteCom(buffer,len+2);
}
void DialogUnitParm::senda4()
{
    char buffer[60];
    buffer[0]=0x02;
    buffer[1]=0x00;
    buffer[2]=0x03;
    buffer[3]=0x80;
    buffer[4]=0xa4;
    buffer[5]=0x00;
    int len=6;
    unsigned short rssum=CommVerify((unsigned char *)buffer,len);
    buffer[len]=rssum/256;
    buffer[len+1]=rssum%256;
    this->com->WriteCom(buffer,len+2);
}
void DialogUnitParm::senda5()
{
    char buffer[60];
    buffer[0]=0x02;
    buffer[1]=0x00;
    buffer[2]=0x03;
    buffer[3]=0x80;
    buffer[4]=0xa5;
    buffer[5]=0x00;
    int len=6;
    unsigned short rssum=CommVerify((unsigned char *)buffer,len);
    buffer[len]=rssum/256;
    buffer[len+1]=rssum%256;
    this->com->WriteCom(buffer,len+2);
}
void DialogUnitParm::senda6()
{
    char buffer[60];
    buffer[0]=0x02;
    buffer[1]=0x00;
    buffer[2]=0x03;
    buffer[3]=0x80;
    buffer[4]=0xa6;
    buffer[5]=0x00;
    int len=6;
    unsigned short rssum=CommVerify((unsigned char *)buffer,len);
    buffer[len]=rssum/256;
    buffer[len+1]=rssum%256;
    this->com->WriteCom(buffer,len+2);
}
void DialogUnitParm::senda8()
{
    char buffer[60];
    buffer[0]=0x02;
    buffer[1]=0x00;
    buffer[2]=0x03;
    buffer[3]=0x80;
    buffer[4]=0xa8;
    buffer[5]=0x00;
    int len=6;
    unsigned short rssum=CommVerify((unsigned char *)buffer,len);
    buffer[len]=rssum/256;
    buffer[len+1]=rssum%256;
    this->com->WriteCom(buffer,len+2);
}
void DialogUnitParm::senda7()
{
    char buffer[60];
    buffer[0]=0x02;
    buffer[1]=0x00;
    buffer[2]=0x03;
    buffer[3]=0x80;
    buffer[4]=0xa7;
    buffer[5]=0x00;
    int len=6;
    unsigned short rssum=CommVerify((unsigned char *)buffer,len);
    buffer[len]=rssum/256;
    buffer[len+1]=rssum%256;
    this->com->WriteCom(buffer,len+2);
}
void DialogUnitParm::sendab()
{
    char buffer[60];
    buffer[0]=0x02;
    buffer[1]=0x00;
    buffer[2]=0x03;
    buffer[3]=0x80;
    buffer[4]=0xab;
    buffer[5]=0x00;
    int len=6;
    unsigned short rssum=CommVerify((unsigned char *)buffer,len);
    buffer[len]=rssum/256;
    buffer[len+1]=rssum%256;
    this->com->WriteCom(buffer,len+2);
}
void DialogUnitParm::sendaa()
{
    char buffer[60];
    buffer[0]=0x02;
    buffer[1]=0x00;
    buffer[2]=0x03;
    buffer[3]=0x80;
    buffer[4]=0xaa;
    buffer[5]=0x00;
    int len=6;
    unsigned short rssum=CommVerify((unsigned char *)buffer,len);
    buffer[len]=rssum/256;
    buffer[len+1]=rssum%256;
    this->com->WriteCom(buffer,len+2);
}
void DialogUnitParm::senda9()
{
    char buffer[60];
    buffer[0]=0x02;
    buffer[1]=0x00;
    buffer[2]=0x03;
    buffer[3]=0x80;
    buffer[4]=0xa9;
    buffer[5]=0x00;
    int len=6;
    unsigned short rssum=CommVerify((unsigned char *)buffer,len);
    buffer[len]=rssum/256;
    buffer[len+1]=rssum%256;
    this->com->WriteCom(buffer,len+2);
}
void DialogUnitParm::seta3()
{
    unsigned char value=(char)(ui->spinFlashContrl->value());
    char buffer[600];
    int len;
    buffer[0]=0x02;
    buffer[1]=0x00;
    buffer[2]=0x04;
    buffer[3]=0x81;
    buffer[4]=0xa3;
    buffer[5]=0x00;
    buffer[6]=value;
    len=7;
    unsigned short rssum=CommVerify((unsigned char *)buffer,len);
    buffer[len]=rssum/256;
    buffer[len+1]=rssum%256;
    this->com->WriteCom(buffer,len+2);
}
void DialogUnitParm::seta4()
{
    unsigned char value=(unsigned char)(ui->spinAllRedContrl->value());
    char buffer[600];
    int len;
    buffer[0]=0x02;
    buffer[1]=0x00;
    buffer[2]=0x04;
    buffer[3]=0x81;
    buffer[4]=0xa4;
    buffer[5]=0x00;
    buffer[6]=value;
    len=7;
    unsigned short rssum=CommVerify((unsigned char *)buffer,len);
    buffer[len]=rssum/256;
    buffer[len+1]=rssum%256;
    this->com->WriteCom(buffer,len+2);
}
void DialogUnitParm::seta5()
{
    int index=ui->signcontrlstate->currentIndex();
    unsigned char value;
    switch (index)
    {
        case 0:
            value=0x01;
            break;
        case 1:
            value=0x02;
            break;
        case 2:
            value=0x03;
            break;
        case 3:
            value=0x04;
            break;
        case 4:
            value=0x05;
            break;
        case 5:
            value=0x06;
            break;
        case 6:
            QString str1;
            str1 = str1.fromLocal8Bit("错误");
            QString str2;
            str2 = str2.fromLocal8Bit("当前信号机控制状态不能设置为错误状态！");
            QMessageBox::information(this, str1,str2,QMessageBox::Ok,NULL);
            break;
     }
    char buffer[600];
    int len;
    buffer[0]=0x02;
    buffer[1]=0x00;
    buffer[2]=0x04;
    buffer[3]=0x81;
    buffer[4]=0xa5;
    buffer[5]=0x00;
    buffer[6]=value;
    len=7;
    unsigned short rssum=CommVerify((unsigned char *)buffer,len);
    buffer[len]=rssum/256;
    buffer[len+1]=rssum%256;
    this->com->WriteCom(buffer,len+2);
}
void DialogUnitParm::seta6(){}
void DialogUnitParm::setaa()
{
    unsigned char value =0x00;
    if(ui->checkBox1->isChecked())
    {
       value=value|0x80;
    }
    if(ui->checkBox2->isChecked())
    {
       value=value|0x40;
    }
    if(ui->checkBox3->isChecked())
    {
       value=value|0x01;
    }
    char buffer[600];
    int len;
    buffer[0]=0x02;
    buffer[1]=0x00;
    buffer[2]=0x04;
    buffer[3]=0x81;
    buffer[4]=0xaa;
    buffer[5]=0x00;
    buffer[6]=value;
    len=7;
    unsigned short rssum=CommVerify((unsigned char *)buffer,len);
    buffer[len]=rssum/256;
    buffer[len+1]=rssum%256;
    this->com->WriteCom(buffer,len+2);
}
void DialogUnitParm::setab()
{
    char value=0x00;
    if(ui->radioButton2->isChecked())
    {
        //qDebug()<<"22222222222222222222222222222222222";
        value=0x01;
    }
    if(ui->radioButton1->isChecked())
    {
       // qDebug()<<"11111111111111111111111111111111111";
        value=0x02;
    }
    if(ui->radioButton5->isChecked())
    {
        //qDebug()<<"55555555555555555555555555555555555";
        value=0x04;
    }
    char buffer[600];
    int len;
    buffer[0]=0x02;
    buffer[1]=0x00;
    buffer[2]=0x04;
    buffer[3]=0x81;
    buffer[4]=0xab;
    buffer[5]=0x00;
    buffer[6]=value;
    len=7;
    unsigned short rssum=CommVerify((unsigned char *)buffer,len);
    buffer[len]=rssum/256;
    buffer[len+1]=rssum%256;
    this->com->WriteCom(buffer,len+2);
}

void DialogUnitParm::on_butfind_clicked()
{
    ui->spinAllRedContrl->clear();
    ui->spinFlashContrl->clear();
    ui->Editsign1->clear();
    ui->Editsign2->clear();
    ui->Editsignlist->clear();
    ui->checkBox1->setChecked(false);
    ui->checkBox2->setChecked(false);
    ui->checkBox3->setChecked(false);
    ui->radioNULL->setChecked(false);
    ui->display->clear();
    finda3=false;
    finda4=false;
    finda5=false;
    finda6=false;
    finda8=false;
    finda7=false;
    findab=false;
    findaa=false;
    finda9=false;
    ui->display->setText(tr("查询中......"));
    QTimer::singleShot(1,this,SLOT(senda3()));
    revtimer->start(80);
    connect(revtimer,SIGNAL(timeout()),this,SLOT(rev()));
    timeout->start(3000);
}

void DialogUnitParm::on_butok_clicked()
{
    ui->display->clear();
    succa3=false;
    succa4=false;
    succaa=false;
    succab=false;

    QTimer::singleShot(1,this,SLOT(seta3()));
    revtimer->start(30);
    connect(revtimer,SIGNAL(timeout()),this,SLOT(rev()));

    timeout->start(5000);

}
