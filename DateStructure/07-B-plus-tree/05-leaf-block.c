#include "leaf-block.h"

void traversalLeafBlockList(LeafBlockNode *head) {
    if (NULL == head)
        return ;
    while (head->next != NULL) {
        printf("%d ", head->next->data);
        head = head->next;
    }
}
LeafBlockNode * createLeafBlockList(void) {
    LeafBlockNode *head = (LeafBlockNode *)malloc(sizeof(LeafBlockNode));
    if (NULL == head)
        return NULL;
    head->next = NULL;
    return head;
}
LeafBlockNode * findLeafBlockList(LeafBlockNode *head, int data) {
    if (NULL == head)
        return NULL;
    while (head->next != NULL) {
        if (head->next->data == data)
            return head->next;
        head = head->next;
    }
    return NULL;
}
int insertLeafBlockList(LeafBlockNode *head, int data) {
    if (NULL == head)
        return 0;
    while ((head->next != NULL) && (data >= head->next->data)) {
        if (data == head->next->data)
            return 0;
        head = head->next;
    }
    LeafBlockNode *temp = (LeafBlockNode *)malloc(sizeof(LeafBlockNode));
    temp->data = data;
    temp->next = head->next;
    head->next = temp;
    return 1;
}
int eraseLeafBlockList(LeafBlockNode *head, int data) {
    if (NULL == head)
        return 0;
    while (head->next != NULL) {
        if (head->next->data == data) {
            LeafBlockNode *temp = head->next;
            head->next = head->next->next;
            free(temp);
            return 1;
        }
        head = head->next;
    }
    return 0;
}
void destoryLeafBlockList(LeafBlockNode *head) {
    if (NULL == head)
        return ;
    LeafBlockNode *temp = NULL;
    while (head->next != NULL) {
        temp = head->next;
        head->next = head->next->next;
        free(temp);
    }
    free(head);
}
void traversalLeafBlock(LeafBlock *root) {
    if (NULL == root)
        return ;
    traversalLeafBlockList(root->head);
}
LeafBlock * createLeafBlock(InternalBlock *parent) {
    LeafBlock *root = (LeafBlock *)malloc(sizeof(LeafBlock));
    root->head = createLeafBlockList();
    root->count = 0;
    root->parent = parent;
    return root;
}
LeafBlockNode * findLeafBlock(LeafBlock *root, int data) {
    if (NULL == root)
        return NULL;
    return findLeafBlockList(root->head, data);
}
int insertLeafBlock(LeafBlock *root, int data) {
    if (NULL == root)
        return 0;
    return insertLeafBlockList(root->head, data);
}
int eraseLeafBlock(LeafBlock *root, int data) {
    if (NULL == root)
        return 0;
    return eraseLeafBlockList(root->head, data);
}
void destoryLeafBlock(LeafBlock *root) {
    if (NULL == root)
        return;
    destoryLeafBlockList(root->head);
    free(root);
}
