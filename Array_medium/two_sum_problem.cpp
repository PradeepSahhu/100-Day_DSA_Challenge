#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

auto start = chrono::steady_clock::now();
//? Start your code from here.

//! 2 sum problem Part-1: (return true or false), that is if sum of two elements in the array is equal
//! to target value or not.
pair<int, int> sum_is_present_in_the_array(vector<int> &v, int target)
// bool sum_is_present_in_the_array(vector<int> &v, int target)
{
    // brute force approach

    // for (int i = 0; i < v.size(); i++)
    // {

    //     for (int j = i + 1; j < v.size(); j++)
    //     {
    //         if (v[i] + v[j] == target)
    //         {
    //             cout << i << " : " << j << endl;
    //             return true;
    //         }
    //     }
    // }
    // return false;

    // better Approach
    map<int, int> mpp; // ordered map : O(log n)
    for (int i = 0; i < v.size(); i++)
    {
        // cout << i << endl;  // cout << mpp[v[i]] != i; //! it means both number should not be same value.
        int res = target - v[i];
        if (mpp.find(res) != mpp.end() && mpp[res] != i) // mpp.find(key) --> checks if the key exist or not
        {
            return make_pair(mpp[res], i); // return true; //return [mpp[res]:i]
        }
        mpp[v[i]] = i; // key ---> value
    }
    // for (int i = 0; i < v.size(); i++)
    // {
    // cout << mpp[v[i]] != i; //! it means both number should not be same value.
    //     int res = target - v[i];
    //     if (mpp.find(res) != mpp.end() && mpp[res] != i) // mpp.find(key) --> checks if the key exist or not
    //     {
    //         return true;
    //     }
    // }
    return make_pair(-1, -1);
    // return false;
}

int main()
{

    //! 2 sum problem Part-1: (return true or false), that is if sum of two elements in the array is equal
    //! to target value or not.

    //! 2 Sum problem Part-2:(return indexes), given that sum is present in the array, our job is to return that indexes
    //! whose sum is equal to target.
    int arr[] = {2, 6, 5, 8, 11};
    int size = sizeof(arr) / sizeof(arr[0]);

    vector<int> v(arr, arr + size);

    // sum_is_present_in_the_array(v, 14) ? cout << "Present" : cout << "Not Present";
    pair<int, int> p = sum_is_present_in_the_array(v, 10);
    cout << p.first << " : " << p.second << endl;

    //   Compilation Time code //
    cout << endl;
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    return 0;
}