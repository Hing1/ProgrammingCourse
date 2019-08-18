#include <stdio.h>

int main()
{
    int arr[3][4] = {
        1  ,2  ,3  ,4,
        10 ,20 ,30 ,40,
        100,200,300,400
    };

    for (int i = 2; i >= 0; i--) {
        for (int j = 3; j >= 0; j--) {
            printf("a[%d][%d] = %#x\n",i,j,&arr[i][j]);
        }
        printf("===============\n");
    }

    putchar(10);

    printf(" arr    = %#x,  arr    + 1 = %#x,  arr    + 2 = %#x\n",arr   ,arr    + 1,arr    + 2);
    printf(" arr[0] = %#x,  arr[0] + 1 = %#x,  arr[0] + 2 = %#x\n",arr[0],arr[0] + 1,arr[0] + 2);
    putchar(10);
    printf("*arr    = %#x, *arr    + 1 = %#x, *arr    + 2 = %#x\n",*arr   ,*arr    + 1,*arr    + 2);
    printf("&arr[0] = %#x, &arr[0] + 1 = %#x, &arr[0] + 2 = %#x\n",&arr[0],&arr[0] + 1,&arr[0] + 2);

}
