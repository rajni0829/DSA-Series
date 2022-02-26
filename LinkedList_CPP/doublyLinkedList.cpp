#include <iostream>
using namespace std;
#include <bits/stdc++.h>

class Node
{
    public:
    int data;
    Node* next;
    Node* prev;

    //constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }

    ~Node(){
        int val = this->data;
        if(next != NULL){
            delete next;
            next = NULL;
        }
    }
};


void print(Node* &head){
    Node* temp = head;
    while(temp!=NULL)
    {
        cout << temp->data<< " ";
        temp = temp->next;
    }
    cout << endl;
}


void insertAtHead(Node* &head,int d)
{
    // empty list
    if(head == NULL)
    {
        Node* temp = new Node(d);
        head = temp;
    }
    else
    {
        Node* temp = new Node(d);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}


void insertAtTail(Node* &tail, int d)
{
    if(tail == NULL)
    {
        Node* temp = new Node(d);
        tail = temp;
    }
    else
    {
        Node* temp = new Node(d);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}


void insertAtPosition(Node* &head, Node* &tail, int pos, int d)
{
    if(pos == 0)
    {
        insertAtHead(head, d);
        return;
    }
    else{
        Node* temp = head;
        int cnt = 1;
        while(cnt < pos-1)
        {
            temp= temp->next;
            cnt++;
        }

        Node* insertNode = new Node(d);
        insertNode->next = temp->next;
        temp->next->prev = insertNode;
        temp->next = insertNode;
        insertNode->prev = temp;
        
    }

}


void deleteNode(Node* &head,Node* &tail,int pos)
{
    if(pos == 1){
        Node* temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }else{
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while(cnt< pos)
        {
            prev = curr;
            curr=curr->next;
            cnt++;
        }

        curr->prev = NULL;
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }

}


int getlength(Node* &head)
{
    Node* temp = head;
    int cnt = 0;
    while(temp != NULL)
    {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}



int main()
{
    // obj
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;
    // print(head);

    cout << "Length : " << getlength(head) << endl;

    insertAtHead(head,15);
    insertAtHead(head,11);
    insertAtHead(head,7);

    insertAtTail(tail,20);

    insertAtPosition(head,tail,3,13);
    // print(head);

    deleteNode(head,tail,3);
    print(head);

}