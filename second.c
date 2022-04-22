#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
int getrandomnum(int n)
{
    srand(time(NULL));
    return rand() % n;
}
int main()
{
    char playername[10];
    int n, i = 0;
    printf("enter the name of player\n");
    scanf("%s", playername);

    printf("game rules: choose given number for rock paper and scissors\n0 for rock\n1 for paper\n2 for scissors\n");

    while (i < 3)
    {
        printf("%s turns\n", playername);
        scanf("%d", &n);
        printf("computer turns\n");
        if (n == 0 && getrandomnum(2) == 1)
        {
            printf("its a paper ,,computer won this round\n");
        }
        else if (n == 0 && getrandomnum(2) == 2)
        {
            printf("its a scissors ,,%s won this round\n ", playername);
        }
        else if (n == 1 && getrandomnum(2) == 0)
        {
            printf("its a rock,,%s won this round\n ", playername);
        }
        else if (n == 1 && getrandomnum(2) == 2)
        {
            printf("its a scissors,,computer won this round\n");
        }
        else if (n == 2 && getrandomnum(2) == 0)
        {
            printf("its a rock,, computer won this round\n");
        }
        else if (n == 2 && getrandomnum(2) == 1)
        {
            printf("its a paper,, %s won this round\n", playername);
        }
        else
        {
            printf("both are same its a draw\n");
        }
        i++;
    }
    return 0;
}