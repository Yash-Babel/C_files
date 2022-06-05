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

void printLList(node **head)
{
    node *tmp = *head;
    while (tmp != NULL)
    {
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
}

int main()
{
    node **l1 = NULL;
    l1 = malloc(sizeof(node));
    node **l2 = NULL;
    l2 = malloc(sizeof(node));
    insertAtEnd(l1, 6);
    insertAtEnd(l1, 4);
    insertAtEnd(l1, 7);
    insertAtEnd(l2, 1);
    insertAtEnd(l2, 6);
    insertAtEnd(l2, 4);
    insertAtEnd(l2, 7);
    insertAtEnd(l2, 5);
    insertAtEnd(l2, 6);
    int l1size = 3;
    int l2size = 6;
    node *tmp = createNode();
    tmp = *l2;
    node *before = createNode();
    int isDone = 0;
    while (tmp->next != NULL)
    {
        node *tmp1 = createNode();
        tmp1 = *l1;
        node *tmp2 = createNode();
        tmp2 = tmp;
        int isPresent = 1;
        for (int j = 0; j < l1size; j++)
        {
            if (tmp1->data != tmp2->data)
            {
                isPresent = 0;
                break;
            }
            tmp1 = tmp1->next;
            tmp2 = tmp2->next;
        }
        if (isPresent)
        {
            isDone = 1;
            node *start = createNode();
            node *second = createNode();
            node *after = createNode();
            start = before;
            second = before->next;
            after = tmp->next;
            for (int i = 0; i < l1size - 1; i++)
            {
                before = tmp;
                tmp = after;
                after = tmp->next;
                tmp->next = before;
            }
            start->next = tmp;
            second->next = after;
        }
        before = tmp;
        tmp = tmp->next;
    }
    if (isDone)
    {
        printLList(l2);
    }
    else
    {
        printf("l1 is not contained in l2.");
    }
}