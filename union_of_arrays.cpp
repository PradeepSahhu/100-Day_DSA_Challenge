#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

auto start = chrono::steady_clock::now();

// void union_of_two_arrays(vector<int> arr1, vector<int> arr2)
// {

//     // brute force approach...
//     set<int> s;
//     for (int i = 0; i < arr1.size(); i++)
//     {
//         s.insert(arr1[i]);
//     }
//     for (int i = 0; i < arr2.size(); i++)
//     {
//         s.insert(arr2[i]);
//     }

//     for (auto it : s)
//     {
//         cout << it << " ";
//     }
// }
void union_of_two_arrays(vector<int> arr1, vector<int> arr2)
{

    // optimum solution...
    vector<int> mainarr;
    int n1 = arr1.size();
    int n2 = arr2.size();

    int i = 0;
    int j = 0;
    // cout << mainarr.size() << endl;

    while (i < n1 && j < n2)
    {
        if (arr1[i] <= arr2[j])
        {
            if (mainarr.size() == 0 || mainarr.back() != arr1[i])
            {
                mainarr.push_back(arr1[i]);
            }

            i++;
        }
        else
        {
            if (mainarr.size() == 0 || mainarr.back() != arr2[j])
            {
                mainarr.push_back(arr2[j]);
            }

            j++;
        }
    }
    while (i < n1)
    {
        if (arr1[i] != mainarr.back())
        {
            mainarr.push_back(arr1[i]);
        }

        i++;
    }
    while (j < n2)
    {
        if (arr2[j] != mainarr.back())
        {
            mainarr.push_back(arr2[j]);
        }

        j++;
    }

    for (auto it : mainarr)
    {
        cout << it << " ";
    }
}

void union_of_two_arrays_(vector<int> a1, vector<int> a2)
{
    vector<int> set;
    int n1 = a1.size();
    int n2 = a2.size();

    int i = 0;
    int j = 0;

    while (i < n1 && j < n2)
    {
        if (a1[i] <= a2[j])
        {
            if (set.size() == 0 || set.back() != a1[i])
            {
                set.push_back(a1[i]);
            }
            i++;
        }
        else if (a2[j] < a1[i])
        {
            if (set.size() == 0 || set.back() != a2[j])
            {
                set.push_back(a2[j]);
            }
            j++;
        }
    }

    while (i < n1)
    {
        if (set.back() != a1[i])
        {
            set.push_back(a1[i]);
        }
        i++;
    }
    while (j < n2)
    {
        if (set.back() != a2[j])
        {
            set.push_back(a2[j]);
        }
        j++;
    }

    for (auto it : set)
    {
        cout << it << " ";
    }
}
int main()
{
    int a1[] = {1, 1, 2, 3, 4, 5, 7, 8};
    int a2[] = {0, 2, 3, 4, 5, 6, 7};

    int size1 = sizeof(a1) / sizeof(a1[0]);
    int size2 = sizeof(a2) / sizeof(a2[0]);

    vector<int> arr1(a1, a1 + size1);
    vector<int> arr2(a2, a2 + size2);

    union_of_two_arrays_(arr1, arr2);

    //   Compilation Time code //
    cout << endl;
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    return 0;
}