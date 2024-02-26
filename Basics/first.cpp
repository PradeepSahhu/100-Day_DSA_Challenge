

#include <iostream>
using namespace std;

void recursiveFunction(int number, vector<int> *v)
{

    // Write Your Code Here

    if (number == 0)
    {
        return;
    }

    recursiveFunction(number - 1, v);
    v->push_back(number);
}

vector<int> printNos(int x)
{

    vector<int> a;
    recursiveFunction(x, &a);

    return a;
}
// vector<int> printNoss(int x)
// {
//     if (x == 0)
//     {
//         return {};
//     }
//     vector<int> v = printNoss(x - 1);
//     v.push_back(x);
// }

int summation(int x)
{

    if (x <= 1)
    {
        // cout << "The value of x is " << x << endl;
        return x;
    }
    x += summation(x - 1);
    cout << "The value of x now is : " << x << endl;
    return x;
}

int summations(int x, int count)
{
    int sum = 0;
    if (x >= count)
    {
        return x;
    }

    sum += summations(x + 1, count);
    return sum + x;
}
void recursiveSummation(int i, int sum)
{

    if (i < 1)
    {
        cout << sum << endl;
        return;
    }
    recursiveSummation(i - 1, sum + i);
}

int functionalSummation(int x)
{
    if (x <= 1)
    {
        return 1;
    }
    return x + functionalSummation(x - 1);
}
int main()
{
    // vector<int> a;
    // a = printNos(5);

    // for (int i = 0; i < a.size(); i++)
    // {
    //     cout << a[i] << " ";
    // }

    // cout << summation(100) << endl;
    // cout << summations(90, 100) << endl;

    // recursiveSummation(5, 0);
    cout << functionalSummation(5) << endl;

    return 0;
}