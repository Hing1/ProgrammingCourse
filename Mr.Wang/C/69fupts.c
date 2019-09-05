#include <stdio.h>

#define F_PRINT_ERR(e)\
do {\
    if(e == NULL) {\
        printf("Open error\n");\
        exit(-1);\
    }\
}while(0)

/**
 * ��ȥ�� n - 1 ���ַ�ǰ��������\n����ͬ\nһ��������������������\0
 * ��ȥ�� n - 1 ���ַ�ǰ����û������\n��Ҳû������EOF����ʱ������ n - 1 ���ַ�������������\0
 * ��ȥ�� n - 1 ���ַ�ǰ��û������\n����������EOF����ʱ������\0
 */
#if 0
int main() {
    FILE * pf = fopen("date.txt", "w");
    F_PRINT_ERR(pf);

    fputs("aaa\naaaaaaa\n", pf);
    fputs("bbbbbbbbbb\n", pf);
    fputs("cccccccccc\n", pf);

    fclose(pf);
    return 0;
}
#endif

#if 1
int main() {
    FILE * pf = fopen("date.txt", "r");
    F_PRINT_ERR(pf);

    char buf[1024];
    fgets(buf, 1024, pf);
    printf("buf = %s", buf);

    fclose(pf);
    return 0;
}
#endif
