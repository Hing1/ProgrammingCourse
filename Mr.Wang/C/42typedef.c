#include <stdio.h>

//struct类型可以定义在任意位置
//一般定义在main（）函数前，#include之后
//项目中定义在头文件中

/**
 * typedef typerename 对已有类型取别名
 * 
 * 1. 用现有类型生成变量
 * 2. 在变量定义之前加typedef
 * 3. 将定义的变量换成别名
 */
#if 0
typedef char        int8;
typedef short       int16;
typedef int         int32;
typedef long long   int64;
typedef int ARRAY[10];

int main()
{
    int8  a;
    int16 b;
    int32 c;
    int64 d;

    int arr1[10];
    printf("arr1    %d\n", sizeof (arr1));
    printf("int[10] %d\n", sizeof (int[10]));

    ARRAY arr2;
    printf("arr2    %d\n", sizeof (arr2));

    return 0;
}
#endif

typedef struct stu {    //别名结构体
    char name[10];
    int ID;
    int score;
} Stu;

int main() {
    struct stu s1;
    Stu s2;
}
