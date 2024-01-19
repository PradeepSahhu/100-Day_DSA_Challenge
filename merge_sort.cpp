#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

auto start = chrono::steady_clock::now();

void merge(vector<int> &arr, int low, int mid, int high)
{
    int size1 = mid - low + 1;
    int size2 = high - mid;
    int arr1[size1];
    int arr2[size2];

    for (int i = 0; i < size1; i++)
    {
        arr1[i] = arr[low + i];
    }
    for (int j = 0; j < size2; j++)
    {
        arr2[j] = arr[mid + 1 + j];
    }

    int i = 0;
    int j = 0;
    int main_index = low; // ?: Read about this later.

    while (i < size1 && j < size2)
    {
        if (arr1[i] <= arr2[j])
        {
            arr[main_index] = arr1[i];
            i++;
            main_index++;
        }
        else
        {
            arr[main_index] = arr2[j];
            j++;
            main_index++;
        }
    }

    while (i < size1)
    {
        arr[main_index] = arr1[i];
        i++;
        main_index++;
    }
    while (j < size2)
    {
        arr[main_index] = arr2[j];
        j++;
        main_index++;
    }
}
// int *merge(vector<int> &arr, int low, int mid, int high)
// {
//     int left = low;
//     int right = mid + 1;

//     vector<int> temp;

//     while (left <= mid && right <= high)
//     {
//         if (arr[left] <= arr[right])
//         {
//             temp.push_back(arr[left]);
//             left++;
//         }
//         else
//         {
//             temp.push_back(arr[right]);
//             right++;
//         }
//     }

//     while (left <= mid)
//     {
//         temp.push_back(arr[left]);
//         left++;
//     }
//     while (right <= high)
//     {
//         temp.push_back(arr[right]);
//         right++;
//     }

//     for (int i = low; i <= high; i++)
//     {
//         arr[i] = temp[i - low];
//     }
// }

void merge_sort(vector<int> &arr, int low, int high)
{
    if (low >= high)
        return;

    int mid = (low + high) / 2;
    merge_sort(arr, low, mid);
    merge_sort(arr, mid + 1, high);

    merge(arr, low, mid, high);
}
int main()
{

    int a[] = {1, 8, 2, 2, 8, 7, 10, 88, 44, 22};
    int n = 10;

    vector<int> arr(a, a + n);

    int size = 10;
    merge_sort(arr, 0, size - 1);

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    //   Compilation Time code //
    cout << endl;
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    return 0;
}