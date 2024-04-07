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

Node* reverse(Node* head){
    Node* prev = nullptr;
    Node* curr = head;
    while(curr!=NULL){
        Node*upcome=curr->next;
        curr->next = prev;
        prev = curr;
        curr = upcome;
    }
    return prev;
}

Node* findkthNode(Node* head, int k){

    int cnt = 1;
    Node* temp = head;
    while(temp!=NULL){
        if(cnt==k){
            return temp;

        }
        temp = temp->next;
        cnt++;
    }   
    return NULL;

}

Node* kReverse(Node* head, int k) {
    
    Node* temp = head;
    Node*prevNode = NULL;

    while(temp!=NULL){
        Node* kthNode = findkthNode(temp,k);

        if(kthNode==NULL){
            if(prevNode)
                  prevNode->next = temp;
            break;
        }
        Node* nextNode = kthNode->next;
        kthNode->next = NULL;
        reverse(temp);

        if(temp==head){
            head = kthNode;
        }else{
            prevNode->next = kthNode;
            
        }
        prevNode = temp;
        temp = nextNode;

    }

    return head;

}

Node* reverseKthNode(Node* head,int k){
    Node*temp = head;

    Node*prevNode = NULL;
    
    while(temp!=NULL){

        Node* kthNode = findkthNode(temp,k);
        if(kthNode==NULL){
            if(prevNode) prevNode->next = temp;
            break;
        }

        Node*nextNode = kthNode->next;
        kthNode->next = NULL;
        reverse(temp);

        if(temp==head){
            head = kthNode;
        }else{
            prevNode->next = kthNode;
        }
        prevNode = temp;
        temp = nextNode;

    }
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