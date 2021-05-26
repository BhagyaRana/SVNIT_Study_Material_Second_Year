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
            cout << i << " " << Aux_Hgt[i] << " ";
            Old_Hgt = Aux_Hgt[i];
        }
    }
    cout << Rmax << " " << Aux_Hgt[Rmax] << endl;
    return;
}

int main()
{
    vector<int> L;
    vector<int> R;
    vector<int> H;

    // li = x-Position Of Left Edge
    // ri = x-Position Of Right Edge
    // hi = Building's Height
    int lft, rgt, hgt;
    while (cin >> lft >> hgt >> rgt)
    {
        L.push_back(lft);
        H.push_back(hgt);
        R.push_back(rgt);
    }

    Sky_Line_Brute_Force(L, R, H);

    return 0;
}

// Sample Test Case [https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=41]

// INPUT :

// 1 11 5
// 2 6 7
// 3 13 9
// 12 7 16
// 14 3 25
// 19 18 22
// 23 13 29
// 24 4 28

// Expected Output:

// 1 11 3 13 9 0 12 7 16 3 19 18 22 3 23 13 29 0
