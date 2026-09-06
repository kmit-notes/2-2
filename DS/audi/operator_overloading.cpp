#include <iostream>
#include <string>
#include<vector>//ds standard template
using namespace std;

//
class Medicine {
private:
    string name;
    double price;
    int quantity;
    
public:
    Medicine(string n = "Unknown", double p = 0.0, int q = 0) 
        : name(n), price(p), quantity(q) {}
    
    // Getters
    string getName() const { return name; }
    double getPrice() const { return price; }
    int getQuantity() const { return quantity; }
    
   
    bool operator<(const Medicine& other) const {
        return price < other.price;
    }
    
   
    bool operator==(const Medicine& other) const {
        return name == other.name && price == other.price;
    }
    
    bool operator>(const Medicine& other) const {
        return price>other.price;
    }
    
    bool operator!=(const Medicine& other) const {
        return name!=other.name && price!=other.price;
    }
    
    Medicine operator+(const Medicine& other) const {
        if (name == other.name&&price==other.price) {
            return Medicine(name, price, quantity + other.quantity);
        }
        cout << "Warning: Adding different medicines!" << endl;
        return *this;
    }
    
    Medicine& operator+=(int amount) {
        quantity += amount;
        return *this;  
    }
    
    Medicine& operator++() {
        ++quantity;
        return *this;
    }
    
    // Postfix increment (med++)
    Medicine operator++(int) {  // int parameter distinguishes postfix
        Medicine temp = *this;  // Save current state
        ++quantity;
        return temp;  // Return old value
    }
    
    void display(){
        cout<<name<<endl;
        cout<<price<<endl;
        cout<<quantity<<endl;
    }
    
    void operator*(){
        cout<<"Hello World";
    }

    friend ostream& operator<<(ostream& s,Medicine &m);
    friend istream& operator>>(istream& c,Medicine &m);
};
ostream& operator<<(ostream& s,Medicine &m){
    s<<m.getName()<<" "<<m.getPrice()<<" "<<m.getQuantity()<<endl;
    return s;
}
istream& operator>>(istream& c,Medicine& m){
    string name;
    double price;
    int qty;
    c>>name;
    c>>price;
    c>>qty;
    Medicine m1(name,price,qty);
    m = m1;
    return c;
}
int main()
{
    Medicine med1("Aspirin", 5.99, 100);
    // Medicine med2("Aspirin", 5.99, 50);
    // Medicine med3("Ibuprofen", 7.25, 75);
    // if (med1 != med2) {
    //     cout << "Medicines are same type" << endl;
    // }
    //  med1 += 30;
    // cout << "After restocking: " << med1.getName() <<" "<<med1.getQuantity() << endl;
    // vector<Medicine> list; 
    // list.push_back(med1);
    // list.push_back(med2);
    // list.push_back(med3);
    // Medicine m = med1;
    // for(int i=1;i<list.size();i++){
    //     if(m==list.at(i)){
    //         m = list.at(i);
    //     }
    // }
    // m++;
    // m.display();
    
    // Medicine m4 = (med1++)+med2;
    // m4.display();
    // med1.display();
    // med2.display();
    
    // cout<<m<<endl;

    // cout<<m.getName()<<endl;
    // Medicine a;
    // *a;
    // cout<<endl;
    // Medicine m5 = med1+med3;
    // m5.display();

    cout<<med1;
    Medicine m;
    cin>>m;
    cout<<m;
}
//normal lessthan sign will not have any function by itself, we have given a form to it which made the datastructure to do it...
// i need to know how the post increment works



//we can access the private variables using the keyword called friend
// friend void setName(string name,Medicine& m) // this must be declared as a abstract class
// then i need to access it as non-member function; 
// (keyword) (return type) (methodName)(params)

//operator overloading -> friend function -> printing the object in string..
//defined as friend as we cannot override cout stream....

//virtual functions 
//vector playground