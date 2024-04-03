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

void createLinkList(Node *&head, int data)
{
    if (head == NULL)
    {
        head->data = data;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->data = data;
}

// void SortLinkedList(Node*&head){
//     Node*curr = head;
//    vector<int> v;
//     while(curr!=NULL){
//        v.push_back(curr->data);
//        curr = curr->next;
//     }
//     sort(v.begin(),v.end());
//     Node*temp = head;
//     int s = v.size();
//     int i = 0;
//     while(i<s){
//         temp->data = v[i];
//         i++;
//         temp = temp->next;
//     }

// }

//! Applying merge sort.

Node *merge(Node *head, Node *head2)
{
    Node *first = head;
    Node *second = head2;
    Node *tempNode = new Node(-1);
    Node *temp = tempNode;

    while (first != NULL && second != NULL)
    {
        if (first->data < second->data)
        {
            temp->next = first;
            first = first->next;
        }
        else
        {
            temp->next = second;
            second = second->next;
        }
        temp = temp->next;
    }

    

    if (first)
        temp->next = first;
    else
        temp->next = second;
    return tempNode->next;
}

Node *findMiddle(Node *head)
{

    Node *slow = head;
    Node *fast = head->next;
    //! returns the first middle not the second middle.
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}


Node *SortLinkedList(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *middle = findMiddle(head);
    Node*lefthead = head;
    Node*righthead = middle->next;
    middle->next = NULL;

    lefthead = SortLinkedList(lefthead);
    righthead = SortLinkedList(righthead);
    return merge(lefthead,righthead);



}

int main()
{
    Node *head = new Node(1, nullptr);
    Node *second = new Node(2, head);
    Node *third = new Node(1, second);
    Node *fourth = new Node(2, third);
    Node *fifth = new Node(11, fourth);
    Node *sixth = new Node(9, fifth);
    Node *seventh = new Node(10, sixth);
    Node *last = new Node(56, seventh);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;
    seventh->next = last;
    last->next = nullptr;

    SortLinkedList(head);
    traversal(head);

    //   Compilation Time code //
    cout << endl;
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    return 0;
}