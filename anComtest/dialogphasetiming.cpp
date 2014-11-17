#include "dialogphasetiming.h"
#include "ui_dialogphasetiming.h"
#include "unit.h"
#include <QDebug>
DialogPhaseTiming::DialogPhaseTiming(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogPhaseTiming)
{
    ui->setupUi(this);
    ui->setupUi(this);
    this->com=new CPubSub();
    this->revtimer=new QTimer();
    this->timeout=new QTimer();
    connect(timeout,SIGNAL(timeout()),this,SLOT(warming()));
    connect(ui->butfind,SIGNAL(clicked()),this,SLOT(on_butfind_clicked()));
    connect(ui->butok,SIGNAL(clicked()),this,SLOT(on_butok_clicked()));
    connect(ui->butquery,SIGNAL(clicked()),this,SLOT(on_butquery_clicked()));
    connect(ui->butclearall,SIGNAL(clicked()),this,SLOT(on_butclearall_clicked()));
    connect(ui->butclear,SIGNAL(clicked()),this,SLOT(on_butclear_clicked()));
}

DialogPhaseTiming::~DialogPhaseTiming()
{
    delete ui;
    deleteLater();
}
void DialogPhaseTiming::setcom(CPubSub *com)
{
    this->com=com;
}

void DialogPhaseTiming::dealwith(uchar* rec,int len)
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

            if((uchar)(*(s+4))==0xc1)
            {

                initPhaseTiming((uchar*)s);
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
            if((uchar)(*(s+4))==0xc1)
            {
                ui->display->setText(tr("设置成功!!!"));
                timeout->stop();
            }
            if((uchar)(*(s+4))==0x79)
            {
                ui->display->setText(tr("清空成功!!!"));
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

void DialogPhaseTiming::initPhaseTiming(unsigned char *buffer)
{
    unsigned char parm1=*(buffer+7);//阶段配时方案号
    unsigned char parm2=*(buffer+8);//阶段号
    unsigned char parm4=*(buffer+9);//放行相位
    unsigned char parm3=*(buffer+10);//
    unsigned char parm5=*(buffer+11);//阶段绿灯时间
    unsigned char parm6=*(buffer+12);//阶段黄灯时间
    unsigned char parm7=*(buffer+13);//阶段红灯时间
    unsigned char parm8=*(buffer+14);//阶段选项参数
    ui->spinBoxplannum->setValue(parm1);
    qDebug()<<QString::number(parm2,10);
    if(parm2!=0xff)
    {
    ui->spinnum->setValue(parm2);
    }
    //if(parm3!=0xff)
    {
       if((parm3&0x01)==0x01)
           ui->phase1->setChecked(true);
       if((parm3&0x02)==0x02)
           ui->phase2->setChecked(true);
       if((parm3&0x04)==0x04)
           ui->phase3->setChecked(true);
       if((parm3&0x08)==0x08)
           ui->phase4->setChecked(true);
       if((parm3&0x10)==0x10)
           ui->phase5->setChecked(true);
       if((parm3&0x20)==0x20)
           ui->phase6->setChecked(true);
       if((parm3&0x40)==0x40)
           ui->phase7->setChecked(true);
       if((parm3&0x80)==0x80)
           ui->phase8->setChecked(true);
    }
    //if(parm4!=0xff)
    {
       if((parm4&0x01)==0x01)
           ui->phase9->setChecked(true);
       if((parm4&0x02)==0x02)
           ui->phase10->setChecked(true);
       if((parm4&0x04)==0x04)
           ui->phase11->setChecked(true);
       if((parm4&0x08)==0x08)
           ui->phase12->setChecked(true);
       if((parm4&0x10)==0x10)
           ui->phase13->setChecked(true);
       if((parm4&0x20)==0x20)
           ui->phase14->setChecked(true);
       if((parm4&0x40)==0x40)
           ui->phase15->setChecked(true);
       if((parm4&0x80)==0x80)
           ui->phase16->setChecked(true);
    }
    if(parm5!=0xff)
    ui->spinblue->setValue(parm5);
    if((parm6!=0xff)&parm6<17)
    {
       ui->spinyellow->setValue(parm6);
    }
    if((parm7!=0xff)&parm7<17)
    {
       ui->spinred->setValue(parm7);
    }
    if(parm8!=0xff)
    {
       if((parm8&0x01)==0x01)
           ui->checkisparm->setChecked(true);
    }
}

void DialogPhaseTiming::rev()
{
    qDebug()<<"~~~~~~~~~~~~~~~~~~";
    char RecBuf[4096];
    memset(RecBuf,NULL,4096);
    QString RecText;
    int Rlen;
    if(com->isopen())
    {
        Rlen=com->GetDataLen();
        if(Rlen>0&&(Rlen==17|Rlen==8|Rlen==9))
        {
            com->ReadCom(RecBuf,Rlen);
            for(int i=0;i<Rlen;i++)
            {
                    RecText.append(QString::number((uchar)RecBuf[i],16));
                    RecText.append("|");
            }
            dealwith((uchar*)RecBuf,Rlen);
        }
    }
}

void DialogPhaseTiming::warming()
{
    ui->display->clear();
    ui->display->setText(tr("失败!请重试!"));
}

void DialogPhaseTiming::sendPhaseTiming()
{
    char parm=(((char)(ui->spinBoxplannum->value()))-1)*16+((char)(ui->spinnum->value()));
    char buffer[60];
    buffer[0]=0x02;
    buffer[1]=0x00;
    buffer[2]=0x04;
    buffer[3]=0x80;
    buffer[4]=0xc1;
    buffer[5]=0x40;
    buffer[6]=parm;
    int len=7;
    unsigned short rssum=CommVerify((unsigned char *)buffer,len);
    buffer[len]=rssum/256;
    buffer[len+1]=rssum%256;
    this->com->WriteCom(buffer,len+2);
}

void DialogPhaseTiming::setPhaseTiming()
{
    char parm[8]={0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
    parm[0]=(char)ui->spinBoxplannum->value();
    parm[1]=(char)ui->spinnum->value();
    char value=(parm[0]-1)*16+parm[1];

       if(ui->phase1->isChecked())
           parm[2]=parm[2]|0x01;
       if(ui->phase2->isChecked())
           parm[2]=parm[2]|0x02;
       if(ui->phase3->isChecked())
           parm[2]=parm[2]|0x04;
       if(ui->phase4->isChecked())
           parm[2]=parm[2]|0x08;
       if(ui->phase5->isChecked())
           parm[2]=parm[2]|0x10;
       if(ui->phase6->isChecked())
           parm[2]=parm[2]|0x20;
       if(ui->phase7->isChecked())
           parm[2]=parm[2]|0x40;
       if(ui->phase8->isChecked())
           parm[2]=parm[2]|0x80;


       if(ui->phase9->isChecked())
           parm[3]=parm[3]|0x01;
       if(ui->phase10->isChecked())
           parm[3]=parm[3]|0x02;
       if(ui->phase11->isChecked())
           parm[3]=parm[3]|0x04;
       if(ui->phase12->isChecked())
           parm[3]=parm[3]|0x08;
       if(ui->phase13->isChecked())
           parm[3]=parm[3]|0x10;
       if(ui->phase14->isChecked())
           parm[3]=parm[3]|0x20;
       if(ui->phase15->isChecked())
           parm[3]=parm[3]|0x40;
       if(ui->phase16->isChecked())
           parm[3]=parm[3]|0x80;

    parm[4]=(char)ui->spinblue->value();
    parm[5]=(char)ui->spinyellow->value();
    parm[6]=(char)ui->spinred->value();
    if(ui->checkisparm->isChecked())
    {
       parm[7]=parm[7]|0x01;
    }
    else{
       parm[7]=0x00;
    }
    char buffer[50];
    buffer[0]=0x02;
    buffer[1]=0x00;
    buffer[2]=0x0c;
    buffer[3]=0x81;
    buffer[4]=0xc1;
    buffer[5]=0x40;
    buffer[6]=value;
    buffer[7]=parm[0];
    buffer[8]=parm[1];
    buffer[9]=parm[3];
    buffer[10]=parm[2];
    buffer[11]=parm[4];
    buffer[12]=parm[5];
    buffer[13]=parm[6];
    buffer[14]=parm[7];
    int len=15;
    unsigned short rssum = CommVerify((unsigned char *)buffer,len);
    buffer[len]=rssum/256;
    buffer[len+1]=rssum%256;
    this->com->WriteCom(buffer,len+2);
}

void DialogPhaseTiming::on_butfind_clicked()
{
    ui->spinblue->clear();
    //ui->spinnum->clear();
    ui->spinred->clear();
    ui->spinyellow->clear();
    ui->checkisparm->setChecked(false);
    ui->phase1->setChecked(false);
    ui->phase2->setChecked(false);
    ui->phase3->setChecked(false);
    ui->phase4->setChecked(false);
    ui->phase5->setChecked(false);
    ui->phase6->setChecked(false);
    ui->phase7->setChecked(false);
    ui->phase8->setChecked(false);
    ui->phase9->setChecked(false);
    ui->phase10->setChecked(false);
    ui->phase11->setChecked(false);
    ui->phase12->setChecked(false);
    ui->phase13->setChecked(false);
    ui->phase14->setChecked(false);
    ui->phase15->setChecked(false);
    ui->phase16->setChecked(false);
    ui->display->setText(tr("查询中......"));
    QTimer::singleShot(1,this,SLOT(sendPhaseTiming()));
    revtimer->start(200);
    connect(revtimer,SIGNAL(timeout()),this,SLOT(rev()));
    timeout->start(5000);
}
void DialogPhaseTiming::on_butok_clicked()
{
    ui->display->clear();
    QTimer::singleShot(1,this,SLOT(setPhaseTiming()));
    revtimer->start(20);
    connect(revtimer,SIGNAL(timeout()),this,SLOT(rev()));
    timeout->start(5000);
}
void DialogPhaseTiming::on_butquery_clicked()
{
    char buffer[60];
    buffer[0]=0x02;
    buffer[1]=0x00;
    buffer[2]=0x04;
    buffer[3]=0x80;
    buffer[4]=0x79;
    buffer[5]=0x00;
    buffer[6]=0xc1;
    int len=7;
    unsigned short rssum=CommVerify((unsigned char *)buffer,len);
    buffer[len]=rssum/256;
    buffer[len+1]=rssum%256;
    this->com->WriteCom(buffer,len+2);
    ui->display->setText(tr("查询中......"));
    revtimer->start(20);
    connect(revtimer,SIGNAL(timeout()),this,SLOT(rev()));
    timeout->start(5000);
}
void DialogPhaseTiming::on_butclearall_clicked()
{
    char buffer[60];
    buffer[0]=0x02;
    buffer[1]=0x00;
    buffer[2]=0x04;
    buffer[3]=0x81;
    buffer[4]=0x79;
    buffer[5]=0x00;
    buffer[6]=0xc1;
    int len=7;
    unsigned short rssum=CommVerify((unsigned char *)buffer,len);
    buffer[len]=rssum/256;
    buffer[len+1]=rssum%256;
    this->com->WriteCom(buffer,len+2);
    revtimer->start(20);
    connect(revtimer,SIGNAL(timeout()),this,SLOT(rev()));
    timeout->start(5000);
}

void DialogPhaseTiming::on_butclear_clicked()
{
    ui->display->clear();
    char parm[8]={0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
    parm[0]=(char)ui->spinBoxplannum->value();
    parm[1]=(char)ui->spinnum->value();
    char value=(parm[0]-1)*16+parm[1];
    char buffer[50];
    buffer[0]=0x02;
    buffer[1]=0x00;
    buffer[2]=0x0c;
    buffer[3]=0x81;
    buffer[4]=0xc1;
    buffer[5]=0x40;
    buffer[6]=value;
    buffer[7]=parm[0];
    buffer[8]=parm[1];
    buffer[9]=0xff;
    buffer[10]=0xff;
    buffer[11]=0xff;
    buffer[12]=0xff;
    buffer[13]=0xff;
    buffer[14]=0xff;
    int len=15;
    unsigned short rssum = CommVerify((unsigned char *)buffer,len);
    buffer[len]=rssum/256;
    buffer[len+1]=rssum%256;
    this->com->WriteCom(buffer,len+2);
    revtimer->start(20);
    connect(revtimer,SIGNAL(timeout()),this,SLOT(rev()));
    timeout->start(5000);
}
