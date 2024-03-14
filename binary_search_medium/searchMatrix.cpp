#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

auto start = chrono::steady_clock::now();

bool searchElement(vector<vector<int>> &matrix, int target)
{
    int n = matrix.size();
    int m = matrix[0].size();
    int row = 0, col = m - 1;

    // traverse the matrix from (0, m-1):
    while (row < n && col >= 0)
    {
        if (matrix[row][col] == target)
            return true;
        else if (matrix[row][col] < target)
            row++;
        else
            col--;
    }
    return false;
}

int main()
{
    searchElement();

    //   Compilation Time code //
    cout << endl;
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    return 0;
}