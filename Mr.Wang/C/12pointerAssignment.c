#include <stdio.h>

int main() {
    int data = 0x12345678;

    char * pc = &data; // 在C++中不允许
    // char * pc = (char *)&data; // 在C++中应该这样
    printf("%#x\n",*pc);

    return 0;
}