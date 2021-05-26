#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

// Maximum X Co-ordinate for Right Edge [Constraint]
#define MAX_Ri 10010
int Aux_Hgt[MAX_Ri];

// Skyline Problem
void Sky_Line_Brute_Force(vector<int> &L, vector<int> &R, vector<int> &H)
{
    int n = H.size();
    int Rmax = 0;
    // Interating For Each Building
    for (int i = 0; i < n; i++)
    {
        // From Range [L[i],R[i])
        // Check if H[i]>Aux_Hgt[j] [Building Bi is Taller]
        for (int j = L[i]; j < R[i]; j++)
        {
            if (Aux_Hgt[j] < H[i])
                Aux_Hgt[j] = H[i];
            if (Rmax < R[i])
                Rmax = R[i];
        }
    }

    int Old_Hgt = 0;
    for (int i = 1; i < Rmax; i++)
    {
        if (Old_Hgt != Aux_Hgt[i])
        {
            cout << i << " " << Aux_Hgt[i] << endl;
            Old_Hgt = Aux_Hgt[i];
        }
    }
    cout << Rmax << " " << Aux_Hgt[Rmax] << endl;
    return;
}

int main()
{
    // Number of Points
    ll n;
    cin >> n;

    vector<int> L(n, 0);
    vector<int> R(n, 0);
    vector<int> H(n, 0);
    // li = x-Position Of Left Edge
    // ri = x-Position Of Right Edge
    // hi = Building's Height

    for (int i = 0; i < n; i++)
    {
        cin >> L[i] >> R[i] >> H[i];
    }

    Sky_Line_Brute_Force(L, R, H);

    return 0;
}

// Sample Test Case

// INPUT :

// 8
// 1 5 11
// 2 7 6
// 3 9 13
// 12 16 7
// 14 25 3
// 19 22 18
// 23 29 13
// 24 28 4

// Expected Output:

// 1 11
// 3 13
// 9 0
// 12 7
// 16 3
// 19 18
// 22 3
// 23 13
// 29 0
