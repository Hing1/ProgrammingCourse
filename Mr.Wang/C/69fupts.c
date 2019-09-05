#include <stdio.h>

#define F_PRINT_ERR(e)\
do {\
    if(e == NULL) {\
        printf("Open error\n");\
        exit(-1);\
    }\
}while(0)

/**
 * 在去读 n - 1 个字符前，遇到了\n，连同\n一并读进，并在其后添加了\0
 * 在去读 n - 1 个字符前，既没有遇到\n，也没有遇到EOF，此时读到了 n - 1 个字符，并在其后添加\0
 * 在去读 n - 1 个字符前，没有遇到\n，但遇到了EOF，此时在其后加\0
 */
#if 0
int main() {
    FILE * pf = fopen("date.txt", "w");
    F_PRINT_ERR(pf);

    fputs("aaa\naaaaaaa\n", pf);
    fputs("bbbbbbbbbb\n", pf);
    fputs("cccccccccc\n", pf);

    fclose(pf);
    return 0;
}
#endif

#if 1
int main() {
    FILE * pf = fopen("date.txt", "r");
    F_PRINT_ERR(pf);

    char buf[1024];
    fgets(buf, 1024, pf);
    printf("buf = %s", buf);

    fclose(pf);
    return 0;
}
#endif
