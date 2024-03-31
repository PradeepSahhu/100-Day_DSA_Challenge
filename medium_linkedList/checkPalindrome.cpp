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

//! Not Working properly.
bool isPalindrome(Node *head)
{
    // write your code here

    Node *start = head;
    map<int, int> mpp;

    while (start != NULL)
    {
        
        mpp[start->data]++;
        start = start->next;
    }

    for (auto it : mpp)
    {
        if (it.second != 2)
        {
            return false;
        }
    }
    return true;
}

bool isPalindromes(Node* head){

    //! first find the middle element.

    Node* slow = head;
    Node* fast = head;
    while(fast->next!=nullptr && fast->next->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
    }

    //!reversing the linked list.

    Node* prev = nullptr;
    Node*curr = slow->next;


    while(curr!=nullptr){
       Node* upcome = curr->next;
        curr->next = prev;
        prev = curr;
        curr = upcome;

    }
    //! prev will be at the start of reverse linkedlist.
    slow->next=nullptr;
    Node*start = head;
    Node*end = prev;
    while(end!=nullptr && start!=nullptr){
        if(start->data!=end->data){
            return false;
        }
        start=start->next;
        end = end->next;
    }
    return true;
}


int main()
{

     Node *head = new Node(1,nullptr);


    Node *second = new Node(2,head);
    Node *third = new Node(3,second);
    Node *fourth = new Node(4,third);
    Node *fifth = new Node(4,fourth);
    Node *sixth = new Node(3,fifth);
    Node *seventh = new Node(2,sixth);
    Node*last = new Node(1,seventh);


    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;
    seventh->next = last;
    last->next = nullptr;

    cout<<isPalindrome(head);

    //   Compilation Time code //
    cout << endl;
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    return 0;
}