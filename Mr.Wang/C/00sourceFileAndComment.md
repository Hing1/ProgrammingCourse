# hello word

## main为入口函数

## 从源文件到可执行文件的过程

gcc -E main.c -o main.i 预处理 </br>
gcc -S main.i -o main.s 编译 </br>
gcc -c main.s -o main.o 汇编（注意-c是小写） </br>
gcc main.o    -0 hello  链接 </br>

## 注释

```c
//单行注释

/*
多行注释  不支持嵌套
*/

#if 0
条件编译
#endif
```