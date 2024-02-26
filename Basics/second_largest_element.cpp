#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

auto start = chrono::steady_clock::now();

void second_largest(vector<int> &arr)
{
    int largest = arr[0];
    int second_l = -1;

    for (int i = 1; i < arr.size(); i++) // O(n)
    {

        if (arr[i] > largest)
        {
            second_l = largest;
            largest = arr[i];
        }
        else if (arr[i] < largest && arr[i] > second_l)
        {
            second_l = arr[i];
        }
    }

    cout << "Largest element is : " << largest << endl;
    cout << "Second largest element is: " << second_l << endl;
}

void second_smallest(vector<int> &arr)
{

    int smallest = arr[0];
    int second_s = INT_MAX;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] < smallest)
        {
            second_s = smallest;
            smallest = arr[i];
        }
        else if (arr[i] > smallest && arr[i] < second_s)
        {
            second_s = arr[i];
        }
    }

    cout << "The smallest element is : " << smallest << endl;
    cout << "The second smallest element is : " << second_s << endl;
}

void sorted_or_not(vector<int> &arr)
{
    bool isSorted = true;

    for (int i = 1; i < arr.size(); i++)
    {
        if (!(arr[i] >= arr[i - 1]))
        {
            isSorted = false;
            break;
        }
        // else{
        //     return false;
        // }

        // return true;
    }

    if (isSorted)
    {
        cout << "The array is sorted" << endl;
    }
    else
    {
        cout << "The array is not sorted" << endl;
    }
}
int main()
{

    // int a[] = {1, 2, 7, 8, 32, 4, 5, 87, 98, 99};
    int a[] = {1, 2, 3, 4, 5, 6, 7, 1};
    int size = sizeof(a) / sizeof(a[0]);
    vector<int> arr(a, a + size);

    // second_largest(arr);
    // second_smallest(arr);
    sorted_or_not(arr);

    //   Compilation Time code //
    cout << endl;
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    return 0;
}