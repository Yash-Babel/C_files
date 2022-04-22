// #include <stdio.h>
int fact(int n)
{
    int answer = 1;
    for (int i = 1; i < (n + 1); i++)
        answer = answer * i;
    return answer;
}
void fib(int n)
{
    int answer;
    int a = 0;
    int b = 1;
    if (n == 1)
        answer = 1;
    else
    {
        int tmp;
        for (int i = 1; i < n; i++)
        {
            tmp = a + b;
            a = b;
            b = tmp;
        }
        answer = b;
    }
    printf("The nth term fibonacci sequence is : %d", answer);
}