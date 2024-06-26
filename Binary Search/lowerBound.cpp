#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

auto start = chrono::steady_clock::now();

int lowerBound(vector<int> arr, int n, int x)
{

    int left = 0;
    int right = n - 1;
    int ans = n;

    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (arr[mid] >= x)
        {
            ans = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return ans;
}

//! Alternative approach.

int lowerBounding(vector<int> &nums, int n, int x)
{
    if (nums[n - 1] < x)
    {
        return n;
    }
    else if (nums[0] > x)
    {
        return 0;
    }
    else
    {
        int left = 0;
        int right = n - 1;
        while (left < right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] < x)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
        return right;
    }
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8};

    cout << lowerBound(arr, arr.size(), 2);

    //   Compilation Time code //
    cout
        << endl;
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    return 0;
}