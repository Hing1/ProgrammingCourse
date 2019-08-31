#include <stdio.h>
#include <stdlib.h>

//申请和初始化的最小单位均是字节

void primaryDataType() {
    //基本数据类型在栈和堆上
    int a;
    a = 100;

    //p 在栈上，p存储的为地址，该地址指向堆的一段空间
    int * p = (int*)malloc(1 * sizeof (int));
    *p = 100;

    printf("a  = %d\n", a);
    printf("*p = %d\n",*p);
}
void arrayMalloc() {
    int arr[10];

    int * pa = (int*)malloc(10 * sizeof (int));

    memset (pa, 0, 10 * sizeof (int));
    for (int i = 0; i < 10; i++) {
        printf("pa[%d] = %d\n", i, pa[i]);
    }
/*
    //不可以printf("pa[%d] = %d\n", i, *pa++);//因为最后pa的位置变了后free会报错
    //可以改为以下这样
    int * pacopy = pa;
    for (int i = 0; i < 10; i++) {
        printf("pa[%d] = %d\n", i, pacopy++);
    }
    
*/
    free(pa);
/*
    memset (pa, 1, 10 * sizeof (int));//为（01010101）16
    for (int i = 0; i < 40; i++) {
        printf("pa[%d] = %#\n", i, ((char*)pa)[i]);
    }
*/
}
void arrayCalloc() {
    //申请多个，并自动初始化
    int *p = (int*)calloc(10, sizeof (int));
    for(int i = 0; i < 10; i++) {
        printf("%d\n", p[i]);
    }
    free(p);
}

int main()
{
    primaryDataType();
    arrayMalloc();
    arrayCalloc();
    return 0;
}
