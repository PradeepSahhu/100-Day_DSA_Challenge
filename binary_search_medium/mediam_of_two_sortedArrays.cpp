#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

auto start = chrono::steady_clock::now();

double findMedianSortedArrays(vector<int> &a, vector<int> &b)
{
    int n = a.size();
    int m = b.size();

    vector<int> ans(n + m);
    std::merge(a.begin(), a.end(), b.begin(), b.end(), ans.begin());
    int index = (n + m);

    if ((index) % 2 == 0)
    {
        index = index / 2;

        return ((double)(ans[index] + ans[index - 1]) / 2.0);
    }
    return ans[(int)(index / 2.0)];
}

double median(vector<int> &a, vector<int> &b)
{

    int n1 = a.size(), n2 = b.size();
    int n = n1 + n2;

    int ind2 = n / 2;
    int ind1 = ind2 - 1;
    int cnt = 0;
    int ind1el = -1, ind2el = -1;

    int i = 0, j = 0;
    while (i < n1 && j < n2)
    {
        if (a[i] < b[j])
        {
            if (cnt == ind1)
                ind1el = a[i];
            if (cnt == ind2)
                ind2el = a[i];
            cnt++;
            i++;
        }
        else
        {
            if (cnt == ind1)
                ind1el = b[j];
            if (cnt == ind2)
                ind2el = b[j];
            cnt++;
            j++;
        }
    }

    while (i < n1)
    {
        if (cnt == ind1)
            ind1el = a[i];
        if (cnt == ind2)
            ind2el = a[i];
        cnt++;
        i++;
    }
    while (j < n2)
    {
        if (cnt == ind1)
            ind1el = b[j];
        if (cnt == ind2)
            ind2el = b[j];
        cnt++;
        j++;
    }

    if (n % 2 == 1)
    {
        return (double)ind2el;
    }
    return (double)((double)(ind1el + ind2el)) / 2.0;
}

int main()
{

    vector<int> v = {1, 3};
    vector<int> v1 = {2, 4};

    cout << median(v, v1);

    //   Compilation Time code //
    cout
        << endl;
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    return 0;
}
