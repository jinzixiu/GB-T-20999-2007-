#include "dialogevent.h"
#include "ui_dialogevent.h"
#include "unit.h"
#include <QDebug>
 #include <QFile>
#include "dlgpubparm.h"
/*************************************************/
union unix_time_type unix_time2;
struct time_type g_current_time2;
//int unix_time_to_rtc_time(unsigned int unix_time2, struct time_type *rtc);
//unsigned int rtc_time_to_unix_time(struct time_type rtc);
//static unsigned int *months(unsigned int year);
/*************************************************/
static unsigned int *months(unsigned int year)
{
    if((year % 4 == 0) && (year % 100 != 0 || year % 400 == 0))
    {
        return leapyear;
    }

    return nonleapyear;
}

unsigned rtc_time_to_unix_time2(struct time_type rtc)
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

int unix_time_to_rtc_time2(unsigned int unix_time2, struct time_type *rtc)
{

    unix_time2 += SECONDS_OF_TIME_ZONE;

    int day = unix_time2 / SECONDS_PER_DAY;
    unix_time2 -= day * SECONDS_PER_DAY;
    if(day < 0) //?
    {
        unix_time2 += SECONDS_PER_DAY;
        day--;
    }

    rtc->hour = unix_time2 / 3600;
    rtc->min = (unix_time2 / 60) % 60;
    rtc->sec = unix_time2 % 60;

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



DialogEvent::DialogEvent(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogEvent)
{
    ui->setupUi(this);
    this->com=new CPubSub();
    this->revtimer=new QTimer();
    this->timeout=new QTimer();
    connect(timeout,SIGNAL(timeout()),this,SLOT(warming()));
}

DialogEvent::~DialogEvent()
{
    delete ui;
    deleteLater();
}
void DialogEvent::setcom(CPubSub *com)
{
    this->com=com;
}

void DialogEvent::dealwith(uchar* rec,int len)
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

        if((uchar)*(s+3)==0x83)//查询命令处理
        {
            if(((uchar)(*(s+4))==0x91)&&(len>18))
            {
                init91((uchar*)s);
                //ui->display->setText(tr("查询成功!"));
                set91();
                timeout->stop();
            }
        }

        if((uchar)*(s+3)==0x84)//查询命令处理
        {
            if((uchar)(*(s+4))==0xc8)
            {

                ui->display->setText(tr("查询成功!"));
                timeout->stop();
            }
            if((uchar)(*(s+4))==0x79)
            {

                ui->display->setText(tr("查询成功!"));
                timeout->stop();
            }
        }
        if((uchar)*(s+3)==0x85)//设置成功命令
        {
            if((uchar)(*(s+4))==0xd2)
            {
                //ui->display->setText(tr("设置成功!"));
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

void DialogEvent::init91(uchar *buffer)
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
    int b = unix_time_to_rtc_time2(localtest,&time3);

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



}

void DialogEvent::rev()
{
    qDebug()<<"~~~~~~~~~~~~~~~~~~";
    char RecBuf[4096];
    memset(RecBuf,NULL,4096);
    QString RecText;
    int Rlen;
    if(com->isopen())
    {
        Rlen=com->GetDataLen();
        if((Rlen>0)&&((Rlen>17)||(Rlen==8)))
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

void DialogEvent::warming()
{
    ui->display->clear();
    ui->display->setText(tr("失败!请重试!"));
}
void DialogEvent::sendd2()
{
    struct time_type time;
    time.year=(char)(ui->local1->text().toInt());
    time.month=(char)(ui->local2->text().toInt());
    time.day=(char)(ui->local3->text().toInt());
    time.hour=(char)(ui->local4->text().toInt());
    time.min=(char)(ui->local5->text().toInt());
    time.sec=(char)(ui->local6->text().toInt());
    unsigned int sectime=rtc_time_to_unix_time2(time);
//    qDebug()<<"==================================================";
//    qDebug()<<"four:"+QString::number(sectime,16);
//    qDebug()<<"==================================================";
    char four=(char)(sectime>>24);
    char whree=(char)(sectime>>16);
    char two=(char)(sectime>>8);
    char one =(char)(sectime);


    struct time_type time2;
    time2.year=(char)(ui->local1_2->text().toInt());
    time2.month=(char)(ui->local2_2->text().toInt());
    time2.day=(char)(ui->local3_2->text().toInt());
    time2.hour=(char)(ui->local4_2->text().toInt());
    time2.min=(char)(ui->local5_2->text().toInt());
    time2.sec=(char)(ui->local6_2->text().toInt());
    unsigned int sectime2=rtc_time_to_unix_time2(time2);
//    qDebug()<<"==================================================";
//    qDebug()<<"four:"+QString::number(sectime,16);
//    qDebug()<<"==================================================";
    char four2=(char)(sectime2>>24);
    char whree2=(char)(sectime2>>16);
    char two2=(char)(sectime2>>8);
    char one2=(char)(sectime2);



    char buffer[60];
    buffer[0]=0x02;
    buffer[1]=0x00;
    buffer[2]=0x0d;
    buffer[3]=0x81;
    buffer[4]=0xd2;
    buffer[5]=0x00;
    buffer[6]=0xaa;
    buffer[7]=0xbb;
    buffer[8]=four;
    buffer[9]=whree;
    buffer[10]=two;
    buffer[11]=one;

    buffer[12]=four2;
    buffer[13]=whree2;
    buffer[14]=two2;
    buffer[15]=one2;
    int len=16;
    unsigned short rssum=CommVerify((unsigned char *)buffer,len);
    buffer[len]=rssum/256;
    buffer[len+1]=rssum%256;
    this->com->WriteCom(buffer,len+2);
}

void DialogEvent::set91()
{
    char buffer[60];
    buffer[0]=0x02;
    buffer[1]=0x00;
    buffer[2]=0x04;
    buffer[3]=0x81;
    buffer[4]=0x91;
    buffer[5]=0x00;
    buffer[6]=0x00;
    int len=7;
    unsigned short rssum=CommVerify((unsigned char *)buffer,len);
    buffer[len]=rssum/256;
    buffer[len+1]=rssum%256;
    this->com->WriteCom(buffer,len+2);
}

void DialogEvent::on_butfind_clicked()
{
    ui->display->clear();
    ui->display->setText(tr("查询中......"));
    QTimer::singleShot(1,this,SLOT(sendd2()));
    revtimer->start(100);
    connect(revtimer,SIGNAL(timeout()),this,SLOT(rev()));
    timeout->start(3000);
}

void DialogEvent::on_butclear_clicked()
{
    ui->textBrowser->clear();
}

void DialogEvent::on_butsave_clicked()
{
    if(!QFile::exists(ui->filename->text()+"txt"))
    {
        QFile file(ui->filename->text()+"txt");
        if (file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            QTextStream out(&file);
            out <<ui->textBrowser->toPlainText();
        }else
        {
            ui->display->setText(tr("文件打开失败!"));
        }
    }
        else
    {
        ui->display->setText(tr("文件已存在!"));
    }
}
