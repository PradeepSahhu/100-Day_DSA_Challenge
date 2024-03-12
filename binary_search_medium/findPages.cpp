#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

auto start = chrono::steady_clock::now();

//! Allocate the books to m students such that the maximum no. of pages that are assigned to student is minimum.

int countStudents(vector<int> &arr, int pages)
{
    int n = arr.size();
    int students = 1;
    long long pagesStudent = 0;
    for (int i = 0; i < n; i++)
    {
        if (pagesStudent + arr[i] <= pages) // maximum allowed books.
        {

            pagesStudent += arr[i];
        }
        else
        {

            students++;
            pagesStudent = arr[i];
        }
    }
    return students;
}

int findPages(vector<int> &arr, int n, int m)
{
    // m : number of students
    // n :
    //  book allocation impossible:
    if (m > n)
        return -1;

    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int students = countStudents(arr, mid);
        if (students > m)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return low;
}

//! Alternate solutions.

int countStudentsBookAllocated(vector<int> arr, int maxPages)
{
    int n = arr.size();
    int countStudents = 1;
    int currentPages = 0;

    for (int i = 0; i < n; i++)
    {
        if (currentPages + arr[i] <= maxPages)
        {
            currentPages += arr[i];
        }
        else
        {
            countStudents++;
            currentPages = arr[i];
        }
    }
    return countStudents;
}

int findPagesOptimized(vector<int> &arr, int n, int m)
{
    if (m > n)
        return -1;
    // m : No. of Students to whom book needs to be allocated.
    int left = *std::max_element(arr.begin(), arr.end());
    int right = accumulate(arr.begin(), arr.end(), 0);

    while (left <= right)
    {
        int mid = (left + right) / 2;
        int students = countStudentsBookAllocated(arr, mid);
        if (students <= m)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return left;
}
int main()
{
    vector<int> v = {25, 46, 28, 49, 24};
    cout << findPagesOptimized(v, 5, 4);

    //   Compilation Time code //
    cout << endl;
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    return 0;
}
