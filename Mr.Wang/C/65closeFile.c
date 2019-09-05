#include <stdio.h>

//fclose主动刷缓存，若没有fclose，系统在结束时也会自动刷缓存，但最好自己主动刷缓存

int main() {
    FILE * pf = fopen("date.txt", "w");

    for (char ch = 'a'; ch <= 'z'; ch++) {
        fputc(ch, pf);
    }

    fclose(pf);
    return 0;
}
