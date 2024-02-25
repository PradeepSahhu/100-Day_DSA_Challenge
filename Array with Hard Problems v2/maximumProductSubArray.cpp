#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

auto start = chrono::steady_clock::now();

int maximumProduct(vector<int> &nums)
{
    //! Brute force approach.
    int n = nums.size();
    int maxProduct = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        int currentProduct = nums[i];
        for (int j = i + 1; j < n; j++)
        {
            currentProduct = currentProduct * nums[j];
            maxProduct = max(maxProduct, currentProduct);
        }
    }
    return maxProduct;
}

//! Working Brute Force approach.
int maxProduct(vector<int> &nums)
{

    //! Brute force approach.
    int n = nums.size();
    int maxProduct = INT_MIN;

    if (n == 1)
    {
        return nums[0];
    }

    for (int i = 0; i < n; i++)
    {
        int currentProduct = 1;
        for (int j = i; j < n; j++)
        {
            currentProduct = currentProduct * nums[j];
            maxProduct = max(maxProduct, currentProduct);
        }
    }
    return maxProduct;
}

//! Most optimum approach.

int maxyProduct(vector<int> &nums)
{
    int n = nums.size();
    int maxProduct = INT_MIN;

    int prod = 1;

    for (int i = 0; i < n; i++)
    {
        prod = prod * nums[i];
        maxProduct = max(maxProduct, prod);

        if (nums[i] == 0)
        {
            prod = 1;
        }
    }
    prod = 1;
    for (int i = n - 1; i >= 0; i--)
    {

        prod = prod * nums[i];
        maxProduct = max(maxProduct, prod);

        if (nums[i] == 0)
        {
            prod = 1;
        }
    }
    return maxProduct;
}
int SmallermaxyProduct(vector<int> &nums)
{
    int n = nums.size();
    int maxProduct = INT_MIN;

    int prefixProduct = 1, suffixProduct = 1;

    for (int i = 0; i < n; i++)
    {

        if (nums[i] == 0)
        {
            prefixProduct = 1;
        }
        if (nums[n - i - 1] == 0)
        {
            suffixProduct = 1;
        }
        prefixProduct = prefixProduct * nums[i];
        suffixProduct *= nums[n - i - 1];
        maxProduct = max(maxProduct, max(prefixProduct, suffixProduct));
    }

    return maxProduct;
}
int main()
{
    vector<int> v = {2, 3, -2, 4};

    cout << SmallermaxyProduct(v);

    //   Compilation Time code //
    cout << endl;
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    return 0;
}