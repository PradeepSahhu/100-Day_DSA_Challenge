#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

auto start = chrono::steady_clock::now();

class Node
{
public:
    int data;   // Data stored in the node
    Node *next; // Pointer to the next node in the linked list
    // Constructors
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }
    // Constructor
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

Node *constructLL(vector<int> &arr)
{
    Node *head = NULL;
    while (arr.size() != 0)
    {
        int val = arr.back();
        Node *temp = new Node(val);
        if (head == NULL)
        {

            head = temp;
        }
        else
        {
            temp->next = head;
            head = temp;
        }
        arr.pop_back();
    }

    return head;
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