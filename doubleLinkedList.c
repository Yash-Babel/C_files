#include <stdio.h>
#include <stdlib.h>

struct dlList
{
    int data;
    struct dlList *next;
    struct dlList *prev;
};

typedef struct dlList node;

node *createNode()
{
    node *n = NULL;
    n = (node *)malloc(sizeof(node));
    n->next = NULL;
    n->prev = NULL;
    return n;
}

void insertAtEnd(node **head, int data)
{
    node *tmp = createNode();
    tmp->data = data;
    if (*head == NULL)
    {
        *head = tmp;
    }
    else
    {
        node *tmp1 = createNode();
        tmp1 = *head;
        while (tmp1->next != NULL)
        {
            tmp1 = tmp1->next;
        }
        tmp1->next = tmp;
        tmp->prev = tmp1;
    }
}

void insertAtBeginning(node **head, int data)
{
    node *tmp = createNode();
    tmp->data = data;
    if (*head == NULL)
    {
        *head = tmp;
    }
    else
    {
        node *tmp1 = createNode();
        tmp1 = *head;
        *head = tmp;
        tmp->next = tmp1;
        tmp1->prev = tmp;
    }
}

void insertAfterAGivenElement(node **head, int data, int num)
{
    node *tmp = createNode();
    tmp->data = data;
    if (*head == NULL)
    {
        return;
    }
    node *tmp1 = createNode();
    tmp1 = *head;
    // tmp1 = tmp1->next;
    while (tmp1->data != num && tmp1->next != NULL)
    {
        tmp1 = tmp1->next;
    }
    if (tmp1->data == num)
    {
        tmp->next = tmp1->next;
        tmp->prev = tmp1;
        tmp1->next = tmp;
        tmp1 = tmp1->next;
        if (tmp1->next != NULL)
        {
            tmp1 = tmp1->next;
            tmp1->prev = tmp;
        }
    }
}

void deleteNodeWithValue(node **head, int value)
{
    node *tmp = createNode();
    if (*head == NULL)
        return;
    node *tmp1 = createNode();
    tmp1 = *head;
    while (tmp1->data != value && tmp1->next != NULL)
    {
        tmp = tmp1;
        tmp1 = tmp1->next;
    }
    if (tmp1->data == value)
    {
        if (tmp1->next == NULL && tmp1->prev == NULL)
        {
            *head = NULL;
            return;
        }
        if (tmp1->next == NULL)
        {
            tmp->next = NULL;
            tmp1->prev = NULL;
            return;
        }
        if (tmp1->prev == NULL)
        {
            tmp1 = tmp1->next;
            *head = tmp1;
            tmp1->prev = NULL;
            return;
        }
        tmp1 = tmp1->next;
        tmp->next = tmp1;
        tmp1->prev = tmp;
    }
}

void deleteNodeWithPosition(node **head, int position)
{
    int count = 0;
    node *tmp = createNode();
    if (*head == NULL)
    {
        return;
    }
    node *tmp1 = createNode();
    tmp1 = *head;
    count++;
    while (count != position && tmp1->next != NULL)
    {
        tmp = tmp1;
        tmp1 = tmp1->next;
        count++;
    }
    if (count == position)
    {
        if (tmp1->next != NULL)
        {
            tmp1->next->prev = tmp1->prev;
        }
        if (tmp1->prev != NULL)
        {
            tmp1->prev->next = tmp1->next;
        }
        else
        {
            *head = tmp1->next;
        }
    }
}

void printLList(node **head)
{
    if (*head == NULL)
    {
        return;
    }
    node *tmp = *head;
    while (tmp->next != NULL)
    {
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
    printf("%d\n", tmp->data);
}

node **reversingLinkedList(node **head)
{
    if (head == NULL || (*head)->next == NULL)
    {
        return head;
    }
    node *tmp1 = createNode();
    node *before = createNode();
    node *current = createNode();
    node *after = createNode();
    current = *head;
    tmp1 = *head;
    while (current->next != NULL)
    {
        after = current->next;
        current->next = before;
        current->prev = after;
        before = current;
        current = after;
    }
    tmp1->next = NULL;
    after = after->next;
    current->next = before;
    current->prev = after;
    head = &current;
    return head;
}
int main()
{
    node **head = NULL;
    head = malloc(sizeof(node));
    insertAtBeginning(head, 20);
    insertAtEnd(head, 5);
    insertAtEnd(head, 6);
    insertAfterAGivenElement(head, 45, 20);
    // deleteNodeWithValue(head, 20);
    // deleteNodeWithValue(head, 5);
    // deleteNodeWithValue(head, 6);
    // deleteNodeWithValue(head, 45);
    // deleteNodeWithPosition(head, 1);
    // deleteNodeWithPosition(head, 4);
    // deleteNodeWithPosition(head, 2);
    // head = reversingLinkedList(head);
    // head = reversingLinkedList(head);
    printLList(head);
}