#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//����ռ�Ӧ�ô�������,�ͷſռ�ʱ��������

typedef struct _stu {
    char * name;
    int num;
} Stu;

int main()
{
    Stu * ps = (Stu*)malloc(sizeof (Stu));
    ps->name = (char*)malloc(100);

    strcpy(ps->name, "Green");
    ps->num = 5;

    printf("name = %s\nnum = %d\n", ps->name, ps->num);

    free(ps->name);
    free(ps);
    return 0;
}
