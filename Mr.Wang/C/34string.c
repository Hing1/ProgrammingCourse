#include <stdio.h>
#include <string.h>

int main()
{
    char * p = "china";
    char arr[10] = "china";
    return 0;
}

#if 0
            strlen      sizeof()
"china"     5           6
p           5           4
arr         5           10
#endif

#if 0
int main() { // ���л������Ϊchar * ������Ϊ����������ƴ�ӣ�ֻ��char arr[10]���͵Ĳſ���
    char * p = "abcd";
    char * q = "efgh";
    strcat(p,q);
}
# endif
