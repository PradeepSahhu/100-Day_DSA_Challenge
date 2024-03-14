#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

auto start = chrono::steady_clock::now();

double findMedianSortedArrays(vector<int> &a, vector<int> &b)
{
    int n = a.size();
    int m = b.size();

    vector<int> ans(n + m);
    std::merge(a.begin(), a.end(), b.begin(), b.end(), ans.begin());

    int index = (n + m) / 2;
    if (index % 2 == 0)
    {
        return (ans[index] + ans[index]) / 2;
    }
    return ans[index];
}

int main()
{

    vector<int> v = {1, 3};
    vector<int> v1 = {2};

    cout << findMedianSortedArrays(v, v1);

    //   Compilation Time code //
    cout
        << endl;
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    return 0;
}