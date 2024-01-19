#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

auto start = chrono::steady_clock::now();

// void move_all_zeroes(int n, vector<int> &arr)
// {

//     int j = 0;
//     for (int i = 0; i < n; i++)
//     {
//         if (arr[i] != 0)
//         {
//             // cout << "this is being called" << endl;
//             swap(arr[i], arr[j]);
//             j++;
//         }
//     }
// }
void move_all_zeroes(int n, vector<int> &arr)
{

    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            // cout << "this is being called" << endl;
            j = i;
            break;
        }
    }
    for (int i = j + 1; i < n; i++)
    {
        if (arr[i] != 0)
        {
            swap(arr[i], arr[j]);
            j++;
        }
    }
}
int main()
{
    int a[] = {1, 0, 2, 3, 2, 0, 0, 4, 5, 1};

    int size = sizeof(a) / sizeof(a[0]);

    vector<int> arr(a, a + size);

    move_all_zeroes(size, arr);

    for (int i = 0; i < arr.size(); i++)
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