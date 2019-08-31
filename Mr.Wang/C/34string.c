#include <stdio.h>
#include <string.h>

int main()
{
    char * p = "china";
    char arr[10] = "china";
    return 0;
}

#if 0
            strlen      sizeof()
"china"     5           6
p           5           4
arr         5           10
#endif

#if 0
int main() { // 运行会出错，因为char * 的区域为常量，不能拼接，只有char arr[10]类型的才可以
    char * p = "abcd";
    char * q = "efgh";
    strcat(p,q);
}
# endif
