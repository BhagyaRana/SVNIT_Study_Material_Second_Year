// U19CS012 BHAGYA VINOD RANA
#include <bits/stdc++.h>
// For Time Calculation
#include <chrono>
using namespace std;
using namespace std::chrono;
#define endl '\n'

int copy_cost, rep_cost, del_cost, ins_cost, twiddle_cost, kill_cost;
#define MAX_VAL 100000000

// (a) Naive iterative solution
// Check If the Sequence in tmp Leads to s1 -> s2
bool check(string s1, string s2, int n, int m, string tmp);
// Checks all Possible Operations
int Naive(string s1, string s2);

// (b) Naive recursive solution [Brute Force]
int Edit_Dist_Recur(string s1, string s2, int i, int j)
{
    if (i == -1 && j == -1)
    {
        return 0;
    }

    // If the First String is Empty,
    // Only Option is to Insert all Characters in Second String
    if (i == -1)
    {
        return (j + 1) * ins_cost;
    }
    // If the Second String is Empty,
    // Only Option is to Remove all Characters from First String
    if (j == -1)
    {
        return min(kill_cost, (i + 1) * del_cost);
    }

    int ans = MAX_VAL;

    if (s1[i] == s2[j])
    {
        ans = min(ans, copy_cost + Edit_Dist_Recur(s1, s2, i - 1, j - 1));
    }
    // Twiddle
    if (i >= 1 && j >= 1)
    {
        if (s1[i] == s2[j - 1] && s1[i - 1] == s2[j])
        {
            ans = min(ans, twiddle_cost + Edit_Dist_Recur(s1, s2, i - 2, j - 2));
        }
    }

    ans = min(ans, ins_cost + Edit_Dist_Recur(s1, s2, i, j - 1));     // Insert
    ans = min(ans, del_cost + Edit_Dist_Recur(s1, s2, i - 1, j));     // Remove
    ans = min(ans, rep_cost + Edit_Dist_Recur(s1, s2, i - 1, j - 1)); // Replace

    return ans;
}

// (c) Top-down dynamic programming solution
int Edit_Dist_TD(string s1, string s2, int i, int j, vector<vector<int>> &mem)
{
    if (i < 0 || j < 0)
        return 0;

    // If Sub-Problem has Already been Solved
    if (mem[i][j] != -1)
    {
        return mem[i][j];
    }

    // If any string is empty,
    // return the remaining characters of other string
    if (i == 0)
    {
        mem[i][j] = j * ins_cost;
        return mem[i][j];
    }
    if (j == 0)
    {
        mem[i][j] = min(i * del_cost, kill_cost);
        return mem[i][j];
    }

    int ans = MAX_VAL;

    // If last characters are equal,
    // recur for n-1, m-1
    if (s1[i - 1] == s2[j - 1])
    {
        ans = copy_cost + Edit_Dist_TD(s1, s2, i - 1, j - 1, mem);
    }

    // Twiddle Case
    if (i >= 2 && j >= 2)
    {
        if (s1[i - 1] == s2[j - 2] && s1[i - 2] == s2[j - 1])
        {
            ans = min(ans, twiddle_cost + Edit_Dist_TD(s1, s2, i - 2, j - 2, mem));
        }
    }

    // If characters are nt equal, we need to
    // find the minimum cost out of all 3 operations.
    ans = min(ans, ins_cost + Edit_Dist_TD(s1, s2, i, j - 1, mem));     // Insert
    ans = min(ans, del_cost + Edit_Dist_TD(s1, s2, i - 1, j, mem));     // Remove
    ans = min(ans, rep_cost + Edit_Dist_TD(s1, s2, i - 1, j - 1, mem)); // Replace

    return mem[i][j] = ans;
}

