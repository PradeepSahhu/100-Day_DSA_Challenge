#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

auto start = chrono::steady_clock::now();
int main()
{

    // map practice.

    map<long, long> mpp;

    int arr[] = {1, 2, 4, 1, 2, 1, 2, 1, 4, 1, 4, 6, 9};
    int size = sizeof(arr) / sizeof(arr[0]);

    vector<int> v(arr, arr + size);

    int sum = 0;

    for (int i = 0; i < v.size(); i++)
    {
        sum += v[i];

        mpp[sum] = i;
    }

    for (auto it : mpp)
    {
        cout << it.first << "-> " << it.second << endl;
    }

    if (mpp.find(18) != mpp.end())
    {
        cout << "The value is : " << mpp[18];
    }
    //   Compilation Time code //
    cout << endl;
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    return 0;
}