#include "dlgtimeinterval.h"
#include "ui_dlgtimeinterval.h"
#include "unit.h"
#include <QDebug>
DlgTimeInterval::DlgTimeInterval(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DlgTimeInterval)
{
    ui->setupUi(this);
    this->com=new CPubSub();
    this->revtimer=new QTimer();
    this->timeout=new QTimer();
    connect(timeout,SIGNAL(timeout()),this,SLOT(warming()));
    //this->setAttribute();
    //this->setWindowFlags(Qt::FramelessWindowHint);//把窗口设置成没框架的

      //this->setAttribute(Qt::WA_TranslucentBackground,true);//背景透明
    //this->setAttribute(Qt::WA_DeleteOnClose);

}

DlgTimeInterval::~DlgTimeInterval()
{
    delete ui;
    deleteLater();
}
void DlgTimeInterval::setcom(CPubSub *com)
{
    this->com=com;
}
void DlgTimeInterval::dealwith(uchar* rec,int len)
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

        char buffer[]={0x02,0x00,0x05 ,0x84 ,0x83 ,0x00 ,0x00 ,0x00};
        unsigned short wewewew=CommVerify((uchar*)buffer,8);
        if(crcnum!=CommVerify((uchar*)s,num+3))
        {
            s++;
            qDebug()<<"chucuo!!!!!jiaoyan!!!";
            continue;
        }
        if((uchar)*(s+3)==0x84)//查询命令处理
        {
            if((uchar)(*(s+4))==0x8e)
            {
                init8e((uchar*)s);
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
            if((uchar)(*(s+4))==0x8e)
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
            if((uchar)(*(s+4))==0x8e)
            {
                ui->display->setText(tr("设置失败!"));
            }
            if((uchar)(*(s+4))==0x79)
            {
                ui->display->setText(tr("设置失败!"));
            }
        }
        s +=(num+5);
        i += (num+4);
    }
}
void DlgTimeInterval::init8e(uchar *buffer)
{
    unsigned char parm1=*(buffer+7);
    unsigned char parm2=*(buffer+8);
    ui->spintimetab->setValue(parm1);
    qDebug()<<QString::number(parm1,10);
    ui->spineventnum->setValue(parm2);
    unsigned char parm3=*(buffer+9);
    ui->spinstarthour->setValue(parm3);
    unsigned char parm4=*(buffer+10);
    ui->spinstartminite->setValue(parm4);
    unsigned char parm5=*(buffer+11);
    unsigned char parm6=*(buffer+12);
    unsigned char parm7=*(buffer+13);     //这里是辉度控制，没需求要写！！！！
    unsigned char parm8=*(buffer+14);
    if((parm3==0xff)&&(parm4==0xff)&&(parm5==0xff))
    {
        ui->radioButton->setChecked(true);
        ui->spinstarthour->clear();
        ui->spinstartminite->clear();
    }
    else{

            if(parm5!=0xff)
            {
                if(parm5==0x00)
                    ui->radionum0->setChecked(true);
                if(parm5==0x01)
                    ui->radionum1->setChecked(true);
                if(parm5==0x02)
                    ui->radionum2->setChecked(true);
                if(parm5==0x03)
                    ui->radionum3->setChecked(true);
                if(parm5==0x06)
                    ui->radionum6->setChecked(true);
                if(parm5==0x08)
                    ui->radionum8->setChecked(true);
                if(parm5==0x0b)
                    ui->radionum11->setChecked(true);
                if(parm5==0x0c)
                    ui->radionum12->setChecked(true);
                if(parm5==0x0d)
                    ui->radionum13->setChecked(true);
            }
    }
    if(parm6==0xff)
        ui->spintimingnum->clear();
    else
        ui->spintimingnum->setValue(parm6);
    if(parm8!=0xff)
    {
    }
}
void DlgTimeInterval::rev()
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
void DlgTimeInterval::warming()
{
    ui->display->setText(tr("失败!请重试!"));
}
void DlgTimeInterval::send8e()
{
    unsigned char tabnum=ui->spintimetab->value();
    unsigned char eventnum=ui->spineventnum->value();
    unsigned char value=(tabnum-1)*16+eventnum;
    char buffer[60];
    buffer[0]=0x02;
    buffer[1]=0x00;
    buffer[2]=0x04;
    buffer[3]=0x80;
    buffer[4]=0x8e;
    buffer[5]=0x40;
    buffer[6]=value;
    int len=7;
    unsigned short rssum = CommVerify((unsigned char *)buffer,len);
    buffer[len]=rssum/256;
    buffer[len+1]=rssum%256;
    com->WriteCom(buffer,len+2);

}
void DlgTimeInterval::set8e()
{
    unsigned char parm0=0x00;
    unsigned char parm1=0x00;
    unsigned char parm2=0x00;
    unsigned char parm3=0x00;
    unsigned char parm4=0x00;
    unsigned char parm5=0x00;
    char buffer[10];
    parm0=(unsigned char)ui->spinstarthour->value();
    parm1=(unsigned char)ui->spinstartminite->value();
    if(ui->radionum0->isChecked()|
            ui->radionum1->isChecked()|
            ui->radionum2->isChecked()|
            ui->radionum3->isChecked()|
            ui->radionum6->isChecked()|
            ui->radionum8->isChecked()|
            ui->radionum11->isChecked()|
            ui->radionum12->isChecked()|
            ui->radionum13->isChecked()){
    if(ui->radionum0->isChecked())
        parm2=0x00;
    if(ui->radionum1->isChecked())
        parm2=0x01;
    if(ui->radionum2->isChecked())
        parm2=0x02;
    if(ui->radionum3->isChecked())
        parm2=0x03;
    if(ui->radionum6->isChecked())
        parm2=0x06;
    if(ui->radionum8->isChecked())
        parm2=0x08;
    if(ui->radionum11->isChecked())
        parm2=0x0b;
    if(ui->radionum12->isChecked())
        parm2=0x0c;
    if(ui->radionum13->isChecked())
        parm2=0x0d;
    }else{
        parm2=0xff;
    }
    parm3=(unsigned char)ui->spintimingnum->value();
    parm4=0xff;//辅助功能输出！！
    parm5=0xff;
    char value=(((unsigned char)ui->spintimetab->value()-1)*16)+(unsigned char)(ui->spineventnum->value());
    buffer[0]=0x02;
    buffer[1]=0x00;
    buffer[2]=0x0c;
    buffer[3]=0x81;
    buffer[4]=0x8e;
    buffer[5]=0x40;
    buffer[6]=value;
    buffer[7]=(unsigned char)ui->spintimetab->value();
    buffer[8]=(unsigned char)(ui->spineventnum->value());
    buffer[9]=parm0;
    buffer[10]=parm1;
    buffer[11]=parm2;
    buffer[12]=parm3;
    buffer[13]=parm4;
    buffer[14]=parm5;
    int len=15;
    unsigned short rssum = CommVerify((unsigned char *)buffer,len);
    buffer[len]=rssum/256;
    buffer[len+1]=rssum%256;
    com->WriteCom(buffer,len+2);
}
void DlgTimeInterval::on_butfind_clicked()
{
        ui->display->setText(tr("查询中......"));
        ui->spinstarthour->clear();
        ui->spinstartminite->clear();
        ui->spintimingnum->clear();
        ui->radioButton->setChecked(true);
        ui->butok->setVisible(true);
        ui->butclear->setVisible(true);
        ui->clearall->setVisible(true);
        ui->spintimingnum->clear();
        ui->radionum0->setChecked(false);
        ui->radionum1->setChecked(false);
        ui->radionum2->setChecked(false);
        ui->radionum3->setChecked(false);
        ui->radionum6->setChecked(false);
        ui->radionum11->setChecked(false);
        ui->radionum12->setChecked(false);
        ui->radionum13->setChecked(false);
        ui->radionum8->setChecked(false);
        QTimer::singleShot(1,this,SLOT(send8e()));
        revtimer->start(200);
        connect(revtimer,SIGNAL(timeout()),this,SLOT(rev()));
        timeout->start(1000);
}
void DlgTimeInterval::on_butok_clicked()
{
    ui->display->clear();
    QTimer::singleShot(1,this,SLOT(set8e()));
    timeout->start(1000);
}

