#include <stdio.h>
#include <string.h>
int stringCompare(char s1[], char s2[], int index, int maxIndex)
{
    if (index > maxIndex)
    {
        if (strlen(s1) > strlen(s2))
        {
            return 2;
        }
        else if (strlen(s1) < strlen(s2))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    if (s1[index] > s2[index])
    {
        return 2;
    }
    else if (s1[index] < s2[index])
    {
        return 1;
    }
    else
    {
        return stringCompare(s1, s2, index + 1, maxIndex);
    }
}
int main()
{
    char s1[50];
    char s2[50];
    printf("Enter a first string\n");
    gets(s1);
    printf("Enter a second string\n");
    gets(s2);
    int len1 = strlen(s1), len2 = strlen(s2);
    int maxIndex;
    if (len1 > len2)
    {
        maxIndex = len2 - 1;
    }
    else
    {
        maxIndex = len1 - 1;
    }
    int answer = stringCompare(s1, s2, 0, maxIndex);
    if (answer == 0)
    {
        printf("Both Strings are same and that is : %s", s1);
    }
    else if (answer == 1)
    {
        printf("Alphabetically smaller String is : %s", s1);
    }
    else
    {
        printf("Alphabetically smaller String is : %s", s2);
    }
    return 0;
}
