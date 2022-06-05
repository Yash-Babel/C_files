#include <stdio.h>
#include <stdlib.h>

struct List
{
    int data;
    struct List *next;
};
typedef struct List queue;
queue *createNode()
{
    queue *n = NULL;
    n = (queue *)malloc(sizeof(queue));
    n->next = NULL;
    return n;
}
void push(queue **head, int data)
{
    queue *tmp = createNode();
    tmp->data = data;
    if (*head == NULL)
    {
        *head = tmp;
    }
    else
    {
        queue *tmp1 = createNode();
        tmp1 = *head;
        while (tmp1->next != NULL)
        {
            tmp1 = tmp1->next;
        }
        tmp1->next = tmp;
    }
}
void pop(queue **head)
{
    if (*head == NULL)
    {
        return;
    }
    queue *tmp = createNode();
    tmp = *head;
    tmp = tmp->next;
    *head = tmp;
}
void printQueue(queue *qu)
{
    while (qu != NULL)
    {
        printf("%d ", qu->data);
        qu = qu->next;
    }
}
int main()
{
    queue **head = NULL;
    head = malloc(sizeof(queue));
    push(head, 8);
    push(head, 9);
    push(head, 10);
    push(head, 11);
    push(head, 12);
    push(head, 13);
    pop(head);
    pop(head);
    printQueue(*head);
    return 0;
}