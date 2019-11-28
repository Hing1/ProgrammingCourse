#include <stdio.h>
#include <stdlib.h>

#define M 5
#define L 3

typedef struct _LeafBlockNode {
    int data;
    struct _LeafBlockNode *next;
} LeafBlockNode;

void traversalLeafBlockList(LeafBlockNode *head);
LeafBlockNode * createLeafBlockList(void);
LeafBlockNode * findLeafBlockList(LeafBlockNode *head, int data);
int insertLeafBlockList(LeafBlockNode *head, int data);
int eraseLeafBlockList(LeafBlockNode *head, int data);
void destoryLeafBlockList(LeafBlockNode *head);

typedef struct _InternalBlock InternalBlock;
typedef struct _LeafBlock {
    LeafBlockNode *head;
    int count;
    InternalBlock *parent;
} LeafBlock;

void traversalLeafBlock(LeafBlock *root);
LeafBlock * createLeafBlock(InternalBlock *parent);
LeafBlockNode * findLeafBlock(LeafBlock *root, int data);
int insertLeafBlock(LeafBlock *root, int data);
int eraseLeafBlock(LeafBlock *root, int data);
void destoryLeafBlock(LeafBlock *root);
