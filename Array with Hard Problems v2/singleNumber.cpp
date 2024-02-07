#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

auto start = chrono::steady_clock::now();

int singleNumber(vector<int> &nums)
{
    // sort(nums.begin(), nums.end());
    // int n = nums.size();
    // int ele;
    // int j = 1;

    // for (int i = 0; i < n; i++)
    // {

    //     if (nums[i] == nums[j])
    //     {
    //         j++;
    //         continue;
    //     }
    //     ele = nums[i];
    // }
    // return ele;

    int n = nums.size();
    int xors = 0;

    for (int i = 0; i < n; i += 2)
    {

        xors ^= nums[i];
    }
    return xors;
}
int main()
{
    vector<int> v = {2, 2, 1};
    cout << singleNumber(v);

    //   Compilation Time code //
    cout << endl;
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    return 0;
}