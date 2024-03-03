#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

auto start = chrono::steady_clock::now();

// int nthrootValue(int mid, int n, int m)
// {
//     long long ans = 1;
//     for (int j = 1; j <= n; j++)
//     {
//         ans *= mid;
//         if (ans > m)
//             return 2;
//     }
//     if (ans == m)
//         return 1;
//     return 0;
// }

// int NthRoot(int n, int m)
// {
//     int left = 1;
//     int right = m;

//     while (left <= right)
//     {
//         int mid = (left + right) / 2;
//         int midAns = nthrootValue(mid, n, m);
//         if (midAns == 1)
//         {
//             return mid;
//         }
//         else if (midAns == 2)
//         {
//             right = mid - 1;
//         }
//         else
//         {
//             left = mid + 1;
//         }
//     }
//     return -1;
// }

//! Alternative easy solution.

int nthrootValue(int mid, int n)
{
    long long ans = 1;
    for (int j = 1; j <= n; j++)
    {
        ans *= mid;
    }
    return ans;
}

int NthRoot(int n, int m)
{
    int left = 1;
    int right = m;

    while (left <= right)
    {
        int mid = (left + right) / 2;
        long long ans = nthrootValue(mid, n);

        if (ans == m)
        {
            return mid;
        }
        else if (ans > m)
        {
            right = mid - 1;
        }
        else
            left = mid + 1;
    }
    return -1;
}
int main()
{
    cout << NthRoot(3, 27);

    //   Compilation Time code //
    cout << endl;
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    return 0;
}