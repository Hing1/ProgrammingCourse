#include <stdio.h>

#define N 5

/**
 * N个数比较N-1次
 * 内层循环下标每次都从头开始，跟下一个比较
 * 内循环的次数为N - i - 1次
 */
int main()
{
    int a[N] = {1,2,3,4,5};
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if(a[j] > a[j + 1]) {
                a[j] ^= a[j + 1];
                a[j + 1] ^= a[j];
                a[j] ^= a[j + 1];
            }
        }
    }
    return 0;
}
