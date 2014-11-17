#ifndef TIME_H
#define TIME_H
/******************************时间转换函数的定义*********************************/
#define		SECONDS_PER_DAY         (24 * 60 * 60)
#define		DAYS_PER_400YEARS       (365 * 400 + 97)
#define		DAYS_PER_100YEARS       (365 * 100 + 24)
#define		DAYS_PER_4YEARS         (365 * 4 + 1)
#define		DAYS_1970_TO_2001       (31 * 365 + 8)
#define     SECONDS_OF_TIME_ZONE    (8 * 3600)
/******************************全局变量*********************************/
//平年每个月的日数
static unsigned int nonleapyear[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

//闰年每个月的日数
static unsigned int leapyear[] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
union unix_time_type
{
    unsigned int time;
    unsigned char buf[4];

};
struct time_type
{
    unsigned char sec;
    unsigned char min;
    unsigned char hour;
    char week;
    unsigned char day;
    unsigned char month;
    unsigned char year;

};

enum
{
    Sunday = 0,
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
};

#endif // TIME_H
