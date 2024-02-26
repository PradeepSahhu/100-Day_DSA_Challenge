#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

void selection_sort(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        int smallest = i;
        for (int j = i; j < size; j++)
        {
            if (arr[smallest] > arr[j])
            {
                smallest = j;
            }
        }
        int temp = arr[smallest];
        arr[smallest] = arr[i];

        arr[i] = temp;
    }

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

auto start = chrono::steady_clock::now();
int main()
{

    int arr[] = {4, 5, 7, 1, 2, 4, 9, 10};
    selection_sort(arr, 8);

    //   Compilation Time code //
    cout << endl;
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    return 0;
}