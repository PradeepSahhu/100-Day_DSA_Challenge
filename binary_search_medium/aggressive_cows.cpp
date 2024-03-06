#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

auto start = chrono::steady_clock::now();

//! This question is based upon finding the minimum distance between consecutive cows having maximum distance.🥲

bool canWePlace(vector<int> &stalls, int dist, int cows)
{
    int n = stalls.size();
    int cntCows = 1;
    int last = stalls[0];
    for (int i = 1; i < n; i++)
    {
        if (stalls[i] - last >= dist)
        {
            cntCows++;
            last = stalls[i];
        }
        if (cntCows >= cows)
            return true;
    }
    return false;
}
int aggressiveCows(vector<int> &stalls, int k)
{
    int n = stalls.size();

    sort(stalls.begin(), stalls.end());

    int low = 1, high = stalls[n - 1] - stalls[0];

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (canWePlace(stalls, mid, k) == true)
        {
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return high;
}

int main()
{
    vector<int> v = {0, 3, 4, 7, 10, 8};

    //   Compilation Time code //
    cout << endl;
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    return 0;
}