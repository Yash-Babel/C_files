#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct studentData
{
    char name[11];
    int id, JEEScore, XIIPercentage;
};

int main()
{
    struct studentData data[50];
    int scholarship[50];
    srand(time(0));

    for (int i = 0; i < 50; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            data[i].name[j] = (rand() % 26) + 65;
        }
        data[i].name[10] = '\0';

        data[i].id = (rand() % 90000) + 10000;

        data[i].JEEScore = rand() % 301;
        data[i].XIIPercentage = rand() % 101;

        if (data[i].JEEScore >= 200)
        {

            if (data[i].XIIPercentage >= 90)
            {
                scholarship[i] = 100;
            }
            else if (data[i].XIIPercentage >= 80)
            {
                scholarship[i] = 75;
            }
            else if (data[i].XIIPercentage >= 70)
            {
                scholarship[i] = 50;
            }
            else
            {
                scholarship[i] = 0;
            }
        }

        else if (data[i].JEEScore >= 100)
        {

            if (data[i].XIIPercentage >= 90)
            {
                scholarship[i] = 75;
            }
            else if (data[i].XIIPercentage >= 80)
            {
                scholarship[i] = 50;
            }
            else if (data[i].XIIPercentage >= 70)
            {
                scholarship[i] = 25;
            }
            else
            {
                scholarship[i] = 0;
            }
        }
        else
        {
            scholarship[i] = 0;
        }

        printf("%s\t%d\t%d\n", data[i].name, data[i].id, scholarship[i]);
    }
    return 0;
}