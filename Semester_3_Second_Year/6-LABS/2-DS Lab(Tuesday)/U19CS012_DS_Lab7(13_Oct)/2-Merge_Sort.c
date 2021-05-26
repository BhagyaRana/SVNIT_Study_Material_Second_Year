//Implement Merge Sort Algorithm

#include <stdio.h>

#define MAX 10001

//Predefined a Static Array of MAX Size
int arr[MAX];

//Recursive Function To Keep on Dividing the Array
void MergeSort(int arr[], int l, int r);

//Function to Merge the Divided Sub-Arrays
void merge(int arr[], int start, int mid, int end);

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

    printf("Initial Array : ");
    print(arr, n);
    printf("\n");

    MergeSort(arr, 0, n - 1);

    printf("Sorted Array : ");
    print(arr, n);
    printf("\n");

    return 0;
}

void merge(int arr[], int start, int mid, int end)
{
    // create a temp array
    int temp[end - start + 1];

    // Iterators for both intervals
    int i = start, j = mid + 1;

    // Iterators for temp
    int k = 0;

    // traverse both arrays and in each iteration add smaller of both elements in temp
    while (i <= mid && j <= end)
    {
        if (arr[i] <= arr[j])
        {
            temp[k] = arr[i];
            k += 1;
            i += 1;
        }
        else
        {
            temp[k] = arr[j];
            k += 1;
            j += 1;
        }
    }

    // add elements left in the first interval
    while (i <= mid)
    {
        temp[k] = arr[i];
        k += 1;
        i += 1;
    }

    // add elements left in the second interval
    while (j <= end)
    {
        temp[k] = arr[j];
        k += 1;
        j += 1;
    }

    // Copy Elements Back to Original Array
    for (i = start; i <= end; i += 1)
    {
        arr[i] = temp[i - start];
    }
}

//Recursive Function To Keep on Dividing the Array
void MergeSort(int arr[], int start, int end)
{
    int n = start + end + 1;
    int mid;

    if (start < end)
    {
        // To Avoid Overflow
        mid = start + (end - start) / 2;

        // Divide and Sort First Half
        MergeSort(arr, start, mid);

        // Divide and Sort Second Half
        MergeSort(arr, mid + 1, end);

        //Now Merge the Two Halfs
        merge(arr, start, mid, end);
    }
}

void print(int arr[], int sz)
{
    int i;
    for (i = 0; i < sz; i++)
        printf("%d ", arr[i]);
    printf("\n");
}