#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

auto start = chrono::steady_clock::now();

vector<int> countFrequency(int n, int x, vector<int> &nums)
{
    // Write your code here.
    vector<int> v(x, 0);

    cout << "is this running" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "this is first loop running" << endl;
        v[nums[i] - 1]++;
    }
    cout << "this is another loop running" << endl;

    // for (int i = 0; i < x; i++)
    // {
    //     cout << v[i] << " ";
    // }

    // for (int i = 0; i < x; i++)
    // {
    //     v.push_back(arr[i]);
    // }

    return v;
}
int main()
{
    int n;
    cin >> n;
    int x;
    cin >> x;
    vector<int> nums;
    for (int i = 0; i < n; i++)
    {
        int number;
        cin >> number;
        nums.push_back(number);
    }
    vector<int> nu = countFrequency(n, x, nums);

    for (int i = 0; i < x; i++)
    {
        cout << nu[i] << " ";
    }

    //   Compilation Time code //
    cout
        << endl;
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    return 0;
}