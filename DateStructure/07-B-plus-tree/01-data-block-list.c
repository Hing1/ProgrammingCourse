#include <stdio.h>
#include <stdlib.h>

#define TYPE int

typedef struct _DataBlockNode {
    TYPE data;
    struct _DataBlockNode *next;
} DataBlockNode;

DataBlockNode * createDataBlockList(void);
void insertDataBlockList(DataBlockNode *head, TYPE data);
void eraseDataBlockList(DataBlockNode *head, TYPE data);
void traversalDataBlockList(DataBlockNode *head);
void destoryDataBlockList(DataBlockNode *head);


int main() {
    DataBlockNode *head = createDataBlockList();
    insertDataBlockList(head, 1);
    insertDataBlockList(head, 2);
    insertDataBlockList(head, 3);
    insertDataBlockList(head, 8);
    insertDataBlockList(head, 6);
    traversalDataBlockList(head);
    putchar(10);
    eraseDataBlockList(head, 2);
    traversalDataBlockList(head);
    putchar(10);
    destoryDataBlockList(head);
    printf("Hello World!\n");
    return 0;
}

DataBlockNode * createDataBlockList(void) {
    DataBlockNode *head = (DataBlockNode *)malloc(sizeof(DataBlockNode));
    if (NULL == head)
        return NULL;
    head->next = NULL;
    return head;
}
void insertDataBlockList(DataBlockNode *head, TYPE data) {
    if (NULL == head)
        return ;
    DataBlockNode *temp = (DataBlockNode *)malloc(sizeof(DataBlockNode));
    temp->data = data;
    while ((head->next != NULL) && (head->next->data < data)){
        head = head->next;
    }
    temp->next = head->next;
    head->next = temp;
}
void eraseDataBlockList(DataBlockNode *head, TYPE data) {
    if (NULL == head)
        return ;
    DataBlockNode *temp = NULL;
    while (head->next != NULL) {
        if (head->next->data == data) {
            temp = head->next;
            head->next = head->next->next;
            free(temp);
        }
        head = head->next;
    }
}
void traversalDataBlockList(DataBlockNode *head) {
    if (NULL == head)
        return ;
    while (head->next != NULL) {
        printf("%d ", head->next->data);
        head = head->next;
    }
}
void destoryDataBlockList(DataBlockNode *head) {
    if (NULL == head)
        return ;
    DataBlockNode *temp = NULL;
    while (head->next != NULL) {
        temp = head->next;
        head->next = head->next->next;
        free(temp);
    }
    free(head);
}
