#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

auto start = chrono::steady_clock::now();

bool isIsomorphic(string s, string t)
{

    unordered_map<char, char> rep;
    unordered_map<char, bool> used;
    for (int idx = 0; idx < s.length(); idx++)
    {
        if (rep.count(s[idx]))
        {
            if (rep[s[idx]] != t[idx])
                return false;
        }
        else
        {
            if (used[t[idx]])
                return false;
            rep[s[idx]] = t[idx];
            used[t[idx]] = true;
        }
    }
    return true;
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