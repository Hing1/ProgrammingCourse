#ifndef SOURCE_H
#define SOURCE_H

#include <iostream>

using namespace std;

template <typename T>
void swapVar(T& a,T &b )
{
    T t = a;
    a = b;
    b = t;
}

#endif // SOURCE_H
