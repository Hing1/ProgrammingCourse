#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// alloc ∫Õ free ≈‰∂‘ π”√
// …Í«Î ≈–ø’  π”√  Õ∑≈ ÷√ø’
// By YourselfÀ≠…Í«ÎÀ≠ Õ∑≈

int main()
{
    char * pc = (char*)malloc(100);
    if(NULL == pc) { // ∑¿÷π–¥≥…(pc = NULL)
        printf("Error1!\n");
        exit(-1);
    }
    strcpy(pc, "abcdefg");
    free(pc);
    pc = NULL;

    if(NULL == pc) {
        printf("Error2!\n");
        exit(-1);
    }
    strcpy(pc, "abcdefg");

    return 0;
}
