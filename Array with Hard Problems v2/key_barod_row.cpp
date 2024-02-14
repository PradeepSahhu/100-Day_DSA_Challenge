#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

auto start = chrono::steady_clock::now();

vector<string> findWords(vector<string> &words)
{
    map<char, int> keyToRowMp;
    vector<string> keyboardRows =
        {"qwertyuiop", "asdfghjkl", "zxcvbnm"};
    for (int i = 0; i < keyboardRows.size(); i++)
    {
        for (auto &ch : keyboardRows[i])
        {
            keyToRowMp.insert(make_pair(ch, i));
            keyToRowMp.insert(make_pair(ch - 'a' + 'A', i));
        }
    }

    vector<string> oneRowWords;
    for (auto &word : words)
    {
        bool oneRowWord = true;
        for (int i = 1; i < word.size(); i++)
        {
            if (keyToRowMp[word[i - 1]] != keyToRowMp[word[i]])
            {
                oneRowWord = false;
                break;
            }
        }
        if (oneRowWord)
            oneRowWords.push_back(word);
    }
    return oneRowWords;
}
int main()
{

    vector<string> v = {"ASDG", "QWER", "ZXC", "ADWEB"};

    vector<string> ans = findWords(v);
    for (auto it : ans)
    {
        cout << it << " ";
    }

    //   Compilation Time code //
    cout << endl;
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    return 0;
}