#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

auto start = chrono::steady_clock::now();

int numberOfInverstions(vector<int> &arr)
{
    int no_of_inversion = 0;
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                no_of_inversion++;
            }
        }
    }
    return no_of_inversion;
}

int mergeSortApproach(vector<int> &arr, int low, int mid, int high)
{
    int no_inversions = 0;
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
            no_inversions += (mid - left + 1);
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
    cout << "The no of inverstions" << no_inversions << endl;

    return no_inversions;
}
//! working.
int numberOfInverstionsMergeSortApproach(vector<int> &arr, int low, int high)
{
    int numberOfInverstions = 0;

    if (low >= high)
        return numberOfInverstions;

    int mid = (low + high) / 2;
    numberOfInverstions += numberOfInverstionsMergeSortApproach(arr, low, mid);
    numberOfInverstions += numberOfInverstionsMergeSortApproach(arr, mid + 1, high);
    numberOfInverstions += mergeSortApproach(arr, low, mid, high);
    return numberOfInverstions;
}
int main()
{
    vector<int> v = {4, 3, 2, 1};
    cout << "The number of invertions " << numberOfInverstionsMergeSortApproach(v, 0, v.size() - 1) << endl;

    //   Compilation Time code //
    cout << endl;
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    return 0;
}