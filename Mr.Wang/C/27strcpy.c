#include <stdio.h>
#include <string.h>

// ���������ַ����������㹻�Ŀռ�
// �ȿ��� ���жϣ���++��

char * myStrcpy(char * dest, char * src) {
    char * d = dest;
    while(*dest++ = *src++);
    return d;
}

int main()
{
    char name[200];
    char * pName = "china";
    char name2[200] = "cyuyan";

    myStrcpy(name, name2);
    printf("%s\n",name);
    return 0;
}
