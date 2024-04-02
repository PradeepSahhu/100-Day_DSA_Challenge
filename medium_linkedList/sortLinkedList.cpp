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

void createLinkList(Node*&head,int data){
    if(head==NULL){
        head->data = data;
    }
    Node*temp= head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->data = data;
}

void SortLinkedList(Node*&head){
    Node*curr = head;
    Node*newNode = NULL;
    while(curr!=NULL){
        if(curr->data<curr->next->data){
            createLinkList(newNode,curr->data);
            curr = curr->next;
        }else{
            

        }
    }

}

int main()
{
    Node *head = new Node(1,nullptr);
    Node *second = new Node(2,head);
    Node *third = new Node(1,second);
    Node *fourth = new Node(2,third);
    Node *fifth = new Node(11,fourth);
    Node *sixth = new Node(9,fifth);
    Node *seventh = new Node(10,sixth);
    Node*last = new Node(56,seventh);


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