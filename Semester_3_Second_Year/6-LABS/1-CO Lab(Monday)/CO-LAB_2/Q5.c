//Perform Addition and Subtraction of two signed binary numbers given from command line.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fromBinary(const char *s)
{
    return (int)strtol(s, NULL, 2);
}

int main(int argc, char *argv[])
{

    int num1, num2, bin_add, bin_sub;

    if (argc < 3)
    {
        printf("Enter Two Arguments!\n");
        return -1;
    }

    // printf("Input Number 1: ");
    // scanf("%d",&num1);

    num1 = fromBinary(argv[1]);

    // printf("Input Number 2: ");
    // scanf("%d",&num2);

    num2 = fromBinary(argv[2]);

    bin_add = num1 + num2;
    bin_sub = num1 - num2;

    printf("Binary Addition Result : %d\n", bin_add);
    printf("Binary Subtraction Result : %d\n", bin_sub);

    return 0;
}
