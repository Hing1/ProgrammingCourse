
#include <iostream>

using namespace std;

class IllegalSubscriptException
{
};

class Date
{
public:
    Date(int y = 0, int m = 1, int d = 1);
    Date(const Date &another);

    static bool leapyear(int year);
    int getYear() const;
    int getMonth() const;
    int getDay() const;

    Date &operator=(const Date &another);

    bool operator==(const Date &another) const;
    bool operator!=(const Date &another) const;
    bool operator>(const Date &another) const;
    bool operator>=(const Date &another) const;
    bool operator<(const Date &another) const;
    bool operator<=(const Date &another) const;

    Date &operator++();
    Date operator++(int);
    Date &operator--();
    Date operator--(int);

    Date &operator+=(int day);
    Date operator+(int day) const;
    Date &operator-=(int day);
    Date operator-(int day) const;

    int operator-(const Date &another) const;
    int &operator[](string str);

private:
    int _year;
    int _month;
    int _day;
};

Date::Date(int y, int m, int d)
    : _year(y), _month(m), _day(d) {}
Date::Date(const Date &another)
{
    this->_day = another._day;
    this->_month = another._month;
    this->_year = another._year;
}

bool Date::leapyear(int year)
{
    return ((year % 400) == 0 || (year % 4 == 0 && year % 100 != 0));
}
int Date::getYear() const
{
    return _year;
}
int Date::getMonth() const
{
    return _month;
}
int Date::getDay() const
{
    return _day;
}

Date &Date::operator=(const Date &another)
{
    this->_day = another._day;
    this->_month = another._month;
    this->_year = another._year;
    return *this;
}

bool Date::operator==(const Date &another) const
{
    return _year == another._year && _month == another._month && _day == another._day;
}
bool Date::operator!=(const Date &another) const
{
    return !(*this == another);
}
bool Date::operator>(const Date &another) const
{
    return ((_year > another._year) || (_year == another._year && _month > another._month) || (_month == another._month && _day > another._day));
}
bool Date::operator>=(const Date &another) const
{
    return ((*this == another) || (*this > another));
}
bool Date::operator<(const Date &another) const
{
    return !(*this >= another);
}
bool Date::operator<=(const Date &another) const
{
    return !(*this > another);
}

static const int Monthdays[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
static int GetMonthDays(int year, int month)
{
    if (month == 2 && (Date::leapyear(year)))
        return 29;
    else
        return Monthdays[month];
}
Date &Date::operator++()
{
    if (_day + 1 > GetMonthDays(_year, _month))
        if (_month + 1 == 13)
        {
            _year++;
            _month = 1;
            _day = 1;
        }
        else
        {
            _month++;
            _day = 1;
        }
    else
        _day++;
    return *this;
}
Date Date::operator++(int)
{
    Date ret(*this);
    ++(*this);
    return ret;
}
Date &Date::operator--()
{
    if (_day == 1)
        if (_month == 1)
        {
            _year--;
            _month = 12;
            _day = 31;
        }
        else
        {
            _month--;
            _day = GetMonthDays(_year, _month);
        }
    else
        _day--;
    return *this;
}
Date Date::operator--(int)
{
    Date ret(*this);
    --(*this);
    return ret;
}

Date &Date::operator+=(int day)
{
    _day += day;
    if (_day > 0)
    {
        while (_day > GetMonthDays(_year, _month))
        {
            _day -= GetMonthDays(_year, _month);
            if (_month == 12)
            {
                _month = 1;
                _year++;
            }
            else
                _month++;
            //_day -= GetMonthDays(_year, _month);
        }
    }
    if (_day <= 0)
    {
        while (_day < 1)
        {
            if (_month == 1)
            {
                _month = 12;
                _year--;
            }
            else
                _month--;
            _day += GetMonthDays(_year, _month);
        }
    }
    return *this;
}
Date Date::operator+(int day) const
{
    Date ret = (*this);
    return ret += day;
}
Date &Date::operator-=(int day)
{
    //return (*this) += -day;
    _day -= day;
    if (_day > 0)
    {
        while (_day > GetMonthDays(_year, _month))
        {
            _day -= GetMonthDays(_year, _month);
            if (_month == 12)
            {
                _month = 1;
                _year++;
            }
            else
                _month++;
            //           _day -= GetMonthDays(_year, _month);
        }
    }
    if (_day <= 0)
    {
        while (_day < 1)
        {
            if (_month == 1)
            {
                _month = 12;
                _year--;
            }
            else
                _month--;
            _day += GetMonthDays(_year, _month);
        }
    }
    return *this;
}
Date Date::operator-(int day) const
{
    //return *this + (-day);
    Date ret = (*this);
    return ret -= day;
}

int Date::operator-(const Date &another) const
{
    if (*this < another)
        return another - *this;
    if (*this == another)
        return 0;

    int ret = 0;
    Date tmp = *this;
    if (tmp._month == 2 && tmp._day == 29)
    {
        tmp._day--;
        ret++;
    }

    if (tmp._month > 2)
    {
        while (tmp._year != another._year)
        {
            (tmp._year % 400 == 0 || (tmp._year % 100 != 0 && tmp._year % 4 == 0)) ? ret += 366 : ret += 365;
            tmp._year--;
        }
    }
    else
    {
        while (tmp._year != another._year)
        {
            tmp._year--;
            leapyear(tmp._year) ? ret += 366 : ret += 365;
        }
    }
    while (tmp._month != another._month)
    {
        ret += tmp._day;
        tmp._month--;
        tmp._day = GetMonthDays(tmp._year, tmp._month);
    }
    ret += tmp._day - another._day;
    return ret;
}
int &Date::operator[](string str)
{
    IllegalSubscriptException ex;
    string temp = str;
    if (temp == "year")
        return _year;
    else if (temp == "month")
        return _month;
    else if (temp == "day")
        return _day;
    else
        throw(IllegalSubscriptException) ex;
}
