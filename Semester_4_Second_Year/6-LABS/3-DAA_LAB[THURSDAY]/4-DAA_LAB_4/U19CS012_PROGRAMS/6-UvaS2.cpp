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

// Skyline Problem [Divide And Conquer Approach ~ Merge Sort]
vpi Skyline_DnC(vvi &buildings, int start, int end)
{
    // Base Case
    if (start == end)
    {
        vpi ans;
        ans.pb({buildings[start][0], buildings[start][1]});
        ans.pb({buildings[start][2], 0});
        return ans;
    }

    int mid = start + (end - start) / 2; // Avoid Overflow Errors

    vpi lft_skyline = Skyline_DnC(buildings, start, mid);
    vpi rgt_skyline = Skyline_DnC(buildings, mid + 1, end);
    vpi ans = merge_skyline(lft_skyline, rgt_skyline);

    return ans;
}

int main()
{
    // Number of Points
    int n, lft, rgt, hgt;
    // cin >> n;

    // lft = x-Position Of Left Edge
    // rgt = x-Position Of Right Edge
    // hgt = Building's Height

    vvi buildings;

    while (cin >> lft >> hgt >> rgt)
    {
        vi tmp;
        tmp.push_back(lft);
        tmp.push_back(hgt);
        tmp.push_back(rgt);
        buildings.push_back(tmp);
    }

    vpi final_ans = Skyline_DnC(buildings, 0, buildings.size() - 1);
    int sz = final_ans.size();
    for (int i = 0; i < sz; i++)
    {
        // Due to Presentation Error in UVa Judge
        if (i == sz - 1)
        {
            cout << final_ans[i].first << " " << final_ans[i].second << endl;
        }
        else
        {
            cout << final_ans[i].first << " " << final_ans[i].second << " ";
        }
    }

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