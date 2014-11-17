#include "dialogcontrlparm.h"
#include "ui_dialogcontrlparm.h"
#include "unit.h"
#include <QDebug>
static bool  findb5=false;
static bool  findb6=false;
static bool  findb7=false;
static bool  findb8=false;
static bool  findb9=false;
static bool  findba=false;
static bool  findbb=false;
static bool  findbd=false;
static bool  findcd=false;
DialogContrlParm::DialogContrlParm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogContrlParm)
{
    ui->setupUi(this);
    this->com=new CPubSub();
    this->revtimer=new QTimer();
    this->timeout=new QTimer();
    connect(timeout,SIGNAL(timeout()),this,SLOT(warming()));
}

DialogContrlParm::~DialogContrlParm()
{
    delete ui;
    deleteLater();
}
void DialogContrlParm::setcom(CPubSub *com)
{
    this->com=com;
}
void DialogContrlParm::dealwith(uchar* rec,int len)
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
            if((uchar)(*(s+4))==0xb5)
            {
                initb5((uchar*)s);
                findb5=true;
                QTimer::singleShot(1,this,SLOT(sendb6()));
            }
            if((uchar)(*(s+4))==0xb6)
            {
                initb6((uchar*)s);
                findb6=true;
                QTimer::singleShot(1,this,SLOT(sendb7()));
            }
            if((uchar)(*(s+4))==0xb7)
            {
                initb7((uchar*)s);
                findb7=true;
                QTimer::singleShot(1,this,SLOT(sendb8()));
            }
            if((uchar)(*(s+4))==0xb8)
            {
                initb8((uchar*)s);
                findb8=true;
                QTimer::singleShot(1,this,SLOT(sendb9()));
            }
            if((uchar)(*(s+4))==0xb9)
            {
                initb9((uchar*)s);
                findb9=true;
                QTimer::singleShot(1,this,SLOT(sendba()));
            }
            if((uchar)(*(s+4))==0xba)
            {
                initba((uchar*)s);
                findba=true;
                QTimer::singleShot(1,this,SLOT(sendbb()));
            }
            if((uchar)(*(s+4))==0xbb)
            {
                initbb((uchar*)s);
                findbb=true;
                QTimer::singleShot(1,this,SLOT(sendbd()));
            }
            if((uchar)(*(s+4))==0xbd)
            {
                initbd((uchar*)s);
                findbd=true;
                QTimer::singleShot(1,this,SLOT(sendcd()));
            }
            if((uchar)(*(s+4))==0xcd)
            {
                initcd((uchar*)s);
                findcd=true;
            }
            if(findb5&findb6&findb7&findb8&findb9&findba&findbb&findbd&findcd)
            {
                ui->display->setText(tr("查询成功!"));
                timeout->stop();
            }
        }
        if((uchar)*(s+3)==0x85)//设置成功命令
        {            
            if((uchar)(*(s+4))==0xcd)
            {
                ui->display->setText(tr("设置成功!!!"));
                timeout->stop();
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
void DialogContrlParm::rev()
{
    qDebug()<<"~~~~~~~~~~~~~~~~~~";
    char RecBuf[4096];
    memset(RecBuf,NULL,4096);
    QString RecText;
    int Rlen;
    if(com->isopen())
    {
        Rlen=com->GetDataLen();
        if(Rlen>0&&(Rlen==16|Rlen==8|Rlen==9))
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
void DialogContrlParm::warming()
{
    ui->display->clear();
    ui->display->setText(tr("失败!请重试!"));
}
void DialogContrlParm::on_butfind_clicked()
{
    findb5=false;
    findb6=false;
    findb7=false;
    findb8=false;
    findb9=false;
    findba=false;
    findbb=false;
    findbd=false;
    findcd=false;
    ui->display->clear();
    ui->spincycletime->clear();
    ui->spininstruction->clear();
    ui->spinManual->clear();
    ui->spinmodel->clear();
    ui->spinphasedif->clear();
    ui->spinstate->clear();
   //ui->spinSystem->clear();
    ui->checkBox1_1->setChecked(false);
    ui->checkBox1_2->setChecked(false);
    ui->checkBox1_3->setChecked(false);
    ui->checkBox1_4->setChecked(false);
    ui->checkBox1_5->setChecked(false);
    ui->checkBox1_6->setChecked(false);
    ui->checkBox1_7->setChecked(false);
    ui->checkBox1_8->setChecked(false);

    ui->checkBox2_1->setChecked(false);
    ui->checkBox2_2->setChecked(false);
    ui->checkBox2_3->setChecked(false);
    ui->checkBox2_4->setChecked(false);
    ui->checkBox2_5->setChecked(false);
    ui->checkBox2_6->setChecked(false);
    ui->checkBox2_7->setChecked(false);
    ui->checkBox2_8->setChecked(false);

    ui->checkBox3_1->setChecked(false);
    ui->checkBox3_2->setChecked(false);
    ui->checkBox3_3->setChecked(false);
    ui->checkBox3_4->setChecked(false);
    ui->checkBox3_5->setChecked(false);
    ui->checkBox3_6->setChecked(false);
    ui->checkBox3_7->setChecked(false);
    ui->checkBox3_8->setChecked(false);

    ui->checkBox4_1->setChecked(false);
    ui->checkBox4_2->setChecked(false);
    ui->checkBox4_3->setChecked(false);
    ui->checkBox4_4->setChecked(false);
    ui->checkBox4_5->setChecked(false);
    ui->checkBox4_6->setChecked(false);
    ui->checkBox4_7->setChecked(false);
    ui->checkBox4_8->setChecked(false);

    ui->radionull->setChecked(true);
    QTimer::singleShot(1,this,SLOT(sendb5()));

    revtimer->start(20);
    connect(revtimer,SIGNAL(timeout()),this,SLOT(rev()));
    timeout->start(5000);
    ui->display->clear();
    ui->display->setText(tr("查询中......"));
}

void DialogContrlParm::on_butok_clicked()
{
    ui->display->clear();
    QTimer::singleShot(1,this,SLOT(setCountDown()));
}

void DialogContrlParm::initb5(uchar *buffer)
{
    unsigned char value=*(buffer+6);
    if(value!=0xff)
    ui->spinManual->setValue(value);
}
void DialogContrlParm::initb6(uchar *buffer)
{
    unsigned char value=*(buffer+6);
    if(value!=0xff)
    {
        if(value==0x00)
            ui->comboBoxplan->setCurrentIndex(0);
        if(value==0x01)
            ui->comboBoxplan->setCurrentIndex(1);
        if(value==0x02)
            ui->comboBoxplan->setCurrentIndex(2);
        if(value==0x03)
            ui->comboBoxplan->setCurrentIndex(3);
        if(value==0x04)
            ui->comboBoxplan->setCurrentIndex(4);
        if(value==0x05)
            ui->comboBoxplan->setCurrentIndex(5);
        if(value==0x06)
            ui->comboBoxplan->setCurrentIndex(6);
        if(value==0x07)
            ui->comboBoxplan->setCurrentIndex(7);
        if(value==0x08)
            ui->comboBoxplan->setCurrentIndex(8);
        if(value==0x09)
            ui->comboBoxplan->setCurrentIndex(9);
        if(value==0x0a)
            ui->comboBoxplan->setCurrentIndex(10);
        if(value==0x0b)
            ui->comboBoxplan->setCurrentIndex(11);
        if(value==0x0c)
            ui->comboBoxplan->setCurrentIndex(12);
        if(value==0x0d)
            ui->comboBoxplan->setCurrentIndex(13);
        if(value==0x0e)
            ui->comboBoxplan->setCurrentIndex(14);
        if(value==0x0f)
            ui->comboBoxplan->setCurrentIndex(15);
        if(value==0x10)
            ui->comboBoxplan->setCurrentIndex(16);
        if(value==0x11)
            ui->comboBoxplan->setCurrentIndex(17);
        if(value==0x12)
            ui->comboBoxplan->setCurrentIndex(18);
        if(value==0x13)
            ui->comboBoxplan->setCurrentIndex(19);
        if(value==0x14)
            ui->comboBoxplan->setCurrentIndex(20);
        if(value==0x15)
            ui->comboBoxplan->setCurrentIndex(21);
        if(value==0x16)
            ui->comboBoxplan->setCurrentIndex(22);
        if(value==0x17)
            ui->comboBoxplan->setCurrentIndex(23);
        if(value==0x18)
            ui->comboBoxplan->setCurrentIndex(24);
        if(value==0x19)
            ui->comboBoxplan->setCurrentIndex(25);
        if(value==0x1a)
            ui->comboBoxplan->setCurrentIndex(26);
        if(value==0x1b)
            ui->comboBoxplan->setCurrentIndex(27);
        if(value==0x1c)
            ui->comboBoxplan->setCurrentIndex(28);
        if(value==0x1d)
            ui->comboBoxplan->setCurrentIndex(29);
        if(value==0x1e)
            ui->comboBoxplan->setCurrentIndex(30);
        if(value==0x1f)
            ui->comboBoxplan->setCurrentIndex(31);

        if(value==0xfc)
            ui->comboBoxplan->setCurrentIndex(32);
        if(value==0xfd)
            ui->comboBoxplan->setCurrentIndex(33);
        if(value==0xfe)
            ui->comboBoxplan->setCurrentIndex(34);
    }
}
void DialogContrlParm::initb7(uchar *buffer)
{
    unsigned char value=*(buffer+6);
    if(1==value)//关灯
    {
        ui->radioclose->isChecked();
    }
    if(2==value)//闪光
    {
        ui->radioflash->isChecked();
    }
    if(3==value)//全红
    {
        ui->radioallred->isChecked();
    }
    if(6==value)//感应
    {
        ui->radiofeel->isChecked();
    }
    if(8==value)//单点优化
    {
        ui->radiosinglebetter->isChecked();
    }
    if(11==value)//主从控制
    {
        ui->radiomasterlinecontrl->isChecked();
    }
    if(12==value)//系统优化
    {
        ui->radiosystembetter->isChecked();
    }
    if(13==value)//干预线控
    {
        ui->radiointerventionlinecontrl->isChecked();
    }
}
void DialogContrlParm::initb8(uchar *buffer)
{
    unsigned char value=*(buffer+6);
    ui->spincycletime->setValue(value);
}
void DialogContrlParm::initb9(uchar *buffer)
{
    unsigned char value=*(buffer+6);
    ui->spinphasedif->setValue(value);
}
void DialogContrlParm::initba(uchar *buffer)
{
    unsigned char value=*(buffer+6);
    ui->spinstate->setValue(value);
}
void DialogContrlParm::initbb(uchar *buffer)
{
    unsigned char value=*(buffer+6);
    ui->spininstruction->setValue(value);
}
void DialogContrlParm::initbd(uchar *buffer)
{
    unsigned char value=*(buffer+6);
    ui->spinmodel->setValue(value);
}
void DialogContrlParm::initcd(uchar *buffer)
{
    unsigned char parm[8];
    parm[0]=*(buffer+6);
//    qDebug()<<"parm[0]:"+QString::number(parm[0],16);
    parm[1]=*(buffer+7);
    parm[2]=*(buffer+8);
    parm[3]=*(buffer+9);
    parm[4]=*(buffer+10);
    parm[5]=*(buffer+11);
    parm[6]=*(buffer+12);
    parm[7]=*(buffer+13);
//    qDebug()<<"parm[1]:"+QString::number(parm[1],16);
//    qDebug()<<"parm[2]:"+QString::number(parm[2],16);
//    qDebug()<<"parm[3]:"+QString::number(parm[3],16);
    ///////////////////1///////////////////////////
    if((parm[0]&0x01)==0x01)
    {
        ui->checkBox1_1->setChecked(true);
    }
    if((parm[0]&0x02)==0x02)
    {
        ui->checkBox1_2->setChecked(true);
    }
    if((parm[0]&0x04)==0x04)
    {
        ui->checkBox1_3->setChecked(true);
    }
    if((parm[0]&0x08)==0x08)
    {
        ui->checkBox1_4->setChecked(true);
    }
    if((parm[1]&0x01)==0x01)
    {
        ui->checkBox1_5->setChecked(true);
    }
    if((parm[1]&0x02)==0x02)
    {
        ui->checkBox1_6->setChecked(true);
    }
    if((parm[1]&0x04)==0x04)
    {
        ui->checkBox1_7->setChecked(true);
    }
    if((parm[1]&0x08)==0x08)
    {
        ui->checkBox1_8->setChecked(true);
    }
    ////////////////2////////////////////////////
    if((parm[2]&0x01)==0x01)
    {
        ui->checkBox2_1->setChecked(true);
    }
    if((parm[2]&0x02)==0x02)
    {
        ui->checkBox2_2->setChecked(true);
    }
    if((parm[2]&0x04)==0x04)
    {
        ui->checkBox2_3->setChecked(true);
    }
    if((parm[2]&0x08)==0x08)
    {
        ui->checkBox2_4->setChecked(true);
    }
    if((parm[3]&0x01)==0x01)
    {
        ui->checkBox2_5->setChecked(true);
    }
    if((parm[3]&0x02)==0x02)
    {
        ui->checkBox2_6->setChecked(true);
    }
    if((parm[3]&0x04)==0x04)
    {
        ui->checkBox2_7->setChecked(true);
    }
    if((parm[3]&0x08)==0x08)
    {
        ui->checkBox2_8->setChecked(true);
    }
    /////////////////////3///////////////////////////
    if((parm[4]&0x01)==0x01)
    {
        ui->checkBox3_1->setChecked(true);
    }
    if((parm[4]&0x02)==0x02)
    {
        ui->checkBox3_2->setChecked(true);
    }
    if((parm[4]&0x04)==0x04)
    {
        ui->checkBox3_3->setChecked(true);
    }
    if((parm[4]&0x08)==0x08)
    {
        ui->checkBox3_4->setChecked(true);
    }
    if((parm[5]&0x01)==0x01)
    {
        ui->checkBox3_5->setChecked(true);
    }
    if((parm[5]&0x02)==0x02)
    {
        ui->checkBox3_6->setChecked(true);
    }
    if((parm[5]&0x04)==0x04)
    {
        ui->checkBox3_7->setChecked(true);
    }
    if((parm[5]&0x08)==0x08)
    {
        ui->checkBox3_8->setChecked(true);
    }
    ////////////////4/////////////////////////////////
    if((parm[6]&0x01)==0x01)
    {
        ui->checkBox4_1->setChecked(true);
    }
    if((parm[6]&0x02)==0x02)
    {
        ui->checkBox4_2->setChecked(true);
    }
    if((parm[6]&0x04)==0x04)
    {
        ui->checkBox4_3->setChecked(true);
    }
    if((parm[6]&0x08)==0x08)
    {
        ui->checkBox4_4->setChecked(true);
    }
    if((parm[7]&0x01)==0x01)
    {
        ui->checkBox4_5->setChecked(true);
    }
    if((parm[7]&0x02)==0x02)
    {
        ui->checkBox4_6->setChecked(true);
    }
    if((parm[7]&0x04)==0x04)
    {
        ui->checkBox4_7->setChecked(true);
    }
    if((parm[7]&0x08)==0x08)
    {
        ui->checkBox4_8->setChecked(true);
    }
}
void DialogContrlParm::sendb5(){this->sendquerymsg(0xb5);}
void DialogContrlParm::sendb6(){this->sendquerymsg(0xb6);}
void DialogContrlParm::sendb7(){this->sendquerymsg(0xb7);}
void DialogContrlParm::sendb8(){this->sendquerymsg(0xb8);}
void DialogContrlParm::sendb9(){this->sendquerymsg(0xb9);}
void DialogContrlParm::sendba(){this->sendquerymsg(0xba);}
void DialogContrlParm::sendbb(){this->sendquerymsg(0xbb);}
void DialogContrlParm::sendbd(){this->sendquerymsg(0xbd);}
void DialogContrlParm::sendcd(){this->sendquerymsg(0xcd);}
void DialogContrlParm::sendquerymsg(char parm)
{
    char buffer[60];
    buffer[0]=0x02;
    buffer[1]=0x00;
    buffer[2]=0x03;
    buffer[3]=0x80;
    buffer[4]=(char)parm;
    buffer[5]=0x00;
    int len=6;
    unsigned short rssum = CommVerify((unsigned char *)buffer,len);
    buffer[len]=rssum/256;
    buffer[len+1]=rssum%256;    
    int i=0;
    for(i;i<3;i++)
    {
            if(com->WriteCom(buffer,len+2))
            {
                    qDebug()<<"81";
                    break;
            }

    }
}
void DialogContrlParm::setCountDown()
{
    unsigned char parm[8]={0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0xf0};
    if(ui->checkBox1_1->isChecked())
    {
        parm[0]=(parm[0]|0x01);
    }
    if(ui->checkBox1_2->isChecked())
    {
        parm[0]=(parm[0]|0x02);
    }
    if(ui->checkBox1_3->isChecked())
    {
        parm[0]=(parm[0]|0x04);
    }
    if(ui->checkBox1_4->isChecked())
    {
        parm[0]=(parm[0]|0x08);
    }
    if(ui->checkBox1_5->isChecked())
    {
        parm[1]=(parm[1]|0x01);
    }
    if(ui->checkBox1_6->isChecked())
    {
        parm[1]=(parm[1]|0x02);
    }
    if(ui->checkBox1_7->isChecked())
    {
        parm[1]=(parm[1]|0x04);
    }
    if(ui->checkBox1_8->isChecked())
    {
        parm[1]=(parm[1]|0x08);
    }
    ////////////////////////////////////////
    if(ui->checkBox2_1->isChecked())
    {
        parm[2]=(parm[2]|0x01);
    }
    if(ui->checkBox2_2->isChecked())
    {
        parm[2]=(parm[2]|0x02);
    }
    if(ui->checkBox2_3->isChecked())
    {
        parm[2]=(parm[2]|0x04);
    }
    if(ui->checkBox2_4->isChecked())
    {
        parm[2]=(parm[2]|0x08);
    }
    if(ui->checkBox2_5->isChecked())
    {
        parm[3]=(parm[3]|0x01);
    }
    if(ui->checkBox2_6->isChecked())
    {
        parm[3]=(parm[3]|0x02);
    }
    if(ui->checkBox2_7->isChecked())
    {
        parm[3]=(parm[3]|0x04);
    }
    if(ui->checkBox2_8->isChecked())
    {
        parm[3]=(parm[3]|0x08);
    }
    ///////////////////////////////////
    if(ui->checkBox3_1->isChecked())
    {
        parm[4]=(parm[4]|0x01);
    }
    if(ui->checkBox3_2->isChecked())
    {
        parm[4]=(parm[4]|0x02);
    }
    if(ui->checkBox3_3->isChecked())
    {
        parm[4]=(parm[4]|0x04);
    }
    if(ui->checkBox3_4->isChecked())
    {
        parm[4]=(parm[4]|0x08);
    }
    if(ui->checkBox3_5->isChecked())
    {
        parm[5]=(parm[5]|0x01);
    }
    if(ui->checkBox3_6->isChecked())
    {
        parm[5]=(parm[5]|0x02);
    }
    if(ui->checkBox3_7->isChecked())
    {
        parm[5]=(parm[5]|0x04);
    }
    if(ui->checkBox3_8->isChecked())
    {
        parm[5]=(parm[5]|0x08);
    }
    ////////////////////////////////////
    if(ui->checkBox4_1->isChecked())
    {
        parm[6]=(parm[6]|0x01);
    }
    if(ui->checkBox4_2->isChecked())
    {
        parm[6]=(parm[6]|0x02);
    }
    if(ui->checkBox4_3->isChecked())
    {
        parm[6]=(parm[6]|0x04);
    }
    if(ui->checkBox4_4->isChecked())
    {
        parm[6]=(parm[6]|0x08);
    }
    if(ui->checkBox4_5->isChecked())
    {
        parm[7]=(parm[7]|0x01);
    }
    if(ui->checkBox4_6->isChecked())
    {
        parm[7]=(parm[7]|0x02);
    }
    if(ui->checkBox4_7->isChecked())
    {
        parm[7]=(parm[7]|0x04);
    }
    if(ui->checkBox4_8->isChecked())
    {
        parm[7]=(parm[7]|0x08);
    }
    char buffer[600];
    int len;
    buffer[0]=0x02;
    buffer[1]=0x00;
    buffer[2]=0x0b;
    buffer[3]=0x81;
    buffer[4]=0xcd;
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
    com->WriteCom(buffer,len+2);
}

void DialogContrlParm::on_checkBox_stateChanged(int i)
{
    if(ui->checkBox->isChecked())
    {
        ui->checkBox1_1->setChecked(true);
        ui->checkBox1_2->setChecked(true);
        ui->checkBox1_3->setChecked(true);
        ui->checkBox1_4->setChecked(true);
        ui->checkBox1_5->setChecked(true);
        ui->checkBox1_6->setChecked(true);
        ui->checkBox1_7->setChecked(true);
        ui->checkBox1_8->setChecked(true);

        ui->checkBox2_1->setChecked(true);
        ui->checkBox2_2->setChecked(true);
        ui->checkBox2_3->setChecked(true);
        ui->checkBox2_4->setChecked(true);
        ui->checkBox2_5->setChecked(true);
        ui->checkBox2_6->setChecked(true);
        ui->checkBox2_7->setChecked(true);
        ui->checkBox2_8->setChecked(true);

        ui->checkBox3_1->setChecked(true);
        ui->checkBox3_2->setChecked(true);
        ui->checkBox3_3->setChecked(true);
        ui->checkBox3_4->setChecked(true);
        ui->checkBox3_5->setChecked(true);
        ui->checkBox3_6->setChecked(true);
        ui->checkBox3_7->setChecked(true);
        ui->checkBox3_8->setChecked(true);

        ui->checkBox4_1->setChecked(true);
        ui->checkBox4_2->setChecked(true);
        ui->checkBox4_3->setChecked(true);
        ui->checkBox4_4->setChecked(true);
        ui->checkBox4_5->setChecked(true);
        ui->checkBox4_6->setChecked(true);
        ui->checkBox4_7->setChecked(true);
        ui->checkBox4_8->setChecked(true);

    }else
    {
        ui->checkBox1_1->setChecked(false);
        ui->checkBox1_2->setChecked(false);
        ui->checkBox1_3->setChecked(false);
        ui->checkBox1_4->setChecked(false);
        ui->checkBox1_5->setChecked(false);
        ui->checkBox1_6->setChecked(false);
        ui->checkBox1_7->setChecked(false);
        ui->checkBox1_8->setChecked(false);

        ui->checkBox2_1->setChecked(false);
        ui->checkBox2_2->setChecked(false);
        ui->checkBox2_3->setChecked(false);
        ui->checkBox2_4->setChecked(false);
        ui->checkBox2_5->setChecked(false);
        ui->checkBox2_6->setChecked(false);
        ui->checkBox2_7->setChecked(false);
        ui->checkBox2_8->setChecked(false);

        ui->checkBox3_1->setChecked(false);
        ui->checkBox3_2->setChecked(false);
        ui->checkBox3_3->setChecked(false);
        ui->checkBox3_4->setChecked(false);
        ui->checkBox3_5->setChecked(false);
        ui->checkBox3_6->setChecked(false);
        ui->checkBox3_7->setChecked(false);
        ui->checkBox3_8->setChecked(false);

        ui->checkBox4_1->setChecked(false);
        ui->checkBox4_2->setChecked(false);
        ui->checkBox4_3->setChecked(false);
        ui->checkBox4_4->setChecked(false);
        ui->checkBox4_5->setChecked(false);
        ui->checkBox4_6->setChecked(false);
        ui->checkBox4_7->setChecked(false);
        ui->checkBox4_8->setChecked(false);

    }
}
