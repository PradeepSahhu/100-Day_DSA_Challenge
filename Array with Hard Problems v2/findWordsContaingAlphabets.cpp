#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

auto start = chrono::steady_clock::now();

vector<int> findWordsContaining(vector<string> &words, char x)
{
    vector<int> ans;

    //! Here the code goes
    for (int i = 0; i < words.size(); i++)
    {

        for (int j = 0; j < words[i].size(); j++)
        {
            if (words[i][j] == x)
            {
                ans.push_back(i);
                break;
            }
        }
    }
    return ans;
}

vector<int> findWordsContainings(vector<string> &words, string x)
{
    vector<int> ans;

    //! Here the code goes
    for (int i = 0; i < words.size(); i++)
    {

        if (words[i].find(x) != string::npos) //! this can be used to find the sequence of characters from the given string.
        {
            ans.push_back(i);
        }
    }
    return ans;
}
int main()
{
    vector<string> words = {"abbbaa", "baab", "aa"};
    vector<int> ans = findWordsContainings(words, "aab");
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    //   Compilation Time code //
    cout << endl;
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    return 0;
}