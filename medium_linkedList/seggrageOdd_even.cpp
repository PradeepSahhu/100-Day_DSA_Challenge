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

Node *oddEvenList(Node *head)
{

    if(head==NULL || head->next==NULL || head->next->next==NULL){
        return head;
    }

    Node *odd = head;
    Node*even = odd->next;
    Node*evenHead = even;

    while (even != NULL && even->next!=NULL)
    {
      
        odd->next = even->next;
        odd = even->next;
        even->next = odd->next;
        even = odd->next;
    }
    odd->next=evenHead;

    return head;
}

//Now seggragate according to even/odd values.

Node*evenOddValues(Node*head){
    
    if(head==NULL){
        return head;
    }
    Node*odd = NULL;
    Node*even=NULL;

    if(head->data%2!=0){
        odd = head;
    }else{
        even = head;
    }

   

}

int main()
{

    Node *head = new Node(1, nullptr);
    Node *second = new Node(2, head);
    Node *third = new Node(3, second);
    Node *fourth = new Node(4, third);
    Node *fifth = new Node(5, fourth);
    Node *sixth = new Node(6, fifth);
    Node *seventh = new Node(7, sixth);
    Node *last = new Node(8, seventh);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;
    seventh->next = last;
    last->next = nullptr;

    Node*newHead= oddEvenList(head);
    traversal(newHead);

    //   Compilation Time code //
    cout << endl;
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    return 0;
}