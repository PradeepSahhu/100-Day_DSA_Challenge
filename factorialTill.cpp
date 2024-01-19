#include <iostream>
using namespace std;

// int factorial(int x, int num, int limit)
// {

//     if (x * num >= limit)
//     {
//         return x;
//     }
//     x = x * num;
//     // cout << "The value of x is: " << x << endl;

//     x = factorial(x, num + 1, limit);
//     return x;
// }

// int solution(int y)
// {

//     return factorial(1, 1, y);
// }

vector<long long> factorial(int x, int num, int limit, vector<long long> &v)
{

    if (x * num > limit)
    {
        return v;
    }
    x = x * num;
    v.push_back(x);
    // cout << "The value of x is: " << x << endl;

    return factorial(x, num + 1, limit, v);
}

vector<long long> vectorArray(long long n)
{
    vector<long long> v;

    return factorial(1, 1, n, v);
}

long long fact(long long x)
{
    if (x <= 1)
    {
        return 1;
    }
    return x * fact(x - 1);
}

vector<long long> factorialNumbers(long long n)
{
    vector<long long> v;
    for (int i = 1; fact(i) <= n; i++)
    {
        v.push_back(fact(i));
    }
    return v;
}

int main()
{
    vector<long long> v = factorialNumbers(100);

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }

    return 0;
}