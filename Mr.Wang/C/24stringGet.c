#include <stdio.h>

// scanf遇到空格结束输入，注意不可以越界
// gets 空格也可以读入
// fget 最安全

int main() {
    char arr[] = "china";
    printf("%s",arr);
    puts(arr);
    printf("============\n");
    puts("");
    printf("============\n");
    return 0;
    scanf("%s",arr);
    gets(arr);
    fgets(arr,6,stdin);
    return 0;
}
