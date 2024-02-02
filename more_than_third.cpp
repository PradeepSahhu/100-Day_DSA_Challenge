#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

auto start = chrono::steady_clock::now();

vector<int> more_than_one_third(vector<int> &nums)
{

    int n = nums.size();
    int lens = (n / 3);
    map<int, int> mpp;
    vector<int> ans(0);
    cout << "the lens is " << lens << endl;

    for (int i = 0; i < n; i++)
    {
        cout << "The current element is repeated " << mpp[nums[i]] << endl;
        mpp[nums[i]]++;
        if (mpp[nums[i]] == lens)
        {
            cout << "this is executing" << endl;
            ans.push_back(nums[i]);
        }
        if (ans.size() == 2)
            break;
    }
    sort(ans.begin(), ans.end());
    return ans;
}
int main()
{

    vector<int> v = {1, 1, 1, 1, 3, 2, 2, 2};
    // vector<int> v = {1, 2, 3};

    vector<int> ans = more_than_one_third(v);
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