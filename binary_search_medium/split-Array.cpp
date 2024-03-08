#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

auto start = chrono::steady_clock::now();

int countPartitions(vector<int> &a, int maxSum)
{
    int n = a.size();
    int partitions = 1;
    long long subarraySum = 0;
    for (int i = 0; i < n; i++)
    {
        if (subarraySum + a[i] <= maxSum)
        {

            subarraySum += a[i];
        }
        else
        {

            partitions++;
            subarraySum = a[i];
        }
    }
    return partitions;
}

int splitArray(vector<int> &a, int k)
{
    int low = *max_element(a.begin(), a.end());
    int high = accumulate(a.begin(), a.end(), 0);

    while (low <= high)
    {
        int mid = (low + high) / 2;
        int partitions = countPartitions(a, mid);
        if (partitions > k)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return low;
}
int main()
{

    vector<int> v = {1, 2, 3};

    //   Compilation Time code //
    cout << endl;
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    return 0;
}