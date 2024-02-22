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
    int missing = 0;
    int repeated;

    for (int i = 0; i < n - 1; i++)
    {
        cout << a[i] << " ";
        // missing = missing^i+1;
        missing = missing ^ (i + 1);
        missing = missing ^ a[i];
        cout << "The value of missing is : " << missing << endl;
        if (a[i] == a[i + 1])
        {
            repeated = a[i];
        }
        cout << 8 ^ 3 << endl;
    }

    cout << endl;
    ans.push_back(repeated);
    ans.push_back(missing);

    return ans;
}
int main()
{

    vector<int> v = {8, 4, 1, 6, 7, 2, 5, 8};

    vector<int> ans = findMissingRepeatingNumbers(v);
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