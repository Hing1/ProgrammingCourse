#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if 0
typedef struct _stu {
    char name[30];
    int num;
} Stu;

int main()
{
    Stu s;
    strcpy(s.name, "Bob");
    s.num = 1;
    return 0;
}
#endif

typedef struct _stu {
    char * name;
    int num;
} Stu;

void fun () {
    Stu s;
//    strcpy(s.name, "Bobbbbbbbbbbbbbb");
//    s.name = "BBob";
    s.name = (char*)malloc(100);
    strcpy(s.name, "Bob");
    s.num = 1;

    printf("name = %s, num = %d", s.name, s.num);
    free(s.name);
}

int main()
{
    fun();
    return 0;
}
