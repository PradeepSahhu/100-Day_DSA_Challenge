#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

auto start = chrono::steady_clock::now();

// Leader : every element on the right should be smaller then its a leader.

// right most element is by default a leader as their is no element on its right.

// vector<int> finding_leader(vector<int> &v)
// {

//     vector<int> ans;
//     for (int i = 0; i < v.size(); i++)
//     {
//         bool leader = true;

//         for (int j = i + 1; j < v.size(); j++)
//         {
//             if (v[i] < v[j])
//             {
//                 leader = false;
//                 break;
//             }
//         }
//         if (leader)
//             ans.push_back(v[i]);
//     }

//     return ans;
// }
vector<int> finding_leader(vector<int> &v)
{

    vector<int> ans;
    int n = v.size();
    int maxi = INT_MIN;
    for (int i = n - 1; i >= 0; i--)
    {

        if (v[i] > maxi)
        {
            ans.push_back(v[i]);
            maxi = v[i];
        }
    }

    return ans;
}

vector<int> superiorElements(vector<int> &a)
{

    vector<int> ans;
    int maxi = INT_MIN;
    int n = a.size();
    for (int i = n - 1; i >= 0; i--)
    {

        if (a[i] > maxi)
        {
            if (ans.size() == 0 || ans.back() != a[i])
            {
                ans.push_back(a[i]);
            }

            maxi = a[i];
        }
    }

    return ans;
}
int main()
{
    int arr[] = {5, 4, 3}; // here 2 ( index = 1) is the breakpoint.

    int size = sizeof(arr) / sizeof(arr[0]);

    vector<int> v(arr, arr + size);

    // vector<int> ans = finding_leader(v);
    vector<int> ans = superiorElements(v);

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