#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

auto start = chrono::steady_clock::now();

string reverseWords(string s)
{
    int left = 0;
    int right = s.length() - 1;

    string temp = "";
    string ans = "";

    while (left <= right)
    {
        char ch = s[left];
        if (ch != ' ')
        {
            temp += ch;
        }
        else if (temp != "")
        {
            if (ans != "")
                ans = temp + " " + ans;
            else
                ans = temp;
            temp = "";
        }
        left++;
    }

    if (temp != "")
    {
        if (ans != "")
            ans = temp + " " + ans;
        else
            ans = temp;
    }

    return ans;
}

int main()
{
    string value = "This is by me";
    string ans = reverseWords(value);
    cout << ans;

    //   Compilation Time code //
    cout << endl;
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    return 0;
}