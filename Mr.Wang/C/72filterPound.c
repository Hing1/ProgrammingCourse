#include <stdio.h>

int main() {
    FILE * pf = fopen("smb.conf", "r+");
    if(NULL == pf)
        exit(-1);

    FILE * pfBak = fopen("smb.conf.bak", "w");
    if(NULL == pfBak) {
        fclose(pf);
        exit(-1);
    }

    char buf[1024];
    while (fgets(buf, 1024, pf)) {
        if(*buf == '#' || *buf == '\n')
            continue;
        printf("%s", buf);
        fputs(buf, pfBak);
    }

    fclose(pf);
    fclose(pfBak);
    return 0;
}
