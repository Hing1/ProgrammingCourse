#ifndef SOURCE_H
#define SOURCE_H

#include <iostream>
#include <cstring>
using namespace std;

int parseHex(const char *const hexString)
{
    //runtime_error ex("Hex number format error");
    int ans = 0;
    int e = 1;
    for (int i = strlen(hexString) - 1; i >= 0; i--)
    {
        if ('0' <= hexString[i] && hexString[i] <= '9')
            ans += e * (hexString[i] - '0');
        else if ('A' <= hexString[i] && hexString[i] <= 'F')
            ans += e * (hexString[i] - 'A' + 10);
        else
            throw(runtime_error) "Hex number format error";
        e *= 16;
    }
    return ans;
}

#endif // SOURCE_H
