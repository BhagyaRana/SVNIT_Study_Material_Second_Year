#include <stdio.h>

long long int arr[100001];
// At Max = 1e5 Elements
typedef long long int ll;
// Since -1e9<=A[i]<=1e9

int main()
{
    int n; // Number of Elements
    scanf("%d", &n);

    ll sum = 0;      // Max Sum
    int ele_cnt = 0; // Elements in Sub-Set
    ll min = -1000000001;
    // for Finding Highest -ve Number [Edge Case]

    for (int i = 0; i < n; i++)
    {
        scanf("%lli", &arr[i]);
        if (arr[i] >= 0)
        {
            ele_cnt++;
            sum += arr[i];
        }
        else
        {
            if (arr[i] > min)
                min = arr[i];
            // To Handle Edge Case When All Numbers are Negative
        }
    }
    // If All Elements are Negative, then ele_cnt = 0
    if (ele_cnt != 0)
        printf("%lli %d", sum, ele_cnt);
    else
        printf("%lli %d", min, 1);
    return 0;
}