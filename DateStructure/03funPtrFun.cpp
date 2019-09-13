#include <stdio.h>
#include <math.h>

void funPtrFun(int (*p1)(int), int n1, int (*p2)(int), int n2) {
    printf("(*p1) = %d\n", (*p1)(n1));
    printf("(*p2) = %d\n", (*p2)(n2));
    return ;
}
int fun1(int n) {
    return n * 2;
}
int fun2(int n) {
    return n * 5;
}

int main() {
    funPtrFun(fun1, 3, fun2, 4);
    return 0;
}

#if 0
int comp(int initValue, int (*p1)(int), int (*p2)(int)) {
    int N;
    N = initValue;
    return (*p1)(1) + (*p2)(1);
}

int f1 (int n);
int f23(int n);
int f4 (int n);

int g1 (int n);
int g2 (int n);
int g34(int n);

int main() {
    int res[4];

    res[0] = comp(1, f1 , g1);
    res[1] = comp(1, f23, g2);
    res[2] = comp(2, f23, g34);
    res[3] = comp(2, f4 , g34);

    for (int i = 0; i < 4; i++) {
        printf("%d ",res[i]);
    }
    putchar(10);
    return 0;
}
#endif
