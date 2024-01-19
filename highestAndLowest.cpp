#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

auto start = chrono::steady_clock::now();

vector<int> countFrequency(vector<int> &nums)
{
    // Write your code here.
    int n = nums.size();
    vector<int> vfrequency(n, 0);

    for (int i = 0; i < n; i++)
    {

        vfrequency[nums[i] - 1]++;
    }

    cout << "The frequency vector" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << vfrequency[i] << " ";
    }
    cout << endl;
    vector<int> m;

    int largest = 0;
    int smallest = 0;
    for (int i = 0; i < n; i++)
    {
        cout << "this is largest for loop" << endl;
        if (vfrequency[i] > vfrequency[largest])
        {

            largest = i;
            cout << "The vlaue of the largest is : " << largest << endl;
        }

        if (vfrequency[i] < vfrequency[smallest])
        {
            if (vfrequency[i] != 0)
            {
                smallest = i;
            }
        }
    }
    cout << "The value of largest is : " << largest + 1 << endl;
    cout << "the smallest value is : " << smallest << endl;
    // m[0] = *(max_element(vfrequency.begin(), vfrequency.end()));
    // m[1] = *(min_element(vfrequency.begin(), vfrequency.end()));
    m.push_back(largest + 1);
    m.push_back(smallest + 1);

    return m;
}
int main()
{
    int n;
    cin >> n;

    vector<int> nums;
    for (int i = 0; i < n; i++)
    {
        int number;
        cin >> number;
        nums.push_back(number);
    }
    vector<int> nu = countFrequency(nums);

    for (int i = 0; i < 2; i++)
    {
        cout << nu[i] << " ";
    }

    //   Compilation Time code //
    cout
        << endl;
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    return 0;
}