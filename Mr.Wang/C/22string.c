#include <stdio.h>

#if 0
计算机内部存储
stack

heap

data （全局变量 static局部变量 常量）

text

#endif

/**
    C语言把字符串常量处理成一个指向data段的这段字符串的地址
 */

int main()
{
    char * p = "china";
    
    printf("p = %p, p + 1 = %p, p[0] = %c, 0[p] = %c\n", p, p + 1, p[0], 0[p]);
    printf("  = %p,   + 1 = %p,  [0] = %c, 0[ ] = %c\n", "china", "china" + 1, "china"[0], 0["china"]);
    
    return 0;
}
