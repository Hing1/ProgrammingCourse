#include <stdio.h>

int main() {
    for(char ch = 'a'; ch <= 'z'; ch ++) {
        printf("ch = %d 小写ch = %c\n", ch, ch);
        printf("ch = %d 大写ch = %c\n", ch - 32, ch - 32);
        printf("ch = %d 大写ch = %c\n", ch - ' ', ch - ' ');//空格的ASCLL为32
    }
}