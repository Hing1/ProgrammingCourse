#include <stdio.h>

int myStrlen(char * str) {
    int len;
    for (len = 0; *str++; len++)   
    return len;
}

int main() {
    char * p = "china";     // 将指针赋给了p
    char arr[100] = "china";// 将指针指向的内容赋给了arr

    char * q = arr;
    int count = 0;
    while (*q != '\0') {
        count++;
        q++;
    }
    printf("%d\n",count);

    q = arr;
    count = 0;
    while (*q++) {
        count++;
    }
    printf("%d\n",count);

    q = arr;
    for (count = 0; *q++; count++);
    printf("%d\n",count);
}
