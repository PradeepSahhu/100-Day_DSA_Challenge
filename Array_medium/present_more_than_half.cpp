#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

auto start = chrono::steady_clock::now();

// moore's voting algorithm

// brute force approach.
// int more_than_half(vector<int> &v)
// {
//     int n = v.size();

//     for (int i = 0; i < v.size(); i++)
//     {
//         int count = 0;
//         for (int j = 0; j < v.size(); j++)
//         {
//             if (v[i] == v[j])
//             {
//                 count++;
//             }
//         }
//         if (count > n / 2)
//             return v[i];
//     }
//     return -1;
// }

// better approach using hashmap.
// int more_than_half(vector<int> &v)
// {
//     map<int, int> mpp;
//     int n = v.size();

//     for (int i = 0; i < v.size(); i++)
//     {
//         mpp[v[i]]++;
//     }
//     for (auto it : mpp)
//     {
//         if (it.second > n / 2)
//         {
//             return it.first;
//         }
//     }
//     return -1;
// }

// most optimised approach.

int more_than_half(vector<int> &v)
{
    int element;
    int count = 0;

    for (int i = 0; i < v.size(); i++)
    {
        if (count == 0)
        {
            count = 1;
            element = v[i];
        }
        else if (element == v[i])
        {
            count++;
        }
        else
        {
            count--;
        }
    }
    int count1 = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (element == v[i])
        {
            count1++;
        }
    }
    if (count1 > v.size() / 2)
    {
        return element;
    }
    return -1;
}
int main()
{

    int arr[] = {3, 2, 2, 3, 3, 3, 3, 2, 9, 3, 3, 2, 3};
    int size = sizeof(arr) / sizeof(arr[0]);

    vector<int> v(arr, arr + size);

    cout << more_than_half(v);

    //   Compilation Time code //
    cout << endl;
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    return 0;
}