#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

auto start = chrono::steady_clock::now();

vector<string> summaryRanges(vector<int> &nums)
{

    int n = nums.size();

    vector<string> ans;
    int start = 0;

    for (int i = 0; i < n; i++)
    {
        if (nums[i] + 1 != nums[i + 1])
        {

            if (start == i)
            {
                string a = to_string(nums[i]);
                ans.push_back(a);
            }
            else
            {
                string val = to_string(nums[start]) + "->" + to_string(nums[i]);
                ans.push_back(val);
            }

            start = i + 1;
        }
    }

    return ans;
}
vector<string> summaryRangeing(vector<int> &nums)
{

    int n = nums.size();

    vector<string> ans;

    for (int i = 0; i < n; i++)
    {
        int start = nums[i];
        while (i < n - 1 && nums[i] + 1 == nums[i + 1])
        {
            i++;
        }
        if (start != nums[i])
            ans.push_back(to_string(start) + "->" + to_string(nums[i]));
        else
            ans.push_back(to_string(start));
    }

    return ans;
}
int main()
{
    vector<int> v = {1, 2, 4, 5, 6, 9};

    vector<string> ans = summaryRangeing(v);
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