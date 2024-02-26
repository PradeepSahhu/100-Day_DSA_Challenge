#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

auto start = chrono::steady_clock::now();

// ######################################################################

int missingNumber(vector<int> v, int n)
{

    // for (int i = 1; i < n; i++)
    // {
    //     int flag = 0;

    //     for (int j = 0; j < v.size(); j++)
    //     {
    //         cout << v[j] << " <-" << i << endl;
    //         if (v[j] == i)
    //         {
    //             flag++;
    //             break;
    //         }
    //     }
    //     if (flag == 0)
    //     {
    //         return i;
    //     }
    // }

    // hasing approach.

    // vector<int> hash(n + 1);

    // for (int i = 0; i < v.size(); i++)
    // {
    //     hash[v[i]]++;
    // }
    // for (int i = 1; i < hash.size(); i++)
    // {
    //     if (hash[i] == 0)
    //     {
    //         return i;
    //     }
    // }

    // optimal approach.

    // int totalSum = n * (n + 1) / 2;
    // int sum = 0;

    // for (int i = 0; i < n - 1; i++)
    // {
    //     sum += v[i];
    // }
    // return totalSum - sum;

    // using XOR.
    int xor1 = 0;
    int xor2 = 0;

    // for (int i = 1; i <= n; i++)
    // {
    //     xor1 = xor1 ^ i;
    // }

    for (int i = 0; i < n - 1; i++)
    {
        xor1 = xor1 ^ (i + 1);
        xor2 = xor2 ^ v[i];
    }
    xor1 = xor1 ^ n;

    return (xor1 ^ xor2);
}

void max_consecutive_ones(vector<int> v)
{
    int max = 0;
    int currentMax = 0;

    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == 1)
        {
            currentMax++;
        }
        else if (v[i] == 0)
        {
            if (currentMax > max)
            {
                max = currentMax;
            }

            currentMax = 0;
        }
    }
    if (currentMax > max)
    {
        max = currentMax;
    }

    cout << max << " ";
}

int min_occurence(vector<int> v)
{
    // better approach than hasing but now most optimised approach...
    // map<int, int> mpp;
    // for (int i = 0; i < v.size(); i++)
    // {
    //     mpp[v[i]]++;
    // }
    // for (auto it : mpp)
    // {
    //     if (it.second == 1)
    //     {
    //         return it.first;
    //     }
    // }

    // most optimised approach...

    int xors = 0;

    for (int i = 0; i < v.size(); i++)
    {
        xors = xors ^ v[i];
    }
    return xors;
}
int main()
{
    // int arr[] = {1, 4, 2, 5};
    // int arr[] = {1, 1, 0, 1, 1, 0, 0, 1, 0};
    int arr[] = {1, 1, 2, 2, 3, 4, 4, 5, 6, 5, 6, 7, 8, 8, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    vector<int> v(arr, arr + size);

    // cout << missingNumber(v, 5);
    // max_consecutive_ones(v);
    cout << min_occurence(v);

    //   Compilation Time code //
    cout << endl;
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    return 0;
}