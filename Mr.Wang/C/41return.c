#include <stdio.h>
#include <stdlib.h>

/**
1.��ֵ�ǿ��Է��ص�
2.��ַ�ǿ��Է��ص�
3.ջ�ϵĿռ䲻���Է��أ���Ϊ�����濪�����꼴��
 */

int fun() {
    int a = 500;
    return a;
}
int * foo() {
/*
    int a = 500;
    printf("%p\n", &a);
    return &a;
*/
    int a = 500;
    int * pa = &a;
    printf("%p\n", pa);
    return pa;
}
char * getFormat(int size, char content) {
    char * p = (char *)malloc(size * sizeof (char));
    if(NULL == p)
        exit(-1);
    memset(p, content, size * sizeof (char) - 1);
    p[size * sizeof (char) - 1] = '\0';
    return p;
}


int main()
{
    int a = fun();
    printf("%d\n", a);

    int * pa = foo();
    printf("%p\n",pa);
    
    char * p = getFormat(100, 'a');
    printf("%s\n", p);
    free(p);
    
    return 0;
}
