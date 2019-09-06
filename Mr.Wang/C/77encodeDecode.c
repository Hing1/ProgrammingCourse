#include <stdio.h>
#include <string.h>

//xx.exe  -c      src     dest
//xx.exe  -d      src     dest
//argv[0] argv[1] argv[2] argv[3]

void encode(char * buf, int n) {
    for (int i = 0; i < n; i++) {
        buf[i]++;
    }
}
void decode(char * buf, int n) {
    for (int i = 0; i < n; i++) {
        buf[i]--;
    }
}

int main(int argc, char * argv[]) {

    if(argc != 4) {
        printf("use xx.exe -d[-c] src dest\n");
        exit(-1);
    }

    FILE * pfr = fopen(argv[2], "rb+");
    if(NULL == pfr)
        exit(-1);

    FILE * pfw = fopen(argv[3], "wb+");
    if(NULL == pfw) {
        fclose(pfr);
        exit(-1);
    }

    int n, buf[1024];
    if(strcmp(argv[1], "-c") == 0) {
        while ((n = fread((void*)buf, 1, 1024, pfr)) > 0) {
            encode(buf, n);
            fwrite((void*)buf, 1, n, pfw);
        }
    }else if (strcmp(argv[1], "-d") == 0) {
        while ((n = fread((void*)buf, 1, 1024, pfr)) > 0) {
            decode(buf, n);
            fwrite((void*)buf, 1, n, pfw);
        }
    }else {
        printf("arg error!\n");
    }

    return 0;
}
