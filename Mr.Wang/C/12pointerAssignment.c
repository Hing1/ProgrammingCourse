#include <stdio.h>

int main() {
    int data = 0x12345678;

    char * pc = &data; // ��C++�в�����
    // char * pc = (char *)&data; // ��C++��Ӧ������
    printf("%#x\n",*pc);

    return 0;
}