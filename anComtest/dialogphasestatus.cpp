#include "dialogphasestatus.h"
#include "ui_dialogphasestatus.h"
#include "unit.h"
#include <QDebug>
#include "dlgpubparm.h"
#include <QFile>
union unix_time_type unix_time3;
struct time_type g_current_time3;
static unsigned int *months(unsigned int year)
{
    if((year % 4 == 0) && (year % 100 != 0 || year % 400 == 0))
    {
        return leapyear;
    }

    return nonleapyear;
}

unsigned rtc_time_to_unix_time3(struct time_type rtc)
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

int unix_time_to_rtc_time3(unsigned int unix_time3, struct time_type *rtc)
{

    unix_time3 += SECONDS_OF_TIME_ZONE;

    int day = unix_time3 / SECONDS_PER_DAY;
    unix_time3 -= day * SECONDS_PER_DAY;
    if(day < 0) //?
    {
        unix_time3 += SECONDS_PER_DAY;
        day--;
    }

    rtc->hour = unix_time3 / 3600;
    rtc->min = (unix_time3 / 60) % 60;
    rtc->sec = unix_time3 % 60;

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


DialogPhaseStatus::DialogPhaseStatus(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogPhaseStatus)
{
    ui->setupUi(this);
    this->com=new CPubSub();
    this->revtimer=new QTimer();
    this->timeout=new QTimer();
    connect(timeout,SIGNAL(timeout()),this,SLOT(warming()));
    setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowMinimizeButtonHint | Qt::WindowMaximizeButtonHint);
    QTimer::singleShot(20,this,SLOT(sendd1()));
    revtimer->start(200);
    connect(revtimer,SIGNAL(timeout()),this,SLOT(rev()));
    ui->butfind->click();
}

