#include <stdio.h>

#if 0
������ڲ��洢
stack

heap

data ��ȫ�ֱ��� static�ֲ����� ������

text

#endif

/**
    C���԰��ַ������������һ��ָ��data�ε�����ַ����ĵ�ַ
 */

int main()
{
    char * p = "china";
    
    printf("p = %p, p + 1 = %p, p[0] = %c, 0[p] = %c\n", p, p + 1, p[0], 0[p]);
    printf("  = %p,   + 1 = %p,  [0] = %c, 0[ ] = %c\n", "china", "china" + 1, "china"[0], 0["china"]);
    
    return 0;
}
