#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

auto start = chrono::steady_clock::now();

int findingPeakOfArray(vector<int> &nums)
{
    //! brute force.
    int n = nums.size();
    for (int i = 0; i < nums.size(); i++)
    {
        if ((i == 0 || nums[i - 1] < nums[i]) && i == n - 1 || nums[i] > nums[i + 1])
        {
            return i;
        }
    }
    return -1;
}
//! Optimum solution.
int findPeakElement(vector<int> &arr)
{
    int n = arr.size(); // Size of array.

    // Edge cases:
    if (n == 1)
        return 0;
    if (arr[0] > arr[1])
        return 0;
    if (arr[n - 1] > arr[n - 2])
        return n - 1;

    int low = 1, high = n - 2;
    while (low <= high)
    {
        int mid = (low + high) / 2;

        // If arr[mid] is the peak:
        if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1])
            return mid;

        // If we are in the left:
        if (arr[mid] > arr[mid - 1])
            low = mid + 1;

        // If we are in the right:
        // Or, arr[mid] is a common point:
        else
            high = mid - 1;
    }
    // Dummy return statement
    return -1;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 5, 1};
    cout << findingPeakOfArray(nums);

    //   Compilation Time code //
    cout << endl;
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    return 0;
}