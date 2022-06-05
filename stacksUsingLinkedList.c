#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct lifo
{
    int data;
    struct lifo *next;
};

typedef struct lifo stack;

stack *createNode()
{
    stack *n = NULL;
    n = (stack *)malloc(sizeof(stack));
    n->next = NULL;
    return n;
}
void push(stack **head, int data)
{
    stack *tmp = createNode();
    tmp->data = data;
    if (*head == NULL)
    {
        *head = tmp;
        return;
    }
    stack *tmp1 = createNode();
    tmp1 = *head;
    *head = tmp;
    tmp->next = tmp1;
}
void pop(stack **head)
{
    if (*head != NULL)
    {
        stack *tmp = createNode();
        tmp = *head;
        tmp = tmp->next;
        *head = tmp;
    }
}
void printStack(stack *st)
{
    while (st != NULL)
    {
        printf("%d ", st->data);
        st = st->next;
    }
}
int main()
{
    stack **head = NULL;
    head = malloc(sizeof(stack));
    push(head, 4);
    push(head, 5);
    push(head, 6);
    push(head, 7);
    pop(head);
    printStack(*head);
}