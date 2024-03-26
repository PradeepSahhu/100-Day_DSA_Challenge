#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

auto start = chrono::steady_clock::now();

// Question link : https://leetcode.com/problems/search-a-2d-matrix-ii/description/

bool searchMatrixRowAndCol(vector<vector<int>> &nums, int target)
{
    int n = nums.size();
    int m = nums[0].size();

    int row = 0, col = m - 1;

    while (row < n && col >= 0)
    {
        if (nums[row][col] == target)
        {
            return true;
        }
        else if (nums[row][col] > target)
        {
            col--;
        }
        else
        {
            row++;
        }
    }
    return false;
}
int main()
{
    vector<vector<int>> v =
        {{1, 4, 7, 11, 15},
         {2, 5, 8, 12, 19},
         {3, 6, 9, 16, 22},
         {10, 13, 14, 17, 24},
         {18, 21, 23, 26, 30}};

    cout << searchMatrixRowAndCol(v, 26);

    //   Compilation Time code //
    cout << endl;
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    return 0;
}