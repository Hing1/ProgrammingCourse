#include <stdio.h>

/**
 * 大端模式，是指数据的低位（就是权值较小的后面那几位）保存在内存的高地址中，而数据的高位，保存在内存的低地址中
 * 小端模式，是指数据的低位保存在内存的低地址中，而数据的高位保存在内存的高地址中
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
