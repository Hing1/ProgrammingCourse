# Description

Please modify class Queue's declaration and definition so as to finish the test from main.cpp��</br>
Attention: please use template you have learned in the class to finish this assignment and DON NOT add and modify any memeber function and member variable.</br>
Warning: DON NOT USE Queue in STL.</br></br>
The Queue's declaration with element type "int" is below:

```cpp
class Queue
{
public:
    Queue();

    Queue(const Queue &another);
    ~Queue();
    bool empty();
    int size();
    int front() const;
    int back() const;
    void push(int element);
    void pop();
    void swap(Queue &queue);

private:
    struct Node
    {
        int element;
        Node *next;
        Node(int ele, Node *n = NULL)
        {
            element = ele;
            next = n;
        }
    };
    Node *front_node;
    Node *back_node;
    int node_num;
};
```

## Hint

���������еĳ�Ա���������ʣ������ľ������ã���μ���[www.cplusplus.com�����queue](http://www.cplusplus.com/reference/queue/queue/?kw=queue)
