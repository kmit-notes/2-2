#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* head = NULL;

// Insert at Beginning
void insertStart(int value)
{
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

// Insert at End
void insertEnd(int value)
{
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;

    if(head == NULL)
    {
        head = newNode;
        return;
    }

    Node* temp = head;
    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

// Insert at Position
void insertPos(int x, int pos){
    Node* newNode = new Node;
    newNode->data = x;
    if(pos == 1){ // edge case, if inserting at pos = 1
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* temp = head;
    for(int i = 1; i<pos-1; i++){
        temp = temp->next;
    }

    if(temp == NULL){
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}
// Delete at Beginning
void deleteStart()
{
    Node* temp = head;
    head = head->next;
    delete temp;
}

// Delete at End
void deleteEnd()
{
    Node* temp = head;

    while(temp->next->next != NULL)
        temp = temp->next;

    delete temp->next;
    temp->next = NULL;
}

// Delete at Position
void deletePosition(int pos)
{
    Node* temp = head;

    for(int i=1;i<pos-1;i++)
        temp = temp->next;

    Node* del = temp->next;
    temp->next = del->next;

    delete del;
}

// Traversal
void traverse()
{
    Node* temp = head;

    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main()
{
    insertStart(10);
    insertStart(5);

    insertEnd(20);
    insertEnd(30);

    insertPos(15,3);

    cout<<"List after insertion: ";
    traverse();

    deleteStart();
    deleteEnd();
    deletePosition(2);

    cout<<"List after deletion: ";
    traverse();

    return 0;
}