#include <stdio.h>

/**
 * @brief main
 * auto ֻ���������ξֲ���������ʾ�ñ����洢��ջ��stack
 * �洢��ջ�ϵ����������濪��������ʧ
 * Ĭ�ϵľֲ�������auto���͵�
 *
 * register �洢��cpu�ϵı������ٶȺܿ죬���������ޣ�ͨ�����Զ��Ż�
 * ֻ�����ξֲ�����
 *
 * extern ���ļ���������ǰ����
 * ȫ�ֱ�����Ĭ��ֵΪ0
 * �ֲ�������Ĭ��ֵΪ���ֵ
 *
 * @return
 */

void fun() {
    auto int a;
}

int main()
{
    auto int a;
    printf("Hello World!\n");
    return 0;
}
