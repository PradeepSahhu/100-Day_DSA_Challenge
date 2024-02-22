#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

auto start = chrono::steady_clock::now();
vector<int> findMissingRepeatingNumbers(vector<int> a)
{
    // Write your code here

    int n = a.size();
    sort(a.begin(), a.end());
    vector<int> ans;
    int missing;
    int repeated;

    for (int i = 0; i < n; i++)
    {

        if (a[i] != i + 1)
        {
            missing = i + 1;
            repeated = a[i];
        }
    }
    ans.push_back(repeated);
    ans.push_back(missing);

    return ans;
}
int main()
{

    vector<int> v = {8, 4, 1, 6, 7, 2, 5, 8};

    findMissingRepeatingNumbers(v);
    //   Compilation Time code //
    cout << endl;
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    return 0;
}