#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

auto start = chrono::steady_clock::now();

void sort_1_(vector<int> &v)
{
    int low = 0;
    int mid = 0;
    int high = v.size() - 1;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[mid] == 0)
        {
            swap(v[low], v[mid]);
            mid++;
            low++;
        }
        else if (v[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(v[mid], v[high]);
            high--;
        }
    }
}
int main()
{

    int arr[] = {0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0};
    int size = sizeof(arr) / sizeof(arr[0]);

    vector<int> v(arr, arr + size);

    sort_1_(v);

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }

    //   Compilation Time code //
    cout << endl;
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    return 0;
}