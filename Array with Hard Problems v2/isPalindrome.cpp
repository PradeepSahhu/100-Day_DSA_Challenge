#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

auto start = chrono::steady_clock::now();

bool valid_palindrome(string s)
{

    int n = s.size();

    string ans;

    for (auto it : s)
    {

        if (isalnum(it))
        {
            ans += tolower(it);
        }
    }
    n = ans.size();

    int left = 0, right = n - 1;

    while (left <= right)
    {
        if (ans[left] != ans[right])
        {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

int main()
{
    // is a string palindrome

    string value = "rac a car";
    //   Compilation Time code //

    cout << valid_palindrome(value);
    cout
        << endl;
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    return 0;
}