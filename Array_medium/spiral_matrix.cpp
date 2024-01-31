#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

auto start = chrono::steady_clock::now();

void sprial_print_matrix(vector<vector<int>> &v)
{

    int n = v.size();
    int m = v[0].size();

    // this problem is solved

    int top = 0;
    int left = 0;
    int right = n - 1;
    int bottom = m - 1;

    while (left < right && top < bottom)
    {

        for (int i = left; i <= right; i++)
        {
            cout << v[top][i] << " ";
        }
        top++;
        for (int i = top; i <= bottom; i++)
        {
            cout << v[i][right] << " ";
        }
        right--;

        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
            {
                cout << v[bottom][i] << " ";
            }
            bottom--;
        }

        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
            {
                cout << v[i][left] << " ";
            }
            left++;
        }
    }
}
int main()
{

    vector<vector<int>> v = {
        {1, 2, 3, 4, 5, 6},
        {7, 8, 9, 10, 11, 12},
        {13, 14, 15, 16, 17, 18},
        {19, 20, 21, 22, 23, 24},
        {25, 26, 27, 28, 29, 30},
        {31, 32, 33, 34, 35, 36}};

    sprial_print_matrix(v);

    //   Compilation Time code //
    cout << endl;
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    return 0;
}