// Question 3 : Write a C program to find second maximum element in array.

#include<stdio.h>
#include <limits.h> // For INT_MIN

int main()
{
    int arr[100];
    int n;

    printf("Enter Number of Elements in Array(<100) :\n");
    scanf("%d", &n);

    if (n<2)
    {
        printf("Second Maximum Cant be Found\n");
        return 0;
    }

    printf("Enter Elements in Array :\n");

    for (int i=0;i<n;i++)
    {
        scanf("%d", &arr[i]);
    }

    int mxn1 = INT_MIN; // maximum in array
    int mxn2 = INT_MIN; // second maximum in array

    for (int i=0;i<n;i++)
    {
        if (arr[i] > mxn1)
        {
            mxn2 = mxn1; // Store the second max
            mxn1 = arr[i];
        }
        else
        {
            // ele > mxn2 && ele < mxn1
            if ((arr[i] > mxn2) && (arr[i] < mxn1))
            {
                mxn2 = arr[i];
            }
        }
    }

    printf("The Second Maximum Element in Array : %d\n", mxn2);

    return 0;
}
