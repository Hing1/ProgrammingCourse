#include <stdio.h>

int main() {
    float  var  = 0.123412341234;
    //float只有小数点后6 ~ 7 位是准确的
    //输出0.12341234087944031000
    double varr = 0.123412341234;
    //double只有小数点后6 ~ 7 位是准确的
    //输出0.12341234123399999000

    printf("%.20f\n",var);
    printf("%.20f\n",varr);
}