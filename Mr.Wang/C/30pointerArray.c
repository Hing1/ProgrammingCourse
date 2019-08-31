#include <stdio.h>

//指针数组的本质是数组
//数组指针的本质是指针

int main()
{
    int arr[] = {1,2,3,4,5,6};              //整型数组
    char cArr[] = {'a','b','c','d','e'};    //字符数组

    int a, b, c, d;
    int * ipArr[] = {&a,&b,&c,&d};          //{int*, int*, int*, int*}
                                            //整型指针数组
    char aa,bb,cc,dd;
    char * cpArr1[] = {&aa,&bb,&cc,&dd};    //{char*, char*, char*, char*}
                                            //字符指针数组
    char *pa, *pb, *pc, *pd;
    char * cpArr2[] = {pa,pb,pc,pd};

    char *pa1 = "china", *pb1 = "ameria", *pc1 = "canada", *pd1 = "japan";
    char * cpArr3[] = {pa1,pb1,pc1,pd1};

    char * cpArr4[] = {"china","ameria","canada","janan"};

    for (int i = 0;i < 4;i++) {
        printf("%p\n",cpArr3[i]);
    }
    putchar(10);
    for (int i = 0;i < 4;i++) {
        printf("%s\n",cpArr3[i]);
    }

    return 0;
}
