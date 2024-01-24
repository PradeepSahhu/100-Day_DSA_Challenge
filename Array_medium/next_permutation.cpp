#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

auto start = chrono::steady_clock::now();

//? A high level for brute force approach is : 1. generate all possible permutations using recursion.

vector<int> next_per(vector<int> &v)
{
    next_permutation(v.begin(), v.end()); //! by using in-build STL functions. ( not recommended)

    return v;
}

vector<int> generatePermutations(vector<int> &v)
{
    int n = v.size(), index = -1;

    // used to finding the breakpoint.

    for (int i = n - 2; i >= 0; i--)
    {
        if (v[i] < v[i + 1])
        {
            index = i;
            break;
        }
    }

    if (index == -1)
    {
        reverse(v.begin(), v.end());
        return v;
    }

    // used to find the number which is just above the current index.
    for (int i = n - 1; i > index; i--)
    {
        if (v[i] > v[index])
        {
            swap(v[i], v[index]);
            break;
        }
    }

    reverse(v.begin() + (index + 1), v.end());

    return v;
}

int main()
{

    int arr[] = {1, 2, 10, 8, 7, 6, 5}; // here 2 ( index = 1) is the breakpoint.

    int size = sizeof(arr) / sizeof(arr[0]);

    vector<int> v(arr, arr + size);

    // vector<int> nums = next_per(v);

    // for (int i = 0; i < nums.size(); i++)
    // {
    //     cout << nums[i] << " ";
    // }
    vector<int> ans = generatePermutations(v);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    //   Compilation Time code //
    cout << endl;
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    return 0;
}