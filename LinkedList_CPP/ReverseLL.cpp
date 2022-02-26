#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

    Node(int d)
    {
        this->data=d;
        this->next=NULL;
    }
};

void insert(Node* &head,int d)
{
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;

}

int reverseLinkedList(Node* &head)
{
    Node* prev = NULL;
    Node* curr = head;
    while (curr->next != NULL){
        Node* forward = curr->next;
        curr->next = prev;
        curr = forward;
        prev = curr;
    }
    return prev;
}

void print(Node* &head)
{
    Node* temp = head;
    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    Node* n1 = head;
    
    print(n1);

}