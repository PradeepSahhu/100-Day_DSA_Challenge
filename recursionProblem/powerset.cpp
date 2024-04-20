#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

auto start = chrono::steady_clock::now();


vector<vector<int>> subsets(vector<int> &nums)
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

//   Compilation Time code //
cout << endl;
auto end = chrono::steady_clock::now();
auto diff = end - start;
cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
return 0;
}