#include <stdio.h>
/**
 * ��ֵ+1������+1
 * ָ��+1���ӵ��ǲ�������ָ�����͵Ĵ�С��sizeof(T)�Ĵ�С��
 */
int main() {
    int data = 0x0001;
    int * p = (int *)0x0001;

    printf("       data = %#x,        data + 1 = %#x\n", data, data + 1);
    printf("          p = %#x,           p + 1 = %#x\n", p   , p    + 1);
    printf("(double *)p = %#x, (double *)p + 1 = %#x\n", (double *)p, (double *)p + 1);
    printf("     (int)p = %#x,      (int)p + 1 = %#x\n", (int)p, (int)p + 1);

	return 0; 
}