#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

auto start = chrono::steady_clock::now();

int kthelement(int array1[], int array2[], int m, int n, int k)
{
    int p1 = 0, p2 = 0, counter = 0, answer = 0;

    while (p1 < m && p2 < n)
    {
        if (counter == k)
            break;
        else if (array1[p1] < array2[p2])
        {
            answer = array1[p1];
            ++p1;
        }
        else
        {
            answer = array2[p2];
            ++p2;
        }
        ++counter;
    }
    if (counter != k)
    {
        if (p1 != m - 1)
            answer = array1[k - counter];
        else
            answer = array2[k - counter];
    }
    return answer;
}
// Add and alternative best solution.
int main()
{

    //   Compilation Time code //
    cout << endl;
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    return 0;
}