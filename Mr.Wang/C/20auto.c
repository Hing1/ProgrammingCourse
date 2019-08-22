#include <stdio.h>

/**
 * @brief main
 * auto 只能用于修饰局部变量，表示该变量存储在栈上stack
 * 存储在栈上的数：随用随开，用完消失
 * 默认的局部变量是auto类型的
 *
 * register 存储于cpu上的变量，速度很快，但数量有限，通常被自动优化
 * 只能修饰局部变量
 *
 * extern 跨文件声明或提前声明
 * 全局变量的默认值为0
 * 局部变量的默认值为随机值
 *
 * @return
 */

void fun() {
    auto int a;
}

int main()
{
    auto int a;
    printf("Hello World!\n");
    return 0;
}
