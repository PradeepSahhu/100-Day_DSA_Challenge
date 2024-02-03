#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

auto start = chrono::steady_clock::now();

//? Longest Sum Subarray with the sum equal to k

// vector<int> longest_sum(vector<int> &v, int k)
// {
//     // vector<vector<int>> allv;
//     vector<int> arr;
//     vector<int> sub;
//     for (int i = 0; i < v.size(); i++)
//     {
//         sub.push_back(v[i]);
//         allv.push_back(sub);

//         for (int j = i + 1; j < v.size(); j++)
//         {
//             // pushing the elements in to the subarray.
//             for (int k = i; k <= j; k++)
//             {
//                 arr.push_back(v[k]);
//             }

//             allv.push_back(arr);
//             arr.clear();
//             sub.clear();
//         }
//     }

//     for (auto it : allv)
//     {
//         cout << '[';

//         for (int i = 0; i < it.size(); i++)
//         {
//             cout << it[i];
//         }
//         cout << ']' << endl;
//     }

//     int sum = 0;

//     // then i am calculating the sum of the subarray.

//     for (auto it : allv)
//     {
//         // cout << " this is first loop" << endl;
//         for (int i = 0; i < it.size(); i++)
//         {
//             // cout << it[i] << " this is second loop" << endl;
//             sum += it[i]; // here.
//         }
//         if (sum == k)
//         {
//             return it;
//         }
//         sum = 0;
//     }
// }

vector<int> longest_sum_subarray(vector<int> &v, int k)
{

    int sum = 0;
    vector<int> ans;

    // better syntax and easy to understand however this doesn't give the garanteee of longest subarray.

    for (int i = 0; i < v.size(); i++)
    {
        // for (int j = i+1;j<v.size();j++)
        for (int j = i; j < v.size(); j++)
        {
            // for(int k = i;k<j;k++)
            for (int k = i; k <= j; k++)
            {
                ans.push_back(v[k]);
                sum += v[k];
            }

            if (sum == k)
            {
                return ans;
            }
            sum = 0;
            ans.clear();
        }
    }
}

void longest_sum_length(vector<int> &v, int l)
{

    int length = 0;

    // better syntax and easy to understand however this doesn't give the garanteee of longest subarray.

    for (int i = 0; i < v.size(); i++)
    {
        for (int j = i; j < v.size(); j++)
        {
            int sum = 0;
            for (int k = i; k <= j; k++)
            {
                sum += v[k];
            }
            cout << "the value of j is : " << j << endl;

            if (sum == l)
            {
                cout << "the value of length is : " << length << endl;
                length = max(length, j - i + 1);
                cout << "the value of length is : " << length << endl;
            }
        }
    }
    cout << length;
}

void optimised_longest_sum(vector<int> &v, int l)
{

    // time complexity of this approach is : O(n^2)
    int length = 0;
    for (int i = 0; i < v.size(); i++)
    {
        int sum = 0;
        for (int j = i; j < v.size(); j++)
        {
            sum += v[j];
            if (sum == l)
            {
                length = max(length, j - i + 1);
            }
        }
    }
    cout << length;
}

// Better approach.
void hash_map_approach(vector<int> &v, int l)
{
    long long sum = 0;
    int maxLen = 0;
    map<long, long> mpp;
    for (int i = 0; i < v.size(); i++)
    {
        sum += v[i];

        if (sum == l)
        {
            maxLen = max(maxLen, i + 1);
        }

        int rem = sum - l;
        // if the rem is present in the map.
        if (mpp.find(rem) != mpp.end())
        {
            int len = i - mpp[rem]; // this will return the key i.e. index of the rem value.
            maxLen = max(maxLen, len);
        }
        if (mpp.find(sum) == mpp.end()) // if the current sum is not already existing in the map.(left most element)
        {
            mpp[sum] = i; // we are setting the key. through value mpp[18] = 0...12;
        }
    }

    // for (auto it : mpp)
    // {
    //     cout << it.first << " " << it.second << endl;
    // }
    cout << maxLen;
}

// most optimum solution ( 2 pointer approach)

void most_optimum_largest_subarray(vector<int> &v, int k)
{
    int left = 0;
    int right = 0;
    int sum = v[0];
    int length = 0;

    for (int l = 1; l < v.size(); l++)
    {
        // while(right < v.size())
        while (left <= right && sum > k)
        {

            sum -= v[left];
            left++;
        }
        if (sum == k)
        {
            length = max(length, right - left + 1);
        }

        right++;
        sum += v[right];
    }
    cout << (length);
}
int main()
{

    int arr[] = {1, 2, 3, 3, 1, 1, 1, 6, 9, 10};
    int size = sizeof(arr) / sizeof(arr[0]);

    vector<int> v(arr, arr + size);
    // vector<int> ans = longest_sum_subarray(v, 10);

    // longest_sum_length(v, 10);
    hash_map_approach(v, 6);
    // most_optimum_largest_subarray(v, 6);

    // for (int i = 0; i < ans.size(); i++)
    // {
    //     cout << ans[i] << " ";
    // }

    //   Compilation Time code //
    cout << endl;
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    return 0;
}