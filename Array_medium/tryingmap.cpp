#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

auto start = chrono::steady_clock::now();
int main()
{
    vector<int> v = {1, 2, 3};

    map<int, int> mpp;

    for (int i = 0; i < 10; i++)
    {
        mpp[i * 2 + 3] = i;
    }

    for (auto &it : mpp)
    {
        // it.first = it.first + 4;
        cout << it.first << "--> " << it.second << endl;
    }
    //   Compilation Time code //
    cout << endl;
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    return 0;
}