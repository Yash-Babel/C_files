#include <stdio.h>
// struct Student
// {
//     char a;
//     int b;
//     char c;
// } sts[5];

union name
{
    int x;
    double y;
};

int main()
{
    char a;
    int b;
    char c;
    printf("%lu", sizeof(main));
    // printf("%lu", sizeof(struct Student));
    // union name value;
    // value.x = 100;
    // value.y = 100.0;
    // printf("%d %lf", value.x, value.y);
    return 0;
}