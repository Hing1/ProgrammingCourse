#include <stdio.h>

#define N 5

/**
 * N�����Ƚ�N-1��
 * �ڲ�ѭ���±�ÿ�ζ���ͷ��ʼ������һ���Ƚ�
 * ��ѭ���Ĵ���ΪN - i - 1��
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
