#include <stdio.h>
#include <string.h>

// 被链接的串必须有足够的空间
// 返回cahr * 是为了实现链式表达

char * myStrcat(char * dest, char * src) {
    char * d = dest;
    while (*dest) dest++;
    while(*dest++ = *src++);
    return d;
}

int main() {
    char firstname[30] = "Jim";
    char lastname[30] = "Green";

    char * p;
    char * q;

    p = firstname;
    q = lastname;

    while(*p)
        p++;
/*
    while(1) {
        *p = *q;
        if(*p == '\0')
            break;
        p++;
        q++;
    }
    */
    /*
    while(1) {
        if((*p = *q) == '\0')
            break;
        p++;
        q++;
    }
    */
    /*
    while(*p = *q)
    {
        p++;
        q++;
    }*/
    while(*p++ = *q++);

    strcat(firstname, lastname);
    printf("%s\n", firstname);
}
