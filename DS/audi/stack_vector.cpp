#include <iostream>
#include <vector>
using namespace std;
class Stack{
public:
	int top;
	vector<int> a;
	Stack(){
	 	top=-1;
    }
	

	
	void push(int x){
		     top++;
		     a.push_back(x);
	}
	
	/*void pop(){
	    a.();
	}*/
	
	void display(){
		for(int i=0;i<=top;i++){
			cout<<a[i]<<endl;
        }
    }
};
int main(){
	Stack s;
	s.push(2);
	s.push(3);
	//s.pop();
	s.push(40);	
	s.push(41);
	s.push(412);
	s.display();
	//cout<<"Hello"<<endl;
}