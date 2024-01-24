#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

auto start = chrono::steady_clock::now();

// void rearrage_elements(vector<int> &v)
// {
//     vector<int> ne;
//     vector<int> po;
//     for (int i = 0; i < v.size(); i++)
//     {
//         if (v[i] < 0)
//         {
//             ne.push_back(v[i]);
//         }
//         else
//         {
//             po.push_back(v[i]);
//         }
//     }
//     for (int i = 0; i < v.size() / 2; i++)
//     {
//         v[2 * i] = po[i];
//         v[2 * i + 1] = ne[i];
//     }
//     for (int i = 0; i < v.size(); i++)
//     {
//         cout << v[i] << " ";
//     }
// }

// void rearrage_elements(vector<int> &v)
// {
//     int positive = 0;
//     int negative = 1;
//     vector<int> ans(v.size());
//     for (int i = 0; i < v.size(); i++)
//     {
//         if (v[i] > 0)
//         {
//             ans[positive] = v[i];
//             positive += 2;
//         }
//         else
//         {
//             ans[negative] = v[i];
//             negative += 2;
//         }
//     }

//     for (int i = 0; i < ans.size(); i++)
//     {
//         cout << ans[i] << " ";
//     }
// }

// Alternate approach...

vector<int> rearrange_ele(vector<int> &nums)
{
    int pos = 0, neg = 0, n = nums.size();
    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            while (nums[pos] < 0)
            {
                pos++;
            }
            ans.push_back(nums[pos++]); //! After inserting increment it so that it doesn't repeat itself.
        }
        else
        {
            while (nums[neg] >= 0)
            {
                neg++;
            }
            ans.push_back(nums[neg++]); //! After inserting it increment is so that it doesn't repeat itself.
        }
    }
}

//! Varity two when postive and negative numbers (frequency of both the numbers are not equal)

vector<int> rearrange_elements(vector<int> &v)
{
    vector<int> pos, neg;

    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] > 0)
        {
            pos.emplace_back(v[i]);
        }
        else
        {
            neg.emplace_back(v[i]);
        }
    }
    cout << pos.size() << endl;
    cout << neg.size() << endl;

    if (pos.size() > neg.size())
    {
        for (int i = 0; i < neg.size(); i++)
        {
            v[2 * i] = pos[i];
            v[2 * i + 1] = neg[i];
        }

        int index = 2 * neg.size();

        for (int i = neg.size(); i < pos.size(); i++)
        {
            v[index] = pos[i];
            index++;
        }
    }
    else
    {
        for (int i = 0; i < pos.size(); i++)
        {
            v[2 * i] = pos[i];
            v[2 * i + 1] = neg[i];
        }

        int index = 2 * pos.size();

        for (int i = pos.size(); i < neg.size(); i++)
        {
            v[index] = neg[i];
            index++;
        }
    }

    return v;
}
int main()
{

    int arr[] = {3, 1, -2, -5, 2, -4, 7, 8, 9};
    int size = sizeof(arr) / sizeof(arr[0]);

    vector<int> v(arr, arr + size);

    vector<int> ans = rearrange_elements(v);
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