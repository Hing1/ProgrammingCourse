#include "node.h"

#include <iostream>

using std::cout;
using std::endl;

Node::Node() {
    cout << "Node()" << endl;
    numItems = 0;
    cout << "num" << numItems << endl;
}

Node * Node::getChild(int childNum) {
    return childArray[childNum];
}
Node * Node::getParent() {
    return parent;
}
Node * Node::disconnectChild(int childNum) {
    Node *temp = childArray[childNum];
    childArray[childNum] = nullptr;
    return temp;
}
bool Node::isLeaf() {
    return (childArray[0] == nullptr);
}
bool Node::isFull() {
    cout << "bool Node::isFull()" << endl;
    cout << "order" << ORDER << endl;
    cout << "num" << numItems << endl;

    if (numItems == ORDER - 1) {
        cout << "bool Node::isFull()" << endl;
        return true;
    } else {
        cout << "fffffff" << endl;
        return false;
    }
}
void Node::connectChild(int childNum, Node *child) {
    childArray[childNum] = child;
    if (child != nullptr)
        child->parent = this;
}
void Node::displayNode() {
    for (int i = 0; i < numItems; ++i) {
        cout << itemArray[i] << endl;
    }
    cout << "/" << endl;
}
int Node::getNUMItems() {
    return numItems;
}
int Node::findItem(long key) {
    for (int i = 0; i < ORDER - 1; ++i) {
        if (itemArray[i] == nullptr)
            break;
        else if (*(itemArray[i]) == key)
            return i;
    }
    return -1;
}
int Node::insertItem(long newItem) {
    ++numItems;
    long newKey = newItem;
    for (int i = ORDER - 2; i >= 0; --i) {
        if (itemArray[i] == nullptr) {
            continue;
        } else {
            long itsKey = *(itemArray[i]);
            if (newKey < itsKey) {
                itemArray[i + 1] = itemArray[i];
            } else {
                itemArray[i + 1] = &newItem;
                return (i + 1);
            }
        }
    }
    itemArray[0] = &newItem;
    return 0;
}
long Node::getItem(int index) {
    return *(itemArray[index]);
}
long Node::removeItem() {
    long *temp = itemArray[numItems - 1];
    itemArray[numItems - 1] = nullptr;
    --numItems;
    return *temp;
}
