#include <stdio.h>

void swapCharacters(char *one, char *two)
{
    char tmp;
    tmp = *one;
    *one = *two;
    *two = tmp;
}

int main()
{
    int size;
    printf("Enter size of string and the string to be reversed.\n");
    scanf("%d ", &size);
    char input[size];
    gets(input);
    for (int i = 0; i < (size + 1) / 2; i++)
    {
        swapCharacters(&input[i], &input[size - i - 1]);
    }
    printf("%s", &input);
    return 0;
}