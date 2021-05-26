// HEADERS AND NAMESPACE
#include <bits/stdc++.h>
// INSTEAD OF ALL THESE
#include <iostream>
// For Creating File
#include <fstream>
#include <vector>
// For set - precision
#include <iomanip>
// For Time Calculation
#include <chrono>
// For File Name and Output File Name
#include <string>

using namespace std;
using namespace std::chrono;

// COMMONLY USED TYPES
typedef long long ll;
typedef vector<ll> vll;

#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)

// Greedy Method Of Solving the Problem
ll Greedy_Jump(vll nums, ll n)
{
    int previous = 0;
    int current = 0;
    int jumps = 0;
    for (int i = 0; i < n; i++)
    {
        if (i > previous)
        {
            jumps = jumps + 1;
            previous = current;
            if (i > current)
                return -1;
        }
        current = max(current, i + nums[i]);
    }
    return jumps;
}

// DP Method of Solving the Problem
ll DP_Jump(vll nums, ll n)
{
    vll jumps(n, 0);
    int i, j;

    // Edge Cases
    if (n == 0 || nums[0] == 0)
        return -1;

    // Minimum Jumps to Reach jumps[0] = 0 [You are Already Standing There!]
    jumps[0] = 0;

    // Find the minimum number of jumps to reach nums[i] from nums[0],
    // and assign this value to jumps[i]
    for (i = 1; i < n; i++)
    {
        jumps[i] = INT_MAX;
        for (j = 0; j < i; j++)
        {
            if (i <= j + nums[j] && jumps[j] != INT_MAX)
            {
                jumps[i] = min(jumps[i], jumps[j] + 1);
                break;
            }
        }
    }

    // If Final Answer is INT_MAX -> No Way to Reach End Otherwise Answer Exist
    return (jumps[n - 1] == INT_MAX) ? -1 : jumps[n - 1];
}

int main()
{
    // For Read & Write from "Input File" and  Return Output to "Output" File
    freopen("output.txt", "w", stdout);

    // EDIT THIS FILE NUMBER , LIMIT and Number of Times File Runs
    int file_no = 1;
    int limit = 10;
    int each_file_runs = 1;

    for (; file_no <= limit; file_no++)
    {
        string inp_file = "File";
        string num = to_string(file_no);
        string ext = ".txt";
        inp_file += num;
        inp_file += ext;

        ifstream File;
        File.open(inp_file);

        vector<ll> arr;

        ll number;
        while (!File.eof())
        {
            File >> number;
            arr.push_back(number);
        }

        ll DP_Duration = 0;
        ll Greedy_Duration = 0;
        auto start = high_resolution_clock::now();
        auto end = high_resolution_clock::now();
        auto time_taken = duration_cast<nanoseconds>(end - start);

        ll n = arr.size();

        for (int f = 0; f < each_file_runs; f++)
        {
            // DP
            start = high_resolution_clock::now();
            // Function Here
            ll dp_ans = DP_Jump(arr, n);
            // Function Ends here
            end = high_resolution_clock::now();
            time_taken = duration_cast<nanoseconds>(end - start);
            DP_Duration += time_taken.count();

            // Greedy
            start = high_resolution_clock::now();
            // Function Here
            ll greedy_ans = Greedy_Jump(arr, n);
            // Function Ends here
            end = high_resolution_clock::now();
            time_taken = duration_cast<nanoseconds>(end - start);
            Greedy_Duration += time_taken.count();

            // For Checking Purpose
            if (dp_ans != greedy_ans)
            {
                cout << inp_file << endl;
                cout << "WRONG ANSWER!" << endl;
            }
        }

        cout << "--------------------------------------------------------" << endl;
        cout << inp_file << endl;

        cout << "TIME TAKEN (DP): ";
        double avg = (double)DP_Duration / (double)each_file_runs;
        avg *= 1e-9;
        cout << fixed << avg << setprecision(9);
        cout << " seconds" << endl;

        cout << "TIME TAKEN (GREEDY): ";
        double avg2 = (double)Greedy_Duration / (double)each_file_runs;
        avg2 *= 1e-9;
        cout << fixed << avg2 << setprecision(9);
        cout << " seconds" << endl;
    }

    return 0;
}
