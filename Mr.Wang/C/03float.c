#include <stdio.h>

int main() {
    float  var  = 0.123412341234;
    //floatֻ��С�����6 ~ 7 λ��׼ȷ��
    //���0.12341234087944031000
    double varr = 0.123412341234;
    //doubleֻ��С�����6 ~ 7 λ��׼ȷ��
    //���0.12341234123399999000

    printf("%.20f\n",var);
    printf("%.20f\n",varr);
}