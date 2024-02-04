#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

auto start = chrono::steady_clock::now();

int extractLastWord(string s)
{
    // int lastSpace = s.rfind(" ");
    int length = s.size();
    string word;

    for (int i = length - 1; i >= 0; i--)
    {
        if (i != length - 1 && s[i] == ' ' && s[i + 1] != ' ')
            break;
        if (s[i] == ' ')
            continue;
        word += s[i];
    }
    return word.size();

    // string lastWord;
    // if (s[lastSpace - 1] != ' ')
    // {
    //     lastWord = s.substr(lastSpace + 1);
    // }
    // else
    // {
    //     lastWord = s.substr(lastSpace - 1);
    // }

    // cout << "last word is: " << lastWord << endl;
    // return lastWord.size();
}
int main()
{
    string message = "I love programming "; // 11

    cout << extractLastWord(message);

    //   Compilation Time code //
    cout << endl;
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    return 0;
}