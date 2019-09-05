#include <stdio.h>
#include <stdlib.h>

//通过fopen打开一个一个文件，返回一个FILE*指针
//通过操作FILE*指针pf来对文件进行操作
//此处的pf被称作句柄

#if 0
r   以只读的方式打开；如果文件不存在，则报错；文件不可写
w   如果文件不存在，则创建文件，如果文件存在，则清空；文件不可读
a   如果文件不存在，则创建文件，如果文件存在，追加写；文件不可读

r+  缺啥补啥
w+
a+
#endif

#if 1
int main() {
    printf("Hello world\n");
    FILE * pf = fopen("data.txt", "r+");
    if(NULL == pf) {
        printf("Open error\n");
        exit(-1);
    }

    if(fputc('a', pf) == EOF) {
        printf("Write error\n");
        exit(-1);
    }
    fputc('a', pf);

    return 0;
}
#endif
#if 0
int main() {
    FILE * pf = fopen("data.txt", "w");
    if(NULL == pf) {
        printf("Open error\n");
        exit(-1);
    }

    if(fputc('a', pf) == EOF) {
        printf("Write error\n");
        exit(-1);
    }
    fputc('a', pf);
    fputc('b', pf);
    fputc('c', pf);

    char ch = fgetc(pf);
    if(ch == EOF) {
        printf("Read error\n");
    }
    return 0;
}
#endif
#if 0
int main() {
    FILE * pf = fopen("data.txt", "a");
    if(NULL == pf) {
        printf("Open error\n");
        exit(-1);
    }

    if(fputs("aaaaaaaaaaaaa", pf) == EOF) {
        printf("Write error\n");
        exit(-1);
    }
    fputs("aaaaaaaaaaaaa", pf);
    fputs("bbbbbbbbbbbbb", pf);
    fputs("ccccccccccccc", pf);

    char ch = fgetc(pf);
    if(ch == EOF) {
        printf("Read error\n");
    }
    printf("%c", ch);
    return 0;
}
#endif

