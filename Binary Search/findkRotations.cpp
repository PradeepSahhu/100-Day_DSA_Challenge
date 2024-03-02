#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

auto start = chrono::steady_clock::now();

//! worked.
int findkRotations(vector<int> &arr)
{
    int n = arr.size();
    int left = 0;
    int right = n - 1;
    int minIndex = n - 1;

    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (arr[left] <= arr[mid])
        {
            // left side is sorted.
            if (arr[left] < arr[minIndex])
            {
                minIndex = left;
            }
            left = mid + 1;
        }
        else
        {
            if (arr[mid] < arr[minIndex])
            {
                minIndex = mid;
            }
            right = mid - 1;
        }
    }
    return minIndex;
}
int main()
{

    // vector<int> nums = {3, 4, 5, 1, 2};
    vector<int> nums = {1, 2, 3};
    cout << findkRotations(nums);

    //   Compilation Time code //
    cout << endl;
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    return 0;
}