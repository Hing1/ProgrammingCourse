#include <stdio.h>

/**
 * ���ģʽ����ָ���ݵĵ�λ������Ȩֵ��С�ĺ����Ǽ�λ���������ڴ�ĸߵ�ַ�У������ݵĸ�λ���������ڴ�ĵ͵�ַ��
 * С��ģʽ����ָ���ݵĵ�λ�������ڴ�ĵ͵�ַ�У������ݵĸ�λ�������ڴ�ĸߵ�ַ��
 */

union u {
    int i;
    char ch;
};

int main() {
    union u uu;
    uu.i = 0x12345678;
    if(uu.ch == 0x12)
        printf("Big endian\n");
    else //uu.ch == 0x78
        printf("Small endian\n");
    return 0;
}
