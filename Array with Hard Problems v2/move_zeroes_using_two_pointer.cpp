#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

auto start = chrono::steady_clock::now();

// problem solved

void moveZeroes(vector<int> &nums)
{

    int n = nums.size();
    int i = 0;
    int j = 0;

    while (j < n)
    {
        if (nums[j] != 0)
        {
            swap(nums[i], nums[j]);
            i++;
            j++;
        }
        else
        {
            j++;
        }
    }
}
int main()
{

    vector<int> v = {1, 0, 3, 0, 12};
    moveZeroes(v);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }

    //   Compilation Time code //
    cout << endl;
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    return 0;
}