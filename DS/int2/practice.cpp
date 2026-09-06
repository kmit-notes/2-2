/** University Management System

A university wants to automate its academic activities.

The system should:

Process student requests in the order they arrive.
Maintain a history of administrative actions with undo functionality.
Store student records using unique roll numbers.
Represent the university organizational hierarchy.
Model relationships between courses and prerequisites.
Tasks
Identify suitable data structures.
Implement all required operations.
Display traversals and searches where applicable. */
#include<iostream>
//#include <bits/stdc++.h>
#include <vector>
#include<map>
using namespace std;
struct Student{
    int rno;
    string name;
};
class Queue{
    vector<int> arr;
    int rear=-1;
    int front=-1;
    public: 
        void enqueue(int x){
            if(front==-1){
                front=0;
            }
            arr.push_back(x);
            rear++;
        }
        int dequeue(){
            
            
            if(front==-1 || front>rear){
                cout<<"Queue empty";
                return -1;
            }
            int x=arr[front];
            front++;
            return x;
            
        }
        void printq(){
            for(int i=front;i<=rear;i++){
                cout<<arr[i]<<endl;
            }
        }
        int len(){
            if(front==-1||front>rear)
            return 0;
            return rear-front+1;
        }
};
class Stack{
    vector<int>arr;
    int front=-1;
    public:
        void insert(int x){

            arr.push_back(x);
            front++;
        }
        int remove(){
            
            
            if(front==-1){
                cout<<"Stack empty";
                return -1;
            }
            int x=arr[front];
            front--;
            return x;
            
        }
        void prints(){
            for(int i=0;i<=front;i++){
                cout<<arr[i]<<endl;
            }
        }
        int len(){
            if(front==-1)
            return 0;
            return front+1;
        }

};
class Student_Stack{
    vector<Student>arr;
    int front=-1;
    public:
        void insert(Student x){

            arr.push_back(x);
            front++;
        }
        Student remove(){
            
            
            if(front==-1){
                cout<<"Stack empty";
                return {-1,""};
            }
            Student x=arr[front];
            front--;
            return x;
            
        }
        void prints(){
            for(int i=0;i<=front;i++){
                cout<<arr[i].rno<<" "<<arr[i].name<<endl;
            }
        }
        int len(){
            if(front==-1)
            return 0;
            return front+1;
        }

};
class MaxHeap{
    vector<Student> arr;
    public:
        void HeapifyUp(int i){
            while(i>0){
                int parent=(i-1)/2;
                if(arr[parent].rno < arr[i].rno){
                    swap(arr[parent],arr[i]);
                    i=parent;
                }
                else{
                    break;
                }
            }
        }
        void HeapifyDown(int i){
            int n=arr.size();
            while(true){
                int largest=i;
                int left=2*i+1;
                int right=2*i + 2;

                if(left<n && arr[left].rno>arr[largest].rno){
                    largest=left;
                    
                }
                if(right<n && arr[right].rno>arr[largest].rno){
                    largest=right;
                    
                }
                if (largest == i) {
                break;
            }
                swap(arr[i],arr[largest]);
                i=largest;
            }
        }

        void insert(Student s){
            arr.push_back(s);
            HeapifyUp(arr.size()-1);
        }
        Student extractMax(){
            if (arr.empty()) {
            return { -1,""};
        }
        Student max=arr[0];
        arr[0]=arr.back();
        arr.pop_back();

        if(!arr.empty()){
            HeapifyDown(0);
        }

        return max;
        }
        void display() {
        cout << "\nMax Heap contents:\n";
        for (Student i : arr) {
            cout<<i.rno<<" "<<i.name<<endl;
        }
    }
        
    
};
class Node{
    public:
        Node* left;
        Node* right;
        Student data;
        Node(Student s){
            left=right=NULL;
            data=s;
        }
};

    Node* insert(Node* root,Student s){
        if (root == NULL) {
        return new Node(s);
    }
    if(s.rno<root->data.rno){
        root->left=insert(root->left,s);
    }
    else{
        root->right=insert(root->right,s);

    }
    return root;
    }
    Node* findMin(Node* root){
    while(root->left!=NULL)
        root=root->left;

    return root;
}
    Node* remove(Node* root,Student s){
        if(root==NULL)
        return NULL;
        if(s.rno < root->data.rno)
        root->left = remove(root->left,s);

    else if(s.rno > root->data.rno)
        root->right = remove(root->right,s);

    else{
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }

        // One child
        else if(root->left==NULL){
            Node* temp=root->right;
            delete root;
            return temp;
        }

        else if(root->right==NULL){
            Node* temp=root->left;
            delete root;
            return temp;
        }
        //Two children
        else{
            Node* temp=findMin(root->right);

            root->data=temp->data;

            root->right=remove(root->right,temp->data);
        }
        

    }
    return root;


}
void displayGraph(vector<Student> orders) {
    map<int, vector<string>> graph;

    /*
       Simple assumption:
       Connect each order to the next order.
       O1 - O2 - O3 - O4 - O5
    */

    for (int i = 0; i < orders.size() - 1; i++) {
        graph[orders[i].rno].push_back(orders[i + 1].name);
        graph[orders[i + 1].rno].push_back(orders[i].name);
    }

    cout << "\nGraph adjacency list:\n";

    for (auto pair : graph) {
        cout << pair.first << " -> ";

        for (string neighbour : pair.second) {
            cout << neighbour << " ";
        }

        cout << endl;
    }
}

int main(){
    Queue students;
    students.enqueue(30);
    students.enqueue(50);
    students.enqueue(20);
    students.enqueue(90);
    students.enqueue(60);
    students.enqueue(55);
    students.enqueue(12);
    
    cout<<"Pop: "<<students.dequeue()<<endl;
    cout<<"Pop: "<<students.dequeue()<<endl;

    students.printq();
    Stack s;
    Queue n;
    cout<<"len"<<students.len()<<endl;
    int y=students.len();
    for(int i=0;i<y;i++){
        int x=students.dequeue();
        if(x>40){
            s.insert(x);
        }
        else{
            n.enqueue(x);
        }

    }
    cout<<"s"<<endl;
    s.prints();
    cout<<"n"<<endl;
    n.printq();
    cout<<"students"<<endl;
    students.printq();
    string ur;
    cin>>ur;
    Stack z;
    if(ur=="undo"){
        z.insert(s.remove());
        s.prints();
        cout<<"z"<<endl;
        z.prints();
    }
    else if(ur=="redo"){
        if(z.len()==-1)
        cout<<"Error";
        s.insert(z.remove());
        s.prints();
        cout<<"z"<<endl;
        z.prints();
        
    }
    Student_Stack s_s;
    s_s.insert({22,"Hans"});
    s_s.insert({21,"Manasa"});
    s_s.prints();
    MaxHeap mh;
    mh.insert({22,"Hans"});
    mh.insert({21,"Manasa"});
    mh.insert({20,"Hans"});
    mh.insert({26,"Manasa"});
    
    mh.extractMax();
    mh.display();
    vector<Student> p= {
        { 500,"01"},
        { 1000,"02"},
        { 5000,"03"},
        { 200,"014"}
        
    };
    displayGraph(p);
}
