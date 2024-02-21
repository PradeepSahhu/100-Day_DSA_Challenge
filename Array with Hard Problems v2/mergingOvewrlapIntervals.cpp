#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

auto start = chrono::steady_clock::now();

vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &arr)
{

    // Write your code here.

    int n = arr.size();

    // brute force approach

    vector<vector<int>> ans;

    for (int i = 0; i < n - 1; i++)
    {

        if (arr[i][1] > arr[i + 1][0])
        {
            vector<int> temp = {arr[i][0], arr[i + 1][1]};
            ans[i] = temp;
            arr.erase(arr.begin() + (i + 1));
        }
    }
    return arr;
}
int main()
{

    vector<vector<int>> v = {{1, 2}, {1, 3}, {1, 6}, {3, 4}, {4, 4}, {4, 5}, {5, 5}, {6, 6}, {6, 6}};

    vector<vector<int>> ans = mergeOverlappingIntervals(v);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << ", ";
        }
        cout << endl;
    }

    //   Compilation Time code //
    cout << endl;
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    return 0;
}