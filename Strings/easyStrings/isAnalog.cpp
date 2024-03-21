
#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

auto start = chrono::steady_clock::now();
int main()
{

    //   Compilation Time code //
    cout << endl;
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    return 0;
}

bool isAnagram(string s, string t)
{
    int count[26] = {0};

    // Count the frequency of characters in string s
    for (char x : s)
    {
        count[x - 'a']++;
    }

    // Decrement the frequency of characters in string t
    for (char x : t)
    {
        count[x - 'a']--;
    }

    // Check if any character has non-zero frequency
    for (int val : count)
    {
        if (val != 0)
        {
            return false;
        }
    }

    return true;
}