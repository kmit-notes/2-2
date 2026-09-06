/*
Create the medicine class Question: 
Write the description of the class and indicate what does it do ?


*/

#include <iostream>
#include <string>
using namespace std;


class Medicine {
private:
    string name;
    double price;
    int quantity;
    string expiryDate;
    
public:

Medicine(string n, double p, int q, string exp) {
        name = n;
        price = p;
        quantity = q;
        expiryDate = exp;
        cout << "Medicine created: " << name << endl;
    }

//Medicine(string n, double p, int q, string exp):name(n),price(p),quantity(q),expiryDate(exp){}
//the above 2 constructors are the same

Medicine(Medicine* m){
	name=m->name;
	price=m->price;
	expiryDate=m->expiryDate;
	cout<<"Copy constructor called";
}
Medicine(Medicine& m){
	name=m.name;
	price=m.price;
	expiryDate=m.expiryDate;
	cout<<"Copy constructor 2 called";
}

Medicine(int i):quantity(i)
{}    
    Medicine() {
        name = "Unknown";
        price = 0.0;
        quantity = 0;
        expiryDate = "N/A";
    }
    
        ~Medicine() {
        cout << "Medicine destroyed: " << name << endl;
    }
    
       string getName() {
        return name;
    }
    
    double getPrice() {
        return price;
    }
    
    int getQuantity() {
        return quantity;
    }
    
    string getExpiryDate() {
        return expiryDate;
    }
    
        void setPrice(double p) {
        if (p >= 0) {
            price = p;
        }
    }
    
    void setQuantity(int q) {
        if (q >= 0) {
            quantity = q;
        }
    }
    
    void sell(int amount) {
        if (amount <= quantity) {
            quantity -= amount;
            cout << "Sold " << amount << " units of " << name << endl;
            cout << "Remaining quantity: " << quantity << endl;
        } else {
            cout << "Insufficient stock! Only " << quantity << " available." << endl;
        }
    }
    
    void restock(int amount) {
        quantity += amount;
        cout << "Restocked " << amount << " units of " << name << endl;
    }
    
    double calculateTotal(int amount) {
        return price * amount;
    }
    
    void display() {
        cout << "\n--- Medicine Details ---" << endl;
        cout << "Name: " << name << endl;
        cout << "Price: $" << price << endl;
        cout << "Quantity: " << quantity << endl;
        cout << "Expiry: " << expiryDate << endl;
    }
    
    
    void displayConst() const {
        cout << name << " - $" << price << endl;
         
    }
};

int main(){
	Medicine m,m1("Aspirin",2.30,90,"30/aug/2030");
	//m.display();
	//m1.display();
	
	Medicine *m3= new Medicine("Azithral",4.34,1000,"15/mar/2032");
//	m3->display();
	//delete m3;
	//Medicine m4 = m1;
	//m4.display();
//	Medicine m5=*m3;
	//m5.display();
//	m5->display();
//	m3->restock(80);
//	cout<<m5->getQuantity()<<endl;	
	return 0;
}

