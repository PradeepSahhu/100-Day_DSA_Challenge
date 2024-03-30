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

// int detectALoop(Node*head){
//     Node* temp = head;

//     map<int,Node* > mpp;

//     while(temp!=NULL){
//          if(!mpp.empty() && mpp.find(temp->data)!=mpp.end()){
//             return 1;
//             break;
//         }
//         mpp[temp->data] = temp;
//         cout<<"executing"<<endl;

       
//         temp= temp->next;
//     }
//     return 0;
// }
int detectALoop(Node*head){
    Node* temp = head;

    set<Node* >st;

    while(temp!=NULL){
         if(!st.empty() && st.find(temp)!=st.end()){
            return 1;
            break;
        }
        st.insert(temp);
        cout<<"executing"<<endl;

       
        temp= temp->next;
    }
    return 0;
}

//!Alternative approach using the slow and fast pointers.

int detectALoopPointer(Node* head){
    Node*slow = head;
    Node*fast = head;

    while(fast!=NULL || fast->next!=NULL){
         slow = slow->next;
        fast = fast->next->next;
        if(slow==fast){
            return 1;
        }
       
    }
    return 0;
}
int main()
{
    Node *head = new Node(1,nullptr);
    

    Node *second = new Node(2,head);
    Node *third = new Node(3,second);
    Node *fourth = new Node(4,third);
    Node *fifth = new Node(5,fourth);
    Node *sixth = new Node(6,fifth);
    Node *seventh = new Node(7,sixth);
    Node*last = new Node(8,seventh);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;
    seventh->next = last;
    last->next = head;

    Node *head2 = new Node(10);
    Node *second2 = new Node(20);
    Node *third2 = new Node(30);
    Node *fourth2 = new Node(40);

    head2->next = second2;
    second2->next = third2;
    third2->next = fourth2;
    fourth2->next = nullptr;


 

    // cout<<detectALoop(head);
    cout<<detectALoopPointer(head);


                 //   Compilation Time code //
                 cout
                 << endl;
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    return 0;
}