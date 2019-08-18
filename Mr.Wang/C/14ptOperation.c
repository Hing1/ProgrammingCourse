#include <stdio.h>

int main1() {
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
int main() {
    int * p = 0x0001;
    int * q = 0x0005;

    if(p + 1 == (int)p + 1 * sizeof(int))
        printf("(p + 1 == (int)p + 1 * sizeof(int))\n");
    if(p + 1 == q)
        printf("p + 1 == q\n");

    printf("     p     = %#x\n",     p     );
    printf("     p + 1 = %#x\n",     p + 1 );
    printf("(int)p     = %#x\n",(int)p     );
    printf("(int)p + 1 = %#x\n",(int)p + 1 );
    return 0;
}