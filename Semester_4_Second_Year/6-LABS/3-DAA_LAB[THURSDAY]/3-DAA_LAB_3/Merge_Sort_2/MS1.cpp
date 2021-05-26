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

// Basic Algorithm Implementation of Merge Sort
// To Merge Two Sorted Array
void merge(vll &arr, ll low, ll mid, ll high)
{
    // Create a Temp Array
    vll tmp(high - low + 1, 0);

    // Crawlers for Temp
    ll i = low, j = mid + 1, k = 0;

    while (i <= mid && j <= high)
    {
        if (arr[i] <= arr[j])
        {
            tmp[k] = arr[i];
            k++;
            i++;
        }
        else
        {
            tmp[k] = arr[j];
            k++;
            j++;
        }
    }

    // Remaining Elements in Second Interval
    while (i <= mid)
    {
        tmp[k] = arr[i];
        i++;
        k++;
    }

    // Remaining Elements in Second Interval
    while (j <= high)
    {
        tmp[k] = arr[j];
        j++;
        k++;
    }

    // Copy Temp Array to Original Array
    for (i = low; i <= high; i++)
    {
        arr[i] = tmp[i - low];
    }
}

// Real Merge Sort Function
void merge_sort(vll &arr, ll low, ll high)
{

    if (low < high)
    {
        ll mid = low + (high - low) / 2; // To Avoid Overflow
        // Call this Function to Recursively Divide into Smaller Sub-array [l,m]
        merge_sort(arr, low, mid);
        // Call this Function to Recursively Divide into Smaller Sub-array [m+1,h]
        merge_sort(arr, mid + 1, high);
        // Merge the Both Sorted Array
        merge(arr, low, mid, high);
    }

    return;
}

int main()
{
    // For Read & Write from "Input File" and  Return Output to "Output" File
    freopen("output.txt", "w", stdout);

    // EDIT THIS FILE NUMBER , LIMIT and Number of Times File Runs
    int file_no = 1;
    int limit = 10;
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
        ll n1 = arr.size();
        for (int f = 0; f < each_file_runs; f++)
        {
            // -------------------------AVERAGE CASE [O(n^2)]-----------------------------

            start = high_resolution_clock::now();
            // Function Here
            merge_sort(arr, 0, arr.size() - 1);
            // Function Ends here
            end = high_resolution_clock::now();
            time_taken = duration_cast<nanoseconds>(end - start);
            Average_Duration += time_taken.count();

            // -------------------------BEST CASE [0(n^2)]-----------------------------
            // The Array is Already Sorted from Average Case, So it Becomes out Best Case
            // sort(arr.begin(), arr.end());
            start = high_resolution_clock::now();
            // Function Here
            merge_sort(arr, 0, arr.size() - 1);
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
            merge_sort(arr, 0, arr.size() - 1);
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
