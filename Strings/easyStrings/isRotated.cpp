#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

auto start = chrono::steady_clock::now();

void rotate(string &v, int x, int y)
{
    for (int i = x, j = y; i <= j; i++, j--)
    {
        swap(v[i], v[j]);
    }
}
bool rotateString(string s, string g)
{
    string k = s;
    for (int i = 0; i < s.size(); i++)
    {
        s = k;
        rotate(s, s.size() - i, s.size() - 1);
        rotate(s, 0, s.size() - 1 - i);
        rotate(s, 0, s.size() - 1);
        if (s == g)
            return true;
    }
    return false;
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