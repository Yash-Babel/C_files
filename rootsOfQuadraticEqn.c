#include <stdio.h>
#include <math.h>
int main()
{
    double a, b, c, d, sq;
    printf("For quadratic equation ax^2 + bx + c , Enter a b c\n");
    scanf("%lf %lf %lf", &a, &b, &c);
    d = (b * b) - (4 * a * c);
    if (d < 0)
    {
        sq = sqrt(-d);
        printf("root 1 : %lf + %lfi\n", -b / (2 * a), sq / (2 * a));
        printf("root 2 : %lf - %lfi", -b / (2 * a), sq / (2 * a));
    }
    else
    {
        sq = sqrt(d);
        printf("root 1 : %lf\n", (-b + sq) / (2 * a));
        printf("root 2 : %lf", (-b - sq) / (2 * a));
    }
    return 0;
}