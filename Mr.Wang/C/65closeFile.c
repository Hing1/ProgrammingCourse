#include <stdio.h>

//fclose����ˢ���棬��û��fclose��ϵͳ�ڽ���ʱҲ���Զ�ˢ���棬������Լ�����ˢ����

int main() {
    FILE * pf = fopen("date.txt", "w");

    for (char ch = 'a'; ch <= 'z'; ch++) {
        fputc(ch, pf);
    }

    fclose(pf);
    return 0;
}
