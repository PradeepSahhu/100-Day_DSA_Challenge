#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

auto start = chrono::steady_clock::now();

int finding_square_root(int n)
{
    int left = 1;
    int right = n;
    int ans = 0;
    if (n <= 1)
    {
        return 1;
    }

    while (left <= right)
    {

        int mid = (left + right) / 2;
        if (mid * mid <= n)
        {
            ans = mid;
            left = mid + 1;
        }
        else
        {

            right = mid - 1;
        }
    }
    return ans;
}
int main()
{
    int n;
    cout << "Enter the number" << endl;
    cin >> n;
    cout << finding_square_root(n);
    //   Compilation Time code //
    cout << endl;
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    return 0;
}