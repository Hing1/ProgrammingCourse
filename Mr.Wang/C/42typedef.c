#include <stdio.h>
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
