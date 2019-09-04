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
    MyNode a, b, c, d, e;//��������ջ�ڴ���

    MyNode * head;
    head = &a;

    a.data = 1;
    b.data = 2;
    c.data = 3;
    d.data = 4;
    e.data = 5;

    //��νָ��˭���Ǵ���˭�ĵ�ַ
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
