//Question 3 : Take a decimal number from command line
//  and display its factorial using recursion. 
#include <stdio.h>

long long int fact(int n)
{
    //Base Case
    if (n==0 || n==1)
    {
        return 1;
    }

    return n*fact(n-1);
    // since n! = n*(n-1)!
}

int main()
{
    int num;
    printf("Enter Number(>=0) :\n");
    scanf("%d", &num);
    long long int ans = fact(num);
    printf("Factorial of %d : %lld\n", num, ans);

    return 0;
}
