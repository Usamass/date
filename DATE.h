#ifndef DATE_H
#define DATE_H
enum week {Mon = 1,Tue,Wed,Thu,Fri,Sat,Sun};
class Date{
public:
    Date(int day ,int month ,int year ,week dayOfWeak);
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
    static  char* const MONTHS[];
    static  char* const DAYS[];
    bool isLeapYear(int);

};


#endif // M_H_INCLUDED
