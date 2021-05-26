//Perform Multiplication for unsigned binary number
//Perform Addition and Subtraction of two signed binary numbers given from command line.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fromBinary(const char *s)
{
    return (int)strtol(s, NULL, 2);
}

int main()
{

    char num1[32], num2[32];
    int n1, n2;

    printf("Input Number 1: ");
    scanf("%s", num1);

    n1 = fromBinary(num1);

    printf("Input Number 2: ");
    scanf("%s", num2);

    n2 = fromBinary(num2);

    printf("Multiplcation Result : %d\n", (n1 * n2));

    return 0;
}
