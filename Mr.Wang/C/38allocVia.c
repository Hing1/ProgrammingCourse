#include <stdio.h>
#include <stdlib.h>

// via

int main()
{
    int * pa;
    int len1;
    printf("Star len:");
    scanf("%d", &len1);
    pa = (int*)malloc(len1 * sizeof(int));
    for (int i = 0; i < len1; i++) {
        pa[i] = 100 + i;
        printf("pa[%d] = %d\n", i, pa[i]);
    }

    int len2;
    printf("\nLarger len:");
    scanf("%d", &len2);
    pa = (int*)realloc(pa, len2 * sizeof (int));
    for (int i = 0; i < len2; i++) {
        if(i >= len1)
            pa[i] = 200 + i;
        printf("pa[%d] = %d\n", i, pa[i]);
    }

    int len3;
    printf("\nSmaller len:");
    scanf("%d", &len3);
    pa = (int*)realloc(pa, len3 * sizeof (int));
    for (int i = 0; i < len3; i++) {
        pa[i] = 300 + i;
        printf("pa[%d] = %d\n", i, pa[i]);


    free(pa);
    return 0;
}
