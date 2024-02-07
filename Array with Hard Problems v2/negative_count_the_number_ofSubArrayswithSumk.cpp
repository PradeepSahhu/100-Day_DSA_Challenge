#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

auto start = chrono::steady_clock::now();

int getLongestSubarray(vector<int> &nums, int k)
{
    // Write your code here

    int maxLen = 0;
    int n = nums.size();

    map<int, int> mpp;
    int preSum = 0;

    for (int i = 0; i < n; i++)
    {
        preSum += nums[i];

        if (preSum == k)
        {
            maxLen = max(maxLen, i + 1);
        }
        int rem = preSum - k;

        if (mpp.find(rem) != mpp.end())
        {
            maxLen = max(maxLen, i - mpp[rem] + 1);
        }
        if (mpp.find(preSum) == mpp.end())
        {
            mpp[preSum] = i;
        }
    }

    return maxLen;
}

int main()
{

    //   Compilation Time code //
    vector<int> v = {-1, 1, 1};

    cout << getLongestSubarray(v, 1);
    cout << endl;
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    return 0;
}