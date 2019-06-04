#include <iostream>
using namespace std;

template <typename T>
class Queue
{
public:
    Queue();
    Queue(const Queue<T> &another);
    ~Queue();
    bool empty();
    int size();
    T front() const;
    T back() const;
    void push(T element);
    void pop();
    void swap(Queue<T> &queue);

private:
    struct Node
    {
        T element;
        Node *next;
        Node(T ele, Node *n = NULL)
        {
            element = ele;
            next = n;
        }
    };
    Node *front_node;
    Node *back_node;
    int node_num;
};

template <typename T>
Queue<T>::Queue()
{
    front_node = back_node = NULL;
    node_num = 0;
}

template <typename T>
Queue<T>::Queue(const Queue<T> &another)
{
    if (this == &another)
        return;
    front_node = back_node = NULL;
    node_num = 0;
    Node *temp = another.front_node;
    while (temp != NULL)
    {
        push(temp->element);
        temp = temp->next;
    }
}

template <typename T>
Queue<T>::~Queue()
{
    while (!empty())
    {
        pop();
    }
}

template <typename T>
bool Queue<T>::empty()
{
    return node_num == 0;
}

template <typename T>
int Queue<T>::size()
{
    return node_num;
}

template <typename T>
T Queue<T>::front() const
{
    return front_node->element;
}

template <typename T>
T Queue<T>::back() const
{
    return back_node->element;
}

template <typename T>
void Queue<T>::push(T element)
{
    if (front_node == NULL)
    {
        front_node = back_node = new Node(element);
    }
    else
    {
        back_node->next = new Node(element);
        back_node = back_node->next;
    }
    node_num++;
}

template <typename T>
void Queue<T>::pop()
{
    if (empty())
        return;
    if (size() == 1)
    {
        delete front_node;
        front_node = back_node = NULL;
    }
    else
    {
        Node *temp = front_node;
        front_node = front_node->next;
        delete temp;
    }
    node_num--;
}

template <typename T>
void Queue<T>::swap(Queue<T> &queue)
{
    int old_size = size();
    while (!empty())
    {
        queue.push(front());
        pop();
    }
    while (queue.size() > old_size)
    {
        push(queue.front());
        queue.pop();
    }
}