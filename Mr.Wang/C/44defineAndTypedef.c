#include <stdio.h>

int main()
{
    char * p, q;
    printf("sizeof (p) = %d\tsizeof (q) = %d\n", sizeof (p), sizeof (q));

    typedef char * pChar;
    pChar a, b;
    printf("sizeof (a) = %d\tsizeof (b) = %d\n", sizeof (a), sizeof (b));

#define DpChar char *
    DpChar m, n;
    printf("sizeof (m) = %d\tsizeof (n) = %d\n", sizeof (m), sizeof (n));
    return 0;
}