// (d) Bottom-up dynamic programming solution
int Edit_Dist_BU(string s1, string s2)
{
    int m = s1.length(), n = s2.length();
    // Table to Store the Results of Sub-Problems
    int dp[m + 1][n + 1];

    // If the Second String is Empty,
    // Only Option is to Remove all Characters from First String
    for (int i = 0; i < m + 1; i++)
    {
        dp[i][0] = min(i * del_cost, kill_cost);
    }

    // If the First String is Empty,
    // Only Option is to Insert all Characters in Second String
    for (int j = 0; j < n + 1; j++)
    {
        dp[0][j] = j * ins_cost;
    }

    // FILL dp[][] in Bottom Up Manner
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dp[i][j] = MAX_VAL;

            // If Last Character is Same,
            // Ignore the Last Character and Recur for Remiaining String
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + copy_cost;

            // Twiddle Case
            if (i >= 2 && j >= 2)
            {
                if (s1[i - 1] == s2[j - 2] && s1[i - 2] == s2[j - 1])
                {
                    dp[i][j] = min(dp[i][j], twiddle_cost + dp[i - 2][j - 2]);
                }
            }

            dp[i][j] = min(dp[i][j], ins_cost + dp[i][j - 1]);     // Insert
            dp[i][j] = min(dp[i][j], del_cost + dp[i - 1][j]);     // Remove
            dp[i][j] = min(dp[i][j], rep_cost + dp[i - 1][j - 1]); // Replace
        }
    }
    return dp[m][n];
}

int main()
{
    string str1, str2;
    cout << "Enter the Initial String :\n";
    cin >> str1;
    cout << "Enter the Final Required String :\n";
    cin >> str2;

    cout << "Enter the Cost for Following Operations :\n";
    cout << "COPY : "; // 0
    cin >> copy_cost;
    cout << "REPLACE : "; // 1
    cin >> rep_cost;
    cout << "DELETE : "; // 1
    cin >> del_cost;
    cout << "INSERT : "; // 1
    cin >> ins_cost;
    cout << "TWIDDLE : "; // 2
    cin >> twiddle_cost;
    cout << "KILL : "; // End
    cin >> kill_cost;

    int m = str1.length(), n = str2.length();

    auto start = high_resolution_clock::now();
    auto end = high_resolution_clock::now();
    auto time_taken = duration_cast<nanoseconds>(end - start);
    double ans = 0;

    // (a) Naive iterative solution
    // <DONOT UNCOMMMENT IT! VERY HIGH TIME COMPLEXITY CODE>
    // cout << "NAIVE ITERATIVE SOLUTION : " << endl;
    // start = high_resolution_clock::now();

    // cout << "Minimum Cost to Convert " << str1 << " to " << str2 << " : " << Naive(str1, str2) << "\n";

    // end = high_resolution_clock::now();
    // time_taken = duration_cast<nanoseconds>(end - start);
    // ans = (double)time_taken.count() / (double)(1e9);
    // cout << "Time Taken : " << ans << " seconds." << endl;

    // // (b) Naive recursive solution
    cout << "\nNAIVE RECURSIVE SOLUTION : " << endl;
    start = high_resolution_clock::now();

    cout << "Minimum Cost to Convert " << str1 << " to " << str2 << " : " << Edit_Dist_Recur(str1, str2, m - 1, n - 1) << "\n";

    end = high_resolution_clock::now();
    time_taken = duration_cast<nanoseconds>(end - start);
    ans = (double)time_taken.count() / (double)(1e9);
    cout << "Time Taken : " << ans << " seconds." << endl;

    // // (c) Top-down dynamic programming solution
    vector<vector<int>> mem(m + 1, vector<int>(n + 1, -1));
    cout << "\nTOP DOWN DP (RECURSIVE + MEMOIZATION) SOLUTION : " << endl;
    start = high_resolution_clock::now();

    cout << "Minimum Cost to Convert " << str1 << " to " << str2 << " : " << Edit_Dist_TD(str1, str2, m, n, mem) << "\n";

    end = high_resolution_clock::now();
    time_taken = duration_cast<nanoseconds>(end - start);
    ans = (double)time_taken.count() / (double)(1e9);
    cout << "Time Taken : " << ans << " seconds." << endl;

    // // (d) Bottom-up dynamic programming solution
    cout << "\nBOTTOM UP DP SOLUTION : " << endl;
    start = high_resolution_clock::now();

    cout << "Minimum Cost to Convert " << str1 << " to " << str2 << " : " << Edit_Dist_BU(str1, str2) << "\n";

    end = high_resolution_clock::now();
    time_taken = duration_cast<nanoseconds>(end - start);
    ans = (double)time_taken.count() / (double)(1e9);
    cout << "Time Taken : " << ans << " seconds." << endl;

    return 0;
}

