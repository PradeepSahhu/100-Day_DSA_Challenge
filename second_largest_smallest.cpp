#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

void second_largest_sm(vector<int> arr)
{

    int largest = arr[0];
    int second_largest = arr[0];

    int smallest = arr[0];
    int second_smallest = INT_MAX;

    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] > largest)
        {
            second_largest = largest;
            largest = arr[i];
        }
        else if (largest > arr[i] && second_largest < arr[i])
        {
            second_largest = arr[i];
        }

        if (arr[i] < smallest)
        {
            second_smallest = smallest;
            smallest = arr[i];
        }
        else if (arr[i] > smallest && second_smallest > arr[i])
        {
            second_smallest = arr[i];
        }
    }

    cout << "The largest nubmer is :" << largest << endl;
    cout << "The second_largest is :" << second_largest << endl;
    cout << "The smallest element is : " << smallest << endl;
    cout << "The second_smallest is : " << second_smallest << endl;
}

auto start = chrono::steady_clock::now();
int main()
{

    int a[] = {2, 99, 8, 9, 22, 88, 56, 44, 98, 102, 34, 76};
    int size = sizeof(a) / sizeof(a[0]);

    vector<int> arr(a, a + size);

    second_largest_sm(arr);

    //   Compilation Time code //
    cout << endl;
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    return 0;
}