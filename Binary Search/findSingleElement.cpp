#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

auto start = chrono::steady_clock::now();

int singleElement(vector<int> &nums)
{
    int n = nums.size();

    int left = 1;
    int right = n - 2;
    if (n == 1)
    {
        return nums[0];
    }
    if (nums[0] != nums[1])
        return nums[0];
    if (nums[n - 1] != nums[n - 2])
        return nums[n - 1];

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (nums[mid - 1] != nums[mid] && nums[mid] != nums[mid + 1])
        {
            return nums[mid];
        }

        if (mid % 2 != 0 && nums[mid - 1] == nums[mid] || (mid % 2 == 0) && nums[mid] == nums[mid + 1])
        {

            left = mid + 1;
        }
        else
        {

            right = mid - 1;
        }
    }
    return -1;
}
int main()
{

    vector<int> nums = {1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6};
    cout << singleElement(nums);
    //   Compilation Time code //
    cout << endl;
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    return 0;
}