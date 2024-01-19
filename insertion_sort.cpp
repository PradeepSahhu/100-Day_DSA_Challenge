#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

// void insertion_sort(int arr[], int size)
// {
//     for (int i = 1; i < size; i++)
//     {
//         int min_number_index = i;

//         for (int j = i - 1; j >= 0; j--)
//         {
//             if (arr[j] > arr[min_number_index])
//             {
//                 int temp = arr[j];
//                 arr[j] = arr[min_number_index];
//                 arr[min_number_index] = temp;
//             }
//             min_number_index = j;
//         }
//     }
// }

void insertion_sort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int j = i;
        while (j > 0 && arr[j - 1] > arr[j])
        {
            int temp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = temp;
            j--;
        }
    }
}
auto start = chrono::steady_clock::now();
int main()
{

    int arr[] = {4, 3, 6, 7, 1, 1, 2, 9, 10, 5};
    insertion_sort(arr, 10);

    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }

    //   Compilation Time code //
    cout
        << endl;
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    return 0;
}