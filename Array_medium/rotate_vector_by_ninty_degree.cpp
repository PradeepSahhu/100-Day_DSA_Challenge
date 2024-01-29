#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

auto start = chrono::steady_clock::now();

void rotate_ninty_degree(vector<vector<int>> &nums)
{
    int row = nums.size();
    int col = nums[0].size();

    vector<vector<int>> ans(row, vector<int>(col, 0));

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            ans[j][row - 1 - i] = nums[i][j];
        }
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            nums[i][j] = ans[i][j];
        }
    }
}

void alternative_best_approach(vector<vector<int>> &nums)
{
    int row = nums.size();
    int col = nums[0].size();
    vector<vector<int>> ans(row, vector<int>(col, 0));

    for (int i = 0; i < row; i++)
    {
        for (int j = i + 1; j < col; j++)
        {
            swap(nums[i][j], nums[j][i]);
        }
    }

    for (int i = 0; i < row; i++)
    {

        reverse(nums[i].begin(), nums[i].end());
    }
}

int main()
{

    vector<vector<int>> v = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}};

    alternative_best_approach(v);

    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }

    //   Compilation Time code //
    cout
        << endl;
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    return 0;
}