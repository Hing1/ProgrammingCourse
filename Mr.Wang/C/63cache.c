#include <stdio.h>

//Windows 自动刷缓存，所以在Linux上才可以体现出来

#if 0
int main() {
    printf("Hello World!");
    while (1);
    return 0;
}
#endif
#if 0
int main() {
    printf("Hello World!\n");
// \n 有刷缓存的作用
    while (1);
    return 0;
}
#endif
#if 1
int main() {
    while (1) {
        printf("+++++++++++++++");
        printf("+++++++++++++++");
        printf("+++++++++++++++");
        printf("+++++++++++++++");
        sleep(1);
    }
}
#endif
