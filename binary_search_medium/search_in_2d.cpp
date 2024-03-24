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

// working in 2D matrix.

//! Finding the first occurence of any number.

int FirstOccurance(vector<int> &v, int k)
{
    int n = v.size();
    int left = 0;
    int right = n - 1;

    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (v[mid] <= k)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return right;
}

int main()
{

    vector<int> v = {0, 0, 1, 1, 1};
    cout << FirstOccurance(v, 1);

    //   Compilation Time code //
    cout << endl;
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    return 0;
}