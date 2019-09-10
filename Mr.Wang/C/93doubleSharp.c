#include <stdio.h>

#define sum(a,b) (a##a + b##b)
#define XNAME(n) x##n
#define PRINT_XN(n) printf("x"#n" = %d\n", x##n)

int main() {
    printf("%d\n", sum(1,2));

    int XNAME(1) = 14;
    int XNAME(2) = 20;
    printf("%d, %d\n", x1, x2);
    PRINT_XN(1);
    PRINT_XN(2);

    return 0;
}
