#include <iostream>

using namespace std;

typedef  struct date{
    int year;
    int month;
    int day;
}Date;

Date inputDate(Date date);
Date nextDate(Date date);
void printDate(Date date);

int main()
{
    Date date1 = {1999,1,1};
    Date date2 = {1999,1,1};

    date1 = inputDate(date1);
    date2 = nextDate(date1);

    cout << "The day is " << endl;
    printDate(date1);
    cout << "The next day is " << endl;
    printDate(date2);

    return 0;
}
bool isLeapYear(int year) {
    return (((year % 4 == 0)&&(year % 100 != 0))||(year % 400 == 0));
}
int monthDay(Date date) {
    if (date.month == 2) {
        if(isLeapYear(date.year))
            return 29;
        else
            return 28;
    } else if((date.month <= 7 && date.month % 2)||(date.month >= 8 && !date.month % 2))
        return 31;
    else
        return 30;
}
Date inputDate(Date date) {
    cout << "Please input year : ";
    cin >> date.year;
    cout << "Please input month : ";
    cin >> date.month;
    cout << "Please input day : ";
    cin >> date.day;
    return date;
}
Date nextDate(Date date) {
    Date nextDay;
    if(date.day == monthDay(date)) {
        nextDay.day = 1;
        nextDay.month = date.month + 1;
    } else
        nextDay.day = date.day + 1;
    return nextDay;
#if 0
    switch (date.month) {
    case 1:
        if(date.day == 31) {
            nextDay.day = 1;
            nextDay.month = date.month + 1;
        } else
            nextDay.day = date.day + 1;
        break;
    case 2:
        if((date.day == 29)||(date.day == 28 && !isLeapYear(date.year))) {
            nextDay.day = 1;
            nextDay.month = date.month + 1;
        } else
            nextDay.day = date.day + 1;
        break;
    case 3:
        if(date.day == 31) {
            nextDay.day = 1;
            nextDay.month = date.month + 1;
        } else
            nextDay.day = date.day + 1;
        break;
    case 4:
        if(date.day == 30) {
            nextDay.day = 1;
            nextDay.month = date.month + 1;
        } else
            nextDay.day = date.day + 1;
        break;
    case 5:
        if(date.day == 31) {
            nextDay.day = 1;
            nextDay.month = date.month + 1;
        } else
            nextDay.day = date.day + 1;
        break;
    case 6:
        if(date.day == 30) {
            nextDay.day = 1;
            nextDay.month = date.month + 1;
        } else
            nextDay.day = date.day + 1;
        break;
    case 7:
        if(date.day == 31) {
            nextDay.day = 1;
            nextDay.month = date.month + 1;
        } else
            nextDay.day = date.day + 1;
        break;
    case 8:
        if(date.day == 31) {
            nextDay.day = 1;
            nextDay.month = date.month + 1;
        } else
            nextDay.day = date.day + 1;
        break;
    case 9:
        if(date.day == 30) {
            nextDay.day = 1;
            nextDay.month = date.month + 1;
        } else
            nextDay.day = date.day + 1;
        break;
    case 10:
        if(date.day == 31) {
            nextDay.day = 1;
            nextDay.month = date.month + 1;
        } else
            nextDay.day = date.day + 1;
        break;
    case 11:
        if(date.day == 30) {
            nextDay.day = 1;
            nextDay.month = date.month + 1;
        } else
            nextDay.day = date.day + 1;
        break;
    case 12:
        if(date.day == 31) {
            nextDay.day = 1;
            nextDay.month = 1;
            nextDay.year = date.year + 1;
        } else
            nextDay.day = date.day + 1;
        break;
    default:
        break;
    }
    return nextDay;
#endif
}
void printDate(Date date) {
    printf("%04d-%02d-%02d\n", date.year, date.month, date.day);
    return;
}
