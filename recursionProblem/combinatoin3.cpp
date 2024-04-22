#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

auto start = chrono::steady_clock::now();

void recursionCombinationThree(int index, int k, int target, vector<int> &ds, vector<vector<int>> &ans)
{

    if (target == 0 && ds.size() == k)
    {
        ans.push_back(ds);
        return;
    }

    for (int i = index; i<=target,i <= 9; i++)
    {
        ds.push_back(i);

        // picking

        recursionCombinationThree(i + 1, k, target - i, ds, ans);

        // not pick
        ds.pop_back();
    }
}

vector<vector<int>> combinationSum3(int k, int n)
{
    vector<int> ds;
    vector<vector<int>> ans;

    recursionCombinationThree(1, k, n, ds, ans);

    return ans;
}

int main()
{

    //   Compilation Time code //
    cout << endl;
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    return 0;
}