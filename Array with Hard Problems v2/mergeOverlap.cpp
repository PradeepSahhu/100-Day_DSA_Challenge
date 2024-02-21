#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

auto start = chrono::steady_clock::now();

// vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &arr)
// {

//     // Write your code here.

//     int n = arr.size();

//     // brute force approach

//     vector<vector<int>> ans;

//     for (int i = 0; i < n - 1; i++)
//     {

//         if (arr[i][1] > arr[i + 1][0])
//         {
//             vector<int> temp = {arr[i][0], arr[i + 1][1]};
//             ans[i] = temp;
//             arr.erase(arr.begin() + (i + 1));
//         }
//     }
//     return arr;
// }

vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &arr)
{
    int n = arr.size();
    vector<vector<int>> ans;

    // Sort the intervals based on the start time
    sort(arr.begin(), arr.end()); //! sorting according to elements of the range

    for (int i = 0; i < n; ++i)
    {
        int start = arr[i][0];
        int end = arr[i][1];

        // Merge overlapping intervals
        while (i < n - 1 && end >= arr[i + 1][0])
        {
            end = max(end, arr[i + 1][1]);
            ++i;
        }

        ans.push_back({start, end});
    }

    return ans;
}

vector<vector<int>> mergeOverlapIntervals(vector<vector<int>> &nums)
{
    // int n = nums.size();
    // sort(nums.begin(), nums.end());
    // vector<vector<int>> ans;

    // for (int i = 0; i < n; i++)
    // {
    //     int start = nums[i][0];
    //     int end = nums[i][1];
    //     while (i < n - 1 && end >= nums[i + 1][0])
    //     {
    //         end = max(end, nums[i + 1][1]);
    //         i++;
    //     }
    //     ans.push_back({start, end});
    // }
    // return ans;

    //! Brute Force Approach.

    int n = nums.size();

    sort(nums.begin(), nums.end());

    vector<vector<int>> ans;

    for (int i = 0; i < n; i++)
    {
        int start = nums[i][0];
        int end = nums[i][1];

        //     if (!ans.empty() && end <= ans.back()[1])
        //     {
        //         continue;
        //     }

        //     for (int j = i + 1; j < n; j++)
        //     {

        //         if (end > nums[j][0])
        //         {
        //             end = max(end, nums[j][1]);
        //         }
        //         else
        //         {
        //             break;
        //         }
        //     }
        //     ans.push_back({start, end});
        // }

        for (int i = 0; i < n; i++)
        {

            if (ans.empty() || ans.back()[1] < nums[i][0])
            {
                ans.push_back(nums[i]);
            }
            else
            {
                ans.back()[1] = max(ans.back()[1], nums[i][1]);
            }
        }
        return ans;
    }
}

int main()
{

    vector<vector<int>> v = {{1, 6}, {1, 2}, {1, 3}, {3, 4}, {4, 4}, {4, 5}, {5, 5}, {6, 6}, {6, 6}};

    // sort(v.begin(), v.end());

    vector<vector<int>> ans = mergeOverlapIntervals(v);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << ", ";
        }
        cout << endl;
    }

    //   Compilation Time code //
    cout << endl;
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    return 0;
}