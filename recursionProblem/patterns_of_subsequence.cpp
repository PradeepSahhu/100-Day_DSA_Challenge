#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

auto start = chrono::steady_clock::now();


//! Print all SubSequence.

void printS(int ind, vector<int> ds, int s, int sum, vector<int> arr, int n)
{
    if (ind == n)
    {
        if (s == sum)
        {
            for (auto it : ds)
                cout << it << " ";
            cout << endl;
        }
        return;
    }

    ds.push_back(arr[ind]);
    s += arr[ind];

    printS(ind + 1, ds, s, sum, arr, n);


    s -= arr[ind];
    ds.pop_back();

    printS(ind + 1, ds, s, sum, arr, n);
}

//! print only one subsequence

bool printSing(int ind, vector<int> ds, int s, int sum, vector<int> arr, int n)
{
    if (ind == n)
    {
        //condition satisfied
        if (s == sum)
        {
            for (auto it : ds)
                cout << it << " ";
            cout << endl;
            return true;
        }
        else return false;
    }

    ds.push_back(arr[ind]);
    s += arr[ind];

    if(printSing(ind + 1, ds, s, sum, arr, n)==true){
        return true;
    }


    s -= arr[ind];
    ds.pop_back();

    if(printSing(ind + 1, ds, s, sum, arr, n)==true) return true;

    return false;
}

//! no of subsequences

int printNumber(int ind, vector<int> ds, int s, int sum, vector<int> arr, int n)
{
    if (ind == n)
    {
        //condition satisfied
        if (s == sum)
        {
            for (auto it : ds)
            return 1;
        }
        else return 0;
    }

    ds.push_back(arr[ind]);
    s += arr[ind];

    int l = printNumber(ind + 1, ds, s, sum, arr, n);

    s -= arr[ind];
    ds.pop_back();

    int r = printNumber(ind + 1, ds, s, sum, arr, n);

    return l+r;
}



int main()
{

    vector<int> nums = {1, 2, 1};
    int n = 3;
    int sum = 2;

    vector<int> ds;

    cout<<printNumber(0, ds, 0, sum, nums, n);

    //   Compilation Time code //
    cout << endl;
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    return 0;
}