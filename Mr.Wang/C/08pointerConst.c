#include <stdio.h>
/**
 * 指针是有类型的地址
 * 类型决定了从改地址开始的寻址能力
 * A pointer is a typed address.
 * Type determines the ability to address from the address change.
 */


int main()
{
    int data = 0x12345678;
    printf("%p\n",&data);

    printf("%x\n",*(&data));
    putchar(10);
    
    printf("%x\n",*((int*  )0x000000000061FE4C));
    printf("%x\n",*((char* )0x000000000061FE4C));
    printf("%x\n",*((short*)0x000000000061FE4C));

    return 0;
}
