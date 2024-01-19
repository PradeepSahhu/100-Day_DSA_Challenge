#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

auto start = chrono::steady_clock::now();

void shifting(vector<int> &arr, int d)
{
    d = (d % arr.size());
    // vector<int> a(d);

    // for (int i = 0; i < d; i++)
    // {
    //     a[i] = arr[i];
    // }
    // for (int i = 0; i < arr.size() - d; i++)
    // {
    //     arr[i] = arr[i + d];
    // }
    // for (int i = 0; i < d; i++)
    // {
    //     arr[arr.size() - d + i] = a[i];
    // }

    while (d--)
    {
        int temp = arr[0];

        for (int i = 0; i < arr.size() - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        arr[arr.size() - 1] = temp;
    }
}

void rev(int arr[], int start, int end)
{
    while (start <= end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void left_shift(int arr[], int n, int d)
{
    // reverse(arr, (arr + d));
    // reverse(arr + d, arr + n);
    // reverse(arr, arr + n);
    rev(arr, 0, d - 1);
    rev(arr, d, n - 1);
    rev(arr, 0, n - 1);
}
int main()
{
    int a[] = {2, 3, 7, 1, 8};
    int size = sizeof(a) / sizeof(a[0]);
    vector<int> arr(a, a + size);
    int d;
    cout << "Enter the shifting position" << endl;
    cin >> d;

    // shifting(arr, d);
    left_shift(a, size, d);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << a[i] << " ";
    }
    //   Compilation Time code //
    cout << endl;
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    return 0;
}