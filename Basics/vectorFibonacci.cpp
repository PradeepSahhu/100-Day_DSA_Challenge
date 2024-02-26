#include <bits/stdc++.h>
#include <chrono>
using namespace std;
//\\ Diabling the warning of c++11
// #pragma GCC diagnostic ignored "-Wc++11-compat-deprecated-writable-strings"

auto start = chrono::steady_clock::now();

int main()
{
    cout << "This is working perfectaly" << endl;

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int hashArr[13] = {0};

    for (int i = 0; i < n; i++)
    {
        hashArr[arr[i]]++;
    }

    for (int i = 0; i < 13; i++)
    {
        cout << hashArr[i] << " ";
    }
    cout << endl;

    int q;
    cin >> q;
    while (q--)
    {
        int number;
        cin >> number;

        cout << hashArr[number] << endl;
    }

    //\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

    cout << "\n";
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    return 0;
}