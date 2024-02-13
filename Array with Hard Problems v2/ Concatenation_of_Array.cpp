#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

auto start = chrono::steady_clock::now();

vector<int> getConcatenation(vector<int> &nums)
{
    vector<int> v;
    for (int i = 0; i < nums.size(); i++)
    {
        v.push_back(nums[i]);
    }
    for (int i = 0; i < nums.size(); i++)
    {
        v.push_back(nums[i]);
    }
    return v;
}

int main()
{

    vector<int> v = {1, 2, 4};
    vector<int> ans = getConcatenation(v);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    //   Compilation Time code //
    cout << endl;
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    return 0;
}