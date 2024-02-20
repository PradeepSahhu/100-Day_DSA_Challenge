#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

auto start = chrono::steady_clock::now();

int subArrayWithGivenSum(vector<int> &nums, int sum)
{
    //! Brute force approach(triple loop or double loop)
    int n = nums.size();
    int maxlen = 0;

    for (int i = 0; i < n; i++)
    {
        long long summation = 0;
        for (int j = i; j < n; j++)
        {
            summation += nums[j];
            if (summation == sum)
            {
                maxlen = max(maxlen, j - i + 1);
            }
        }
    }
    return maxlen;
}

int subArrayWithGivenSumBetter(vector<int> &a, long long k)
{
    //! Better Approach. ( by using the hashmap ) need to check -- Best approach for two pointer.
    int n = a.size();
    map<long long, int> preSumMap;

    long long maxy = 0;
    int maxlen = 0;

    for (int i = 0; i < n; i++)
    {
        maxy += a[i];

        if (maxy == k)
        {
            maxlen = max(maxlen, i + 1);
        }
        long long element = maxy - k;

        if (preSumMap.find(element) != preSumMap.end())
        {
            int length = i - preSumMap[element];

            maxlen = max(maxlen, length);
        }

        if (preSumMap.find(maxy) == preSumMap.end())
        {
            preSumMap[maxy] = i;
        }
    }
    return maxlen;
}

int subArrayWithGivenSumBest(vector<int> &a, long long k)
{
    //! Best Approach using two pointer Approach. (only positive values)

    int n = a.size();
    int left = 0, right = 0;
    long long summation = a[0];
    int maxLen = 0;

    while (right < n)
    {

        while (left <= right && summation > k)
        {

            summation -= a[left];
            left++;
        }
        if (summation == k)
        {
            maxLen = max(maxLen, right - left + 1);
        }
        right++;

        if (right < n)
            summation += a[right];
    }

    return maxLen;
}

int main()
{

    vector<int> v = {1, 2, 3, 1, 1, 1, 1};

    cout << subArrayWithGivenSumBest(v, 3);

    //   Compilation Time code //
    cout << endl;
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    return 0;
}