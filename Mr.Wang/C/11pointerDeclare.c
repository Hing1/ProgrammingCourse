#include <stdio.h>

int main() {
    int data;
    int *pd = &data; // *用于声明变量
    *pd = 200;       // 解引用 取内容

    char * p1, q1;   // 前者是指针，后者是变量
    printf("sizeof(p1) = %d, sizeof(q1) = %d\n",sizeof(p1), sizeof(q1));
    char * p2, * q2; // 两者都是变量
    printf("sizeof(p2) = %d, sizeof(q2) = %d\n",sizeof(p2), sizeof(q2));

    return 0;
}