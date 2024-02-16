#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

auto start = chrono::steady_clock::now();

int strStr(string haystack, string needle)
{
    //! not working
    int m = needle.size();
    int n = haystack.size();
    if (m > n)
    {
        return -1;
    }

    int index = -1;

    int needleIndex = 0;

    for (int i = 0; i < n; i++)
    {
        if (haystack[i] == needle[needleIndex])
        {
            needleIndex++;
            if (index == -1)
            {
                index = i;
            }
            if (needleIndex == m)
            {
                break;
            }
        }
        else
        {
            needleIndex = 0;
            index = -1;
        }
    }
    return index;
}

int strStrs(string haystack, string needle)
{
    int m = needle.size();
    int n = haystack.size();

    for (int i = 0; i < n; i++)
    {
        if (needle == haystack.substr(i, m))
        {
            return i;
        }
    }
    return -1;
}

int main()
{

    string needle = "issip";
    string haystack = "mississippi";
    cout << strStrs(haystack, needle);

    //   Compilation Time code //
    cout << endl;
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    return 0;
}