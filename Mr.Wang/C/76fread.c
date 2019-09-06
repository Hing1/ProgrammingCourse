#include <stdio.h>

int main() {
    FILE * pf = fopen("xx.txt", "w+");

    char buf[1024] = "123456789";
    fwrite(buf, 1, 9, pf);
    rewind(pf);

    char rbuf[1024];
    int n;
    n = fread(rbuf, 1, 4, pf);
    printf("n = %d\n", n);
    n = fread(rbuf, 1, 4, pf);
    printf("n = %d\n", n);
    n = fread(rbuf, 1, 4, pf);
    printf("n = %d\n", n);
    n = fread(rbuf, 1, 4, pf);
    printf("n = %d\n", n);

    fclose(pf);
    return 0;
}
