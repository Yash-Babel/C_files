#include <stdio.h>
#include <stdlib.h>

typedef struct lList *node;

struct lList
{
    int data;
    struct lList *next;
};

node createNode()
{
    node n = NULL;
    n = (node)(malloc(sizeof(node)));
    n->next = NULL;
    return n;
}

void insertAtEnd(node head, int data)
{
    node tmp = createNode();
    tmp->data = data;
    while (head->next != NULL)
    {
        head = head->next;
    }
    head->next = tmp;
}

void insertAtBeginning(node head, int data)
{
    node tmp = createNode();
    tmp->data = data;
    tmp->next = head->next;
    head->next = tmp;
}

void insertAfterAGivenElement(node head, int data, int num)
{
    node tmp = createNode();
    tmp->data = data;
    while (head->data != num && head->next != NULL)
    {
        head = head->next;
    }
    tmp->next = head->next;
    head->next = tmp;
}

void deleteNodeWithValue(node head, int value)
{
    node tmp = createNode();
    while (head->data != value)
    {
        tmp = head;
        head = head->next;
    }
    tmp->next = head->next;
    head->next = NULL;
}

void printLList(node head)
{
    node tmp = head;
    tmp = tmp->next;
    while (tmp->next != NULL)
    {
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
    printf("%d\n", tmp->data);
}

node reversingLinkedList(node head)
{
    node tmp1 = createNode();
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
        node before = createNode();
        node current = createNode();
        node after = createNode();
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
    node head = createNode();
    insertAtEnd(head, 5);
    insertAtEnd(head, 6);
    insertAtBeginning(head, 20);
    insertAfterAGivenElement(head, 45, 5);
    deleteNodeWithValue(head, 5);
    head = reversingLinkedList(head);
    printLList(head);
}