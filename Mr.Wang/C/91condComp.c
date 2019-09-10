#include <stdio.h>

#define X86     1
#define MIPS    2
#define POWERPC 3

#define MACHINE X86

int main() {
#if X86
    printf("Hello World!\n");
#else
    printf("Hello World!\n");
#endif

#ifdef X86
    printf("Hello World!\n");
#else
    printf("Hello World!\n");
#endif
    
#ifndef X86
    printf("Hello World!\n");
#else
    printf("Hello World!\n");
#endif

#if MACHINE==X86
    printf("1");
#elif MACHINE==MIPS
    printf("2");
#elif MACHINE==POWREPC
    printf("3");
#endif
    
    return 0;
}
