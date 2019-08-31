#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if 0
源程序     即源代码
程序       即可执行文件
.exe

进程       时间概念 从可执行文件被拉起到结束的这一段过程，称为进程
进程空间    可执行文件被拉起后在内存中的分布情况


stack   栈
heap    堆
data
text
#endif

#if 0
4G
    ...     //内核空间
3G
    ...

            //用户空间
    ...
0
#endif

#if 0
栈空间 1M左右，用于交换数据，不适用于大空间的申请
堆空间主要用于大内存的申请使用

栈的地址发展方向从大地址到小地址
#endif

#if 0
堆内存可以存放任意类型数据，需要自己申请和释放
堆的大小：相对于栈来说，堆为无穷大
malloc 以字节为单位申请堆内存
#endif

void sizeofStack() {
    char arr[1024 * 1024] = {0}; // 1M
    strcpy(arr, "china");
    printf("sizeofStack() over!!!\n");
}
void dictionStack() {
    printf("dictionStack()\n");
    int a, b, c, d;
    printf("%p\n",&a);
    printf("%p\n",&b);
    printf("%p\n",&c);
    printf("%p\n",&d);
}
void sizeofHeap() {
    char * p =(char *)malloc(1024 * 1024 * 1024 * 5);   // 5G
    if (p == NULL)
        printf("malloc error!\n");
    strcpy(p, "abcd");
    printf("sizeofHeap() over!\n");
    free(p);
}
void dictionHeap() {
    printf("dictionHeap()\n");
    char *pa, *pb, *pc, *pd;
    pa = (char*)malloc(100);
    pb = (char*)malloc(100);
    pc = (char*)malloc(100);
    pd = (char*)malloc(100);
    printf("%p\n", pa);
    printf("%p\n", pb);
    printf("%p\n", pc);
    printf("%p\n", pd);
}

int main()
{
    dictionHeap();
    dictionStack();
    //sizeofStack();
    //sizeofHeap();
    return 0;
}
