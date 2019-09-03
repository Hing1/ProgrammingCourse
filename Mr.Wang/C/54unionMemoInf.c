#include <stdio.h>

struct Staff {
    char name[30];
    char job;
    union {
        int grade;
        char position[50];
    }gOrp;
};

void printStaff(struct Staff * sta);

int main()
{
    struct Staff sta;

    printf("Please input the name : ");
    scanf("%s", sta.name);
    printf("Please input the job(s or p) : ");
    scanf(" %c", &sta.job);

    if(sta.job == 's') {
        printf("Please input the grade : ");
        scanf("%d", &sta.gOrp.grade);
    }else {
        printf("Please input the position : ");
        scanf("%s", sta.gOrp.position);
    }

    printStaff(&sta);
    return 0;
}

void printStaff(struct Staff * sta) {
    printf("name     = %s\n", sta->name);
    printf("job      = %c\n", sta->job);
    if(sta->job == 's')
        printf("grade    = %d\n", sta->gOrp.grade);
    else
        printf("position = %s\n", sta->gOrp.position);
}
