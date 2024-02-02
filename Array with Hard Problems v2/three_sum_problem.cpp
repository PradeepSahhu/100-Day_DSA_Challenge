#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

auto start = chrono::steady_clock::now();

// Three sum problem.

void printvector(vector<int> &v)
{
    cout << "the temp vector is " << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}
vector<vector<int>> bruteForce(vector<int> &nums)
{

    set<vector<int>> s;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (nums[i] + nums[j] + nums[k] == 0)
                {
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    sort(temp.begin(), temp.end());
                    printvector(temp);
                    s.insert(temp);
                }
            }
        }
    }
    vector<vector<int>> ans(s.begin(), s.end());
    return ans;
}

void printmap(map<int, int> &mpp)
{
    for (auto it : mpp)
    {
        cout << it.first << " -> " << it.second << endl;
    }
}

vector<vector<int>> betterApproach(vector<int> &nums)
{
    //! using hashmap approach...

    int n = nums.size();

    set<vector<int>> s;

    for (int i = 0; i < n; i++)
    {
        map<int, int> mpp;
        for (int j = i + 1; j < n; j++)
        {

            int elementToSearch = -(nums[i] + nums[j]);
            if (mpp.find(elementToSearch) != mpp.end())
            {
                cout << mpp[elementToSearch] << endl;
                vector<int> temp = {nums[i], nums[j], elementToSearch};
                sort(temp.begin(), temp.end());
                s.insert(temp);
            }
            else
            {

                mpp[nums[j]] = j;
            }
        }
    }

    vector<vector<int>> ans(s.begin(), s.end());
    return ans;
}

int main()
{

    vector<int> v = {-1, 0, 1, 2, -1, -4};
    // vector<vector<int>> ans = bruteForce(v);
    vector<vector<int>> ans = betterApproach(v);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << "Real answer is " << endl;
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