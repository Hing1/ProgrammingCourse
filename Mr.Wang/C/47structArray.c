#include <stdio.h>

//结构体支持赋值
//等位拷贝

typedef struct structArray
{
    int a[10];
}Arr ;


int main () {
    Arr arr1 = {{1,2,3,4,5,6,7,8,9,10}};
    Arr arr2;
    arr2 = arr1;

    for (int i = 0; i < 10; i++)
    {
        printf("%d ",arr2.a[i]);
    }
    return 0;
}