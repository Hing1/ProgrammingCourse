#include <stdio.h>

#if 0
int * fun() { // 可以成功返回地址，但该地址无意义，访问非法可能出错，不能使用
    int a = 100;
    return &a;
}

int main () {
    int * pa;
    pa = fun();
    printf("%d\n", *pa);
}
#endif

int * fun() { // 若为static则变量的生命周期与进程相同，可以正常访问
    static int a = 100;
    return &a;
}

int main () {
    int * pa;
    pa = fun();
    printf("%d\n", *pa);
}