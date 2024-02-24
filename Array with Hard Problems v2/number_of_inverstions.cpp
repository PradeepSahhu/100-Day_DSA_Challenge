#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

auto start = chrono::steady_clock::now();

int mergeSort(vector<int> &v, int low, int mid, int high)
{
    int number_of_inverstions = 0;

    int n1 = mid - low + 1;
    int n2 = high - mid;

    vector<int> v1(n1);
    vector<int> v2(n2);

    for (int i = 0; i < n1; i++)
    {
        v1[i] = v[i + low];
    }
    for (int j = 0; j < n2; j++)
    {
        v2[j] = v[mid + 1 + j];
    }

    int i = 0, j = 0;

    int k = low;

    while (i < n1 && j < n2)
    {
        if (v1[i] <= v2[j])
        {

            v[k] = (v1[i]);
            i++;
            k++;
        }
        else
        {
            number_of_inverstions += (n1 - i);
            v[k] = (v2[j]);
            j++;
            k++;
        }
    }

    while (i < n1)
    {
        v[k] = (v1[i]);
        i++;
        k++;
    }
    while (j < n2)
    {
        v[k] = (v2[j]);
        j++;
        k++;
    }

    return number_of_inverstions;
}

int numberOfInverstionsMergeSortApproach(vector<int> &v, int low, int high)
{
    int numberOfInverstions = 0;
    if (low < high)
    {
        int mid = (low + high) / 2;
        numberOfInverstions += numberOfInverstionsMergeSortApproach(v, low, mid);
        numberOfInverstions += numberOfInverstionsMergeSortApproach(v, mid + 1, high);
        numberOfInverstions += mergeSort(v, low, mid, high);
    }
    return numberOfInverstions;
}
int main()
{

    vector<int> v = {15, 28, 11, 20, 14, 7, 14, 2, 15, 4, 22, 19, 17, 1, 26, 6, 20, 2, 6};
    cout << "The number of invertions " << numberOfInverstionsMergeSortApproach(v, 0, v.size() - 1) << endl;

    //   Compilation Time code //
    cout << endl;
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    return 0;
}