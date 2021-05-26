//To perform all arithmetic operations of two numbers
// given from the command line.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int a, b;

    if (argc < 3)
    {
        printf("Enter Two Arguments!\n");
        return -1;
    }

    // printf("Enter Number 1 :\n");

    // scanf("%d", &a);
    a = atoi(argv[1]);

    // printf("Enter Number 2 :\n");

    // scanf("%d", &b);
    b = atoi(argv[2]);

    int add = a + b;
    printf("a + b = %d\n", add);
    int sub = a - b;
    printf("a - b = %d\n", sub);
    int mul = (a * b);
    printf("a * b = %d\n", mul);

    if (b != 0)
    {
        int ans = (a / b);
        printf("a / b = %d\n", ans);
    }
    else
    {
        printf("Divide by Zero Error!\n");
    }

    // printf("Since Modulus Operator Works only for Integer Numbers, Enter Input Again\n");

    // int num1 = a, num2 = b;

    // printf("Enter Number 1 :\n");

    // scanf("%lld", &num1);

    // printf("Enter Number 2 :\n");

    // scanf("%lld", &num2);

    if (b != 0)
    {
        int ans1 = a % b;
        printf("a %% b = %d", ans1);
    }
    else
    {
        printf("Modulo by Zero Error!");
    }

    return 0;
}