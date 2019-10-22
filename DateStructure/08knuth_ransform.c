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

typedef struct _LCRSNode {
    struct _LCRSNode *child_left_;
    struct _LCRSNode *sibling_right_;
    int data_;
} LCRSNode;
void InTraversalLCRSTree(LCRSNode *r);
void DestoryLCRSTree(LCRSNode *r);

LCRSNode * KnuthTransform(TreeNode *src_root) {
    if (src_root != NULL) {
        LCRSNode *des_root = (LCRSNode *)malloc(sizeof(LCRSNode));
        des_root->data_ = src_root->data_;
        des_root->child_left_ = KnuthTransform(&(src_root->children_head->next_->tree_node_));
        if (src_root->parent_ == NULL) {
            des_root->sibling_right_ = NULL;
        } else {
            ListNode *head_src = src_root->parent_->children_head->next_;
            while (&(head_src->tree_node_) != src_root) {
                head_src= head_src->next_;
            }
            head_src = head_src->next_;
            des_root->sibling_right_ = KnuthTransform(&(head_src->tree_node_));
        }
//        InTraversalLCRSTree(des_root);
        return des_root;
    }
    return NULL;
}

void test1(void) {
	printf("\ntest1:\n");
	TreeNode *src_root = createTree(1);
    insertTree(src_root, 1, 11);
    insertTree(src_root, 1, 12);

    printf("Before Knuth transform:\n");
    PostTraversalTree(src_root);

    LCRSNode *des_root = KnuthTransform(src_root);

    printf("\nAfter Knuth transform:\n");                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  
    InTraversalLCRSTree(des_root);
	putchar(10);

    DestoryTree(src_root);
	DestoryLCRSTree(des_root);
}
void test2(void) {
	printf("\ntest2:\n");
	TreeNode *src_root = createTree(1);
    insertTree(src_root, 1, 11);
    insertTree(src_root, 1, 12);
    insertTree(src_root, 1, 13);
    insertTree(src_root, 1, 14);
    insertTree(src_root, 12, 121);
    insertTree(src_root, 12, 122);
    insertTree(src_root, 12, 123);

    printf("Before Knuth transform:\n");
    PostTraversalTree(src_root);

    LCRSNode *des_root = KnuthTransform(src_root);

    printf("\nAfter Knuth transform:\n");
    InTraversalLCRSTree(des_root); 
    putchar(10);
    
	DestoryTree(src_root);
    DestoryLCRSTree(des_root);
}
void test3(void) {
	printf("\ntest3:\n");
	TreeNode *src_root = createTree(1);
	insertTree(src_root, 1, 11);
    insertTree(src_root, 1, 12);
    insertTree(src_root, 1, 13);
    insertTree(src_root, 11, 111);
    insertTree(src_root, 11, 112);
    insertTree(src_root, 11, 113);
    insertTree(src_root, 12, 121);
    insertTree(src_root, 12, 122);
    insertTree(src_root, 13, 131);
    insertTree(src_root, 13, 132);
    insertTree(src_root, 122, 1221);
    insertTree(src_root, 122, 1222);
    
	printf("Before Knuth transform:\n");
    PostTraversalTree(src_root);

    LCRSNode *des_root = KnuthTransform(src_root);

    printf("\nAfter Knuth transform:\n");
    InTraversalLCRSTree(des_root);
	putchar(10);

	DestoryTree(src_root);
    DestoryLCRSTree(des_root);
}
int main() {
    test1();
    test2();
    test3();
    printf("\n\nHappy end !!! Hello World!\n");
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
