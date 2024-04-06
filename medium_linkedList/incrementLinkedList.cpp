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
    Node*prev = NULL;
    Node*curr = head;
    while(curr!=NULL){
        Node*upcome = curr->next;
        curr->next=prev;
        prev = curr;
        curr=upcome;
    }
    return prev;
}

//!Not working.
// Node *addOne(Node *head)
// {
//     int number = 0;

//      Node*temp = head;


//     while(temp!=NULL){
//         number = number*10+temp->data;
//         temp=temp->next;
//     }
//     number++;
    
//     Node *newNode = new Node(-1);
//     Node*newHead = newNode;

//     while(number>0){
//         int lastdigit = number%10;
//         Node*temp = new Node(lastdigit);
//         newNode->next = temp;
//         newNode = newNode->next;
//         number = number/10;
    
//     }
//     Node*prev = NULL;
//     Node*curr = newHead->next;
//     while(curr!=NULL){
//         Node*upcome = curr->next;
//         curr->next=prev;
//         prev = curr;
//         curr=upcome;
//     }
//     return prev;

// }


Node *addOne(Node *head)
{
    head = reverse(head);

    Node*temp = head;
    // traversal(head);
    int carry = 1;

    while(temp!=NULL){
        temp->data = temp->data + carry;

        if(temp->data < 10){
            carry = 0;
            break;
        }else{
            carry = 1;
            temp->data = 0;
        }
        temp = temp->next;
    }
    if(carry == 1){
        Node* newNode = new Node(1);
        head = reverse(head);
        newNode->next = head;
        return newNode;

    }
    head = reverse(head);
    return head;
}


Node* addOnes(Node*head){
    int carry = 1;

    head = reverse(head);

    Node*temp = head;
    while(temp!=NULL){
        temp->data = temp->data+carry;

        if(temp->data<10){
            head = reverse(head);
            break;
        }else{
            temp->data = 0;
            carry = 1;
        }
        temp = temp->next;
    }

    if(carry == 1){
        Node *newHead = new Node(1);
        newHead->next = head;
        return newHead;
    }
    return head;

}


int main()
{

    Node *head = new Node(9, nullptr);
    Node *second = new Node(9, head);
    Node *third = new Node(9, second);
    Node *fourth = new Node(9, third);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = nullptr;

    Node*ans = addOne(head);
    traversal(ans);

    //   Compilation Time code //
    cout << endl;
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    return 0;
}