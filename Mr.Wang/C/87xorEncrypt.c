#include <stdio.h>

void fun() {
//    异或清零
    int a;
    a ^= a;
    printf("%d\n", a);
}
/*
    由于异或清零，所以若ch在buf中存在，则buf中的ch将会变为0，成为字符串结束符
    解密时字符串长度不正确，只能解密一部分。
    所以ch不可以是buf中包含的字符


void encode(char * buf, char ch) {
    int len = strlen(buf);
    for (int i = 0; i < len; i++) {
        buf[i] ^= ch;
    }
    return;
}
    解决方法是:若字符相同则跳过
*/
void encode(char * buf, char ch) {
    int len = strlen(buf);
    for (int i = 0; i < len; i++) {
        if(ch == buf[i])
            continue;
        buf[i] ^= ch;
    }
    return;
}
void decode(char * buf, char ch) {
    int len = strlen(buf);
    for (int i = 0; i < len; i++) {
        if(ch == buf[i])
            continue;
        buf[i] ^= ch;
    }
    return;
}

int main() {
    char buf[] = "I love xxx";
    char ch = 'a';

    printf("%s\n", buf);

    encode(buf, ch);
    printf("%s\n", buf);
    decode(buf, ch);
    printf("%s\n", buf);

    putchar(10);
    fun();
    return 0;
}
