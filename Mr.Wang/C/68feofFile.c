#include <stdio.h>

//feof 检测文件结束标志，1表示结束，0表示没有结束
//feof 会导致多读一次字符，标志位检测滞后

#define F_PRINT_ERR(e)\
do {\
    if(e == NULL) {\
        printf("Open error\n");\
        exit(-1);\
    }\
}while(0)

int main() {
    FILE * pf = fopen("date.txt", "w+");
    F_PRINT_ERR(pf);

    for (char ch = 'a'; ch <= 'g'; ch++) {
        putchar(fputc(ch, pf));
    }

    rewind(pf);
    printf("\n+++++++++++++++++++++\n");
    char ch;
    while (!feof(pf)) {
        ch = fgetc(pf);
        printf("%x -> %c\n", ch, ch);
    }

    rewind(pf);
    printf("\n+++++++++++++++++++++\n");
    while ((ch = fgetc(pf)) && !feof(pf)) {
        printf("%x -> %c\n", ch, ch);
    }
    
    fclose(pf);
    return 0;
}
