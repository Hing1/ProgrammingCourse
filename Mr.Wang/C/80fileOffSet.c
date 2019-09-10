#include <stdio.h>

int main() {
    FILE * pf = fopen("xx.txt", "w+");
    fputs("abcdefg", pf);
    int n = ftell(pf);
    printf("n = %d\n", n);

    rewind(pf);
    n = ftell(pf);
    printf("n = %d\n", n);

    fseek(pf, 0, SEEK_END);
    n = ftell(pf);
    printf("n = %d\n", n);

    fseek(pf, -1, SEEK_END);
    n = ftell(pf);
    printf("n = %d\n", n);

    fseek(pf, 0, SEEK_SET);
    n = ftell(pf);
    printf("n = %d\n", n);

    fseek(pf, 1, SEEK_CUR);
    n = ftell(pf);
    printf("n = %d\n", n);

    return 0;
}
