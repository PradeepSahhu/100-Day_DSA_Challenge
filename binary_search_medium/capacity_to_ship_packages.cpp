#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

auto start = chrono::steady_clock::now();

int calDays(vector<int> &v, int mid)
{
    int totalCargo = 0;
    int daysTook = 0;
    for (auto it : v)
    {
        if ((totalCargo + it) <= mid)
        {
            totalCargo += it;
        }
        else
        {
            daysTook++;
            totalCargo = it;
        }
    }
    daysTook++;
    return daysTook;
}

int shipWithinDays(vector<int> &weights, int days)
{
    int n = weights.size();
    int left = *std::max_element(weights.begin(), weights.end());
    int right = accumulate(weights.begin(), weights.end(), 0);
    // cout << "The value of left is " << left << endl;
    // cout << "The vlaue of right is " << right << endl;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        int t_days = calDays(weights, mid);
        // cout << "the value of mid is " << mid << "and " << t_days << endl;
        if (t_days <= days)
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
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << shipWithinDays(v, 5);

    //   Compilation Time code //
    cout << endl;
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    return 0;
}