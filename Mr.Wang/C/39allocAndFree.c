#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// alloc �� free ���ʹ��
// ���� �п� ʹ�� �ͷ� �ÿ�
// By Yourself˭����˭�ͷ�

int main()
{
    char * pc = (char*)malloc(100);
    if(NULL == pc) { // ��ֹд��(pc = NULL)
        printf("Error1!\n");
        exit(-1);
    }
    strcpy(pc, "abcdefg");
    free(pc);
    pc = NULL;

    if(NULL == pc) {
        printf("Error2!\n");
        exit(-1);
    }
    strcpy(pc, "abcdefg");

    return 0;
}
