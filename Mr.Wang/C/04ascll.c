#include <stdio.h>

int main() {
    for(char ch = 'a'; ch <= 'z'; ch ++) {
        printf("ch = %d Сдch = %c\n", ch, ch);
        printf("ch = %d ��дch = %c\n", ch - 32, ch - 32);
        printf("ch = %d ��дch = %c\n", ch - ' ', ch - ' ');//�ո��ASCLLΪ32
    }
}