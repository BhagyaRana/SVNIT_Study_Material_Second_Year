//To perform all arithmetic operations of two numbers
// given from the command line, but using qualifiers.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc > 1)
    {
        printf("Constants Value Cant Be Modified!\n");
        printf("Enter 0 Arguments Only!");
        return -1;
    }
    // Using Qualifier
    const double a = 250.800, b = 125.400;
    printf("a = %lf\n", a);
    printf("b = %lf\n", b);

    const double add = a + b;
    printf("a + b = %lf\n", add);
    const double sub = a - b;
    printf("a - b = %lf\n", sub);
    const double mul = (a * b);
    printf("a * b = %lf\n", mul);

    if (b != 0)
    {
        const double ans = (a / b);
        printf("a / b = %lf\n", ans);
    }
    else
    {
        printf("Divide by Zero Error!\n");
    }

    printf("Since Modulus Operator Works only for Integer Numbers\nEg : [1000, 3]\n");

    const long long int num1 = 1000, num2 = 3;

    if (num2 != 0)
    {
        const long long int ans1 = num1 % num2;
        printf("num1 %% num2 = %lld", ans1);
    }
    else
    {
        printf("Modulo by Zero Error!");
    }
    return 0;
}