DialogPhaseStatus::~DialogPhaseStatus()
{
    delete ui;
    deleteLater();
}
void DialogPhaseStatus::setcom(CPubSub *com)
{
    this->com=com;
}
void DialogPhaseStatus::dealwith(uchar* rec,int len)
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
        if((uchar)(*(s+3))==0x93)
        {
            initb1((uchar*)s);
            qDebug()<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$";
            ui->display->setText(tr("查询成功!"));
            //timeout->stop();
        }
        if((uchar)*(s+3)==0x83)//事件表
        {
            if((uchar)(*(s+4))==0x92)
            {
                init92((uchar*)s);
                //timeout->stop();
            }
            if((uchar)(*(s+4))==0xa0)
            {
                inita0((uchar*)s);
                //timeout->stop();
            }
        }
        if((uchar)*(s+3)==0x84)//查询命令处理
        {
            if((uchar)(*(s+4))==0xb1)
            {
                init96iii((uchar*)s);
                ui->display->setText(tr("查询成功!"));
                //timeout->stop();
            }
        }
        if((uchar)*(s+3)==0x85)//设置成功命令
        {
            qDebug()<<"###################################";
            if((uchar)(*(s+4))==0xd1)
            {
                //if((*(s)+5)==0x00)
                ui->display->setText(tr("开关触发成功!"));
                //if((*(s)+5)==0xaa)
                //ui->display->setText(tr("开关开!"));
                //timeout->stop();
            }
        }
        if((uchar)*(s+3)==0x86)//设置错误命令
        {

        }
        s +=(num+5);
        i += (num+4);       
    }
}
void DialogPhaseStatus::initb1(uchar *buffer)
{


    ui->r1->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->r2->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->r3->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->r4->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->r5->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->r6->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->r7->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->r8->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
   //============================================================================================
    ui->y1->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->y2->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->y3->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->y4->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->y5->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->y6->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->y7->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->y8->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
   //===========================================================================================
    ui->g1->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->g2->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->g3->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->g4->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->g5->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->g6->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->g7->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->g8->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->r9->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->r10->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->r11->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->r12->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->r13->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->r14->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->r15->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->r16->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
   /////////////////////////////////////////////////////////////////////////////////////////////
    ui->y9->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->y10->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->y11->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->y12->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->y13->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->y14->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->y15->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->y16->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
   //////////////////////////////////////////////////////////////////////////////////////////
    ui->g9->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->g10->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->g11->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->g12->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->g13->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->g14->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->g15->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->g16->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    unsigned char parm1=*(buffer+7);
    unsigned char parm2=*(buffer+8);
    unsigned char parm3=*(buffer+9);
    unsigned char parm4=*(buffer+10);

    unsigned char parm5=*(buffer+11);
    unsigned char parm6=*(buffer+12);
    unsigned char parm7=*(buffer+13);
    unsigned char parm8=*(buffer+14);
    //===============================================

    if(parm1==0x01)
    {
      if((parm2&0x01)==0x01)
       ui->r1->setStyleSheet("background:Red;border:2px ;border-radius:14px;padding:2px 4px");
      if((parm2&0x02)==0x02)
       ui->r2->setStyleSheet("background:Red;border:2px ;border-radius:14px;padding:2px 4px");
      if((parm2&0x04)==0x04)
       ui->r3->setStyleSheet("background:Red;border:2px ;border-radius:14px;padding:2px 4px");
      if((parm2&0x08)==0x08)
       ui->r4->setStyleSheet("background:Red;border:2px ;border-radius:14px;padding:2px 4px");
      if((parm2&0x10)==0x10)
       ui->r5->setStyleSheet("background:Red;border:2px ;border-radius:14px;padding:2px 4px");
      if((parm2&0x20)==0x20)
       ui->r6->setStyleSheet("background:Red;border:2px ;border-radius:14px;padding:2px 4px");
      if((parm2&0x40)==0x40)
       ui->r7->setStyleSheet("background:Red;border:2px ;border-radius:14px;padding:2px 4px");
      if((parm2&0x80)==0x80)
       ui->r8->setStyleSheet("background:Red;border:2px ;border-radius:14px;padding:2px 4px");
      /////////////////////////////////////red   hou 8////////////////////////////////////////////////////////

      //============================================================================================
      if((parm3&0x01)==0x01)
       ui->y1->setStyleSheet("background:Yellow;border:2px ;border-radius:14px;padding:2px 4px");
      if((parm3&0x02)==0x02)
       ui->y2->setStyleSheet("background:Yellow;border:2px ;border-radius:14px;padding:2px 4px");
      if((parm3&0x04)==0x04)
       ui->y3->setStyleSheet("background:Yellow;border:2px ;border-radius:14px;padding:2px 4px");
      if((parm3&0x08)==0x08)
       ui->y4->setStyleSheet("background:Yellow;border:2px ;border-radius:14px;padding:2px 4px");
      if((parm3&0x10)==0x10)
       ui->y5->setStyleSheet("background:Yellow;border:2px ;border-radius:14px;padding:2px 4px");
      if((parm3&0x20)==0x20)
       ui->y6->setStyleSheet("background:Yellow;border:2px ;border-radius:14px;padding:2px 4px");
      if((parm3&0x40)==0x40)
       ui->y7->setStyleSheet("background:Yellow;border:2px ;border-radius:14px;padding:2px 4px");
      if((parm3&0x80)==0x80)
       ui->y8->setStyleSheet("background:Yellow;border:2px ;border-radius:14px;padding:2px 4px");

      //===========================================================================================
      if((parm4&0x01)==0x01)
       ui->g1->setStyleSheet("background:Green;border:2px ;border-radius:14px;padding:2px 4px");
      if((parm4&0x02)==0x02)
       ui->g2->setStyleSheet("background:Green;border:2px ;border-radius:14px;padding:2px 4px");
      if((parm4&0x04)==0x04)
       ui->g3->setStyleSheet("background:Green;border:2px ;border-radius:14px;padding:2px 4px");
      if((parm4&0x08)==0x08)
       ui->g4->setStyleSheet("background:Green;border:2px ;border-radius:14px;padding:2px 4px");
      if((parm4&0x10)==0x10)
       ui->g5->setStyleSheet("background:Green;border:2px ;border-radius:14px;padding:2px 4px");
      if((parm4&0x20)==0x20)
       ui->g6->setStyleSheet("background:Green;border:2px ;border-radius:14px;padding:2px 4px");
      if((parm4&0x40)==0x40)
       ui->g7->setStyleSheet("background:Green;border:2px ;border-radius:14px;padding:2px 4px");
      if((parm4&0x80)==0x80)
       ui->g8->setStyleSheet("background:Green;border:2px ;border-radius:14px;padding:2px 4px");
    }
    //=========================================================================================
    //============================================================================================
    //============================================================================================

    if(parm5==0x02)
    {
      if((parm6&0x01)==0x01)
       ui->r9->setStyleSheet("background:Red;border:2px ;border-radius:14px;padding:2px 4px");
      if((parm6&0x02)==0x02)
       ui->r10->setStyleSheet("background:Red;border:2px ;border-radius:14px;padding:2px 4px");
      if((parm6&0x04)==0x04)
       ui->r11->setStyleSheet("background:Red;border:2px ;border-radius:14px;padding:2px 4px");
      if((parm6&0x08)==0x08)
       ui->r12->setStyleSheet("background:Red;border:2px ;border-radius:14px;padding:2px 4px");
      if((parm6&0x10)==0x10)
       ui->r13->setStyleSheet("background:Red;border:2px ;border-radius:14px;padding:2px 4px");
      if((parm6&0x20)==0x20)
       ui->r14->setStyleSheet("background:Red;border:2px ;border-radius:14px;padding:2px 4px");
      if((parm6&0x40)==0x40)
       ui->r15->setStyleSheet("background:Red;border:2px ;border-radius:14px;padding:2px 4px");
      if((parm6&0x80)==0x80)
       ui->r16->setStyleSheet("background:Red;border:2px ;border-radius:14px;padding:2px 4px");
      /////////////////////////////////////////////////////////////////////////////////////////////
      if((parm7&0x01)==0x01)
       ui->y9->setStyleSheet("background:Yellow;border:2px ;border-radius:14px;padding:2px 4px");
      if((parm7&0x02)==0x02)
       ui->y10->setStyleSheet("background:Yellow;border:2px ;border-radius:14px;padding:2px 4px");
      if((parm7&0x04)==0x04)
       ui->y11->setStyleSheet("background:Yellow;border:2px ;border-radius:14px;padding:2px 4px");
      if((parm7&0x08)==0x08)
       ui->y12->setStyleSheet("background:Yellow;border:2px ;border-radius:14px;padding:2px 4px");
      if((parm7&0x10)==0x10)
       ui->y13->setStyleSheet("background:Yellow;border:2px ;border-radius:14px;padding:2px 4px");
      if((parm7&0x20)==0x20)
       ui->y14->setStyleSheet("background:Yellow;border:2px ;border-radius:14px;padding:2px 4px");
      if((parm7&0x40)==0x40)
       ui->y15->setStyleSheet("background:Yellow;border:2px ;border-radius:14px;padding:2px 4px");
      if((parm7&0x80)==0x80)
       ui->y16->setStyleSheet("background:Yellow;border:2px ;border-radius:14px;padding:2px 4px");
      //////////////////////////////////////////////////////////////////////////////////////////
      if((parm8&0x01)==0x01)
       ui->g9->setStyleSheet("background:Green;border:2px ;border-radius:14px;padding:2px 4px");
      if((parm8&0x02)==0x02)
       ui->g10->setStyleSheet("background:Green;border:2px ;border-radius:14px;padding:2px 4px");
      if((parm8&0x04)==0x04)
       ui->g11->setStyleSheet("background:Green;border:2px ;border-radius:14px;padding:2px 4px");
      if((parm8&0x08)==0x08)
       ui->g12->setStyleSheet("background:Green;border:2px ;border-radius:14px;padding:2px 4px");
      if((parm8&0x10)==0x10)
       ui->g13->setStyleSheet("background:Green;border:2px ;border-radius:14px;padding:2px 4px");
      if((parm8&0x20)==0x20)
       ui->g14->setStyleSheet("background:Green;border:2px ;border-radius:14px;padding:2px 4px");
      if((parm8&0x40)==0x40)
       ui->g15->setStyleSheet("background:Green;border:2px ;border-radius:14px;padding:2px 4px");
      if((parm8&0x80)==0x80)
       ui->g16->setStyleSheet("background:Green;border:2px ;border-radius:14px;padding:2px 4px");
    }
}

