// U19CS012 BHAGYA VINOD RANA
#include <bits/stdc++.h>
// For Time Calculation
#include <chrono>
using namespace std;
using namespace std::chrono;

// (a) Naive iterative solution
bool is_palindrome(string s)
{
    string t = s;
    reverse(t.begin(), t.end());
    return (s == t) ? true : false;
}

int LPS_Iter(string s)
{
    int ans = 1;
    int n = s.length();
    long long int lmt = 1 << n; //2^n Possibilities
    for (int i = 0; i < lmt; i++)
    {
        string tmp;
        for (int bit = n - 1; bit >= 0; bit--)
        {
            // If that Bit is Set
            if (i & (1 << bit))
            {
                tmp += s[bit];
            }
        }
        if (is_palindrome(tmp))
        {
            if (tmp.length() > ans)
                ans = tmp.length();
        }
    }
    return ans;
}

// (b) Naive recursive solution [Brute Force]
int LPS_NR(string s, int l, int r)
{
    // BASE CASE
    if (l > r)
        return 0;
    // Single Character = Palindrome
    if (l == r)
        return 1;
    // First Character == Last Character
    if (s[l] == s[r])
    {
        // Include the First and Last Character in the Palindrome
        // Recur for Remaining String
        return 2 + LPS_NR(s, l + 1, r - 1);
    }
    else
    {
        // Last character different from First Character
        // 1.) Remove first character & recur for [i+1,j]
        // 2.) Remove last character & recur for [i,j-1]

        // return max of Two Cases
        return max(LPS_NR(s, l + 1, r), LPS_NR(s, l, r - 1));
    }
}

// (c) Top-down dynamic programming solution
int LPS_TDDP(string s, int l, int r, vector<vector<int>> &mem)
{
    // BASE CASE
    if (l > r)
        return 0;
    // Single Character = Palindrome
    if (l == r)
        return 1;

    // Check if Answer is Already Computed [Memoization]
    if (mem[l][r])
        return mem[l][r];

    // First Character == Last Character
    if (s[l] == s[r])
    {
        // Include the First and Last Character in the Palindrome
        // Recur for Remaining String
        return 2 + LPS_TDDP(s, l + 1, r - 1, mem);
    }
    else
    {
        // Last character different from First Character
        // 1.) Remove first character & recur for [i+1,j]
        // 2.) Remove last character & recur for [i,j-1]

        // return max of Two Cases
        return max(LPS_TDDP(s, l + 1, r, mem), LPS_TDDP(s, l, r - 1, mem));
    }
}

// (d) Bottom-up dynamic programming solution
int LPS_BUDP(string s)
{
    int n = s.length();
    // Create a table to store results of subproblems
    int table[n][n];

    int i, j, strlen;

    // String of Length 1 = Palindromic
    for (int i = 0; i < n; i++)
    {
        table[i][i] = 1;
    }

    for (strlen = 2; strlen <= n; strlen++)
    {
        for (i = 0; i < n - strlen + 1; i++)
        {
            j = i + strlen - 1;

            // i -> Left Pointer
            // j -> Right Pointer

            // Same Character Palindrome of Length 2
            if (s[i] == s[j] && strlen == 2)
            {
                table[i][j] = 2;
            }
            else if (s[i] == s[j])
            {
                table[i][j] = 2 + table[i + 1][j - 1];
            }
            else
            {
                table[i][j] = max(table[i + 1][j], table[i][j - 1]);
            }
        }
    }

    // LPS in Range 0 to n-1
    return table[0][n - 1];
}

int main()
{
    string s;
    cin >> s;
    int n = s.length();

    auto start = high_resolution_clock::now();
    auto end = high_resolution_clock::now();
    auto time_taken = duration_cast<nanoseconds>(end - start);
    double ans = 0;

    // (a) Naive iterative solution
    cout << "NAIVE ITERATIVE SOLUTION : " << endl;
    start = high_resolution_clock::now();

    cout << "Length of Longest Palindromic Subsequence : " << LPS_Iter(s) << endl;

    end = high_resolution_clock::now();
    time_taken = duration_cast<nanoseconds>(end - start);
    ans = (double)time_taken.count() / (double)(1e9);
    cout << "Time Taken : " << ans << " seconds." << endl;

    // (b) Naive recursive solution
    cout << "\nNAIVE RECURSIVE SOLUTION : " << endl;
    start = high_resolution_clock::now();

    cout << "Length of Longest Palindromic Subsequence : " << LPS_NR(s, 0, n - 1) << endl;

    end = high_resolution_clock::now();
    time_taken = duration_cast<nanoseconds>(end - start);
    ans = (double)time_taken.count() / (double)(1e9);
    cout << "Time Taken : " << ans << " seconds." << endl;

    // (c) Top-down dynamic programming solution
    vector<vector<int>> mem(n, vector<int>(n));
    cout << "\nTOP DOWN DP (RECURSIVE + MEMOIZATION) SOLUTION : " << endl;
    start = high_resolution_clock::now();

    cout << "Length of Longest Palindromic Subsequence : " << LPS_TDDP(s, 0, n - 1, mem) << endl;

    end = high_resolution_clock::now();
    time_taken = duration_cast<nanoseconds>(end - start);
    ans = (double)time_taken.count() / (double)(1e9);
    cout << "Time Taken : " << ans << " seconds." << endl;

    // (d) Bottom-up dynamic programming solution
    cout << "\nBOTTOM UP DP SOLUTION : " << endl;
    start = high_resolution_clock::now();

    cout << "Length of Longest Palindromic Subsequence : " << LPS_BUDP(s) << endl;

    end = high_resolution_clock::now();
    time_taken = duration_cast<nanoseconds>(end - start);
    ans = (double)time_taken.count() / (double)(1e9);
    cout << "Time Taken : " << ans << " seconds." << endl;

    return 0;
}

// TEST CASE

// LEPCABZBQCPBA => 7
// GAMXVFLCZQPO => 1