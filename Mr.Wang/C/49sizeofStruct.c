#include <stdio.h>

/**
 * 类型本身是不占空间的，类型产生的变量才占用空间
 * 结构体中的每个成员的地址都是可以获得的
 *
 * 用多个机器取读一个变量，造成这种现象的原因是内存不对齐
 * 要实现内存对齐，牺牲空间，换取时间
 */

#if 0
pack    n   8       4   m
                    Y = 4 外对齐
        1
        2
        4
                    x = 1 内对齐
                        2
                        4
x86(linux 默认#pragma pack(4), window 默认#pragma pack(8))。linux 最大支持 4 字节对齐。
1.取 pack(n)的值（n= 1 2 4 8--),取结构体中类型最大值 m。两者取小即为外对齐大 小 Y= (m<n?m:n)。
2.将每一个结构体的成员大小与 Y 比较取小者为 X,作为内对齐大小.
3.所谓按 X 对齐，即为地址(设起始地址为 0)能被 X 整除的地方开始存放数据
4.外部对齐原则是依据 Y 的值(Y 的最小整数倍)，进行补空操作
#endif

//  #pragma pack(1)

#if 0
typedef struct _stu {
    char sex;
    int age;
    short num;
} Stu;
#endif
#if 1
typedef struct _stu {
    char sex;
    short num;
    int age;
} Stu;
#endif

int main() {
    printf("sizeof(char)  = %d\n", sizeof (char));
    printf("sizeof(short) = %d\n", sizeof (short));
    printf("sizeof(int)   = %d\n", sizeof (int));
    putchar(10);

    Stu m;
    printf("sizeof(m)   = %d\n", sizeof (m));
    printf("sizeof(Stu) = %d\n", sizeof (Stu));

    printf("m       %p\n", &m);
    printf("m.sex   %p\n", &m.sex);
    printf("m.age   %p\n", &m.age);
    printf("m.num   %p\n", &m.num);

    return 0;
}
