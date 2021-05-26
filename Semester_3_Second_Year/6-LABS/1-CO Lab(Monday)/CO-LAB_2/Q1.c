//To declare the native data type,
// check the size of them and
// print the values if given beyond the range.
#include <stdio.h>

int main()
{
    long long int x;
    printf("Enter Integer :\n");
    scanf("%lld", &x);
    if (x >= -2147483648 && x <= 2147483647)
    {
        printf("Valid Input!\n");
        printf("The Size of Integer is %d\n", sizeof(int));
    }
    else
    {
        printf("Invalid Input!\n");
        printf("Value Entered is Out of Range of Data Type\n");
    }

    return 0;
}
