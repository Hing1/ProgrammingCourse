#include <stdio.h>

#define F_PRINT_ERR(e)\
do {\
    if(e == NULL) {\
        printf("Open error\n");\
        exit(-1);\
    }\
}while(0)

#if 0
int main() {
    FILE * pf = fopen("date.txt", "w+");
    F_PRINT_ERR(pf);

    for (char ch = 'a'; ch <= 'z'; ch++) {
        putchar(fputc(ch, pf));
    }

    fclose(pf);
    return 0;
}
#endif
#if 1
int main() {
    FILE * pf = fopen("date.txt", "r+");
    F_PRINT_ERR(pf);

    putchar(10);
    char ch;
    while ((ch = fgetc(pf)) != EOF) {
        putchar(ch);
    }

    fclose(pf);
    return 0;
}
#endif
