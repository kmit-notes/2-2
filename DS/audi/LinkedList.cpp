#include <iostream>
#include <string>
using namespace std;


class Student{
	public:
		string name;
		long rollno;
		float cgpa;
		Student* p;
		
		Student(string n, long r, float c):name(n),rollno(r),cgpa(c){
			p=nullptr;
		}
};
class SLL{
	public:
	Student* sp=nullptr;
	
	/*bool addAtEnd(Student& s){
		if(sp==nullptr) // SLL is new
		{
			sp = s;
			
		}else{
			Student* tp = sp;
			//write the logic
			while(tp->p != nullptr)
			{
				Student* d = tp->p;
				tp=d->p;
			}
		}
		return true;
	}*/
	void printll(){
		Student* tp = sp;
		while(tp != nullptr){
			cout<<tp->cgpa<<tp->name<<endl;
			tp=tp->p;
		}
	}
};

int main(){
	Student s1("Radha",101001,4.5), s2("Radhika",1112313,45.6), s3("Rama",23123141,30.5);
	SLL l1;
	l1.sp=&s1;
	s1.p=&s2;
	s2.p=&s3;
	s3.p=nullptr;
	l1.printll();
}