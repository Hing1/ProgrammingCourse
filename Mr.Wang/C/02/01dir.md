#

## Dir

```c
 7/ 3 =  2;
 7% 3 =  1;// 2 *  3 +  1 =  7
-7/ 3 = -2;
-7% 3 = -1;//-2 *  3 + -1 = -7
 7/-3 = -2;
 7%-3 =  1;//-2 * -3 +  1 =  7
```

## varialbe

1 数字0~9，字母‘a’~‘z’，‘A’~‘Z’，下划线'_"
2 不能以数字开头
3 不能是关键字

## exchange

```c
a = a + b;
b = a - b;
a = a - b;
```

```c
a = a ^ b;
b = a ^ b;
a = a ^ b;
```

## name

驼峰命名法</br>
myFristName

## 输出二进制

```c
#include <stdio.h>

void disBin(char ch) {
    int i = 8;
    while(i--) {
        if((1 << i) & ch)
            printf("1");
        else
            printf("0");
        if(i % 4 == 0)
            printf(" ");
    }
    putchar(10);
}
int main() {
    for(int i = -128; i < 127; i++) {
        printf("%4d ---->", i);
        disBin(i);
    }
    printf("%4d ---->", 127);
        disBin(127);

    return 0;
}
```

## 补码

0 的补码是零</br>
为什么范围是 -128 ~ 127 而不是-127 ~ 128</br>
因为补码的构造原则</br>

### 有效数字

从该数的第一个非零数字起，直到末尾数字止的数字称为有效数字

## ASCLL

|ASCLL|字符|
|-|-|
|32|speace|
|48|字符'0'|
|49|字符'1'|
|65|A|
|66|B|
|97|a|
|98|b|
