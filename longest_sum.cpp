#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

auto start = chrono::steady_clock::now();

void longest_sum(vector<int> &v)
{
    vector<vector<int> > allv;
    vector<int> arr;
    vector<int> sub;
    for (int i = 0; i < v.size(); i++)
    {
        sub.push_back(v[i]);

        for (int j = i; j < v.size(); j++)
        {
            for (int k = i; k < j; k++)
            {
                arr.push_back(v[k]);
            }
            allv.push_back(sub);
            allv.push_back(arr);
            arr.clear();
            sub.clear();
        }
    }

    for (auto it : allv)
    {
        cout << '[';

        for (int i = 0; i < it.size(); i++)
        {
            cout << it[i];
        }
        cout << ']' << endl;
    }
}
int main()
{

    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(arr) / sizeof(arr[0]);

    vector<int> v(arr, arr + size);
    longest_sum(v);

    //   Compilation Time code //
    cout << endl;
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    return 0;
}