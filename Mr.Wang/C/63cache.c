#include <stdio.h>

//Windows �Զ�ˢ���棬������Linux�ϲſ������ֳ���

#if 0
int main() {
    printf("Hello World!");
    while (1);
    return 0;
}
#endif
#if 0
int main() {
    printf("Hello World!\n");
// \n ��ˢ���������
    while (1);
    return 0;
}
#endif
#if 1
int main() {
    while (1) {
        printf("+++++++++++++++");
        printf("+++++++++++++++");
        printf("+++++++++++++++");
        printf("+++++++++++++++");
        sleep(1);
    }
}
#endif
