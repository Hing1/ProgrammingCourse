#ifndef CALCULATOR_HPP
#define CALCULATOR_HPP

#include "Exception.hpp"
#include <iostream>
#include <cstring>

using namespace std;

class calculator
{
public:
    calculator() {}
    int calculate(const string str)
    {

        int _siz = str.size();
        if (_siz == 0)
            throw EmptyExpressionException();
        for (int i = 0; i < _siz; i++)
        {
            if (!('0' <= str[i] && str[i] <= '9'))
                if (str[i] != '+' && str[i] != '-')
                    throw IllegalSymbolException(i);
        }

        int result;
        if ('0' <= str[0] && str[0] <= '9')
            result = (str[0] - '0');
        else
            throw MissingOperandException(0);

        for (int i = 1; i < _siz; i++)
        {
            if (str[i] == '+')
            {
                i++;
                if ('0' <= str[i] && str[i] <= '9')
                    result += (str[i] - '0');
                else
                    throw MissingOperandException(i);
            }
            else if (str[i] == '-')
            {
                i++;
                if ('0' <= str[i] && str[i] <= '9')
                    result -= (str[i] - '0');
                else
                    throw MissingOperandException(i);
            }
            else
                throw MissingOperatorException(i);
        }
        return result;
    }
};

#endif // CALCULATOR_HPP