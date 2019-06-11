#ifndef JUDGE_H
#define JUDGE_H

#include <iostream>
#include <cstring>
#include <math.h>

class NumberParseException
{
};
bool isNumber(const char *str)
{
    if (str == nullptr || strlen(str) == 0)
        return false;
    if (strlen(str) == 1 && !isdigit(str[0]))
        return false;
    if (!isdigit(str[0]) && str[0] != '-' && str[0] != '+')
        return false;
    for (int i = 1; i < strlen(str); i++)
        if (!isdigit(str[i]))
            return false;
    return true;
}

int parseNumber(const char *str)
{
    if (!isNumber(str))
        throw NumberParseException();
    int ans = 0;
    int e = 1;
    for (int i = strlen(str) - 1; i >= 0; i--)
        if (str[i] == '+')
            ans *= 1;
        else if (str[i] == '-')
            ans *= -1;
        else
        {
            ans += e * (str[i] - '0');
            e *= 10;
        }
    return ans;
}

#endif // JUDGE_H
