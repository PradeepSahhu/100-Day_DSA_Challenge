#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

auto start = chrono::steady_clock::now();

vector<int> plusOne(vector<int> &digits)
{

    int n = digits.size();
    int count = 0;
    // vector<int> ans;
    // int count;

    for (int i = 0; i < n; i++)
    {
        count = count * 10 + digits[i];
    }
    count = count + 1;
    int temp = count;
    int digit = to_string(temp).length();
    cout << "The value of digit is : " << digit << endl;
    cout << "The value of count is " << count << endl;
    vector<int> ans(digit);

    for (int i = digit - 1; i >= 0; i--)
    {
        ans[i] = count % 10;
        count = count / 10;
        cout << count << endl;
    }

    // for (int i = 0; i < n; i++)
    // {

    //     if (digits[i] == 9)
    //     {
    //         if (count == 0)
    //         {
    //             ans.push_back(1);
    //         }
    //         count++;
    //     }
    //     else if (i == n - 1)
    //     {
    //         ans.push_back(digits[i] + 1);
    //     }
    //     else
    //     {
    //         ans.push_back(digits[i] + count);

    //         ans.push_back(count);
    //         count--;
    //     }
    // }

    return ans;
}

int main()
{

    vector<int> v = {9, 9};    // edge case.
    vector<int> s = {1, 2, 3}; // normal case.

    vector<int> ans = plusOne(v);
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