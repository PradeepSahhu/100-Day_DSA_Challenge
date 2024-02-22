#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

auto start = chrono::steady_clock::now();

void mergeTwoSortedArraysWithoutExtraSpace(vector<long long> &a, vector<long long> &b)
{
    // Write your code here.

    //! Better Approach than using the extra space approach.

    int na = a.size();
    int nb = b.size();

    int ia = na - 1;
    int jb = 0;

    while (ia >= 0 && jb < nb)
    {
        if (a[ia] > b[jb])
        {
            int temp = a[ia];
            a[ia] = b[jb];
            b[jb] = temp;
            ia--;
            jb++;
        }
        else
        {
            break;
        }
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
}
int main()
{

    vector<long long> a = {0, 2, 4, 6, 8};

    vector<long long> b = {1, 3, 5, 7, 9};

    mergeTwoSortedArraysWithoutExtraSpace(a, b);

    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
    //! executed the code
    cout << endl;
    for (int i = 0; i < b.size(); i++)
    {
        cout << b[i] << " ";
    }
    //   Compilation Time code //
    cout << endl;
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    return 0;
}