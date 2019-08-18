#include <stdio.h>
/**
 * 数值+1，就是+1
 * 指针+1，加的是步长，即指针类型的大小（sizeof(T)的大小）
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