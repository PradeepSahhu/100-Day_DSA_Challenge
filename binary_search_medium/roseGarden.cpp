#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

auto start = chrono::steady_clock::now();

int count_bouqet(vector<int> arr, int mid, int k)
{
    int count = 0;
    int bouqet = 0;
    for (auto it : arr)
    {
        cout << "the value of it" << it << endl;
        if (mid >= it)
        {
            count++;
        }
        else
        {
            bouqet += count / k;
            count = 0;
        }
    }
    bouqet += count / k;

    return bouqet;
}

int roseGarden(vector<int> arr, int k, int m)
{
    int n = arr.size();
    if ((k * m) > n)
        return -1;
    int left = *std::min_element(arr.begin(), arr.end());
    int right = *std::max_element(arr.begin(), arr.end());

    while (left <= right)
    {
        int mid = (left + right) / 2;
        int bouqet = count_bouqet(arr, mid, k);
        cout << mid << ":" << bouqet << endl;

        if (bouqet >= m)
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
    vector<int> arr = {7, 7, 7, 7, 13, 11, 12, 7};
    cout << roseGarden(arr, 3, 2);

    //   Compilation Time code //
    cout << endl;
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    return 0;
}