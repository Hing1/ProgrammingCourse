#include <stdio.h>

/**
左移:   高位溢出，低位补零
        在不溢出时，每左移一位乘二
右移：{
    低位舍弃，
    高位 {
        无符号数、有符号数正数：高位补零
        有符号负数：{
            (取决于系统)
            补 1 ：算数右移
            补 0 ：逻辑右移
        }
    }
    在低位为零时，每右移一位除以二
}
*/

void dis32bin(int data) {
    int i = 32;
    while (i--) {
        if(data & (1 << i))
            printf("1");
        else
            printf("0");

        if(i % 4 == 0) {
            if(i % 8 == 0)
                printf(" ");
            else
                printf("-");
        }
    }
    putchar(10);
}

void shiftLeft();
void shiftRight();
void appShift();

int main() {
//    shiftLeft();
//    shiftRight();
    appShift();
    return 0;
}

void shiftLeft() {
    int a = 0x01;
    dis32bin(a);
    dis32bin(a << 1);
    dis32bin(a << 2);
    dis32bin(a << 33);
    dis32bin(a << 34);
}

void shiftRight() {
    int a = 0x55;
    dis32bin(a);
    dis32bin(a >> 1);
    dis32bin(a >> 2);
    dis32bin(a >> 33);
    dis32bin(a >> 34);

    putchar(10);
    putchar(10);

    int b = 0x80000000;
    dis32bin(b);
    dis32bin(b >> 1);
    dis32bin(b >> 2);
    dis32bin(b >> 33);
    dis32bin(b >> 34);

}

void appShift() {
    int a = 2;
    printf("%d\n", a);
    printf("%d\n", a << 1);
    printf("%d\n", a << 2);

    int b = 0x80;
    printf("%d\n", b);
    printf("%d\n", b >> 1);
    printf("%d\n", b >> 2);
}
