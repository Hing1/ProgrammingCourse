#include <stdio.h>

/**
 * 按位与  ：跟1按位与保持不变，跟0按位与清零。在某些位保持不变的情况下，某些位清零。
 * 按位或  ：跟0按位或保持不变，跟1按位或置一。在某些位保持不变的情况下，某些位置一。
 * 按位取反：用于间接的构造某些数
 * 异或    ：跟 0 异或保持不变，跟 1 异或取反。在某些位保持不变的情况下，某些位取反。
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

void andFun();
void orFun();
void notFun();
void xorFun();

int main()
{
//    andFun();
//    orFun();
//    notFun();
    xorFun();
    return 0;
}

void andFun() {
    int a = 3;
    int b = 11;

    dis32bin(a);
    dis32bin(b);
    dis32bin(a & b);

    putchar(10);
    int x = 0x55;
    int y = 0x00;
    int z = 0xff;
    int zz = 0x0f;
    dis32bin(x & y);
    dis32bin(x & z);
    dis32bin(x & zz);
}

void orFun() {
    int a = 3;
    int b = 9;

    dis32bin(a);
    dis32bin(b);
    dis32bin(a | b);

    putchar(10);
    int x = 0x55;
    int y = 0x00;
    int z = 0xff;
    int zz = 0x0f;
    dis32bin(x | y);
    dis32bin(x | z);
    dis32bin(x | zz);
}

void notFun() {
    int a = 0x55;
    dis32bin(a);
    dis32bin(~a);

    dis32bin(0);
    dis32bin(~0);
}

void xorFun() {
    putchar(10);
    int x = 0x55;
    int y = 0x00;
    int z = 0xff;
    int zz = 0x0f;
    dis32bin(x ^ y);
    dis32bin(x ^ z);
    dis32bin(x ^ zz);
}
