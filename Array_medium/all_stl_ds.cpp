#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

auto start = chrono::steady_clock::now();
int main()
{

    // vectors

    // vector<int> v = {1, 2, 34, 7, 5, 6};

    // Through Array.
    int arr[] = {1, 2, 3, 4, 5, 6, 8, 1, 2, 3};
    int size = sizeof(arr) / sizeof(arr[0]);

    // vector<int> vec(arr, arr + size);

    // for (int i = 0; i < vec.size(); i++)
    // {
    //     cout << vec[i] << " ";
    // }

    // map Data structure.

    // map<int, int> hashMpp;
    // hashMpp[1] = 100;

    // if (hashMpp.find(2) != hashMpp.end()) // used to find the keys in the map data structure.
    // {
    //     cout << hashMpp[1] << endl;
    // }
    // else
    // {
    //     cout << "Can't find the value" << endl;
    // }

    // sets.
    // // set<int> s = {1, 2, 3, 1, 1, 2, 3};

    // set<int> s(arr, arr + size);

    // // traversing through iterators.

    // set<int>::iterator it = s.begin();

    // while (it != s.end())
    // {
    //     cout << *it << " ";
    //     it++;
    // }
    // cout << endl;

    // list<int> l(arr, arr + size);

    // list<int>::iterator itr;

    // for (itr = l.begin(); itr != l.end(); itr++)
    // {
    //     cout << *itr << " ";
    // }

    // stack<int> s;
    // s.push(3);
    // s.push(5);
    // s.push(8);
    // s.emplace(100);

    // while (!s.empty())
    // {
    //     cout << s.top() << " ";
    //     s.pop();
    // }

    // queue
    queue<int> q;
    q.push(99);
    q.push(100);
    q.push(101);
    q.push(102);
    q.push(103);
    q.push(104);
    q.push(105);

    // while (!q.empty())
    // {
    //     cout << q.front() << " ";
    //     q.pop();
    // }

    priority_queue<int> pq;
    pq.push(3);
    pq.push(1);
    pq.push(100);
    pq.push(1000);
    pq.push(5);

    // while (!pq.empty())
    // {
    //     cout << pq.top() << " ";
    //     pq.pop();
    // }

    map<int, int> mpp;
    mpp[2] = 100;
    mpp[7] = 6969;
    mpp[3] = 1020;
    mpp[4] = 1030;
    mpp[5] = 1020;
    mpp[6] = 1040;
    mpp[18] = 1030;
    mpp[8] = 1080;
    // for (auto its : mpp)
    // {
    //     cout << its.first << " " << its.second << endl;
    // }
    // cout << endl;

    unordered_map<int, int> umpp;
    umpp[2] = 100;
    umpp[3] = 1020;
    umpp[4] = 1030;
    umpp[5] = 1020;
    umpp[6] = 1040;
    umpp[18] = 1030;
    umpp[8] = 1080;

    // for (auto it : umpp)
    // {
    //     cout << it.first << " " << it.second << endl;
    // }

    // unordered_set<int> us(arr, arr + size);

    // unordered_set<int>::iterator itsu = us.begin();

    // while (itsu != us.end())
    // {
    //     cout << *itsu << endl;
    // }

    //   Compilation Time code //
    cout
        << endl;
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    return 0;
}