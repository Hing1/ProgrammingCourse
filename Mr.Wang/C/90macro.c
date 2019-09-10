#include <stdio.h>
/**
 * 1.不要吝惜括号
 * 2.宏函数S紧接的括号间不可以有空格
 */

#define N 2 + 3
#define M (2 + 3)

// 常用
#define ERR_EXIT(m)\
do {\
    printf("Err:%s", m);\
    exit(-1);\
} while(0)

#define MAX(a,b) ((a)>(b)?(a):(b))

int main() {
    printf("N = %d\n", N);
    printf("N * 2 = %d\n", N * 2);
    printf("M * 2 = %d\n", M * 2);
//#undef MAX
    int a = MAX(9,8);

    FILE * pf = fopen("aa.c", "r");
    ERR_EXIT(pf);

    return 0;
}
