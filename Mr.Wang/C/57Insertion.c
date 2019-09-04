#include <stdio.h>

typedef struct node {
    int data;
    struct node * next;
}Node;

#if 0
Node * createList() {
    //尾插法
    Node * head = (Node*)malloc(sizeof (Node));
    if(NULL == head)
        exit(-1);
    head->next = NULL;

    Node * t = head;
    Node *cur;
    int nodeData;

    scanf("%d", &nodeData);
    while (nodeData) {
        cur = (Node*)malloc(sizeof (Node));
        if(NULL == head)
            exit(-1);
        cur->data = nodeData;
        t->next = cur;
        t = cur;
        scanf("%d", &nodeData);
    }
    t->next = NULL;
    return head;
}
#endif
#if 0
Node * createList() {
    //头插法,应用更多
    //让新来的节点有所指向，避免打断原有的指向
    Node * head = (Node*)malloc(sizeof (Node));
    if(NULL == head)
        exit(-1);
    head->next = NULL;
    Node * cur;

    int nodeDate;
    scanf("%d", &nodeDate);
    while (nodeDate) {
        cur = (Node*)malloc(sizeof (Node));
        if(NULL == head)
            exit(-1);
        cur->data = nodeDate;

        cur->next = head->next;
        head->next = cur;

        scanf("%d", &nodeDate);
    }
    return head;
}
#endif
#if 1
Node * createList() {
    //真正创建链表时，就是创建一个空链表
    Node * head = (Node*)malloc(sizeof(Node));
    if(NULL == head)
        exit(-1);
    head->next = NULL;
    return head;
}
#endif

void insertList(Node * head, int nodeDate) {
    //插入操作 本质就是头插法
    Node * cur = (Node*)malloc(sizeof (Node));
    if(NULL == head)
        exit(-1);
    cur->data = nodeDate;
    cur->next = head->next;
    head->next = cur;
}

void traverseList(Node * head) {
    head = head->next;
    while (head) {
        printf("%d\n", head->data);
        head = head->next;
    }
}

int main() {
    Node * head = createList();

    for (int i = 0; i < 10; i++) {
        insertList(head, i);
    }

    traverseList(head);
    return 0;
}
