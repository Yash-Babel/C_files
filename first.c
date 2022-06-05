#include <stdio.h>
#include <stdlib.h>

struct lList
{
    int data;
    struct lList *next;
};

typedef struct lList node;

node *createNode()
{
    node *n = NULL;
    n = (node *)malloc(sizeof(node));
    n->next = NULL;
    return n;
}

void insertAtEnd(node **head, int data)
{
    node *tmp = createNode();
    node *tmp1 = createNode();
    tmp1 = *head;
    tmp->data = data;
    if (*head == NULL)
    {
        tmp1->next = tmp;
    }
    else
    {
        while (tmp1->next != NULL)
        {
            tmp1 = tmp1->next;
        }
        tmp1->next = tmp;
    }
}

void insertAtBeginning(node **head, int data)
{
    node *tmp = createNode();
    tmp->data = data;
    node *tmp1 = createNode();
    tmp1 = *head;
    tmp->next = tmp1->next;
    tmp1->next = tmp;
}

void insertAfterAGivenElement(node **head, int data, int num)
{
    node *tmp = createNode();
    tmp->data = data;
    node *tmp1 = createNode();
    tmp1 = *head;
    while (tmp1->data != num && tmp1->next != NULL)
    {
        tmp1 = tmp1->next;
    }
    tmp->next = tmp1->next;
    tmp1->next = tmp;
}

void deleteNodeWithValue(node **head, int value)
{
    node *tmp = createNode();
    node *tmp1 = createNode();
    tmp1 = *head;
    while (tmp1->data != value)
    {
        tmp = tmp1;
        tmp1 = tmp1->next;
    }
    tmp->next = tmp1->next;
    tmp1->next = NULL;
}

void printLList(node *head)
{
    node *tmp = head;
    tmp = tmp->next;
    while (tmp->next != NULL)
    {
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
    printf("%d\n", tmp->data);
}

node *reversingLinkedList(node *head)
{
    node *tmp1 = createNode();
    tmp1 = head;
    int count = 0;
    while (tmp1->next != NULL)
    {
        count++;
        tmp1 = tmp1->next;
        if (count > 1)
        {
            break;
        }
    }
    if (count > 1)
    {
        node *before = createNode();
        node *current = createNode();
        node *after = createNode();
        current = head->next;
        tmp1 = head->next;
        while (current->next != NULL)
        {
            after = current->next;
            current->next = before;
            before = current;
            current = after;
        }
        current->next = before;
        before = current;
        head->next = before;
        tmp1->next = NULL;
    }
    return head;
}
int main()
{
    node *head = NULL;
    head = malloc(sizeof(node));
    insertAtEnd(&head, 5);                  // 5
    insertAtEnd(&head, 6);                  // 5 6
    insertAtBeginning(&head, 20);           // 20 5 6
    insertAfterAGivenElement(&head, 45, 5); // 20 5 45 6
    deleteNodeWithValue(&head, 5);          // 20 45 6
    head = reversingLinkedList(head);       // 6 45 20
    printLList(head);
}