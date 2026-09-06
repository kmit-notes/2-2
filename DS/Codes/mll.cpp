/**Design and implement a C++ program to manage medicines in two pharmacies using Linked Lists and Object-Oriented Programming concepts.

Requirements:
	1.	Create a class Medicine with the following data members:
	•	id (int)
	•	name (string)
	•	expiry (string)
	•	price (double)
	2.	Implement the following operator overloading in the Medicine class:
	•	== → compare medicines based on id
	•	< → compare medicines based on price
	•	+ → combine quantities of same medicines (assume same id means same medicine)
	•	<< → display medicine details
	3.	Create a Node class and a LinkedList class to store Medicine objects.
	4.	In the LinkedList class, implement:
	•	Insert at end
	•	Display
	•	Search (by id)
	5.	Create two linked lists:
	•	Pharmacy1
	•	Pharmacy2
	6.	Perform the following operations:
	•	Intersection: Display medicines common in both pharmacies (based on id)
	•	Union: Display all unique medicines from both lists (no duplicates)
	•	Merge: Combine both lists (duplicates allowed)
	7.	Additional Requirement:
	•	Create linked lists for:
	•	integers
	•	strings
(either using templates or separate implementations)
	8.	Constraints:
	•	Use Linked List (no arrays for main storage)
	•	Must use classes and objects
	•	Must use operator overloading

Sample Input:

Pharmacy1:
3
1 Paracetamol 2026 50
2 Aspirin 2025 30
3 Dolo 2027 40

Pharmacy2:
3
2 Aspirin 2025 30
3 Dolo 2027 40
4 Ibuprofen 2026 60

Expected Output:

Pharmacy 1:
1 Paracetamol 2026 50
2 Aspirin 2025 30
3 Dolo 2027 40

Pharmacy 2:
2 Aspirin 2025 30
3 Dolo 2027 40
4 Ibuprofen 2026 60

Intersection:
2 Aspirin 2025 30
3 Dolo 2027 40

Union:
1 Paracetamol 2026 50
2 Aspirin 2025 30
3 Dolo 2027 40
4 Ibuprofen 2026 60

Merged:
1 Paracetamol 2026 50
2 Aspirin 2025 30
3 Dolo 2027 40
2 Aspirin 2025 30
3 Dolo 2027 40
4 Ibuprofen 2026 60
 */

 #include<iostream>
 using namespace std;
 class Medicine{
    public:
        int id;
	    string name;
	    string expiry;
	    double price; 

    
        Medicine(int i=0, string n="", string e="", double p=0.0){
            id=i;
            name=n;
            expiry=e;
            price=p;

        }
        int getid() const{
            return id;
        }
        string getname() const{return name;}
        string getexpiry()const { return expiry;}
        double getprice() const{return price;}

        /**== → compare medicines based on id
	•	< → compare medicines based on price
	•	+ → combine quantities of same medicines (assume same id means same medicine)
	•	<< → display medicine details */

    bool operator==(const Medicine& other)const{
        if(id==other.id) return true;
        return false;
    }
    bool operator<(const Medicine& other)const{
        return price<other.price;
    }
    Medicine operator+(const Medicine& other) {
    if(id == other.id)
        return Medicine(id, name, expiry, price + other.price);
    return *this;
}
    
        

 };
 istream& operator>>(istream& c, Medicine& m){
        int id;
        string name;
        string expiry;
        double price;
        c>>id;
        c>>name;
        c>>expiry;
        c>>price;
        Medicine m1(id,name,expiry,price);
        m=m1;
        return c;

    } 
    ostream& operator<<(ostream& o,const Medicine& m){
        o<<m.getid()<<" "<<m.getname()<<" "<<m.getexpiry()<<" "<<m.getprice()<<endl;
    return o;    }

class Node{
    public:
        Node* next;
        Medicine data;

        Node(Medicine m){
            next=NULL;
            data=m;

    }
};
class linkedlist{
    public:
        Node* head;
        linkedlist(){
            head=NULL;
        }
        void insertend(Medicine m){
            Node* newnode=new Node(m);
            //newnode->data=m;
            newnode->next=NULL;
            Node* temp=head;
            if(head==NULL){
                head=newnode;
                return;
            }
            while(temp->next != NULL){
                temp=temp->next;
            }
            temp->next=newnode;
        }
        void display(){
            Node* temp=head;
            while(temp!=NULL){
                cout<<temp->data;
                temp=temp->next;
            }
        }
        bool exists(Medicine m){
            Node* temp=head;
            while(temp!=NULL){
                if(temp->data==m){
                    return true;
                }
                temp=temp->next;
            }
            return false;
        }
        Medicine* search(int id) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data.getid() == id) {
                return &temp->data;
            }
            temp = temp->next;
        }
        return nullptr;
    }

};


linkedlist intersection(linkedlist l1,linkedlist l2){
    Node* temp=l1.head;
    linkedlist result;
    while(temp!=NULL){
    if(l2.exists(temp->data)){
        result.insertend(temp->data);

    }
    temp=temp->next;
    }
    return result;
}
linkedlist unionlist(linkedlist l1, linkedlist l2){
    Node* temp=l1.head;
    linkedlist result;
    while(temp!=NULL){
        if(!result.exists(temp->data)){
            result.insertend(temp->data);
        }
        temp=temp->next;
    }
    temp=l2.head;
    while(temp!=NULL){
        if(!result.exists(temp->data)){
            result.insertend(temp->data);
        }
        temp=temp->next;
    }
    return result;

}
linkedlist merge(linkedlist l1,linkedlist l2){
    Node* temp=l1.head;
    linkedlist result;
    while(temp!=NULL){
        
            result.insertend(temp->data);
        
        temp=temp->next;
    }
    temp=l2.head;
    while(temp!=NULL){
        
            result.insertend(temp->data);
        
        temp=temp->next;
    }
    return result;
    
}
int main(){
    linkedlist Pharmacy1;
    linkedlist Pharmacy2;
    Medicine m1(1, "Paracetamol", "2026", 50);
    Medicine m2(2, "Aspirin", "2025", 30);
    Medicine m3(3, "Dolo", "2027", 40);

    Pharmacy1.insertend(m1);
    Pharmacy1.insertend(m2);
    Pharmacy1.insertend(m3);

    Medicine n1(2, "Aspirin", "2025", 30);
    Medicine n2(3, "Dolo", "2027", 40);
    Medicine n3(4, "Ibuprofen", "2026", 60);

    Pharmacy2.insertend(n1);
    Pharmacy2.insertend(n2);
    Pharmacy2.insertend(n3);

    // Output
    cout << "Pharmacy 1: \n";
    Pharmacy1.display();
    
    cout << "\nPharmacy 2: \n";
    Pharmacy2.display();

    cout << "\nIntersection:\n";
    intersection(Pharmacy1, Pharmacy2).display();

    cout << "\nUnion:\n";
    unionlist(Pharmacy1, Pharmacy2).display();

    cout << "\nMerged:\n";
    merge(Pharmacy1, Pharmacy2).display();

    return 0;

    
}