#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

auto start = chrono::steady_clock::now();

vector<vector<int>> three_sum_brute(vector<int> &v)
{
    int n = v.size();
    set<vector<int>> s;
    // brute force solution
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (v[i] + v[j] + v[k] == 0)
                {

                    vector<int> temp = {v[i], v[j], v[k]};
                    sort(temp.begin(), temp.end());
                    s.insert(temp);
                }
            }
        }
    }
    vector<vector<int>> ans(s.begin(), s.end());
    return ans;
}

// better approach.
vector<vector<int>> three_sum_better(vector<int> &v)
{
    int n = v.size();
    set<vector<int>> s;

    // better approach
    for (int i = 0; i < n; i++)
    {
        map<int, int> mpp;
        for (int j = i + 1; j < n; j++)
        {
            int element = -(v[i] + v[j]);
            if (mpp.find(element) != mpp.end())
            {
                vector<int> temp = {v[i], v[j], element};
                sort(temp.begin(), temp.end());
                s.insert(temp);
            }
            else
            {
                mpp[v[j]] = j;
            }
        }
    }
    vector<vector<int>> ans(s.begin(), s.end());
    return ans;
}

vector<vector<int>> three_sum_optimised(vector<int> &nums)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;

    for (int i = 0; i < n; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
        {
            continue;
        }
        int j = i + 1;
        int k = n - 1;

        while (j < k)
        {
            int summation = nums[i] + nums[j] + nums[k];
            if (summation > 0)
            {
                k--;
            }
            else if (summation < 0)
            {
                j++;
            }
            else
            {
                vector<int> temp = {nums[i], nums[j], nums[k]};
                ans.push_back(temp);
                j++;
                k--;
                while (j < k && nums[j] == nums[j - 1])
                    j++;
                while (j < k && nums[k] == nums[k + 1])
                    k--;
            }
        }
    }
    // vector<vector<int>> ans(s.begin(), s.end());
    return ans;
}
//! Solved.

//? Watching other approaches.

//? 1. Finding the negative of the first element. by adding nums[j] + nums[k]

//! Example
vector<vector<int>> three_sum_optimised_others(vector<int> &nums)
{
    int n = nums.size();
    int i = 0;
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;

    while (i < n)
    {

        int j = i + 1;
        int k = n - 1;

        int to_find = -nums[i];

        while (j < k)
        {
            if (nums[j] + nums[k] == to_find)
            {
                vector<int> temp = {nums[i], nums[j], nums[k]};
                ans.push_back(temp);

                while (k > 0 && nums[k] == nums[k - 1])
                {
                    k--;
                }
                k--;
                while (j + 1 < n && nums[j] == nums[j + 1])
                {
                    j++;
                }
                j++;
            }
            else if (nums[j] + nums[k] > to_find)
            {
                while (k > 0 && nums[k] == nums[k - 1])
                {
                    k--;
                }
                k--;
            }
            else
            {
                while (j + 1 < n && nums[j] == nums[j + 1])
                {
                    j++;
                }
                j++;
            }
        }
        while (i + 1 < n && nums[i] == nums[i + 1])
        {
            i++;
        }
        i++;
    }
    return ans;
}

int main()
{
    vector<int> v = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> ans = three_sum_optimised_others(v);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    //   Compilation Time code //
    cout << endl;
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    return 0;
}