#include <stdio.h>
#include <stdlib.h>

//����ͳ�ʼ������С��λ�����ֽ�

void primaryDataType() {
    //��������������ջ�Ͷ���
    int a;
    a = 100;

    //p ��ջ�ϣ�p�洢��Ϊ��ַ���õ�ַָ��ѵ�һ�οռ�
    int * p = (int*)malloc(1 * sizeof (int));
    *p = 100;

    printf("a  = %d\n", a);
    printf("*p = %d\n",*p);
}
void arrayMalloc() {
    int arr[10];

    int * pa = (int*)malloc(10 * sizeof (int));

    memset (pa, 0, 10 * sizeof (int));
    for (int i = 0; i < 10; i++) {
        printf("pa[%d] = %d\n", i, pa[i]);
    }
/*
    //������printf("pa[%d] = %d\n", i, *pa++);//��Ϊ���pa��λ�ñ��˺�free�ᱨ��
    //���Ը�Ϊ��������
    int * pacopy = pa;
    for (int i = 0; i < 10; i++) {
        printf("pa[%d] = %d\n", i, pacopy++);
    }
    
*/
    free(pa);
/*
    memset (pa, 1, 10 * sizeof (int));//Ϊ��01010101��16
    for (int i = 0; i < 40; i++) {
        printf("pa[%d] = %#\n", i, ((char*)pa)[i]);
    }
*/
}
void arrayCalloc() {
    //�����������Զ���ʼ��
    int *p = (int*)calloc(10, sizeof (int));
    for(int i = 0; i < 10; i++) {
        printf("%d\n", p[i]);
    }
    free(p);
}

int main()
{
    primaryDataType();
    arrayMalloc();
    arrayCalloc();
    return 0;
}
