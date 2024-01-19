#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;
auto start = chrono::steady_clock::now();

vector<int> getFrequency(vector<int> &nums)
{
    vector<int> v;
    map<int, int> mpp;
    for (int i = 0; i < nums.size(); i++)
    {
        mpp[nums[i]]++;
    }

    int minelement = 0;
    int minfrequency = nums.size();
    int maxelement = 0;
    int maxfrequency = 0;

    for (auto it : mpp)
    {
        int element = it.first;
        int freq = it.second;
        if (freq > maxfrequency)
        {
            maxfrequency = freq;
            maxelement = element;
        }
        if (freq < minfrequency)
        {
            minelement = element;
            minfrequency = freq;
        }
    }
    v.push_back(maxelement);
    v.push_back(minelement);

    return v;
}

int main()
{

    int n;
    cin >> n;

    vector<int> nums;
    for (int i = 0; i < n; i++)
    {
        int number;
        cin >> number;
        nums.push_back(number);
    }
    vector<int> nu = getFrequency(nums);

    for (auto n : nu)
    {
        cout << n << endl;
    }

    //   Compilation Time code //
    cout << endl;
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    return 0;
}