#include "dlgtimebase.h"
#include "ui_dlgtimebase.h"
#include "unit.h"
#include <QDebug>
DlgTimeBase::DlgTimeBase(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DlgTimeBase)
{
    ui->setupUi(this);
    this->com=new CPubSub();
    this->revtimer=new QTimer();
    this->timeout=new QTimer();
    connect(timeout,SIGNAL(timeout()),this,SLOT(warming()));
}

DlgTimeBase::~DlgTimeBase()
{
    delete ui;    
    deleteLater();
//    delete revtimer;
//    delete timeout;
}
void DlgTimeBase::setcom(CPubSub *com)
{
    this->com=com;
}
void DlgTimeBase::rev()
{
    qDebug()<<"~~~~~~~~~~~~~~~~~~";
    char RecBuf[4096];
    memset(RecBuf,NULL,4096);
    QString RecText;
    int Rlen;
    if(com->isopen())
    {
            Rlen=com->GetDataLen();
            if(Rlen>0&&(Rlen==18|Rlen==9|Rlen==8))
            {
                com->ReadCom(RecBuf,Rlen);
                for(int i=0;i<Rlen;i++)
                {

                        RecText.append(QString::number((uchar)RecBuf[i],16));
                        RecText.append("|");
                }
                //ui->textEdit->setText(RecText);
                //SetDlgItemText(IDC_DISP,"接收成功!");
                //ui->display->setText(tr("接收成功!总数为:")+QString::number(Rlen,10));
            }

            dealwith((uchar*)RecBuf,Rlen);

    }
}

void DlgTimeBase::dealwith(uchar* rec,int len)
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
            if((uchar)(*(s+4))==0x8d)
            {
                init8d((uchar*)s);
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
            if((uchar)(*(s+4))==0x8d)
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
        s +=(num+5);
        i += (num+4);
    }
}

