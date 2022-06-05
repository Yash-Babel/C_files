#include <stdio.h>
#include <stdlib.h>

typedef struct lList node;
struct lList
{
    int data;
    struct lList *next;
};
node *createNode()
{
    node *n = NULL;
    n = malloc(sizeof(node));
    n->next = NULL;
    return n;
}
void insertAtEnd(node **head, int data)
{
    node *tmp = createNode();
    tmp->data = data;
    if (*head == NULL)
    {
        *head = tmp;
        return;
    }
    node *tmp1 = createNode();
    tmp1 = *head;
    while (tmp1->next != NULL)
    {
        tmp1 = tmp1->next;
    }
    tmp1->next = tmp;
}

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

struct List
{
    int data;
    struct List *next;
};
typedef struct List queue;
queue *createNodeForQueue()
{
    queue *n = NULL;
    n = (queue *)malloc(sizeof(queue));
    n->next = NULL;
    return n;
}
void enqueue(queue **head, int data)
{
    queue *tmp = createNodeForQueue();
    tmp->data = data;
    if (*head == NULL)
    {
        *head = tmp;
    }
    else
    {
        queue *tmp1 = createNodeForQueue();
        tmp1 = *head;
        while (tmp1->next != NULL)
        {
            tmp1 = tmp1->next;
        }
        tmp1->next = tmp;
    }
}
int dequeue(queue **head)
{
    if (*head == NULL)
    {
        printf("Queue Underflow");
        return -1;
    }
    queue *tmp = createNodeForQueue();
    tmp = *head;
    int i = tmp->data;
    tmp = tmp->next;
    *head = tmp;
    return i;
}

int main()
{
    node **head = NULL;
    head = malloc(sizeof(node));
    queue **qu = NULL;
    qu = malloc(sizeof(queue));
    stack *st = createStack();
    stack *st1 = createStack();
    for (int i = 1; i < 7; i++)
    {
        insertAtEnd(head, i);
    }
    node *tmp = createNode();
    tmp = *head;
    while (tmp != NULL)
    {
        if (tmp->data % 2 == 0)
        {
            enqueue(qu, tmp->data);
        }
        else
        {
            push(st, tmp->data);
        }
        tmp = tmp->next;
    }
    int len = size(st);
    int arr[len];
    for (int i = 0; i < len; i++)
    {
        arr[i] = top(st);
        pop(st);
    }
    for (int i = 0; i < len; i++)
    {
        push(st1, arr[len - i - 1]);
        push(st1, dequeue(qu));
        pop(st);
    }
    printStack(st1);
}