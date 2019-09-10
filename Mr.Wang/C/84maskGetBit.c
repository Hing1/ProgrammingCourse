#include <stdio.h>

void fun1() {
    int a = 0x55;
    int mask = 0x00;
    for (int i = 3; i <= 6; i++) {
        mask |= (1 << i);
    }
    a &= mask;
    a >>= 3;
    printf("%d\n", a);
}

void fun2() {
    int a = 0x55;
    a >>= 3;
    int mask = 0x0f;

    a &= mask;
    printf("%d\n", a);
}

int main() {
    fun1();
    fun2();
    return 0;
}
