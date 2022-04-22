#include <stdio.h>
int main()
{
    int value = 0, k;
    int mat1[2][2] = {
        {1, 2},
        {3, 4}};
    int mat2[2][2] = {
        {3, 4},
        {1, 2}};
    int answer[2][2] = {
        {0, 0},
        {0, 0}};
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (k = 0; k < 2; k++)
            {
                value += (mat1[i][k] * mat2[k][j]);
            }
            answer[i][j] = value;
            value = 0;
        }
    }
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("%d ", answer[i][j]);
        }
        printf("\n");
    }
}