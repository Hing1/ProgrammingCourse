#ifndef TREE234_H
#define TREE234_H

#include "node.h"

class Tree234
{
public:
    int find(long key);
    void insert(long dValue);
    void split(Node *thisNode);
    Node * getNextChild(Node *theNode, long theValue);
    void displauTree();
    void recDisplayTree(Node *thisNode, int level, int childNumber);
//    Tree234();
private:
    Node *root;
};

#endif // TREE234_H
