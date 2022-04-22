#include <stdio.h>
int main()
{
    int n, sum = 0;
    printf("Enter number of numbers to find mean, median and mode\n");
    scanf("%d", &n);
    int arr[n];
    printf("Enter numbers\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // MEAN

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    printf("Mean : %f\n", (sum * 1.0) / (n * 1.0));

    // MEDIAN

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
    if (n % 2 == 1)
    {
        printf("Median  :  %f\n", arr[(n - 1) / 2] * 1.0);
    }
    else
    {
        printf("Median  :  %f\n", (((arr[n / 2 - 1] + arr[n / 2]) * 1.0) / (2 * 1.0)));
    }

    // MODE

    int count[2 * n];
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
    int max = count[1];
    for (int i = 3; i < 2 * elements; i = i + 2)
    {
        if (count[i] > max)
        {
            max = count[i];
        }
    }
    printf("Mode  :  ");
    for (int i = 1; i < 2 * elements; i = i + 2)
    {
        if (count[i] == max)
        {
            printf("%d, ", count[i - 1]);
        }
    }
    printf("with frequency %d", max);
}