#include <stdio.h>

int func1(int n) { 
    if(n == 0)
        return 1;
    else
        return func1(--n) + 2;
        //return func1(n - 1) + 2; //Ч����ͬ
}

int func2(int n) {
    if(n == 0)
        return 1;
    else
        return n * func2(n - 1); 
    // ���ﲻ������n--����Ϊ����һֱ�ڲ�������
    // �ݹ�����в���n��ֵ����ȷ
}

int main() {
    printf("%d\n",func1(5));
    printf("%d\n",func1(5));
    return 0;
}