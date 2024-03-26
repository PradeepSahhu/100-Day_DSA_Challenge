#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

auto start = chrono::steady_clock::now();

class Node
{
    int data;
    Node *next;

public:
    Node(int data1, Node *address)
    {
        data = data1;
        next = address;
    }
    Node(int data1)
    {
        data = data1;
    }

    void deletionInBeg(Node *head)
    {
    }
};
int main()
{

    //   Compilation Time code //
    cout << endl;
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    return 0;
}