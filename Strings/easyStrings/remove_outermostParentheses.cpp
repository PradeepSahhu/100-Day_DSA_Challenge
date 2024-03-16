#include <iostream>
#include <bits/stdc++.h>
#include <chrono>

using namespace std;

auto start = chrono::steady_clock::now();

string removeOuterParentheses(string s)
{
    int total = 0;
    string ans = "";

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(' && total == 0)
        {
            total++;
        }
        else if (s[i] == '(' && total > 0)
        {
            ans += '(';
            total++;
        }
        else if (s[i] == ')' && total > 1)
        {
            ans += ')';
            total--;
        }
        else
        {
            total--;
        }
    }

    return ans;
}

int main()
{

    //   Compilation Time code //
    cout << endl;
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    return 0;
}