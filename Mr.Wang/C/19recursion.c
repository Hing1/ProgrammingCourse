#include <stdio.h>

int func1(int n) { 
    if(n == 0)
        return 1;
    else
        return func1(--n) + 2;
        //return func1(n - 1) + 2; //效果相同
}

int func2(int n) {
    if(n == 0)
        return 1;
    else
        return n * func2(n - 1); 
    // 这里不可以用n--，因为参数一直在参与运算
    // 递归过程中参数n的值不正确
}

int main() {
    printf("%d\n",func1(5));
    printf("%d\n",func1(5));
    return 0;
}