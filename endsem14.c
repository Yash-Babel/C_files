#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int num = 0;
    if (n == 2)
    {
        printf("Not Possible");
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i % 2 == 0)
                {
                    if (j % 2 == 0 && num < n)
                    {
                        printf("1");
                        num++;
                    }
                    else
                    {
                        printf("0");
                    }
                }
                else
                {
                    printf("0");
                }
            }
            printf("\n");
        }
    }
}