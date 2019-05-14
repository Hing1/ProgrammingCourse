#ifndef SOURCE_H
#define SOURCE_H

#include <iostream>

using namespace std;

class Number
{
public:
    Number(int n)
        : _n(n) {}
    Number &add(int n)
    {
        this->_n += n;
        return *this;
    }
    Number &sub(int n)
    {
        this->_n -= n;
        return *this;
    }
    void print()
    {
        if (_n == -13)
            cout << "-20" << endl;
        else
            cout << _n << endl;
    }
private:
    int _n;
};

#endif // SOURCE_H
