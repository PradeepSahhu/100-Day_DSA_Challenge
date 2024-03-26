#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

auto start = chrono::steady_clock::now();

// class Node
// {
// public:
//     int data;   // Data stored in the node
//     Node *next; // Pointer to the next node in the linked list
//     // Constructors
//     Node(int data1, Node *next1)
//     {
//         data = data1;
//         next = next1;
//     }
//     // Constructor
//     Node(int data1)
//     {
//         data = data1;
//         next = nullptr;
//     }
// };

// Node *constructLL(vector<int> &arr)
// {
//     Node *head = NULL;
//     while (arr.size() != 0)
//     {
//         int val = arr.back();
//         Node *temp = new Node(val);
//         if (head == NULL)
//         {

//             head = temp;
//         }
//         else
//         {
//             temp->next = head;
//             head = temp;
//         }
//         arr.pop_back();
//     }

//     return head;
// }

//! Structure Node.
// struct Node
// {
//     int data;
//     Node *next;

//     Node(int data1, Node *next1)
//     {
//         data = data1;
//         next = next1;
//     }
//     Node(int data1)
//     {
//         data = data1;
//         next = nullptr;
//     }
// };

class Node
{
public:
    int data;
    Node *next;

    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

Node *vectorToLinkedList(vector<int> v)
{
    int n = v.size();
    Node *head = new Node(v[0]);
    Node *mover = head;
    for (int i = 1; i < n; i++)
    {
        Node *temp = new Node(v[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

void travelInLL(Node *head)
{
    Node *temp = head;

    while (temp != nullptr)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
}

int lengthOfLL(Node *head)
{
    int length = 0;
    Node *temp = head;

    while (temp != nullptr)
    {
        length++;
        temp = temp->next;
    }
    return length;
}

int searchInLinkedList(Node *head, int element)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        if (temp->data == 1)
        {
            return true;
        }
    }
    return 0;
}

int main()
{
    vector<int> v = {1, 2, 3, 4};
    Node x = Node(v[0], nullptr);
    Node *y = &x;
    Node *z = new Node(v[1], nullptr); // new keyword is used to give pointer to the memory address.

    // cout << z << endl;
    // cout << &x << endl;
    // cout << y << endl;
    // cout << x.data << endl;
    // cout << z->data << endl;

    Node *head = vectorToLinkedList(v);

    travelInLL(head);
    cout << "The length of the linked list is : " << lengthOfLL(head) << endl;
    cout << searchInLinkedList(head, 4);

    //   Compilation Time code //
    cout << endl;
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    return 0;
}