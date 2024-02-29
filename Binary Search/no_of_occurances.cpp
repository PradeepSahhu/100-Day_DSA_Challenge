#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

auto start = chrono::steady_clock::now();

int firstOccurance(vector<int> arr, int n, int x)
{
    int left = 0;
    int right = n - 1;
    int first = -1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (arr[mid] == x)
        {
            first = mid;
            right = mid - 1;
        }
        else if (arr[mid] < x)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return first;
}

int lastOccurance(vector<int> arr, int n, int x)
{
    int left = 0;
    int right = n - 1;
    int last = -1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (arr[mid] == x)
        {
            last = mid;
            left = mid + 1;
        }
        else if (arr[mid] < x)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return last;
}

int count(vector<int> &arr, int n, int x)
{
    // Write Your Code Here

    int lb = firstOccurance(arr, n, x);
    if (lb == -1)
        return 0;
    return (lastOccurance(arr, n, x) - lb) + 1;
}

int main()
{

    vector<int> arr = {1, 1, 2, 2, 2, 3, 3, 3, 3, 3};
    cout << count(arr, arr.size(), 3);

    //   Compilation Time code //
    cout << endl;
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    return 0;
}