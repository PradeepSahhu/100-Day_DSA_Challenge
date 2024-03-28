#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

auto start = chrono::steady_clock::now();

//! Insertion in linked list.

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

//! Traversal in linkedlist.
void traversal(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
}

//?Insertion in head.
void insertion_in_head(Node *&head, int element)
{
    Node *newHead = new Node(element);
    newHead->next = head;
    head = newHead;
}

int main()
{
    Node *head = new Node(2); // new keyword returns a pointer.
    insertion_in_head(head, 5);
    traversal(head);

    //   Compilation Time code //
    cout << endl;
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    return 0;
}