// INSERTION IN LL 

#include <iostream>
using namespace std;
#include <bits/stdc++.h>

// node
class Node{
    // intialize
    public:
        int data;
        Node* next;

    // constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    ~Node(){
        int val = this->data;
        if(this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "memory is free for node with data : " << val << endl;
    }
};


void insertAtHead(Node* &head, int d)    //reference so that new ll na bane,change in original
{    
    Node* temp = new Node(d);            // new Node
    temp->next = head;                  // inserting 
    head = temp;
}


void insertAtTail(Node* &tail,int d)
{
    Node* temp = new Node(d);                // new Node
    tail->next = temp;
    tail = temp;
}


void insertAtPosition(Node* &tail, Node* &head, int pos,int d)
{
    if(pos == 1){
        insertAtHead(head,d);
        return;
    }
    
    // traverse and find pos
    Node* temp = head;
    int cnt = 1 ;
 
    while(cnt < pos-1){
        temp = temp->next;
        cnt++;
    }

    // inserting at last pos
    if(temp->next == NULL)
    {
        insertAtTail(tail,d);
        return;
    }

    // creating node for d;
    Node * nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}


void deleteNode(Node* &head, int pos)
{
    // del8 first node
    if(pos == 1)
    {
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;          //freeing memory
    }
    else
    {
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while(cnt <= pos)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }

        prev->next = curr->next;
        curr->next = NULL;
        delete curr;

    }
}

void print(Node* &head)
{
    // temp node create pointing to head
    Node* temp = head;
    while(temp != NULL)
    {
        cout<<temp->data<< " ";
        temp = temp->next;
    }
}


int main()
{
    //obj of node   
    Node* node1 = new Node(5);
    // cout << node1->data<<endl;
    // cout << node1->next<<endl;

    // head pointing to node1
    Node* head = node1;
    Node* tail = node1;
    // print(node1);

    insertAtHead(head,15);
    insertAtHead(head,20);
    insertAtHead(head,25);
    insertAtHead(head,30);

    // insertAtTail(tail,15);
    // insertAtTail(tail,20);
    // insertAtTail(tail,25);
    // insertAtTail(tail,30);

    insertAtPosition(tail, head,4,33);
    // print(head);

    deleteNode(head,2);
    print(head);

}