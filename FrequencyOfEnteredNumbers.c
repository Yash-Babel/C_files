#include <stdio.h>
int main()
{
    int n, sum = 0;
    printf("Enter number of numbers you want to find sum of\n");
    scanf("%d", &n);
    int arr[n];
    int count[2 * n];
    printf("Enter numbers\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int elements = 0;
    int newElement = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < elements; j++)
        {
            if (arr[i] == count[2 * j])
            {
                count[2 * j + 1]++;
                newElement = 0;
                break;
            }
        }
        if (newElement)
        {
            count[2 * elements] = arr[i];
            count[2 * elements + 1] = 1;
            elements++;
        }
        newElement = 1;
    }
    for (int i = 0; i < elements; i++)
    {
        printf("The frequency of %d is equal to %d\n", count[2 * i], count[2 * i + 1]);
    }
}