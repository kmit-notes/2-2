#include <iostream>
#include <string>
using namespace std;
class Student
{
	public:
		string name;
		long rollno;
		float cgpa;
		Student* p;
		
		Student(string n, long r, float c):name(n),rollno(r),cgpa(c){p=nullptr;}
};
class SLL
{
	public:
	Student* sp=nullptr;
	
	
	void printll(){
		Student* tp = sp;
		while(tp != nullptr){
			cout<<tp->rollno<<" "<<tp->name<<" "<<tp->cgpa<<" "<<endl;
			tp=tp->p;
        }
    }
    
    void addAtEnd(Student* ns){
        Student* tp = sp;
        while(tp->p != nullptr){
            tp=tp->p;
        }
        tp->p=ns;
        ns->p=nullptr;
    }
    
    void addAtfront(Student* ns){
        ns->p=sp;
        sp=ns;
    }
    
    void addAfter(Student* ns, string n){
        Student* tp=sp;
        while(tp->name!=n){
            tp=tp->p;
        }
        ns->p=tp->p;
        tp->p=ns;
    }
    
    void addBefore(Student* ns, string n){
        Student* tp=sp;
        Student* bp=nullptr;
        while(tp->name!=n){
            bp=tp;
            tp=tp->p;
        }ns->p=tp;
        bp->p=ns;
        
    }
    void deleteLast(){
        Student* tp=sp;
        while(tp->p->p!=nullptr){
            tp=tp->p;
        }tp->p=nullptr;
    }
    
    void deleteFront(){
        Student* tp=sp;
        sp=tp->p;
        tp->p=nullptr;
    }
    
    void del(string n){
        Student* tp=sp;
        Student* bp=nullptr;
        while(tp->name!=n){
            bp=tp;
            tp=tp->p;
        }
        if(tp==sp){
            deleteFront();
        }else{
        bp->p=tp->p;
        tp=nullptr;}
    }
    void rev(){
    	Student* prev =nullptr;
    	Student* curr = sp;
    	Student* next = sp->p;
    	while(curr!=nullptr){
    		curr->p=prev;
    		prev=curr;
    	    curr=next;
    		next=next->p;
		}
		sp = prev;
	}
};
int main()
{
	Student s1("Radha",101001,4.5), s2("Radhika",1112313,45.6), s3("Rama",23123141,30.5);
	SLL l1;
	l1.sp=&s1;
	s1.p=&s2;
	s2.p=&s3;
	s3.p=nullptr;
	Student ns("Rohit",123123,10);
	Student *ns1= new Student("Rishi",123123,10);
	l1.addAtEnd(&ns);
	//l1.addAtEnd(ns1);
	//l1.addAtfront(ns1);
	//l1.addAfter(ns1,"Radha");
//	l1.addBefore(ns1,"Radhika");
	//l1.deleteLast();
	//l1.deleteFront();
	//l1.del("Radha");
	l1.rev();
	l1.printll();
}