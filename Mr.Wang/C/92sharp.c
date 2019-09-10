#include <stdio.h>

#define str1(x) #x
#define str2(x) "aaaaaaaaaaaaaaaaaaaaaa"
#define str3(x) "aaaaaaaaaa"#x"aaaaaaaa"

#define PSQR(x) printf("the sqr of "#x"= %d\n", (x) * (x))

int main() {
    char buf[] = "china"" is"" great";
    printf("%s\n", buf);

    printf("%s\n", str1(100));
    printf("%s\n", str2(100));
    printf("%s\n", str3(100));

    int y = 3;
    PSQR(y);
    PSQR(2 + 3);

    return 0;
}
