#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

auto start = chrono::steady_clock::now();

// Kadane's Algorithm

int maximum_subArray_sum(vector<int> &v)
{
    int sum = 0;
    int maxi = 0;
    for (int i = 0; i < v.size(); i++)
    {
        sum += v[i];
        maxi = max(maxi, sum);
        if (sum < 0)
        {
            sum = 0;
        }
    }
    return maxi;
}
int main()
{

    // int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int arr[] = {-1};
   
    int size = sizeof(arr) / sizeof(arr[0]);

    vector<int> v(arr, arr + size);
    cout << maximum_subArray_sum(v);

    //   Compilation Time code //
    cout << endl;
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    return 0;
}