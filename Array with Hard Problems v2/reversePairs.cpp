#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

auto start = chrono::steady_clock::now();

//! Brute force approach.

int mergeSortApproach(vector<int> &arr, int low, int mid, int high)
{

    int left = low;
    int right = mid + 1;

    vector<int> temp;

    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {

            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);

            right++;
        }
    }

    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }
    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}

int countPairs(vector<int> &arr, int low, int mid, int high)
{
    int right = mid + 1;
    int cnt = 0;
    for (int i = low; i <= mid; i++)
    {
        while (right <= high && arr[i] > 2 * arr[right])
        {
            right++;
        }
        cnt += (right - (mid + 1));
    }
    return cnt;
}

int reversePairing(vector<int> &arr, int low, int high)
{
    int reversePairs = 0;

    if (low >= high)
        return reversePairs;

    int mid = (low + high) / 2;
    reversePairs += reversePairing(arr, low, mid);
    reversePairs += reversePairing(arr, mid + 1, high);
    reversePairs += countPairs(arr, low, mid, high);
    mergeSortApproach(arr, low, mid, high);
    return reversePairs;
}
int main()
{

    vector<int> v = {40, 25, 19, 12, 9, 6, 2};

    cout << reversePairing(v, 0, v.size() - 1);

    //   Compilation Time code //
    cout << endl;
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    return 0;
}