#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

auto start = chrono::steady_clock::now();

//! Iterative Approach
int binary_search(vector<int> &nums, int target)
{
    int n = nums.size();

    int left = 0, right = n - 1;

    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (nums[mid] == target)
        {
            return mid;
        }
        else if (nums[mid] > target)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return -1;
}

//! Recrusive approach.

int binarySearch(vector<int> &nums, int left, int right, int target)
{

    if (left > right)
        return -1;

    int mid = (left + right) / 2;

    if (nums[mid] == target)
    {
        return mid;
    }
    else if (nums[mid] > target)
    {
        right = mid - 1;
        return binarySearch(nums, left, mid - 1, target);
    }
    return binarySearch(nums, mid + 1, right, target);
}

int binary_searching(vector<int> &nums, int target)
{
    int n = nums.size();
    int left = 0;
    int right = n - 1;
    return binarySearch(nums, left, right, target);
}
int main()
{

    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << binary_searching(nums, 8);

    //   Compilation Time code //
    cout << endl;
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    return 0;
}