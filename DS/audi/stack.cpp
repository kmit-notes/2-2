#include <iostream>
using namespace std;
class Stack{
public:
	int top;
	int capacity;
	int a[];
	//int *a;
	Stack(int b){
		capacity = b;
	 	a[capacity];
	 	// a= new int[capacity];
	 	top=-1;
    }
	
	bool isfull(){
        if(top==(capacity-1)){
 	        cout<<"Stack is full"<<endl;
		    return true;
		}
		else{
		    return false;
		}
	}
	bool isempty(){
	    if(top<0){
	        cout<<"Empty";
	        return true;
	    }return false;
	}
	
	void push(int x){
	    if(isfull()){
	        return;
	    }
		 else{
		     top++;
		     a[top]=x;
		 }
	}
	
	void pop(){
		top--;
	}
	
	void display(){
		for(int i=0;i<=top;i++){
			cout<<a[i]<<endl;
        }
    }
};
int main(){
	Stack s(3);
	s.push(2);
	s.push(3);
	s.pop();
	s.push(40);	
	s.push(41);
	s.isfull();
	s.push(412);
	s.display();
	//cout<<"Hello"<<endl;
	s.isfull();
	s.isempty();
}