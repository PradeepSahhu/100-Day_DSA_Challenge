#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

auto start = chrono::steady_clock::now();

vector<int> searchRange(vector<int> &nums, int target)
{
    if (std::find(nums.begin(), nums.end(), target) == nums.end())
    {
        return {-1, -1};
    }

    int lower_bound = (std::lower_bound(nums.begin(), nums.end(), target)) - nums.begin();
    int upper_bound = (std::upper_bound(nums.begin(), nums.end(), target)) - nums.begin();

    return {lower_bound, upper_bound - 1};
}

//! Better Approach.

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

            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return left;
}

int upperBound(vector<int> &arr, int n, int x)
{

    int left = 0;
    int right = n - 1;
    int ans = n;

    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (arr[mid] > x)
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
vector<int> searchRanges(vector<int> &nums, int target)
{

    int n = nums.size();

    int lb = lowerBound(nums, n, target);

    if (lb == n || nums[lb] != target)
        return {-1, -1};
    return {lb, upperBound(nums, n, target) - 1};
}
//! using pure binary search.

int firstIndex(vector<int> nums, int target)
{
    int n = nums.size();
    int left = 0;
    int right = n - 1;
    int first = -1;

    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (nums[mid] == target)
        {
            first = mid;
            right = mid - 1;
        }
        else if (nums[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return first;
}

int lastIndex(vector<int> nums, int target)
{
    int n = nums.size();
    int left = 0;
    int right = n - 1;
    int last = -1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (nums[mid] == target)
        {
            last = mid;
            left = mid + 1;
        }
        else if (nums[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return last;
}
int main()
{
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    vector<int> v = searchRange(nums, 6);
    for (auto it : v)
    {
        cout << it << " ";
    }

    //   Compilation Time code //
    cout << endl;
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    return 0;
}