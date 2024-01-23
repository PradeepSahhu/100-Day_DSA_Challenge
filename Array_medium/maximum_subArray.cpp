#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

auto start = chrono::steady_clock::now();

// int maximum_subArray(vector<int> &v)
// {
//     int max_number = INT_MIN;
//     for (int i = 0; i < v.size(); i++)
//     {
//         int current_max = 0;
//         for (int j = i; j < v.size(); j++)
//         {
//             current_max += v[j];
//             max_number = max(current_max, max_number); // after each iteration : checking if the max is the current max;
//         }
//     }
//     return max_number;
// }

//! most optimized approach : kadene's algorithm.

// int maximum_subArray(vector<int> &v)
// {
//     int max_number = INT_MIN;
//     int sum = 0;

//     for (int i = 0; i < v.size(); i++)
//     {
//         sum += v[i];
//         max_number = max(sum, max_number);

//         if (sum < 0)
//         {
//             sum = 0;
//         }
//     }
//     return max_number;
// }

//! returning the index of the maximum_subarray.

vector<int> maximum_subArray(vector<int> &v)
{
    int max_number = INT_MIN;
    int sum = 0;
    int start = -1;

    int ansStart = -1;
    int ansEnd = -1;

    for (int i = 0; i < v.size(); i++)
    {
        if (sum == 0)
        {
            start = i;
        }
        sum += v[i];
        if (max_number < sum)
        {
            max_number = sum;
            ansStart = start;
            ansEnd = i;
        }
        // max_number = max(sum, max_number);

        if (sum < 0)
        {
            sum = 0;
        }
    }
    vector<int> ans;
    // cout << start << endl;
    // cout << ansStart << ansEnd << endl;
    ans.push_back(ansStart);
    ans.push_back(ansEnd);
    return ans;
}

int main()
{

    int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};

    int size = sizeof(arr) / sizeof(arr[0]);

    vector<int> v(arr, arr + size);
    // cout << maximum_subArray(v);
    vector<int> ans = maximum_subArray(v);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    //   Compilation Time code //
    cout << endl;
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    return 0;
}