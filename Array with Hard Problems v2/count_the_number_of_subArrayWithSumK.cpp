#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

auto start = chrono::steady_clock::now();

//! only for positive numbers.
int longestSubarrayWithSumK(vector<int> a, long long k)
{

    int n = a.size();

    int maxlength = 0;
    map<long long, int> mpp;

    // better syntax and easy to understand however this doesn't give the garanteee of longest subarray.

    // for (int i = 0; i < a.size(); i++)
    // {
    //     summation += a[i];

    //     if (summation == k)
    //     {
    //         maxlength = i + 1;
    //     }
    //     long long rem = summation - k;
    //     if (mpp.find(rem) != mpp.end())
    //     {
    //         maxlength = max(maxlength, i - mpp[rem]);
    //     }
    //     if (mpp.find(rem) == mpp.end())
    //     {
    //         mpp[summation] = i;
    //     }
    // }

    int left = 0, right = 0;
    long long summation = a[0];
    while (right < n)
    {
        while (left < right && summation > k)
        {
            summation -= a[left];
            left++;
        }
        if (summation == k)
        {
            maxlength = max(maxlength, right - left + 1);
        }
        right++;

        if (right < n)
        {
            summation += a[right];
        }
    }
    // cout << length;
    return maxlength;
}

int maximum_length_ofSubarray_with_given_summation(vector<int> &nums, int k)
{ //! only for positive.

    //! works for both positive and negative
}

//! 2. Count the number of subArray with Sum k ( it works for all questions based on number of subarray with sum, subraction, multiplication, division or XOR)

int count_the_number_of_subArrayWithSumk_bruteForce(vector<int> &nums, int k)
{
    int n = nums.size();
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        int summation = nums[i];
        if (summation == k)
        {
            count++;
        }

        for (int j = i + 1; j < n; j++)
        {
            summation += nums[j];
            if (summation == k)
            {
                count++;
            }
        }
    }
    return count;
}

int count_the_number_of_subArrayWithSumk_betterApproach(vector<int> &nums, int k)
{
    int n = nums.size();
    int count = 0;
}
int main()
{
    vector<int> v = {1, 1, 1};
    cout << longestSubarrayWithSumK(v, 2);

    //   Compilation Time code //
    cout
        << endl;
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    return 0;
}