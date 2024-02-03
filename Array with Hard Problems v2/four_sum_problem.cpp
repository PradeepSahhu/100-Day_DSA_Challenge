#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

auto start = chrono::steady_clock::now();

vector<vector<int>> bruteForce(vector<int> &nums, int target)
{
    int n = nums.size();
    set<vector<int>> s;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                for (int l = k + 1; l < n; l++)
                {
                    if (nums[i] + nums[j] + nums[k] + nums[l] == target)
                    {
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        sort(temp.begin(), temp.end());
                        s.insert(temp);
                    }
                }
            }
        }
    }
    vector<vector<int>> ans(s.begin(), s.end());
    return ans;
}
vector<vector<int>> BetterApproach(vector<int> &nums, int target)
{
    int n = nums.size();
    set<vector<int>> s;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            map<int, int> mpp;
            for (int k = j + 1; k < n; k++)
            {
                int element = target - (nums[i] + nums[j] + nums[k]);
                if (mpp.find(element) != mpp.end())
                {

                    vector<int> temp = {nums[i], nums[j], nums[k], element};
                    sort(temp.begin(), temp.end());
                    s.insert(temp);
                }
                else
                {
                    mpp[nums[k]] = k;
                }
            }
        }
    }
    vector<vector<int>> ans(s.begin(), s.end());
    return ans;
}

vector<vector<int>> bestApproach(vector<int> &nums, int target)
{
    
}

int main()
{

    vector<int> v = {1, 0, -1, 0, -2, 2};
    // vector<vector<int>> ans = bruteForce(v, 0);
    vector<vector<int>> ans = BetterApproach(v, 3);

    cout << "My answer" << endl;
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