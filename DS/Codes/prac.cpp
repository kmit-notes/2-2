#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
};
Node* head=NULL;
void insertstart(int val){
    Node* newnode=new Node();
    newnode->data=val;
    newnode->next=head;
    head=newnode;
}
void insertend(int val){
    Node* newnode=new Node();
    newnode->data=val;
    newnode->next=NULL;
    if(head==NULL){
        head=newnode;
        return;
    }
    Node* temp=new Node();
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;
}
void insertpos(int val, int pos){
    Node* newnode= new Node();
    newnode->data=val;
    Node* temp=new Node();
    if(pos==1){
        newnode->next=head;
        head=newnode;
        return;
    }
    for(int i=1;i<pos-1;i++){
        temp=temp->next;
    }
    if(temp == NULL){
        return;
    }
    newnode->next=temp->next;
    temp->next=newnode;
}
void deletefirst(){
    Node* temp=head;
    head=temp->next;
    delete temp;
}
void deleteend(){
    Node* temp=head;
    while(temp->next->next != NULL){
        temp=temp->next;
    }
    Node* x=temp->next;
    temp->next=x->next;
    delete x;

}
void deletepos(int pos){
    Node* temp=head;
    for(int i=1;i<pos-1;i++){
        temp=temp->next;
    }
    Node* x=temp->next;
    temp->next=x->next;
    delete x;
}
void traversefirst(){
    Node* temp = head;

    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
int main(){
    
}