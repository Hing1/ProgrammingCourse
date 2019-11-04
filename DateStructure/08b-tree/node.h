#ifndef NODE_H
#define NODE_H

//#include "dataitem.h"

#define ORDER 4

class Node {
public:
    Node ();
    Node * getChild(int childNum);
    Node * getParent();
    Node * disconnectChild(int childNum);
    bool isLeaf();
    bool isFull();
    void connectChild(int childNum, Node *child);
    void displayNode();
    int getNUMItems();
    int findItem(long key);
    int insertItem(long newItem);
    long getItem(int index);
    long removeItem();

private:
    int numItems;
    Node *parent;
    Node *childArray[ORDER];
    long *itemArray[ORDER - 1];
};

#endif // NODE_H
