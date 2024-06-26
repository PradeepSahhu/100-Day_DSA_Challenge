#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

auto start = chrono::steady_clock::now();
//! Median in a row wise sorted Matrix.

int lowestElement(vector<vector<int>> &v)
{
    int smallest = INT_MAX;
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        if (v[i][0] < smallest)
        {
            smallest = v[i][0];
        }
    }
    return smallest;
}

int largestElement(vector<vector<int>> &v)
{
    int largest = INT_MIN;
    int n = v.size();
    int m = v[0].size();
    for (int i = 0; i < n; i++)
    {
        if (v[i][m - 1] > largest)
        {
            largest = v[i][m - 1];
        }
    }
    return largest;
}

int upperbounding(vector<int> &nums, int x, int n)
{
    int left = 0;
    int right = n - 1;
    int ans = 0;

    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (nums[mid] <= x)
        {
            ans = mid + 1;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return left;
    // return ans;
}

int smallCountEql(vector<vector<int>> &v, int x)
{
    int n = v.size();
    int m = v[0].size();
    int summation = 0;

    for (int i = 0; i < n; i++)
    {
        summation += upperbounding(v[i], x, m);
    }
    return summation;
}

int median_of_2d(vector<vector<int>> &v)
{
    int n = v.size();
    int m = v[0].size();

    int low = lowestElement(v);
    int high = largestElement(v);

    int req = (n * m) / 2;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        int smallerEquals = smallCountEql(v, mid);
        if (smallerEquals <= req)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return low;
}

int main()
{
    vector<vector<int>> v = {
        {1, 5, 7, 9, 11},
        {2, 3, 4, 5, 10},
        {9, 10, 12, 14, 16}};

    cout << median_of_2d(v);

    //   Compilation Time code //
    cout << endl;
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    return 0;
}