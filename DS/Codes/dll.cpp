#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* prev;
    Node* next;
};

Node* head = NULL;

// Insert at Beginning
void insertStart(int value)
{
    Node* newNode = new Node();
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;

    if(head != NULL)
        head->prev = newNode;

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
        newNode->prev = NULL;
        head = newNode;
        return;
    }

    Node* temp = head;
    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

// Insert at Position
void insertPosition(int value,int pos)
{
    Node* newNode = new Node();
    newNode->data = value;

    Node* temp = head;

    for(int i=1;i<pos-1;i++)
        temp = temp->next;

    newNode->next = temp->next;
    newNode->prev = temp;

    temp->next->prev = newNode;
    temp->next = newNode;
}

// Delete at Beginning
void deleteStart()
{
    Node* temp = head;

    head = head->next;

    if(head != NULL)
        head->prev = NULL;

    delete temp;
}

// Delete at End
void deleteEnd()
{
    Node* temp = head;


    while(temp->next->next != NULL){
        temp=temp->next;
    }
    Node* del=temp->next;
    temp->next=del->next;
    delete del;

}

// Delete at Position
void deletePosition(int pos)
{
    Node* temp = head;

    for(int i=1;i<pos;i++)
        temp = temp->next;

    temp->prev->next = temp->next;

    if(temp->next != NULL)
        temp->next->prev = temp->prev;

    delete temp;
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

    insertPosition(15,3);

    cout<<"DLL after insertion: ";
    traverse();

    deleteStart();
    deleteEnd();
    deletePosition(2);

    cout<<"DLL after deletion: ";
    traverse();

    return 0;
}