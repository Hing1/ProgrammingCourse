#include <stdio.h>
/**
 * ����ṹ�庯����ָ�봫�Σ�Ч�ʸ���
 */

typedef struct _MyComplex
{
    float x;
    float y;
} MyComplex;

MyComplex addComplex(MyComplex * pa, MyComplex * pb) {
    MyComplex temp;
    temp.x = pa->x + pb->x;
    temp.y = pa->y + pb->y;
    return temp;
}

int main () {
    MyComplex x = {1, 2};
    MyComplex y = {3, 4};

    MyComplex z = addComplex(&x, &y);

    printf("(%d, %d)\n", z.x, z.y);

    return 0;
}
