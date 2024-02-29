#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

auto start = chrono::steady_clock::now();

int search_in_rorated_sorted_array(vector<int> nums, int target)
{
    int n = nums.size();
    int left = 0;
    int right = n - 1;

    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (nums[mid] == target)
            return mid;
        if (nums[left] > nums[mid])
        {
            // right side sorted

            if (nums[mid] <= target && target <= nums[right])
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        else
        {
            // left side sorted.

            if (nums[left] <= target && target <= nums[mid])
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
    }
    return -1;
}

//! For Duplicate values

int search_in_rorated_sorted_array_duplicate(vector<int> nums, int target)
{
    int n = nums.size();
    int left = 0;
    int right = n - 1;

    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (nums[mid] == target)
            return true;
        if (nums[left] == nums[mid] && nums[mid] == nums[right])
        {
            left++;
            right--;
            continue;
        }
        if (nums[left] > nums[mid])
        {
            // right side sorted

            if (nums[mid] <= target && target <= nums[right])
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        else
        {
            // left side sorted.

            if (nums[left] <= target && target <= nums[mid])
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
    }
    return false;
}
int main()
{

    vector<int> nums = {7, 8, 9, 1, 2, 3, 4, 5, 6};
    cout << search_in_rorated_sorted_array(nums, 1);

    //   Compilation Time code //
    cout << endl;
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    return 0;
}