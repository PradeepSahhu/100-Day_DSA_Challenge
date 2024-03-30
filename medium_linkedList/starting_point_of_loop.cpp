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

//!using hashtable approach.

Node* hashTableApproach(Node* head){

    Node* slow = head;

    set<Node*> st;
    while(slow!=NULL){
        if(st.find(slow)!=st.end()){
            return slow;
        }

        st.insert(slow);
        slow=slow->next;
    }
    return NULL;
}


//!Alternative approach using the slow and fast pointers.(best Approach)

Node* StartingAndEndingPoint(Node* head){

    if(head==NULL || head->next==NULL){
        return NULL;
    }
    Node*slow = head;
    Node*fast = head;
    Node*entry = head;
    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast){
           break;
        }
    }

     while(slow!=entry){
                slow = slow->next;
                entry=entry->next;
            }
            return entry;
    return NULL;
    
}

//!Alternative solution of the above.


Node* firstNode(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return nullptr;
    }

    Node* slow = head;
    Node* fast = head;


    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            break;
        }
    }


    if (slow != fast) {
        return nullptr;
    }


    fast = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
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
    last->next = third;

  


 

    // cout<<detectALoop(head);

    // cout<<hashTableApproach(head)->data;
    cout<<StartingAndEndingPoint(head)->data;


                 //   Compilation Time code //
                 cout
                 << endl;
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    return 0;
}