// Question 1 :Take a decimal number from command line
//  and convert into binary number. 

#include <stdio.h>

int main()
{
    int n;
    printf("Enter A Decimal(Integer) Number : ");
    scanf("%d", &n);

    int ans = 0;
    int power = 1;

    while (n)
    {
        ans += ((n%2)*power);
        power *= 10;
        n = n/2;
    }

    printf("Binary Number : %d\n", ans);

    return 0;
}
