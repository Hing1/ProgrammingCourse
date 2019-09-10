#include <stdio.h>

void swap1(int * pa, int * pb) {
    int t = *pa;
    *pa = *pb;
    *pb = t;
}

void swap2(int * pa, int * pb) {
    *pa = *pa + *pb;
    *pb = *pa - *pb;
    *pa = *pa - *pb;
}

void swap3(int * pa, int *pb) {
/*
    无参交换
    不要从二进制角度理解，要从宏观角度，与上面的加减法类比

    原理a ^ b = c  --> a ^ c = b
*/
    *pa = *pa ^ *pb;
    *pb = *pa ^ *pb;
    *pa = *pa ^ *pb;
#if 0
    *pa ^= *pb;
    *pb ^= *pa;
    *pa ^= *pb;
#endif
}

int main() {
    int a = 3;
    int b = 5;
    printf("a = %d, b= %d\n", a, b);
    swap3(&a, &b);
    printf("a = %d, b= %d\n", a, b);
    return 0;
}
