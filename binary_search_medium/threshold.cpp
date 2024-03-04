#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

auto start = chrono::steady_clock::now();

int counting_dividents(vector<int> &nums, int val, int threshold)
{
    int dividents = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        dividents += ceil((double)(nums[i]) / (double)(val));
    }
    if (dividents <= threshold)
        return 0;
    return 1;
}

int smallestDivisor(vector<int> &nums, int threshold)
{
    int n = nums.size();
    if (n > threshold)
        return -1;
    int left = 1;
    int right = *std::max_element(nums.begin(), nums.end());

    while (left <= right)
    {
        int mid = (left + right) / 2;
        int result = counting_dividents(nums, mid, threshold);
        if (result == 0)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return left;
}
int main()
{

    vector<int> v = {1, 2, 5, 9};

    cout << smallestDivisor(v, 6);

    //   Compilation Time code //
    cout << endl;
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    return 0;
}