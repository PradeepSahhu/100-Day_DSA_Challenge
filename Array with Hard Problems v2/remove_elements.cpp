#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

auto start = chrono::steady_clock::now();

int remove_elements(vector<int> &nums, int val)
{
    int modified_index = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        if (nums[i] != val)
        {
            nums[modified_index] = nums[i];
            modified_index++;
        }
    }
    return modified_index;
}

int main()
{
    vector<int> v = {3, 2, 2, 3};

    int index = remove_elements(v, 3);

    for (int i = 0; i < index; i++)
    {
        cout << v[index] << " ";
    }

    //   Compilation Time code //
    cout
        << endl;
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    return 0;
}