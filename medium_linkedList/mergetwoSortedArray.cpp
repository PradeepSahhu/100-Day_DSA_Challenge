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
   vector<int> v;
    while(curr!=NULL){
       v.push_back(curr->data);
       curr = curr->next;
    }
    sort(v.begin(),v.end());
    Node*temp = head;
    int s = v.size();
    int i = 0;
    while(i<s){
        temp->data = v[i];
        i++;
        temp = temp->next;
    }

}

Node* mergeTwoSortedLinkedList(Node*head,Node* head2){
    Node*first = head;
    Node*second=head2;
    Node*tempNode = new Node(-1);
    Node*temp=tempNode;

    while(first!=NULL && second!=NULL){
        if(first->data<second->data){
            temp->next = first;
            first=first->next;
        }else{
            temp->next=second;
            second=second->next;
        }
        temp=temp->next;
    }

    // while(first!=NULL){
    //     temp->next = first;
    //     temp=temp->next;
    //     first=first->next;
    // }
    // while(second!=NULL){
    //      temp->next = second;
    //     temp=temp->next;
    //     second=second->next;
        
    // }
    if(first) temp->next = first;
    else temp->next = second;
    return tempNode->next;
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

    Node* newNode = mergeTwoSortedLinkedList(head,head2);
    traversal(newNode);
    

    //   Compilation Time code //
    cout << endl;
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    return 0;
}