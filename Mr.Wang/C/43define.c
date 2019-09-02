#include <stdio.h>

/**
 * typedef 构成的C语言语句参与编译
 * #define 构成的语句在预处理阶段处理完成
 */
#define DINT int

int main() {
    typedef int TINT;

    DINT a = 5;
    TINT b = 6;

    printf("sizeof (a)    = %d\n", sizeof (a));
    printf("sizeof (b)    = %d\n", sizeof (b));
    printf("sizeof (int)  = %d\n", sizeof (int));
    printf("sizeof (DINT) = %d\n", sizeof (DINT));
    printf("sizeof (TINT) = %d\n", sizeof (TINT));

    return 0;
}