#include <stdio.h>

long long int a[100001], b[100001];
// At Max = 1e5 Elements
#define max(a, b) (a < b ? b : a)

int main()
{
    int test; // Number of Test Cases
    scanf("%d", &test);
    while (test--)
    {
        int n; // Size of Both Array [A & B]
        int madness = 0;

        scanf("%d", &n);

        for (int i = 0; i < n; i++)
        {
            scanf("%lli", &a[i]);
        }
        for (int i = 0; i < n; i++)
        {
            scanf("%lli", &b[i]);
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                if (b[j] >= a[i])
                {
                    madness = max(j - i, madness);
                }
                else
                {
                    break;
                    // Since it is Non-Decreasing Sequence
                    // we wont find any b[j] >= a[i] further
                }
            }
        }
        printf("%d\n", madness);
    }
    return 0;
}