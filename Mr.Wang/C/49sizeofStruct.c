#include <stdio.h>

/**
 * ���ͱ����ǲ�ռ�ռ�ģ����Ͳ����ı�����ռ�ÿռ�
 * �ṹ���е�ÿ����Ա�ĵ�ַ���ǿ��Ի�õ�
 *
 * �ö������ȡ��һ��������������������ԭ�����ڴ治����
 * Ҫʵ���ڴ���룬�����ռ䣬��ȡʱ��
 */

#if 0
pack    n   8       4   m
                    Y = 4 �����
        1
        2
        4
                    x = 1 �ڶ���
                        2
                        4
x86(linux Ĭ��#pragma pack(4), window Ĭ��#pragma pack(8))��linux ���֧�� 4 �ֽڶ��롣
1.ȡ pack(n)��ֵ��n= 1 2 4 8--),ȡ�ṹ�����������ֵ m������ȡС��Ϊ������ С Y= (m<n?m:n)��
2.��ÿһ���ṹ��ĳ�Ա��С�� Y �Ƚ�ȡС��Ϊ X,��Ϊ�ڶ����С.
3.��ν�� X ���룬��Ϊ��ַ(����ʼ��ַΪ 0)�ܱ� X �����ĵط���ʼ�������
4.�ⲿ����ԭ�������� Y ��ֵ(Y ����С������)�����в��ղ���
#endif

//  #pragma pack(1)

#if 0
typedef struct _stu {
    char sex;
    int age;
    short num;
} Stu;
#endif
#if 1
typedef struct _stu {
    char sex;
    short num;
    int age;
} Stu;
#endif

int main() {
    printf("sizeof(char)  = %d\n", sizeof (char));
    printf("sizeof(short) = %d\n", sizeof (short));
    printf("sizeof(int)   = %d\n", sizeof (int));
    putchar(10);

    Stu m;
    printf("sizeof(m)   = %d\n", sizeof (m));
    printf("sizeof(Stu) = %d\n", sizeof (Stu));

    printf("m       %p\n", &m);
    printf("m.sex   %p\n", &m.sex);
    printf("m.age   %p\n", &m.age);
    printf("m.num   %p\n", &m.num);

    return 0;
}
