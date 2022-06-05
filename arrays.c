#include <stdio.h>

void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);

    printf("\n");

    return;
}

void insert(int arr[], int size, int ind, int data)
{
    for (int i = size - 1; i >= ind; i--)
        arr[i + 1] = arr[i];

    arr[ind] = data;

    return;
}

void delete (int arr[], int size, int ind)
{
    for (int i = ind; i < size - 1; i++)
        arr[i] = arr[i + 1];

    return;
}

int main()
{
    int arr[100] = {}, n;

    printf("Enter the size of the array. It should be less than 100 :\n");
    scanf("%d", &n);

    printf("Enter the elements :\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to be inserted at the beginning: ");
    int a;
    scanf("%d", &a);

    insert(arr, n, 0, a);
    n++;

    printf("New array after insertion: ");
    display(arr, n);

    // inserting a new element at the end
    printf("Enter the element to be inserted at the end: ");
    scanf("%d", &a);

    insert(arr, n, n, a);
    n++;

    printf("New array after insertion: ");
    display(arr, n);

    // inserting a new element at a given position
    printf("Index at which the new element is to be inserted: ");
    int index;
    scanf("%d", &index);

    if (index <= n && index >= 0)
    {
        printf("Enter the new element: ");
        scanf("%d", &a);

        insert(arr, n, index, a);
        n++;

        printf("New array after insertion: ");
        display(arr, n);
    }
    else
        printf("%d isn't a valid index.\n", index);

    // inserting element after a given element
    // first we need to find the index of the given element
    printf("Enter the element after which the new element is to be inserted: ");
    int b;
    scanf("%d", &b);

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == b)
        {
            printf("Enter the element to be inserted: ");
            scanf("%d", &a);

            index = i + 1;

            insert(arr, n, index, a);
            n++;

            printf("New array after insertion: ");
            display(arr, n);

            break;
        }
        else if (i == n - 1)
            printf("%d is not present in the array.\n", b);
    }

    // deleting a given element
    // first we need to find the index of the given element
    printf("Enter the element to be deleted: ");
    scanf("%d", &b);

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == b)
        {
            index = i;

            delete (arr, n, index);
            n--;

            printf("New array after deletion: ");
            display(arr, n);

            break;
        }
        else if (i == n - 1)
            printf("%d is not present in the array.\n", b);
    }

    return 0;
}