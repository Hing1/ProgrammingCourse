#include <stdio.h>

#if 0
1字节 char
unsigned char   0  ~ 255
char          -128 ~ 127

2字节 short
    0  ~ 65535    0   ~ 2^16-1
-32768 ~ 32767  -2^15 ~ 2^15 -1

4字节 int
0   ~ 2^32-1
-2^31 ~ 2^31 -1

#endif

int main() {
    printf("sizeof(char       ) = %d\n",sizeof(char       ));//1字节
    printf("sizeof(short      ) = %d\n",sizeof(short      ));//2
    printf("sizeof(int        ) = %d\n",sizeof(int        ));//4
    printf("sizeof(long       ) = %d\n",sizeof(long       ));//4
    printf("sizeof(long long  ) = %d\n",sizeof(long long  ));//8
    printf("sizeof(float      ) = %d\n",sizeof(float      ));//4
    printf("sizeof(double     ) = %d\n",sizeof(double     ));//8
    printf("sizeof(long double) = %d\n",sizeof(long double));//12
    
    return 0;
}