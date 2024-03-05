#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

auto start = chrono::steady_clock::now();

int findKthPositive(vector<int> &arr, int k)
{
    // find the number which is missing at kth position.
    int n = arr.size();
    int left = 0;
    int right = n - 1;

    while (left <= right)
    {
        
        int mid = (left + right) / 2;
        int missing = arr[mid] - (mid + 1);
        if (missing < k)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return k + left;
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