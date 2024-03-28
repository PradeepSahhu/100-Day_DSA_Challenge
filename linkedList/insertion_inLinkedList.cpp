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
//! Insert the element according to its position.

void insertion_in_position(Node *&head, int position, int element)
{
    if (position == 1)
    {
        insertion_in_head(head, element);
    }
    int cnt = 2;
    Node *newNode = new Node(element);
    Node *temp = head;
    while (temp != NULL)
    {

        if (cnt == position)
        {
            newNode->next = temp->next;
            temp->next = newNode;
            break;
        }
        cnt++;
        temp = temp->next;
    }
}
//! Insert the element in to move the element from its position.
void insert_in_element(Node *&head, int elementToReplace, int element)
{
    if (head->data == elementToReplace)
    {
        insertion_in_head(head, element);
    }
    Node *newNode = new Node(element);
    Node *temp = head;

    while (temp->next != NULL)
    {
        if (temp->next->data == elementToReplace)
        {
            newNode->next = temp->next;
            temp->next = newNode;
            break;
        }
        temp = temp->next;
    }
}
//! Insert in the tail.
void insert_in_tail(Node *&head, int element)
{
    Node *newNode = new Node(element);
    Node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

int main()
{
    Node *head = new Node(2); // new keyword returns a pointer.
    insertion_in_head(head, 5);
    traversal(head);
    cout << endl;
    insertion_in_position(head, 2, 10);
    traversal(head);
    cout << endl;
    insert_in_element(head, 10, 6);
    traversal(head);
    cout << endl;
    insert_in_tail(head, 30);
    traversal(head);

    //   Compilation Time code //
    cout << endl;
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    return 0;
}