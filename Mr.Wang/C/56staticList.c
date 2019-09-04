#include <stdio.h>

typedef struct node {
    int data;
    struct node * next;
}MyNode;

void traverseList(MyNode * head) {
    while (head) {
        printf("%d\n", head->data);
        head = head->next;
    }
}

int main() {
    MyNode a, b, c, d, e;//此链表都在栈内存上

    MyNode * head;
    head = &a;

    a.data = 1;
    b.data = 2;
    c.data = 3;
    d.data = 4;
    e.data = 5;

    //所谓指向谁就是存了谁的地址
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;

    e.next = NULL;

    MyNode * pHead = head;

    while (pHead != NULL) {
        printf("%d\n", pHead->data);
        pHead = pHead->next;
    }
    void traverseList(head);
    return 0;
}
