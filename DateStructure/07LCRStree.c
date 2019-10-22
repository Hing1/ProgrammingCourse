#include <stdio.h>
#include <stdlib.h>

typedef struct _LCRSNode {
    struct _LCRSNode *child_left_;
    struct _LCRSNode *sibling_right_;
    int data_;
} LCRSNode;
void InTraversalLCRSTree(LCRSNode *r);
void DestoryLCRSTree(LCRSNode *r);

int main() {
    LCRSNode a,b,c,d,e,f,g,h;
    a.data_ = 1;
    b.data_ = 11;
    c.data_ = 12;
    d.data_ = 13;
    e.data_ = 14;
    f.data_ = 121;
    g.data_ = 122;
    h.data_ = 123;
    LCRSNode *root = &a;
    a.child_left_ = &b  ;a.sibling_right_ = NULL;
    b.child_left_ = NULL;b.sibling_right_ = &c;
    c.child_left_ = &f  ;c.sibling_right_ = &d;
    d.child_left_ = NULL;d.sibling_right_ = &e;
    e.child_left_ = NULL;e.sibling_right_ = NULL;
    f.child_left_ = NULL;f.sibling_right_ = &g;
    g.child_left_ = NULL;g.sibling_right_ = &h;
    h.child_left_ = NULL;h.sibling_right_ = NULL;

    InTraversalLCRSTree(root);
    putchar(10);

    printf("Hello World!\n");
    return 0;
}
void InTraversalLCRSTree(LCRSNode *r) {
    if (r) {
        InTraversalLCRSTree(r->child_left_);
        printf("%d ", r->data_);
        InTraversalLCRSTree(r->sibling_right_);
    }
}
void DestoryLCRSTree(LCRSNode *r) {
    if (r != NULL) {
        DestoryLCRSTree(r->child_left_);
        DestoryLCRSTree(r->sibling_right_);
        free(r);
        r = NULL;
    }
}
