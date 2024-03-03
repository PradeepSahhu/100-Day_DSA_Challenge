#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

auto start = chrono::steady_clock::now();


int maxelement(vector<int> nums)
{
    int maxi = INT_MIN;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, nums[i]);
    }
    return maxi;
}

int timeReq(vector<int> &v, int hourly)
{
    int n = v.size();
    int totalH = 0;

    for (int i = 0; i < n; i++)
    {
        totalH += ceil((double)(v[i]) / (double)(hourly));
    }
    return totalH;
}

int koko_eating_banana(vector<int> &piles, int h)
{

    int left = 1;

    int right = maxelement(piles); // find the maximum element.
    while (left <= right)
    {
        long long mid = (left + right) / 2;
        int total_time_required = timeReq(piles, mid);
        if (total_time_required <= h)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return left;
}
int main()
{
    vector<int> piles = {3, 6, 7, 11};
    cout << koko_eating_banana(piles, 8);
    // cout << timeReq(piles, 4, piles.size());

    //   Compilation Time code //
    cout << endl;
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    return 0;
}