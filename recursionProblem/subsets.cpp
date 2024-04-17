#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

auto start = chrono::steady_clock::now();

vector<vector<string>> subsets(string s)
{
    vector<vector<string>> vec;

    int n = s.size();
    // cout<<"The size of n is : "<<n<<endl;

    int x = (1 << n) - 1; // 2^n-1
    // cout<<"The value of x is: "<<x<<endl;

    for (int num = 0; num <= x; num++)
    {
        vector<string> temp;
        string substr = "";

        for (int i = 0; i <= n - 1; i++)
        {

            if (num & (1 << i))
            {
                substr+=s[i];
            }
        }
        temp.push_back(substr);
        vec.push_back(temp);
        cout<<substr<<" ";
    }

    // cout << x << endl;

    return vec;
}

vector<vector<int>> subset(vector<int> &nums)
{
    vector<vector<int>> vec;

    int n = nums.size();
    // cout<<"The size of n is : "<<n<<endl;

    int x = (1 << n) - 1; // 2^n-1
    // cout<<"The value of x is: "<<x<<endl;

    for (int num = 0; num <= x; num++)
    {
        vector<int> temp;
        // int substr;

        for (int i = 0; i <= n - 1; i++)
        {

            if (num & (1 << i))
            {
                temp.push_back(nums[i]);
                // substr = nums[i];
              
            }
             
        }
        // temp.push_back(substr);
       
        vec.push_back(temp);
    }

    // cout << x << endl;

    return vec;
}


int main()
{

    string s = "abc";
    vector<int> temp = {1,2,3};
    vector<vector<int>> ans = subset(temp);
    cout<<endl;

    for(int i = 0;i<ans.size();i++){
        cout<<'[';
        for(int j = 0;j<ans[i].size();j++){
            cout<<ans[i][j];
        }
        cout<<']'<<endl;
    }

    //   Compilation Time code //
    cout << endl;
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    return 0;
}