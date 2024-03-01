#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

auto start = chrono::steady_clock::now();

int search_in_rorated_sorted_array(vector<int> &arr)
{
    int n = arr.size();
    int minimum = INT_MAX;

    int left = 0;
    int right = n - 1;

    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (arr[mid] < minimum)
        {
            minimum = arr[mid];
        }
        if (arr[left] <= arr[right])
        {
            // left side sorted
            if (arr[left] < minimum && minimum < arr[mid])
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        else
        {
            // right side sorted
            if (arr[mid] < minimum && minimum < arr[right])
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
    }
    return minimum;
}
int main()
{
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};

    //   Compilation Time code //
    cout << endl;
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    return 0;
}