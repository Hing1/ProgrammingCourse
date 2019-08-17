#include <stdio.h>

int main()
{
    int data = 0x12345678;
    printf("%p\n",&data);

    printf("%x\n",*(&data));
    putchar(10);

    printf("%x\n",*((int*  )0x000000000061FE44));
    printf("%x\n",*((char* )0x000000000061FE44));
    printf("%x\n",*((short*)0x000000000061FE44));

    printf("=============\n");

    int * pd = &data;
    printf("%p\n",pd);
    printf("%x\n",*pd);
    printf("%x\n",*((int*  )pd));
    printf("%x\n",*((char* )pd));
    printf("%x\n",*((short*)pd));

    return 0;
}
