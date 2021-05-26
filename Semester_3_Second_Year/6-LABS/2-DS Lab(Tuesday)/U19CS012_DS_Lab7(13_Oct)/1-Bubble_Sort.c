//Implement Bubble Sort Algorithm

#include <stdio.h>

#define MAX 10001

//Predefined a Static Array of MAX Size
int arr[MAX];

//1 -> Simple Bubble Sort Implementation Always -> 0(n^2)
void Bubble_Sort(int arr[], int n);

//2 -> Optimised Bubble Sort Implementation
//Takes Less Iterations if Array is Already Sorted
void Optimized_Bubble_Sort(int arr[], int n);

//Small Helper Function to Print the Array
void print(int arr[], int sz);

int main()
{
    int n;
    printf("\nEnter the Number of Elements [Max: 1e5] to Sort : ");
    scanf("%d", &n);

    // Invalid Input Entered
    if (n < 0)
    {
        printf("\nInvalid Input!\nEnter Positive Number of Elements [>0]!!\n");
        return 0;
    }
    // No Element to Sort
    if (n == 0)
    {
        printf("\nWe Need to Enter (atleast) One Element to Sort!!");
        return 0;
    }

    printf("\nEnter the Values of Array to Sort : \n");

    for (int i = 0; i < n; i++)
    {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }

    int choice;
    printf("Which Bubble Sort to Use \n1 -> Simple \n2 -> Optimized\n");
    printf("Choice : ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        Bubble_Sort(arr, n);
        break;
    case 2:
        Optimized_Bubble_Sort(arr, n);
        break;
    default:
        printf("Enter a Valid Choice!");
        break;
    }

    return 0;
}

void Bubble_Sort(int arr[], int n)
{
    // Iterators
    int i, j;
    // tmp Variable For Swapping
    int tmp;

    printf("Initial Array : ");
    print(arr, n);
    printf("\n");

    int pass = 1;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
            {
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        printf("Array After Pass %d : ", pass);
        print(arr, n);
        printf("\n");
        pass += 1;
    }
    printf("Sorted Array : ");
    print(arr, n);
    printf("\n");
}

void Optimized_Bubble_Sort(int arr[], int n)
{
    // Iterators
    int i, j;
    // tmp Variable For Swapping
    int tmp;

    printf("Initial Array : ");
    print(arr, n);
    printf("\n");

    int pass = 1;
    int flag = 0;
    for (i = 0; i < n - 1; i++)
    {
        flag = 0;
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
            {
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
                flag = 1;
            }
        printf("Array After Pass %d : ", pass);
        print(arr, n);
        printf("\n");
        pass += 1;
        // flag -> 0 ; When No Element is Swapped
        if (flag == 0)
        {
            break;
        }
    }
    printf("Sorted Array : ");
    print(arr, n);
    printf("\n");
}

void print(int arr[], int sz)
{
    int i;
    for (i = 0; i < sz; i++)
        printf("%d ", arr[i]);
    printf("\n");
}