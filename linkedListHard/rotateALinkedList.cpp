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

int lengthOfLinkedList(Node* head){
    int cnt = 0;
    Node* temp = head;
    while(temp!=NULL){
      
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

Node *rotate(Node *head, int k) {
    Node* temp = head;
    int cnt = 1;

    int size = lengthOfLinkedList(temp);
    k = k%size;

    if(k==0){
        return head;
    }
    Node*temps = head;
    Node*newHead = NULL;

    while(cnt<size-k && temp!=NULL){
        cnt++;
        temps = temps->next;
        

    }
    if(temp==NULL){
        return head;
    }
    newHead = temps->next;
    temps->next = NULL;

    Node* lastNode = newHead;

    while(lastNode->next !=NULL){
        lastNode= lastNode->next;
    }
    lastNode->next = head;
    head = newHead;

    return head;
}

//!Alternative solution.


Node *rotateRight(Node *head, int k) {
    Node* temp = head;
    Node*tail = head;
    int cnt = 1;
    int size =1;

    while(tail->next !=NULL){
        size++;
        tail = tail->next;
    }
    k = k%size;

    if(k==0){
        return head;
    }
    Node*temps = head;
    Node*newHead = NULL;

    while(cnt<size-k && temp!=NULL){
        cnt++;
        temps = temps->next;
    }
    if(temp==NULL){
        return head;
    }
    newHead = temps->next;
    temps->next = NULL;

    tail->next = head;
    head = newHead;

    return head;
}


int main()
{
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* fifth = new Node(5);
    Node* sixth = new Node(6);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = NULL;

  Node* newNode = rotate(head,2);
  traversal(newNode);


    //   Compilation Time code //
    cout << endl;
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    return 0;
}