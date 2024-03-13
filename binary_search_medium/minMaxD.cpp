#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

auto start = chrono::steady_clock::now();

//! Brute force Approach.

long double placeGasStations(vector<int> v, int k)
{
    int n = v.size();

    vector<int> howMany(n - 1, 0);

    for (int gas = 1; gas <= k; gas++)
    {
        long double maxSection = -1;
        int maxInd = -1;
        for (int i = 0; i < n - 1; i++)
        {
            long double diff = v[i + 1] - v[i];
            long double sectionLen = diff / (long double)(howMany[i] + 1);
            if (maxSection < sectionLen)
            {
                maxSection = sectionLen;
                maxInd = i;
            }
        }
        howMany[maxInd]++;
    }

    long double maxAns = -1;

    for (int i = 0; i < n - 1; i++)
    {
        long double diff = (v[i + 1] - v[i]);
        long double sectionLen = diff / (long double)(howMany[i] + 1);
        maxAns = max(maxAns, sectionLen);
    }

    return maxAns;
}

//! Better Approach.

long double putGasStations(vector<int> &v, int k)
{
    int n = v.size();
    vector<int> howMany(n - 1, 0);

    priority_queue<pair<long double, int>> pq;

    for (int i = 0; i < n - 1; i++)
    {
        pq.push({(long double)(v[i + 1] - v[i]), i});
    }

    for (int gasStations = 1; gasStations <= k; gasStations++)
    {

        long double maxSectionLen = pq.top().first;
        int maxInd = pq.top().second;
        pq.pop();
        howMany[maxInd]++;

        long double iniDiff = (long double)v[maxInd + 1] - v[maxInd];
        long double newSecDiff = iniDiff / (long double)(howMany[maxInd] + 1);

        pq.push({newSecDiff, maxInd});
    }

    return pq.top().first;
}

int main()
{

    vector<int> v = {1, 2, 3, 4, 5, 6, 7};
    cout << placeGasStations(v, 6);

    //   Compilation Time code //
    cout << endl;
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    return 0;
}
int numberOfGasStationsRequired(long double dist, vector<int> &arr)
{
    int n = arr.size(); // size of the array
    int cnt = 0;
    for (int i = 1; i < n; i++)
    {
        int numberInBetween = ((arr[i] - arr[i - 1]) / dist);
        if ((arr[i] - arr[i - 1]) == (dist * numberInBetween))
        {
            numberInBetween--;
        }
        cnt += numberInBetween;
    }

    return cnt;
}

long double minimiseMaxDistance(vector<int> &arr, int k)
{
    int n = arr.size(); // size of the array
    long double low = 0;
    long double high = 0;

    // Find the maximum distance:
    for (int i = 0; i < n - 1; i++)
    {
        high = max(high, (long double)(arr[i + 1] - arr[i]));
    }

    // Apply Binary search:
    long double diff = 1e-6;
    while (high - low > diff)
    {
        long double mid = (low + high) / (2.0);
        int cnt = numberOfGasStationsRequired(mid, arr);
        if (cnt > k)
        {
            low = mid;
        }
        else
        {
            high = mid;
        }
    }
    return high;
}