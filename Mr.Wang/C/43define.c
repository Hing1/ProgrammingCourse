#include <stdio.h>

/**
 * typedef ���ɵ�C�������������
 * #define ���ɵ������Ԥ����׶δ������
 */
#define DINT int

int main() {
    typedef int TINT;

    DINT a = 5;
    TINT b = 6;

    printf("sizeof (a)    = %d\n", sizeof (a));
    printf("sizeof (b)    = %d\n", sizeof (b));
    printf("sizeof (int)  = %d\n", sizeof (int));
    printf("sizeof (DINT) = %d\n", sizeof (DINT));
    printf("sizeof (TINT) = %d\n", sizeof (TINT));

    return 0;
}