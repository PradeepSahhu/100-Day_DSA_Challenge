#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;
auto start = chrono::steady_clock::now();

int duplicate_items_number(vector<int> &arr)
{
    set<int> s; // set doesn't contain duplicate items.
    for (int i = 0; i < arr.size(); i++)
    {
        s.insert(arr[i]);
    }
    int j = 0;

    for (auto it : s)
    {
        cout << "The elements are : " << it << endl;
        arr[j] = it;
        j++;
    }
    return j;
} // Time complexity : O(2n)

int duplicate_items_nu(vector<int> &arr)
{

    int i = 0;
    for (int j = 1; j < arr.size(); j++)
    {
        if (arr[j] != arr[i])
        {
            arr[i + 1] = arr[j];
            i++;
        }
    }

    return (i + 1);
}

int main()
{

    int a[] = {1, 1, 1, 2, 2, 3, 3, 3, 4, 4, 5, 5, 5};
    int size = sizeof(a) / sizeof(a[0]);

    vector<int> arr(a, a + size);
    cout << "The number of elements in the vector is : " << duplicate_items_nu(arr) << endl;

    //   Compilation Time code //
    cout
        << endl;
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    return 0;
}