void DlgTimeInterval::on_butclear_clicked()
{
    unsigned char  parm1=ui->spintimetab->value();
    unsigned char  parm2=ui->spineventnum->value();
    char buffer[600];
    buffer[0]=0x02;
    buffer[1]=0x00;
    buffer[2]=0x0c;
    buffer[3]=0x81;
    buffer[4]=0x8e;
    buffer[5]=0x40;
    buffer[6]=(((parm1-1)*16)+parm2);
    buffer[7]=parm1;
    buffer[8]=parm2;
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
    com->WriteCom(buffer,len+2);
}

void DlgTimeInterval::on_query_clicked()
{
    ui->display->clear();
    ui->hang->clear();
    revtimer->stop();
    char buffer[60];
    buffer[0]=0x02;
    buffer[1]=0x00;
    buffer[2]=0x04;
    buffer[3]=0x80;
    buffer[4]=0x79;
    buffer[5]=0x00;
    buffer[6]=0x8e;
    int len=7;
    unsigned short rssum=CommVerify((unsigned char*)buffer,len);
    buffer[len]=rssum/256;
    buffer[len+1]=rssum%256;
    this->com->WriteCom(buffer,len+2);
    revtimer->start(20);
    connect(revtimer,SIGNAL(timeout()),this,SLOT(rev()));
    timeout->start(1000);
}

void DlgTimeInterval::on_clearall_clicked()
{
    ui->hang->clear();
    ui->display->clear();
    char buffer[60];
    buffer[0]=0x02;
    buffer[1]=0x00;
    buffer[2]=0x04;
    buffer[3]=0x81;
    buffer[4]=0x79;
    buffer[5]=0x00;
    buffer[6]=0x8e;
    int len=7;
    unsigned short rssum=CommVerify((unsigned char *)buffer,len);
    buffer[len]=rssum/256;
    buffer[len+1]=rssum%256;
    this->com->WriteCom(buffer,len+2);
    timeout->start(1000);
}
