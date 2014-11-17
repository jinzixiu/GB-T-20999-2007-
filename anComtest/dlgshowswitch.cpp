#include "dlgshowswitch.h"
#include "ui_dlgshowswitch.h"
#include "unit.h"
#include <QDebug>

static bool revcc=false;
static bool revcb=false;
static bool findcc=false;
static bool findcb=false;


DlgShowSwitch::DlgShowSwitch(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DlgShowSwitch)
{
    ui->setupUi(this);
    this->com=new CPubSub();
    this->revtimer=new QTimer();
    this->timeout=new QTimer();
    connect(timeout,SIGNAL(timeout()),this,SLOT(warming()));
}

DlgShowSwitch::~DlgShowSwitch()
{
    delete ui;
    deleteLater();
}
void DlgShowSwitch::setcom(CPubSub *com)
{
    this->com=com;
}
void DlgShowSwitch::dealwith(uchar* rec,int len)
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
            if((uchar)(*(s+4))==0xcc)
            {
                initcc((uchar*)s);
                findcc=true;
                QTimer::singleShot(1,this,SLOT(sendcb()));
            }
            if((uchar)(*(s+4))==0xcb)
            {
                initcb((uchar*)s);
                findcb=true;
            }
            if(findcb&findcc)
            {
                ui->display->setText(tr("查询成功!"));
                timeout->stop();
            }
        }
        if((uchar)*(s+3)==0x85)//设置成功命令
        {
            if((uchar)(*(s+4))==0xcc)
            {
                revcc=true;
            }
            if((uchar)(*(s+4))==0xcb)
            {
                revcb=true;
            }
            if(revcc&revcb)
            {
                ui->display->setText(tr("设置成功!"));
                timeout->stop();
            }

        }
        if((uchar)*(s+3)==0x86)//设置错误命令
        {
            if((uchar)(*(s+4))==0xcc)
            {
               ui->display->setText(tr("闪烁开关设置失败!"));
            }
            if((uchar)(*(s+4))==0xcb)
            {
                ui->display->setText(tr("行人开关设置失败!"));
            }
        }
        s +=(num+5);
        i += (num+4);
    }
}
void DlgShowSwitch::initcc(unsigned char *buffer)
{
    char parm[8];
    parm[0]=*(buffer+6);
    parm[1]=*(buffer+7);
    parm[2]=*(buffer+8);
    parm[3]=*(buffer+9);
    parm[4]=*(buffer+10);
    parm[5]=*(buffer+11);
    parm[6]=*(buffer+12);
    parm[7]=*(buffer+13);
    //if((uchar)parm[0]!=0xff)
    {
    if((parm[0]&0x01)==0x01)
       ui->r1->setChecked(true);
    if((parm[0]&0x02)==0x02)
       ui->r2->setChecked(true);
    if((parm[0]&0x04)==0x04)
       ui->r3->setChecked(true);
    if((parm[0]&0x08)==0x08)
       ui->r4->setChecked(true);
    if((parm[0]&0x10)==0x10)
       ui->y1->setChecked(true);
    if((parm[0]&0x20)==0x20)
       ui->y2->setChecked(true);
    if((parm[0]&0x40)==0x40)
       ui->y3->setChecked(true);
    if((parm[0]&0x80)==0x80)
       ui->y4->setChecked(true);
    }
    //////////char 1/////////////////
    if((uchar)parm[1]!=0xff)
    {
    if((parm[1]&0x01)==0x01)
       ui->b1->setChecked(true);
    if((parm[1]&0x02)==0x02)
       ui->b2->setChecked(true);
    if((parm[1]&0x04)==0x04)
       ui->b3->setChecked(true);
    if((parm[1]&0x08)==0x08)
       ui->b4->setChecked(true);
    }
    /////////char  2/////////////////
    //if((uchar)parm[2]!=0xff)
    {
    if((parm[2]&0x01)==0x01)
       ui->r5->setChecked(true);
    if((parm[2]&0x02)==0x02)
       ui->r6->setChecked(true);
    if((parm[2]&0x04)==0x04)
       ui->r7->setChecked(true);
    if((parm[2]&0x08)==0x08)
       ui->r8->setChecked(true);
    if((parm[2]&0x10)==0x10)
       ui->y5->setChecked(true);
    if((parm[2]&0x20)==0x20)
       ui->y6->setChecked(true);
    if((parm[2]&0x40)==0x40)
       ui->y7->setChecked(true);
    if((parm[2]&0x80)==0x80)
       ui->y8->setChecked(true);
    }
    //////////char 3/////////////////
    if((uchar)parm[3]!=0xff)
    {
    if((parm[3]&0x01)==0x01)
       ui->b5->setChecked(true);
    if((parm[3]&0x02)==0x02)
       ui->b6->setChecked(true);
    if((parm[3]&0x04)==0x04)
       ui->b7->setChecked(true);
    if((parm[3]&0x08)==0x08)
       ui->b8->setChecked(true);
    }
    /////////char  4/////////////////
    //if((uchar)parm[4]!=0xff)
    {
    if((parm[4]&0x01)==0x01)
       ui->r9->setChecked(true);
    if((parm[4]&0x02)==0x02)
       ui->r10->setChecked(true);
    if((parm[4]&0x04)==0x04)
       ui->r11->setChecked(true);
    if((parm[4]&0x08)==0x08)
       ui->r12->setChecked(true);
    if((parm[4]&0x10)==0x10)
       ui->y9->setChecked(true);
    if((parm[4]&0x20)==0x20)
       ui->y10->setChecked(true);
    if((parm[4]&0x40)==0x40)
       ui->y11->setChecked(true);
    if((parm[4]&0x80)==0x80)
       ui->y12->setChecked(true);
    }
    //////////char 5/////////////////
    if((uchar)parm[5]!=0xff)
    {
    if((parm[5]&0x01)==0x01)
       ui->b9->setChecked(true);
    if((parm[5]&0x02)==0x02)
       ui->b10->setChecked(true);
    if((parm[5]&0x04)==0x04)
       ui->b11->setChecked(true);
    if((parm[5]&0x08)==0x08)
       ui->b12->setChecked(true);
    }
    /////////char  6/////////////////
    //if((uchar)parm[6]!=0xff)
    {
    if((parm[6]&0x01)==0x01)
       ui->r13->setChecked(true);
    if((parm[6]&0x02)==0x02)
       ui->r14->setChecked(true);
    if((parm[6]&0x04)==0x04)
       ui->r15->setChecked(true);
    if((parm[6]&0x08)==0x08)
       ui->r16->setChecked(true);
    if((parm[6]&0x10)==0x10)
       ui->y13->setChecked(true);
    if((parm[6]&0x20)==0x20)
       ui->y14->setChecked(true);
    if((parm[6]&0x40)==0x40)
       ui->y15->setChecked(true);
    if((parm[6]&0x80)==0x80)
       ui->y16->setChecked(true);
    }
    //////////char 7/////////////////
    if((uchar)parm[7]!=0xff)
    {
    if((parm[7]&0x01)==0x01)
       ui->b13->setChecked(true);
    if((parm[7]&0x02)==0x02)
       ui->b14->setChecked(true);
    if((parm[7]&0x04)==0x04)
       ui->b15->setChecked(true);
    if((parm[7]&0x08)==0x08)
       ui->b16->setChecked(true);
    }
    /////////char  8/////////////////
}
void DlgShowSwitch::initcb(unsigned char *buffer)
{
    char value=*(buffer+6);
    if((uchar)value!=0xff)
    {
        if((uchar)0x01==value)
        {
           ui->radpassswitch1->setChecked(true);

        }
        if((uchar)0x00==value)
        {
           ui->radpassswitch2->setChecked(true);

        }
    }else
    {
        ui->null_2->setChecked(true);
    }
}
void DlgShowSwitch::rev()
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
void DlgShowSwitch::warming()
{
    ui->display->clear();
    ui->display->setText(tr("失败!请重试!"));
}
void DlgShowSwitch::sendcc()
{
    char buffer[60];
    buffer[0]=0x02;
    buffer[1]=0x00;
    buffer[2]=0x03;
    buffer[3]=0x80;
    buffer[4]=0xcc;
    buffer[5]=0x00;
    int len=6;
    unsigned short rssum=CommVerify((unsigned char *)buffer,len);
    buffer[len]=rssum/256;
    buffer[len+1]=rssum%256;
    this->com->WriteCom(buffer,len+2);
}
void DlgShowSwitch::sendcb()
{
    char buffer[60];
    buffer[0]=0x02;
    buffer[1]=0x00;
    buffer[2]=0x03;
    buffer[3]=0x80;
    buffer[4]=0xcb;
    buffer[5]=0x00;
    int len=6;
    unsigned short rssum=CommVerify((unsigned char *)buffer,len);
    buffer[len]=rssum/256;
    buffer[len+1]=rssum%256;
    this->com->WriteCom(buffer,len+2);
}
void DlgShowSwitch::setcc()
{
    unsigned char parm[8]={0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
    if(ui->r1->isChecked())
       parm[0]=(parm[0]|0x01);
    if(ui->r2->isChecked())
       parm[0]=(parm[0]|0x02);
    if(ui->r3->isChecked())
       parm[0]=(parm[0]|0x04);
    if(ui->r4->isChecked())
       parm[0]=(parm[0]|0x08);
    if(ui->y1->isChecked())
       parm[0]=(parm[0]|0x10);
    if(ui->y2->isChecked())
       parm[0]=(parm[0]|0x20);
    if(ui->y3->isChecked())
       parm[0]=(parm[0]|0x40);
    if(ui->y4->isChecked())
       parm[0]=(parm[0]|0x80);
    //////////char 1/////////////////
    if(ui->b1->isChecked())
       parm[1]=(parm[1]|0x01);
    if(ui->b2->isChecked())
       parm[1]=(parm[1]|0x02);
    if(ui->b3->isChecked())
       parm[1]=(parm[1]|0x04);
    if(ui->b4->isChecked())
       parm[1]=(parm[1]|0x08);
    /////////char  2/////////////////
    if(ui->r5->isChecked())
       parm[2]=(parm[2]|0x01);
    if(ui->r6->isChecked())
       parm[2]=(parm[2]|0x02);
    if(ui->r7->isChecked())
       parm[2]=(parm[2]|0x04);
    if(ui->r8->isChecked())
       parm[2]=(parm[2]|0x08);

    if(ui->y5->isChecked())
       parm[2]=(parm[2]|0x10);
    if(ui->y6->isChecked())
       parm[2]=(parm[2]|0x20);
    if(ui->y7->isChecked())
       parm[2]=(parm[2]|0x40);
    if(ui->y8->isChecked())
       parm[2]=(parm[2]|0x80);
    //////////char 3/////////////////
    if(ui->b5->isChecked())
       parm[3]=(parm[3]|0x01);
    if(ui->b6->isChecked())
       parm[3]=(parm[3]|0x02);
    if(ui->b7->isChecked())
       parm[3]=(parm[3]|0x04);
    if(ui->b8->isChecked())
       parm[3]=(parm[3]|0x08);
    /////////char  4/////////////////
    if(ui->r9->isChecked())
       parm[4]=(parm[4]|0x01);
    if(ui->r10->isChecked())
       parm[4]=(parm[4]|0x02);
    if(ui->r11->isChecked())
       parm[4]=(parm[4]|0x04);
    if(ui->r12->isChecked())
       parm[4]=(parm[4]|0x08);

    if(ui->y9->isChecked())
       parm[4]=(parm[4]|0x10);
    if(ui->y10->isChecked())
       parm[4]=(parm[4]|0x20);
    if(ui->y11->isChecked())
       parm[4]=(parm[4]|0x40);
    if(ui->y12->isChecked())
       parm[4]=(parm[4]|0x80);

    //////////char 5/////////////////
    if(ui->b9->isChecked())
       parm[5]=(parm[5]|0x01);
    if(ui->b10->isChecked())
       parm[5]=(parm[5]|0x02);
    if(ui->b11->isChecked())
       parm[5]=(parm[5]|0x04);
    if(ui->b12->isChecked())
       parm[5]=(parm[5]|0x08);
    /////////char  6/////////////////
    if(ui->r13->isChecked())
       parm[6]=(parm[6]|0x01);
    if(ui->r14->isChecked())
       parm[6]=(parm[6]|0x02);
    if(ui->r15->isChecked())
       parm[6]=(parm[6]|0x04);
    if(ui->r16->isChecked())
       parm[6]=(parm[6]|0x08);

    if(ui->y13->isChecked())
       parm[6]=(parm[6]|0x10);
    if(ui->y14->isChecked())
       parm[6]=(parm[6]|0x20);
    if(ui->y15->isChecked())
       parm[6]=(parm[6]|0x40);
    if(ui->y16->isChecked())
       parm[6]=(parm[6]|0x80);
    //////////char 7/////////////////
    if(ui->b13->isChecked())
       parm[7]=(parm[7]|0x01);
    if(ui->b14->isChecked())
       parm[7]=(parm[7]|0x02);
    if(ui->b15->isChecked())
       parm[7]=(parm[7]|0x04);
    if(ui->b16->isChecked())
       parm[7]=(parm[7]|0x08);
    /////////char  8/////////////////
  /**************************************************
  ***************************************************/
    char buffer[600];
    int len;
    buffer[0]=0x02;
    buffer[1]=0x00;
    buffer[2]=0x0b;
    buffer[3]=0x81;
    buffer[4]=0xcc;
    buffer[5]=0x00;
    buffer[6]=parm[0];
    buffer[7]=parm[1];
    buffer[8]=parm[2];
    buffer[9]=parm[3];
    buffer[10]=parm[4];
    buffer[11]=parm[5];
    buffer[12]=parm[6];
    buffer[13]=parm[7];
    len=14;
    unsigned short rssum=CommVerify((unsigned char *)buffer,len);
    buffer[len]=rssum/256;
    buffer[len+1]=rssum%256;
    this->com->WriteCom(buffer,len+2);
}
void DlgShowSwitch::setcb()
{
    unsigned char value =0x00;
    if(ui->radpassswitch1->isChecked())
    {
        value=0x01;
    }
    if(ui->radpassswitch2->isChecked())
    {
        value=0x00;
    }
    if(ui->null_2->isChecked())
    {
        value=0xff;
    }
    char buffer[600];
    int len;
    buffer[0]=0x02;
    buffer[1]=0x00;
    buffer[2]=0x04;
    buffer[3]=0x81;
    buffer[4]=0xcb;
    buffer[5]=0x00;
    buffer[6]=value;
    len=7;
    unsigned short rssum=CommVerify((unsigned char *)buffer,len);
    buffer[len]=rssum/256;
    buffer[len+1]=rssum%256;
    this->com->WriteCom(buffer,len+2);
}

void DlgShowSwitch::on_butfind_clicked()
{
    ui->display->clear();
    findcc=false;
    findcb=false;

    ui->radpassswitch1->setChecked(false);
    ui->radpassswitch1->setChecked(false);

    ui->checkg->setChecked(false);
    ui->checkr->setChecked(false);
    ui->checky->setChecked(false);

    ui->null_2->setChecked(false);

    ui->r1->setChecked(false);
    ui->r2->setChecked(false);
    ui->r3->setChecked(false);
    ui->r4->setChecked(false);
    ui->r5->setChecked(false);
    ui->r6->setChecked(false);
    ui->r7->setChecked(false);
    ui->r8->setChecked(false);
    ui->r9->setChecked(false);
    ui->r10->setChecked(false);
    ui->r11->setChecked(false);
    ui->r12->setChecked(false);
    ui->r13->setChecked(false);
    ui->r14->setChecked(false);
    ui->r15->setChecked(false);
    ui->r16->setChecked(false);

    ui->b1->setChecked(false);
    ui->b2->setChecked(false);
    ui->b3->setChecked(false);
    ui->b4->setChecked(false);
    ui->b5->setChecked(false);
    ui->b6->setChecked(false);
    ui->b7->setChecked(false);
    ui->b8->setChecked(false);
    ui->b9->setChecked(false);
    ui->b10->setChecked(false);
    ui->b11->setChecked(false);
    ui->b12->setChecked(false);
    ui->b13->setChecked(false);
    ui->b14->setChecked(false);
    ui->b15->setChecked(false);
    ui->b16->setChecked(false);

    ui->y1->setChecked(false);
    ui->y2->setChecked(false);
    ui->y3->setChecked(false);
    ui->y4->setChecked(false);
    ui->y5->setChecked(false);
    ui->y6->setChecked(false);
    ui->y7->setChecked(false);
    ui->y8->setChecked(false);
    ui->y9->setChecked(false);
    ui->y10->setChecked(false);
    ui->y11->setChecked(false);
    ui->y12->setChecked(false);
    ui->y13->setChecked(false);
    ui->y14->setChecked(false);
    ui->y15->setChecked(false);
    ui->y16->setChecked(false);
    ui->display->setText(tr("设置中......"));
    QTimer::singleShot(1,this,SLOT(sendcc()));
    revtimer->start(30);
    connect(revtimer,SIGNAL(timeout()),this,SLOT(rev()));
    timeout->start(5000);
}

void DlgShowSwitch::on_butok_clicked()
{
    revcc=false;
    revcb=false;
    ui->display->clear();
    QTimer::singleShot(1,this,SLOT(setcc()));
    QTimer::singleShot(500,this,SLOT(setcb()));
    timeout->start();
}

void DlgShowSwitch::on_checkr_stateChanged(int i)
{
    if(ui->checkr->isChecked())
    {
        ui->r1->setChecked(true);
        ui->r2->setChecked(true);
        ui->r3->setChecked(true);
        ui->r4->setChecked(true);
        ui->r5->setChecked(true);
        ui->r6->setChecked(true);
        ui->r7->setChecked(true);
        ui->r8->setChecked(true);
        ui->r9->setChecked(true);
        ui->r10->setChecked(true);
        ui->r11->setChecked(true);
        ui->r12->setChecked(true);
        ui->r13->setChecked(true);
        ui->r14->setChecked(true);
        ui->r15->setChecked(true);
        ui->r16->setChecked(true);
    }
    else
    {
        ui->r1->setChecked(false);
        ui->r2->setChecked(false);
        ui->r3->setChecked(false);
        ui->r4->setChecked(false);
        ui->r5->setChecked(false);
        ui->r6->setChecked(false);
        ui->r7->setChecked(false);
        ui->r8->setChecked(false);
        ui->r9->setChecked(false);
        ui->r10->setChecked(false);
        ui->r11->setChecked(false);
        ui->r12->setChecked(false);
        ui->r13->setChecked(false);
        ui->r14->setChecked(false);
        ui->r15->setChecked(false);
        ui->r16->setChecked(false);
    }
}

void DlgShowSwitch::on_checky_stateChanged(int i)
{
    if(ui->checky->isChecked())
    {
        ui->y1->setChecked(true);
        ui->y2->setChecked(true);
        ui->y3->setChecked(true);
        ui->y4->setChecked(true);
        ui->y5->setChecked(true);
        ui->y6->setChecked(true);
        ui->y7->setChecked(true);
        ui->y8->setChecked(true);
        ui->y9->setChecked(true);
        ui->y10->setChecked(true);
        ui->y11->setChecked(true);
        ui->y12->setChecked(true);
        ui->y13->setChecked(true);
        ui->y14->setChecked(true);
        ui->y15->setChecked(true);
        ui->y16->setChecked(true);
    }
    else
    {
        ui->y1->setChecked(false);
        ui->y2->setChecked(false);
        ui->y3->setChecked(false);
        ui->y4->setChecked(false);
        ui->y5->setChecked(false);
        ui->y6->setChecked(false);
        ui->y7->setChecked(false);
        ui->y8->setChecked(false);
        ui->y9->setChecked(false);
        ui->y10->setChecked(false);
        ui->y11->setChecked(false);
        ui->y12->setChecked(false);
        ui->y13->setChecked(false);
        ui->y14->setChecked(false);
        ui->y15->setChecked(false);
        ui->y16->setChecked(false);
    }
}

void DlgShowSwitch::on_checkg_stateChanged(int i)
{
    if(ui->checkg->isChecked())
    {
        ui->b1->setChecked(true);
        ui->b2->setChecked(true);
        ui->b3->setChecked(true);
        ui->b4->setChecked(true);
        ui->b5->setChecked(true);
        ui->b6->setChecked(true);
        ui->b7->setChecked(true);
        ui->b8->setChecked(true);
        ui->b9->setChecked(true);
        ui->b10->setChecked(true);
        ui->b11->setChecked(true);
        ui->b12->setChecked(true);
        ui->b13->setChecked(true);
        ui->b14->setChecked(true);
        ui->b15->setChecked(true);
        ui->b16->setChecked(true);
    }
    else
    {
        ui->b1->setChecked(false);
        ui->b2->setChecked(false);
        ui->b3->setChecked(false);
        ui->b4->setChecked(false);
        ui->b5->setChecked(false);
        ui->b6->setChecked(false);
        ui->b7->setChecked(false);
        ui->b8->setChecked(false);
        ui->b9->setChecked(false);
        ui->b10->setChecked(false);
        ui->b11->setChecked(false);
        ui->b12->setChecked(false);
        ui->b13->setChecked(false);
        ui->b14->setChecked(false);
        ui->b15->setChecked(false);
        ui->b16->setChecked(false);
    }
}

