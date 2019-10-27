#include "data-block-list.h"
#include <stdio.h>

#define M 5
#define TYPE int

typedef struct _BPlusTreeNode {
    int key[M];
    int key_count;
    struct _BPlusTreeNode *child[M];
    DataBlockNode *data_head[M];
} BPlusTreeNode;

BPlusTreeNode * createBPlusTree(int key);
void insertBPlusTree(BPlusTreeNode *root, int key);
void eraseBPlusTree(BPlusTreeNode *root, int key);
void traversalBPlusTree(BPlusTreeNode *root);
void destoryBPlusTree(BPlusTreeNode *root);

int main() {
    DataBlockNode *data_head1 = createDataBlockList();
    insertDataBlockList(data_head1, 1);
    insertDataBlockList(data_head1, 2);
    insertDataBlockList(data_head1, 3);
    DataBlockNode *data_head2 = createDataBlockList();
    insertDataBlockList(data_head2, 4);
    insertDataBlockList(data_head2, 5);
    insertDataBlockList(data_head2, 6);

    BPlusTreeNode a;
    for (int i = 0; i < M; ++i) {
        a.data_head[i] = NULL;
    }
    for (int i = 0; i < M; ++i) {
        a.child[i] = NULL;
    }
    a.key[0] = 1;
    a.key[1] = 4;
    a.key_count = 2;
    a.data_head[0] = data_head1;
    a.data_head[1] = data_head2;

    traversalBPlusTree(&a);
    putchar(10);
    printf("Hello World!\n");
    return 0;
}

BPlusTreeNode * createBPlusTree(int key) {
    BPlusTreeNode *root = (BPlusTreeNode *)malloc(sizeof(BPlusTreeNode));
    if (NULL == root)
        return NULL;
    root->key[0] = key;
    root->key_count = 1;
    root->data_head[0] = createDataBlockList();
    insertDataBlockList(root->data_head[0], key);
    for (int i = 1; i < M; ++i) {
        root->key[i] = -1;
    }
    for (int i = 0; i < M; ++i) {
        root->child[i] = NULL;
    }
    for (int i = 1; i < M; ++i) {
        root->data_head[i] = NULL;
    }
    return root;
}
//BPlusTreeNode * insertBPlusTree(BPlusTreeNode *root, int key);
void insertBPlusTree(BPlusTreeNode *root, int key) {
    if (NULL == root) {
        root = createBPlusTree(key);
        return ;
    }
}
void eraseBPlusTree(BPlusTreeNode *root, int key);
int isLeaf(BPlusTreeNode *root) {
    for (int i = 0; i < root->key_count; ++i) {
        if (root->data_head[i] != NULL)
            return 1;
    }
    return 0;
}
void traversalBPlusTree(BPlusTreeNode *root) {
    if (NULL == root)
        return ;
    if (isLeaf(root)) {
        for (int i = 0; i < root->key_count; ++i) {
            traversalDataBlockList(root->data_head[i]);
        }
    } else {
        for (int i = 0; i < root->key_count; ++i) {
            traversalBPlusTree(root->child[i]);
        }
    }
    return ;
}
void destoryBPlusTree(BPlusTreeNode *root) {
    if (NULL == root)
        return ;
    if (isLeaf(root)) {
        for (int i = 0; i < root->key_count; ++i) {
            destoryDataBlockList(root->data_head[i]);
        }
    } else {
        for (int i = 0; i < root->key_count; ++i) {
            destoryBPlusTree(root->child[i]);
        }
    }
    free(root);
    return ;
}

