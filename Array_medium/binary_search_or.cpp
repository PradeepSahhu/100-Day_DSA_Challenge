#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

auto start = chrono::steady_clock::now();

int binary_sear(vector<int> &nums, int target)
{

    int start = 0;
    int end = nums.size();
    int middle = (start + end) / 2;

    if (target > nums[end - 1])
    {
        return end;
    }

    
    while (start <= end)
    {
        cout << "Working" << endl;
        if (nums[middle] == target)
        {
        }
        else if (nums[middle] > target)
        {
            end = middle - 1;
        }
        else
        {
            start = middle + 1;
        }
        middle = (start + end) / 2;
    }

    // return shouldbe;

    // if(nums[shouldbe]> target){
    //     return shouldbe-1;
    // }else{
    //     return shouldbe+1;
    // }

    return start;
}
int main()
{

    vector<int> v = {1, 3, 5, 7, 11};

    cout << binary_sear(v, 2);

    //   Compilation Time code //
    cout << endl;
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    return 0;
}
