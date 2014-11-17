#include "dlgpubparm.h"
#include "ui_dlgpubparm.h"
#include "unit.h"
#include <QDebug>
/*************************************************/
union unix_time_type unix_time;
struct time_type g_current_time;
int unix_time_to_rtc_time(unsigned int unix_time, struct time_type *rtc);
unsigned int rtc_time_to_unix_time(struct time_type rtc);
static unsigned int *months(unsigned int year);
/*************************************************/
static bool find81=false;
static bool find83=false;
static bool find84=false;
static bool find86=false;
static bool find87=false;
static bool find88=false;
static bool findcf=false;
static bool findd3=false;

static bool set81f=false;
static bool set88f=false;
static bool setcff=false;
static QString RecText;
DlgPubParm::DlgPubParm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DlgPubParm)
{
    ui->setupUi(this);
    this->com=new CPubSub();
    this->revtimer=new QTimer();
    this->timeout=new QTimer();
    connect(timeout,SIGNAL(timeout()),this,SLOT(warming()));
}

DlgPubParm::~DlgPubParm()
{
    delete ui;
    deleteLater();
    delete revtimer;
    delete timeout;
    //delete com;
    //com=NULL;
}
void DlgPubParm::setcom(CPubSub *com)
{
    this->com=com;
}
void DlgPubParm::warming()
{
    ui->display->setText(tr("错误请重新尝试!"));
}
void DlgPubParm::on_butsend_clicked()
{
    find81=false;
    find83=false;
    find84=false;
    find86=false;
    find87=false;
    find88=false;
    findcf=false;
    findd3=false;
    ui->EditMac1->clear();
    ui->EditMac2->clear();
    ui->EditMac3->clear();
    ui->EditMac4->clear();
    ui->EditMac5->clear();
    ui->EditMac6->clear();
    ui->EditGateway1->clear();
    ui->EditGateway2->clear();
    ui->EditGateway3->clear();
    ui->EditGateway4->clear();
    ui->Editid->clear();
    ui->EditIp1->clear();
    ui->EditIp2->clear();
    ui->EditIp3->clear();
    ui->EditIp4->clear();
    ui->Editmask1->clear();
    ui->Editmask2->clear();
    ui->Editmask3->clear();
    ui->Editmask4->clear();
    ui->EditPort->clear();
//    ui->Editpubsyntime->clear();
//    ui->Editpubsynmask->clear();
    ui->local1->clear();
    ui->local2->clear();
    ui->local3->clear();
    ui->local4->clear();
    ui->local5->clear();
    ui->local6->clear();
//    ui->labeltimezore->clear();

//    ui->pub1->clear();
//    ui->pub2->clear();
//    ui->pub3->clear();
//    ui->pub4->clear();
//    ui->pub5->clear();
//    ui->pub6->clear();
    RecText="";
    QTimer::singleShot(1,this,SLOT(send81()));
    revtimer->start(20);
    connect(revtimer,SIGNAL(timeout()),this,SLOT(rev()));
    timeout->start(1000);
    ui->display->clear();
    ui->display->setText(tr("查询中......"));
}