void DlgTimeBase::warming()
{
    ui->display->clear();
    ui->display->setText(tr("失败!请重试!"));
}
void DlgTimeBase::on_butfind_clicked()
{
    ui->display->setText(tr("查询中......"));
    ui->cm1_1->setChecked(false);
    ui->cm1_2->setChecked(false);
    ui->cm1_3->setChecked(false);
    ui->cm1_4->setChecked(false);
    ui->cm1_5->setChecked(false);
    ui->cm1_6->setChecked(false);
    ui->cm1_7->setChecked(false);
    ui->cm1_8->setChecked(false);
    ui->cm1_9->setChecked(false);
    ui->cm1_10->setChecked(false);
    ui->cm1_11->setChecked(false);
    ui->cm1_12->setChecked(false);

    ui->cw1_1->setChecked(false);
    ui->cw1_2->setChecked(false);
    ui->cw1_3->setChecked(false);
    ui->cw1_4->setChecked(false);
    ui->cw1_5->setChecked(false);
    ui->cw1_6->setChecked(false);
    ui->cw1_7->setChecked(false);

    ui->cd1_1->setChecked(false);
    ui->cd1_2->setChecked(false);
    ui->cd1_3->setChecked(false);
    ui->cd1_4->setChecked(false);
    ui->cd1_5->setChecked(false);
    ui->cd1_6->setChecked(false);
    ui->cd1_7->setChecked(false);
    ui->cd1_8->setChecked(false);
    ui->cd1_9->setChecked(false);
    ui->cd1_10->setChecked(false);
    ui->cd1_11->setChecked(false);
    ui->cd1_12->setChecked(false);
    ui->cd1_13->setChecked(false);
    ui->cd1_14->setChecked(false);
    ui->cd1_15->setChecked(false);
    ui->cd1_16->setChecked(false);
    ui->cd1_17->setChecked(false);
    ui->cd1_18->setChecked(false);
    ui->cd1_19->setChecked(false);
    ui->cd1_20->setChecked(false);
    ui->cd1_21->setChecked(false);
    ui->cd1_22->setChecked(false);
    ui->cd1_23->setChecked(false);
    ui->cd1_24->setChecked(false);
    ui->cd1_25->setChecked(false);
    ui->cd1_26->setChecked(false);
    ui->cd1_27->setChecked(false);
    ui->cd1_28->setChecked(false);
    ui->cd1_29->setChecked(false);
    ui->cd1_30->setChecked(false);
    ui->cd1_31->setChecked(false);

    send8d();
    revtimer->start(20);
    connect(revtimer,SIGNAL(timeout()),this,SLOT(rev()));
    timeout->start(3000);
}
void DlgTimeBase::on_butset_clicked()
{
    ui->display->clear();
    set8d();
    timeout->start();
}
void DlgTimeBase::init8d(uchar *buffer)
{
    ui->spinNumber->setValue(buffer[7]);
    unsigned char value1=buffer[9];// buffer[8];
    unsigned char value2=buffer[8];// buffer[9];

    unsigned char value3= buffer[10];//??

    unsigned char value4= buffer[14];//buffer[11];
    unsigned char value5= buffer[13];//buffer[12];    ??
    unsigned char value6= buffer[12];//buffer[13];    ??
    unsigned char value7= buffer[11];//buffer[14];

    unsigned char value8= buffer[15];
    qDebug()<<"7"+QString::number((unsigned char)buffer[7],16);
    qDebug()<<"8"+QString::number((unsigned char)buffer[8],16);
    qDebug()<<"9"+QString::number((unsigned char)buffer[9],16);
    qDebug()<<"10"+QString::number((unsigned char)buffer[10],16);
    qDebug()<<"11"+QString::number((unsigned char)buffer[11],16);
    qDebug()<<"12"+QString::number((unsigned char)buffer[12],16);
    qDebug()<<"13"+QString::number((unsigned char)buffer[13],16);
    qDebug()<<"14"+QString::number((unsigned char)buffer[14],16);
    qDebug()<<"15"+QString::number((unsigned char)buffer[15],16);
    if(value8==0xff)
      ui->spinTimeTab->clear();
    else
      ui->spinTimeTab->setValue(value8);

 /////////////////yue//////////////////////////
    if((value1!=0xff)||(value2!=0xff))
    {
      if((value1&0x01)==0x01)
          ui->cm1_1->setChecked(true);
      if((value1&0x02)==0x02)
          ui->cm1_2->setChecked(true);
      if((value1&0x04)==0x04){
          ui->cm1_3->setChecked(true);
      }
      if((value1&0x08)==0x08)
          ui->cm1_4->setChecked(true);
      if((value1&0x10)==0x10){
          ui->cm1_5->setChecked(true);
      }
      if((value1&0x20)==0x20)
          ui->cm1_6->setChecked(true);
      if((value1&0x40)==0x40){
          ui->cm1_7->setChecked(true);
      }
      if((value1&0x80)==0x80)
          ui->cm1_8->setChecked(true);


      if((value2&0x01)==0x01){
          ui->cm1_9->setChecked(true);
      }
      if((value2&0x02)==0x02)
          ui->cm1_10->setChecked(true);
      if((value2&0x04)==0x04){
          ui->cm1_11->setChecked(true);
      }
      if((value2&0x08)==0x08)
          ui->cm1_12->setChecked(true);
    }
    if(value3!=0xff)
    {
          if((value3&0x01)==0x01)
              ui->cw1_1->setChecked(true);
          if((value3&0x02)==0x02)
              ui->cw1_2->setChecked(true);
          if((value3&0x04)==0x04)
              ui->cw1_3->setChecked(true);
          if((value3&0x08)==0x08)
              ui->cw1_4->setChecked(true);
          if((value3&0x10)==0x10)
              ui->cw1_5->setChecked(true);
          if((value3&0x20)==0x20)
              ui->cw1_6->setChecked(true);
          if((value3&0x40)==0x40)
              ui->cw1_7->setChecked(true);
    }
    ////////////////////ri////////////////////
    if(((value4!=0xff)||(value5!=0xff)||(value6!=0xff)||(value7!=0xff)))
    {
      if((value4&0x01)==0x01)
          ui->cd1_1->setChecked(true);
      if((value4&0x02)==0x02)
          ui->cd1_2->setChecked(true);
      if((value4&0x04)==0x04)
          ui->cd1_3->setChecked(true);
      if((value4&0x08)==0x08)
          ui->cd1_4->setChecked(true);
      if((value4&0x10)==0x10)
          ui->cd1_5->setChecked(true);
      if((value4&0x20)==0x20)
          ui->cd1_6->setChecked(true);
      if((value4&0x40)==0x40)
          ui->cd1_7->setChecked(true);
      if((value4&0x80)==0x80)
          ui->cd1_8->setChecked(true);

      if((value5&0x01)==0x01)
          ui->cd1_9->setChecked(true);
      if((value5&0x02)==0x02)
          ui->cd1_10->setChecked(true);
      if((value5&0x04)==0x04)
          ui->cd1_11->setChecked(true);
      if((value5&0x08)==0x08)
          ui->cd1_12->setChecked(true);
      if((value5&0x10)==0x10)
          ui->cd1_13->setChecked(true);
      if((value5&0x20)==0x20)
          ui->cd1_14->setChecked(true);
      if((value5&0x40)==0x40)
          ui->cd1_15->setChecked(true);
      if((value5&0x80)==0x80)
          ui->cd1_16->setChecked(true);

      if((value6&0x01)==0x01)
          ui->cd1_17->setChecked(true);
      if((value6&0x02)==0x02)
          ui->cd1_18->setChecked(true);
      if((value6&0x04)==0x04)
          ui->cd1_19->setChecked(true);
      if((value6&0x08)==0x08)
          ui->cd1_20->setChecked(true);
      if((value6&0x10)==0x10)
          ui->cd1_21->setChecked(true);
      if((value6&0x20)==0x20)
          ui->cd1_22->setChecked(true);
      if((value6&0x40)==0x40)
          ui->cd1_23->setChecked(true);
      if((value6&0x80)==0x80)
          ui->cd1_24->setChecked(true);

      if((value7&0x01)==0x01)
          ui->cd1_25->setChecked(true);
      if((value7&0x02)==0x02)
          ui->cd1_26->setChecked(true);
      if((value7&0x04)==0x04)
          ui->cd1_27->setChecked(true);
      if((value7&0x08)==0x08)
          ui->cd1_28->setChecked(true);
      if((value7&0x10)==0x10)
          ui->cd1_29->setChecked(true);
      if((value7&0x20)==0x20)
          ui->cd1_30->setChecked(true);
      if((value7&0x40)==0x40)
          ui->cd1_31->setChecked(true);

    }
}

