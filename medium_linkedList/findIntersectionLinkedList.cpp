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

Node *getIntersectionNode(Node *headA, Node *headB) {
    if (headA == NULL || headB == NULL) {
        return NULL;
    }

    Node* tempa = headA;
    Node* tempb = headB;

    while (tempa != tempb) {
        tempa = (tempa == NULL) ? headB : tempa->next;
        tempb = (tempb == NULL) ? headA : tempb->next;
    }

    return tempa; 
}



int main()
{
    Node *head = new Node(1,nullptr);
    Node *second = new Node(3,head);
    Node *third = new Node(5,second);
    Node *fourth = new Node(7,third);

    Node*head2 = new Node(2);
    Node*second2 = new Node(4);
    Node*third2 = new Node(6);

    head2->next = second2;
    second2->next = third2;
    third2->next = nullptr;
   


    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = nullptr;

    
    

    //   Compilation Time code //
    cout << endl;
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    return 0;
}