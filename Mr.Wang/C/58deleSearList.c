#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node * next;
}Node;

Node * createList();
void insertList(Node * head, int nodeDate);
void traverseList(Node * head);

int lenList(Node * head) {
    int len = 0;
    head = head->next;
    while (head) {
        len++;
        head = head->next;
    }
    return len;
}
Node *searchList(Node * head, int findDate) {
    head = head->next;
    while (head) {
        if(head->data == findDate)
            break;
        head = head->next;
    }
    //ÕÒ²»µ½·µ»ØNULL
    return head;
}
void deleteNodeOfList(Node * head, Node * pFind) {
    while (head->next != pFind) {
        head = head->next;
    }
    head->next = pFind->next;
    free(pFind);
    pFind = NULL;
}

int main() {
    Node * head = createList();
    for (int i = 0; i < 10; i++) {
        insertList(head, i);
    }
    traverseList(head);

    printf("Len of List %d\n", lenList(head));

    Node * pFind = searchList(head, 9);
    if(pFind) {
        printf("Finded data in list is %d\n", pFind->data);
        pFind->data = 100;
        traverseList(head);
        deleteNodeOfList(head, pFind);
    }
    else
        printf("None!\n");
//    traverseList(head);

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
        printf("%d\n", head->data);
        head = head->next;
    }
}
