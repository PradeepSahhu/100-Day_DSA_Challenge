#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

auto start = chrono::steady_clock::now();
int main()
{

    // vectors

    // vector<int> v = {1, 2, 34, 7, 5, 6};

    // Through Array.
    int arr[] = {1, 2, 3, 4, 5, 6, 8};
    int size = sizeof(arr) / sizeof(arr[0]);

    vector<int> vec(arr, arr + size);

    // for (int i = 0; i < vec.size(); i++)
    // {
    //     cout << vec[i] << " ";
    // }

    // map Data structure.

    map<int, int> hashMpp;
    hashMpp[1] = 100;

    if (hashMpp.find(2) != hashMpp.end()) // used to find the keys in the map data structure.
    {
        cout << hashMpp[1] << endl;
    }
    else
    {
        cout << "Can't find the value" << endl;
    }

    // sets.

    set<int> s = {1, 2, 3, 1, 1, 2, 3};

    // traversing through iterators.

    set<int>::iterator it = s.begin();

    while (it != s.end())
    {
        cout << *it << endl;
        it++;
    }

    //   Compilation Time code //
    cout << endl;
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    return 0;
}