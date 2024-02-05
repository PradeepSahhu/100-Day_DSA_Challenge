#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

auto start = chrono::steady_clock::now();

vector<int> plusOne(vector<int> &digits)
{

    int n = digits.size();

    for (int i = n - 1; i >= 0; i--)
    {
        if (digits[i] < 9)
        {
            digits[i]++;
            cout << "The value of digits are " << digits[i] << endl;
            return digits; // incrementing the last index and returning the whole list.
        }
        digits[i] = 0; // if the last index is 9 then settting it to 0 and running it for last-1 index.
    }
    digits.insert(digits.begin(), 1); // if the list is not terminated in the loop then it means it has 9,9,9 elements in the array. hence inserting the 1 in the beginning.
    return digits;                    // returning the funciton.
}

int main()
{

    vector<int> v = {9, 9};    // edge case.
    vector<int> s = {1, 2, 9}; // normal case.

    vector<int> ans = plusOne(s);
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