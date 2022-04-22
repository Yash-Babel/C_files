#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

    char w1[20], w2[20];
    int n;

    printf("Enter word to be replaced : ");
    scanf("%s", w1);
    printf("Enter the word that will replace: ");
    scanf("%s", w2);
    printf("Enter number of times the replacement to be done: ");
    scanf("%d", &n);

    int len = strlen(w1);
    char fileCh[5000];
    int numberOfCh = 0;
    FILE *ptr;
    ptr = fopen("FILE.txt", "r");

    char ch = fgetc(ptr);

    while (ch != EOF)
    {
        fileCh[numberOfCh] = ch;
        numberOfCh++;
        ch = fgetc(ptr);
    }

    fclose(ptr);

    ptr = fopen("FILE.txt", "w");

    int replacementsDone = 0;

    for (int i = 0; i < numberOfCh; i++)
    {
        int replaceable = 1;
        if ((n < 0 || replacementsDone < n) && i < numberOfCh - len + 1)
        {
            for (int j = 0; j < len; j++)
            {
                if (fileCh[i + j] == w1[j])
                {
                    continue;
                }
                else
                {
                    replaceable = 0;
                    break;
                }
            }
        }
        else
        {
            replaceable = 0;
        }
        if (replaceable)
        {
            fprintf(ptr, "%s", w2);
            i += (len - 1);
            replacementsDone++;
        }
        else
        {
            fputc(fileCh[i], ptr);
        }
    }

    if (n >= 0 && replacementsDone != n)
    {
        printf("Replacements done = %d", replacementsDone);
    }

    return 0;
}