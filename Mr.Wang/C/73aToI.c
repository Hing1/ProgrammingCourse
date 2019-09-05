#include <stdio.h>

int main() {
    char * p = "123  \n";
    int num = atoi(p);
    printf("%d\n", num);
    return 0;
}
