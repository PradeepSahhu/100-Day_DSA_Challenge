#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

auto start = chrono::steady_clock::now();

int upperBound(vector<int> &arr, int x, int n)
{
    // Write your code here.

    if (arr[n - 1] < x)
    {
        return n;
    }
    else if (arr[0] > x)
    {
        return 0;
    }
    else
    {
        int left = 0;
        int right = n - 1;
        int ans = n;

        while (left <= right)
        {
            int mid = (left + right) / 2;

            if (arr[mid] <= x)
            {
                ans = mid + 1;
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return ans;
    }
}

//! Alternative Solution

int upperbounding(vector<int> &nums, int x, int n)
{
    int left = 0;
    int right = n - 1;
    int ans = 0;

    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (nums[mid] <= x)
        {
            ans = mid + 1;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return ans;
}
int main()
{

    vector<int> nums = {1, 4, 7, 8, 10};
    cout << upperbounding(nums, nums.size(), 4);

    //   Compilation Time code //
    cout << endl;
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    return 0;
}