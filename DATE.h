#ifndef DATE_H
#define DATE_H
#include<iostream>
enum week {Non,Mon,Tue,Wed,Thu,Fri,Sat,Sun};
class date{
public:
    date(int,int,int,week);
    void operator++();
    void operator--();
    void operator+=(int);
    void operator-=(int);
    void showDate()const;
private:
    int Day,Month,Year;
    static int dDay,dMonth,dYear;
    int DOW;
    int dayOfMonths[13] = {0, 31 , 28 , 31 , 30 , 31, 30 , 31 , 31 , 30 , 31 , 30 , 31};
    char* monthPtr;
    int* dayofMonthPtr;
    char* dayOfWeekPtr;
    static  char* MONTHS[];
    static  char* DAYS[];
    bool isLeapYear(int);

};
int date::dDay = 01;
int date::dMonth = 01;
int date::dYear = 2000;
char* date::DAYS[] = {"", "Mon", "Tue", "Wed",
"Thr", "Fri", "Sat",
"Sun"};
char* date::MONTHS[] = {
"", "Jan", "Fab", "Mar",
"Apr", "May", "Jun",
"Jul", "Aug", "Sep",
"Oct", "Nov",
"Dec"};

#endif // M_H_INCLUDED
