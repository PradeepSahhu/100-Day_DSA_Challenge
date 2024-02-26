
#include <iostream>
using namespace std;
vector<string> printNTimes(int n)
{
    if (n < 1)
    {
        return {};
    }

    vector<string> v = printNTimes(n - 1);
    v.push_back("Coding Ninjas");
    // Write your code here.
}

int main()
{

    printNTimes(5);

    return 0;
}