#include <stdio.h>
int main()
{
    int n;
    printf("Enter number of numbers you want to save in array\n");
    scanf("%d", &n);
    int arr[n];
    printf("Enter numbers\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                arr[i] += arr[j];
                arr[j] = arr[i] - arr[j];
                arr[i] = arr[i] - arr[j];
            }
        }
    }
    printf("Entered numbers are :\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", arr[i]);
    }
}