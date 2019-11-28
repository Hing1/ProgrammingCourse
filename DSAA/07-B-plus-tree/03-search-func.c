#include "data-block-list.h"
#include <stdio.h>

#define M 5
#define TYPE int

typedef struct _BPlusTreeNode {
    int key[M];
    int key_count;
    void *child[M];
    int isLeaf;
} BPlusTreeNode;

BPlusTreeNode * createBPlusTree(int key);
DataBlockNode * searchBPlusTree(BPlusTreeNode *root, int key);
BPlusTreeNode * insertBPlusTree(BPlusTreeNode *root, int key);
BPlusTreeNode * eraseBPlusTree(BPlusTreeNode *root, int key);
BPlusTreeNode * destoryBPlusTree(BPlusTreeNode *root);
void traversalBPlusTree(BPlusTreeNode *root);

int test1() {
    DataBlockNode *data_head1 = createDataBlockList();
    insertDataBlockList(data_head1, 1);
    insertDataBlockList(data_head1, 2);
    insertDataBlockList(data_head1, 3);
    DataBlockNode *data_head2 = createDataBlockList();
    insertDataBlockList(data_head2, 4);
    insertDataBlockList(data_head2, 5);
    insertDataBlockList(data_head2, 6);

    BPlusTreeNode a;
//    for (int i = 0; i < M; ++i) {
//        a.data_head[i] = NULL;
//    }
    for (int i = 0; i < M; ++i) {
        a.child[i] = NULL;
    }
    a.key[0] = 1;
    a.key[1] = 4;
    a.key_count = 2;
    a.child[0] = data_head1;
    a.child[1] = data_head2;
    a.isLeaf = 1;

    traversalBPlusTree(&a);
    putchar(10);

    DataBlockNode *t = NULL;
    t = searchBPlusTree(&a, 6);
    if (t != NULL)
        printf("Find  %d\n", t->data);
    else
        printf("None find\n");
    printf("Hello World!\n");
    return 0;
}
int main() {
//    BPlusTreeNode *root = createBPlusTree(1);
//    traversalBPlusTree(root);
//    root = destoryBPlusTree(root);
    BPlusTreeNode *root2 = NULL;
    insertBPlusTree(root2,5);
    traversalBPlusTree(root2);
    root2 = destoryBPlusTree(root2);
    printf("Hello End\n");
}

BPlusTreeNode * createBPlusTree(int key) {
    BPlusTreeNode *root = (BPlusTreeNode *)malloc(sizeof(BPlusTreeNode));
    if (NULL == root)
        return NULL;
    root->key[0] = key; ///////////////////////////////////////////////////////////////////
    root->key_count = 1;
    root->isLeaf = 1;
    root->child[0] = createDataBlockList();
    insertDataBlockList(root->child[0], key);
    for (int i = 1; i < M; ++i) {
        root->key[i] = -1;
    }
    for (int i = 1; i < M; ++i) {
        root->child[i] = NULL;
    }
    return root;
}

DataBlockNode * searchBPlusTree(BPlusTreeNode *root, int key) {
    if (NULL == root)
            return NULL;
    if (!root->isLeaf) {
        if (key < root->key[1]) {
            return searchBPlusTree(root->child[0], key);
        } else if (key > root->key[M - 1]) {
            return searchBPlusTree(root->child[M - 1], key);
        } else {
            for (int i = 1; i < M - 2; ++i) {
                if (root->key[i] <= key && key < root->key[i - 1])
                    return searchBPlusTree(root->child[i], key);
            }
            return NULL;
        }
    } else {
        if (key < root->key[1]) {
            return searchDateBlockList(root->child[0], key);
        } else if (key > root->key[root->key_count - 1]) {
            return searchDateBlockList(root->child[root->key_count - 1], key);
        } else {
            for (int i = 1; i < M - 2; ++i) {
                if (root->key[i] <= key && key < root->key[i - 1])
                    return searchDateBlockList(root->child[i], key);
            }
            return NULL;
        }
    }
}
//BPlusTreeNode * insertBPlusTree(BPlusTreeNode *root, int key);
BPlusTreeNode * insertBPlusTree(BPlusTreeNode *root, int key) {
    if (NULL == root) {
        root = createBPlusTree(key);
        return root;
    }
}
BPlusTreeNode * eraseBPlusTree(BPlusTreeNode *root, int key) {

}
BPlusTreeNode * destoryBPlusTree(BPlusTreeNode *root) {
    if (NULL == root)
        return NULL;
    if (root->isLeaf) {
        for (int i = 0; i < root->key_count; ++i) {
            destoryDataBlockList(root->child[i]);
        }
    } else {
        for (int i = 0; i < root->key_count; ++i) {
            destoryBPlusTree(root->child[i]);
        }
    }
    free(root);
    root = NULL;
    return root;
}
void traversalBPlusTree(BPlusTreeNode *root) {
    if (NULL == root)
        return ;
    if (root->isLeaf) {
        for (int i = 0; i < root->key_count; ++i) {
            traversalDataBlockList(root->child[i]);
        }
    } else {
        for (int i = 0; i < root->key_count; ++i) {
            traversalBPlusTree(root->child[i]);
        }
    }
    return ;
}

