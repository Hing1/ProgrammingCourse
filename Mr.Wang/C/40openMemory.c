#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fun(char * p) {
    printf("%s\n",p);
}
void foo(char * p) {
    printf("%s\n",p);
    strcpy(p, "america");
}

int main()
{
    char * p = (char*)malloc(100);
    strcpy(p, "abcdefg");

    fun(p);
    foo(p);

    printf("%s\n",p);

    return 0;
}
