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
    int numberOfInverstions = 0;
    int n1 = mid - low + 1;
    int n2 = high - mid;

    vector<int> v1(n1);
    vector<int> v2(n2);

    for (int i = 0; i < n1; i++)
    {
        v1[i] = arr[low + i];
    }
    for (int j = 0; j < n2; j++)
    {
        v2[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = low;

    while (i <= n1 && j <= n2)
    {
        if (v1[i] <= v2[j])
        {

            arr[k] = v1[i];
            i++;
            k++;
        }
        else
        {
            arr[k] = v2[j];
            numberOfInverstions += mid - i + 1;
            j++;
            k++;
        }
    }

    while (i < n1)
    {
        arr[k] = v1[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = v2[j];
        j++;
        k++;
    }
    return numberOfInverstions;
}
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
    vector<int> v = {5, 3, 2, 4, 1};
    cout << "The number of invertions " << numberOfInverstionsMergeSortApproach(v, 0, v.size() - 1) << endl;

    //   Compilation Time code //
    cout << endl;
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    return 0;
}