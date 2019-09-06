#include <stdio.h>

/**
 * fwrite and fread will ignore \n and \0
 */
#if 0
int main()
{
    FILE * pfa = fopen("xx.txt" , "w+");
    char buf[1024] = "a\nbc\0defg";
    fputs(buf, pfa);

    rewind(pfa);
    char readArr[1024];
    fgets(readArr, 1024, pfa);
    printf("%s", readArr);
    fclose(pfa);

    printf("++++++++++++++++\n");

    FILE * pfb = fopen("yy.txt", "wb+");
    fwrite((void*)buf, 1, 8,pfb);
    rewind(pfb);
    fread((void*)readArr, 1, 8, pfb);

    for (int i = 0; i < 8; i++) {
        printf("%x -> %c\n", readArr[i], readArr[i]);
    }

    fclose(pfb);
    return 0;
}
#endif

int main() {
    FILE * pf1 = fopen("xxx.txt" , "w+");
    int arr[10] = {0,1,0xffffffff,2,3,4,5,6,7,8};
    fputs((char*)arr, pf1);
    fclose(pf1);

    FILE * pf2 = fopen("xxxx.txt" , "wb+");
    fwrite((char*)arr, 4, 10, pf2);

    int arrCpy[10];
    fread((void*)arrCpy, 4, 10, pf2);
    for (int i = 0; i < 10; i++) {
        printf("%d\n", arrCpy[i]);
    }

    fclose(pf2);
    return 0;
}
