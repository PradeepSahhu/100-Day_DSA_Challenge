#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

auto start = chrono::steady_clock::now();

void intersection(vector<int> arr1, vector<int> arr2)
{
    vector<int> visited(arr2.size());
    vector<int> intersections;
    for (int i = 0; i < arr1.size(); i++)
    {
        for (int j = 0; j < arr2.size(); j++)
        {
            if (arr1[i] == arr2[j] && visited[j] == 0)
            {
                intersections.push_back(arr1[i]);
                visited[j]++;
                break;
            }
            if (arr2[j] > arr1[i])
                break;
        }
    }

    for (auto it : intersections)
    {
        cout << it << " ";
    }
}

void intersectin(vector<int> arr1, vector<int> arr2)
{
    vector<int> intersectionArr;
    int j = 0;
    int i = 0;
    while (i < arr1.size() && j < arr2.size())
    {
        if (arr1[i] < arr2[j])
        {
            i++;
        }
        else if (arr1[i] > arr2[j])
        {
            j++;
        }
        else
        {
            intersectionArr.push_back(arr1[i]);
            i++;
            j++;
        }
    }

    for (auto it : intersectionArr)
    {
        cout << it << " ";
    }
}
// Brute force approach..
void intersection_v2(vector<int> a1, vector<int> a2)
{

    vector<int> visited(a2.size());
    vector<int> inters;
    int n1 = a1.size();
    int n2 = a2.size();

    int i = 0;
    int j = 0;

    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            if (a1[i] == a2[j] && visited[j] == 0)
            {
                inters.push_back(a1[i]);
                visited[j]++;
                break;
            }
            if (a2[j] > a1[i])
            {
                break;
            }
        }
    }

    for (auto it : inters)
    {
        cout << it << " ";
    }
}

void intersection_v3(vector<int> v1, vector<int> v2)
{
    vector<int> intersec;
    int i = 0;
    int j = 0;

    while (i < v1.size() && j < v2.size())
    {
        if (v1[i] < v2[j])
        {
            i++;
        }
        else if (v2[j] < v1[i])
        {
            j++;
        }
        else
        {
            intersec.push_back(v1[i]);
            i++;
            j++;
        }
    }
    for (auto it : intersec)
    {
        cout << it << " ";
    }
}

void rightRotate(vector<int> v1, int d)
{
    // 1 right is equal to (n-1) left.
    int n = v1.size();
    d = d % n;

    reverse(v1.begin(), v1.begin() + (n - d));
    reverse(v1.begin() + (n - d), v1.end());
    reverse(v1.begin(), v1.end());

    for (auto it : v1)
    {
        cout << it << " ";
    }
}

int main()
{
    int a1[] = {1, 1, 2, 3, 4, 5};
    int a2[] = {2, 3, 3, 4, 5, 6, 7};

    int size1 = sizeof(a1) / sizeof(a1[0]);
    int size2 = sizeof(a2) / sizeof(a2[0]);

    vector<int> arr1(a1, a1 + size1);
    vector<int> arr2(a2, a2 + size2);

    // intersection(arr1, arr2);
    // intersectin(arr1, arr2);
    // intersection_v3(arr1, arr2);
    rightRotate(arr2, 2);

    //   Compilation Time code //
    cout << endl;
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    return 0;
}