#include <stdio.h>
/**
 * @brief main
 * @return
 * 对变量取地址，取出的地址就是一个常量指针
 * 常量指针不是一个单纯的地址，而是地址+类型
 */
int main()
{
    char a = 1;
    short b = 2;
    int c = 10;
    double d = 123.45;

    printf("&a = %p  ",&a);printf("%#x\n",&a);
    printf("&b = %p  ",&b);printf("%#x\n",&b);
    printf("&c = %p  ",&c);printf("%#x\n",&c);
    printf("&d = %p  ",&d);printf("%#x\n",&d);
    putchar(10);

    printf("%d\n",*(&a));
    printf("%d\n",*(&b));
    printf("%d\n",*(&c));
    printf("%d\n",*(&d));

//    printf("%d\n",*(0x000000000061FE4F));
//    printf("%d\n",*(0x000000000061FE4C));
//    printf("%d\n",*(0x000000000061FE48));
//    printf("%d\n",*(0x000000000061FE40));


    printf("%d\n",*((char*  )0x000000000061FE4F));
    printf("%d\n",*((short* )0x000000000061FE4C));
    printf("%d\n",*((int*   )0x000000000061FE48));
    printf("%d\n",*((double*)0x000000000061FE40));
    return 0;

}
