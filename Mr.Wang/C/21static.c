#include <stdio.h>

/**
 * static ���ξֲ�������Ĭ��ֵΪ��
 * static �洢��data���������ڵ�ͬ�ڳ������
 * static ����ֵ��ʼ��һ��
 * ��������ִ�д���
 * ��¼��ӡ�����Ĵ���
 *
 * static ����ȫ�ֱ����Ժ���������ʧ����ɱ��ļ��ڲ���ȫ�ֱ���
 * @brief fun
 */
void print(int num, int age, char sex, float score) {
    static int flag = 1;
    static int count = 0;
    if (flag == 1) {
        printf("num\tage\tsex\tscore\tidx\n");
        flag = 0;
    }
    printf("%d\t%d\t%c\t%.2f\t%d\n",num,age,sex,score,++count);
}
int main() {
    print(1001,12,'x',99);
    print(1019,12,'x',99);
    print(1009,12,'x',99);
    print(1004,12,'x',99);
    print(1025,12,'x',99);
    print(1006,12,'x',99);
    return 0;
}


#if 0
void fun() {
    int a = 1;
    printf("a = %d\t",a);

    static int b = 1;
    printf("b = %d\n",b);
}
int main()
{
    for (int i = 0; i < 10; i++) {
        fun();
    }
    return 0;
}
#endif
