#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * ��ʼ����һ���ر���﷨������ֵ���ȼ�
 * ���ǻ������ͣ��ȿ����ڶ����ʱ���ʼ����Ҳ�����ȶ����ٸ�ֵ
 * ���ǹ������ͣ���Ҫ�ڶ����ʱ���ʼ�����������ȶ������Գ�ʼ���ķ�ʽ��ֵ
 */

struct stu{
    int ID;
    char name[100];
    char sex;
    int age;
};

void funPointer(){
    struct stu s = {1001, "zhangsan", 'f', 19};
    struct stu * ps = &s;
    ps->ID = 123;
    printf("%d\n", ps->ID);
    printf("%d\n", (*ps).ID);
}

void mallocStruct(){
    struct stu * pps = (struct stu*)malloc(sizeof (struct stu));
}

int main()
{
    struct stu s = {1001, "zhangsan", 'f', 19};
/* ������
 * struct stu s;
 * s = {1001, "zhangsan", 'f', 19};
 */

//    s.name = "Lisi";//error
    strcpy(s.name, "Lisi");
    s.ID = 1002;
    s.sex = 'm';
    s.age = 18;

    scanf("%s%d%c%d", s.name, &s.ID, &s.sex, &s.age);

    printf("name    = %s\n", s.name);
    printf("ID      = %d\n", s.ID);
    printf("sex     = %c\n", s.sex);
    printf("age     = %d\n", s.age);

    funPointer();

    return 0;
}
