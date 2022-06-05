#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100
struct lifo
{
    int arr[MAXSIZE];
    int top;
};
typedef struct lifo stack;
stack *createStack()
{
    stack *n = NULL;
    n = malloc(sizeof(stack));
    n->top = -1;
    return n;
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
    {
        (st->top)++;
        st->arr[st->top] = data;
    }
}
void pop(stack *st)
{
    if (!isEmpty(st))
    {
        st->top--;
    }
}
int size(stack *st)
{
    return (st->top + 1);
}
int top(stack *st)
{
    if (!isEmpty(st))
    {
        return st->arr[st->top];
    }
}
void printStack(stack *st)
{
    int size = st->top;
    for (int i = 0; i <= size; i++)
    {
        printf("%d ", st->arr[i]);
    }
    printf("\n");
}

int main()
{
    int a[] = {200, 180, 160, 170, 160, 175, 185};
    int answer[7];
    stack *st = createStack();
    push(st, 0);
    answer[0] = 1;
    for (int i = 1; i < 7; i++)
    {
        while (!isEmpty(st) && a[st->arr[st->top]] < a[i])
        {
            pop(st);
        }
        answer[i] = isEmpty(st) ? (i + 1) : (i - top(st));
        push(st, i);
    }
    for (int i = 0; i < 7; i++)
    {
        printf("%d ", answer[i]);
    }
}