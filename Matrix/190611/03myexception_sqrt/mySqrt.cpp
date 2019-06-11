#include "mySqrt.hpp"
#include "MyException.hpp"
#include <math.h>

double mySqrt(double dnum)
{
    if (dnum < 0)
        throw MyException("invalid argument");
    return sqrt(dnum);
}
