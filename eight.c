#include <stdio.h>
#include <string.h>
int main()
{
    int row1, col1, row2, col2;
    printf("enter the value of row and column i and j for matrix first and k and l for matrix second\n");
    scanf("%d %d %d %d", &row1, &col1, &row2, &col2);
    int mat1[row1][col1], mat2[row2][col2];
    // getchar();
    printf("enter the element of matrix 1\n");

    for (int i = 0; i < row1; i++)
    {

        for (int j = 0; j < col1; j++)
        {
            scanf("%d", &mat1[i][j]);
        }
    }
    printf("enter the element of matrix 2\n");

    for (int k = 0; k < row2; k++)
    {

        for (int l = 0; l < col2; l++)
        {
            scanf("%d", &mat2[k][l]);
        }
    }

    return 0;
}