#include <stdio.h>

//feof ����ļ�������־��1��ʾ������0��ʾû�н���
//feof �ᵼ�¶��һ���ַ�����־λ����ͺ�

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
