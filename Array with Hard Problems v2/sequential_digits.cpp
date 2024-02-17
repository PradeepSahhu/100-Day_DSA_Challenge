#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
#include <cmath>
using namespace std;

auto start = chrono::steady_clock::now();

bool isnextOrder(int num)
{

    string tempWord = to_string(num);
    int digits = tempWord.length();
    // cout << digits << endl;
    int last_digit = num / (int)pow(10, digits - 1);
    // cout << "The value of last_digit is " << last_digit << endl;
    num = num % (int)pow(10, digits - 1);
    digits--;

    do
    {
        int temp = num / (int)pow(10, digits - 1);
        // cout << "The value of temp is " << temp << endl;
        if (last_digit + 1 != temp)
        {
            return false;
        }
        num = num % (int)pow(10, digits - 1);
        cout << "the value of num is " << num << endl;
        digits--;
        last_digit = temp;
    } while (num > 0);
    return true;
}
vector<int> sequentialDigits(int low, int high)
{

    vector<int> ans;
    for (int i = low; i < high; i++)
    {
        // cout << "The vaue of i is " << i << endl;
        if (isnextOrder(i) == true)
        {
            if (i % 10 != 0)
            {
                ans.push_back(i);
            }
        }
    }
    return ans;
}

int main()
{

    int number = 123;
    // cout << isnextOrder(number);
    vector<int> ans = sequentialDigits(100, 300);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    //   Compilation Time code //
    cout << endl;
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    return 0;
}