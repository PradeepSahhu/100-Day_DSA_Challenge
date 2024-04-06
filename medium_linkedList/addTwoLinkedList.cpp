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

Node *addTwoNumbers(Node *l1, Node *l2)
{

    Node *dNode = new Node(-1);
    Node *dummyHead = dNode;

    Node *temp1 = l1;
    Node *temp2 = l2;
    int carry = 0;

    while (temp1 != NULL || temp2 != NULL)
    {
        int summation = carry; // temp1->data+temp2->data+carry;

        if (temp1 != NULL)
        {
            summation += temp1->data;
            temp1 = temp1->next;
        }
        if (temp2 != NULL)
        {
            summation += temp2->data;
            temp2 = temp2->next;
        }

        carry = summation / 10;
        summation = summation % 10;
        Node *tempSum = new Node(summation);
        dNode->next = tempSum;
        dNode = dNode->next;
    }

   
    if (carry > 0)
    {
        Node *lastNode = new Node(carry);
        dNode->next = lastNode;
    }
    return dummyHead->next;
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