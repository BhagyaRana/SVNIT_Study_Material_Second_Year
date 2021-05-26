#include <bits/stdc++.h>

using namespace std;

//SHORT HAND
#define pb push_back
#define mp make_pair

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pi;
typedef vector<pi> vpi;

// Merging of Two Skylines Using Two-Pointer Approach
vpi merge_skyline(vpi &lft_skyline, vpi &rgt_skyline);

// Skyline Problem [Divide And Conquer Approach ~ Merge Sort]
vpi Skyline_DnC(vvi &buildings, int start, int end);

int main()
{
    // Number of Points
    int n, lft, rgt, hgt;
    cin >> n;

    // lft = x-Position Of Left Edge
    // rgt = x-Position Of Right Edge
    // hgt = Building's Height

    vvi buildings;
    for (int i = 0; i < n; i++)
    {
        cin >> lft >> rgt >> hgt;
        vi tmp;
        tmp.push_back(lft);
        tmp.push_back(rgt);
        tmp.push_back(hgt);
        buildings.push_back(tmp);
    }

    vpi final_ans = Skyline_DnC(buildings, 0, buildings.size() - 1);

    for (auto pr : final_ans)
    {
        cout << pr.first << " " << pr.second << endl;
    }

    return 0;
}

// Skyline Problem [Divide And Conquer Approach ~ Merge Sort]
vpi Skyline_DnC(vvi &buildings, int start, int end)
{
    // Base Case
    if (start == end)
    {
        vpi ans;
        ans.pb({buildings[start][0], buildings[start][2]});
        ans.pb({buildings[start][1], 0});
        return ans;
    }

    int mid = start + (end - start) / 2; // Avoid Overflow Errors

    vpi lft_skyline = Skyline_DnC(buildings, start, mid);
    vpi rgt_skyline = Skyline_DnC(buildings, mid + 1, end);
    vpi ans = merge_skyline(lft_skyline, rgt_skyline);

    return ans;
}

// Merging of Two Skylines Using Two-Pointer Approach
vpi merge_skyline(vpi &lft_skyline, vpi &rgt_skyline)
{
    vpi ans;
    // Two Pointers
    int i = 0, j = 0, curr_hgt1 = 0, curr_hgt2 = 0;
    int max_hgt = max(curr_hgt1, curr_hgt2);

    // Iterating until any one of Skyline Ends
    while (i < lft_skyline.size() && j < rgt_skyline.size())
    {
        // Case 1 : X Co-Ordinate of Left Skyline is Smaller
        if (lft_skyline[i].first < rgt_skyline[j].first)
        {
            curr_hgt1 = lft_skyline[i].second;
            if (max_hgt != max(curr_hgt1, curr_hgt2))
            {
                ans.pb({lft_skyline[i].first, max(curr_hgt1, curr_hgt2)});
            }
            max_hgt = max(curr_hgt1, curr_hgt2);
            i++;
        }
        // Case 2 : X Co-Ordinate of Right Skyline is Smaller
        else if (lft_skyline[i].first > rgt_skyline[j].first)
        {
            curr_hgt2 = rgt_skyline[j].second;
            if (max_hgt != max(curr_hgt1, curr_hgt2))
            {
                ans.pb({rgt_skyline[j].first, max(curr_hgt1, curr_hgt2)});
            }
            max_hgt = max(curr_hgt1, curr_hgt2);
            j++;
        }
        // Case 3 : Both Have Same X Co-ordinate
        else
        {
            curr_hgt1 = lft_skyline[i].second;
            curr_hgt2 = rgt_skyline[j].second;
            // Case 3 (a) : Height of Left Skyline is Greater
            if (lft_skyline[i].second >= rgt_skyline[j].second)
            {
                if (max_hgt != max(curr_hgt1, curr_hgt2))
                {
                    ans.pb({lft_skyline[i].first, max(curr_hgt1, curr_hgt2)});
                }
            }
            // Case 3 (b) : Height of Right Skyline is Greater
            else
            {
                if (max_hgt != max(curr_hgt1, curr_hgt2))
                {
                    ans.pb({rgt_skyline[j].first, max(curr_hgt1, curr_hgt2)});
                }
            }
            max_hgt = max(curr_hgt1, curr_hgt2);
            i++;
            j++;
        }
    }
    // Remaining Elements in Left Skyline
    while (i < lft_skyline.size())
    {
        ans.pb(lft_skyline[i]);
        i++;
    }
    // Remaining Elements in Right Skyline
    while (j < rgt_skyline.size())
    {
        ans.pb(rgt_skyline[j]);
        j++;
    }

    return ans;
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