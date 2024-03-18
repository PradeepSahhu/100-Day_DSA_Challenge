#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

auto start = chrono::steady_clock::now();
string largestOddNumber(string num)
{

    int len = num.size();
    bool append = false;
    string res = "";
    for (int i = len - 1; i >= 0; i--)
    {
        if ((num[i] - '0') & 1) // convert from string digit to integer, then check it is odd, as the LSB must be 1
            append = true;
        if (append)
            res += num[i];
    }
    reverse(res.begin(), res.end());
    return res;
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