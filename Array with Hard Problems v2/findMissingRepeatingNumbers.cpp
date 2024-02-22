#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

auto start = chrono::steady_clock::now();
//! solved but taking so much time in top 8. something.
vector<int> findMissingRepeatingNumbers(vector<int> a)
{
    // Write your code here

    int n = a.size();
    sort(a.begin(), a.end());
    vector<int> ans;
    int missing = 0;
    int repeated;

    for (int i = 0; i < n; i++)
    {
        // cout << a[i] << " ";
        // missing = missing^i+1;

        // cout << "The value of missing is : " << missing << endl;
        if (a[i] == a[i + 1])
        {
            repeated = a[i];
        }
        missing = missing ^ (i + 1);
        missing = missing ^ a[i];
    }
    missing = missing ^ repeated;
    // missing = missing ^ repeated;

    ans.push_back(repeated);
    ans.push_back(missing);

    return ans;
}
//! working good but TLX (time limit exceeded)

vector<int> findMissingRepeatingNumbering(vector<int> a)
{
    map<int, int> mpp;
    sort(a.begin(), a.end());
    int n = a.size();
    int missing;
    int repeated;
    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        mpp[a[i]]++;
    }

    for (int i = 0; i < n; i++)
    {
        if (mpp.find(i + 1) == mpp.end())
        {
            missing = i + 1;
        }
        if (mpp[i + 1] > 1)
        {
            repeated = i + 1;
        }
    }
    ans.push_back(repeated);
    ans.push_back(missing);

    return ans;
}
vector<int> findMissingRepeatingFormulaApproach(vector<int> a)
{

    sort(a.begin(), a.end());
    int n = a.size();
    int missing;
    int repeated;
    int summation = n * (n + 1) / 2;
    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        // cout << a[i] << " ";
        // missing = missing^i+1;

        // cout << "The value of missing is : " << missing << endl;
        if (a[i] == a[i + 1])
        {
            repeated = a[i];
        }
        // missing = missing ^ (i + 1);
        // missing = missing ^ a[i];
        summation -= a[i];
    }
    summation = summation + repeated;

    ans.push_back(repeated);
    ans.push_back(summation);

    return ans;
}

vector<int> findMissingRepeatingMathematicsApproach(vector<int> a)
{
    long long n = a.size();

    long long summation = n * (n + 1) / 2;
    long long squareSummation = (n * (n + 1) * (2 * n + 1)) / 6;
    long long x = 0;
    long long y = 0;

    // cout << "the summation value is :" << summation << endl;
    // cout << "the square summation value is: " << squareSummation << endl;

    for (int i = 0; i < n; i++)
    {
        // cout << "the value of y is " << y << endl;
        x += a[i];
        y += a[i] * a[i];
    }
    cout << x << " : " << y << endl;

    long long eq1 = x - summation;
    long long eq2 = y - squareSummation;
    eq2 = eq2 / eq1;

    long long repeatingNumber = (eq1 + eq2) / 2;
    long long missingNumber = eq2 - repeatingNumber;

    return {(int)repeatingNumber, (int)missingNumber};
}

int main()
{

    // vector<int> v = {8, 4, 1, 6, 7, 2, 5, 8};
    vector<int> v = {10, 11, 1, 12, 3, 4, 13, 8, 2, 6, 7, 9, 5, 3};
    // vector<int> v = {4, 6, 3, 2, 1, 1};

    vector<int>
        ans = findMissingRepeatingMathematicsApproach(v);
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