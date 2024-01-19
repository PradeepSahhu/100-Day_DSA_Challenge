#include <iostream>
using namespace std;

int fibonnaci(int x)
{
    if (x <= 1)
    {
        return x;
    }

    int last = fibonnaci(x - 1);
    int slast = fibonnaci(x - 2);
    return last + slast;
}
int main()
{
    for (int i = 0; i < 10; i++)
    {
        cout << fibonnaci(i) << " ";
    }

    return 0;
}