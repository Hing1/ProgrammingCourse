#include <stdio.h>

int main() {
    char buf[1024] = "12345678";

    FILE * pf = fopen("oo.txt", "w+");
    if(NULL == pf)
        exit(-1);

//    fwrite((void*)buf, 1, 8, pf);
    fwrite((void*)buf, 8, 1, pf);

    rewind(pf);

    char read[10];
    int n;
//    n = fread((void*)read, 1, 8, pf);
//    printf("n = %d\n", n);
//    n = fread((void*)read, 1, 8, pf);
//    printf("n = %d\n", n);

//    n = fread((void*)read, 3, 1, pf);
//    printf("n = %d\n", n);
//    n = fread((void*)read, 3, 1, pf);
//    printf("n = %d\n", n);
//    n = fread((void*)read, 3, 1, pf);
//    printf("n = %d\n", n);

    while ((n = fread((void*)read, 1, 3, pf)) > 0) {
        for (int i = 0; i < n; i++) {
            printf("%c", read[i]);
        }
    }

    fclose(pf);
    return 0;
}
