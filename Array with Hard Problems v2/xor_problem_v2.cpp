#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

auto start = chrono::steady_clock::now();

int number_of_subArrays_equal_to_that_xor(vector<int> &nums, int k)
{
    int count = 0;
    map<int, int> mpp;
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        int xor_of_number = xor_of_number ^ nums[i];

        int rem = xor_of_number ^ k;

        count += mpp[rem];

        mpp[xor_of_number] += 1;
    }
    return count;
}
int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    cout << number_of_subArrays_equal_to_that_xor(v, 3);

    //   Compilation Time code //
    cout << endl;
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    return 0;
}