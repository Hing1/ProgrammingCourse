#include <stdio.h>

int main() {
    int data;
    int *pd = &data; // *������������
    *pd = 200;       // ������ ȡ����

    char * p1, q1;   // ǰ����ָ�룬�����Ǳ���
    printf("sizeof(p1) = %d, sizeof(q1) = %d\n",sizeof(p1), sizeof(q1));
    char * p2, * q2; // ���߶��Ǳ���
    printf("sizeof(p2) = %d, sizeof(q2) = %d\n",sizeof(p2), sizeof(q2));

    return 0;
}