void DialogPhaseStatus::init92(uchar *buffer)
{
    uchar number=buffer[6];
    uchar value1=buffer[13];
    uchar value2=buffer[14];
    uchar value3=buffer[15];
    uchar value4=buffer[16];
    unsigned int value=(value1<<24)+(value2<<16)+(value3<<8)+value4;
    QString str1="";

    if((number==0x01)&&(value==0x01))
    {
        str1 = str1.fromLocal8Bit("Flash错误");
    }
    if((number==0x01)&&(value==0x02)){ str1 = str1.fromLocal8Bit("时钟芯片错误");}
    if((number==0x01)&&(value==0x03)){ str1 = str1.fromLocal8Bit("网卡芯片错误");}
    if((number==0x01)&&(value==0x04)){ str1 = str1.fromLocal8Bit("GPS模块出错");}

    if((number==0x02))
    {
        QString str3;
        if(value3==0x00)
            str3="块驱动板";
        if(value3==0x01)
            str3="块采集板";
        QString str4="第"+QString::number(value4,10)+
                str3+"没回应";
        QByteArray ba = str4.toLatin1();
        char *mm = ba.data();
        str1 = str1.fromLocal8Bit(mm);
    }

    if(number==0x03)
    {
        QString str2;
        QString str3;
        if(value3==0x01)
            str2="红灯";
        if(value3==0x01)
            str2="黄灯";
        if(value3==0x01)
            str2="绿灯";

        if(value4==0x00)
            str3="无故障";
        if(value4==0x01)
            str3="短路";
        if(value4==0x02)
            str3="断路";
        if(value4==0x03)
            str3="短路不可控";

        QString str4="驱动板电路故障:第"+QString::number(value1,10)+"个驱动板,第"+QString::number(value2,10)+"个灯组"+str2+str3;
        QByteArray ba = str4.toLatin1();
        char *mm = ba.data();

        str1 = str1.fromLocal8Bit(mm);
    }
    if(number==0x04)
    {
        str1 = str1.fromLocal8Bit("读参数返回ok");
    }
    if(number==0x05){str1 = str1.fromLocal8Bit("读参数错误");}
    if(number==0x06)
    {
        QString str4="设"+QString::number(value4,16)+"个对象ok";
        QByteArray ba = str4.toLatin1();
        char *mm = ba.data();
        str1 = str1.fromLocal8Bit(mm);
    }
    if(number==0x07)
    {
        QString str4="设"+QString::number(value4,16)+"个对象错误";
        QByteArray ba = str4.toLatin1();
        char *mm = ba.data();
        str1 = str1.fromLocal8Bit(mm);
    }
    if(number==0x09){str1 = str1.fromLocal8Bit("表内全灭事件");}
    if(number==0x0a){str1 = str1.fromLocal8Bit("表内全红事件");}

    if((number==0x08)&&(value==0x01)){str1 = str1.fromLocal8Bit("表内正常黄闪");}
    if((number==0x08)&&(value==0x02)){str1 = str1.fromLocal8Bit("绿冲突黄闪");}
    if((number==0x08)&&(value==0x03)){str1 = str1.fromLocal8Bit("驱动板错误黄闪");}
    if((number==0x08)&&(value==0x04)){str1 = str1.fromLocal8Bit("灯组电路故障黄闪");}
    if((number==0x08)&&(value==0x05)){str1 = str1.fromLocal8Bit("无表黄闪");}
    if((number==0x08)&&(value==0x06)){str1 = str1.fromLocal8Bit("手动黄闪");}
    if(number==0x0b)
    {
        QString str4="IP:"+QString::number(value1,10)+"-"
                           +QString::number(value2,10)+"-"
                            +QString::number(value3,10)+"-"
                             +QString::number(value4,10)+"访问信号机事件";
        QByteArray ba = str4.toLatin1();
        char *mm = ba.data();
        str1 = str1.fromLocal8Bit(mm);
    }
    if(number==0x0c)
    {
        QString str4="MAC后四位:"+QString::number(value1,10)+"-"
                           +QString::number(value2,10)+"-"
                            +QString::number(value3,10)+"-"
                             +QString::number(value4,10)+"访问信号机事件";
        QByteArray ba = str4.toLatin1();
        char *mm = ba.data();
        str1 = str1.fromLocal8Bit(mm);
    }
    if(number==0x0d)
    {
        QString str3;


        if(value2==0x00)
            str3="无故障";
        if(value2==0x01)
            str3="短路";
        if(value2==0x02)
            str3="断路";
        if(value2==0x03)
            str3="异常";

        QString str4="第"+QString::number(value1,10)+
                "个线圈出现"+str3;
        if(value1==0x01)
            ui->x1->setStyleSheet("background:Red;border:2px ;border-radius:14px;padding:2px 4px");
        if(value1==0x02)
            ui->x1_2->setStyleSheet("background:Red;border:2px ;border-radius:14px;padding:2px 4px");
        if(value1==0x03)
            ui->x1_3->setStyleSheet("background:Red;border:2px ;border-radius:14px;padding:2px 4px");
        if(value1==0x04)
            ui->x1_4->setStyleSheet("background:Red;border:2px ;border-radius:14px;padding:2px 4px");
        if(value1==0x05)
            ui->x1_5->setStyleSheet("background:Red;border:2px ;border-radius:14px;padding:2px 4px");
        if(value1==0x06)
            ui->x1_6->setStyleSheet("background:Red;border:2px ;border-radius:14px;padding:2px 4px");
        if(value1==0x07)
            ui->x1_7->setStyleSheet("background:Red;border:2px ;border-radius:14px;padding:2px 4px");
        if(value1==0x08)
            ui->x1_8->setStyleSheet("background:Red;border:2px ;border-radius:14px;padding:2px 4px");
        if(value1==0x09)
            ui->x1_9->setStyleSheet("background:Red;border:2px ;border-radius:14px;padding:2px 4px");
        if(value1==0x0a)
            ui->x1_10->setStyleSheet("background:Red;border:2px ;border-radius:14px;padding:2px 4px");
        if(value1==0x0b)
            ui->x1_11->setStyleSheet("background:Red;border:2px ;border-radius:14px;padding:2px 4px");
        if(value1==0x0c)
            ui->x1_12->setStyleSheet("background:Red;border:2px ;border-radius:14px;padding:2px 4px");
        if(value1==0x0d)
            ui->x1_13->setStyleSheet("background:Red;border:2px ;border-radius:14px;padding:2px 4px");
        if(value1==0x0e)
            ui->x1_14->setStyleSheet("background:Red;border:2px ;border-radius:14px;padding:2px 4px");
        if(value1==0x0f)
            ui->x1_15->setStyleSheet("background:Red;border:2px ;border-radius:14px;padding:2px 4px");
        if(value1==0x10)
            ui->x1_16->setStyleSheet("background:Red;border:2px ;border-radius:14px;padding:2px 4px");
        if(value1==0x11)
            ui->x1_17->setStyleSheet("background:Red;border:2px ;border-radius:14px;padding:2px 4px");
        if(value1==0x12)
            ui->x1_18->setStyleSheet("background:Red;border:2px ;border-radius:14px;padding:2px 4px");
        if(value1==0x13)
            ui->x1_19->setStyleSheet("background:Red;border:2px ;border-radius:14px;padding:2px 4px");
        if(value1==0x14)
            ui->x1_20->setStyleSheet("background:Red;border:2px ;border-radius:14px;padding:2px 4px");
        if(value1==0x15)
            ui->x1_21->setStyleSheet("background:Red;border:2px ;border-radius:14px;padding:2px 4px");
        if(value1==0x16)
            ui->x1_22->setStyleSheet("background:Red;border:2px ;border-radius:14px;padding:2px 4px");
        if(value1==0x17)
            ui->x1_23->setStyleSheet("background:Red;border:2px ;border-radius:14px;padding:2px 4px");
        if(value1==0x18)
            ui->x1_24->setStyleSheet("background:Red;border:2px ;border-radius:14px;padding:2px 4px");
        if(value1==0x19)
            ui->x1_25->setStyleSheet("background:Red;border:2px ;border-radius:14px;padding:2px 4px");
        if(value1==0x1a)
            ui->x1_26->setStyleSheet("background:Red;border:2px ;border-radius:14px;padding:2px 4px");
        if(value1==0x1b)
            ui->x1_27->setStyleSheet("background:Red;border:2px ;border-radius:14px;padding:2px 4px");
        if(value1==0x1c)
            ui->x1_28->setStyleSheet("background:Red;border:2px ;border-radius:14px;padding:2px 4px");
        if(value1==0x1d)
            ui->x1_29->setStyleSheet("background:Red;border:2px ;border-radius:14px;padding:2px 4px");
        if(value1==0x1e)
            ui->x1_30->setStyleSheet("background:Red;border:2px ;border-radius:14px;padding:2px 4px");
        if(value1==0x1f)
            ui->x1_31->setStyleSheet("background:Red;border:2px ;border-radius:14px;padding:2px 4px");
        if(value1==0x20)
            ui->x1_32->setStyleSheet("background:Red;border:2px ;border-radius:14px;padding:2px 4px");
        if(value1==0x21)
            ui->x1_33->setStyleSheet("background:Red;border:2px ;border-radius:14px;padding:2px 4px");
        if(value1==0x22)
            ui->x1_34->setStyleSheet("background:Red;border:2px ;border-radius:14px;padding:2px 4px");
        if(value1==0x23)
            ui->x1_35->setStyleSheet("background:Red;border:2px ;border-radius:14px;padding:2px 4px");
        if(value1==0x24)
            ui->x1_36->setStyleSheet("background:Red;border:2px ;border-radius:14px;padding:2px 4px");
        if(value1==0x25)
            ui->x1_37->setStyleSheet("background:Red;border:2px ;border-radius:14px;padding:2px 4px");
        if(value1==0x26)
            ui->x1_38->setStyleSheet("background:Red;border:2px ;border-radius:14px;padding:2px 4px");
        if(value1==0x27)
            ui->x1_39->setStyleSheet("background:Red;border:2px ;border-radius:14px;padding:2px 4px");
        if(value1==0x28)
            ui->x1_40->setStyleSheet("background:Red;border:2px ;border-radius:14px;padding:2px 4px");
        if(value1==0x29)
            ui->x1_41->setStyleSheet("background:Red;border:2px ;border-radius:14px;padding:2px 4px");
        if(value1==0x2a)
            ui->x1_42->setStyleSheet("background:Red;border:2px ;border-radius:14px;padding:2px 4px");
        if(value1==0x2b)
            ui->x1_43->setStyleSheet("background:Red;border:2px ;border-radius:14px;padding:2px 4px");
        if(value1==0x2c)
            ui->x1_44->setStyleSheet("background:Red;border:2px ;border-radius:14px;padding:2px 4px");
        if(value1==0x2d)
            ui->x1_45->setStyleSheet("background:Red;border:2px ;border-radius:14px;padding:2px 4px");
        if(value1==0x2e)
            ui->x1_46->setStyleSheet("background:Red;border:2px ;border-radius:14px;padding:2px 4px");
        if(value1==0x2f)
            ui->x1_47->setStyleSheet("background:Red;border:2px ;border-radius:14px;padding:2px 4px");
        if(value1==0x30)
            ui->x1_48->setStyleSheet("background:Red;border:2px ;border-radius:14px;padding:2px 4px");
        if(value1==0x31)
            ui->x1_49->setStyleSheet("background:Red;border:2px ;border-radius:14px;padding:2px 4px");
        if(value1==0x32)
            ui->x1_50->setStyleSheet("background:Red;border:2px ;border-radius:14px;padding:2px 4px");
        if(value1==0x33)
            ui->x1_51->setStyleSheet("background:Red;border:2px ;border-radius:14px;padding:2px 4px");
        if(value1==0x34)
            ui->x1_52->setStyleSheet("background:Red;border:2px ;border-radius:14px;padding:2px 4px");
        if(value1==0x35)
            ui->x1_53->setStyleSheet("background:Red;border:2px ;border-radius:14px;padding:2px 4px");
        if(value1==0x36)
            ui->x1_54->setStyleSheet("background:Red;border:2px ;border-radius:14px;padding:2px 4px");
        if(value1==0x37)
            ui->x1_55->setStyleSheet("background:Red;border:2px ;border-radius:14px;padding:2px 4px");
        if(value1==0x38)
            ui->x1_56->setStyleSheet("background:Red;border:2px ;border-radius:14px;padding:2px 4px");

        QByteArray ba = str4.toLatin1();
        char *mm = ba.data();
        str1 = str1.fromLocal8Bit(mm);
    }
    if(number==0x0e){str1 = str1.fromLocal8Bit("信号机掉电");}
    if(number==0x0f){str1 = str1.fromLocal8Bit("信号机上电");}
    if(number==0xff){ui->display->setText(tr("事件查询结束"));}
    unsigned char localparm1=buffer[9];
    unsigned char localparm2=buffer[10];
    unsigned char localparm3=buffer[11];
    unsigned char localparm4=buffer[12];
    unsigned int localtest=(localparm1<<24)+(localparm2<<16)+(localparm3<<8)+localparm4;
        qDebug()<<"test2:"+QString::number(localtest, 16);
            qDebug()<<"localparm1:"+QString::number(localparm1, 16);
            qDebug()<<"localparm2:"+QString::number(localparm2, 16);
            qDebug()<<"localparm3:"+QString::number(localparm3, 16);
            qDebug()<<"localparm4:"+QString::number(localparm4, 16);
    //qDebug()<<"time#########################:"+QString::number(localtest, 16);
    //产生时间结构体
    struct time_type time3;
    int b = unix_time_to_rtc_time3(localtest,&time3);

    // qDebug()<< "the funtion of unix_time_to_rtc_time:"+QString::number(b, 10);
    unsigned int year=(int)time3.year;
    unsigned int month=(int)time3.month;
    unsigned int days=(int)time3.day;
    unsigned int hour=(int)time3.hour;
    unsigned int min=(int)time3.min;
    unsigned int sec=(int)time3.sec;
    ui->textBrowser->append(tr("时间:")+tr("     ")+
                            QString::number(year,10)+tr("年")+
                            QString::number(month,10)+tr("月")+
                            QString::number(days,10)+tr("日")+
                            QString::number(hour,10)+tr("时")+
                            QString::number(min,10)+tr("分")+
                            QString::number(sec,10)+tr("秒")+
                            tr("    发生事件:")+str1
                            );
    QFile file(tr("日志.txt"));
    if (file.open(QIODevice::WriteOnly|QIODevice::Append))
    {
        QTextStream out(&file);
        out <<tr("时间:")+tr("     ")+
               QString::number(year,10)+tr("年")+
               QString::number(month,10)+tr("月")+
               QString::number(days,10)+tr("日")+
               QString::number(hour,10)+tr("时")+
               QString::number(min,10)+tr("分")+
               QString::number(sec,10)+tr("秒")+
               tr("    发生事件:")+str1+tr("\n");//ui->textBrowser->toPlainText();
    }else
    {
        ui->display->setText(tr("文件打开失败!"));
    }
}

