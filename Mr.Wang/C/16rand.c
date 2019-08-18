#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

int main()
{
    int randArr[N];
    srand(time(NULL));
    randArr[0] = rand() % 100;

    int count = 1;
    while(count <= N) {
        int num = rand() % 100;
        int flag = 1;
        for (int i = 0;i < count;i++) {
            if (num == randArr[i]) {
                flag = 0;
                break;
            }
        }
        if(flag == 1) {
            randArr[count++] = num;
        }
    }

    for (int i = 0;i < N; i++) {
        printf("%d ",randArr[i]);
    }
    putchar(10);

    return 0;
}
