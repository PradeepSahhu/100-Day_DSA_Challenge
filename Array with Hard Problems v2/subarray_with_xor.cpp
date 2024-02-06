#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

auto start = chrono::steady_clock::now();

// Subarray with given XOR
/*
Given an array of integers A and an integer B.

Find the total number of subarrays having bitwise XOR of all elements equals to B.
*/

int no_of_subArray_with_xor_bruteForce_approach(vector<int> &v, int b)
{ //! Time limit Exceed.
    int n = v.size();
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        int xors = v[i];
        if (xors == b)
        {
            count++;
        }
        for (int j = i + 1; j < n; j++)
        {
            xors ^= v[j];
            if (xors == b)
            {
                count++;
            }
        }
    }
    return count;
}
int main()
{
    vector<int> v = {4, 2, 2, 6, 4};

    cout << no_of_subArray_with_xor_bruteForce_approach(v, 6);

    //   Compilation Time code //
    cout << endl;
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    return 0;
}