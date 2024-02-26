
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

auto start = chrono::steady_clock::now();
int main()
{

    string str;
    cin >> str;

    // int hashArr[26] = {0}; // only works when input data is in small letters only.

    int hashArr[256] = {0}; //  when the input data is mix of everything every ASCII character.

    for (int i = 0; i < str.size(); i++)
    {
        // hashArr[str[i] - 'a']++; // only works when input data is in small letters only.

        hashArr[str[i]]++; // when the input data is mix of everything every ASCII character.
    }

    int q;
    cin >> q;

    while (q--)
    {

        char ch;
        cin >> ch;

        // cout << hashArr[ch - 'a'] << endl; // only works when input data is in small letters only.
        cout << hashArr[ch] << endl; // when the input data is mix of everything every ASCII character.
    }
    //   Compilation Time code //
    cout << endl;
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    return 0;
}