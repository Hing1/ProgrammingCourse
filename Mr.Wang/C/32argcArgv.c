#include <stdio.h>

//char *   argv[]
//�ַ� ָ�� ����     ���ָ������

//����������ʱ��ͨ�������д��ݸ����̵Ĳ����������ݸ�main�Ĳ���

//arg  argument  ����
//c    count     ����
//v    vector
//argc  ��������
//argv  ָ����������

// a.out 100 //100Ϊִ�д���

int main(int argc, char * argv[])
{
    for (int i = 0; i < argc; i++) {
        printf("argv[%d] = %s\n", i, argv[i]);
    }
    return 0;
}

#if 0
int main(int argc, char * argv[]) {
    int num = atoi(argv[1]);

    for (int i = 0; i < num; i++) {
        printf("*******************\n");
    }
}
#endif
