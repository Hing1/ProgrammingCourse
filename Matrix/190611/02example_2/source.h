#ifndef SOURCE_H
#define SOURCE_H

#include <iostream>

using namespace std;

void f3(int x)
{
    switch (x)
    {
    case 1:
        throw 3.4;
    case 2:
        throw 2.5f;
    case 3:
        throw 1;
    }
    cout << "End of f3" << endl;
}
void f2(int x)
{
    try
    {
        f3(x);
    }
    catch (int)
    {
        cout << "An int exception occurred!--from f2" << endl;
    }
    catch (float)
    {
        cout << "A float exception occurred!--from f2" << endl;
    }
    cout << "End of f2" << endl;
}
void f1(int x)
{
    try
    {
        f2(x);
    }
    catch (int)
    { // int型异常的处理代码
        cout << "An int exception occurred!--from f1" << endl;
    }
    catch (float)
    { // float型异常的处理代码
        cout << "A float exception occurred!--from f1" << endl;
    }
    catch (double)
    { // double型异常的处理代码
        cout << "A double exception occurred!--from f1" << endl;
    }
    cout << "End of f1" << endl;
}

#endif // SOURCE_H
