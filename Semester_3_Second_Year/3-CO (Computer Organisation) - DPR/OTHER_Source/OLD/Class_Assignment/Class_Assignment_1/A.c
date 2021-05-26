// Program for division of two numbers
#include <stdio.h>

int main()
{
    double a, b;

    printf("Enter Number 1 :\n");

    scanf("%lf", &a);

    printf("Enter Number 2 :\n");

    scanf("%lf", &b);

    if (b != 0)
    {
        double ans = (a / b);
        printf("a/b = %lf", ans);
    }
    else
    {
        printf("Divide by Zero Error!");
    }

    return 0;
}