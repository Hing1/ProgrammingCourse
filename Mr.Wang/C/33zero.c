#include <stdio.h>

/*
int     0
float   0.0
        NULL    //��ʶδ��ʼ����ָ��,�����ڴ�����ַ
        '\0'    //�ַ���������־

�ٵ���
char    '0'
ASCII   '0'
        "0"     //'0' + '\0'

*/

int main()
{
    printf("int     %d\n",0);
    printf("float   %f\n",0.0);
    printf("char    %c\n",'0');
    printf("ASCII   %d\n",'0');
    printf("NULL    %p\t\tNULL  %d\n", NULL, NULL);
    printf("'\\0'    %d\t\t\t\t'\\0'***%c***\n", '\0', '\0');
    return 0;
}
