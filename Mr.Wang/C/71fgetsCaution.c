#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Save the following in advance in the xx.ini file :
Hing
 */

int main() {
    FILE * pf = fopen("xx.ini", "r++");
    if(NULL == pf)
        exit(-1);

    char name[1024];
    scanf("%s", name);

    char buf[1024];
    fgets(buf, 1024, pf);

    char * p = buf;
    while (*p) p++;
    p--;
    while (*p == '\t') {
        *p = '\0';
        p--;
    }

    if(strcmp(name, buf) == 0)
        printf("Login successful!\n");
    else
        printf("Login failed!\n");

    fclose(pf);
    return 0;
}
