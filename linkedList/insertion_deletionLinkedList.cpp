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

    Node(int data1, Node *address)
    {
        data = data1;
        next = address;
    }
    Node(int data1)
    {
        data = data1;
    }
};

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

Node *deletionInBeg(Node *head)
{
    if (head == NULL)
    {
        return head;
    }
    Node *temp = head;
    head = head->next;
    delete temp;
    return head;
}

Node *deleteTail(Node *head)
{
    if (head == NULL || head->next == NULL)
        return NULL;
    Node *mover = head;
    while (mover != NULL)
    {
        if (mover->next->next == nullptr)
        {
            Node *temp = mover->next;
            mover->next = nullptr;
            delete temp;
            break;
        }
        mover = mover->next;
    }
    return head;

    // while (mover->next->next != NULL)
    // {
    //    mover = mover->next;
    // }
    // delete mover->next;
    // mover->next = nullptr:
    //
    // return head;
}

//! Delete According to the value of the linkedlist.

Node *deleteInMid(Node *head, int val)
{
    if (head == NULL)
        return NULL;

    if (head->data == val)
        return deletionInBeg(head);

    Node *mover = head;

    while (mover->next != nullptr)
    {
        if (mover->next->data == val)
        {
            Node *temp = mover->next;
            mover->next = temp->next;
            delete temp;
            break;
        }
        mover = mover->next;
    }

    //! alternative approach.
    // Node*temp = head;
    // Node*prev = NULL;
    //
    //  while (temp!= nullptr)
    // {
    //     if (temp->data == val)
    //     {
    //         prev->next = prev->next->next;
    // free(temp);
    //          break;
    //     }
    //      prev = temp;
    //     temp = temp->next;
    // }
    return head;
}

//! Delete According to the position of the linkedlist.

Node *deleteInMidPosition(Node *head, int position)
{
    int nodeCount = 1;
    if (head == NULL)
        return head;

    if (position == 1)
        return deletionInBeg(head);

    int lengthOfLinkedList = lengthOfLL(head);

    if (lengthOfLinkedList < position)
        return head;

    if (lengthOfLinkedList == position)
        return deleteTail(head);

    Node *mover = head;

    while (mover->next != nullptr)
    {
        nodeCount++;
        if (nodeCount == position)
        {
            Node *temp = mover->next;
            mover->next = temp->next;
            delete temp;
            break;
        }
        mover = mover->next;
    }

    //! Alternative.
    // Node*prev = NULL;
    // while (mover != nullptr)
    // {
    //     nodeCount++;
    //     if (nodeCount == position)
    //     {
    //         prev->next = prev->next->next;
    //           delete mover;
    //
    //         break;
    //     }
    // prev = mover;
    //     mover = mover->next;
    // }
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