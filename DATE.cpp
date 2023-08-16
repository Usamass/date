#include "DATE.h"
#include <iostream>
// initialization of static date members
int Date::dDay = 01;
int Date::dMonth = 01;
int Date::dYear = 2000;
char* const Date::DAYS[] = {"", "Mon", "Tue", "Wed",
"Thr", "Fri", "Sat",
"Sun"};
char* const Date::MONTHS[] = {
"", "Jan", "Fab", "Mar",
"Apr", "May", "Jun",
"Jul", "Aug", "Sep",
"Oct", "Nov",
"Dec"};


Date::Date(int day ,int month , int year ,week w ){
    dayOfWeekPtr = DAYS[w];
    DOW = w;

    if(day < 1 || day > 31)Day = dDay; else Day = day;
    if(month < 1 || month > 12){
    Month = dMonth;
    monthPtr = MONTHS[dMonth];
    dayofMonthPtr = dayOfMonths+dMonth;

    } else {
        Month = month;
        monthPtr = MONTHS[month];
        dayofMonthPtr = dayOfMonths+month;
    }
    if(year < 1900 || year > 3000)Year = dYear;
    else
        Year = year;
    if(isLeapYear(year)){dayOfMonths[2]++;
    }
    if(day > dayOfMonths[month])
        Day = dayOfMonths[month];
}
void Date::operator++(){

    DOW++;
    if(DOW > 7){
    dayOfWeekPtr = DAYS[1];
    DOW = 1;
    }
    else
    dayOfWeekPtr+=4;

    if(++Day > dayOfMonths[Month]){

            Day = 1;
            if (Month++ == 12){
                Month = 1;
                Year++;
            }
            monthPtr = MONTHS[Month];
            dayofMonthPtr = dayOfMonths+Month;
    }
}
void Date::operator--(){

    DOW--;
    if(DOW < 1){
    dayOfWeekPtr = DAYS[7];
    DOW = 7;
    }
    else
    dayOfWeekPtr-=4;

    if(--Day < 1){
            dayofMonthPtr = dayOfMonths+Month-1;
            Day = *dayofMonthPtr;
            if (Month-- == 1){
            dayofMonthPtr = dayOfMonths+Month+11;
            Day = *dayofMonthPtr;
                Month = 12;
                Year--;
            }
            monthPtr = MONTHS[Month];
            dayofMonthPtr = dayOfMonths+Month;
    }
}
void Date::operator+=(int Inc){
    for(int i =1; i<=Inc; i++){++*(this);}
}
void Date::operator-=(int Dec){
    for(int j =1; j<=Dec; j++){--*(this);}
}
bool Date::isLeapYear(int isleap){
    if (((isleap % 4 == 0) && (isleap % 100 != 0)) || (isleap % 400 == 0))
        return 1;
    else
        return 0;
}
void Date::showDate()const{
        std::cout<<Day<<'/'<<Month<<'/'<<Year
        <<std::endl<<dayOfWeekPtr<<'/'<<*dayofMonthPtr<<'/'<<monthPtr;
}

