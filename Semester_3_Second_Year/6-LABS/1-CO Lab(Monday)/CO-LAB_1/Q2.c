// Question 2 : Take a binary number from command line
//  and convert into decimal number.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Enter Minimum 1 Argument!");
        return -1;
    }

    long int bnum = stol(argv[1]);
    // printf("Enter Binary Number : \n");
    // scanf("%ld", &bnum);
    // fflush(stdin);
    int ans = 0, r = 0, base = 1, i = 0;

    while (bnum) //bnum!=0
    {
        r = bnum % 10; // remainder
        bnum /= 10;
        ans += (r * pow(2, i));
        i++;
    }

    printf("The Decimal Number : %d\n", ans);

    return 0;
}
