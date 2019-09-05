#include <stdio.h>

#define F_PRINT_ERR(e)\
do {\
    if(e == NULL) {\
        printf("Open error\n");\
        exit(-1);\
    }\
}while(0)


int main() {
    FILE * pfr = fopen("C:/Users/Hing/Desktop/Project/QtProject/1909/31copyFile/main.c", "r+");
    F_PRINT_ERR(pfr);

    FILE *pfw = fopen("C:/Users/Hing/Desktop/copy.c", "w+");
    F_PRINT_ERR(pfw);

    char ch;
    while ((ch = fgetc(pfr)) != EOF) {
        putchar(fputc(ch, pfw));
    }

    fclose(pfr);
    fclose(pfw);
    return 0;
}
