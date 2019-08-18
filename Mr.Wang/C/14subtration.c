#include <stdio.h>

int main() {
    int arr[10];

    int * pHead = &arr[0];
    int * pTaill = &arr[9];

    printf("%d\n", pTaill - pHead);

    // if (pHead + 9 == pTaill)
    //     printf("pHead + 9 == pTaill\n");

    int _pHead = (int)&arr[0];
    int _pTaill = (int)&arr[9];

    printf("%d\n", _pTaill - _pHead);

    return 0;
}