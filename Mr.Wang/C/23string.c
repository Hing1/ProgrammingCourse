#include <stdio.h>

int main() {
    char arr[2] = "china";// ǰ�����ַ���ֵ���룬����Ϊ����ַ�
    printf("arr = %s\n",arr); // һֱ��ӡֱ������\0

    printf("%s\n","chi\0na");
}
