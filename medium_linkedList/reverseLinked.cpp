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
void traversal(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
}

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

Node *reverseLinkedListRecursion(Node *prev, Node *curr)
{

    if (curr == NULL)
    {
        return prev;
    }
    Node *upnext = curr->next;
    curr->next = prev;
    // prev = curr;
    // curr = upnext;
    return reverseLinkedListRecursion(curr, upnext);
}

Node *reverseLinkedListRecursion(Node *head)
{

    return reverseLinkedListRecursion(nullptr, head);
}

//! Strivers LinkedList Question :
Node *reverseRecurion(Node *head)
{
}
int main()
{
    Node *head = new Node(1);
    insert_in_tail(head, 2);
    insert_in_tail(head, 3);
    insert_in_tail(head, 4);
    insert_in_tail(head, 5);
    insert_in_tail(head, 6);
    insert_in_tail(head, 7);
    insert_in_tail(head, 8);
    insert_in_tail(head, 9);
    insert_in_tail(head, 10);

    head = reverseLinkedListRecursion(head);

    traversal(head);

    //   Compilation Time code //
    cout << endl;
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    return 0;
}