void DlgPubParm::rev()
{
    char RecBuf[4096];
    memset(RecBuf,NULL,4096);    
    int Rlen;
    if(com->isopen())
    {
            Rlen=com->GetDataLen();
            if(Rlen>0&&Rlen>7)
            {
                com->ReadCom(RecBuf,Rlen);
                for(int i=0;i<Rlen;i++)
                {
                    RecText.append(QString::number((uchar)RecBuf[i],16));
                    RecText.append("|");
                }
                RecText.append("\n");
                ui->textEdit->setText(RecText);
                //SetDlgItemText(IDC_DISP,"接收成功!");
                //ui->display->setText(tr("接收成功!总数为:")+QString::number(Rlen,10));
            }
            dealwith((uchar*)RecBuf,Rlen);
    }
}
void DlgPubParm::dealwith(uchar* rec,int len)
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
//            if((uchar)(*(s+4))==0x83)
//            {
//                                find83=true;
//                                init83(s);
//                                QTimer::singleShot(1,this,SLOT(send84()));
//            }
//            if((uchar)(*(s+4))==0x84)
//            {
//                                find84=true;
//                                init84(s);
//                                 QTimer::singleShot(1,this,SLOT(send86()));
//            }
//            if((uchar)(*(s+4))==0x86)
//            {
//                find86=true;
//                init86(s);
//                 QTimer::singleShot(1,this,SLOT(send87()));
//            }
//            if((uchar)(*(s+4))==0x87)
//            {
//                                find87=true;
//                                init87();
//                QTimer::singleShot(1,this,SLOT(send88()));
//            }//
            if((uchar)(*(s+4))==0x88)
            {
                                find88=true;
                                init88(s);                                 
            QTimer::singleShot(1,this,SLOT(sendcf()));
            }
            if((uchar)(*(s+4))==0xcf)
            {
                findcf=true;
                initcf(s);                 
            QTimer::singleShot(1,this,SLOT(sendd3()));
            }
            if((uchar)(*(s+4))==0x81)
            {
                            find81=true;
                            init81(s);
             QTimer::singleShot(1,this,SLOT(send88()));
            }
            if((uchar)(*(s+4))==0xd3)
            {
                findd3=true;
                this->initd3(s);                
            }
            if(find81&find88&findcf&findd3)
            {
                   ui->display->setText(tr("查询成功!"));
                   timeout->stop();
            }else
            {
                   //ui->display->setText(tr("查询失败!"));
                   //timeout->stop();
            }
        }
        if((uchar)*(s+3)==0x85)//设置成功命令
        {
            if((uchar)(*(s+4))==0x81)
            {
                set81f=true;
                QTimer::singleShot(1,this,SLOT(set88()));
            }
            if((uchar)(*(s+4))==0x88)
            {
                set88f=true;
                QTimer::singleShot(1,this,SLOT(setcf()));
            }
            if((uchar)(*(s+4))==0xcf)
            {
                setcff=true;
            }
            if(set81f&set88f&setcff)
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
void DlgPubParm::send81()
{
    char buffer[]={0X02,0X00,0X03,0X80,0x81,0x00};
    int len=6;
    unsigned short rssum = CommVerify((uchar*)buffer,len);
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
//    QTimer::singleShot(1,this,SLOT(send83()));

}

void DlgPubParm::send83()
{
    char buffer[]={0X02,0X00,0X03,0X80,0x83,0x00};
    int len=6;
    unsigned short rssum = CommVerify((uchar*)buffer,len);
    buffer[len]=rssum/256;
    buffer[len+1]=rssum%256;
    int i=0;
    for(i;i<3;i++)
    {
            if(com->WriteCom(buffer,len+2))
            {
                qDebug()<<"83";
                    break;
            }
    }
//    QTimer::singleShot(1,this,SLOT(send84()));

}

void DlgPubParm::send84()
{
    char buffer[]={0X02,0X00,0X03,0X80,0x84,0x00};
    int len=6;
    unsigned short rssum = CommVerify((uchar*)buffer,len);
    buffer[len]=rssum/256;
    buffer[len+1]=rssum%256;
    int i=0;
    for(i;i<3;i++)
    {
            if(com->WriteCom(buffer,len+2))
            {
                qDebug()<<"84";
                    break;
            }
    }
//    QTimer::singleShot(1,this,SLOT(send86()));

}

void DlgPubParm::send86()
{
    char buffer[]={0X02,0X00,0X03,0X80,0x86,0x00};
    int len=6;
    unsigned short rssum = CommVerify((uchar*)buffer,len);
    buffer[len]=rssum/256;
    buffer[len+1]=rssum%256;
    int i=0;
    for(i;i<3;i++)
    {
            if(com->WriteCom(buffer,len+2))
            {
                qDebug()<<"86";
                    break;
            }
    }
//    QTimer::singleShot(1,this,SLOT(send87()));

}

void DlgPubParm::send87()
{
    char buffer[]={0X02,0X00,0X03,0X80,0x87,0x00};
    int len=6;
    unsigned short rssum = CommVerify((uchar*)buffer,len);
    buffer[len]=rssum/256;
    buffer[len+1]=rssum%256;
    int i=0;
    for(i;i<3;i++)
    {
            if(com->WriteCom(buffer,len+2))
            {
                qDebug()<<"87";
                 break;


            }
    }
//    QTimer::singleShot(1,this,SLOT(send88()));
}

void DlgPubParm::send88()
{
    char buffer[]={0X02,0X00,0X03,0X80,0x88,0x00};
    int len=6;
    unsigned short rssum = CommVerify((uchar*)buffer,len);
    buffer[len]=rssum/256;
    buffer[len+1]=rssum%256;
    int i=0;
    for(i;i<3;i++)
    {
            if(com->WriteCom(buffer,len+2))
            {
                qDebug()<<"88";
                    break;
            }
    }
//    QTimer::singleShot(1,this,SLOT(sendcf()));

}

void DlgPubParm::sendcf()
{
    char buffer[]={0X02,0X00,0X03,0X80,0xcf,0x00};
    int len=6;
    unsigned short rssum = CommVerify((uchar*)buffer,len);
    buffer[len]=rssum/256;
    buffer[len+1]=rssum%256;
    int i=0;
    for(i;i<3;i++)
    {
            if(com->WriteCom(buffer,len+2))
            {
                 qDebug()<<"cf";
                    break;
            }
    }
//   QTimer::singleShot(1,this,SLOT(sendd3()));
}

void DlgPubParm::sendd3()
{
    char buffer[]={0X02,0X00,0X03,0X80,0xd3,0x00};
    int len=6;
    unsigned short rssum = CommVerify((uchar*)buffer,len);
    buffer[len]=rssum/256;
    buffer[len+1]=rssum%256;
    int i=0;
    for(i;i<3;i++)
    {
            if(com->WriteCom(buffer,len+2))
            {
                qDebug()<<"d3";
                    break;
            }
    }

}
void DlgPubParm::init86(unsigned char*buffer)
{
//    unsigned char parm1=buffer[6];
//    unsigned char parm2=buffer[7];
//    unsigned char parm3=buffer[8];
//    unsigned char parm4=buffer[9];
//    unsigned int test=(parm1<<24)+(parm2<<16)+(parm3<<8)+parm4;
//    //    qDebug()<<"test1:"+QString::number(test, 16);
//    //qDebug()<<"test:"+QString::number(test, 10)+":"+QString::number(((unsigned int)buffer[6]<<24), 10)+":"+QString::number((unsigned int)buffer[7], 10)+":"+QString::number((unsigned int)buffer[8], 10)+":"+QString::number((unsigned int)buffer[9], 10);

//    struct time_type time;
//    int b = unix_time_to_rtc_time(test,&time);
//    //qDebug()<< "the funtion of unix_time_to_rtc_time:"+QString::number(b, 10);

//    unsigned int year=(int)time.year;
//    unsigned int month=(int)time.month;
//    unsigned int days=(int)time.day;
//    unsigned int hour=(int)time.hour;
//    unsigned int min=(int)time.min;
//    unsigned int sec=(int)time.sec;
//    if(year<9)
//    {
//       ui->pub1->setText("0"+QString::number(year, 10));
//    }
//    else
//    {
//       ui->pub1->setText(QString::number(year, 10));
//    }
//    ui->pub2->setText(QString::number(month, 10));
//    ui->pub3->setText(QString::number(days, 10));
//    ui->pub4->setText(QString::number(hour, 10));
//    ui->pub5->setText(QString::number(min, 10));
//    ui->pub6->setText(QString::number(sec, 10));
}

void DlgPubParm::init87()
{
//    ui->labeltimezore->setText("east 8");
}

void DlgPubParm::init88(unsigned char*buffer)
{
    unsigned char localparm1=buffer[6];
    unsigned char localparm2=buffer[7];
    unsigned char localparm3=buffer[8];
    unsigned char localparm4=buffer[9];
    unsigned int localtest=(localparm1<<24)+(localparm2<<16)+(localparm3<<8)+localparm4;
    //    qDebug()<<"test2:"+QString::number(localtest, 16);
        qDebug()<<"localparm1:"+QString::number(localparm1, 16);
        qDebug()<<"localparm2:"+QString::number(localparm2, 16);
        qDebug()<<"localparm3:"+QString::number(localparm3, 16);
        qDebug()<<"localparm4:"+QString::number(localparm4, 16);
    //qDebug()<<"time#########################:"+QString::number(localtest, 16);
    //产生时间结构体
    struct time_type time;
    int b = unix_time_to_rtc_time(localtest,&time);

    // qDebug()<< "the funtion of unix_time_to_rtc_time:"+QString::number(b, 10);
    unsigned int year=(int)time.year;
    unsigned int month=(int)time.month;
    unsigned int days=(int)time.day;
    unsigned int hour=(int)time.hour;
    unsigned int min=(int)time.min;
    unsigned int sec=(int)time.sec;
    if(year<9)
    {
       ui->local1->setText("0"+QString::number(year, 10));
}
    else
    {
       ui->local1->setText(QString::number(year, 10));
    }
    ui->local2->setText(QString::number(month, 10));
    ui->local3->setText(QString::number(days, 10));
    ui->local4->setText(QString::number(hour, 10));
    ui->local5->setText(QString::number(min, 10));
    ui->local6->setText(QString::number(sec, 10));
}

void DlgPubParm::init81(unsigned char*buffer)
{
    //    qDebug()<<"buffer6:"+QString::number(buffer[6], 10);
    //       qDebug()<<"buffer7:"+QString::number(buffer[7], 10);
    //        qDebug()<<"buffer8:"+QString::number(buffer[8], 10);
    //         qDebug()<<"buffer9:"+QString::number(buffer[9], 10);

       unsigned char idparm1=buffer[6];
       unsigned char idparm2=buffer[7];
    //     qDebug()<<"test:"+QString::number(idparm1, 10);
    //     qDebug()<<"test:"+QString::number(idparm2, 10);
       unsigned short int sidtest=idparm1+(idparm2<<8);
       //int iidtest= (int) sidtest;
    //    qDebug()<<QString::number(sidtest, 10);
       ui->Editid->setText(QString::number(sidtest, 10));
}

void DlgPubParm::initcf(unsigned char*buffer)
{
    unsigned char ipparm1=buffer[6];
    unsigned char ipparm2=buffer[7];
    unsigned char ipparm3=buffer[8];
    unsigned char ipparm4=buffer[9];
    unsigned char ipparm5=buffer[10];
    unsigned char ipparm6=buffer[11];
    short int setport=(ipparm5<<8)+(ipparm6<<0);
//    qDebug()<<"123-----"+QString::number(((char)buffer[10]<<8), 10);//25h   37s
//    qDebug()<<"123-----"+QString::number((char)buffer[11], 10);//37h    55s
//    qDebug()<<"456-----"+QString::number(setport, 10);
    //qDebug()<<QString::number(ipparm3, 10);
    //qDebug()<<QString::number(ipparm4, 10);
    unsigned char maskparm1=buffer[12];
    unsigned char maskparm2=buffer[13];
    unsigned char maskparm3=buffer[14];
    unsigned char maskparm4=buffer[15];
    unsigned char Gateway1=buffer[16];
    unsigned char Gateway2=buffer[17];
    unsigned char Gateway3=buffer[18];
    unsigned char Gateway4=buffer[19];

//        qDebug()<<QString::number(maskparm1, 10);
//        qDebug()<<QString::number(maskparm2, 10);
//        qDebug()<<QString::number(maskparm3, 10);
//        qDebug()<<QString::number(maskparm4, 10);

    ui->Editmask1->setText(QString::number(maskparm1, 10));
    ui->Editmask2->setText(QString::number(maskparm2, 10));
    ui->Editmask3->setText(QString::number(maskparm3, 10));
    ui->Editmask4->setText(QString::number(maskparm4, 10));

    ui->EditGateway1->setText(QString::number(Gateway4, 10));
    ui->EditGateway2->setText(QString::number(Gateway3, 10));
    ui->EditGateway3->setText(QString::number(Gateway2, 10));
    ui->EditGateway4->setText(QString::number(Gateway1, 10));

    ui->EditIp1->setText(QString::number(ipparm1, 10));
    ui->EditIp2->setText(QString::number(ipparm2, 10));
    ui->EditIp3->setText(QString::number(ipparm3, 10));
    ui->EditIp4->setText(QString::number(ipparm4, 10));
    ui->EditPort->setText(QString::number(setport, 10));
}

void DlgPubParm::initd3(unsigned char*buffer)
{
    unsigned char mac1=buffer[6];
    unsigned char mac2=buffer[7];
    unsigned char mac3=buffer[8];
    unsigned char mac4=buffer[9];
    unsigned char mac5=buffer[10];
    unsigned char mac6=buffer[11];


    qDebug()<<QString::number(mac1, 16);
    qDebug()<<QString::number(mac2, 16);
    qDebug()<<QString::number(mac3, 16);
    qDebug()<<QString::number(mac4, 16);
    qDebug()<<QString::number(mac5, 16);
    qDebug()<<QString::number(mac6, 16);

    ui->EditMac1->setText(QString::number(mac1, 16));
    ui->EditMac2->setText(QString::number(mac2, 16));
    ui->EditMac3->setText(QString::number(mac3, 16));
    ui->EditMac4->setText(QString::number(mac4, 16));
    ui->EditMac5->setText(QString::number(mac5, 16));
    ui->EditMac6->setText(QString::number(mac6, 16));
}

void DlgPubParm::init83(unsigned char*buffer)
{
//    unsigned char syntimeparm1=buffer[6];
//    unsigned char syntimeparm2=buffer[7];
//    unsigned short int syntimeparm=syntimeparm1+(syntimeparm2<<8);
//    this->ui->Editpubsyntime->setText(QString::number(syntimeparm, 10));
}

void DlgPubParm::init84(unsigned char*buffer)
{
//    char synmaskparm1=(char)buffer[6];
//    char synmaskparm2=(char)buffer[7];
//    unsigned short int synmaskparm=synmaskparm1+(synmaskparm2<<8);
//    this->ui->Editpubsynmask->setText(QString::number(synmaskparm, 10));
}
void DlgPubParm::on_butchange_clicked()
{
    set81f=false;
    set88f=false;
    setcff=false;
    revtimer->stop();
    ui->display->clear();
    QTimer::singleShot(1,this,SLOT(set81()));
//    QTimer::singleShot(1,this,SLOT(set88()));
//    QTimer::singleShot(1,this,SLOT(sendcf()));
    revtimer->start(100);
    connect(revtimer,SIGNAL(timeout()),this,SLOT(rev()));
    timeout->start(1000);
}

void DlgPubParm::set81()
{
    short int id=ui->Editid->text().toInt();
    qDebug()<<"id="+QString::number(id,10);
    char buffer[600];
    int len;
    buffer[0]=0x02;
    buffer[1]=0x00;
    buffer[2]=0x05;
    buffer[3]=0x81;
    buffer[4]=0x81;
    buffer[5]=0x00;
    buffer[6]=(char)id;
    buffer[7]=(char)(id>>8);
    len=8;
    unsigned short rssum=CommVerify((unsigned char*)buffer,len);
    buffer[len]=rssum/256;
    buffer[len+1]=rssum%256;
    com->WriteCom(buffer,len+2);
}

void DlgPubParm::set83()
{
//    short int pubsyntimeparm=ui->Editpubsyntime->text().toInt();
//    char buffer[600];
//    int len;
//    buffer[0]=0x02;
//    buffer[1]=0x00;
//    buffer[2]=0x05;
//    buffer[3]=0x81;
//    buffer[4]=0x83;
//    buffer[5]=0x00;
//    buffer[6]=(char)pubsyntimeparm;
//    buffer[7]=(char)(pubsyntimeparm>>8);
//    //qDebug()<<"1:"+QString::number(port1>>8,10);
//    //qDebug()<<"2:"+QString::number(port1,10);
//    len=8;
//    unsigned short rssum=CommVerify((unsigned char*)buffer,len);
//    buffer[len]=rssum/256;
//    buffer[len+1]=rssum%256;
//    com->WriteCom(buffer,len+2);
//    qDebug()<<"dddddddddddddddddddddd";
}

void DlgPubParm::set88()
{
    struct time_type time;
    time.year=(char)(ui->local1->text().toInt());
    time.month=(char)(ui->local2->text().toInt());
    time.day=(char)(ui->local3->text().toInt());
    time.hour=(char)(ui->local4->text().toInt());
    time.min=(char)(ui->local5->text().toInt());
    time.sec=(char)(ui->local6->text().toInt());
    unsigned int sectime=rtc_time_to_unix_time(time);
//    qDebug()<<"==================================================";
//    qDebug()<<"four:"+QString::number(sectime,16);
//    qDebug()<<"==================================================";
    char four=(char)(sectime>>24);
    char whree=(char)(sectime>>16);
    char two=(char)(sectime>>8);
    char one =(char)(sectime);
    char buffer[600];
    int len;
    buffer[0]=0x02;
    buffer[1]=0x00;
    buffer[2]=0x07;
    buffer[3]=0x81;
    buffer[4]=0x88;
    buffer[5]=0x00;
    buffer[6]=four;
    buffer[7]=whree;
    buffer[8]=two;
    buffer[9]=one;
    len=10;

//    qDebug()<<"four:"+QString::number(four,10);
//    qDebug()<<"whree:"+QString::number(whree,10);
//    qDebug()<<"two:"+QString::number(two,10);
//    qDebug()<<"one:"+QString::number(one,10);
//qDebug()<<"buffer[6]:"+(BYTE)buffer[6];
    unsigned short rssum=CommVerify((unsigned char*)buffer,len);
     buffer[len]=rssum/256;
     buffer[len+1]=rssum%256;
    com->WriteCom(buffer,len+2);
}
void DlgPubParm::setcf()
{
    int ip1=ui->EditIp1->text().toInt();
    int ip2=ui->EditIp2->text().toInt();
    int ip3=ui->EditIp3->text().toInt();
    int ip4=ui->EditIp4->text().toInt();
    char maskparm1=ui->Editmask1->text().toInt();
    char maskparm2=ui->Editmask2->text().toInt();
    char maskparm3=ui->Editmask3->text().toInt();
    char maskparm4=ui->Editmask4->text().toInt();
    char Gateway1=ui->EditGateway1->text().toInt();
    char Gateway2=ui->EditGateway2->text().toInt();
    char Gateway3=ui->EditGateway3->text().toInt();
    char Gateway4=ui->EditGateway4->text().toInt();

    short int port1=ui->EditPort->text().toInt();

    qDebug()<<"ip1:"+QString::number(ip1,10);
    char buffer[600];
    int len;
    buffer[0]=0x02;
    buffer[1]=0x00;
    buffer[2]=0x11;
    buffer[3]=0x81;
    buffer[4]=0xcf;
    buffer[5]=0x00;
    buffer[6]=ip1;
    buffer[7]=ip2;
    buffer[8]=ip3;
    buffer[9]=ip4;

    buffer[10]=(char)(port1>>8);
    buffer[11]=(char)port1;

    buffer[12]=maskparm1;
    buffer[13]=maskparm2;
    buffer[14]=maskparm3;
    buffer[15]=maskparm4;

    buffer[16]=Gateway4;
    buffer[17]=Gateway3;
    buffer[18]=Gateway2;
    buffer[19]=Gateway1;
    len=20;
    unsigned short rssum=CommVerify((unsigned char*)buffer,len);
    buffer[len]=rssum/256;
    buffer[len+1]=rssum%256;
    com->WriteCom(buffer,len+2);
    qDebug()<<"cccccccccccccccccccccccccc";
}


static unsigned int *months(unsigned int year)
{
    if((year % 4 == 0) && (year % 100 != 0 || year % 400 == 0))
    {
        return leapyear;
    }

    return nonleapyear;
}

unsigned rtc_time_to_unix_time(struct time_type rtc)
{
    // First, accumulate days since January 1, 2001.
    // Using 2001 instead of 1970 makes the leap-year
    // handling easier (see SecondsToUTC), because
    // it is at the beginning of the 4-, 100-, and 400-year cycles.
    unsigned int day = 0;
    unsigned int year = rtc.year+2000;
    // Rewrite year to be >= 2001.
    if(year < 2001)
    {
        unsigned int n = (2001 - year) / 400 + 1;
        year += 400 * n;
        day -= DAYS_PER_400YEARS * n;
    }

    // Add in days from 400-year cycles.
    unsigned int n = (year - 2001) / 400;
    year -= 400 * n;
    day += DAYS_PER_400YEARS * n;

    // Add in 100-year cycles.
    n = (year - 2001) / 100;
    year -= 100 * n;
    day += DAYS_PER_100YEARS * n;

    // Add in 4-year cycles.
    n = (year - 2001) / 4;
    year -= 4 * n;
    day += DAYS_PER_4YEARS * n;

    // Add in non-leap years.
    n = year - 2001;
    day += 365 * n;

    // Add in days this year.
    unsigned int *month = months(rtc.year);
    int m = 0;
    for(m = 0; m < rtc.month - 1; m++)
    {
        day += month[m];
    }
    day += rtc.day - 1;

    // Convert days to seconds since January 1, 2001.
    unsigned int sec = day * SECONDS_PER_DAY;

    // Add in time elapsed today.
    sec += rtc.hour * 3600;
    sec += rtc.min * 60;
    sec += rtc.sec;

    // Convert from seconds since 2001 to seconds since 1970.
    sec += DAYS_1970_TO_2001 * SECONDS_PER_DAY;
    sec -= SECONDS_OF_TIME_ZONE;

    return sec;
}

int unix_time_to_rtc_time(unsigned int unix_time, struct time_type *rtc)
{

    unix_time += SECONDS_OF_TIME_ZONE;

    int day = unix_time / SECONDS_PER_DAY;
    unix_time -= day * SECONDS_PER_DAY;
    if(day < 0) //?
    {
        unix_time += SECONDS_PER_DAY;
        day--;
    }

    rtc->hour = unix_time / 3600;
    rtc->min = (unix_time / 60) % 60;
    rtc->sec = unix_time % 60;

    // Day 0 = January 1, 1970 was a Thursday
    rtc->week = (day + Thursday) % 7;
    if(rtc->week < 0)
    {
        rtc->week += 7;
    }
    if(rtc->week==0){
        rtc->week=7;
    }

    // Change day from 0 = 1970 to 0 = 2001,
    // to make leap year calculations easier
    // (2001 begins 4-, 100-, and 400-year cycles ending in a leap year.)
    day -= DAYS_1970_TO_2001;
    unsigned int year = 2001;
    if(day < 0)
    {
        // Go back enough 400 year cycles to make day positive.
        unsigned int n = -day / DAYS_PER_400YEARS + 1;
        year -= 400 * n;
        day += DAYS_PER_400YEARS * n;
    }

    // Cut off 400 year cycles.
    unsigned int n = day / DAYS_PER_400YEARS;
    year += 400 * n;
    day -= DAYS_PER_400YEARS * n;

    // Cut off 100-year cycles
    n = day / DAYS_PER_100YEARS;
    if(n > 3)
    {
        n = 3;
    }
    year += 100 * n;
    day -= DAYS_PER_100YEARS * n;

    // Cut off 4-year cycles
    n = day / DAYS_PER_4YEARS;
    if(n > 24)
    {  // happens on last day of 100th year
        n = 24;
    }
    year += 4 * n;
    day -= DAYS_PER_4YEARS * n;

    // Cut off non-leap years.
    n = day / 365;
    if(n > 3)
    {
        // happens on last day of 4th year
        n = 3;
    }
    year += n;
    day -= 365 * n;
    rtc->year = year%100;

    unsigned int *month = months(year);
    int m = 0;
    for(; m < 12 && day >= month[0]; m++)
    {
        day -= month[m];
    }

    rtc->month = m + 1;
    rtc->day = day + 1;

    return 0;
}


