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

int main()
{

//   Compilation Time code //
cout << endl;
auto end = chrono::steady_clock::now();
auto diff = end - start;
cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
return 0;
}