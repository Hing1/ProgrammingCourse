#include <stdio.h>

/**
 * static 修饰局部变量，默认值为零
 * static 存储在data，生命周期等同于程序进程
 * static 变量值初始化一次
 * 控制语句的执行次数
 * 记录打印函数的次数
 *
 * static 修饰全局变量以后，外延性消失，变成本文件内部的全局变量
 * @brief fun
 */
void print(int num, int age, char sex, float score) {
    static int flag = 1;
    static int count = 0;
    if (flag == 1) {
        printf("num\tage\tsex\tscore\tidx\n");
        flag = 0;
    }
    printf("%d\t%d\t%c\t%.2f\t%d\n",num,age,sex,score,++count);
}
int main() {
    print(1001,12,'x',99);
    print(1019,12,'x',99);
    print(1009,12,'x',99);
    print(1004,12,'x',99);
    print(1025,12,'x',99);
    print(1006,12,'x',99);
    return 0;
}


#if 0
void fun() {
    int a = 1;
    printf("a = %d\t",a);

    static int b = 1;
    printf("b = %d\n",b);
}
int main()
{
    for (int i = 0; i < 10; i++) {
        fun();
    }
    return 0;
}
#endif
