#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

auto start = chrono::steady_clock::now();
int main()
{

    int n;
    cin >> n;
    int arr[n];

    // using map to count the frequency of any number as value and that number as key ( key : value) ---> (number : frequency)

    // map<int, int> mpp; // always store number in sorted order.(map) its time complexity of storing and fetching is O(log n)

    unordered_map<int, int> mpp; // order of the stored element is not consistent and it keeps changing.(unordered_map)

    // unordered_map should be given priority because its time complexity is O(1) --> average and best / worst is O(n) but it rearly happens

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        mpp[arr[i]]++;
    }

    // map printing; // iterate over the map.
    for (auto it : mpp)
    {
        cout << it.first << " ---> " << it.second << endl;
    }

    int q;
    cin >> q;
    while (q--)
    {
        int number;
        cin >> number;

        cout << mpp[number] << endl;
    }

    //   Compilation Time code //
    cout << endl;
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    return 0;
}