void DialogPhaseStatus::rev()
{
    qDebug()<<"~~~~~~~~~~~~~~~~~~";
    char RecBuf[4096];
    memset(RecBuf,NULL,4096);
    QString RecText;
    int Rlen;
    if(com->isopen())
    {
        Rlen=com->GetDataLen();
        if((Rlen>0))//&&((Rlen==8)||(Rlen==28))
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

void DialogPhaseStatus::warming()
{
    ui->display->clear();
    ui->display->setText(tr("失败!请重试!"));
}

void DialogPhaseStatus::sendb1()
{
    char buffer[60];
    buffer[0]=0x02;
    buffer[1]=0x00;
    buffer[2]=0x04;
    buffer[3]=0x80;
    buffer[4]=0xb1;
    buffer[5]=0x00;
    buffer[6]=0x00;
    int len=7;
    unsigned short rssum=CommVerify((unsigned char *)buffer,len);
    buffer[len]=rssum/256;
    buffer[len+1]=rssum%256;
    this->com->WriteCom(buffer,len+2);
}

void DialogPhaseStatus::init96iii(uchar *buffer)
{
    unsigned char parm1=*(buffer+7);
    unsigned char parm2=*(buffer+8);
    unsigned char parm3=*(buffer+9);
    unsigned char parm4=*(buffer+10);

    unsigned char parm5=*(buffer+11);
    unsigned char parm6=*(buffer+12);
    unsigned char parm7=*(buffer+13);
    unsigned char parm8=*(buffer+14);
    //===============================================
    if(parm1==0x01)
    {
      if((parm2&0x01)==0x01)
       ui->r1->setStyleSheet("background:Red;border:2px ;border-radius:14px;padding:2px 4px");
      if((parm2&0x02)==0x02)
       ui->r2->setStyleSheet("background:Red;border:2px ;border-radius:14px;padding:2px 4px");
      if((parm2&0x04)==0x04)
       ui->r3->setStyleSheet("background:Red;border:2px ;border-radius:14px;padding:2px 4px");
      if((parm2&0x08)==0x08)
       ui->r4->setStyleSheet("background:Red;border:2px ;border-radius:14px;padding:2px 4px");
      if((parm2&0x10)==0x10)
       ui->r5->setStyleSheet("background:Red;border:2px ;border-radius:14px;padding:2px 4px");
      if((parm2&0x20)==0x20)
       ui->r6->setStyleSheet("background:Red;border:2px ;border-radius:14px;padding:2px 4px");
      if((parm2&0x40)==0x40)
       ui->r7->setStyleSheet("background:Red;border:2px ;border-radius:14px;padding:2px 4px");
      if((parm2&0x80)==0x80)
       ui->r8->setStyleSheet("background:Red;border:2px ;border-radius:14px;padding:2px 4px");
      /////////////////////////////////////red   hou 8////////////////////////////////////////////////////////

      //============================================================================================
      if((parm3&0x01)==0x01)
       ui->y1->setStyleSheet("background:Yellow;border:2px ;border-radius:14px;padding:2px 4px");
      if((parm3&0x02)==0x02)
       ui->y2->setStyleSheet("background:Yellow;border:2px ;border-radius:14px;padding:2px 4px");
      if((parm3&0x04)==0x04)
       ui->y3->setStyleSheet("background:Yellow;border:2px ;border-radius:14px;padding:2px 4px");
      if((parm3&0x08)==0x08)
       ui->y4->setStyleSheet("background:Yellow;border:2px ;border-radius:14px;padding:2px 4px");
      if((parm3&0x10)==0x10)
       ui->y5->setStyleSheet("background:Yellow;border:2px ;border-radius:14px;padding:2px 4px");
      if((parm3&0x20)==0x20)
       ui->y6->setStyleSheet("background:Yellow;border:2px ;border-radius:14px;padding:2px 4px");
      if((parm3&0x40)==0x40)
       ui->y7->setStyleSheet("background:Yellow;border:2px ;border-radius:14px;padding:2px 4px");
      if((parm3&0x80)==0x80)
       ui->y8->setStyleSheet("background:Yellow;border:2px ;border-radius:14px;padding:2px 4px");

      //===========================================================================================
      if((parm4&0x01)==0x01)
       ui->g1->setStyleSheet("background:Green;border:2px ;border-radius:14px;padding:2px 4px");
      if((parm4&0x02)==0x02)
       ui->g2->setStyleSheet("background:Green;border:2px ;border-radius:14px;padding:2px 4px");
      if((parm4&0x04)==0x04)
       ui->g3->setStyleSheet("background:Green;border:2px ;border-radius:14px;padding:2px 4px");
      if((parm4&0x08)==0x08)
       ui->g4->setStyleSheet("background:Green;border:2px ;border-radius:14px;padding:2px 4px");
      if((parm4&0x10)==0x10)
       ui->g5->setStyleSheet("background:Green;border:2px ;border-radius:14px;padding:2px 4px");
      if((parm4&0x20)==0x20)
       ui->g6->setStyleSheet("background:Green;border:2px ;border-radius:14px;padding:2px 4px");
      if((parm4&0x40)==0x40)
       ui->g7->setStyleSheet("background:Green;border:2px ;border-radius:14px;padding:2px 4px");
      if((parm4&0x80)==0x80)
       ui->g8->setStyleSheet("background:Green;border:2px ;border-radius:14px;padding:2px 4px");
    }
    //=========================================================================================
    //============================================================================================
    //============================================================================================
    if(parm5==0x02)
    {
      if((parm6&0x01)==0x01)
       ui->r9->setStyleSheet("background:Red;border:2px ;border-radius:14px;padding:2px 4px");
      if((parm6&0x02)==0x02)
       ui->r10->setStyleSheet("background:Red;border:2px ;border-radius:14px;padding:2px 4px");
      if((parm6&0x04)==0x04)
       ui->r11->setStyleSheet("background:Red;border:2px ;border-radius:14px;padding:2px 4px");
      if((parm6&0x08)==0x08)
       ui->r12->setStyleSheet("background:Red;border:2px ;border-radius:14px;padding:2px 4px");
      if((parm6&0x10)==0x10)
       ui->r13->setStyleSheet("background:Red;border:2px ;border-radius:14px;padding:2px 4px");
      if((parm6&0x20)==0x20)
       ui->r14->setStyleSheet("background:Red;border:2px ;border-radius:14px;padding:2px 4px");
      if((parm6&0x40)==0x40)
       ui->r15->setStyleSheet("background:Red;border:2px ;border-radius:14px;padding:2px 4px");
      if((parm6&0x80)==0x80)
       ui->r16->setStyleSheet("background:Red;border:2px ;border-radius:14px;padding:2px 4px");
      /////////////////////////////////////////////////////////////////////////////////////////////
      if((parm7&0x01)==0x01)
       ui->y9->setStyleSheet("background:Yellow;border:2px ;border-radius:14px;padding:2px 4px");
      if((parm7&0x02)==0x02)
       ui->y10->setStyleSheet("background:Yellow;border:2px ;border-radius:14px;padding:2px 4px");
      if((parm7&0x04)==0x04)
       ui->y11->setStyleSheet("background:Yellow;border:2px ;border-radius:14px;padding:2px 4px");
      if((parm7&0x08)==0x08)
       ui->y12->setStyleSheet("background:Yellow;border:2px ;border-radius:14px;padding:2px 4px");
      if((parm7&0x10)==0x10)
       ui->y13->setStyleSheet("background:Yellow;border:2px ;border-radius:14px;padding:2px 4px");
      if((parm7&0x20)==0x20)
       ui->y14->setStyleSheet("background:Yellow;border:2px ;border-radius:14px;padding:2px 4px");
      if((parm7&0x40)==0x40)
       ui->y15->setStyleSheet("background:Yellow;border:2px ;border-radius:14px;padding:2px 4px");
      if((parm7&0x80)==0x80)
       ui->y16->setStyleSheet("background:Yellow;border:2px ;border-radius:14px;padding:2px 4px");
      //////////////////////////////////////////////////////////////////////////////////////////
      if((parm8&0x01)==0x01)
       ui->g9->setStyleSheet("background:Green;border:2px ;border-radius:14px;padding:2px 4px");
      if((parm8&0x02)==0x02)
       ui->g10->setStyleSheet("background:Green;border:2px ;border-radius:14px;padding:2px 4px");
      if((parm8&0x04)==0x04)
       ui->g11->setStyleSheet("background:Green;border:2px ;border-radius:14px;padding:2px 4px");
      if((parm8&0x08)==0x08)
       ui->g12->setStyleSheet("background:Green;border:2px ;border-radius:14px;padding:2px 4px");
      if((parm8&0x10)==0x10)
       ui->g13->setStyleSheet("background:Green;border:2px ;border-radius:14px;padding:2px 4px");
      if((parm8&0x20)==0x20)
       ui->g14->setStyleSheet("background:Green;border:2px ;border-radius:14px;padding:2px 4px");
      if((parm8&0x40)==0x40)
       ui->g15->setStyleSheet("background:Green;border:2px ;border-radius:14px;padding:2px 4px");
      if((parm8&0x80)==0x80)
       ui->g16->setStyleSheet("background:Green;border:2px ;border-radius:14px;padding:2px 4px");
    }
}
void DialogPhaseStatus::setb96(){}
void DialogPhaseStatus::inita0(uchar *buffer)
{
    ui->x1->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->x1_2->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->x1_3->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->x1_4->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->x1_5->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");

    ui->x1_6->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->x1_7->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->x1_8->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->x1_9->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->x1_10->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");

    ui->x1_11->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->x1_12->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->x1_13->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->x1_14->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->x1_15->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");

    ui->x1_16->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->x1_17->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->x1_18->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->x1_19->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->x1_20->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");

    ui->x1_21->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->x1_22->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->x1_23->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->x1_24->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->x1_25->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");

    ui->x1_26->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->x1_27->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->x1_28->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->x1_29->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->x1_30->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");

    ui->x1_31->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->x1_32->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->x1_33->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->x1_34->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->x1_35->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");

    ui->x1_36->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->x1_37->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->x1_38->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->x1_39->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->x1_40->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");

    ui->x1_41->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->x1_42->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->x1_43->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->x1_44->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->x1_45->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");

    ui->x1_46->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->x1_47->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->x1_48->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->x1_49->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->x1_50->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");

    ui->x1_51->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->x1_52->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->x1_53->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->x1_54->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->x1_55->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");


    ui->x1_56->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    uchar parm1=buffer[7];
    uchar parm2=buffer[8];
    uchar parm3=buffer[9];
    uchar parm4=buffer[10];
    uchar parm5=buffer[11];
    uchar parm6=buffer[12];
    uchar parm7=buffer[13];

    if((parm1&0x01)==0x01)
        ui->x1->setStyleSheet("background:Green;border:2px ;border-radius:14px;padding:2px 4px");
    if((parm1&0x02)==0x02)
        ui->x1_2->setStyleSheet("background:Green;border:2px ;border-radius:14px;padding:2px 4px");
    if((parm1&0x04)==0x04)
        ui->x1_3->setStyleSheet("background:Green;border:2px ;border-radius:14px;padding:2px 4px");
    if((parm1&0x08)==0x08)
        ui->x1_4->setStyleSheet("background:Green;border:2px ;border-radius:14px;padding:2px 4px");

    if((parm1&0x10)==0x10)
        ui->x1_5->setStyleSheet("background:Green;border:2px ;border-radius:14px;padding:2px 4px");
    if((parm1&0x20)==0x20)
        ui->x1_6->setStyleSheet("background:Green;border:2px ;border-radius:14px;padding:2px 4px");
    if((parm1&0x40)==0x40)
        ui->x1_7->setStyleSheet("background:Green;border:2px ;border-radius:14px;padding:2px 4px");
    if((parm1&0x80)==0x80)
        ui->x1_8->setStyleSheet("background:Green;border:2px ;border-radius:14px;padding:2px 4px");

        if((parm2&0x01)==0x01)
            ui->x1_9->setStyleSheet("background:Green;border:2px ;border-radius:14px;padding:2px 4px");
        if((parm2&0x02)==0x02)
            ui->x1_10->setStyleSheet("background:Green;border:2px ;border-radius:14px;padding:2px 4px");
        if((parm2&0x04)==0x04)
            ui->x1_11->setStyleSheet("background:Green;border:2px ;border-radius:14px;padding:2px 4px");
        if((parm2&0x08)==0x08)
            ui->x1_12->setStyleSheet("background:Green;border:2px ;border-radius:14px;padding:2px 4px");

        if((parm2&0x10)==0x10)
            ui->x1_13->setStyleSheet("background:Green;border:2px ;border-radius:14px;padding:2px 4px");
        if((parm2&0x20)==0x20)
            ui->x1_14->setStyleSheet("background:Green;border:2px ;border-radius:14px;padding:2px 4px");
        if((parm2&0x40)==0x40)
            ui->x1_15->setStyleSheet("background:Green;border:2px ;border-radius:14px;padding:2px 4px");
        if((parm2&0x80)==0x80)
            ui->x1_16->setStyleSheet("background:Green;border:2px ;border-radius:14px;padding:2px 4px");
    if((parm3&0x01)==0x01)
        ui->x1_17->setStyleSheet("background:Green;border:2px ;border-radius:14px;padding:2px 4px");
    if((parm3&0x02)==0x02)
        ui->x1_18->setStyleSheet("background:Green;border:2px ;border-radius:14px;padding:2px 4px");
    if((parm3&0x04)==0x04)
        ui->x1_19->setStyleSheet("background:Green;border:2px ;border-radius:14px;padding:2px 4px");
    if((parm3&0x08)==0x08)
        ui->x1_20->setStyleSheet("background:Green;border:2px ;border-radius:14px;padding:2px 4px");

    if((parm3&0x10)==0x10)
        ui->x1_21->setStyleSheet("background:Green;border:2px ;border-radius:14px;padding:2px 4px");
    if((parm3&0x20)==0x20)
        ui->x1_22->setStyleSheet("background:Green;border:2px ;border-radius:14px;padding:2px 4px");
    if((parm3&0x40)==0x40)
        ui->x1_23->setStyleSheet("background:Green;border:2px ;border-radius:14px;padding:2px 4px");
    if((parm3&0x80)==0x80)
        ui->x1_24->setStyleSheet("background:Green;border:2px ;border-radius:14px;padding:2px 4px");

        if((parm4&0x01)==0x01)
            ui->x1_25->setStyleSheet("background:Green;border:2px ;border-radius:14px;padding:2px 4px");
        if((parm4&0x02)==0x02)
            ui->x1_26->setStyleSheet("background:Green;border:2px ;border-radius:14px;padding:2px 4px");
        if((parm4&0x04)==0x04)
            ui->x1_27->setStyleSheet("background:Green;border:2px ;border-radius:14px;padding:2px 4px");
        if((parm4&0x08)==0x08)
            ui->x1_28->setStyleSheet("background:Green;border:2px ;border-radius:14px;padding:2px 4px");

        if((parm4&0x10)==0x10)
            ui->x1_29->setStyleSheet("background:Green;border:2px ;border-radius:14px;padding:2px 4px");
        if((parm4&0x20)==0x20)
            ui->x1_30->setStyleSheet("background:Green;border:2px ;border-radius:14px;padding:2px 4px");
        if((parm4&0x40)==0x40)
            ui->x1_31->setStyleSheet("background:Green;border:2px ;border-radius:14px;padding:2px 4px");
        if((parm4&0x80)==0x80)
            ui->x1_32->setStyleSheet("background:Green;border:2px ;border-radius:14px;padding:2px 4px");

    if((parm5&0x01)==0x01)
        ui->x1_33->setStyleSheet("background:Green;border:2px ;border-radius:14px;padding:2px 4px");
    if((parm5&0x02)==0x02)
        ui->x1_34->setStyleSheet("background:Green;border:2px ;border-radius:14px;padding:2px 4px");
    if((parm5&0x04)==0x04)
        ui->x1_35->setStyleSheet("background:Green;border:2px ;border-radius:14px;padding:2px 4px");
    if((parm5&0x08)==0x08)
        ui->x1_36->setStyleSheet("background:Green;border:2px ;border-radius:14px;padding:2px 4px");

    if((parm5&0x10)==0x10)
        ui->x1_37->setStyleSheet("background:Green;border:2px ;border-radius:14px;padding:2px 4px");
    if((parm5&0x20)==0x20)
        ui->x1_38->setStyleSheet("background:Green;border:2px ;border-radius:14px;padding:2px 4px");
    if((parm5&0x40)==0x40)
        ui->x1_39->setStyleSheet("background:Green;border:2px ;border-radius:14px;padding:2px 4px");
    if((parm5&0x80)==0x80)
        ui->x1_40->setStyleSheet("background:Green;border:2px ;border-radius:14px;padding:2px 4px");

        if((parm6&0x01)==0x01)
            ui->x1_41->setStyleSheet("background:Green;border:2px ;border-radius:14px;padding:2px 4px");
        if((parm6&0x02)==0x02)
            ui->x1_42->setStyleSheet("background:Green;border:2px ;border-radius:14px;padding:2px 4px");
        if((parm6&0x04)==0x04)
            ui->x1_43->setStyleSheet("background:Green;border:2px ;border-radius:14px;padding:2px 4px");
        if((parm6&0x08)==0x08)
            ui->x1_44->setStyleSheet("background:Green;border:2px ;border-radius:14px;padding:2px 4px");

        if((parm6&0x10)==0x10)
            ui->x1_45->setStyleSheet("background:Green;border:2px ;border-radius:14px;padding:2px 4px");
        if((parm6&0x20)==0x20)
            ui->x1_46->setStyleSheet("background:Green;border:2px ;border-radius:14px;padding:2px 4px");
        if((parm6&0x40)==0x40)
            ui->x1_47->setStyleSheet("background:Green;border:2px ;border-radius:14px;padding:2px 4px");
        if((parm6&0x80)==0x80)
            ui->x1_48->setStyleSheet("background:Green;border:2px ;border-radius:14px;padding:2px 4px");

    if((parm7&0x01)==0x01)
        ui->x1_49->setStyleSheet("background:Green;border:2px ;border-radius:14px;padding:2px 4px");
    if((parm7&0x02)==0x02)
        ui->x1_50->setStyleSheet("background:Green;border:2px ;border-radius:14px;padding:2px 4px");
    if((parm7&0x04)==0x04)
        ui->x1_51->setStyleSheet("background:Green;border:2px ;border-radius:14px;padding:2px 4px");
    if((parm7&0x08)==0x08)
        ui->x1_52->setStyleSheet("background:Green;border:2px ;border-radius:14px;padding:2px 4px");

    if((parm7&0x10)==0x10)
        ui->x1_53->setStyleSheet("background:Green;border:2px ;border-radius:14px;padding:2px 4px");
    if((parm7&0x20)==0x20)
        ui->x1_54->setStyleSheet("background:Green;border:2px ;border-radius:14px;padding:2px 4px");
    if((parm7&0x40)==0x40)
        ui->x1_55->setStyleSheet("background:Green;border:2px ;border-radius:14px;padding:2px 4px");
    if((parm7&0x80)==0x80)
        ui->x1_56->setStyleSheet("background:Green;border:2px ;border-radius:14px;padding:2px 4px");
}

void DialogPhaseStatus::sendd1()
{
    char buffer[60];
    buffer[0]=0x02;
    buffer[1]=0x00;
    buffer[2]=0x04;
    buffer[3]=0x81;
    buffer[4]=0xd1;
    buffer[5]=0x00;
    buffer[6]=0xaa;
    int len=7;
    unsigned short rssum=CommVerify((unsigned char *)buffer,len);
    buffer[len]=rssum/256;
    buffer[len+1]=rssum%256;
    this->com->WriteCom(buffer,len+2);
}

void DialogPhaseStatus::setbd1()
{
    char buffer[60];
    buffer[0]=0x02;
    buffer[1]=0x00;
    buffer[2]=0x04;
    buffer[3]=0x81;
    buffer[4]=0xd1;
    buffer[5]=0x00;
    buffer[6]=0x00;
    int len=7;
    unsigned short rssum=CommVerify((unsigned char *)buffer,len);
    buffer[len]=rssum/256;
    buffer[len+1]=rssum%256;
    this->com->WriteCom(buffer,len+2);
}


void DialogPhaseStatus::on_butfind_clicked()
{
    ui->display->clear();
    {
    ui->r1->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->r2->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->r3->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->r4->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->r5->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->r6->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->r7->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->r8->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
   //============================================================================================
    ui->y1->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->y2->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->y3->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->y4->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->y5->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->y6->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->y7->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->y8->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
   //===========================================================================================
    ui->g1->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->g2->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->g3->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->g4->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->g5->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->g6->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->g7->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->g8->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->r9->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->r10->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->r11->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->r12->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->r13->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->r14->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->r15->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->r16->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
   /////////////////////////////////////////////////////////////////////////////////////////////
    ui->y9->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->y10->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->y11->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->y12->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->y13->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->y14->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->y15->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->y16->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
   //////////////////////////////////////////////////////////////////////////////////////////
    ui->g9->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->g10->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->g11->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->g12->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->g13->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->g14->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->g15->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
    ui->g16->setStyleSheet("background:Black;border:2px ;border-radius:14px;padding:2px 4px");
   ////////////////////////////////////
    }
    ui->display->setText(tr("查询中......"));
    QTimer::singleShot(1,this,SLOT(sendb1()));
    revtimer->start(500);
    connect(revtimer,SIGNAL(timeout()),this,SLOT(rev()));
    //timeout->start(3000);
}


void DialogPhaseStatus::on_butquit_clicked()
{
    QTimer::singleShot(1,this,SLOT(setbd1()));
    revtimer->start(20);
    QTimer::singleShot(2000,this,SLOT(close()));
}
