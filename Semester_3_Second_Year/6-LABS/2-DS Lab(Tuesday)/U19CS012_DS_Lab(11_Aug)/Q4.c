// Question 4 : Write a C program to find second minimum element in array.

#include<stdio.h>
#include <limits.h> // For INT_MAX1

int main()
{
    int arr[100];
    int n;
    printf("Enter Number of Elements in Array(<100) :\n");
    scanf("%d", &n);

    if (n<2)
    {
        printf("Second Minimum Cant be Found\n");
        return 0;
    }

    printf("Enter Elements in Array :\n");

    for (int i=0;i<n;i++)
    {
        scanf("%d", &arr[i]);
    }

    int min1 = INT_MAX; // minimum in array
    int min2 = INT_MAX; // second minimum in array

    for (int i=0;i<n;i++)
    {
        if (arr[i] < min1)
        {
            min2 = min1; // Store the second min
            min1 = arr[i];
        }
        else
        {
            // ele > min1 && ele < min2
            if ((arr[i] > min1) && (arr[i] < min2))
            {
                min2 = arr[i];
            }
        }
    }

    printf("The Second Minimum Element in Array : %d\n", min2);

    return 0;
}