bool check(string s1, string s2, int n, int m, string tmp)
{
    int ptr1 = 0, ptr2 = 0;
    char ch;
    for (int i = 0; i < tmp.length() && ptr1 < n && ptr2 < m; i++)
    {
        ch = tmp[i];
        if (ch == 'C')
        {
            if (s1[ptr1] == s2[ptr2])
            {
                ptr1++;
                ptr2++;
            }
        }
        else if (ch == 'R')
        {
            ptr1++;
            ptr2++;
        }
        else if (ch == 'D')
        {
            ptr1++;
        }
        else if (ch == 'I')
        {
            ptr2++;
        }
        else if (ch == 'T')
        {
            if (ptr1 <= n - 2 && ptr2 <= m - 2)
            {
                if (s1[ptr1] == s2[ptr2 + 1] && s1[ptr2] == s2[ptr1 + 1])
                {
                    ptr1 += 2;
                    ptr2 += 2;
                }
            }
        }
        else
        {
            if (ptr2 == m)
            {
                ptr1 = n;
                break;
            }
            // if (ptr1 == n)
            // {
            //     ptr2 = m;
            //     break;
            // }
        }
    }
    if (ptr1 == n && ptr2 == m)
        return true;
    else
        return false;
}

// Checks all Possible Operations
int Naive(string s1, string s2)
{
    int n = s1.length(), m = s2.length();
    // Since there are 6 Operations
    long int lmt = pow(7, m + n) - 1;
    int res = MAX_VAL;

    // Finding 7-ary Equivalent to Decimal Number

    for (int i = 0; i <= lmt; i++)
    {
        string tmp;
        int nums = i;
        for (int j = 0; j < max(m, n); j++)
        {
            tmp = to_string(nums % 7) + tmp;
            nums /= 7;
        }

        // cout << tmp << "\n";

        bool fl = false;
        for (int k = 0; k < tmp.length(); k++)
        {
            if (tmp[k] == '0')
            {
                fl = true;
                break;
            }
        }

        // Skip Number with 0 -> No Operation
        if (fl != false)
            continue;

        string tmp2;
        // 1 -> Copy, 2 -> Replace, 3 -> Delete, 4 -> Insert, 5 -> Twiddle 6 -> Kill
        for (int k = 0; k < tmp.length(); k++)
        {
            if (tmp[k] == '1')
                tmp2 += 'C';
            else if (tmp[k] == '2')
                tmp2 += 'R';
            else if (tmp[k] == '3')
                tmp2 += 'D';
            else if (tmp[k] == '4')
                tmp2 += 'I';
            else if (tmp[k] == '5')
                tmp2 += 'T';
            else
                tmp2 += 'K';
        }

        bool is_possible = check(s1, s2, n, m, tmp2);

        if (is_possible)
        {
            int cost = 0;
            for (int k = 0; k < tmp2.length(); k++)
            {
                if (tmp2[k] == 'C')
                    cost += copy_cost;
                else if (tmp2[k] == 'R')
                    cost += rep_cost;
                else if (tmp2[k] == 'I')
                    cost += ins_cost;
                else if (tmp2[k] == 'T')
                    cost += twiddle_cost;
                else if (tmp2[k] == 'D')
                    cost += del_cost;
                else
                    cost += kill_cost;
            }
            if (cost < res)
            {
                // cout << tmp2 << endl;
                res = cost;
            }
        }
    }
    return res;
}