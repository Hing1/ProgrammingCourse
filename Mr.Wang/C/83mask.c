#include <stdio.h>

/**
1.确定操作哪位
2.找到掩码
3.异或与或
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

void fun1();
void fun2();
void fun3();
void fun4();
void fun5();

int main() {
    fun1();
    fun2();
    fun3();
    fun4();
    fun5();
    return 0;
}

void fun1() {
    int a = 0x55;
    int mask = 1 << 3;

    dis32bin(a);
    dis32bin(mask);
    a |= mask;
    dis32bin(a);
}

void fun2() {
    int a = 0x55;
    int mask = ~(1 << 4);

    dis32bin(a);
    dis32bin(mask);
    a &= mask;
    dis32bin(a);
}

void fun3() {
    int a = 0x55;
    int mask = ~((1 << 4) | (1 << 2));

    dis32bin(a);
    dis32bin(mask);
    a &= mask;
    dis32bin(a);
}

void fun4() {
    int a = 0x55;
    int mask = (1 << 5) | (1 << 4) | (1 << 3) | (1 << 2);

    dis32bin(a);
    dis32bin(mask);
    a ^= mask;
    dis32bin(a);
}

void fun5() {
    int a = 0x55;
    int mask = 1 << 4;

    dis32bin(a);
    dis32bin(mask);
    
    if(a & mask)
        printf("It is 1\n");
    else
        printf("It is 0\n");
}
