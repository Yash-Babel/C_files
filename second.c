#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int num;
    struct node *next;
} node;

// global variable pointer
node *list = NULL;

void free_list(node *list)
{
    while (list != NULL)
    {
        node *tmp = list->next;
        free(list);
        list = tmp;
    }

    return;
}

void create_list(int size)
{
    // creating the first node
    node *n = (node *)malloc(sizeof(node));

    // if enough space isn't available on the heap and malloc returned NULL
    if (n == NULL)
    {
        printf("Failed to allocate memory.\n");
        exit(1);
    }

    // getting user inputs
    printf("Enter the element(s) of the list: ");
    int data;
    scanf("%d", &data);

    // initialising the node
    n->num = data; // n->num is same as (*n).num
    n->next = NULL;
    list = n;

    // temporary pointer
    node *_tmp = list;

    for (int i = 2; i <= size; i++)
    {
        // creating a new node
        n = (node *)malloc(sizeof(node));

        if (n == NULL)
        {
            printf("Failed to allocate memory.\n");

            // freeing the memory already allocated to the list
            free_list(list);

            exit(1);
        }

        // getting user input
        scanf("%d", &data);

        // entering data in our new node
        n->num = data;
        n->next = NULL;

        // linking the new node with our list using our temporary pointer
        _tmp->next = n;

        // updating the temporary pointer
        _tmp = _tmp->next;
    }

    printf("SINGLY LINKED LIST CREATED SUCCESSFULLY!\n");

    return;
}

void insert(node **tmp, int a)
{
    // creating a new node
    node *n = (node *)malloc(sizeof(node));
    if (n == NULL)
    {
        printf("Failed to allocate memory.\n");

        // freeing the memory already allocated to the list
        free_list(list);

        exit(1);
    }

    n->num = a;
    n->next = (*tmp); // poitning to the next node

    // now we can redirect tmp to the new node
    (*tmp) = n;

    return;
}

void display(node *list)
{
    for (node *tmp = list; tmp != NULL; tmp = tmp->next)
        printf("%d ", tmp->num);

    printf("\n");

    return;
}

int main()
{
    printf("Enter the size of the linked list: ");
    int n;
    scanf("%d", &n);

    // calling our create_list function to create a list of size n
    create_list(n);

    // diaplaying the contents of the list
    printf("LIST: ");
    display(list);

    // inserting element at the beginning
    int a;
    printf("Enter the element to be inserted at the beginning: ");
    scanf("%d", &a);

    insert(list, a);

    printf("New list after insertion: ");
    display(list);

    // inserting element after a given element
    // first we need to find the index of the given element
    printf("Enter the element after which the new element is to be inserted: ");
    int b;
    scanf("%d", &b);

    for (node *tmp = list; tmp != NULL; tmp = tmp->next)
    {
        if (tmp->num == b)
        {
            printf("Enter the element to be inserted: ");
            scanf("%d", &a);

            insert(tmp->next, a);

            printf("New list after insertion: ");
            display(list);

            break;
        }
        else if (tmp->next == NULL)
            printf("%d is not present in the list.\n", b);
    }

    // freeing all the memory requested from the heap
    free_list(list);

    return 0;
}