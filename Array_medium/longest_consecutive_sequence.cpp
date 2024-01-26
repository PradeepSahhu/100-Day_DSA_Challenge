#include <iostream>
#include <bits/stdc++.h>
#include <unordered_set>
#include <chrono>
using namespace std;

auto start = chrono::steady_clock::now();

bool linear_search(vector<int> &v, int key)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == key)
        {
            return true;
        }
    }
    return false;
}

// int longest_consecutive_sequence(vector<int> &v)
// {

//     int maincount = 0;

//     for (int i = 0; i < v.size(); i++)
//     {
//         int search = v[i];
//         int count = 1;
//         while (find(v.begin(), v.end(), search + 1) != v.end())
//         {
//             count++;
//             search = search + 1;
//         }
//         maincount = max(count, maincount);
//     }

//     return maincount;
// }

// int longest_consecutive_sequence(vector<int> &v)
// {

//     int maincount = 0;

//     sort(v.begin(), v.end());

//     int lastElement = INT_MIN;
//     int count = 1;

//     for (int i = 0; i < v.size(); i++)
//     {

//         if (v[i] - 1 == lastElement)
//         {
//             count++;
//         }
//         else if (v[i] == lastElement)
//         {
//         }
//         else
//         {
//             count = 1;
//         }
//         maincount = max(count, maincount);
//         lastElement = v[i];
//     }

//     return maincount;
// }
int longest_consecutive_sequence(vector<int> &v)
{

    int n = v.size();
    unordered_set<int> s;

    for (int i = 0; i < n; i++)
    {
        s.insert(v[i]);
    }

    int maxCount = 0;

    for (auto it : s)
    {
        int count = 1;
        int x = it;
        if (s.find(x - 1) == s.end())
        {
            while (s.find(x + 1) != s.end())
            {
                count++;
                x = x + 1;
            }
            maxCount = max(maxCount, count);
        }
    }
    return maxCount;
}

int main()
{

    // int arr[] = {102, 4, 100, 1, 101, 3, 2, 1, 1};
    // int size = sizeof(arr) / sizeof(arr[0]);

    // vector<int> v(arr, arr + size);
    vector<int> v = {102, 4, 100, 1, 101, 3, 2, 1, 1};

    cout << longest_consecutive_sequence(v);

    //   Compilation Time code //
    cout << endl;
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    return 0;
}