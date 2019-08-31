#include <stdio.h>

//char *   argv[]
//字符 指针 数组     简称指针数组

//在启动进程时，通过命令行传递给进程的参数，即传递给main的参数

//arg  argument  参数
//c    count     个数
//v    vector
//argc  参数个数
//argv  指针数组向量

// a.out 100 //100为执行次数

int main(int argc, char * argv[])
{
    for (int i = 0; i < argc; i++) {
        printf("argv[%d] = %s\n", i, argv[i]);
    }
    return 0;
}

#if 0
int main(int argc, char * argv[]) {
    int num = atoi(argv[1]);

    for (int i = 0; i < num; i++) {
        printf("*******************\n");
    }
}
#endif
