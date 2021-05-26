// Question 1 :Take a decimal number from command line
//  and convert into binary number.

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

    // printf("Enter A Decimal(Integer) Number : ");
    // scanf("%d", &n);
    if (argc < 2)
    {
        printf("Enter Minimum 1 Argument!");
        return -1;
    }

    int n = atoi(argv[1]);

    int ans = 0;
    int power = 1;

    while (n)
    {
        ans += ((n % 2) * power);
        power *= 10;
        n = n / 2;
    }

    printf("Binary Number : %d\n", ans);

    return 0;
}
