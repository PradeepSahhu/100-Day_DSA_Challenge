#include <iostream>
using namespace std;
#include <vector>
#include <map>
#include <algorithm>

int getLongestZeroSumSubarrayLength(vector<int> &arr)
{

    map<int, int> mpp;
    int n = arr.size();
    int preSum = 0;
    int Maxlength = 0;
    // Write your code here.

    for (int i = 0; i < n; i++)
    {
        preSum += arr[i];

        if (preSum == 0)
        {
            Maxlength = i + 1;
        }
        else
        {
            if (mpp.find(preSum) != mpp.end())
            {

                Maxlength = max(Maxlength, i - mpp[preSum]);
            }
            else
            {
                mpp[preSum] = i;
            }
        }
    }

    return Maxlength;
}
int main()
{
    vector<int> v = {1, -1, 0, 0, 2};

    cout << getLongestZeroSumSubarrayLength(v) << endl;

    return 0;
}