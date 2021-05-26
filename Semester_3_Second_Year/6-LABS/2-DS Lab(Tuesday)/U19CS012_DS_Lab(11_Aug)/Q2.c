// Question 2 : Write a C program to find minimum element in array.

#include<stdio.h>

int main()
{
    int arr[100];
    int n;
    
    printf("Enter Number of Elements in Array(<100) :\n");
    scanf("%d", &n);

    if (n<1)
    {
        printf("Minimum Cant be Found\n");
        return 0;
    }

    printf("Enter Elements in Array :\n");

    for (int i=0;i<n;i++)
    {
        scanf("%d", &arr[i]);
    }

    int min = arr[0];

    if (n==1)
    {
        printf("The Minimum Element in Array : %d\n", min);
        return 0;
    }

    for (int i=1;i<n;i++)
    {
        if (arr[i]<min)
            min = arr[i];
    }

    printf("The Minimum Element in Array : %d\n", min);

    return 0;
}
