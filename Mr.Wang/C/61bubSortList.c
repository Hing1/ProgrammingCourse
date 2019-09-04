#include <time.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node * next;
}Node;

Node * createList();
void insertList(Node * head, int nodeDate);
void traverseList(Node * head);
int lenList(Node * head);

void bubSortList(Node * head) {
    int len = lenList(head);
    Node * preP, * p, * q;
    for (int i = 0; i < len - 1; i++) {
        preP = head;
        p = head->next;
        q = p->next;
        for (int j = 0; j < len - i - 1; j++) {
            if(p->data > q->data) {
                preP->next = q;
                p->next = q->next;
                q->next = p;

                Node * temp = p;
                p = q;
                q = temp;
            }
            preP = preP->next;
            p = p->next;
            q = p->next;
        }
    }
}

#if 0
// 含有大量的数据交换，当结构体较大时，不推荐使用
void bubSortList(Node * head) {
    int len = lenList(head);
    head = head->next;
    Node * temp;
    for (int i = 0; i < len - 1; i++) {
        temp = head;
        for (int j = 0; j < len - i - 1; j++) {
            if(temp->data > temp->next->data) {
                temp->data ^= temp->next->data;
                temp->next->data ^= temp->data;
                temp->data ^= temp->next->data;
            }
            temp = temp->next;
        }
    }
}
#endif

int main() {
    Node * head = createList();

    srand(time(NULL));

    for (int i = 0; i < 10; i++) {
        insertList(head, rand() % 100);
    }
    traverseList(head);
    bubSortList (head);
    traverseList(head);
    return 0;
}

Node * createList() {
    Node * head = (Node*)malloc(sizeof(Node));
    if(NULL == head)
        exit(-1);
    head->next = NULL;
    return head;
}
void insertList(Node * head, int nodeDate) {
    Node * cur = (Node*)malloc(sizeof (Node));
    if(NULL == head)
        exit(-1);
    cur->data = nodeDate;
    cur->next = head->next;
    head->next = cur;
}
void traverseList(Node * head) {
    head = head->next;
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    putchar(10);
}
int lenList(Node * head) {
    int len = 0;
    head = head->next;
    while (head) {
        len++;
        head = head->next;
    }
    return len;
}
