#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
  以链表作为内存数据模型，将文件作为数据库，将终端作为交互界面

  1.初始化数据库，此时的数据库是文件
  2.读数据库，生成内存数据模型
  3.增，查，改，删，排序
  4.更新数据库
*/
typedef struct _student{
    char name[30];
    char sex;
    int age;
    float score;
} Stu;

typedef struct _StuNode {
    Stu data;
    struct _StuNode * next;
} StuNode;

void initDate2File();
StuNode * createListFromFile(char * filePath);
void traverseStuList(StuNode * head);
void addListStu(StuNode * head);
StuNode * searchListStu(StuNode * head);
void deleteListStu(StuNode * head);
int lenListStu(StuNode * head);
void sortListStu(StuNode * head);
void saveListStu2File(StuNode * head, char * filePath);
void destoryListStu(StuNode * head);

int main() {
//    initDate2File();
    StuNode * head = createListFromFile("stu.data");

    int choice;
    StuNode * pfind;

    while (1) {
        system("cls");
        traverseStuList(head);
        printf("1->add    2->search    3->delete    4->sort    5->exit\n");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            addListStu(head);
            break;
        case 2:
            if(pfind = searchListStu(head)){
                printf("The name you search is in the system.\n");
                printf("\t%-10s\t\t%c\t\t%d\t\t%.2f\n",
                       pfind->data.name,
                       pfind->data.sex,
                       pfind->data.age,
                       pfind->data.score);
            }
            else
                printf("The name is not in the system.\n");
            getchar();getchar();
            break;
        case 3:
            deleteListStu(head);
            break;
        case 4:
            sortListStu(head);
            break;
        case 5:
            saveListStu2File(head, "stu.data");
            destoryListStu(head);
            return 0;
        default:
            printf("Input error!\n");
        }
    }
    return 0;
}

void initDate2File() {
    Stu s[4] = {
        {"aaa", 'x', 50, 100},
        {"bbb", 'x', 60, 99},
        {"ccc", 'f', 70, 98},
        {"ddd", 'f', 80, 97}
    };

    FILE * pf = fopen("stu.data", "w+");
    if(NULL == pf)
        exit(-1);

    fwrite((void*)s, sizeof (s), 1, pf);
    fclose(pf);
    return;
}

StuNode * createListFromFile(char * filePath) {
    FILE * pf = fopen(filePath, "r+");
    if(NULL == pf)
        exit(-1);

    StuNode * head = (StuNode*)malloc(sizeof (StuNode));
    head->next = NULL;

    StuNode * cur = (StuNode*)malloc(sizeof (StuNode));
    while (fread((void*)&cur->data, sizeof (Stu), 1, pf)) {
        cur->next = head->next;
        head->next = cur;

        cur = (StuNode*)malloc(sizeof (StuNode));
    }
    free(cur);
    return head;
}

void traverseStuList(StuNode * head) {
    printf("\t\t\tStudent Management System\n\n");
    printf("\t\t\t\t\t\t\t\tCopyLeft\n\n");

    printf("\tname\t\t\tsex\t\tage\t\tscore\n");
    head = head->next;
    while (head) {
        printf("\t%-10s\t\t%c\t\t%d\t\t%.2f\n",
               head->data.name,
               head->data.sex,
               head->data.age,
               head->data.score);
        head = head->next;
    }
    putchar(10);
}

void addListStu(StuNode * head) {
    StuNode * cur = (StuNode*)malloc(sizeof (StuNode));

    printf("name  :");
    scanf("%s", cur->data.name);

    getchar();
    printf("sex   :");
    scanf("%c", &cur->data.sex);

    printf("age   :");
    scanf("%d", &cur->data.age);

    printf("score :");
    scanf("%f", &cur->data.score);

    cur->next = head->next;
    head->next = cur;
}

StuNode * searchListStu(StuNode * head) {
    char name[30];
    printf("Please input your search name : ");
    scanf("%s", name);

    while (head) {
        if(!strcmp(head->data.name, name))
            break;
        head = head->next;
    }
    return head;
}

void deleteListStu(StuNode * head) {
    StuNode * pfind = searchListStu(head);
    if(NULL == pfind) {
        printf("The name is not in the system.\n");
        getchar();getchar();
        return;
    }
    while (head->next != pfind)
        head =head->next;
    head->next = pfind->next;
    free(pfind);
    return;
}

int lenListStu(StuNode * head) {
    int len = 0;
    head = head->next;
    while (head) {
        len++;
        head = head->next;
    }
    return len;
}

void sortListStu(StuNode * head) {
    int len = lenListStu(head);
    StuNode *prep, *p, *q;
    for (int i = 0; i < len - 1; i++) {
        prep = head;
        p = prep->next;
        q = p->next;
        for (int j = 0; j < len - i - 1; j++) {
            if(strcmp(p->data.name, q->data.name) > 0) {
                prep->next = q;
                p->next = q->next;
                q->next = p;

                prep = q;
                q = p->next;
                continue;
            }
            prep = prep->next;
            p = p->next;
            q = q->next;
        }
    }
}

void saveListStu2File(StuNode * head, char * filePath) {
    FILE * pf = fopen(filePath, "w+");
    if(NULL == pf)
        exit(-1);
    head = head->next;
    while (head) {
        fwrite((void*)&head->data, sizeof (Stu), 1, pf);
        head = head->next;
    }
    fclose(pf);
}

void destoryListStu(StuNode * head) {
    StuNode * t;
    while (head) {
        t = head;
        head = head->next;
        free(t);
    }
}
