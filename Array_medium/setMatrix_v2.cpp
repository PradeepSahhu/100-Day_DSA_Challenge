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
// vector<vector<int>> setMatrix_(vector<vector<int>> &v, int n, int m)
// {
//     // cout << "hello world" << endl;

//     // int col[m] = {0};
//     // vector<int> cols(v[0][...]); // it will give the no. of columns.
//     // vector<int> rows(v[...][0]); // it will give the no. of rows.
//     vector<int> col(m, 0);
//     vector<int> row(n, 0);
//     // int row[n] = {0};
//     for (int i = 0; i < v.size(); i++)
//     {
//         for (int j = 0; j < v[i].size(); j++)
//         {
//             if (v[i][j] == 0)
//             {
//                 row[i] = 1;
//                 col[j] = 1;
//             }
//         }
//     }
//     for (int i = 0; i < v.size(); i++)
//     {
//         for (int j = 0; j < v[i].size(); j++)
//         {
//             if (row[i] || col[j])
//             {
//                 v[i][j] = 0;
//             }
//         }
//     }

//     return v;
// }

vector<vector<int>> setMatrix_(vector<vector<int>> &v, int n, int m)
{
    // vector<int> col(m, 0); // for the no. of columns = v[0][...]
    // vector<int> row(n, 0); // for the no. of rows = v[...][0]

    int col0 = 1;

    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {

            // marking the first row & first column
            if (v[i][j] == 0)
            {
                // mark the i-th row
                v[i][0] = 0;
                // mark the j-th column
                if (j != 0)
                {
                    v[0][j] = 0;
                }
                else
                {
                    col0 = 0;
                }
            }
        }
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (v[i][j] != 0) // checking if the current nubmer is not equal to 0.
                // checking the row & col, then checking if the row or col is 0 if yes then assigning it to 0.
                if (v[i][0] == 0 || v[0][j] == 0)
                {

                    v[i][j] = 0;
                }
        }
    }

    // converting the first column.

    if (v[0][0] == 0)
    {

        for (int i = 0; i < m; i++)
        {

            v[0][i] = 0;
        }
    }

    // converting the first row.

    if (col0 == 0)
    {

        for (int i = 0; i < n; i++)
        {

            v[i][0] = 0;
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
        {1, 1, 0, 1}};

    vector<vector<int>> s = setMatrix_(v, 4, 4);

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