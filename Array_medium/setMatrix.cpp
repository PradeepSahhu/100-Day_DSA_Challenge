#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

auto start = chrono::steady_clock::now();

// vector<vector<int>> setMatrix_(vector<vector<int>> &v)
// {
//     for (int i = 0; i < v.size(); i++)
//     {
//         for (int j = 0; j < v[i].size(); j++)
//         {
//             if (v[i][j] == 0)
//             {
//                 for (int k = 0; k < v[i].size(); k++)
//                 {
//                     if (v[i][k] == 1)
//                     {
//                         v[i][k] = -1;
//                     }
//                 }
//                 for (int l = 0; l < v.size(); l++)
//                 {
//                     if (v[l][j] == 1)
//                     {
//                         v[l][j] = -1;
//                     }
//                 }
//             }
//         }
//     }
//     for (int i = 0; i < v.size(); i++)
//     {
//         for (int j = 0; j < v[i].size(); j++)
//         {
//             if (v[i][j] == -1)
//             {
//                 v[i][j] = 0;
//             }
//         }
//     }

//     return v;
// }
vector<vector<int>> setMatrix_(vector<vector<int>> &v, int n, int m)
{
    // cout << "hello world" << endl;

    // int col[m] = {0};
    vector<int> col(m, 0);
    vector<int> row(n, 0);
    // int row[n] = {0};
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            if (v[i][j] == 0)
            {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            if (row[i] || col[j])
            {
                v[i][j] = 0;
            }
        }
    }

    return v;
}

int main()
{

    vector<vector<int>> v = {
        {1, 1, 1, 1},
        {1, 0, 0, 1},
        {1, 1, 1, 1},
        {1, 1, 1, 1}};

    vector<vector<int>> s = setMatrix_(v, 4, 5);

    for (int i = 0; i < s.size(); i++)
    {
        for (int j = 0; j < s[i].size(); j++)
        {
            cout << s[i][j] << " ";
        }
        cout << endl;
    }

    //   Compilation Time code //
    cout
        << endl;
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    return 0;
}