#include <stdio.h>
#include <stdlib.h>

#define TYPE int

typedef struct _AvlNode {
    struct _AvlNode *left_child;
    struct _AvlNode *right_child;
    int height;
    TYPE data;
} AvlNode;
AvlNode * CreateAvlTree(TYPE data);
AvlNode * InsertAvlTree(AvlNode *r, TYPE data);
void MidOrderTraversal(AvlNode *r);
void DestoryAvlTree(AvlNode *r);

AvlNode * singleRotateWithRight(AvlNode *r);
AvlNode * singleRotateWithLeft(AvlNode *r);
AvlNode * doubleRotateWithLeft(AvlNode *r);
AvlNode * doubleRotateWithRight(AvlNode *r);
int Height(AvlNode *r);

int main() {
	AvlNode *root = CreateAvlTree(3);
    root = InsertAvlTree(root, 2);
    root = InsertAvlTree(root, 1);
    root = InsertAvlTree(root, 4);
    root = InsertAvlTree(root, 5);
    root = InsertAvlTree(root, 6);
    MidOrderTraversal(root);
    DestoryAvlTree(root);
    printf("\nHello world end!\n\n");
    return 0;
}

int Max(int a, int b) {
    if (a > b)
        return a;
    else
        return b;
}
AvlNode * singleRotateWithRight(AvlNode *r) {
    AvlNode *temp = r->left_child;
    r->left_child = temp->right_child;
    temp->right_child = r;
    r->height = Max(Height(r->left_child), Height(r->right_child)) + 1;
    temp->height = Max(Height(temp->left_child), Height(temp->right_child)) + 1;
    return temp;
}
AvlNode * singleRotateWithLeft(AvlNode *r) {
    AvlNode *temp = r->right_child;
    r->right_child = temp->left_child;
    temp->left_child = r;
    r->height = Max(Height(r->left_child), Height(r->right_child)) + 1;
    temp->height = Max(Height(temp->left_child), Height(temp->right_child)) + 1;
    return temp;
}
AvlNode * doubleRotateWithLeft(AvlNode *r) {
    r->left_child = singleRotateWithLeft(r->left_child);
    r = singleRotateWithRight(r);
    return r;
}
AvlNode * doubleRotateWithRight(AvlNode *r) {
    r->right_child = singleRotateWithRight(r->right_child);
    r = singleRotateWithLeft(r);
    return r;
}
AvlNode * InsertAvlTree(AvlNode *r, TYPE data) {
    if (NULL == r)
        return CreateAvlTree(data);
    if (data < r->data) {
        r->left_child = InsertAvlTree(r->left_child, data);
        if (Height(r->left_child) - Height(r->right_child) == 2) {
            if (data < r->left_child->data)
                r = singleRotateWithRight(r);
            else
                r = doubleRotateWithLeft(r);
        }
    } else if (data > r->data) {
        r->right_child = InsertAvlTree(r->right_child, data);
        if (Height(r->right_child) - Height(r->left_child) == 2) {
            if (data > r->right_child->data)
                r = singleRotateWithLeft(r);
            else
                r = doubleRotateWithRight(r);
        }
    }
    r->height = Max(Height(r->left_child), Height(r->right_child)) + 1;
    return r;
}
AvlNode * CreateAvlTree(TYPE data) {
    AvlNode *r = (AvlNode *)malloc(sizeof(AvlNode));
    r->data = data;
    r->left_child = NULL;
    r->right_child = NULL;
    r->height = 0;
    return r;
}
void PrintNodeData(AvlNode *r) {
    if (r == NULL)
        printf("NULL");
    else
        printf("%4d", r->data);
}
void PrintNode(AvlNode *r) {
    printf("%d --- ", r->data);
    printf("left child: ");
    PrintNodeData(r->left_child);
    printf(", left child: ");
    PrintNodeData(r->right_child);
    putchar(10);
}
void MidOrderTraversal(AvlNode *r) {
    if (NULL == r)
        return ;
    MidOrderTraversal(r->left_child);
    PrintNode(r);
    MidOrderTraversal(r->right_child);
}
void DestoryAvlTree(AvlNode *r) {
    if (NULL == r)
        return ;
    DestoryAvlTree(r->left_child);
    DestoryAvlTree(r->right_child);
    free(r);
    return ;
}
int Height(AvlNode *r) {
    if (NULL == r)
        return -1;
    else
        return r->height;
}
