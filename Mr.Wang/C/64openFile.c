#include <stdio.h>
#include <stdlib.h>

//ͨ��fopen��һ��һ���ļ�������һ��FILE*ָ��
//ͨ������FILE*ָ��pf�����ļ����в���
//�˴���pf���������

#if 0
r   ��ֻ���ķ�ʽ�򿪣�����ļ������ڣ��򱨴��ļ�����д
w   ����ļ������ڣ��򴴽��ļ�������ļ����ڣ�����գ��ļ����ɶ�
a   ����ļ������ڣ��򴴽��ļ�������ļ����ڣ�׷��д���ļ����ɶ�

r+  ȱɶ��ɶ
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

