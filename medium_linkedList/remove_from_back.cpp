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

int lengthofLinkedList(Node*head){
    int cnt = 0;
    Node*temp= head;

    while(temp!=NULL){
        temp = temp->next;
        cnt = cnt+1;
    }
    return cnt;
}

Node* removeKthNode(Node* head, int K)
{

    if(head==NULL){
        return head;
    }
    int length = lengthofLinkedList(head);
    cout<<"The value of length is : "<<length<<endl;
    int k = length-K+1;
    if(k==1){
        head = head->next;
        return head;
    }
    // Write your code here.
    int cnt = 1;
    Node*temp = head;

    while(temp!=NULL){
          cnt++;
        if(cnt==k){
            Node*rm = temp->next;
            temp->next = rm->next;
            return head;
        }
      
        temp = temp->next;
    }
    return head;

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

    Node* newHead = removeKthNode(head,3);
    traversal(newHead);

    //   Compilation Time code //
    cout << endl;
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    return 0;
}