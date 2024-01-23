#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

auto start = chrono::steady_clock::now();

int bestTimeToBuyAndSellStock(vector<int> &prices)
{
    int mini = prices[0];

    int profit = 0;
    for (int i = 1; i < prices.size(); i++)
    {

        int cost = prices[i] - mini;

        profit = max(profit, cost);
        mini = min(mini, prices[i]);
    }
    // cout << profit;
    return profit;
}

void stock_buy_sell(vector<int> &v)
{
    int mini = v[0];
    int buy = -1;
    int sell = -1;

    int profit = 0;
    for (int i = 1; i < v.size(); i++)
    {

        int cost = v[i] - mini;

        if (profit < cost)
        {
            profit = cost;
            sell = i;
        }
        if (mini > v[i])
        {
            mini = v[i];
            buy = i;
        }

        // profit = max(profit, cost);
        // mini = min(mini, v[i]);
    }

    cout << "Buy at " << buy << " And sell at " << sell << endl;
    cout << profit;
}
int main()
{

    int arr[] = {7, 1, 5, 3, 6, 4};
    int size = sizeof(arr) / sizeof(arr[0]);

    vector<int> v(arr, arr + size);
    stock_buy_sell(v);

    //   Compilation Time code //
    cout << endl;
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    return 0;
}