#include <stdio.h>
#include <string.h>

void encode(char * buf, char * px) {
    int len = strlen(buf);
    int n = strlen(px);

    int j = 0;
    for (int i = 0; i < len; i++) {
        if(px[j] == buf[i])
            j++;
        else {
            buf[i] ^= px[j++];
            if(j == n)
                j = 0;
        }
    }
    return;
}

void decode(char * buf, char * px) {
    int len = strlen(buf);
    int n = strlen(px);

    int j = 0;
    for (int i = 0; i < len; i++) {
        if(px[j] == buf[i])
            j++;
        else {
            buf[i] ^= px[j++];
            if(j == n)
                j = 0;
        }
    }
    return;
}

int main() {
    char buf[] = "I love xxx";
    char xx[] = "19900909";

    encode(buf, xx);
    printf("%s\n", buf);

    char buf2[1024];
    scanf("%s", buf2);
    decode(buf, buf2);
    printf("%s\n", buf);

    return 0;
}
