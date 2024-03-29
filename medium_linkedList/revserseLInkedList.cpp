#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

auto start = chrono::steady_clock::now();

class Node
{
public:
    int data;
    Node *next;
    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

Node *reverseList(Node *head)
{

    if (head == NULL)
    {
        return head;
    }

    Node *curr = head;
    Node *prev = NULL;
    Node *upcoming;

    while (curr != NULL)
    {
        upcoming = curr->next;
        curr->next = prev;

        prev = curr;
        curr = upcoming;
    }
    return prev;
}
int main()
{

    //   Compilation Time code //
    cout << endl;
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    return 0;
}