#include <stdio.h>

// scanf�����ո�������룬ע�ⲻ����Խ��
// gets �ո�Ҳ���Զ���
// fget �ȫ

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
