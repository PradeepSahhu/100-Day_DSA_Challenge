#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

auto start = chrono::steady_clock::now();
int main()
{

    int arr[] = {1, 1, 2, 3, 3, 3, 8, 8, 8, 4, 5, 4, 5, 8, 8};
    int size = sizeof(arr) / sizeof(arr[0]);

    vector<int> v(arr, arr + size);

    map<int, int> m;

    for (int i = 0; i < v.size(); i++)
    {
        m[v[i]]++;
    }

    for (auto it : m)
    {
        if (it.second == 1)
        {
            cout << it.first << endl;
            break;
        }
    }

    // for (int i = 0; i < 10; i++)
    // {
    //     m[i] = i + 10;
    // }
    map<int, int>::iterator it = m.begin();
    while (it != m.end())
    {
        cout << "key : " << it->first << ", value : " << it->second << endl;
        it++;
    }

    //   Compilation Time code //
    cout << endl;
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    return 0;
}