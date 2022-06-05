#include <stdio.h>

void arrayReverse(int *arr, int len)
{
    for (int i = 0; i < (len + 1) / 2; i++)
    {
        int tmp = arr[i];
        arr[i] = arr[len - i - 1];
        arr[len - i - 1] = tmp;
    }
}
int main()
{
    int n;
    printf("Enter the size of the array\n");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    arrayReverse(arr, n);
    // for (int i = 0; i < (n + 1) / 2; i++)
    // {
    //     int tmp = arr[i];
    //     arr[i] = arr[n - i - 1];
    //     arr[n - i - 1] = tmp;
    // }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}