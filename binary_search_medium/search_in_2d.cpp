#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

auto start = chrono::steady_clock::now();

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int n = matrix.size();
    int m = matrix[0].size();

    // apply binary search:
    int low = 0, high = n * m - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int row = mid / m, col = mid % m;
        if (matrix[row][col] == target)
            return true;
        else if (matrix[row][col] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return false; 
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