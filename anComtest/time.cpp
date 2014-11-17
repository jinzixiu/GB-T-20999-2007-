#include "time.h"

//union unix_time_type unix_time;
//struct time_type g_current_time;
//int unix_time_to_rtc_time(unsigned int unix_time, struct time_type *rtc);
//unsigned int rtc_time_to_unix_time(struct time_type rtc);
//static unsigned int *months(unsigned int year);

//static unsigned int *months(unsigned int year)
//{
//    if((year % 4 == 0) && (year % 100 != 0 || year % 400 == 0))
//    {
//        return leapyear;
//    }

//    return nonleapyear;
//}

//unsigned rtc_time_to_unix_time(struct time_type rtc)
//{
//    // First, accumulate days since January 1, 2001.
//    // Using 2001 instead of 1970 makes the leap-year
//    // handling easier (see SecondsToUTC), because
//    // it is at the beginning of the 4-, 100-, and 400-year cycles.
//    unsigned int day = 0;
//    unsigned int year = rtc.year+2000;
//    // Rewrite year to be >= 2001.
//    if(year < 2001)
//    {
//        unsigned int n = (2001 - year) / 400 + 1;
//        year += 400 * n;
//        day -= DAYS_PER_400YEARS * n;
//    }

//    // Add in days from 400-year cycles.
//    unsigned int n = (year - 2001) / 400;
//    year -= 400 * n;
//    day += DAYS_PER_400YEARS * n;

//    // Add in 100-year cycles.
//    n = (year - 2001) / 100;
//    year -= 100 * n;
//    day += DAYS_PER_100YEARS * n;

//    // Add in 4-year cycles.
//    n = (year - 2001) / 4;
//    year -= 4 * n;
//    day += DAYS_PER_4YEARS * n;

//    // Add in non-leap years.
//    n = year - 2001;
//    day += 365 * n;

//    // Add in days this year.
//    unsigned int *month = months(rtc.year);
//    int m = 0;
//    for(m = 0; m < rtc.month - 1; m++)
//    {
//        day += month[m];
//    }
//    day += rtc.day - 1;

//    // Convert days to seconds since January 1, 2001.
//    unsigned int sec = day * SECONDS_PER_DAY;

//    // Add in time elapsed today.
//    sec += rtc.hour * 3600;
//    sec += rtc.min * 60;
//    sec += rtc.sec;

//    // Convert from seconds since 2001 to seconds since 1970.
//    sec += DAYS_1970_TO_2001 * SECONDS_PER_DAY;
//    sec -= SECONDS_OF_TIME_ZONE;

//    return sec;
//}

//int unix_time_to_rtc_time(unsigned int unix_time, struct time_type *rtc)
//{

//    unix_time += SECONDS_OF_TIME_ZONE;

//    int day = unix_time / SECONDS_PER_DAY;
//    unix_time -= day * SECONDS_PER_DAY;
//    if(day < 0) //?
//    {
//        unix_time += SECONDS_PER_DAY;
//        day--;
//    }

//    rtc->hour = unix_time / 3600;
//    rtc->min = (unix_time / 60) % 60;
//    rtc->sec = unix_time % 60;

//    // Day 0 = January 1, 1970 was a Thursday
//    rtc->week = (day + Thursday) % 7;
//    if(rtc->week < 0)
//    {
//        rtc->week += 7;
//    }
//    if(rtc->week==0){
//        rtc->week=7;
//    }

//    // Change day from 0 = 1970 to 0 = 2001,
//    // to make leap year calculations easier
//    // (2001 begins 4-, 100-, and 400-year cycles ending in a leap year.)
//    day -= DAYS_1970_TO_2001;
//    unsigned int year = 2001;
//    if(day < 0)
//    {
//        // Go back enough 400 year cycles to make day positive.
//        unsigned int n = -day / DAYS_PER_400YEARS + 1;
//        year -= 400 * n;
//        day += DAYS_PER_400YEARS * n;
//    }

//    // Cut off 400 year cycles.
//    unsigned int n = day / DAYS_PER_400YEARS;
//    year += 400 * n;
//    day -= DAYS_PER_400YEARS * n;

//    // Cut off 100-year cycles
//    n = day / DAYS_PER_100YEARS;
//    if(n > 3)
//    {
//        n = 3;
//    }
//    year += 100 * n;
//    day -= DAYS_PER_100YEARS * n;

//    // Cut off 4-year cycles
//    n = day / DAYS_PER_4YEARS;
//    if(n > 24)
//    {  // happens on last day of 100th year
//        n = 24;
//    }
//    year += 4 * n;
//    day -= DAYS_PER_4YEARS * n;

//    // Cut off non-leap years.
//    n = day / 365;
//    if(n > 3)
//    {
//        // happens on last day of 4th year
//        n = 3;
//    }
//    year += n;
//    day -= 365 * n;
//    rtc->year = year%100;

//    unsigned int *month = months(year);
//    int m = 0;
//    for(; m < 12 && day >= month[0]; m++)
//    {
//        day -= month[m];
//    }

//    rtc->month = m + 1;
//    rtc->day = day + 1;

//    return 0;
//}

