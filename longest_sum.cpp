#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

auto start = chrono::steady_clock::now();

vector<int> longest_sum(vector<int> &v, int k)
{
    vector<vector<int> > allv;
    vector<int> arr;
    vector<int> sub;
    for (int i = 0; i < v.size(); i++)
    {
        sub.push_back(v[i]);
        allv.push_back(sub);

        for (int j = i + 1; j < v.size(); j++)
        {
            // pushing the elements in to the subarray.
            for (int k = i; k <= j; k++)
            {
                arr.push_back(v[k]);
            }

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

    int sum = 0;

    // then i am calculating the sum of the subarray.

    for (auto it : allv)
    {
        // cout << " this is first loop" << endl;
        for (int i = 0; i < it.size(); i++)
        {
            // cout << it[i] << " this is second loop" << endl;
            sum += it[i]; // here.
        }
        if (sum == k)
        {
            return it;
        }
        sum = 0;
    }
}

vector<int> longest_sum_subarray(vector<int> &v, int k)
{

    int sum = 0;
    vector<int> ans;

    // better syntax and easy to understand.

    for (int i = 0; i < v.size(); i++)
    {
        for (int j = i + 1; j < v.size(); j++)
        {
            for (int k = i; k < j; k++)
            {
                ans.push_back(v[k]);
                sum += v[k];
            }

            if (sum == k)
            {
                return ans;
            }
            sum = 0;
            ans.clear();
        }
    }
}
int main()
{

    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(arr) / sizeof(arr[0]);

    vector<int> v(arr, arr + size);
    vector<int> ans = longest_sum_subarray(v, 10);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    //   Compilation Time code //
    cout << endl;
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    return 0;
}