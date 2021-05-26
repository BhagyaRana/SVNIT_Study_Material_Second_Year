// U19CS012 BHAGYA VINOD RANA
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
    // Input
    ll n;
    cin >> n;
    vector<ll> arr(n, 0);
    for (auto &x : arr)
    {
        cin >> x;
    }

    // Confessions of each child when Traversed from Left
    vector<ll> lft(n, 1);
    // Confessions of each child when Traversed from Right
    vector<ll> rgt(n, 1);

    // Left Sub-Problem
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr[i - 1])
            lft[i] = lft[i - 1] + 1;
    }

    // Right Sub-Problem
    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] > arr[i + 1])
            rgt[i] = rgt[i + 1] + 1;
    }

    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        // max will take care of both the neighbours
        ans += max(lft[i], rgt[i]);
    }
    cout << "Minimum Confessions : " << ans << "\n";

    return 0;
}
