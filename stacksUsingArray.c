#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100
struct lifo
{
    int arr[MAXSIZE];
    int top;
};
typedef struct lifo stack;
void createStack(stack *st)
{
    (st->top) = -1;
}
int isEmpty(stack *st)
{
    return (st->top == -1);
}

int isFull(stack *st)
{
    return st->top == (MAXSIZE - 1);
}
void push(stack *st, int data)
{
    if (!isFull(st))
        (st->top)++;
    st->arr[st->top] = data;
}
void pop(stack *st)
{
    if (!isEmpty(st))
    {
        st->top--;
    }
}
int top(stack *st)
{
    if (!isEmpty(st))
    {
        return st->arr[st->top];
    }
}
int size(stack *st)
{
    return (st->top + 1);
}
void printStack(stack *st)
{
    while (!isEmpty(st))
    {
        printf("%d ", top(st));
        pop(st);
    }
    printf("\n");
}
int main()
{

    stack st;
    createStack(&st);
    isEmpty(&st);
    push(&st, 5);
    push(&st, 4);
    push(&st, 3);
    push(&st, 2);
    top(&st);
    pop(&st);
    top(&st);
    printf("SIZE = %d\n", size(&st));
    printStack(&st);
}