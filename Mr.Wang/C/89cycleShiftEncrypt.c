#include <stdio.h>

void encode(char * buf, int n) {
    for (int i = 0; i < n; i++) {
        unsigned char ch = buf[i];
        buf[i] = (ch << 1) | (ch >> 7);
    }
}

void decode(char * buf, int n) {
    for (int i = 0; i < n; i++) {
        unsigned char ch = buf[i];
        buf[i] = (ch >> 1) | (ch << 7);
    }
}

int main() {
    FILE * pfr = fopen("01.png", "rb+");
    if(NULL == pfr)
        exit(-1);

    FILE * pfw = fopen("02.png", "wb+");
    if(NULL == pfw) {
        fclose(pfr);
        exit(-1);
    }

    char buf[1024];

    int n;
    while ((n = fread(buf, 1, 1024, pfr)) > 0) {
        encode(pfr, n);
        fwrite(buf, 1, n, pfw);
    }

    fclose(pfw);
    fclose(pfr);
    return 0;
}
