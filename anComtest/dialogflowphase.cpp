#include "dialogflowphase.h"
#include "ui_dialogflowphase.h"
#include "unit.h"
#include <QDebug>
DialogFlowPhase::DialogFlowPhase(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogFlowPhase)
{
    ui->setupUi(this);
    this->com=new CPubSub();
    this->revtimer=new QTimer();
    this->timeout=new QTimer();
    connect(timeout,SIGNAL(timeout()),this,SLOT(warming()));
}

DialogFlowPhase::~DialogFlowPhase()
{
    delete ui;
    deleteLater();
}
void DialogFlowPhase::setcom(CPubSub *com)
{
    this->com=com;
}
void DialogFlowPhase::dealwith(uchar* rec,int len)
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
            if((uchar)(*(s+4))==0xc8)
            {
                initc8((uchar*)s);
                ui->display->setText(tr("查询成功!"));
                timeout->stop();
            }
            if((uchar)(*(s+4))==0x79)
            {
                 ui->hang->setText(QString::number(*(s+6),10));
                ui->display->setText(tr("查询成功!"));
                timeout->stop();
            }
        }
        if((uchar)*(s+3)==0x85)//设置成功命令
        {
            if((uchar)(*(s+4))==0xc8)
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
            if((uchar)(*(s+4))==0xc8)
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

void DialogFlowPhase::initc8(uchar *buffer)
{
    uchar parm1=buffer[8];

    uchar parm2=buffer[10];
    uchar parm3=buffer[9];

    uchar parm4=buffer[12];
    uchar parm5=buffer[11];

    uchar parm6=buffer[13];
    uchar parm7=buffer[14];
    uchar parm8=buffer[15];

    if(parm1!=0xff)
    {
        if(parm1==0x01)
            ui->radioother->setChecked(true);
        if(parm1==0x02)
            ui->radionormal->setChecked(true);
        if(parm1==0x03)
            ui->radiomin->setChecked(true);
        if((parm1!=0x01)&&(parm1!=0x02)&&(parm1!=0x03))
            ui->radioButton->setChecked(true);
    }
    else
    {
        ui->radioButton->setChecked(true);
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

            if((parm4&0x01)==0x01)
                ui->xiu->setChecked(true);
            if((parm4&0x02)==0x02)
                ui->xiu_2->setChecked(true);
            if((parm4&0x04)==0x04)
                ui->xiu_3->setChecked(true);
            if((parm4&0x08)==0x08)
                ui->xiu_4->setChecked(true);
            if((parm4&0x10)==0x10)
                ui->xiu_5->setChecked(true);
            if((parm4&0x20)==0x20)
                ui->xiu_6->setChecked(true);
            if((parm4&0x40)==0x40)
                ui->xiu_7->setChecked(true);
            if((parm4&0x80)==0x80)
                ui->xiu_8->setChecked(true);

            if((parm5&0x01)==0x01)
                ui->xiu_9->setChecked(true);
            if((parm5&0x02)==0x02)
                ui->xiu_10->setChecked(true);
            if((parm5&0x04)==0x04)
                ui->xiu_11->setChecked(true);
            if((parm5&0x08)==0x08)
                ui->xiu_12->setChecked(true);
            if((parm5&0x10)==0x10)
                ui->xiu_13->setChecked(true);
            if((parm5&0x20)==0x20)
                ui->xiu_14->setChecked(true);
            if((parm5&0x40)==0x40)
                ui->xiu_15->setChecked(true);
            if((parm5&0x80)==0x80)
                ui->xiu_16->setChecked(true);


        if(parm6!=0xff)
        {
            ui->spinBoxg->setValue(parm6);
        }
        else
        {
            ui->spinBoxg->clear();
        }

        if(parm7!=0xff)
        {
            ui->spinBoxr->setValue(parm7);
        }
        else
        {
            ui->spinBoxr->clear();
        }

        if(parm8!=0xff)
        {
            ui->spinBoxy->setValue(parm8);
        }
        else
        {
            ui->spinBoxy->clear();
        }
}


void DialogFlowPhase::rev()
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
void DialogFlowPhase::warming()
{
    ui->display->clear();
    ui->display->setText(tr("失败!请重试!"));
}
void DialogFlowPhase::sendc8()
{
    char index=ui->spinBoxnumber->value();
    char buffer[60];
    buffer[0]=0x02;
    buffer[1]=0x00;
    buffer[2]=0x04;
    buffer[3]=0x80;
    buffer[4]=0xc8;
    buffer[5]=0x40;
    buffer[6]=index;
    int len=7;
    unsigned short rssum=CommVerify((unsigned char *)buffer,len);
    buffer[len]=rssum/256;
    buffer[len+1]=rssum%256;
    this->com->WriteCom(buffer,len+2);
}
void DialogFlowPhase::setc8()
{
    uchar parm1=0x00;

    uchar parm2=0x00;
    uchar parm3=0x00;

    uchar parm4=0x00;
    uchar parm5=0x00;

    uchar parm6=0x00;
    uchar parm7=0x00;
    uchar parm8=0x00;

    if(ui->radioButton->isChecked())
        parm1=0xff;
    if(ui->radioother->isChecked())
        parm1=0x01;
    if(ui->radionormal->isChecked())
        parm1=0x02;
    if(ui->radiomin->isChecked())
        parm1=0x03;

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


    if(ui->xiu->isChecked())
        parm4=(parm4|0x01);
    if(ui->xiu_2->isChecked())
        parm4=(parm4|0x02);
    if(ui->xiu_3->isChecked())
        parm4=(parm4|0x04);
    if(ui->xiu_4->isChecked())
        parm4=(parm4|0x08);
    if(ui->xiu_5->isChecked())
        parm4=(parm4|0x10);
    if(ui->xiu_6->isChecked())
        parm4=(parm4|0x20);
    if(ui->xiu_7->isChecked())
        parm4=(parm4|0x40);
    if(ui->xiu_8->isChecked())
        parm4=(parm4|0x80);


    if(ui->xiu_9->isChecked())
        parm5=(parm5|0x01);
    if(ui->xiu_10->isChecked())
        parm5=(parm5|0x02);
    if(ui->xiu_11->isChecked())
        parm5=(parm5|0x04);
    if(ui->xiu_12->isChecked())
        parm5=(parm5|0x08);
    if(ui->xiu_13->isChecked())
        parm5=(parm5|0x10);
    if(ui->xiu_14->isChecked())
        parm5=(parm5|0x20);
    if(ui->xiu_15->isChecked())
        parm5=(parm5|0x40);
    if(ui->xiu_16->isChecked())
        parm5=(parm5|0x80);


    parm6=ui->spinBoxg->value();
    parm7=ui->spinBoxr->value();
    parm8=ui->spinBoxy->value();

    uchar value=ui->spinBoxnumber->value();
    char buffer[60];
    buffer[0]=0x02;
    buffer[1]=0x00;
    buffer[2]=0x0d;
    buffer[3]=0x81;
    buffer[4]=0xc8;
    buffer[5]=0x40;
    buffer[6]=value;
    buffer[7]=value;
    buffer[8]=parm1;
    buffer[9]=parm3;
    buffer[10]=parm2;
    buffer[11]=parm5;
    buffer[12]=parm4;
    buffer[13]=parm6;
    buffer[14]=parm7;
    buffer[15]=parm8;

    int len=16;
    unsigned short rssum=CommVerify((unsigned char *)buffer,len);
    buffer[len]=rssum/256;
    buffer[len+1]=rssum%256;
    this->com->WriteCom(buffer,len+2);

}


void DialogFlowPhase::on_butfind_clicked()
{
    ui->spinBoxg->clear();
    ui->spinBoxr->clear();
    ui->spinBoxy->clear();

    ui->radioButton->setChecked(true);

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

    ui->xiu->setChecked(false);
    ui->xiu_2->setChecked(false);
    ui->xiu_3->setChecked(false);
    ui->xiu_4->setChecked(false);
    ui->xiu_5->setChecked(false);
    ui->xiu_6->setChecked(false);
    ui->xiu_7->setChecked(false);
    ui->xiu_8->setChecked(false);
    ui->xiu_9->setChecked(false);
    ui->xiu_10->setChecked(false);
    ui->xiu_11->setChecked(false);
    ui->xiu_12->setChecked(false);
    ui->xiu_13->setChecked(false);
    ui->xiu_14->setChecked(false);
    ui->xiu_15->setChecked(false);
    ui->xiu_16->setChecked(false);

    ui->display->clear();
    ui->display->setText(tr("查询中......"));
    QTimer::singleShot(1,this,SLOT(sendc8()));
    revtimer->start(100);
    connect(revtimer,SIGNAL(timeout()),this,SLOT(rev()));
    timeout->start(3000);

}


void DialogFlowPhase::on_butset_clicked()
{
    ui->display->clear();
    QTimer::singleShot(1,this,SLOT(setc8()));
    revtimer->start(100);
    connect(revtimer,SIGNAL(timeout()),this,SLOT(rev()));
    timeout->start(3000);
}

void DialogFlowPhase::on_butcleaer_clicked()
{
    uchar value=ui->spinBoxnumber->value();
    char buffer[60];
    buffer[0]=0x02;
    buffer[1]=0x00;
    buffer[2]=0x0d;
    buffer[3]=0x81;
    buffer[4]=0xc8;
    buffer[5]=0x40;
    buffer[6]=value;
    buffer[7]=value;
    buffer[8]=0xff;
    buffer[9]=0xff;
    buffer[10]=0xff;
    buffer[11]=0xff;
    buffer[12]=0xff;
    buffer[13]=0xff;
    buffer[14]=0xff;
    buffer[15]=0xff;

    int len=16;
    unsigned short rssum=CommVerify((unsigned char *)buffer,len);
    buffer[len]=rssum/256;
    buffer[len+1]=rssum%256;
    this->com->WriteCom(buffer,len+2);
    timeout->start(3000);
}

void DialogFlowPhase::on_butquery_clicked()
{
    char buffer[60];
    buffer[0]=0x02;
    buffer[1]=0x00;
    buffer[2]=0x04;
    buffer[3]=0x80;
    buffer[4]=0x79;
    buffer[5]=0x00;
    buffer[6]=0xc8;
    int len=7;
    unsigned short rssum=CommVerify((unsigned char *)buffer,len);
    buffer[len]=rssum/256;
    buffer[len+1]=rssum%256;
    this->com->WriteCom(buffer,len+2);
    revtimer->start(20);
    connect(revtimer,SIGNAL(timeout()),this,SLOT(rev()));
    timeout->start(3000);
}

void DialogFlowPhase::on_butclearall_clicked()
{
    char buffer[60];
    buffer[0]=0x02;
    buffer[1]=0x00;
    buffer[2]=0x04;
    buffer[3]=0x81;
    buffer[4]=0x79;
    buffer[5]=0x00;
    buffer[6]=0xc8;
    int len=7;
    unsigned short rssum=CommVerify((unsigned char *)buffer,len);
    buffer[len]=rssum/256;
    buffer[len+1]=rssum%256;
    this->com->WriteCom(buffer,len+2);
    revtimer->start(20);
    connect(revtimer,SIGNAL(timeout()),this,SLOT(rev()));
    timeout->start(3000);
}