void DlgTimeBase::send8d()
{
    unsigned char value= (unsigned char)ui->spinNumber->value();
    char buffer[60];
    buffer[0]=0x02;
    buffer[1]=0x00;
    buffer[2]=0x04;
    buffer[3]=0x80;
    buffer[4]=0x8d;
    buffer[5]=0x40;
    buffer[6]=value;
    int len=7;
    unsigned short rssum=CommVerify((unsigned char*)buffer,len);
    buffer[len]=rssum/256;
    buffer[len+1]=rssum%256;
    this->com->WriteCom(buffer,len+2);
    qDebug()<<"query is sended !!";
}

void DlgTimeBase::set8d()
{
    unsigned char parm[8]={0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
    parm[0]=(unsigned char)(ui->spinNumber->value());
    ////////////parm[1][2]//////////////////////////////////
    if(ui->cm1_1->isChecked()|
            ui->cm1_2->isChecked()|
            ui->cm1_3->isChecked()|
            ui->cm1_4->isChecked()|
            ui->cm1_5->isChecked()|
            ui->cm1_6->isChecked()|
            ui->cm1_7->isChecked()|
            ui->cm1_8->isChecked())
    {
        if(ui->cm1_1->isChecked())
            parm[1]=parm[1]|0x01;
        if(ui->cm1_2->isChecked())
            parm[1]=parm[1]|0x02;
        if(ui->cm1_3->isChecked())
            parm[1]=parm[1]|0x04;
        if(ui->cm1_4->isChecked())
            parm[1]=parm[1]|0x08;
        if(ui->cm1_5->isChecked())
            parm[1]=parm[1]|0x10;
        if(ui->cm1_6->isChecked())
            parm[1]=parm[1]|0x20;
        if(ui->cm1_7->isChecked())
            parm[1]=parm[1]|0x40;
        if(ui->cm1_8->isChecked())
            parm[1]=parm[1]|0x80;
    }else{
    parm[1]=0x00;
    }
    if(
            ui->cm1_9->isChecked()|
            ui->cm1_10->isChecked()|
            ui->cm1_11->isChecked()|
            ui->cm1_12->isChecked()
            )
    {
        if(ui->cm1_9->isChecked())
            parm[2]=parm[2]|0x01;
        if(ui->cm1_10->isChecked())
            parm[2]=parm[2]|0x02;
        if(ui->cm1_11->isChecked())
            parm[2]=parm[2]|0x04;
        if(ui->cm1_12->isChecked())
            parm[2]=parm[2]|0x08;
    }
    else{
        parm[2]=0x00;
    }
    ///////////////////parm[3]////////////////////////////////
    if(ui->cw1_1->isChecked()|
            ui->cw1_2->isChecked()|
            ui->cw1_3->isChecked()|
            ui->cw1_4->isChecked()|
            ui->cw1_5->isChecked()|
            ui->cw1_6->isChecked()|
            ui->cw1_7->isChecked())
    {
        if(ui->cw1_1->isChecked())
            parm[3]=parm[3]|0x01;
        if(ui->cw1_2->isChecked())
            parm[3]=parm[3]|0x02;
        if(ui->cw1_3->isChecked())
            parm[3]=parm[3]|0x04;
        if(ui->cw1_4->isChecked())
            parm[3]=parm[3]|0x08;
        if(ui->cw1_5->isChecked())
            parm[3]=parm[3]|0x10;
        if(ui->cw1_6->isChecked())
            parm[3]=parm[3]|0x20;
        if(ui->cw1_7->isChecked())
            parm[3]=parm[3]|0x40;
    }
    else{
        parm[3]=0x00;
    }
    //////////////////////parm4 ,5 ,6 ,7////////////////////////
    if(ui->cd1_1->isChecked()|
            ui->cd1_2->isChecked()|ui->cd1_3->isChecked()|ui->cd1_4->isChecked()|
            ui->cd1_5->isChecked()|ui->cd1_6->isChecked()|ui->cd1_7->isChecked()|ui->cd1_8->isChecked()
            )
    {
        if(ui->cd1_1->isChecked())
            parm[4]=parm[4]|0x01;
        if(ui->cd1_2->isChecked())
            parm[4]=parm[4]|0x02;
        if(ui->cd1_3->isChecked())
            parm[4]=parm[4]|0x04;
        if(ui->cd1_4->isChecked())
            parm[4]=parm[4]|0x08;
        if(ui->cd1_5->isChecked())
            parm[4]=parm[4]|0x10;
        if(ui->cd1_6->isChecked())
            parm[4]=parm[4]|0x20;
        if(ui->cd1_7->isChecked())
            parm[4]=parm[4]|0x40;
        if(ui->cd1_8->isChecked())
            parm[4]=parm[4]|0x80;
    }else
    {
        parm[4]=0x00;
    }

    if(ui->cd1_9->isChecked()|ui->cd1_10->isChecked()|
            ui->cd1_11->isChecked()|ui->cd1_12->isChecked()|ui->cd1_13->isChecked()|
            ui->cd1_14->isChecked()|ui->cd1_15->isChecked()|ui->cd1_16->isChecked())
    {
        if(ui->cd1_9->isChecked())
            parm[5]=parm[5]|0x01;
        if(ui->cd1_10->isChecked())
            parm[5]=parm[5]|0x02;
        if(ui->cd1_11->isChecked())
            parm[5]=parm[5]|0x04;
        if(ui->cd1_12->isChecked())
            parm[5]=parm[5]|0x08;
        if(ui->cd1_13->isChecked())
            parm[5]=parm[5]|0x10;
        if(ui->cd1_14->isChecked())
            parm[5]=parm[5]|0x20;
        if(ui->cd1_15->isChecked())
            parm[5]=parm[5]|0x40;
        if(ui->cd1_16->isChecked())
            parm[5]=parm[5]|0x80;
    }
    else{
        parm[5]=0x00;
    }

    if(ui->cd1_17->isChecked()|ui->cd1_18->isChecked()|
            ui->cd1_19->isChecked()|ui->cd1_20->isChecked()|ui->cd1_21->isChecked()|
            ui->cd1_22->isChecked()|ui->cd1_23->isChecked()|ui->cd1_24->isChecked())
    {
        if(ui->cd1_17->isChecked())
            parm[6]=parm[6]|0x01;
        if(ui->cd1_18->isChecked())
            parm[6]=parm[6]|0x02;
        if(ui->cd1_19->isChecked())
            parm[6]=parm[6]|0x04;
        if(ui->cd1_20->isChecked())
            parm[6]=parm[6]|0x08;
        if(ui->cd1_21->isChecked())
            parm[6]=parm[6]|0x10;
        if(ui->cd1_22->isChecked())
            parm[6]=parm[6]|0x20;
        if(ui->cd1_23->isChecked())
            parm[6]=parm[6]|0x40;
        if(ui->cd1_24->isChecked())
            parm[6]=parm[6]|0x80;
    }
    else{
        parm[6]=0x00;
    }
    if(ui->cd1_25->isChecked()|ui->cd1_26->isChecked()|
            ui->cd1_27->isChecked()|ui->cd1_28->isChecked()|ui->cd1_29->isChecked()|
            ui->cd1_30->isChecked()|ui->cd1_31->isChecked())
    {
        if(ui->cd1_25->isChecked())
            parm[7]=parm[7]|0x01;
        if(ui->cd1_26->isChecked())
            parm[7]=parm[7]|0x02;
        if(ui->cd1_27->isChecked())
            parm[7]=parm[7]|0x04;
        if(ui->cd1_28->isChecked())
            parm[7]=parm[7]|0x08;
        if(ui->cd1_29->isChecked())
            parm[7]=parm[7]|0x10;
        if(ui->cd1_30->isChecked())
            parm[7]=parm[7]|0x20;
        if(ui->cd1_31->isChecked())
            parm[7]=parm[7]|0x40;
    }
    else{
        parm[7]=0x00;
    }
    //parm[8]=
    //qDebug()<<"parm[8]"+QString::number(parm[8],16);

    char buffer[50];
    buffer[0]=0x02;
    buffer[1]=0x00;
    buffer[2]=0x0d;
    buffer[3]=0x81;
    buffer[4]=0x8d;
    buffer[5]=0x40;
    buffer[6]=parm[0];
    buffer[7]=parm[0];
    qDebug()<<"7:"+QString::number(buffer[7],16);
    buffer[8]=parm[2];
    qDebug()<<"8:"+QString::number(buffer[8],16);
    buffer[9]=parm[1];
    qDebug()<<"9:"+QString::number(buffer[9],16);
    buffer[10]=parm[3];
    qDebug()<<"10:"+QString::number(buffer[10],16);
    buffer[11]=parm[7];
    qDebug()<<"11:"+QString::number(buffer[11],16);
    buffer[12]=parm[6];
    qDebug()<<"12:"+QString::number(buffer[12],16);
    buffer[13]=parm[5];
    qDebug()<<"13:"+QString::number(buffer[13],16);
    buffer[14]=parm[4];
    qDebug()<<"14:"+QString::number(buffer[14],16);
    buffer[15]=(unsigned char)ui->spinTimeTab->value();
    qDebug()<<"15:"+QString::number(buffer[15],16);
    int len=16;
    unsigned short rssum = CommVerify((unsigned char*)buffer,len);
    buffer[len]=rssum/256;
    buffer[len+1]=rssum%256;
    com->WriteCom(buffer,len+2);
}

void DlgTimeBase::on_bufclear_clicked()
{
    ui->display->clear();
    unsigned char value= (unsigned char)ui->spinNumber->value();
    char buffer[50];
    buffer[0]=0x02;
    buffer[1]=0x00;
    buffer[2]=0x0d;
    buffer[3]=0x81;
    buffer[4]=0x8d;
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
    unsigned short rssum = CommVerify((unsigned char*)buffer,len);
    buffer[len]=rssum/256;
    buffer[len+1]=rssum%256;
    com->WriteCom(buffer,len+2);
    timeout->start();
}
void DlgTimeBase::on_checkBoxifofmon_stateChanged(int i )
{
    if(ui->checkBoxifofmon->isChecked())
    {
        ui->cm1_1->setChecked(true);
        ui->cm1_2->setChecked(true);
        ui->cm1_3->setChecked(true);
        ui->cm1_4->setChecked(true);
        ui->cm1_5->setChecked(true);
        ui->cm1_6->setChecked(true);
        ui->cm1_7->setChecked(true);
        ui->cm1_8->setChecked(true);
        ui->cm1_9->setChecked(true);
        ui->cm1_10->setChecked(true);
        ui->cm1_11->setChecked(true);
        ui->cm1_12->setChecked(true);
    }
    else
    {
        ui->cm1_1->setChecked(false);
        ui->cm1_2->setChecked(false);
        ui->cm1_3->setChecked(false);
        ui->cm1_4->setChecked(false);
        ui->cm1_5->setChecked(false);
        ui->cm1_6->setChecked(false);
        ui->cm1_7->setChecked(false);
        ui->cm1_8->setChecked(false);
        ui->cm1_9->setChecked(false);
        ui->cm1_10->setChecked(false);
        ui->cm1_11->setChecked(false);
        ui->cm1_12->setChecked(false);
    }
}
void DlgTimeBase::on_checkBoxifofweek_stateChanged(int i)
{
    if(ui->checkBoxifofweek->isChecked())
    {
        ui->cw1_1->setChecked(true);
        ui->cw1_2->setChecked(true);
        ui->cw1_3->setChecked(true);
        ui->cw1_4->setChecked(true);
        ui->cw1_5->setChecked(true);
        ui->cw1_6->setChecked(true);
        ui->cw1_7->setChecked(true);
    }
    else
    {
        ui->cw1_1->setChecked(false);
        ui->cw1_2->setChecked(false);
        ui->cw1_3->setChecked(false);
        ui->cw1_4->setChecked(false);
        ui->cw1_5->setChecked(false);
        ui->cw1_6->setChecked(false);
        ui->cw1_7->setChecked(false);
    }
}
void DlgTimeBase::on_checkBoxifofday_stateChanged(int i)
{
    if(ui->checkBoxifofday->isChecked())
    {
        ui->cd1_1->setChecked(true);
        ui->cd1_2->setChecked(true);
        ui->cd1_3->setChecked(true);
        ui->cd1_4->setChecked(true);
        ui->cd1_5->setChecked(true);
        ui->cd1_6->setChecked(true);
        ui->cd1_7->setChecked(true);
        ui->cd1_8->setChecked(true);
        ui->cd1_9->setChecked(true);
        ui->cd1_10->setChecked(true);
        ui->cd1_11->setChecked(true);
        ui->cd1_12->setChecked(true);
        ui->cd1_13->setChecked(true);
        ui->cd1_14->setChecked(true);
        ui->cd1_15->setChecked(true);
        ui->cd1_16->setChecked(true);
        ui->cd1_17->setChecked(true);
        ui->cd1_18->setChecked(true);
        ui->cd1_19->setChecked(true);
        ui->cd1_20->setChecked(true);
        ui->cd1_21->setChecked(true);
        ui->cd1_22->setChecked(true);
        ui->cd1_23->setChecked(true);
        ui->cd1_24->setChecked(true);
        ui->cd1_25->setChecked(true);
        ui->cd1_26->setChecked(true);
        ui->cd1_27->setChecked(true);
        ui->cd1_28->setChecked(true);
        ui->cd1_29->setChecked(true);
        ui->cd1_30->setChecked(true);
        ui->cd1_31->setChecked(true);
    }
    else
    {
        ui->cd1_1->setChecked(false);
        ui->cd1_2->setChecked(false);
        ui->cd1_3->setChecked(false);
        ui->cd1_4->setChecked(false);
        ui->cd1_5->setChecked(false);
        ui->cd1_6->setChecked(false);
        ui->cd1_7->setChecked(false);
        ui->cd1_8->setChecked(false);
        ui->cd1_9->setChecked(false);
        ui->cd1_10->setChecked(false);
        ui->cd1_11->setChecked(false);
        ui->cd1_12->setChecked(false);
        ui->cd1_13->setChecked(false);
        ui->cd1_14->setChecked(false);
        ui->cd1_15->setChecked(false);
        ui->cd1_16->setChecked(false);
        ui->cd1_17->setChecked(false);
        ui->cd1_18->setChecked(false);
        ui->cd1_19->setChecked(false);
        ui->cd1_20->setChecked(false);
        ui->cd1_21->setChecked(false);
        ui->cd1_22->setChecked(false);
        ui->cd1_23->setChecked(false);
        ui->cd1_24->setChecked(false);
        ui->cd1_25->setChecked(false);
        ui->cd1_26->setChecked(false);
        ui->cd1_27->setChecked(false);
        ui->cd1_28->setChecked(false);
        ui->cd1_29->setChecked(false);
        ui->cd1_30->setChecked(false);
        ui->cd1_31->setChecked(false);
    }
}
void DlgTimeBase::on_butquery_clicked()
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
    buffer[6]=0x8d;
    int len=7;
    unsigned short rssum=CommVerify((unsigned char*)buffer,len);
    buffer[len]=rssum/256;
    buffer[len+1]=rssum%256;
    this->com->WriteCom(buffer,len+2);
    revtimer->start(20);
    connect(revtimer,SIGNAL(timeout()),this,SLOT(rev()));
    timeout->start();
}
void DlgTimeBase::on_butclearall_clicked()
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
    buffer[6]=0x8d;
    int len=7;
    unsigned short rssum=CommVerify((unsigned char *)buffer,len);
    buffer[len]=rssum/256;
    buffer[len+1]=rssum%256;
    this->com->WriteCom(buffer,len+2);
    timeout->start();
    revtimer->start(20);
    connect(revtimer,SIGNAL(timeout()),this,SLOT(rev()));
    timeout->start();
}
