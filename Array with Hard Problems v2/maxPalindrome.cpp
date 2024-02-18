#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

auto start = chrono::steady_clock::now();

int maxPalindromesAfterOperations(vector<string> &words)
{
    
}
int ain()
{
    vector<string> words = {"abbb", "ba", "aa"};
    cout << maxPalindromesAfterOperations(words);

    //   Compilation Time code //
    cout << endl;
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    return 0;
}