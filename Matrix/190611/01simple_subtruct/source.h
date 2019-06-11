#ifndef SOURCE_H
#define SOURCE_H

#include <iostream>

using namespace std;

int calc(int a, int b) throw(string)
{
    if (a < 0)
        throw(string) "Out of range exeception";
    else if (b < 0)
        throw(string) "Out of range exeception";
    else if (a < b)
        throw(string) "Minuend smaller than subtrahend";
    return a - b;
}
void test(int a, int b)
{
    try
    {
        cout << calc(a, b) << endl;
    }
    catch (string s)
    {
        cout << s << endl;
    }
}

#endif // SOURCE_H
