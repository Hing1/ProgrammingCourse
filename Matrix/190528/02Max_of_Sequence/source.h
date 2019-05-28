#ifndef SOURCE_H
#define SOURCE_H

#include <cstring>

template <typename T>
T max(T *a, int size)
{
    T temp = a[0];
    for (int i = 1; i < size; i++)
    {
        if (a[i] > temp)
            temp = a[i];
    }
    return temp;
}
#endif // SOURCE_H
