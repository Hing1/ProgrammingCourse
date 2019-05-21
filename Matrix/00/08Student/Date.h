#ifndef DATE_H
#define DATE_H
#include <iostream>

#include <sstream>
using namespace std;
class Date
{
private:
    int _year;
    int _month;
    int _day;

public:
    Date(int y, int m, int d)
    {
        _year = y;
        _month = m;
        _day = d;
    }
    Date(string dateString)
    {
        int i;
        _year = _month = _day = 0;
        for (i = 0; dateString[i] != '-'; i++)
            _year = _year * 10 + dateString[i] - '0';
        for (i = i + 1; dateString[i] != '-'; i++)
            _month = _month * 10 + dateString[i] - '0';
        for (i = i + 1; i < dateString.size(); i++)
            _day = _day * 10 + dateString[i] - '0';
    }
    int getYear() const
    {
        return _year;
    }
    void setYear(int y)
    {
        _year = y;
    }
    int getMonth() const
    {
        return _month;
    }
    void setMonth(int m)
    {
        _month = m;
    }
    int getDay() const
    {
        return _day;
    }
    void setDay(int d)
    {
        _day = d;
    }
    bool operator==(Date &other) const
    {
        if (_year == other._year && _month == other._month && _day == other._day)
            return true;
        return false;
    }
    bool operator<(Date &other) const
    {
        if (_year < other._year)
            return true;
        if (_year > other._year)
            return false;
        if (_month < other._month)
            return true;
        if (_month > other._month)
            return false;
        return _day < other._day;
    }
    bool operator>(Date &other) const
    {
        if (_year > other._year)
            return true;
        if (_year < other._year)
            return false;
        if (_month > other._month)
            return true;
        if (_month < other._month)
            return false;
        return _day > other._day;
    }
    std::string toString() const
    {
        stringstream s;
        s << _year << "-" << _month << "-" << _day;
        return s.str();
    }
};
#endif // DATE_H
