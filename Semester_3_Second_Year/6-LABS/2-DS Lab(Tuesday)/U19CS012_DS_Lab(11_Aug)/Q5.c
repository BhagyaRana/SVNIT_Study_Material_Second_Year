// Question 5 : Write a C Program to copy an array to another array in reverse.

#include<stdio.h>

int main()
{
    int arr[100];
    int n;
    printf("Enter Number of Elements in Array(<100) :\n");
    scanf("%d", &n);

    if (n<1)
    {
        printf("Reverse Not Possible\n");
        return 0;
    }

    printf("Enter Elements in Array :\n");

    for (int i=0;i<n;i++)
    {
        scanf("%d", &arr[i]);
    }

    int copy[100];

    printf("Reverse Array is :\n");

    for (int i=0;i<n;i++)
    {
        copy[i] = arr[n-i-1];
        printf("%d ", copy[i]);
    }
    printf("\n");

    return 0;
}
