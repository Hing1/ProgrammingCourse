#include <stdio.h>
#include <string.h>

// 被拷贝的字符串必须有足够的空间
// 先拷贝 再判断，再++；

char * myStrcpy(char * dest, char * src) {
    char * d = dest;
    while(*dest++ = *src++);
    return d;
}

int main()
{
    char name[200];
    char * pName = "china";
    char name2[200] = "cyuyan";

    myStrcpy(name, name2);
    printf("%s\n",name);
    return 0;
}
