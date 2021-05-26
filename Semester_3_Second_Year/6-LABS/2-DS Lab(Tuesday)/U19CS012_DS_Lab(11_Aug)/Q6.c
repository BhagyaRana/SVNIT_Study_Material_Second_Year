// Question 6 : Write a C Program to concatenate arrays. 

#include<stdio.h>

int main()
{
    int arr[100];
    int n;

    printf("Enter Number of Elements in Array(<100) :\n");
    scanf("%d", &n);

    printf("Enter Elements in Array :\n");

    for (int i=0;i<n;i++)
    {
        scanf("%d", &arr[i]);
    }

    int arr2[100];
    int m;
    
    printf("Enter Number of Elements in Array 2 (<100) :\n");
    scanf("%d", &m);

    printf("Enter Elements in Array 2 :\n");

    for (int i=0;i<m;i++)
    {
        scanf("%d", &arr2[i]);
    }

    int arr3[200];
    for (int i=0;i<n;i++)
    {
        arr3[i] = arr[i];
    }

    for (int i=0;i<m;i++)
    {
        arr3[i+n] = arr2[i];
    }

    printf("The Concatenate Array is :\n");

    for (int i=0;i<(n+m);i++)
    {
        printf("%d ", arr3[i]);
    }
    printf("\n");

    return 0;
}
