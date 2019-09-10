#include <stdio.h>

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

void circleShift(unsigned int *pa, int n) {
    n %= sizeof (*pa) * 8;
    if(n >= 0)
        *pa = (*pa <<  n  ) | (*pa >> (sizeof (*pa) * 8 - n));
    else
        *pa = (*pa << (-n)) | (*pa >> (sizeof (*pa) * 8 + n));
    return;
}

int main() {
    int a = 0x80000001;
    dis32bin(a);

    circleShift(&a, -1);
    dis32bin(a);

    return 0;
}
