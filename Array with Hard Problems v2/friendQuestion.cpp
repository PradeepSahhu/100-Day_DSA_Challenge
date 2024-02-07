#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

auto start = chrono::steady_clock::now();

void printPattern(int a, int d)
{

    int x = a;
    int i = 0;
    bool isExecuted = false;

    do
    {

        if (a > 0 && isExecuted == false)
        {
            cout << a << " ";
            a = a - d;
        }
        else
        {
            cout << a << " ";
            a = a + d;
            isExecuted = true;
        }

    } while (x >= a);
}
int main()
{

    cout << "Enter any number" << endl;
    int a;
    cin >> a;
    cout << "Enter the difference" << endl;
    int d;
    cin >> d;

    printPattern(a, d);

    //   Compilation Time code //
    cout
        << endl;
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    return 0;
}