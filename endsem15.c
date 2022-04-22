#include <stdio.h>

void swapingUsingPointer(int *p, int *q)
{
    int temp = *q;
    *q = *p;
    *p = temp;
}

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    int *p = &a;
    int *q = &b;
    pointerswap(p, q);
    printf("After changing %d %d", a, b);
    return 0;
}