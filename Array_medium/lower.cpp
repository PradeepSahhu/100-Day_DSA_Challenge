#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <chrono>
using namespace std;

auto start = chrono::steady_clock::now();
//! First Question.
string returnString(string &value)
{
    cout << value[0] - 'a'; // a
    // for (char &c : value)
    // {
    //     if (islower(c))
    //     {
    //         c = (c - 'a' + 1) % 26 + 'a';
    //     }
    //     else if (isupper(c))
    //     {
    //         c = (c - 'A' - 1 + 26) % 26 + 'A';
    //     }
    // }

    return value;
}
//! Two Question.
char returnChar(string &value, int k)
{

    k = k % value.size();
    return value[k];
}

//! Third Question.
int maxSequenceOfsubArray(vector<int> &v)
{
    // int maxLen = 0;
    // int currLen = 0;

    // for (int i = 0; i < v.size(); i++)
    // {
    //     int sum = 0;
    //     for (int j = i; j < v.size(); j++)
    //     {
    //         sum += v[j];
    //         if (sum % 2 == 0)
    //         {
    //             currLen = j - i + 1;
    //             maxLen = max(maxLen, currLen);
    //         }
    //     }
    // }

    // for (int i = 0; i < v.size(); i++)
    // // {
    // int n = v.size();

    // int evenCount = 0;
    // int oddCount = 0;

    // for (int i = 0; i < n; ++i)
    // {
    //     if (v[i] % 2 == 0)
    //     {
    //         evenCount++;
    //     }
    //     else
    //     {
    //         oddCount++;
    //     }
    // }

    // // If the sum of all elements is even, the entire array is the required subsequence
    // if (accumulate(v.begin(), v.end(), 0) % 2 == 0)
    // {

    //     return n;
    // }

    // // If the sum is odd, exclude one odd element if there are odd elements present
    // if (oddCount > 0)
    // {
    //     return n - 1;
    // }

    // // If there are no odd elements, the entire array is the required subsequence
    // return n;

    // // return maxLen;

    vector<int> v = {1, 2};
    cout << v.size() << endl;
    int odd = 0;
    for (int num : v)
    {
        if (num % 2 != 0)
        {
            odd++;
        }
    }
    return v.size() - (odd % 2);
}
int main()
{

    string value = "abc";
    returnString(value);
    // cout << returnChar(value, 7);
    // vector<int> v = {1, 2, 3, 5};
    // cout << maxSequenceOfsubArray(v);

    //   Compilation Time code //
    cout << endl;
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    return 0;
}