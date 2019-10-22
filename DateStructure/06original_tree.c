#include <stdio.h>
#include <stdlib.h>

typedef struct _ListNode ListNode;
typedef struct _TreeNode {
    int data_;
    struct _TreeNode *parent_;
    ListNode *children_head;
} TreeNode;
TreeNode * createTree(int data);
TreeNode * searchTree(TreeNode *root, int data);
int insertTree(TreeNode *root, int parent_data, int data);
void PostTraversalTree(TreeNode *r);
void DestoryTree(TreeNode *r);

typedef struct _ListNode {
    TreeNode tree_node_;
    ListNode *next_;
} ListNode;
ListNode * createList(void);
void insertList(ListNode *head, TreeNode nodeDate);
void traverseList(ListNode *head);
void destoryList(ListNode *head);

int main() {
    TreeNode *root = createTree(1);
    insertTree(root, 1, 11);
    insertTree(root, 1, 12);
    insertTree(root, 1, 13);
    insertTree(root, 1, 14);
    insertTree(root, 12, 121);
    insertTree(root, 12, 122);
    insertTree(root, 12, 123);

    PostTraversalTree(root);
    putchar(10);

    DestoryTree(root);
    printf("hello\n");
    return 0;
}

TreeNode * createTree(int root_data) {
    TreeNode *root = (TreeNode *)malloc(sizeof(TreeNode));
    root->data_ = root_data;
    root->parent_ = NULL;
    root->children_head = createList();
    return root;
}
TreeNode * searchTree(TreeNode *root, int data) {
    if (root != NULL) {
        if (root->data_ == data)
            return root;
        else {
            TreeNode *des = NULL;
            ListNode *head = root->children_head;
            head = head->next_;
            while (head) {
                des = searchTree(&(head->tree_node_), data);
                if (des != NULL)
                    break;
                head = head->next_;
            }
            return des;
        }
    }
    return NULL;
}
int insertTree(TreeNode *root, int parent_data, int data) {
    if (root) {
        TreeNode *parent = searchTree(root, parent_data);
        if (parent != NULL) {
            TreeNode *temp = (TreeNode *)malloc(sizeof(TreeNode));
            temp->data_ = data;
            temp->parent_ = parent;
            temp->children_head = createList();
            insertList(parent->children_head, *temp);
            return 1;
        }
        else {
            printf("parent data error!\n");
            return 0;
        }
    }
    return 0;
}
void PostTraversalTree(TreeNode *root) {
    if (root != NULL) {
        ListNode *head = root->children_head;
        head = head->next_;
        while (head) {
            PostTraversalTree(&(head->tree_node_));
            head = head->next_;
        }
        printf("%d ", root->data_);
    }
}
void DestoryTree(TreeNode *root) {
    if (root != NULL) {
        ListNode *head = root->children_head;
        head = head->next_;
        while (head) {
            ListNode *temp = head;
            head = head->next_;
            free(temp);
        }
        free(root);
    }
}

ListNode * createList() {
    ListNode *head = (ListNode*)malloc(sizeof(ListNode));
    if(NULL == head)
        exit(-1);
    head->next_ = NULL;
    return head;
}
void insertList(ListNode *head, TreeNode tree_node) {
    ListNode *temp = (ListNode *)malloc(sizeof(ListNode));
    if(NULL == temp)
        exit(-1);
    temp->tree_node_ = tree_node;

    while (head->next_) {
        head = head->next_;
    }
    temp->next_ = head->next_;
    head->next_ = temp;
}
void destoryList(ListNode *head) {
    while (head->next_ != NULL) {
        ListNode *temp = head->next_;
        head->next_ = head->next_->next_;
        free(temp);
    }
    free(head);
}

