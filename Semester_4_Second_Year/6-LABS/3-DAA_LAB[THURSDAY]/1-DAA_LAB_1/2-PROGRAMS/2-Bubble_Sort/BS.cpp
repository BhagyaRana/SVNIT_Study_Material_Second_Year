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

// Basic Algorithm Implementation of Bubble Sort
void bubble_sort(vll &arr)
{
    ll n = arr.size(), i, j, tmp;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

int main()
{
    // For Read & Write from "Input File" and  Return Output to "Output" File
    freopen("output.txt", "a+", stdout);

    // EDIT THIS FILE NUMBER , LIMIT and Number of Times File Runs
    int file_no = 1;
    int limit = 5;
    int each_file_runs = 2;

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

        ll number, idx = 0;
        while (!File.eof())
        {
            File >> number;
            arr.push_back(number);
        }

        ll Best_Duration = 0, Worst_Duration = 0, Average_Duration = 0;
        auto start = high_resolution_clock::now();
        auto end = high_resolution_clock::now();
        auto time_taken = duration_cast<nanoseconds>(end - start);
        for (int f = 0; f < each_file_runs; f++)
        {
            // -------------------------AVERAGE CASE [O(n^2)]-----------------------------

            start = high_resolution_clock::now();
            // Function Here
            bubble_sort(arr);
            // Function Ends here
            end = high_resolution_clock::now();
            time_taken = duration_cast<nanoseconds>(end - start);
            Average_Duration += time_taken.count();

            // -------------------------BEST CASE [0(n)]-----------------------------
            // The Array is Already Sorted from Average Case, So it Becomes out Best Case
            // sort(arr.begin(), arr.end());
            start = high_resolution_clock::now();
            // Function Here
            bubble_sort(arr);
            // Function Ends here
            end = high_resolution_clock::now();
            time_taken = duration_cast<nanoseconds>(end - start);
            Best_Duration += time_taken.count();

            // -------------------------WORST CASE [0(n^2)]-----------------------------
            // This will Reverse the Sorted Array, Therfore we will Get the Worst Case

            reverse(arr.begin(), arr.end());
            // sort(arr.begin(), arr.end(), greater<ll>());
            start = high_resolution_clock::now();
            // Function Here
            bubble_sort(arr);
            // Function Ends here
            end = high_resolution_clock::now();
            time_taken = duration_cast<nanoseconds>(end - start);
            Worst_Duration += time_taken.count();
        }

        cout << "--------------------------------------------------------" << endl;
        cout << inp_file << endl;
        cout << "AVERAGE CASE : ";
        double avg = (double)Average_Duration / (double)each_file_runs;
        avg *= 1e-9;
        cout << fixed << avg << setprecision(9);
        cout << " seconds" << endl;
        cout << "BEST CASE    : ";
        double best = (double)Best_Duration / (double)each_file_runs;
        best *= 1e-9;
        cout << fixed << best << setprecision(9);
        cout << " seconds" << endl;
        cout << "WORST CASE   : ";
        double worst = (double)Worst_Duration / (double)each_file_runs;
        worst *= 1e-9;
        cout << fixed << worst << setprecision(9);
        cout << " seconds" << endl;
    }

    return 0;
}
