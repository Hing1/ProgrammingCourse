#include <stdio.h>

#if 0
int * fun() { // ���Գɹ����ص�ַ�����õ�ַ�����壬���ʷǷ����ܳ�������ʹ��
    int a = 100;
    return &a;
}

int main () {
    int * pa;
    pa = fun();
    printf("%d\n", *pa);
}
#endif

int * fun() { // ��Ϊstatic����������������������ͬ��������������
    static int a = 100;
    return &a;
}

int main () {
    int * pa;
    pa = fun();
    printf("%d\n", *pa);
}