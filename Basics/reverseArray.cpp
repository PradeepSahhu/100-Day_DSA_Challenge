#include <iostream>
using namespace std;

int *reverseArray(int i, int j, int *arr)
{
    if (i >= j)
    {
        return arr;
    }
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
    reverseArray(i + 1, j - 1, arr);

    return arr;
}

int *reverseone(int j, int *arr, int n)
{

    if (j <= n / 2)
    {
        return arr;
    }
    int temp = arr[j];
    arr[j] = arr[n - j];
    arr[n - j] = temp;

    reverseone(j - 1, arr, n);
    return arr;
}

void traverse(int *arr)
{
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }
}

bool isPalindrome(int i, string &arr)
{
    // cout << "is thie workig" << endl;
    cout << arr[i] << ":::" << arr[arr.size() - i - 1] << "::: " << endl;
    if (i >= arr.size() / 2)
    {
        return true;
    }
    if (arr[i] != arr[arr.size() - i - 1])
    {
        return false;
    }
    return isPalindrome(i + 1, arr);
    // return true;
}

bool isPalindromes(int i, const char *arr, int n)
{
    // cout << "is thie workig" << endl;
    cout << arr[i] << ":::" << arr[n - i - 1] << "::: " << endl;
    if (i >= n / 2)
    {
        return true;
    }
    if (arr[i] != arr[n - i - 1])
    {
        return false;
    }
    return isPalindromes(i + 1, arr, n);
    // return true;
}

vector<int> returns(int x)
{
    vector<int> v;
    if (x <= 1)
    {
        v.push_back(x);
        return v;
    }
    v = returns(x - 1);
    v.push_back(x);
    return v;
}

void number(int x, vector<int> &v)
{
    if (x <= 1)
    {
        v.push_back(x);
        return;
    }
    v.push_back(x);
    number(x - 1, v);
    return;
}

vector<int> printNos(int x)
{

    vector<int> v;
    // Write Your Code Here

    number(x, v);
    return v;
}

int main()
{
    // int *arr2 = (int *)malloc(sizeof(int) * 10);

    // int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // // arr2 = reverseArray(0, 9, arr);
    // arr2 = reverseone(9, arr, 9);

    // traverse(arr2);
    // traverse(arr2);
    // string name = "MADAM";

    // // char name[5] = {'M', 'A', 'D', 'A', 'M'};

    // cout << isPalindromes(0, name.c_str(), 5) << endl;

    vector<int> v;
    v = printNos(5);

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    return 0;
}