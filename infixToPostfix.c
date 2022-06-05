#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct lifo
{
    char data;
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
int isEmpty(stack **head)
{
    return (*head == NULL);
}
void push(stack **head, char data)
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
char pop(stack **head)
{
    if (*head != NULL)
    {
        char ch = (*head)->data;
        stack *tmp = createNode();
        tmp = *head;
        tmp = tmp->next;
        *head = tmp;
        return ch;
    }
    return ':';
}
void printStack(stack *st)
{
    while (st != NULL)
    {
        printf("%d ", st->data);
        st = st->next;
    }
}
char top(stack **head)
{
    return (*head)->data;
}
int main()
{
    // stack **head = NULL;
    // head = malloc(sizeof(stack));
    // push(head, 4);
    // push(head, 5);
    // push(head, 6);
    // push(head, 7);
    // pop(head);
    // printStack(*head);
    int t = 1;
    scanf("%d", &t);
    while (t--)
    {
        char s[500];
        scanf("%s", s);
        stack **head = NULL;
        head = malloc(sizeof(stack));
        int len = strlen(s);
        // printf("%d", len);
        for (int i = 0; i < len; i++)
        {
            char ch = s[i];
            if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^' || ch == '(')
            {
                push(head, ch);
            }
            else if (ch == ')')
            {
                while (!isEmpty(head) && top(head) != '(')
                {
                    printf("%c", pop(head));
                }
                if (!isEmpty(head))
                {
                    pop(head);
                }
            }
            else
            {
                printf("%c", ch);
            }
        }
        while (!isEmpty(head))
        {
            printf("%c", pop(head));
        }
        printf("\n");
    }
}