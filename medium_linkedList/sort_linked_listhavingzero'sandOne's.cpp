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



Node *sortList(Node *head)
{
    Node*temp = head;
    Node* zeroTemp = new Node(-1);
    Node* oneTemp = new Node(-1);
    Node* twoTemp = new Node(-1);

    Node*zeroHead = zeroTemp;
    Node*oneHead = oneTemp;
    Node*twoHead = twoTemp;

    while(temp!=NULL){
        if(temp->data==0){
            zeroTemp->next = temp;
            zeroTemp = zeroTemp->next;
        }else if(temp->data ==1){
            oneTemp->next = temp;
            oneTemp = oneTemp->next;
        }else{
            twoTemp->next = temp;
            twoTemp=twoTemp->next;
        }
        temp = temp->next;
    }
    zeroTemp->next = (oneHead->next)?oneHead->next:twoHead->next;
    oneTemp->next = twoHead->next;
    twoTemp->next = nullptr;
    return zeroHead->next;
    
}

int main()
{

    Node *head = new Node(1, nullptr);
    Node *second = new Node(2, head);
    Node *third = new Node(1, second);
    Node *fourth = new Node(2, third);
    Node *fifth = new Node(0, fourth);
    Node *sixth = new Node(0, fifth);
    Node *seventh = new Node(0, sixth);
    Node *last = new Node(1, seventh);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;
    seventh->next = last;
    last->next = nullptr;
    Node*newNode = sortList(head);
    traversal(newNode);


    //   Compilation Time code //
    cout << endl;
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    return 0;
}