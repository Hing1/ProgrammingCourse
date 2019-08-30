#include <stdio.h>
#include <string.h>

int main()
{
    char name[100] = {0};
    char passwd[100] = {0};
    int count = 3;

    while(1){
        printf("您还有%d次机会\n",count);
        printf("Name : ");
        scanf("%s",name);
        printf("Passwd : ");
        scanf("%s",passwd);

        if(strcmp(name, "Cyuyan") == 0&&strcmp(passwd,"Cyuyan") == 0)
            break;
        else {
            count--;
            if(count == 0)
                exit(-1);
        }
    }

    return 0;
}
