#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if 0
Դ����     ��Դ����
����       ����ִ���ļ�
.exe

����       ʱ����� �ӿ�ִ���ļ������𵽽�������һ�ι��̣���Ϊ����
���̿ռ�    ��ִ���ļ�����������ڴ��еķֲ����


stack   ջ
heap    ��
data
text
#endif

#if 0
4G
    ...     //�ں˿ռ�
3G
    ...

            //�û��ռ�
    ...
0
#endif

#if 0
ջ�ռ� 1M���ң����ڽ������ݣ��������ڴ�ռ������
�ѿռ���Ҫ���ڴ��ڴ������ʹ��

ջ�ĵ�ַ��չ����Ӵ��ַ��С��ַ
#endif

#if 0
���ڴ���Դ�������������ݣ���Ҫ�Լ�������ͷ�
�ѵĴ�С�������ջ��˵����Ϊ�����
malloc ���ֽ�Ϊ��λ������ڴ�
#endif

void sizeofStack() {
    char arr[1024 * 1024] = {0}; // 1M
    strcpy(arr, "china");
    printf("sizeofStack() over!!!\n");
}
void dictionStack() {
    printf("dictionStack()\n");
    int a, b, c, d;
    printf("%p\n",&a);
    printf("%p\n",&b);
    printf("%p\n",&c);
    printf("%p\n",&d);
}
void sizeofHeap() {
    char * p =(char *)malloc(1024 * 1024 * 1024 * 5);   // 5G
    if (p == NULL)
        printf("malloc error!\n");
    strcpy(p, "abcd");
    printf("sizeofHeap() over!\n");
    free(p);
}
void dictionHeap() {
    printf("dictionHeap()\n");
    char *pa, *pb, *pc, *pd;
    pa = (char*)malloc(100);
    pb = (char*)malloc(100);
    pc = (char*)malloc(100);
    pd = (char*)malloc(100);
    printf("%p\n", pa);
    printf("%p\n", pb);
    printf("%p\n", pc);
    printf("%p\n", pd);
}

int main()
{
    dictionHeap();
    dictionStack();
    //sizeofStack();
    //sizeofHeap();
    return 0;
}
