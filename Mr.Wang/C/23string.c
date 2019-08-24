#include <stdio.h>

int main() {
    char arr[2] = "china";// 前两个字符赋值进入，后面为随机字符
    printf("arr = %s\n",arr); // 一直打印直到遇见\0

    printf("%s\n","chi\0na");
}
