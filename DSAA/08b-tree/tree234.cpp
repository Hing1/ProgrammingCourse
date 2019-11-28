#include "tree234.h"

#include <iostream>

using std::cout;
using std::endl;

int Tree234::find(long key) {
    Node *curNode = root;
    int childNumber = 0;
    while (1) {
        if ((childNumber = curNode->findItem(key)) != -1)
            return childNumber;
        else if (curNode->isLeaf())
            return -1;
        else
            curNode = getNextChild(curNode, key);
    }
}
void Tree234::insert(long dValue) {
    cout << "a" << endl;
    Node *curNode = root;
    cout << "b" << endl;
    long tempItem = dValue;
    cout << "c" << endl;
    while (1) {
        cout << "d" << endl;
        if (curNode->isFull()) {
            cout << "e" << endl;
            split(curNode);
            curNode = curNode->getParent();
            curNode = getNextChild(curNode, dValue);
        } else if (curNode->isLeaf()) {
            cout << "f" << endl;
            break;
        } else {
            cout << "g" << endl;
            curNode = getNextChild(curNode, dValue);
        }
    }
    cout << "z" << endl;
    curNode->insertItem(tempItem);
}
void Tree234::split(Node *thisNode) {
    long itemC = thisNode->removeItem();
    long itemB = thisNode->removeItem();
    Node *parent;
    Node *child2 = thisNode->disconnectChild(2);
    Node *child3 = thisNode->disconnectChild(3);

    Node *newRight = new Node();
    if (thisNode == root) {
        root = new Node();
        parent = root;
        root->connectChild(0, thisNode);
    } else {
        parent = thisNode->getParent();
    }
    int itemIndex = parent->insertItem(itemB);
    int n = parent->getNUMItems();
    for (int i = n - 1; i > itemIndex; --i) {
        Node *temp = parent->disconnectChild(i);
        parent->connectChild(i + 1, temp);
    }
    parent->connectChild(itemIndex + 1, newRight);
    newRight->insertItem(itemC);
    newRight->connectChild(0, child2);
    newRight->connectChild(1, child3);
}
Node * Tree234::getNextChild(Node *theNode, long theValue) {
    int numItems = theNode->getNUMItems();
    int i = 0;
    for (; i < numItems; ++i) {
        if (theValue < theNode->getItem(i))
            return theNode->getChild(i);
    }
    return theNode->getChild(i);
}
void Tree234::displauTree() {
    recDisplayTree(root, 0, 0);
}
void Tree234::recDisplayTree(Node *thisNode, int level, int childNumber) {
    cout << "level = " << level << " ";
    cout << "child = " << childNumber << " ";
    thisNode->displayNode();

    int numItems = thisNode->getNUMItems();
    Node *nextNode;
    for (int i = 0; i <= numItems; ++i) {
        nextNode = thisNode->getChild(i);
        if (nextNode != nullptr)
            recDisplayTree(nextNode, level + 1, i);
        else
            return ;
    }
}
