 #include <iostream>
using namespace std;
#include <bits/stdc++.h>

class Node{
    public:
    int data;
    Node* next;

    Node(int d){
        this->data = d;
        this->next = NULL;
    }

    ~Node(){
        int val = this->data;
        if(this->next !=NULL){
            delete next;
            this->next = NULL;
        }
        cout << "memory is free for node with data : "<< val<<endl;
    }
};

void insertNode(Node* &tail, int element,int d)
{
    // if list is empty
    if(tail == NULL)
    {
        Node* newn = new Node(d);
        tail = newn;
        newn->next = newn;     // self-pointing cuzz circular LL
    }else{
        Node* curr = tail;
        while (curr->data != element){
            curr = curr->next;
        }

        // elem found -- curr is represtng elem wala node
        Node* temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}


void deleteNode(Node* &tail, int value)
{
    // empty list
    if(tail == NULL){
        cout << "List Empty" << endl;
        return;
    }else{
        Node* prev = tail;
        Node* curr = prev->next;

        while(curr->data != value)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;

        // one node CLL
        if(prev == curr){
            tail = NULL;
        }
        //  >-2 node LL
        else if(tail == curr){
            tail = prev;
        }
        curr->next = NULL;
        delete curr;
    }
}


void print(Node* tail){
    Node* temp = tail;
    // cout << tail->data << " ";

    // while (tail->data != temp  )
    // {
    //     cout << tail->data << " ";
    //     tail = tail->next;
    // }

    do{
        cout << tail->data << " ";
        tail = tail->next;
    }
    while (tail != temp);
        cout << endl;
}



int main()
{
  //head is next of tail in cll
    Node* tail = NULL;
    insertNode(tail,2,4);
        print(tail);

    insertNode(tail,4,5);
        print(tail);

    insertNode(tail,5,6);
        print(tail);

    insertNode(tail,6,7);
    print(tail);

    deleteNode(tail,4);
        print(tail);


}