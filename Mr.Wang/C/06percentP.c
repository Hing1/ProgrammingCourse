#include <stdio.h>

int main() {
    int a[3][4];

    printf("a       = %p\n",a);
    printf("a[0]    = %p\n",a[0]);
    printf("a[0][0] = %p\n",a[0][0]);

    putchar(10);

    printf("a + 1         = %p\n",a + 1);
    printf("a[0] + 1      = %p\n",a[0] + 1);
    printf("a[0][0] + 1   = %p\n",a[0][0] + 1);

    return 0;
}
