#ifndef SOURCE_H
#define SOURCE_H

#include <iostream>
#include <cstring>

using namespace std;

int parseBinary(const char * const binaryString)
{
    int ans = 0;
    int e = 1;
    for (int i = strlen(binaryString) - 1;i >= 0;i--) {
        if(binaryString[i] == '0' || binaryString[i] == '1')
            ans += e * (binaryString[i] - '0');
        else
            throw (runtime_error)"Binary number format error";
        e *= 2;
    }
    return ans;
}

#endif // SOURCE_H
