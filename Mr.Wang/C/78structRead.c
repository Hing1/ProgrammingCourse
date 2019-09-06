#include <stdio.h>

/**
  结构体中类型不统一
  可以将二进制转化为文本，使其统一，降低效率，占用多余的空间
  */

typedef struct _stu {
    int num;
    char name[30];
    char sex;
    float math;
    float english;
    float chinese;
} Stu;
#if 0
int main()
{
    Stu s[3] = {
        1001, "aaa", 'x', 12, 23, 34,
        1002, "bbb", 'x', 45, 56, 67,
        1003, "ccc", 'y', 78, 89, 90
    };

    FILE * pfs = fopen("stu.data", "w+");
    if(pfs == NULL)
        exit(-1);

    for (int i = 0; i < 3; i++) {
        fwrite((void*)&s[i], sizeof (Stu), 1, pfs);
    }

    fclose(pfs);
    return 0;
}
#endif
#if 1
int main() {
    FILE * pf = fopen("stu.data", "r+");
    if(NULL == pf)
        exit(-1);

    Stu s;
    while (fread((void*)&s, sizeof(Stu), 1, pf)) {
        printf("num     = %d\n", s.num    );
        printf("name    = %s\n", s.name   );
        printf("sex     = %c\n", s.sex    );
        printf("math    = %.2f\n", s.math   );
        printf("english = %.2f\n", s.english);
        printf("chinese = %.2f\n", s.chinese);
        putchar(10);
    }

    fclose(pf);
}
#endif
