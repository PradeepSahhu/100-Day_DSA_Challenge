#include <iostream>
using namespace std;

void swap(int x, int y)
{
    int temp = x;
    x = y;
    y = temp;
}

vector<int> reverseArray(int i, int n, vector<int> &v)
{
    if (i >= n / 2)
    {
        return v;
    }
    int temp = v[i];
    v[i] = v[n - i - 1];
    v[n - i - 1] = temp;
    return reverseArray(i + 1, n, v);
}

vector<int> reverse(int n, vector<int> &v)
{
    return reverseArray(0, n, v);
}

int main()
{
    int n;
    cin >> n;
    int input;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        cin >> input;
        v.push_back(input);
    }
    v = reverse(5, v);
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }

    return 0;
}