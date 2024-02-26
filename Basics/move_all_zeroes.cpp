#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

void move_all_zero(vector<int> &arr)
{
    int i = 0;
    int j = arr.size() - 1;
    while (i < j)
    {
        while (arr[i] != 0)
        {
            i++;
        }
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        j--;
    }
}

void left_shift(vector<int> &arr, int index)
{
    int temp = arr[index];
    for (int i = index; i < arr.size() - 1; i++)
    {
        // cout << "value of i is :" << i << " and value at i+1 is : " << arr[i + 1] << endl;
        arr[i] = arr[i + 1];
    }

    arr[arr.size() - 1] = temp;
}

void move_zeroes(vector<int> &arr)
{
    int zero_count = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == 0)
        {
            zero_count++;
        }
    }

    for (int i = 0; i < arr.size() - zero_count; i++)
    {
        if (arr[i] == 0)
        {
            left_shift(arr, i);
            i = i - 1;
        }
    }
}

vector<int> move_all_zeroes(vector<int> &a)
{
    vector<int> arr;
    int j = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] != 0)
        {
            j++;

            arr.push_back(a[i]);
        }
    }
    int value = a.size() - j;
    while (value--)
    {
        arr.push_back(0);
    }
    return arr;
}

auto start = chrono::steady_clock::now();
int main()
{
    int a[] = {1, 0, 2, 3, 2, 0, 0, 4, 5, 1};

    int size = sizeof(a) / sizeof(a[0]);

    vector<int> arr(a, a + size);

    // move_zeroes(arr);
    vector<int> ab = move_all_zeroes(arr);

    for (int i = 0; i < ab.size(); i++)
    {
        cout << ab[i] << " ";
    }

    //   Compilation Time code //
    cout << endl;
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    return 0;
}