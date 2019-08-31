#include <stdio.h>
#include <string.h>

int main()
{
    char * pArr[] = {"china","ameria","canada","japan"};

    for (int i = 0;i < 4;i++) {
        printf("%p\t\t%s\n",pArr[i],pArr[i]);
    }

    int n = sizeof (pArr)/sizeof (pArr[0]);
    //int n = sizeof (pArr) / sizeof (*pArr);
    for (int i = 0;i < n - 1;i++) {
        for (int j = i + 1;j < n;j++) {
            if(strcmp(pArr[i],pArr[j]) > 0) {
                char * temp;
                temp    = pArr[i];
                pArr[i] = pArr[j];
                pArr[j] = temp;
            }
        }
    }

    putchar(10);
    for (int i = 0;i < 4;i++) {
        printf("%p\t\t%s\n",pArr[i],pArr[i]);
    }
    return 0;
}
/*
0000000000404000                china
0000000000404006                ameria
000000000040400D                canada
0000000000404014                japan

0000000000404006                ameria
000000000040400D                canada
0000000000404000                china
0000000000404014                japan
*/
