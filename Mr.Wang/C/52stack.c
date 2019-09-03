#include <stdio.h>

#define MAX 128

typedef struct _MyStack {
    char mem[MAX];
    int top;
} MyStack;

int isFull(MyStack * ps);
int isEmpty(MyStack * ps);
void push(MyStack * ps, char ch);
char pop(MyStack * ps);

int main() {
    MyStack s = {{0}, 0};

    for (char ch = 'a'; ch <= 'z'; ch++) {
        if(!isFull(&s))
            push(&s, ch);
    }
    while (!isEmpty(&s)) {
        putchar(pop(&s));
    }
    return 0;
}
int isFull(MyStack * ps) {
    return ps->top == MAX;
}
int isEmpty(MyStack * ps) {
    return ps->top == 0;
}
void push(MyStack * ps, char ch) {
    ps->mem[ps->top++] = ch;
}
char pop(MyStack * ps) {
    return ps->mem[--ps->top];
}
