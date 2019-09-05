#include <stdio.h>

#define F_PRINT_ERR(e)\
do {\
    if(e == NULL) {\
        printf("Open error\n");\
        exit(-1);\
    }\
}while(0)

/**
 * 在date.txt中提前保存以下内容
1234567890abcdefg
1234567890
abcdefg
 */
int main() {
    FILE * pf = fopen("date.txt", "r+");
    F_PRINT_ERR(pf);

    char buf[10];
    int count = 0;
    while (fgets(buf, 10, pf) != NULL) {
        printf("%s",buf);
        count++;
    }
    printf("\ncount = %d\n", count);

    fclose(pf);
    return 0;
}
