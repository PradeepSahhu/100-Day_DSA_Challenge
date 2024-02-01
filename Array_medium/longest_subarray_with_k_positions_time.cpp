#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

auto start = chrono::steady_clock::now();

int count_subArray_with_given_sum(vector<int> &v, int k)
{
    map<int, int> mpp;

    mpp[0] = 1;

    int preSum = 0, cnt = 0;

    for (int i = 0; i < v.size(); i++)
    {
        preSum += v[i];
        int remove = preSum - k;
        cnt += mpp[remove];
        mpp[preSum] = 1;
    }
    return cnt;
}
int main()
{

    vector<int> v = {1, 2, 3, -3, 1, 1, 1, 4, 2, -3};
    cout << count_subArray_with_given_sum(v, 3);

    //   Compilation Time code //
    cout << endl;
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    return 0;
}